#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 


int rec_binary(int A[],int l ,int r,int y)
{
    //printf("%d %d %d\n",l,r,y);
    int rec = (l+r)/2;
    //char pass;
    //pass = getchar();
    if(rec == 1 || rec == 0)
    {
        if(A[rec]!= y)
            return -1;
        else 
            return rec;
    }
    if(A[rec]>y)
        return rec_binary(A,l,rec,y);
    else if(A[rec]<y)
        return rec_binary(A,rec,r,y);
    else  
        return rec;

}

int main()
{
    int x=1,y=1,z=0;
    while(1)
    {
        
        scanf("%d %d",&x,&y);
        int A[x];
        for(int i = x ;i <= y ;i++)
            A[i-1] = i;
        printf("Enter the number you want find:\n");
        scanf("%d",&z);
        int a = rec_binary(A,x,y-1,z);
        printf("%d is on the %d\n",z,a);
    }
    
    
}