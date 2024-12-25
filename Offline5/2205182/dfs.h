#include <iostream>
#include <vector>

using namespace std;

void edges(vector<vector<int>> &list, int a, int b)
{
    list[a].push_back(b);
    list[b].push_back(a);
}
void dfstraversal(int n, vector<vector<int>> &list, vector<bool> &visited)
{
    visited[n] = true;
    for (int neighbor : list[n])
    {
        if (!visited[neighbor])
        {
            dfstraversal(neighbor, list, visited);
        }
    }
}
void alonenodes(int nodes, vector<vector<int>> &list)
{
    // cout<<"hello"<<endl;
    vector<int> alone;
    vector<bool> visited(nodes + 1, false); 
    dfstraversal(1, list, visited);
    for (int i = 1; i < nodes; i++)
    {
        if (!visited[i])
        {
            alone.push_back(i);
        }
    }
    int smallestnode = -1;
    for (int i = 1; i <= list.size(); i++)
    {
        if (!list[i].empty())
        {
            smallestnode = i;
            break;
        }
    }
    cout<<alone.size()<<endl;
    for (int i = 0; i < alone.size(); i++)
    {
        cout << smallestnode << " " << alone[i] << endl;
        edges(list, smallestnode, alone[i]);
        smallestnode = alone[i];
    }
}
// void traverse(vector <int> list[], int n){
//     vector <int> alone;
//     for (int i = 1; i <= n; i++)
//     {
//         if (list[i].empty())
//         {
//             alone.push_back(i);
//         }

//     }
//     cout<<alone.size()<<endl;

//     int smallestnode=-1;

//     for(int i=1; i<=n; i++){
//         if (!list[i].empty())
//         {
//             smallestnode=i;
//             break;
//         }

//     }
//     for (int i = 0; i < alone.size(); i++)
//     {
//         cout<<smallestnode<<" "<<alone[i]<<endl;
//         dfs(list, smallestnode,alone[i]);
//         smallestnode=alone[i];
//     }

// }