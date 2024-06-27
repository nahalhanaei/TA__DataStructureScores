#include<iostream>
#include <math.h>
using namespace std;
class Tree
{
public:
    int tree[100]={0};
    int tree2[100]={0};
    int size_tree();
    void insert_checkBST(int);
    void check_avl(int);
    void fix_avl();
    int return_hight(int);
    void print();
    
};

int Tree::size_tree()
{
    int c=0;
    for(int i=0 ; i<100 ; i++)
    {
        if(tree[i]!=0)
            c++;
    }
    return c;
}

//adding node and checking for BST at the same time (that is: i put the value as BST)
void Tree::insert_checkBST(int a)
{
    int index=1;
    if(tree[1]==0)
        tree[1]=a;
    else
    {
        while (1)
        {
            if(a<tree[index])
            {
                if(tree[2*index]==0)
                {
                    tree[2*index]=a;
                    break;
                }
                else
                    index=2*index;
            }
            
            else if(a>tree[index])
            {
                if(tree[(2*index)+1]==0)
                {
                    tree[(2*index)+1]=a;
                    break;
                }
                else
                    index=(2*index)+1;
            }
        }
    }
}

//finding the state of the node that is not in equilibrium
void Tree::check_avl(int a)
{
    for(int i=1 ; i<size_tree(); i++)
    {
       if(abs( return_hight(tree[2*i]) - return_hight(tree[(2*i)+1]) )>1)
       {
           //is not avl
           if(a<tree[i] && a<tree[2*i])
               tree2[i]=1;
           else if(a<tree[i] && a>tree[2*i])
               tree2[i]=2;
           else if(a>tree[i] && a>tree[(2*i)+1])
               tree2[i]=3;
           else if (a>tree[i] && a< tree[(2*i)+1])
               tree2[i]=4;
       }
       else
       {
           //is avl
           tree2[i]=0;
       }
    }
    /*
    cout << "tree2 : ";
    for(int i=0 ; i<size_tree() ; i++)
        cout<<tree2[i]<<" " ;
    cout<<endl;
    
    */
    for(int i=0 ; i<size_tree(); i++)
    {
        if(tree2[i]!=0)
            fix_avl();
    }
}

//solving mthe imbalance problem
void Tree::fix_avl()
{
    int tree_halat1[100];
    
    for(int i=0 ; i<100; i++)
    {
        tree_halat1[i]=-1;
    }
    
    int root=tree[1];
    int c=1;
    for(int i=0 ; i<size_tree()+20; i++)
    {
        if(tree2[i]!=0)
        {
            //1
            if(tree2[i]==1)
            {
                tree_halat1[i]=tree[2*i];
                tree_halat1[2*i]=tree[2*(2*i)];
                tree_halat1[(2*i)+1]=tree[i];
                tree_halat1[2*((2*i)+1)]=tree[(2*(2*i))+1];
                tree_halat1[(2*((2*i)+1))+1]=tree[(2*i)+1];
            }
            
            //2
            if(tree2[i]==2)
            {
                tree_halat1[i]=tree[(2*(2*i))+1];
                tree_halat1[(2*(2*i))+1]=tree[2*((2*(2*i))+1)];
                tree_halat1[(2*i)+1]=tree[i];
                tree_halat1[2*((2*i)+1)]=tree[(2*((2*(2*i))+1))+1];
                tree_halat1[2*i]=tree[2*i];
            }
            
            //3
            if(tree2[i]==3)
            {
                tree_halat1[i]=tree[(2*i)+1];
                tree_halat1[2*i]=tree[i];
                tree_halat1[(2*i)+1]=tree[(2*((2*i)+1))+1];
                tree_halat1[(2*(2*i))+1]=tree[2*((2*i)+1)];
            }
            
            //4
            if(tree2[i]==4)
            {
                tree_halat1[2*i]=tree[i];
                tree_halat1[i]=tree[2*((2*i)+1)];
                tree_halat1[(2*i)+1]=tree[(2*i)+1];
                tree_halat1[2*((2*i)+1)]=tree[(2*(2*((2*i)+1)))+1];
                tree_halat1[(2*(2*i))+1]=tree[2*(2*((2*i)+1))];
            }
            
            break;
            
        }
        else
            tree_halat1[i]=tree[i];
    }
    
    for(int i=0 ; i<size_tree()+20 ; i++)
    {
        if(tree_halat1[i]==-1)
        {
            int parent =tree_halat1[i/2];
            for(int j=0 ; j<size_tree()+20 ; j++)
            {
                if(tree[j]==parent)
                {
                    if(i%2==0)
                       tree_halat1[i]=tree[2*j];
                    if(i%2!=0)
                        tree_halat1[i]=tree[(2*j)+1];
                }
            }
        }
    }
    
    
    for(int i=0 ; i<size_tree()+20; i++)
    {
        tree[i]=tree_halat1[i];
    }
    cout<<endl;
}

