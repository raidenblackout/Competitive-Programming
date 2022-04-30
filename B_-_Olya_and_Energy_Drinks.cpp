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
char graph[1000][1000];
int moves[1000][1000][2];
int dis[1000][1000];
int bfs(int startx,int starty, int goalx,int goaly,int n,int m, int k){
    queue<pii> q;
    q.push(mkp(startx,starty));
    dis[startx][starty]=0;
    moves[startx][starty][0]=0;
    moves[startx][starty][1]=0;
    while(!q.empty()){
        pii curr=q.front();
        q.pop();
        int updownx[]={0,0}, updowny[]={1,-1};
        int leftrightx[]={1,-1}, leftrighty[]={0,0};
        for(int i=0;i<2;i++){
            int x=curr.first+leftrightx[i];
            int y=curr.second+leftrighty[i];
            int change=(moves[curr.first][curr.second][1]>1?0:1);
            if(x>=0 && x<n && y>=0 && y<m && graph[x][y]=='.' && dis[x][y]>dis[curr.first][curr.second]+change){
                dis[x][y]=dis[curr.first][curr.second]+change;
                moves[x][y][1]=moves[curr.first][curr.second][1]-1;
                if(moves[x][y][1]<=0) moves[x][y][1]=k;
                q.push(mkp(x,y));
            }
        }
        for(int i=0;i<2;i++){
            int x=curr.first+updownx[i];
            int y=curr.second+updowny[i];
            int change=(moves[curr.first][curr.second][0]>1?0:1);
            if(x>=0 && x<n && y>=0 && y<m && graph[x][y]=='.' && dis[x][y]>dis[curr.first][curr.second]+change){
                dis[x][y]=dis[curr.first][curr.second]+change;
                moves[x][y][0]=moves[curr.first][curr.second][0]-1;
                if(moves[x][y][0]<=0) moves[x][y][0]=k;
                q.push(mkp(x,y));
            }
        }
        
    }
    return dis[goalx][goaly]==1e9?-1:dis[goalx][goaly];
}
void run(){
    int n,m,k;
    cin>>n>>m>>k;
    fora(i,n){
        fora(j,m){
            cin>>graph[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dis[i][j]=1e9;
            moves[i][j][0]=0;
            moves[i][j][1]=0;
        }
    }
    int startx,starty,goalx,goaly;
    cin>>startx>>starty>>goalx>>goaly;
    int res=bfs(startx-1,starty-1,goalx-1,goaly-1,n,m,k);
    cout<<res<<endl;
}

int main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    run();
}
