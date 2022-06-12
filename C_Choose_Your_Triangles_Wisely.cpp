#include <bits/stdc++.h>
#if 0
#define HOME
#endif
#ifndef ONLINE_JUDGE
#define dbgA2(A, n, m)  {cout<<"-->"<<#A<<"=\n";for(int i = 0; i < n; i++){for(int j = 0; j < m; j++){cout<<A[i][j]<<" ";}cout<<"\n";}cout<<"\n";}
#define dbgA(A, n)      {cout<<"-->"<<#A<<"=(";for(int i = 0; i < n; i++)cout<<A[i]<<" ";cout<<")\n";}
#define dbg(args...)    {string sss(#args);sss+=',';cout<<"-->";debugger::call(sss.begin(), sss.end(), args);cout<<"\n";}
#else
#define dbgA2(A, n, m)
#define dbgA(A, n)
#define dbg(args...)
#endif
#define fora(I,n) for(int I=0; I<n;I++)
#define forb(I,n) for(int I=1; I<=n;I++)
#define mXI (int)1e8
#define umXI UINT_MAX
#define llmXI LLONG_MAX
#define pb push_back
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define mkp(a,b) make_pair(a,b)
using namespace std;
/*struct debugger {
    typedef string::iterator si;
    static void call(si it, si ed) {}
    template<typename T, typename ... aT>
    static void call(si it, si ed, T a, aT... rest) {
        string b;
        for(; *it!=','; ++it)
            if(*it!=' ')
                b+=*it;
        cout << b << "=" << a << " ";
        call(++it, ed, rest...);
    }
};
ll siev_arr[mXI];
void siev(ll n)
{
    siev_arr[0] = siev_arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!siev_arr[i])
        {
            cout<<i<<endl;
            for (int j = i + i; j <= n; j += i)
            {
                siev_arr[j] = 1;
            }
        }
    }
}

int dfs(int v, int *arr, int *visited){
    if(visited[arr[v]]){
        return arr[v]=arr[arr[v]];
    }
    visited[v]=1;
    return arr[v]=dfs(arr[v],arr,visited);
}*/

void run(){
    int t;
    cin>>t;
    int tt=1;
    while(t--){
        cout<<"Case "<<tt++<<": ";
        int n;
        cin>>n;
        vector<int> v(n);
        fora(i,n)cin>>v[i];
        sort(v.rbegin(),v.rend());
        bool flag=true;
        int ans=1e9;
        for(int i=0;i<n-1 && flag;i++){
            for(int j=i+1;j<n;j++){
                int len = abs(v[i]-v[j]);
                int index=lower_bound(v.begin()+j,v.end(),len)-v.begin();
                index++;
                if((v[i]+v[j])>v[index] && (v[i]+v[index])>v[j] && (v[index]+v[j])>v[i]){
                    ans=min(v[i]+v[j]+v[index],ans);
                    flag=false;
                    break;
                }
            }
        }
        sort(v.begin(),v.end());
        int ans2=1e9;
        bool flag2=true;
        for(int i=0;i<n-1 && flag2;i++){
            for(int j=i+1;j<n;j++){
                int len = abs(v[i]-v[j]);
                int index=lower_bound(v.begin()+j+1,v.end(),len)-v.begin();
                if((v[i]+v[j])>v[index] && (v[i]+v[index])>v[j] && (v[index]+v[j])>v[i]){
                    ans2=min(v[i]+v[j]+v[index],ans2);
                    break;
                }
            }
        }
        if(ans==1e9 && ans2==1e9){
            cout<<-1<<endl;
        }
        else{
            cout<<ans2<<" "<<ans<<endl;
        }
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
