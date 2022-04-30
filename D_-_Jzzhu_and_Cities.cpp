#include <bits/stdc++.h>
#if 0
#define HOME
#endif
#ifndef ONLINE_JUDGE
#define dbgA2(A, n, m)  {cout<<"-->"<<#A<<"=\n";for(ll i = 0; i < n; i++){for(ll j = 0; j < m; j++){cout<<A[i][j]<<" ";}cout<<"\n";}cout<<"\n";}
#define dbgA(A, n)      {cout<<"-->"<<#A<<"=(";for(ll i = 0; i < n; i++)cout<<A[i]<<" ";cout<<")\n";}
#define dbg(args...)    {string sss(#args);sss+=',';cout<<"-->";debugger::call(sss.begin(), sss.end(), args);cout<<"\n";}
#else
#define dbgA2(A, n, m)
#define dbgA(A, n)
#define dbg(args...)
#endif
#define fora(I,n) for(ll I=0; I<n;I++)
#define forb(I,n) for(ll I=1; I<=n;I++)
#define mXI (ll)1e8
#define umXI Ull_MAX
#define llmXI LLONG_MAX
#define pb push_back
#define ll long long
#define pll pair<ll,ll>
#define pii pair<ll,ll>
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
    for (ll i = 2; i <= n; i++)
    {
        if (!siev_arr[i])
        {
            cout<<i<<endl;
            for (ll j = i + i; j <= n; j += i)
            {
                siev_arr[j] = 1;
            }
        }
    }
}

ll dfs(ll v, ll *arr, ll *visited){
    if(visited[arr[v]]){
        return arr[v]=arr[arr[v]];
    }
    visited[v]=1;
    return arr[v]=dfs(arr[v],arr,visited);
}*/

void run(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pii>> graph(n+1);
    map<pair<int,pair<int,int>>,bool> ff;
    fora(i,m){
        ll u,v,w;
        cin>>u>>v>>w;
        graph[u].pb(mkp(w,v));
        graph[v].pb(mkp(w,u));
        ff[{w,{u,v}}]=true;
        ff[{w,{v,u}}]=true;
    }
    
    ll dist[n+1];
    fora(i,n+1)dist[i]=1e12;
    dist[1]=0;
    int parent[n+1];
    fora(i,n+1)parent[i]=-1;
    int selectedEdge[n+1][n+1];
    fora(i,n+1)fora(j,n+1)selectedEdge[i][j]=0;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push(mkp(0,1));
    while(!pq.empty()){
        pii cur=pq.top();
        pq.pop();
        ll u=cur.second;
        for(auto it:graph[u]){
            ll v=it.second;
            ll w=it.first;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                parent[v]=u;
                selectedEdge[u][v]=w;
                selectedEdge[v][u]=w;
                pq.push(mkp(dist[v],v));
            }
        }
    }
    map<pair<int,int>,int> counts;
    fora(i,k){
        ll v,w;
        cin>>v>>w;
        graph[1].pb(mkp(w,v));
        graph[v].pb(mkp(w,1));
        counts[{1,v}]++;
        counts[{v,1}]++;
    }
    pq=priority_queue<pll,vector<pll>,greater<pll>>();
    pq.push(mkp(0,1));
    while(!pq.empty()){
        pii cur=pq.top();
        pq.pop();
        ll u=cur.second;
        for(auto it:graph[u]){
            ll v=it.second;
            ll w=it.first;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                parent[v]=u;
                selectedEdge[u][v]=w;
                selectedEdge[v][u]=w;
                pq.push(mkp(dist[v],v));
            }
        }
    }
    vector<pair<int,pair<int,int>>> selected;
    map<pii,ll> mp;
    forb(i,n){
        ll u = i;
        while(parent[u]!=-1){
            if(mp[{parent[u],u}]==0){
                selected.pb(mkp(selectedEdge[parent[u]][u],mkp(parent[u],u)));
                mp[{parent[u],u}]=1;
            }
            u=parent[u];
        }
    }
    ll ans=k;
    for(auto it:selected){
        //cout<<it.second.first<<" "<<it.second.second<<" "<<it.first<<endl;
        if(!ff[it] && counts[{it.second.first,it.second.second}]>0){
            ans--;
        }
    }
    cout<<ans<<endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
