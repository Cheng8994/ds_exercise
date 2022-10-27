#include<iostream>
#include<random>
#include <time.h> 

using namespace std;


void generate(int *ptr,int length)
{
    srand( time(NULL) );
    for(int i = 0;i < length ; i++)
    {
        int x = rand()%17;
        *(ptr+i) = x;
    }
}
template <typename t>
void swap(t *a,t *b)
{
    t c = *a;
    *a = *b;
    *b = c;
}