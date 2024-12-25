#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// int temp;

void matrix(vector<vector<int>> &mat, int x, int y)
{
    mat[x][y] = 1;
    mat[y][x] = 1;
}
// void print(vector<vector<int>> & mat){
//     for (int i = 0; i < mat.size(); i++)
//     {
//         /* code */
//         for (int j = 0; j < mat.size(); j++)
//         {
//             /* code */
//             cout<<mat[i][j]<<" ";
//         }

//     }

// }

void bfstraversal(int start, vector<bool> &visited, vector<vector<int>> &mat)
{
    // vector<bool> visited(mat.size(),false);

    queue<int> q;
    q.push(start);

    visited[start] = true;

    int temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        for (int i = 0; i < mat[temp].size(); i++)
        {
            if (mat[temp][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
void alonenodes(int n, vector<vector<int>> &mat)
{vector<int> alone;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
    
        if(!visited[i]){
                bfstraversal(1,visited,mat);
                break;

        }
    }
    
    // bfstraversal(1,visited,mat);
    // cout << "starting" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {

            bfstraversal(i, visited, mat);
            alone.push_back(i);

        }
    }
    // cout<<"done"<<endl;
    // for (int i = 1; i < mat.size(); i++)
    // {
    //     if (!visited[i])
    //     {
    //         alone.push_back(i);

    //     }

    // }
    // cout<<"done"<<endl;

    int smallestnode = -1;
    for (int i = 1; i <= mat.size(); i++)
    {
        if (!mat[i].empty())
        {
            smallestnode = i;
            break;
        }
    }

    // }
    // if (isConnected)
    // {
    //     smallestnode=i;
    //     break;
    // }
    // }
    // cout<<"done"<<endl;
    // for (int i = 0; i < alone.size(); i++)
    // {
    //     cout<<alone[i]<<endl;
    // }

    cout << alone.size() << endl;
    for (int i = 0; i < alone.size(); i++)
    {
        cout << smallestnode << " " << alone[i] << endl;
        matrix(mat, smallestnode, alone[i]);
        smallestnode = alone[i];
    }
}