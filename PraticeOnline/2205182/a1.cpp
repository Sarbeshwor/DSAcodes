#include <iostream>
#include "Maxheap.h"
using namespace std;

int main(){

    int m,n;
    cin>>m;
    cin>>n;
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        cin>>arr[i];
    }

    MaxHeap maxHeap;

    for (int i = 0; i < m; i++)
    {
        maxHeap.insert(arr[i]);
    }
    int total=0;

    for (int i = 0; i < n; i++)
    {
        int maxseats=maxHeap.extractMax();

        total=total+maxseats;
        if (maxseats>1)
        {
            maxHeap.insert(maxseats-1);
        }
        
    }
    cout<<total<<endl;
   
    
    
}