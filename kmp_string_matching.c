#include <stdio.h>
#include <string.h>
int failure_table[80];
int failure_func(char *s,int n)
{
    int k = 0;
    int count = 0;
    for(int k = n ; k >=0; k--)
    {
        printf("%d \n",k);
        count = 0;
        for(int i = 0;i<k-1;i++)
        {
            printf("%c %c\n",s[i],s[n-k+i]);
            printf("%d %d\n",i,k);
            if(s[i] != s[n-k])
            {
                count = 1;
                break;
            }
                
        }
        if(count == 0)
            return k;
    }
}

int main()
{
    char pattern[80] = "abccaba";
    char string[1024];
    int a = failure_func(pattern,strlen(pattern));
    printf("%d \n",a);
    //scanf("%s",pattern);
}