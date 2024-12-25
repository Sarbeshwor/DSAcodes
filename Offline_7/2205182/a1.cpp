#include <iostream>
#include <string>

using namespace std;
int check(string &t, int start, int end)
{
    if (start>=end)
    {
        return 0;
    }
    int mid = (start+end)/2;
   

    int leftsum = check(t, start, mid);
    int rightsum = check(t, mid+1, end);
    
    int crossum=(t[mid]>t[mid+1] )?1:0;
    return leftsum+rightsum+crossum;
}
int checks(int arr[], int start, int end){
    if (start==end)
    {
        return 1;
    }
    int mid=(start+end)/2;

    int left= checks(arr, start, mid);
    int right=checks(arr,mid+1,end);
    int cross=(arr[mid]==arr[mid+1])?-1:0;
    return left+right+cross;

    
}

int main()
{
   
    // string t;
    // cin>>t;
    // // int start, end;
    // // start = 0;
    // // end = 0;

    // int result= check(t, 0,t.size()-1);
    // cout<<result;
    int m;
    cin>>m;
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        cin>>arr[i];
    }
    int ans=checks(arr,0,m-1);
    cout<<ans;

    
}