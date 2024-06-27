#include<iostream>
using namespace std;

class List
{
public:
    class Node
    {
    public:
        Node(int e =0 , Node *n=nullptr);
        int node_value;
        Node *next_node;
    };
    
    const bool empty();
    int front();
    Node *begin();
    Node *end();
    int size();
    void push_front(int);//insert to front of List
    int pop_front();//delete of front of List
    void erase(int);//delete by given number
    void push(int,int);//insert to List by given index
    void print();
    int count(int);
    int avg();
    void reverse();
    
private:
    Node *list_head=NULL;
};

//cunstactor
List::Node::Node(int e , Node *n)
{
    node_value=e;
    next_node=n;
}

//pardazesh list
//find the number of duplicates
int List::count(int n)
{
    Node *ptr=new Node(list_head->node_value , list_head->next_node);
    int node_count=0;
    for(int i=0 ; i<size() ; i++)
    {
        if(ptr->node_value == n)
        {
            node_count++;
        }
        ptr=ptr->next_node;
    }
    return node_count;
}

//find the average of the total value of the list
int List::avg()
{
    int m;
    int sum =0;
    Node *ptr=new Node(list_head->node_value , list_head->next_node);
    for (int i=0 ; i<size() ; i++)
    {
        sum=sum+(ptr->node_value);
        ptr=ptr->next_node;
    }
    m=sum/size();
    return m;
}

//the list is empty
const bool List::empty()
{
    return (list_head==nullptr);
}

//point to the beginning of the list
List::Node *List ::begin()
{
    return list_head;
}

//refer to the end of the list
List::Node *List::end()
{
    return nullptr;
}

//show the first value of the list
int List::front()
{
    if ( empty() )
        return -1 ;
    
    return begin()->node_value;
}

//add to the first of list
void List::push_front(int n)
{
    if( empty() )
        list_head = new Node(n , nullptr);
    else
        list_head = new Node(n , begin() );
}

//delete from the first of list
int List::pop_front()
{
    if( empty() )
        return -1;
    int e =front();
    Node *ptr=list_head;
    list_head=list_head->next_node;
    delete ptr;
    return e;
}

//size list
int List::size()
{
    int c=1;
    Node *n=new Node(list_head->node_value , list_head->next_node);
    while(n->next_node!=nullptr)
    {
        c++;
        n=n->next_node;
    }
    return c;
}

//remove the desired node from the list
void List::erase(int a)
{
    Node *pn=new Node(list_head->node_value , list_head->next_node);
    Node *n=new Node(list_head->node_value , list_head->next_node);
    int t;
    for(int i=0 ; i<size() ; i++)
    {
        if(n->node_value==a)
        {
            t=i;
            break;
        }
        else
        {
            pn=n;
            n=n->next_node;
        }
    }
    
    if(t==0)
        list_head=list_head->next_node;
    if(t==size()-1)
        pn->next_node=nullptr;
    else
    {
        pn->next_node=n->next_node;
    }
}

//add node anywhere int the list
void List::push(int index , int data)
{
    Node *n=new Node(list_head->node_value , list_head->next_node);
    for(int i=1 ; i<index ; i++)
    {
        n=n->next_node;
    }
    Node *m=new Node(data,n->next_node);
    n->next_node=m;
    if(index==1)
    {
        list_head->next_node=m;
    }
}

void List::print()
{
    Node *n=list_head;
    while(n!=NULL)
    {
        cout << n->node_value<<"  ";
        n=n->next_node;
    }
    
}
//reverse the list
void List::reverse()
{
    Node *pn=NULL;
    Node *n=NULL;
    while (list_head!=NULL)
    {
        n=list_head->next_node;
        list_head->next_node=pn;
        pn=list_head;
        list_head=n;
    }
    list_head=pn;
}


int main()
{
    List l1;
    int x;
    int y;
    int m;
    int index;
    while (1)
    {
        cout <<"Enter 1/2/3/4/5/6/7/8 or -1 for Stop"<<endl;
        cout<<"1.push_front"<<endl<<"2.push"<<endl<<"3.pop_front"<<endl<<"4.erase"<<endl<<"5.printlist?"<<endl<<"6.count"<<endl<<"7.avg"<<endl<<"-1->STOP"<<endl;
        cin>>x;
        if(x==-1)
            break;
        
        if(x==1)
        {
            cout <<"Enter num : ";
            cin>>y;
            l1.push_front(y);
            cout <<endl;
        }
        if(x==2)
        {
            cout << "Enter index : ";
            cin>>index;
            cout <<"Enter num : ";
            cin>>y;
            l1.push(index , y);
            cout <<endl;
        }
        
        if(x==3)
        {
            l1.pop_front();
            cout <<endl;
        }
        if(x==4)
        {
            cout<<"Enter num for erase : ";
            cin>>y;
            l1.erase(y);
            cout <<endl;
        }
        
        if(x==5)
        {
            cout<<"List --> ";
            l1.print();
            cout <<endl;
        }
        
        if(x==6)
        {
            cout << "enter num for counter : ";
            cin >> m;
            cout << l1.count(m);
            cout << endl;
        }
        if(x==7)
        {
            cout<< "avg = "<< l1.avg()<<endl;
        }
        
        if(x==8)
        {
            l1.reverse();
            cout<<endl;
            l1.print();
            cout<<endl;
        }
       
         
    }
    return 0;
}
