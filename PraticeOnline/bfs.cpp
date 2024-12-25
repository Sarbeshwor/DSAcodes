#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Position{
    int x,y;
}
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
            if (mat[temp][i] == '.' && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
int main(){
    int n, m;
    cin>>n;
    cin>>m;
    Position start;
    vector<vector<char>> mat(n,vector<char>(m,'.'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < m; j++)
        {
            cin>>mat[i][j];
            if(mat[i][j]=='S'){
                start={i,j};
            }
        }
        
    }


}