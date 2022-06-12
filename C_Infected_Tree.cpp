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

int dfs(vector<vector<int>> &graph, int u, vector<int> &visited,vector<int> &nodevalues){
    if(visited[u]){
        return -1;
    }
    visited[u]=1;
    int ans=0;
    for(int i=0;i<graph[u].size();i++){
       ans+=dfs(graph,graph[u][i],visited,nodevalues)+1;
    }
    return nodevalues[u]=ans;
}
int getheight(vector<vector<int>> &graph,int u,vector<int> &visited,vector<int> &heights){
    if(visited[u]){
        return -1;
    }
    visited[u]=1;
    int ans=0;
    for(auto i:graph[u]){
        ans=max(getheight(graph,i,visited,heights)+1,ans);
    }
    return heights[u]=ans; 
}
int getresult(vector<vector<int>> &graph,int u,vector<int> &visited,vector<int> &heights,vector<int> &nodesv){
    if(visited[u]){
        return 0;
    }
    visited[u]=1;
    int ans=0;
    int index=0;
    int largest=0;
        for(auto i:graph[u]){
            if(visited[i]){
                continue;
            }
            if(heights[i]>heights[largest]){
                largest=i;
            }
            if(heights[i]<heights[index]){
                index=i;
            }
        }
    if(graph[u].size()==2){
        return nodesv[index];
    }
    return getresult(graph,index,visited,heights,nodesv)+nodesv[largest];
}
void run(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> graph(n);
        vector<vector<pii>> levels(n);
        fora(i,n-1){
            int u,v;
            cin>>u>>v;
            graph[u-1].pb(v-1);
            graph[v-1].pb(u-1);
        }
        vector<int> nodevalues(n);
        vector<int> visited(n);
        vector<int> heights(n);
        dfs(graph,0,visited,nodevalues);
        for(auto i:nodevalues){
            cout<<i<<" ";
        }
        cout<<endl;
        
        visited.assign(n,0);
        getheight(graph,0,visited,heights);
        for(auto i:heights){
            cout<<i<<" ";
        }
        cout<<endl;
        visited.assign(n,0);
        stack<int> st;
        st.push(0);
        int level=0;
        while(!st.empty()){
            int u=st.top();
            st.pop();
            visited[u]=1;
            for(auto i:graph[u]){
                if(!visited[i]){
                    levels[level].pb(mkp(heights[i],i));
                    st.push(i);
                }
            }
            level++;
        }
        visited.assign(n,0);
        int sum=getresult(graph,0,visited,heights,nodevalues);
        // for(auto i:levels){
        //     sort(i.begin(),i.end());
        //     // for(auto j:i){
        //     //     cout<<j.first<<" "<<j.second<<" ";
        //     // }
        //     // cout<<endl;
        //     if(i.size()>0){
        //         cout<<i[0].first<<"\n";
        //         sum+=nodevalues[i[0].second];
        //     }else{
        //         break;
        //     }
            
        // }
        cout<<sum<<endl;
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
