#include "generate.cpp"

using namespace std;
template <typename t>
void selection(t *a,int n)
{
    t *min = a;
    for(int i = 0 ; i < n ;i++)
    {
        min = a + i; 
        for(int j = i; j < n;j++)
            if ( a[j] < *min)
                swap(a+j,min);     
    }
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
        selection(a,size);
        for(int i = 0 ; i< size;i++)
            cout << a[i] << " ";
        cout << endl;


    }
}