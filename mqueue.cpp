#include <iostream>
#include <string.h>
using namespace std;
template<class KeyType>
class c_queue
{
private:
    int front;
    int rear;
    int capcity;
    void queue_full();
    KeyType *queue;
public:
    c_queue(int max = 10);
    bool is_full();
    bool is_empty();
    void push_back(const KeyType& x);
    KeyType pop();
};
template<class KeyType>
void c_queue<KeyType>::queue_full()
{
    cout << "queue is full"<<endl;
}
template<class KeyType>
c_queue<KeyType>::c_queue(int max):capcity(max)
{
    front = rear = 0;
    queue = new KeyType[max];
}
template<class KeyType>
bool c_queue<KeyType>::is_full()
{
    return front == (rear +1)%capcity?true:false;
}
template<class KeyType>
bool c_queue<KeyType>::is_empty()
{
    return front==rear?true:false;
} 
template<class KeyType>
void c_queue<KeyType>::push_back(const KeyType& x)
{
    if(is_full())
        queue_full();
    else
        queue[rear=(rear+1)%capcity] = x;
}
template<class KeyType>
KeyType c_queue<KeyType>::pop()
{
    if(is_empty())
    {
        return 0;
    }
    front = (front+1)%capcity;
    return queue[front];
}
