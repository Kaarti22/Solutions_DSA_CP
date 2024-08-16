#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<n+1; i++){
            parent[i] = i;
            size[i] = 1;
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

    void UnionBySize(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main(){
    // Using rank
    DisjointSet ds1(7);
    ds1.UnionByRank(1, 2);
    ds1.UnionByRank(2, 3);
    ds1.UnionByRank(4, 5);
    ds1.UnionByRank(6, 7);
    ds1.UnionByRank(5, 6);
    
    // if 3 and 7 are connected
    if(ds1.findUltimateParent(3) == ds1.findUltimateParent(7)){
        cout<<"Connected"<<endl;
    } else {
        cout<<"Not connected"<<endl;
    }

    ds1.UnionByRank(3, 7);

    // if 3 and 7 are connected
    if(ds1.findUltimateParent(3) == ds1.findUltimateParent(7)){
        cout<<"Connected"<<endl;
    } else {
        cout<<"Not connected"<<endl;
    }

    // Using size
    DisjointSet ds2(7);
    ds2.UnionBySize(1, 2);
    ds2.UnionBySize(2, 3);
    ds2.UnionBySize(4, 5);
    ds2.UnionBySize(6, 7);
    ds2.UnionBySize(5, 6);
    
    // if 3 and 7 are connected
    if(ds2.findUltimateParent(3) == ds2.findUltimateParent(7)){
        cout<<"Connected"<<endl;
    } else {
        cout<<"Not connected"<<endl;
    }

    ds2.UnionBySize(3, 7);

    // if 3 and 7 are connected
    if(ds2.findUltimateParent(3) == ds2.findUltimateParent(7)){
        cout<<"Connected"<<endl;
    } else {
        cout<<"Not connected"<<endl;
    }
    return 0;
}