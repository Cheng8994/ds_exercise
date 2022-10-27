#include<iostream>
#define default 10
using namespace std;

template<typename T>
class max_heap
{
private:
    T heap[10];
    int last;
    void handler(int x);
    void heap_swap(int x,int y){
        T temp = heap[x];
        heap[x] = heap[y];
        heap[y]=temp;}
public:
    void print_tree()
    {
        for(int i = 1 ; i < last ; i++)
            cout << heap[i]<<" ";
        cout <<endl;
    }
    max_heap(){last = 1;}
    T delete_max();
    void push(const T &x);
};
template<typename T>
void max_heap<T>::handler(int x)
{
    if(heap[x] > heap[x/2] && x> 1)
    {
        heap_swap(x,x/2);
        handler(x/2);
    }
    //cout << heap[x] << " ";
    if(2*x > last-1)
        return;
    T left =heap[2*x]  ,right = heap[2*x+1];
    if(heap[x] < left || heap[x] < right)
    {
        if(left > right)
        {
            heap_swap(x,2*x);
            handler(2*x);
        }
        else
        {
            heap_swap(x,2*x+1);
            handler(2*x+1);
        }
    }
}
template<typename T>
void max_heap<T>::push(const T &x)
{
    heap[last++] = x;
    handler(last-1);
}
template<typename T>
T max_heap<T>::delete_max()
{
    T res = heap[1];
    heap[1] = heap[--last];
    handler(1);
    return res;
}

template<typename T>
class min_heap
{
private:
    T heap[10];
    int last;
    void handler(int x);
    void heap_swap(int x,int y){
        T temp = heap[x];
        heap[x] = heap[y];
        heap[y]=temp;}
public:
    void print_tree()
    {
        for(int i = 1 ; i < last ; i++)
            cout << heap[i]<<" ";
        cout <<endl;
    }
    min_heap(){last = 1;}
    T delete_min();
    void push(const T &x);
};

template<typename T>
void min_heap<T>::handler(int x)
{
    if(heap[x] < heap[x/2] && x> 1)
    {
        heap_swap(x,x/2);
        handler(x/2);
    }
    if(2*x > last-1)
        return;
    T left =heap[2*x]  ,right = heap[2*x+1];
    if(heap[x] > left || heap[x] > right)
    {
        if(left < right)
        {
            heap_swap(x,2*x);
            handler(2*x);
        }
        else if(2*x > last)
        {
            heap_swap(x,2*x+1);
            handler(2*x+1);
        }
    }
}
template<typename T>
void min_heap<T>::push(const T &x)
{
    heap[last++] = x;
    handler(last-1);
}
template<typename T>
T min_heap<T>::delete_min()
{
    T res = heap[1];
    heap[1] = heap[--last];
    handler(1);
    return res;
}



