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
void dfs(vector<int> &p, int u,vector<int> &visited,vector<int> &paths){
    if(visited[u]){
        return;
    }
    visited[u]=1;
    if(p[u]==u){
        paths.pb(u+1);
        return;
    }
    dfs(p,p[u],visited,paths);
    paths.pb(u+1);
}

void run(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> p;
        map<int,bool> mp;
        int lastnode=0;
        fora(i,n){
            int x;
            cin>>x;
            p.pb(x-1);
            mp[x-1]=1;
            lastnode=max(lastnode,x-1);
        }
        vector<int> leafNodes;
        
        fora(i,n){
            if(!mp[i]){
                leafNodes.pb(i);
            }
        }
        if(leafNodes.size()==0){
            cout<<1<<endl<<1<<endl<<p[0]+1<<endl<<endl;
            continue;
        }
        cout<<leafNodes.size()<<endl;
        vector<int> visited(n+1,0);
        vector<vector<int>> paths;
        for(auto &x:leafNodes){
            vector<int> path;
            dfs(p,x,visited,path);
            //reverse(path.begin(),path.end());
            paths.pb(path);
        }
        for(auto &x:paths){
            cout<<x.size()<<endl;
            for(auto &y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
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
