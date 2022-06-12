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

int LIS(vector<int> &arr){
    vector<ll> dp(arr.size(),1e18);
    vector<int> count(arr.size(),1);
    for(int i=0;i<arr.size();i++){
        int index=lower_bound(dp.begin(),dp.end(),arr[i])-dp.begin();
        dp[index]=arr[i];
        count[i]=index;
    }
    return *max_element(count.begin(),count.end());

}

void run(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        map<int,int> counter;
        map<int,int> cc;
        fora(i,n){
            int x;
            cin>>x;
            arr.push_back(x);
        }
        sort(arr.begin(),arr.end());
        vector<int> a,b;
        int i=0;
        bool flip=0;
        while(i<arr.size()){
            if(!flip){
                b.pb(arr[i]);
            }
            else{
                a.pb(arr[i]);
            }
            flip=!flip;
            i++;
        }
        int left=0,right=0;
        vector<int> merged;
        fora(i,a.size()){
            merged.pb(a[i]);
        }
        for(int i=b.size()-1;i>=0;i--){
            merged.pb(b[i]);
        }
        vector<int> second = merged;
        int ans=LIS(merged);
        reverse(second.begin(),second.end());
        int ans2=LIS(second);
        cout<<min(ans,ans2)+1<<endl;

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