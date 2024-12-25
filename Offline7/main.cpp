#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

typedef struct {
    int start,end,size,total;

}numbers;

numbers maxinbetween(int arr[], int left, int mid, int right){
    int leftsum = INT_MIN, rightsum = INT_MIN, sum =0;
    int leftmax=mid, leftright = mid+1;

    for (int i = mid; i >= left; i--)
    {
        sum+=arr[i];
        if (sum>leftsum)
        {
            leftsum=sum;
            leftmax=i;
        }
        
    }
    sum=0;
    for (int i = mid+1; i <=right; i++)
    {
        sum+=arr[i];
        if (sum>rightsum)
        {
            rightsum=sum;
            leftright=i;
        }
    }
    numbers result = {leftsum+rightsum, leftmax, leftright, leftright-leftmax+1};
    return result;
    

}


int main(){

    vector <int> list;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    // hotteststreak(arr,n);


}