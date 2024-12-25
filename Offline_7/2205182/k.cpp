#include <iostream>
#include <limits.h>
using namespace std;

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

    int crosssum = rightSum+leftSum;

    if (leftSUM>rightSUM&&leftSUM>crosssum)
    {
        start=leftIndex;
        end=leftEnd;
        return leftSUM;

    }
    else if (rightSUM>leftSUM&&rightSUM>crosssum)
    {
        start=rightIndex+m;
        end=rightEnd+m;
        return rightSUM;
    }
    else if (crosssum>=leftSUM&&crosssum>=rightSUM)
    {
        start=leftCROSSstart;
        end=rightCROSSend;
        return crosssum;
    }
    else if (rightSUM==leftSUM|| rightSUM==crosssum || leftSUM==crosssum){
        if (leftSUM==rightSUM && leftSUM==crosssum){
            if (leftEnd-leftIndex<rightEnd-rightIndex && leftEnd-leftIndex<rightCROSSend-leftCROSSstart){
                start=leftIndex;
                end=leftEnd;
                return leftSUM;
            }
            else if (rightEnd-rightIndex<leftEnd-leftIndex && rightEnd-rightIndex<rightCROSSend-leftCROSSstart){
                start=rightIndex+m;
                end=rightEnd+m;
                return rightSUM;
            }
            else{
                start=leftCROSSstart;
                end=rightCROSSend;
                return crosssum;
            }
        }
        else if (leftSUM==rightSUM){
            if (leftEnd-leftIndex<rightEnd-rightIndex){
                start=leftIndex;
                end=leftEnd;
                return leftSUM;
            }
            else{
                start=rightIndex+m;
                end=rightEnd+m;
                return rightSUM;
            }
        }
        else if (leftSUM==crosssum){
            if (leftEnd-leftIndex<rightCROSSend-leftCROSSstart){
                start=leftIndex;
                end=leftEnd;
                return leftSUM;
            }
            else{
                start=leftCROSSstart;
                end=rightCROSSend;
                return crosssum;
            }
        }
        else if (rightSUM==crosssum){
            if (rightEnd-rightIndex<rightCROSSend-leftCROSSstart){
                start=rightIndex+m;
                end=rightEnd+m;
                return rightSUM;
            }
            else{
                start=leftCROSSstart;
                end=rightCROSSend;
                return crosssum;
            }
        }
        
        
    }
    
    
    
    
    


}
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