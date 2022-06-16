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
void dfs1(vector<vector<char>> &graph,int u,int v,vector<vector<int>> &visited){
    if(u>=8 || v>=8 || visited[u][v] || graph[u][v]!='#' ) return;
    visited[u][v]=1;
    dfs1(graph,u+1,v+1,visited);
}
void dfs2(vector<vector<char>> &graph,int u,int v,vector<vector<int>> &visited){
    if(u>=8 || v<0 ||visited[u][v] || graph[u][v]!='#') return;
    // cout<<u<<" "<<v<<endl;
    visited[u][v]=1;
    dfs2(graph,u+1,v-1,visited);
}
void run(){
    int t;
    cin>>t;
    while(t--){
        int n=8;
        vector<vector<char>> graph(n,vector<char>(n));
        vector<vector<int>> visited1(n,vector<int>(n,0));
        vector<vector<int>> visited2(n,vector<int>(n,0));
        int start=-1;
        fora(i,n){
            fora(j,n){
                cin>>graph[i][j];
            }
        }
        fora(i,n){
            fora(j,n){
                if(i<n-1 && j<n-1 && graph[i][j]=='#' && graph[i+1][j+1]=='#'){
                    dfs1(graph,i,j,visited1);
                }
                if(j>0 && i<n-1 && graph[i][j]=='#' && graph[i+1][j-1]=='#'){
                    dfs2(graph,i,j,visited2);
                }
            }
        }
        int x=-1,y=-1;
        fora(i,n){
            fora(j,n){
                if(visited1[i][j]==visited2[i][j] && visited1[i][j]==1){
                    y=i;
                    x=j;
                    break;
                }
            }
        }
        cout<<y+1<<" "<<x+1<<endl;

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
