#include <iostream>
using namespace std;
template<class KeyType>
class my_stack
{    
public:
    void push(const KeyType& x);
    KeyType pop();
    bool is_full();
    bool is_empty();
    my_stack(int max = 10);
    int top;
    int capacity;
    KeyType *stack;
private:

    void stack_full();

};
template<class KeyType>
my_stack<KeyType>::my_stack(int max):capacity(max)
{
    stack = new KeyType[max];
    top=-1;
}
template<class KeyType>
void my_stack<KeyType>::stack_full()
{
    cout << "is full now"<<endl;
}
template<class KeyType>
void my_stack<KeyType>::push(const KeyType& x)
{
    if(is_full())
        stack_full();
    else
        stack[++top] = x;
}
template<class KeyType>
KeyType my_stack<KeyType>::pop()
{
    if(is_empty())
        return 0;
    return stack[top--];
    //x = stack[top--];
    //return &x;
}
template<class KeyType>
bool my_stack<KeyType>::is_empty()
{
    if(top == -1)
        return true;
    else
        return false;
}
template<class KeyType>
inline bool my_stack<KeyType>::is_full()
{
    if(top == capacity-1)
        return true;
    else
        return false;  
}

