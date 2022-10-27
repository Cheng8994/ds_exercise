#include "generate.cpp"
using namespace std;

template <typename t>
t* split(t *a,int k,int pivot)
{
    t x = a[pivot],b[k];
    int p1= 0,p2 = k-1;
    for(int i = 0 ; i <  k ; i ++ )
    {
        if(i == pivot)
            continue;
        if(a[i] <= x )
            b[p1++] = a[i];
        else
            b[p2--] = a[i];
    }
    for(int i = 0 ; i < k ; i++)
        a[i] = b[i];
    a[p1] = x;
    return a;

}
template <typename t>
void quick(t *a,int k)
{
    
}
int main()
{
    while(1)
    {
        int size= 0;
        cin >> size;
        int a[size];
        generate(a,size);
        for(int i = 0 ; i< size;i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "pivot is : " << a[size/2]<<endl;
        split(a,size,size/2);
        for(int i = 0 ; i< size;i++)
            cout << a[i] << " ";
        cout << endl;


    }
}