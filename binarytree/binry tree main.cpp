#include<iostream>
using namespace std;
//binary tree
class Tree
{
public:
    void insert(int,char,int);
    int size_Tree();
    const string is_root(int);
    const string is_leaf(int);
    int Tree_height();
    int return_parent(int);//node_parent
    int return_height(int);//node_height
    void print();
    
    int BT[24]={0};//BT--->Binary Tree
    
    class Stack{
    public:
        int stack[24];
        void push(int);
        int pop();
        int top=-1;
    };
    
    //PEIMAYESH
    void BFS();
    void DFS_or_PreOrder();
    void InOrder();
    void PostOrder();
};

//adding to the array using the parent and getting left or right and the value
void Tree::insert(int p , char LorR , int v)
{
    int index_parent;
    if(p==0 && LorR=='0')
        BT[1]=v;
    
    else
    {
        for(int i=0 ; i<24 ; i++)
        {
            if(BT[i]==p)
            {
                index_parent=i;
            }
        }
        if(LorR=='l')
        {
            BT[2*index_parent]=v;
        }
        if(LorR=='r')
        {
            BT[(2*index_parent)+1]=v;
        }
    }
}


int Tree::size_Tree()
{
    int c=0;
    for(int i=0 ; i<24 ; i++)
    {
        if(BT[i]!=0)
            c++;
    }
    return c;
}

//checking if the node is root?
const string Tree::is_root(int a)
{
    if(a==BT[1])
        return "True";
    else
        return "False";
}
//checking if the node is leaf?
const string Tree::is_leaf(int a)
{
    int index_laef=0;
    for(int i=0 ; i<24 ; i++)
    {
        if(BT[i]==a)
            index_laef=i;
    }
    if(BT[2*index_laef]==0 && BT[(2*index_laef)+1]==0)
        return "True";
    else
        return "False";
}

int Tree::Tree_height()
{
    int max1=0;//root_height
    
    for(int i=1 ; i<24 ; i++)
    {

        if(return_height(BT[i])>max1)
        {
            max1=return_height(BT[i]);
        }
    }
    return max1;
}

//return the parent of the received node
int Tree::return_parent(int a)
{
    int parent=0;
    int index_a=0;
    if(a==BT[1])
        return 0;
    for(int i=0 ; i<24 ;i++)
    {
        if(a==BT[i])
            index_a=i;
        
    }
    parent=BT[index_a/2];
    return parent;
}

//return the height of the received node
int Tree::return_height(int a)
{
    int height_a=0;
    if(a==BT[1])
        return 0;
    else if(a==0)
        return NULL;
    else
        height_a=return_height(return_parent(a))+1;
    
    return height_a;
}

void Tree::print()
{
    
    for(int i=0 ; i<24 ; i++)
    {
        cout<<BT[i]<<"   ";
    }
}


void Tree::Stack::push(int a)
{
    stack[top+1]=a;
    top++;
}
int Tree::Stack::pop()
{
    return stack[top--];
}


void Tree::BFS()
{
    for(int i=0 ; i<24; i++)
    {
        if(BT[i]!=0)
            cout<<BT[i]<<"  ";
    }
}

void Tree::DFS_or_PreOrder()
{
    Stack s1;
    s1.push(BT[1]);
    int i=1;
    int x=s1.pop();
    cout<<x<<"  ";
    int t=1;
    while(1)
    {
        if(t==size_Tree())
            break;
        if(BT[(2*i)+1]!=0 && BT[(2*i)]!=0 )
        {
            s1.push(BT[(2*i)+1]);
            s1.push(BT[2*i]);
        }
        else if(BT[(2*i)+1]!=0 && BT[(2*i)]==0 )
        {
            s1.push(BT[(2*i)+1]);
        }
        else if(BT[(2*i)+1]==0 && BT[(2*i)]!=0 )
        {
            s1.push(BT[2*i]);
        }
        x=s1.pop();
        t++;
        cout<<x <<"  ";
        for(int j=0 ; j<24 ; j++)
        {
            if(x==BT[j])
                i=j;
        }
    }
}

