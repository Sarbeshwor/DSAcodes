#include<iostream>
#include<limits.h>
// #include<vector>
using namespace std;

int main(){
    // int arr[9] = {-10, 3, -2, 5, -1, 4, -9, 6, 3};
    // int arr[9] = {-9, 6, 3,-10, 3, -2, 5, -1, 4};
    int arr[9] = {6, 3,-9, 5, 2, -2, 4, -9, 9};
    int n = 9;

    int sum = 0;
    int max = INT_MIN;
    int start = -1, end = -1, tempStart = 0;

    for (int i = 0; i < n; i++)
    {
        sum +=arr[i];

        if(sum > max)
        {
            max = sum;
            start = tempStart;
            end = i;
        }
        int arrLen = end - start;
        int currLen = i - tempStart;
        if(sum == max && currLen < arrLen)
        {
            start = tempStart;
            end = i;
        }
        if(sum <= 0)
        {
            sum = 0;
            tempStart = i + 1;
        }
    }
    cout << max << endl;

    for(int i = start; i <= end; i ++)
    {
        cout << arr[i] << " "; 
    }
    
    return 0;
}
