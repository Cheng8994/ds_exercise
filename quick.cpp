#include<iostream>
#include<random>
#include <time.h> 
using namespace std;


void generate_random_array(int *ptr,int length)
{
    srand( time(NULL) );
    for(int i = 0;i < length ; i++)
    {
        int x = rand()%17;
        *(ptr+i) = x;
    }
}
void split_two_seg(int *ptr,int n,int pivot)
{
    int temp[n];
    for(int i = 0;i<n;i++)
        temp[i] = *(ptr+i);
}
void quick_sort(int *ptr)
{
    
}

int main()
{
    int length = 0;
    while(1)
    {
        cin >> length;
        int A[length];
        int* ptr = A;
        generate_random_array(ptr,length);
        for(int i = 0;i<length;i++)
            cout << A[i] << " ";
        cout << endl;
        quick_sort(ptr);
        for(int i = 0;i<length;i++)
            cout << A[i] << " ";
        cout << endl;
    }
}
