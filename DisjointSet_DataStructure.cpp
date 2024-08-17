#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// class DisjointSet {
//     vector<int> rank, parent;
// public:
//     DisjointSet(int n){
//         rank.resize(n+1, 0);
//         parent.resize(n+1);
//         for(int i=0; i<=n; i++){
//             parent[i] = i;
//         }
//     }

//     int findUPar(int node){
//         if(node == parent[node]) return node;
//         return parent[node] = findUPar(parent[node]);
//     }

//     void unionByRank(int u, int v){
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if(ulp_u == ulp_v) return;
//         if(rank[ulp_u] < rank[ulp_v]){
//             parent[ulp_u] = ulp_v;
//         }
//         else if(rank[ulp_u] > rank[ulp_v]){
//             parent[ulp_u] = ulp_v; 
//         }
//         else{
//             parent[ulp_u] = ulp_v;
//             rank[ulp_v]++;
//         }
//     }
// };

class DisjointSet {
    vector<int> size, parent;
public:
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

int main(){
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"Same";
    }
    else{
        cout<<"Not same"<<endl;
    }
    ds.unionBySize(3, 7);
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not same";
    }
    return 0;
}