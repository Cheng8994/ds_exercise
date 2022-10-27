#include<stdio.h>

void c_swap(char *a,int s, int e)
{
    char c = *(a+s);
    *(a+s) = *(a+e);
    *(a+e) = c;
}

void perm(char *a,int s,int e)
{
    if(s == e)
    {
        printf("{");
        for(int i = 0;i<e-1;i++)
            printf("%c,",a[i]);
        printf("%c}",a[e-1]);
        printf("\n");
    }
    else
    {
        for(int i = s;i<e;i++)
        {
            c_swap(a,s,i);
            perm(a,s+1,e);
            c_swap(a,s,i);
        }
    }
}
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        fgetchar();
        char cs[n];
        for(int i =0;i<n;i++)
            cs[i] = fgetchar();
        printf("==============\n");
        perm(cs,0,n);
        printf("==============\n");
    }
}