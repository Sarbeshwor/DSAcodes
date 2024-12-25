#include <iostream>
#include <vector>
// #include <string.h>

using namespace std;
void matching(string first, string second)
{
    int n = first.size();
    int m = second.size();
    // vector<bool> dp(n + 1, false);

    vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
    dp[0][0]=true;

    for (int j = 1; j <= m; j++)
    {
        if (second[j-1]=='*')
        {
            dp[0][j]=dp[0][j-2];
        }
        else if (second[j-1]=='+')
        {
            dp[0][j]=false;
        }
        
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
            
            if(second[j-1]==first[i-1]|| second[j-1]=='.'){
                dp[i][j]=dp[i-1][j-1];
            }
            else if(second[j-1]=='*'){
                dp[i][j]=dp[i][j-2];
                if (second[j-2]==first[i-1]||second[j-2]=='.')
                {
                    dp[i][j]=dp[i][j] || dp[i-1][j];
                }

                
            }
            else if (second[j-1]=='+'){
                if (second[j-2]==first[i-1]|| second [j-2]=='.')
                {
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-1];
                }
                
            }
        }
       
        
        
    }
    
    
    // dp[0] = true;
    // for (int i = 0; i < n; i++)
    // {

    //     if (first[i] == second[i] || first[i] == '.')
    //     {
    //         dp[i]=true;
    //     }
    //     else if (second[i]=='*')

    //     {
    //         char a=second[i-1];
    //         for (int k = i; k < n; k++)
    //         {
    //             if (first[k]=a)
    //             {
    //                 dp[k]=true;
    //             }
    //             else{
    //                 break;
    //             }
    //             i=k;
    //         }
            
            
            
    //     }

        
    // }
 if (dp[n][m])
        {
            cout<<"True";
        }
        else{
            cout<<"False";
        }
}

int main()
{
    string first;
    string second;
    cin >> first;
    cin >> second;
    matching(first,second);
}