#include<iostream>
#define n 10
using namespace std;
class Sort
{
public:
    void bubble_sort(int arr[] , int size);
    void selection_sort(int arr[] , int size);
    void insertion_sort(int arr[] , int size);
    void mergsort(int arr[],int left , int right);
    void minheap_sort();
    
};

class Minheap
{
public:
    int tree[100]={0};
    int size_tree();
    void insert(int);
    void Delete();
    void minheap_sort();
    void print();
};

class Search
{
    public:
    int Linersearch(int arr[] , int size , int x);
    string BinarySearch(int arr[] , int left , int right , int x);
};

//BUBBLE SORT
void Sort::bubble_sort(int arr[] , int size)
{
    int temp;
    
    for(int i=n-2 ; i>=0 ; i--)
    {
        for(int j=0 ; j<=i ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

}

//SELECTION SORT
void Sort::selection_sort(int arr[] , int size)
{
    int tmp , min_index;
    
    for(int i=0 ; i<n-1 ; i++)
    {
        min_index=i;
        for(int j=i+1 ; j<n ; j++)
        {
           if(arr[j] < arr[min_index])
               min_index = j;
        }
        
        if(min_index != i)
        {
            tmp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = tmp;
        }
    }
    
    for (int i=0 ; i<n ; i++)
        cout << arr[i]<<" ";
}

//INSERTION SORT
void Sort::insertion_sort(int arr[] , int size)
{
   int i,j,x;

    for(i=1; i<n ; i++)
    {
        x = arr[i];
        for(j=i ; j>0 ; j--)
        {
            if(x>=arr[j-1])
                break;
            arr[j]=arr[j-1];
        }
        arr[j] = x;
    }
        
    for(int i=0 ; i<n; i++)
        cout <<arr[i]<<" ";
}

//MERGE SORT
void merg(int arr[] ,int left , int mid ,int right)
{
    int size = right-left+1;
    int c[size];
    int leftarr[mid-left+1];
    int rightarr[right-mid];

    for(int i=0 ; i<mid-left+1 ; i++)
        leftarr[i]=arr[left+i];
    for(int i=0 ; i<right-mid ; i++)
        rightarr[i]=arr[1+mid+i];

    int indexleft=0;
    int indexright=0;
    int indexmerg=left;
  
    while(indexleft<mid-left+1 && indexright<right-mid)
    {
        if(leftarr[indexleft]<=rightarr[indexright])
        {
            arr[indexmerg]=leftarr[indexleft];
            indexleft++;
        }
        
        else
        {
            arr[indexmerg]=rightarr[indexright];
            indexright++;
        }
        indexmerg++;
    }
    
    while(indexright<right-mid)
    {
        arr[indexmerg]=rightarr[indexright];
        indexright++;
        indexmerg++;
    }
    
    while(indexleft<mid-left+1)
    {
        arr[indexmerg] = leftarr[indexleft];
        indexleft++;
        indexmerg++;
    }
}

void Sort::mergsort(int arr[],int left , int right)
{
    if(left<right)
    {
        int mid =(left+right)/2;
        mergsort(arr ,left,mid );
        mergsort(arr ,mid+1,right);
        merg(arr ,left,mid ,right);
        
    }
}

//MINHEAP TREE SORT
int Minheap::size_tree()
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

void Minheap::insert(int m)
{
    int tmp;
    int parent;
    tree[size_tree()+1]=m;
    
    parent = size_tree()/2;
    int index_m=size_tree();
    while(m<tree[parent])
    {
        tmp=tree[parent];
        tree[parent]=m;
        tree[index_m]=tmp;
        index_m=parent;
        parent= index_m/2;
    }
}

void Minheap::Delete() {
    while (size_tree() > 0) {
        cout<< tree[1] << " ";
        tree[1] = tree[size_tree()];
        tree[size_tree()] = 0;
        int z = tree[1];
        int index_z = 1;
        int tmp;

        while (1) {
            if (z > tree[2 * index_z] && z > tree[(2 * index_z) + 1] &&
                2 * index_z <= size_tree() && (2 * index_z) + 1 <= size_tree()) {
                if (tree[2 * index_z] < tree[(2 * index_z) + 1]) {
                    tmp = tree[2 * index_z];
                    tree[2 * index_z] = z;
                    tree[index_z] = tmp;
                    index_z = 2 * index_z;
                } else {
                    tmp = tree[(2 * index_z) + 1];
                    tree[(2 * index_z) + 1] = z;
                    tree[index_z] = tmp;
                    index_z = (2 * index_z) + 1;
                }
            } else if (z > tree[2 * index_z] && z < tree[(2 * index_z) + 1] &&
                       2 * index_z <= size_tree()) {
                tmp = tree[2 * index_z];
                tree[2 * index_z] = z;
                tree[index_z] = tmp;
                index_z = 2 * index_z;
            } else if (z < tree[2 * index_z] && z > tree[(2 * index_z) + 1] &&
                       (2 * index_z) + 1 <= size_tree()) {
                tmp = tree[(2 * index_z) + 1];
                tree[(2 * index_z) + 1] = z;
                tree[index_z] = tmp;
                index_z = (2 * index_z) + 1;
            } else {
                break;
            }
        }
    }
}


void Minheap:: minheap_sort()
{
    while(size_tree() > 0)
        Delete();
}

void Minheap::print()
{
    for(int i=0 ; i<size_tree()+10 ; i++)
    {
        cout<<tree[i]<<"  ";
    }
}

//----------------------------------------------------------------------------------------------------//

int Search::Linersearch(int arr[], int size , int x)
{
    for (int i = 0; i <size ; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

string Search::BinarySearch(int arr[] , int left , int right , int x)
{
    int mid = (left+right)/2;
    
    
    if(arr[mid] == x)
        return "Find";
    
    if(left == right && left==mid )
        return "Not Find";
    
    if(arr[mid] < x)
    {
        left = mid +1;
        return BinarySearch(arr , left , right ,x);
    }
    
    else
    {
        right = mid-1;
        return BinarySearch(arr, left , right, x);
    }
}


int main()
{
    Sort s1;
    int total_arr[n];
    
    cout<<"Enter numbers for sorting: " ;
    for (int i=0 ; i<n ; i++)
        cin >> total_arr[i];
    
    cout<<endl<< "-------------------------"<<endl;

    cout<<"1.Bubble sort"<<endl;
    s1.bubble_sort(total_arr, n);
    
    cout<<endl<< "-------------------------"<<endl;
    
    cout<<"2.Selection sort"<<endl;
    s1.selection_sort(total_arr, n);
    
    
    cout<<endl<< "-------------------------"<<endl;
    
     cout<<"3.Insertion sort"<<endl;
    s1.insertion_sort(total_arr, n);
    
    cout<<endl<< "-------------------------"<<endl;
    
    cout<<"4.Merge sort"<<endl;
    s1.mergsort(total_arr, 0 , n-1);
    for(int i=0 ; i<n; i++)
       cout <<total_arr[i]<<" ";
       
    cout<<endl<< "-------------------------"<<endl;
    
    cout<<"5.Minheap sort"<<endl;
    
    Minheap m1;
    m1.insert(8);
    m1.insert(9);
    m1.insert(12);
    m1.insert(10);
    m1.insert(14);
    m1.insert(26);
    m1.insert(29);
    m1.insert(23);
    m1.insert(25);
    m1.insert(19);
    m1.insert(15);
    cout<<"TREE : ";
    m1.print();
    cout<<endl<<"TREE Sorted: ";
    m1.minheap_sort();

    cout<<endl<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    
    
    Search s2;
    int size =5;
    int arr[size];
    cout<<"Enter eleman of arraye fo search: ";
    for (int i=0 ; i<size ; i++)
        cin>>arr[i];
    
    cout<<"1.BinarySearch "<<endl;
    cout<<"Enter x: ";
    int x ;
    cin >> x;
    cout << s2.BinarySearch(arr, 0 ,size-1, x);
    
    cout<<endl<< "-------------------------"<<endl;
    
    cout<<"2.linerSearch "<<endl;
    cout<<"Enter y: ";
    int y ;
    cin >> y;
    int result = s2.Linersearch(arr, size, y);
    if(result == -1)
        cout << "Element is not present in array";
    else
        cout << "Find and x index is: " << result;
    
    cout<<endl<< "-------------------------"<<endl;
    
    return 0;
}
