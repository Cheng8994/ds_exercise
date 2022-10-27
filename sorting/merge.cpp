#include "generate.cpp"

using namespace std;

void merge(int *a,int *b,int la,int lb)
{
    int pa=0,pb=0;
    int temp[lb+la];
    for(int i = 0; i<lb+la;i++)
    {
        if( pa >= la)
        {
            temp[i] = *(b+pb);
            pb++;
        }
        else if (pb >= lb)
        {
            temp[i] = *(a+pa);
            pa++;
        }
        else if( *(a+pa)  < *(b+pb))
        {
            temp[i]=*(a+pa);
            pa++;
        }
        else 
        {
            temp[i]=*(b+pb);
            pb++;
        }
    }
    for(int i =0 ; i< lb+la;i++)
        *(a+i) = temp[i];
}
void merge_sort(int *ptr,int length)
{
    int *a = ptr,*b = ptr+length/2;
    if(length == 1)
        return;
    merge_sort(a,length/2);
    merge_sort(b,length - length/2);
    merge(a,b,length/2,length - length/2);
}