void Tree::InOrder()
{
    int BT2[24];
    for(int i=0 ; i<24 ; i++)
    {
        BT2[i]=BT[i];
    }
    
    Stack s2;
    s2.push(BT2[1]);
    int i=1;
    int t=0;
    //int n=BT2[1];
    while (1)
    {
        if(t==size_Tree())
            break;
        
        for(int j=0 ; j<24; j++)
        {
            if(s2.stack[s2.top] == BT[j])
            {
                i=j;
            }
        }
        
        if(BT2[2*i]==0 && BT2[(2*i)+1]==0)
        {
            cout<< s2.pop() <<"  ";
            BT2[i]=0;
            t++;
        }
        
        else if(BT2[(2*i)+1]!=0 && BT2[(2*i)]==0)
        {
            cout<< s2.pop() <<"  ";
            t++;
            BT2[i]=0;
            s2.push(BT2[(2*i)+1]);
        }
        else if(BT2[2*i]!=0 && BT2[(2*i)+1]!=0)
        {
            s2.push(BT2[2*i]);
        }
        else if(BT2[2*i]!=0 && BT2[(2*i)+1]==0)
        {
            s2.push(BT2[2*i]);
        }
    }
}

void Tree::PostOrder()
{
    int BT3[24];
    for(int i=0 ; i<24 ; i++)
    {
        BT3[i]=BT[i];
    }
    
    int i=1;
    Stack s3;
    s3.push(BT3[i]);
    int t=0;
    
    while (1)
    {
        if(t==size_Tree())
            break;
        
        for(int j=0 ; j<24; j++)
        {
            if(s3.stack[s3.top] == BT[j])
            {
                i=j;
            }
        }
        
        
        if(BT3[2*i]==0 && BT3[(2*i)+1]==0)
        {
            cout<<s3.pop() <<"  ";
            BT3[i]=0;
            t++;
        }
        else if(BT3[(2*i)+1]!=0 && BT3[(2*i)]==0)
        {
            s3.push(BT3[(2*i)+1]);
        }
        else if(BT3[2*i]!=0 && BT3[(2*i)+1]!=0)
        {
            s3.push(BT3[2*i]);
        }
        else if(BT3[2*i]!=0 && BT3[(2*i)+1]==0)
        {
            s3.push(BT3[2*i]);
        }
    }
}

int main()
{
    Tree t1;
    
    t1.insert(0 , '0', 3);
    t1.insert(3, 'l', 9);
    t1.insert(3 , 'r', 5);
    t1.insert(9, 'l', 14);
    t1.insert(9 , 'r', 10);
    t1.insert(5, 'l', 6);
    t1.insert(5, 'r', 8);
    t1.insert(10, 'l', 13);
    t1.insert(10, 'r', 23);
    cout<<"T1: ";
    t1.print();
    cout <<endl;
    
    cout<<endl;
    cout<<"tree_height: " <<t1.Tree_height()<<endl;
    cout <<endl;
    
    cout <<"root: "<< t1.is_root(3)<<endl;
    cout <<endl;
    
    cout<<"lseaf :" <<t1.is_leaf(14)<<endl;
    cout <<endl;
    
    cout<<"parent : " <<t1.return_parent(13)<<endl;
    cout <<endl;
    
    cout<<"height: "<<t1.return_height(23)<<endl;
    cout <<endl;
    
    cout << "tree size: "<<t1.size_Tree()<<endl;
    cout <<endl;
    //bfs
    cout <<"BFS: ";
    t1.BFS();
    cout <<endl<<endl;
    
    //dfs or preorder
    cout <<"DFS or PreOrder: ";
    t1.DFS_or_PreOrder();
    cout<<endl<<endl;
    
    //inorder
    cout<<"InOrder: ";
    t1.InOrder();
    cout<<endl<<endl;
    
    //postorder
    cout<<"PostOrder: ";
    t1.PostOrder();
    cout<<endl<<endl;
    
    return 0;
}
