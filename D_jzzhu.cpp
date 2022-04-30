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
struct edge{
    int next;
    ll w;
};
bool operator<(const edge &a, const edge &b){
    return a.w < b.w;
}
const int MAXN=100001;
vector<edge> graph[MAXN];
vector<edge> trains;
ll dist[MAXN];
bool visited[MAXN];
void sssp(int source){
    queue<int> q;
    q.push(source);
    visited[source]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto it:graph[u]){
            if(dist[it.next]>dist[u]+it.w){
                dist[it.next]=dist[u]+it.w;
                if(!visited[it.next]){
                    q.push(it.next);
                    visited[it.next]=1;
                }
            }
        }
        visited[u]=0;
    }
}
void run(){
    int n,m,k;
    cin>>n>>m>>k;
    fora(i,n+1){
        graph[i].clear();
        dist[i]=1e15;
    }
    fora(i,m){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].pb(edge{v,w});
        graph[v].pb(edge{u,w});
    }
    dist[1]=0;
    sssp(1);
    fora(i,k){
        int v,w;
        cin>>v>>w;
        trains.pb(edge{v,w});
    }
    sort(trains.begin(),trains.end());
    ll ans=0;
    fora(i,trains.size()){
        if(dist[trains[i].next]>trains[i].w){
            dist[trains[i].next]=trains[i].w;
            sssp(trains[i].next);
        }else{
            ans++;
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
