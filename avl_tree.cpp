#include "my_stack.cpp"
#include "mqueue.cpp"
template <typename t> class avl_tree;
template <typename t>
class avl_node
{
private:
    t data;
    t* left,right;
    int height;
    friend class avl_tree;
public:
    avl_node(const t &a){data = a,left= nullptr,right = nullptr;}
    avl_node(){left = nullptr , right = nullptr;}
};

template <typename t>
class avl_tree
{
private:
    void maintain();
    avl_node<t> *root;
public:
    avl_tree(const t &a){
        avl_node<t> temp(a);
        temp.left = nullptr,temp.right = nullptr;
        root = temp; 
    }
    avl_tree(){
        avl_node<t> temp;
        temp.left = nullptr,temp.right = nullptr;
    }
    void _insert(const t &a , avl_node<t> *ptr);
    void _delete(const t &a);
    void insert(const t &a){
        _insert(t,root);
    }

};
template <typename t>
void avl_tree<t>::_insert(const t &a , avl_node<t> *ptr)
{
    if(!ptr)
    {
        avl_node<t> temp(a);
        ptr = &temp;
    }
    if(a > ptr)
        _insert(a,ptr->left);
    else if ( a < ptr)
        _insert(a,ptr->right)
    else 
        return;
        
}
