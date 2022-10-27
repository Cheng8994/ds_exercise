#include "generate.cpp"

using namespace std;
template <typename t>
void bubble(t *a , int n)
{
    for(int i= 0 ; i< n;i++)
        for (int j = n-1; j > i ; j--)
            if(a[j] < a[j-1])
                swap(a+j,a+j-1);
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
        bubble(a,size);
        for(int i = 0 ; i< size;i++)
            cout << a[i] << " ";
        cout << endl;


    }
}