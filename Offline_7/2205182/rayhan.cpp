#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int CrossingSubArray(vector<int> &arr, int l, int m, int h, int &start_index, int &end_index)
{
    int left_max = INT_MIN, right_max = INT_MIN;
    int sum = 0;
    int temp_start = m;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_max)
        {
            left_max = sum;
            temp_start = i;
        }
    }
    sum = 0;
    int temp_end = m;
    for (int i = m + 1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_max)
        {
            right_max = sum;
            temp_end = i;
        }
    }
    start_index = temp_start;
    end_index = temp_end;
    return left_max + right_max;
}
int maximumSubArray(vector<int> &arr, int l, int h, int &start_index, int &end_index)
{
    if (l == h)
    {
        start_index = end_index = l;
        return arr[l];
    }
    int m = l + (h - l) / 2;
    int left_start, left_end, right_start, right_end, cross_start, cross_end;
    int leftSubArray = maximumSubArray(arr, l, m, left_start, left_end);
    int rightSubArray = maximumSubArray(arr, m + 1, h, right_start, right_end);
    int crossSubArray = CrossingSubArray(arr, l, m, h, cross_start, cross_end);
    int left_len = left_end - left_start +1;
    int right_len = right_end - right_start +1;
    int cross_len = cross_end - cross_start +1;
    if (leftSubArray >= rightSubArray && leftSubArray >= crossSubArray)
    {
        if (leftSubArray == rightSubArray && left_len > right_len) // if two sub array same return shortest subarray
        {
            start_index = right_start;
            end_index = right_end;
            return rightSubArray;
        }
        if (leftSubArray == crossSubArray && left_len > cross_len)
        {
            start_index = cross_start;
            end_index = cross_end;
            return crossSubArray;
        }
        else
        {
            start_index = left_start;
            end_index = left_end;
            return leftSubArray;
        }
    }
    if (rightSubArray >= leftSubArray && rightSubArray >= crossSubArray)
    {
        if (rightSubArray == crossSubArray && right_len > cross_len)
        {
            start_index = cross_start;
            end_index = cross_end;
            return crossSubArray;
        }
        else
        {
            start_index = right_start;
            end_index = right_end;
            return rightSubArray;
        }
    }
    else
    {
        start_index = cross_start;
        end_index = cross_end;
        return crossSubArray;
    }
}
int main()
{
    vector<int> arr;
    int num,size;
    cout <<"Enter number of round: ";
    cin>>size;
    while (size--)
    {   cin >> num;
        arr.push_back(num);
    }
    int n = arr.size();
    int start = 0, end = 0;
    int max_sum = maximumSubArray(arr, 0, n - 1, start, end);

    for (int i = start; i <= end; i++)
    {
        if (i == start)
            cout << "[";
        cout << arr[i];
        if (i == end)
            cout << "]";
        else
            cout << ", ";
    }
    cout << " with sum of " << max_sum;

    return 0;
}