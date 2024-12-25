#include <iostream>
#include <limits.h>
using namespace std;
// int max(int a ,int b){
//     if (a>=b)
//     {
//         return a;
//         }

//     return b;

// }

int longsum(int arr[], int n, int &start, int &end)
{
    if (n == 1)
    {
        start = 0;
        end = 0;
        return arr[0];
    }
    int m = n / 2;
    int leftIndex, leftEnd;
    int rightIndex, rightEnd;

    int leftSUM = longsum(arr, m, leftIndex, leftEnd);
    int rightSUM = longsum(arr + m, n - m, rightIndex, rightEnd);

    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int sum = 0;
    int leftCROSSstart = m - 1;
    int rightCROSSend = m;

    for (int i = m - 1; i >= 0; i--)
    {
        sum += arr[i];
        if (sum > leftSum)
        {
            leftSum = sum;
            leftCROSSstart = i;
        }
    }
    sum = 0;
    for (int i = m; i < n; i++)
    {
        sum += arr[i];
        if (sum > rightSum)
        {
            rightSum = sum;
            rightCROSSend = i;
        }
    }
    // int crossingsum=rightSUM+
    // if (leftSUM>=rightSUM && leftSUM>=leftsum+rightsum)
    // {
    //     start=leftIndex;
    //     end=leftEnd;
    //     return leftSUM;

    // }
    // else if (rightSUM>=leftSUM && rightSUM>=leftsum+rightsum)
    // {
    //     start=rightIndex+m;
    //     end=rightEnd+m;
    //     return rightSUM;
    // }
    // else
    // {
    //     start=leftCROSSstart;
    //     end=rightCROSSend;
    //     return leftsum+rightsum;
    // }
    if (leftSUM > rightSUM && leftSUM > (leftSum + rightSum))
    {
        start = leftIndex;
        end = leftEnd;
        return leftSUM;
    }
    else if (rightSUM > leftSUM && rightSUM > (leftSum + rightSum))
    {
        start = rightIndex + m;
        end = rightEnd + m;
        return rightSUM;
    }
    else if (leftSUM == rightSUM && leftSUM == (leftSum + rightSum))
    {
        int leftLen = leftEnd - leftIndex+1;
        int rightLen = rightEnd - rightIndex+1;
        int crossLen = rightCROSSend - leftCROSSstart+1;

        if (leftLen<=rightLen && leftLen<=crossLen)
        {
            start = leftIndex;
            end = leftEnd;
            return leftSUM;
        }
        else if (rightLen<=leftLen && rightLen<=crossLen)
        {
            start = rightIndex + m;
            end = rightEnd + m;
            return rightSUM;
        }
        else
        {
            start = leftCROSSstart;
            end = rightCROSSend;
            return leftSum + rightSum;
        }
    }
        
       
}
    // return leftSUM+rightSUM;


int main()
{
    int n;
    int start = 0, end = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = longsum(arr, n, start, end);
    cout << "[";
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << " ]" << endl;
    cout << ans << endl;
}

