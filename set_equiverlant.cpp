#include "link_list.cpp"
#include "my_stack.cpp"


void out_set(bool *mark,int i,LinkedList<int> *A)
{
    ListNode<int> *ptr = A[i].first;
    while(ptr != nullptr)
    {
        if(!mark[ptr->data])
        {
            cout << ptr->data <<" ";
            mark[ptr->data] = true;
            out_set(mark,ptr->data,A);
        }
        mark[ptr->data] = true;
        ptr = ptr->next;
    }
}

void equvilant()
{
    int x=1,y=1,count =0;
    LinkedList<int> A[100];
    bool mark[12];
    for(int i = 0 ; i<12;i++)
        mark[i] = false;
    while(count <=100)
    {
        cin>>x; 
        if(x == -1)
            break;
        cin >> y;
        A[x].Push_front(y);
        A[y].Push_front(x);
        count++;
    }
    cout << "===================== " << endl;

    for(int i =0 ;i<=11;i++)
    {
        if(!mark[i])
        {
            cout << i <<" ";
            mark[i] = true;
            out_set(mark,i,A);
            cout << endl;
        }     
    }
}

int main()
{
    equvilant();
}
