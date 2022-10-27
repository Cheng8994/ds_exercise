#include "merge.cpp"

using namespace std;

template<typename t>
int binary_search(t *a,int right,t k){
    int mid = right/2 , left = 0;
    while( a[mid] != k)
    {
        if(left+1 == right)
            return -1;
        if(a[mid] > k)
            right = mid;
        else
            left = mid;
        mid = (right + left)/2;
    }
    return mid;
}

