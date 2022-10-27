#include <iostream>
#include "my_stack.cpp"
#include "mqueue.cpp"
using namespace std;

template <typename T>
class array_binary_tree
{
private:

public:
    T *Datas;
    bool *mark;
    int capacity;
    int size;
    array_binary_tree(int size = 1);
    bool is_full(){ return size==capacity?true:false;}
    bool is_empty(){ return size==0?true:false;}
    void push_back(const T);
    void full_handler();
};
template <typename T>
void array_binary_tree<T>::full_handler()
{
    T *ns = new T[capacity*2];
    bool nm[capacity*2];
    for(int i = 0;i< capacity ;i++)
    {
        ns[i] = Datas[i];
        nm[i] = mark[i];
    }
    capacity *=2;
    mark = nm;
    Datas = ns;
}
template <typename T>
array_binary_tree<T>::array_binary_tree(int cap):capacity(cap)
{
    capacity = cap;
    Datas = new T[cap];
    mark = new bool[cap];
    size = 0;
}
template <typename T>
void array_binary_tree<T>::push_back(const T x)
{
    if(is_full())
        full_handler();
    mark[size] = true;
    Datas[size++] = x;
    //cout << Datas[size-1]<<endl;
}


template <typename T> class linked_tree;
template <typename T>
class linked_node
{
private:
    friend class linked_tree<T>;
public:
    bool mark;
    T data;
    int value;
    linked_node<T> *left,*right; 
    linked_node(){right = left = nullptr,mark = false,value = 0; }
    linked_node(T);
    friend bool operator>(const linked_node<T>& a,const linked_node<T> & b){return a.data > b.data?true:false;}
    friend bool operator>=(const linked_node<T> &a,const linked_node<T> &b){return a.data >= b.data?true:false;}
    friend bool operator<(const linked_node<T> &a,const linked_node<T> &b){return a.data < b.data?true:false;}
    friend bool operator<=(const linked_node<T> &a,const linked_node<T> &b){return a.data <= b.data?true:false;}
};
template <typename T>
linked_node<T>::linked_node(T x)
{
    data = x;
    left = nullptr;
    right = nullptr;
}




template <typename T>
class linked_tree
{
private:
    
public:
    linked_node<T> *root;
    linked_tree(){root = nullptr;}
    linked_tree(linked_node<T>* ptr){root = ptr;}
    void inorder(){inorder(root),cout<<endl;}
    void inorder(linked_node<T> *currentNode);
    void postorder(){postorder(root),cout<<endl;}
    void postorder(linked_node<T> *currentNode);
    void preorder(){preorder(root),cout<<endl;}
    void preorder(linked_node<T> *currentNode);
    void levelorder(){levelorder(root),cout<<endl;}
    void levelorder(linked_node<T> *currentNode);
    linked_node<T>* copy(linked_node<T> *);
    linked_tree(const linked_tree<T> &s){root = copy(s.root);}
};
template <typename T>
void linked_tree<T>::inorder(linked_node<T> *currentNode)
{
    if(currentNode != nullptr)
    {
        inorder(currentNode->left);
        cout << currentNode->data<<" ";
        inorder(currentNode->right);
    }
    return;
}
template <typename T>
void linked_tree<T>::preorder(linked_node<T> *currentNode)
{
    my_stack<linked_node<T>*> s;
    s.push(currentNode);
    while(!s.is_empty())
    {
        currentNode = s.pop();
        cout<< currentNode->data << " ";
        if(currentNode->right)
            s.push(currentNode->right);
        if(currentNode->left)
            s.push(currentNode->left);
    }
}
template <typename T>
void linked_tree<T>::postorder(linked_node<T> *currentNode)
{
    my_stack<linked_node<T>*> s;
    s.push(currentNode);
    while(!s.is_empty())
    {
        currentNode = s.pop();
        if(currentNode->mark)
            cout << currentNode->data << " ";
        else
        {
            s.push(currentNode);
            currentNode->mark = true;   
            if(currentNode->right )
                s.push(currentNode->right);    
            if(currentNode->left)
                s.push(currentNode->left);
        }   
    }
}
template <typename T>
void linked_tree<T>::levelorder(linked_node<T> *currentNode)
{
    c_queue<linked_node<T> *> q;
    q.push_back(currentNode);
    while(!q.is_empty())
    {
        currentNode = q.pop();
        cout << currentNode->data<<" ";
        if (currentNode->left)
            q.push_back(currentNode->left);
        if(currentNode->right)
            q.push_back(currentNode->right);
    }
}
template <typename T>
linked_node<T>* linked_tree<T>::copy(linked_node<T>* x)
{
    if(x)
    {
        linked_node<T> *temp = new linked_node<T>;
        temp->data = x->data;
        temp->left = copy(x->left);
        temp->right = copy(x->right);
        return temp;
    }
    return nullptr;
}



