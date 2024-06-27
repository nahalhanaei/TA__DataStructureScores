#include<iostream>
using namespace std;
class Polynomial {
public:
    class Node
    {
    public:
        Node(int coeff =0 , int deg=0 , Node *n=nullptr);
        int coefficient;
        int degree;
        Node *next;
    };
        bool empty();
        int size();
        void insert(int , int);
        void sum(Polynomial);
        void derivative(Polynomial);
        void Delete(int);
        int result(int);
        void print();
   
    private:
        Node *list_head =NULL;
};

//cunstactor
Polynomial::Node::Node(int c ,int d ,Node *n)
{
    coefficient=c;
    degree=d;
    next=n;
}

//the list is empty
bool Polynomial::empty()
{
    if(list_head==NULL)
        return true;
    else
        return false;
}

//size list
int Polynomial::size()
{
    int counter=1;
    if(empty())
        return 0;
    Node *p=list_head;
    while(1)
    {
        if(p->next==nullptr)
            break;
        else
        {
            p=p->next;
            counter++;
        }
    }
    return counter;
}

//get the value of coefficient and degree
void Polynomial::insert(int c, int d)
{
    Node *a=new Node(c, d ,nullptr);

    if(empty())
        list_head=a;
    
    else
    {
        Node *m1 , *m2;
        m1=list_head;
        m2=list_head;
        //insert to first of the list
        if(d>list_head->degree)
        {
            a->next=list_head;
            list_head=a;
        }
        //insert to list if d==degree of list
        else if(d==list_head->degree)
           list_head->coefficient += a->coefficient;
       
        else
        {
            for(int i=0 ; i<size() ; i++)
            {
                m1=m2;
                m2=m2->next;
                if(m2==nullptr)
                {
                    list_head->next=a;
                    a->next=nullptr;
                    break;
                }
               
                if(d>=m2->degree)
                {
                    if(d==m2->degree)
                        m2->coefficient+=a->coefficient;
                    else
                    {
                        m1->next=a;
                        a->next=m2;
                    }
                    break;
                }
                if(m2->next==nullptr)
                {
                    m2->next=a;
                    a->next=nullptr;
                    break;
                }
                
            }
        }
    }
}

//the sum function of tow polynomials
void Polynomial::sum(Polynomial p2)
{
    Node *a=new Node(0, 0 ,nullptr);
    Node *m1=new Node (list_head->coefficient ,list_head->degree  ,list_head->next);
    Node *m2=new Node (p2.list_head->coefficient ,p2.list_head->degree  ,p2.list_head->next);
    
    while (1)
    {
        if(m1==nullptr)
        {
            
            while(m2 !=nullptr)
            {
                cout <<m2->coefficient<<"x^"<<m2->degree;
                if(m2->next != nullptr)
                    cout<<" + ";
                m2=m2->next;
            }
            break;
        }
        
        else if(m2==nullptr)
        {
            while(m1 != nullptr)
            {
                cout <<m1->coefficient<<"x^"<<m1->degree;
                if(m1->next != nullptr)
                    cout<<" + ";
                m1=m1->next;
            }
            break;
        }
        
        else if(m1->degree > m2->degree)
        {
            cout <<m1->coefficient<<"x^"<<m1->degree;
            m1=m1->next;
        }
        
        else if(m1->degree < m2->degree)
        {
            cout <<m2->coefficient<<"x^"<<m2->degree;
            m2=m2->next;
        }
        
        else
        {
            cout << m1->coefficient + m2->coefficient << "x^"<<m1->degree;
                m1=m1->next;
                m2=m2->next;
        }
        cout <<" + ";
    }
}

//the derivative function of polynoial
void Polynomial:: derivative(Polynomial d)
{

    Node *m1=new Node (list_head->coefficient ,list_head->degree  ,list_head->next);
    
    for(int i=0 ; i<size() ; i++)
    {
        if(m1->degree==0)
            break;
        
        d.insert(m1->degree * m1->coefficient, (m1->degree)-1);
        m1=m1->next;
        
    }
    cout << "derivative = ";
    d.print();
}

//remove a valu using degrees
void Polynomial::Delete(int deg)
{
    Node *m=new Node (list_head->coefficient ,list_head->degree  ,list_head->next);
    Node *pm=new Node(list_head->coefficient ,list_head->degree  ,list_head->next);
    int t=0;
    while(1)
    {
        if(deg == m->degree)
        {
            break;
        }
        else
        {
            pm = m;
            m=m->next;
            t++;
        }
    }
        
    if(t == 0)
        list_head=list_head->next;

    else if(t==size()-1)
        pm->next=nullptr;
    
    else if(t==1)
    {
        pm->next=m->next;
        list_head->next=m->next;
    }
    else
        pm->next=m->next;
}

//function to find the total value of a polynomial
int Polynomial::result(int x)
{
    Node *m=new Node (list_head->coefficient ,list_head->degree  ,list_head->next);
    int r=1;
    int c;
    int save=0;
    for(int i=0 ; i<size() ; i++)
    {
        for(int j=0 ; j<m->degree ; j++)
            r*=x;
        c=m->coefficient*r;
        save+=c;
        r=1;
        m=m->next;
    }
    return save;
}

void Polynomial::print()
{
    Node *z = list_head;
    for(int i=0 ; i<size() ; i++)
    {
        cout << z->coefficient << "x^" << z->degree;
        if(i == size()-1)
            break;
        cout<< " + ";
        z=z->next;
    }
    cout<<endl;
}

int main()
{
    
    Polynomial p1;
    Polynomial d;
    p1.insert(3,0);
    p1.insert(4,5);
    p1.insert(6,3);
    p1.insert(2,1);
    p1.insert(6,9);
    cout << "p1: ";
    p1.print();
    cout << endl;
    
    Polynomial p2;
    p2.insert(9,5);
    p2.insert(5,2);
    p2.insert(2,7);
    p2.insert(2,3);
    p2.insert(5,3);
    cout <<"p2: ";
    p2.print();
    cout << endl;
    
    cout<<"sum = ";
    p1.sum(p2);
    cout << endl<<endl;
    
    d.insert(0 , 0);
    cout << "p1: ";
    p1.derivative(d);
    cout << endl;
    
    cout << "p2: ";
    p2.derivative(d);
    cout << endl;
    
    cout<< "If want to DELETE eleman enter 1 else enter 0 :";
    int e;
    cin>> e;
    if(e==1)
    {
        cout<< "Enter Degree For DELETE eleman from p2: ";
        int x;
        cin >> x;
        cout << "p2: ";
        p2.Delete(x);
        p2.print();
        cout << endl;
        cout << "Enter x for p1: ";
        int y;
        cin >> y;
        cout << p1.result(y)<<endl<<endl;
        
        cout << "Enter x for p2: ";
        int z;
        cin >> z;
        cout << p2.result(z)<<endl;
    }
    
    else
    {
        cout << "Enter x for p1: ";
        int y;
        cin >> y;
        cout << p1.result(y)<<endl<<endl;
        
        cout << "Enter x for p2: ";
        int z;
        cin >> z;
        cout << p2.result(z)<<endl;
    }
}
