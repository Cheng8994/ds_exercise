// C++ code
#include <iostream>
#include <string>
using namespace std;
template<typename Type> class LinkedList; 
class PolyList;
class polynode;
template<typename Type> class ListNode
{
private:
    friend class LinkedList<Type>;
    friend class PolyList;
    friend class polynode;
public:
    Type data;
    ListNode *next;
    ListNode *prev;

    ListNode<Type>():data(0),next(nullptr){};

};
template<typename Type> class LinkedList{
    friend class PolyList;
    friend class polynode;
private:
public:
    int size; 
    ListNode<Type> *first; 
    ListNode<Type> *last; 
    LinkedList<Type>():first(nullptr){
        first = nullptr;
        last = nullptr;
        size = 0;
    };
    void PrintList();           // 印出list的所有資料
    void RevePrint();
    void Push_front(Type x);     // 在list的開頭新增node
    void Push_back(Type x);      // 在list的尾巴新增node
    void Delete(Type x);         // 刪除list中的 int x
    void Clear();               // 把整串list刪除
    void insert(ListNode<Type>* ptr,Type x);
    int pop_front();
    int pop_back();
    void concatenate(LinkedList<Type>* ptr2);
    ListNode<Type>* find(Type x);
};
template<typename Type>
void LinkedList<Type>::Clear()
{
    ListNode<Type> *ptr = first,*temp = first;
    while (ptr!=nullptr )
    {
        temp = ptr->next;
        delete ptr;
        ptr = temp;
    }
    last = first = temp = ptr =nullptr;
    size = 0;
}
template<typename Type>
void LinkedList<Type>::insert(ListNode<Type>* ptr,Type x)
{
    size++;
    ListNode<Type> *new_ptr = new (ListNode<Type>[1]);
    new_ptr->data = x;
    new_ptr->prev = ptr;
    new_ptr->next = ptr->next;
    ptr->next = new_ptr;
    new_ptr->next->prev = new_ptr;
}
template<typename Type>
ListNode<Type>* LinkedList<Type>::find(Type x)
{
    ListNode<Type> *ptr = first;
    while(ptr!= nullptr)
    {
        if(ptr->data == x)
            break;
        ptr = ptr->next;
    }
    return ptr;
}
template<typename Type>
void LinkedList<Type>::Delete(Type x)
{
    ListNode<Type> *ptr = find(x),*temp;
    if( ptr == nullptr)
    {
        cout << x <<" is not in the list"<<endl;
        return;
    }
    size--;
    temp = ptr->prev;
    temp->next = ptr->next;
    temp->next->prev = temp;
    delete ptr;
    ptr = nullptr;
    temp = nullptr;
    
}
template<typename Type>
void LinkedList<Type>::Push_back(Type x)
{
    //size++;
    ListNode<Type> *ptr = new ListNode<Type>[1];
    ptr->data = x;
    ptr->next = nullptr;
    if (first == nullptr || last == nullptr)
        first = ptr;
    else
    {
        last->next = ptr;
        ptr->prev = last;
    }
    last = ptr;
}
template<typename Type>
void LinkedList<Type>::Push_front(Type x)
{
    size++;
    ListNode<Type> *ptr = new ListNode<Type>[1];
    ptr->data = x;
    ptr->prev = nullptr;
    if(last == nullptr || first == nullptr)
        last = ptr;
    else
    {
        first->prev = ptr;
        ptr->next = first;
    }
    first = ptr;
}
template<typename Type>
void LinkedList<Type>::PrintList()
{
    ListNode<Type> *ptr = first;
    if(first == nullptr)
    {
        cout << "The list is empty "<<endl;
        return;
    }
    while(ptr != nullptr)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout << endl;
}
template<typename Type>
void LinkedList<Type>::RevePrint()
{
    ListNode<Type> *ptr = last;
    if(last == nullptr)
    {
        cout << " The list is empty "<<endl;
        return;
    }
    while(ptr != nullptr)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->prev;
    }
    cout << endl;
}
template<typename Type>
int LinkedList<Type>::pop_front()
{
    ListNode<Type> *ptr = first;
    first = first->next;
    ptr->next = nullptr;
    first->prev = nullptr;
    return ptr->data;
}
template<typename Type>
int LinkedList<Type>::pop_back()
{
    ListNode<Type> *ptr = last;
    last = last->prev;
    ptr->prev = nullptr;
    last->next = nullptr;
    return ptr->data;
}
template<typename Type>
void LinkedList<Type>::concatenate(LinkedList<Type>* ptr)
{
    ListNode<Type> *ptr1 = last;
    ListNode<Type> *ptr2 = ptr->first;
    ptr1->next = ptr2;
    ptr2->prev = ptr1;
}
