#include <stdio.h>
#include <stdlib.h>
#define Max 500
typedef struct 
{
    int row,column,value;
}term;
typedef struct 
{
    term *smA;
    int cap;
    int act_row;
    int act_col;
}sparse_matrix;
sparse_matrix transpose_sparse(sparse_matrix sm)
{
    sparse_matrix new_sm;
    new_sm.cap = sm.cap;
    new_sm.smA = malloc(sm.cap*sizeof(*sm.smA));
    int arr[Max][2],mmax = 0;
    new_sm.act_row = sm.act_col;
    new_sm.act_col = sm.act_row;
    for(int i = 0;i<Max;i++)
        arr[i][0]=arr[i][1] = 0;
    for(int i = 0;i<sm.cap;i++)
    {
        arr[(sm.smA+i)->column][0]++;
        if((sm.smA+i)->column > mmax)
            mmax = (sm.smA+i)->column;
    }
    arr[0][1]= 0;
    for(int i = 1 ; i<= mmax;i++)
        arr[i][1] = arr[i-1][1] + arr[i-1][0];
    for(int i = 0;i<sm.cap;i++)
    {
        int temp = (sm.smA+i)->row;
        (sm.smA+i)->row = (sm.smA+i)->column;
        (sm.smA+i)->column = temp;
        *(new_sm.smA+arr[(sm.smA+i)->row][1]) = *(sm.smA+i);
        arr[(sm.smA+i)->row][1]++;
    }
    return new_sm;
}
void print_sm(sparse_matrix sm)
{
    printf("row |column |value \n");
    printf("-------------------\n");
    for(int i = 0;i<sm.cap; i++)
        printf("%4d|%7d|%5d\n",(sm.smA+i)->row,(sm.smA+i)->column,(sm.smA+i)->value);
    printf("-------------------\n");
}
void print_as_normal(sparse_matrix sm)
{
    int rows[sm.act_col];
    for(int i = 0 ; i <sm.act_col;i++)
        rows[i] = 0;
    int current_row = 0;
    for(int i = 0 ; i < sm.cap;i++)
    {
        if(current_row != (sm.smA+i)->row)
        {
            for(int j = 0; j<sm.act_col;j++)
            {
                printf("%d ",rows[j]);
                rows[j] = 0;
            }
            printf("\n");
            current_row++;
        }
        rows[(sm.smA+i)->column] = (sm.smA+i)->value;
    }
    for(int i = current_row ;i < sm.act_row;i++)
    {
        for(int j = 0; j<sm.act_col;j++)
        {
            printf("%d ",rows[j]);
            rows[j] = 0;
        }
        printf("\n");
    }
}
int main()
{
    term temp;
    sparse_matrix sm1,sm2;
    int x = 3;
    sm1.cap = 3;
    sm1.act_col = 3;
    sm1.act_row = 3;
    sm1.smA = malloc(x*sizeof(temp));
    temp.row = 0;
    temp.column = 2;
    temp.value = 3;
    *(sm1.smA + 0) = temp;
    temp.row = 1;
    temp.column = 1;
    temp.value = 4;
    *(sm1.smA + 1) = temp;
    temp.row = 1;
    temp.column = 2;
    temp.value = 3;
    *(sm1.smA + 2) = temp;
    print_sm(sm1);
    sm2 = transpose_sparse(sm1);
    print_sm(sm2);
    sm2 = transpose_sparse(sm2);
    print_sm(sm2);
    print_as_normal(sm2);
    
}