#include<iostream>
using namespace std;
class Tree
{
public:
    int tree[100]={0};
    int size_tree();
    void insert(int);
    void erase_root();
    void print();
};

int Tree::size_tree()
{
    int t=1;
    int counter=0;
    while(tree[t]!=0)
    {
        counter++;
        t++;
    }
    return counter;
}

//add to the tree
void Tree::insert(int n)
{
    int tmp;
    int parent;
    tree[size_tree()+1]=n;//add to the last empty nod
    
    parent = size_tree()/2;
    int index_n=size_tree();
    while(n<tree[parent])
    {
        tmp=tree[parent];
        tree[parent]=n;
        tree[index_n]=tmp;
        index_n=parent;
        parent= index_n/2;
    }
}

//remove from the tree root
void Tree::erase_root()
{
    //we put the value of the root as the valu of the last node and set the valu of the last node to zero
    tree[1]=tree[size_tree()];
    tree[size_tree()]=0;
    int n=tree[1];
    int index_n=1;
    int tmp;
    while(1)
    {
        if(n>tree[2*index_n] && n>tree[(2*index_n)+1] && 2*index_n<=size_tree() && (2*index_n)+1 <=size_tree())
        {
            if(tree[2*index_n]<tree[(2*index_n)+1])
            {
                tmp=tree[2*index_n];
                tree[2*index_n]=n;
                tree[index_n]=tmp;
                index_n=2*index_n;
            }
            
            if(tree[2*index_n]>tree[(2*index_n)+1])
            {
                tmp=tree[(2*index_n)+1];
                tree[(2*index_n)+1]=n;
                tree[index_n]=tmp;
                index_n=(2*index_n)+1;
            }
        }
        
        else if(n>tree[2*index_n] && n<tree[(2*index_n)+1] && 2*index_n<=size_tree())
        {
            tmp=tree[2*index_n];
            tree[2*index_n]=n;
            tree[index_n]=tmp;
            index_n=2*index_n;
        }
        
        else if (n<tree[2*index_n] && n>tree[(2*index_n)+1] && (2*index_n)+1 <=size_tree())
        {
            tmp=tree[(2*index_n)+1];
            tree[(2*index_n)+1]=n;
            tree[index_n]=tmp;
            index_n=(2*index_n)+1;
        }
        
        else
            break;
    }
}

void Tree::print()
{
    for(int i=0 ; i<size_tree() ; i++)
    {
        cout<< tree[i] << "  ";
    }
}

int main()
{
    Tree t1;
    t1.insert(3);
    t1.insert(6);
    t1.insert(12);
    t1.insert(9);
    t1.insert(14);
    t1.insert(23);
    t1.insert(29);
    t1.insert(10);
    t1.insert(25);
    t1.insert(19);
    t1.insert(15);
    t1.insert(26);
    cout << "T1: ";
    t1.print();
    cout<<endl;
    t1.insert(8);
    cout << "T1: ";
    t1.print();
    
    cout<<endl<<endl;
    
    Tree t2;
    t2.insert(8);
    t2.insert(9);
    t2.insert(12);
    t2.insert(10);
    t2.insert(14);
    t2.insert(26);
    t2.insert(29);
    t2.insert(23);
    t2.insert(25);
    t2.insert(19);
    t2.insert(15);
    cout<<"T2: ";
    t2.print();
    cout<<endl;
    t2.erase_root();
    cout<<"T2: ";
    t2.print();
    cout<<endl;
    t2.erase_root();
    cout << "T2: ";
    t2.print();
    cout<<endl;


}
