#include <iostream>
// #include "bfs.h"
#include "dfs.h"
using namespace std;

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<vector<int>> list(n+1);
    // vector<vector<int>> mat(n+1, vector<int>(n+1,0));
    // vector<vector<int>> mat;
    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));


    for (int i = 0; i < m; i++)
    {   int a;
        int b;
        cin>>a;
        cin>>b;
        
        edges(list,a,b);
        // matrix(mat,a,b);
       

        
    }
// print(mat);
    // cout<<"allnodes"<<endl;
    alonenodes(n,list);
    return 0;

}