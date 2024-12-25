#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class UnionData {
    
    public:
    vector<int> parent,rank;
    UnionData(int n){
        parent.resize(n,-1);
        rank.resize(n,1);
        for (int i = 0; i < n; ++i)
        {
            parent[i]=i;
        }
        
    }
    int find(int u){
        if (parent[u]!=u)
        {
            parent[u]=find(parent[u]);
        }
        return parent[u];
        
    }

    void unionSets(int u, int v){
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV){
            if (rank[rootU]> rank[rootV])
            {
                /* code */
                parent[rootV]= rootU;

            }
            else if(rank[rootU]< rank[rootV]){
                parent[rootU]= rootV;
            }
            else{
                parent[rootU]= rootV;
                rank[rootV]++;
            }
            
        }
    }
};

struct Edge{
    int weight,u,v;
    // Edge(int w, int a, int b){
    //     weight = w;
    //     u = a;
    //     v = b;

    // }
    bool operator<(const Edge &other) const{
        return weight < other.weight;
    }
};

bool compareEdge(Edge &a, Edge &b){
    return a.weight < b.weight;
}

struct Compare{
    bool operator()(Edge& a, Edge& b){
        return a.weight >b.weight;
    }
};


// class Graph{
//     int V;

// }



int kruksal(int n, vector<Edge> &edges, UnionData &dsu, int mstWeight, int mstEdges){
    for (const auto& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unionSets(edge.u, edge.v);
            mstWeight += edge.weight;
            mstEdges++;
        }
        
        if (mstEdges == n - 1) {
            break; 
        }
    }
    return mstWeight;
}

int main(){
    ifstream inputfile("input.txt");
    ofstream outputfile("output.txt");

    int n,m;
    inputfile>>n>>m;

    vector<Edge> edges(m);
        // cout << "Hello" << endl;

    for(int i=0; i<m; ++i){
        inputfile >> edges[i].weight >> edges[i].u >> edges[i].v;
        // int u,v,w;
        // inputfile >> u >> v >> w;
        // edges.push_back(Edge(w,u,v));
    }
    // cout << "Hello" << endl;


    sort(edges.begin(),edges.end());
        // cout << "Hello" << endl;

    UnionData dsu(n);
    int mstWeight = 0;
    int mstEdges = 0;
        // cout << "Hello" << endl;


    int ans = kruksal(n,edges,dsu,mstWeight,mstEdges);

    outputfile << ans<<endl;

    // int ans = kruskal(n,edges,dsu,mstWeight,mstEdges);
    // cout<<ans<<endl;
    // cout<<"Hello"<<endl;
    // outputfile<<ans<<endl;
    return 0;

   
    

}