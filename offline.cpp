#include <bits/stdc++.h>


using namespace std;
int find(vector<int> &parent, int u){
    if(parent[u]==u)
        return u;
    return find(parent,parent[u]);
}

void Union(int a, int b, vector<int> &parent) {
    int x = find(parent, a);
    int y = find(parent, b);
    parent[x] = y;
}
void printComponents(vector<int> &parent,vector<set<int>> &components) {
    for(int i=1;i<parent.size();i++){
        int p = find(parent,i);
        components[p].insert(i);
    }
}
int main(){
    int n,t;
    cin>>n>>t;
    vector<int> parent(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    while(t--){
        int type;
        cin>>type;
        if(type==1){
            int x,y;
            cin>>x>>y;
            Union(x,y,parent);
        }else if(type==2){
            vector<set<int>> components(n+1);
            printComponents(parent,components);
            int x=0;
            for(int i=1;i<=n;i++){
                if(components[i].size()>0){
                    x++;
                }
            }
            cout<<"No. of components: "<<x<<endl;
            for(int i=1;i<=n;i++){
                if(components[i].size()>0){
                    for(auto &j:components[i]){
                        cout<<j<<" ";
                    }
                    cout<<endl;
                }
            }
        }


    }
}