int Tree::return_hight(int node)
{
    int index_node;
    if(tree[1]==0)
        return -1;
    
    for(int i=0 ; i<size_tree()+20 ; i++)
    {
        if(tree[i]==node)
            index_node=i;
    }
    
    if(tree[2*index_node]==0 && tree[(2*index_node)+1]==0)
        return 0;
    
   else if(tree[2*index_node]==0 && tree[(2*index_node)+1]!=0)
        return 1;
    
    else if(tree[2*index_node]!=0 && tree[(2*index_node)+1]==0)
        return 1;
    else
    {
        int max=(return_hight(tree[2*index_node])+1);
        if((return_hight(tree[(2*index_node)+1])+1)>max)
            max=(return_hight(tree[(2*index_node)+1])+1);
        
        return max;
    }
}


void Tree::print()
{
    for(int i=0 ; i<size_tree()+20 ; i++)
    {
        cout<<tree[i]<<"  ";
    }
    
}

int main()
{
    
    Tree t1;
    t1.insert_checkBST(36);
    t1.insert_checkBST(12);
    t1.insert_checkBST(44);
    t1.insert_checkBST(7);
    t1.insert_checkBST(23);
    t1.insert_checkBST(38);
    t1.insert_checkBST(45);
    t1.insert_checkBST(3);
    t1.insert_checkBST(10);
    t1.insert_checkBST(17);
    t1.insert_checkBST(27);
    t1.insert_checkBST(6);
    cout<<"Tree_1: ";
    t1.print();
    cout<<endl;
    t1.check_avl(6);
    cout<<"AVL:    ";
    t1.print();
    cout<<endl<<"-------"<<endl;
    Tree t2;
    t2.insert_checkBST(21);
    t2.insert_checkBST(6);
    t2.insert_checkBST(26);
    t2.insert_checkBST(3);
    t2.insert_checkBST(18);
    t2.insert_checkBST(24);
    t2.insert_checkBST(29);
    t2.insert_checkBST(1);
    t2.insert_checkBST(5);
    t2.insert_checkBST(10);
    t2.insert_checkBST(19);
    t2.insert_checkBST(14);
    cout<<"Tree_2: ";
    t2.print();
    cout<<endl;
    t2.check_avl(14);
    cout<<"AVL:    ";
    t2.print();
    cout<<endl <<"-------"<<endl;
    
    Tree t3;
    t3.insert_checkBST(36);
    t3.insert_checkBST(12);
    t3.insert_checkBST(57);
    t3.insert_checkBST(7);
    t3.insert_checkBST(23);
    t3.insert_checkBST(51);
    t3.insert_checkBST(73);
    t3.insert_checkBST(44);
    t3.insert_checkBST(62);
    t3.insert_checkBST(87);
    t3.insert_checkBST(67);
    cout<<"Tree_3: ";
    t3.print();
    cout<<endl;
    t3.check_avl(67);
    cout<<"AVL:    ";
    t3.print();
    cout<<endl <<"-------"<<endl;
    
    Tree t4;
    t4.insert_checkBST(36);
    t4.insert_checkBST(12);
    t4.insert_checkBST(72);
    t4.insert_checkBST(7);
    t4.insert_checkBST(23);
    t4.insert_checkBST(53);
    t4.insert_checkBST(83);
    t4.insert_checkBST(44);
    t4.insert_checkBST(61);
    t4.insert_checkBST(95);
    t4.insert_checkBST(67);
    cout<<"Tree_4: ";
    t4.print();
    cout<<endl;
    t4.check_avl(67);
    cout<<"AVL:    ";
    t4.print();
     
    return 0;
}
