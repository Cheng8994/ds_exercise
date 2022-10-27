#include<iostream>
#include "heap.cpp"
#include "binary_tree.cpp"
using namespace std;
int main()
{
    min_heap<int> a;
    a.push(9);
    //a.print_tree();
    a.push(8);
    a.print_tree();
    a.push(7);
    a.push(6); 
    a.push(5);
    a.push(4);
    a.push(3);
    a.push(2);
    a.push(1);
    a.print_tree();
    //cout << a.delete_max() << " "<<endl;
    a.delete_min();
    a.delete_min();
    //a.delete_max();
    //a.delete_max();

    a.print_tree();

    linked_node<int> ac(-1),b(5);
    if(ac>b)
        cout << "a is largger"<<endl;
    else
        cout << "b is largger"<<endl;
}