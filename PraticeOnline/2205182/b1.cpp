#include <iostream>
#include "MaxHeap.h"
using namespace std;
int main(){

    int N ,K;
    cin>>N;
    cin>>K;
    int arr[N];
    MaxHeap candices;
    for (int i = 0; i < N; i++)
    {
        cin>>arr[i];
    }
    

    for (int i = 0; i < N; i++)
    {
        candices.insert(arr[i]);
    }
    int candy=0;
    for (int i = 0; i < K; i++)
    {
        int max = candices.extractMax();
        candy=max+candy;
        if(max>1){
            candices.insert(candy/2);
        }
    }
    cout<<candy;
    

}