#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank, parent;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0; i<n+1; i++){
            parent[i] = i;
        }
    }

    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void UnionByRank(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main(){
    DisjointSet ds(7);
    ds.UnionByRank(1, 2);
    ds.UnionByRank(2, 3);
    ds.UnionByRank(4, 5);
    ds.UnionByRank(6, 7);
    ds.UnionByRank(5, 6);
    
    // if 3 and 7 are connected
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout<<"Connected"<<endl;
    } else {
        cout<<"Not connected"<<endl;
    }

    ds.UnionByRank(3, 7);

    // if 3 and 7 are connected
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout<<"Connected"<<endl;
    } else {
        cout<<"Not connected"<<endl;
    }
    return 0;
}