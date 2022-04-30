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
    int n,m;
    cin>>n>>m;
    vector<vector<pll>> edges(n+1);
    fora(i,m){
        int u,v,w;
        cin>>u>>v>>w;
        edges[u].pb(mkp(w,v));
        edges[v].pb(mkp(w,u));
    }
    vector<ll> dist(n+1,1e16);
    vector<ll> visited(n+1,0);
    dist[1]=0;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push(mkp(0,1));
    vector<ll> parents(n+1,-1);
    while(!pq.empty()){
        pii p=pq.top();
        pq.pop();
        ll u=p.second;
        if(visited[u])continue;
        visited[u]=1;
        for(auto v:edges[u]){
            if(dist[v.second]>dist[u]+v.first){
                dist[v.second]=dist[u]+v.first;
                parents[v.second]=u;
                pq.push(mkp(dist[v.second],v.second));
            }
        }
    }
    stack<ll> st;
    ll u=n;
    while(parents[u]!=-1){
        st.push(u);
        u=parents[u];
    }
    if(u!=1){
        cout<<-1<<endl;
        return;
    }else{
        st.push(u);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
