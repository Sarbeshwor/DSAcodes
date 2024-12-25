#include <iostream>

using namespace std;

struct Result{
    int start,end,sum;
};

Result bestoption(Result a, Result b){
    if(b.sum>a.sum || (b.sum==a.sum && (b.end-b.start<a.end-a.start))){
        return b;
    }
    return a;

}
Result Crossingsum(int arr[], int l, int m, int h){
    int left_sum=INT_MIN, sum =0;
    
}