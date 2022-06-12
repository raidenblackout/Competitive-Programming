#include<bits/stdc++.h>
using namespace std;

# define INF 9999999

typedef pair<int, int> edgeWeightPair;

class Graph
{
    int V;
    list<edgeWeightPair> *adj;
    vector< vector< int  > > dist ;
    vector< vector< int  > > e ;

public:
    Graph(int V) ///Constructer
    {
        this->V = V;
        adj = new list<edgeWeightPair> [V];
        dist = vector< vector< int > > (V , vector< int > (V , INF)) ;
        e = vector< vector< int > > (V , vector< int > (V , INF)) ;
        for(int i = 0 ; i < V ; i ++ ) dist[i][i] = e[i][i] = 0 ; 
    }
    void addEdge(int u, int v, int w) ///adjacency List Development
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
        e[v][u] = e[u][v] = dist[u][v] = dist[v][u] = w ;
    }
    void Floyd_Warshall(){
        for(int k = 0 ; k < V ; k ++ ){
            for(int i = 0 ; i < V ; i ++ ){
                for(int j = 0 ; j < V ; j ++ ){
                    if(dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j] ;
                    }
                }
            }
        }
    }
    int edge_weight(int node1 , int node2){
        return e[node1][node2] ;
    }
    int getDist(int node1 , int node2){
        return dist[node1][node2] ;
    }
};
void generateSets(vector<vector<int>> &sets,int i, int l,vector<int> &v){
    if(i == l){
        if(binary_search(v.begin(),v.end(),0) && binary_search(v.begin(),v.end(),l-1)){
            sets.push_back(v);
        }
        return ;
    }
    v.push_back(i);
    generateSets(sets,i+1,l,v);
    v.pop_back();
    generateSets(sets,i+1,l,v);
}

int main()
{
    int tc ;
    cin >> tc ;
    while(tc -- ){
        int n , m , l;
        cin >> n >> m >> l ;
        vector< int > b(l) ;
        for(int i = 0 ; i < l ; i ++ ){
            cin >> b[i] ;
            b[i] -- ;
        }
        Graph g(n) ;
        for(int i = 0 ; i < m ; i ++ ){
            int x , y , c ;
            cin >> x >> y >> c ;
            x -- ; y -- ;
            g.addEdge(x , y , c) ;
        }
        g.Floyd_Warshall() ;
        vector<int> cumulativeDistance(l , 0) ;
        cumulativeDistance[0] = 0 ;
        for(int i = 1 ; i < l; i ++ ){
            cumulativeDistance[i]=cumulativeDistance[i-1]+g.edge_weight(b[i-1] , b[i]) ;
        }
        vector<vector<int>> sets ;
        vector<int> v ;
        generateSets(sets , 0 , l , v);
        sort(sets.begin(),sets.end());
        bool pp=0;
        int mm=1e9;
        for(auto &x : sets){
            bool correct=true;
            for(int i=0;i<x.size()-1;i++){
                int distance=cumulativeDistance[x[i+1]]-cumulativeDistance[x[i]];
                if(distance!=g.getDist(b[x[i]] , b[x[i+1]])){
                    correct=false;
                    break;
                }
            }
            if(correct){
                pp=1;
                mm=min(mm,(int)x.size());
                //break;
            }
        }
        if(pp) cout<<mm<<endl;
        if(!pp) cout<<"-1"<<endl;
    }
    return 0;
}