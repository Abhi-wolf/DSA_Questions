#include <iostream>
using namespace std;
/*
struct Array
{
    int *A;
    int length;
    int size;
};


//    INITIALIZATION FUNCTION
void Initialization(struct Array *arr)
{
    //struct Array arr;

    cout<<"Enter the size of Array : ";
    cin>>arr->size;

    arr->A = new int [arr->size];

    int n;
    cout<<"Enter the number of numbers : ";
    cin>>n;

    cout<<"Enter elements\n";

    for(int i=0;i<n;i++)
    {
        cin>>arr->A[i];
    }

    arr->length = n;
}





//         INSERT   FUNCTION
void Insert(struct Array *ar,int index,int key)
{
    cout<<"\n\tInsert Function\n";
    if(index>=0 && index<=ar->length)
    {
        for(int i=ar->length;i>index;i--)
            ar->A[i] = ar->A[i-1];

        ar->A[index] = key;
        ar->length++;
    }

}


//        DELETE  FUNCTION
int Delete(struct Array *ar2,int index)
{
     cout<<"\n\tDelete Function\n";
    if(index>=0 && index<=ar2->length)
    {
        int x = ar2->A[index];

        for(int i=index;i<ar2->length-1;i++)
        {
           ar2->A[i]=ar2->A[i+1];
        }

        ar2->length -= 1;
        return x;
    }

    return -1;
}


//       SEARCH  FUNCTION
int Search(struct Array ar3,int key,int first,int last)
{
     cout<<"\n\tSearch Function\n";

    int la = last -1;
    while(first <= la)
    {
        int mid = (first+la)/2;

        if(ar3.A[mid] == key)
         return mid;

        else if(ar3.A[mid] > key)
          la=mid-1;
        
        else if(ar3.A[mid] < key)
          first=mid+1;
    }

    return -1;
}



//    SORTING FUNCTION
void Sorting (struct Array *ar4)
{
     
   int first = 0;
   int last = ar4->length;

   for(int i=0;i<last;i++)
   {
       for(int j=0;j<last-1;j++)
       {
           if(ar4->A[j] > ar4->A[j+1])
            {
                int temp = ar4->A[j];
                ar4->A[j] = ar4->A[j+1];
                ar4->A[j+1] = temp;
            }
       }
   }
}



//       DISPLAY FUNCTION
void Display(struct Array arr)
{
  for(int i=0;i<arr.length;i++)
   cout<<arr.A[i]<<"  ";

  cout<<endl;
}


//     SET FUNCTION
void Set(struct Array *ar5,int key,int index)
{
    if(index>=0 && index<=ar5->length)
    {
        ar5->A[index] = key;
    }
}


//      GET FUNCTION
void Get(struct Array ar6,int index)
{
    if(index>=0 && index<=ar6.length)
    {
        cout<<"Element at index "<<index<<" is "<<ar6.A[index]<<endl;
    }
}


//   MAXIMUM FUNCTION
int Maximum(struct Array ar7)
{
    int max = ar7.A[0];

    for(int i=0;i<ar7.length;i++)
    {
        if(ar7.A[i] > max)
         max = ar7.A[i];
    }

    return max;
}


//        MINIMUM FUNCTION
int Minimum(struct Array ar7)
{
    int min = ar7.A[0];

    for(int i=0;i<ar7.length;i++)
    {
        if(ar7.A[i] < min)
         min = ar7.A[i];
    }

    return min;
}


//    SUM FUNCTION
int Sum(struct Array ar8)
{
    int sum=0;

    for(int i=0;i<ar8.length;i++)
    {
        sum += ar8.A[i];
    }

    return sum;
}



//    AVERAGE FUNCTION
float Avg(struct Array ar8)
{
    float avg=0;

    avg = Sum(ar8) / ar8.length;

    return avg;
}





//       REVERSE AN ARRAY
void Reverse(struct Array *arr)
{
    int i,j,temp;

    for(int i=arr->length,j=0;i>j;i--,j++)
    {
        temp=arr->A[i];
        arr->A[i]=arr->A[j];
        arr->A[j]=temp;
    }
}




//         INSERT ELEMENT IN SORTED ARRAY
int InsertSort(struct Array *arr,int num)
{
    int i=arr->length-1;
    if(arr->length < arr->size)
    {
    while(i>=0 && arr->A[i]>num)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }

    arr->A[i]=num;
    arr->length++;
    return 1;
    }
    else
     return -1;

}



//   IS ARRAY SORTED
int isSorted(struct Array arr)
{
    int i=0;
    for(i=0;i<arr.length;i++)
    {
        if(arr.A[i] > arr.A[i+1])
         return 0;
    }

    return 1;
}




//   MERGE TWO ARRAYS     (combine two arrays,irrespective of common element)
struct Array* Merge(struct Array *a1,struct Array *a2)
{
    int i=0,j=0,k=0;
    struct Array *a3 = new Array [a1->length+a2->length];

    while(i<a1->length && j<a2->length)
    {
        if(a1->A[i] < a2->A[j])
        {
         a3->A[k] = a1->A[i];
         k++;
         i++;
        }
        else 
        {
            a3->A[k] = a2->A[j];
            k++;
            j++;
        }
    }
    for(;i<a1->length;i++)
    {
        a3->A[k] = a1->A[i];
        i++; k++;
    }

    for(;j<a1->length;j++)
    {
        a3->A[k] = a1->A[j];
        j++; k++;
    }

    a3->length = a1->length + a2->length;
    a3->size = a1->size + a2->size;

    return a3;
}




//  UNION OF TWO ARRAYS  (all elements , but element should not be repeated)
struct Array* Union(struct Array *a1,struct Array *a2)
{
    int i=0,j=0,k=0;
    struct Array *a3 = new Array [a1->length+a2->length];

    while(i<a1->length && j<a2->length)
    {
        if(a1->A[i] < a2->A[j])
        {
         a3->A[k] = a1->A[i];
         k++;
         i++;
        }
        else if(a1->A[i] > a2->A[j])
        {
            a3->A[k] = a2->A[j];
            k++;
            j++;
        }
        else
        {
            a3->A[k] = a1->A[i];
            i++; k++; j++;
        }

    }
    for(;i<a1->length;i++)
    {
        a3->A[k] = a1->A[i];
        i++; k++;
    }

    for(;j<a1->length;j++)
    {
        a3->A[k] = a1->A[j];
        j++; k++;
    }

    a3->length = k;
    a3->size = a1->size + a2->size;

    return a3;
}






//   INTERSECTION OF TWO ARRAY  (common elements)
struct Array* Intersection(struct Array *a1,struct Array *a2)
{
    int i=0,j=0,k=0;
    struct Array *a3 = new Array [a1->length+a2->length];

    while(i<a1->length && j<a2->length)
    {
        if(a1->A[i] < a2->A[j])
            i++;
        
        else if(a1->A[i] > a2->A[j])
            j++;
        
        else if(a1->A[i] == a2->A[j])
        {
            a3->A[k] = a1->A[i];
            k++; i++; j++;
        }
    }
    
    a3->length = k;
    a3->size = a1->size;

    return a3;
}




//   DIFFERENCE OF ARRAYS  (not common elements)
struct Array* Difference(struct Array *a1,struct Array *a2)
{
    int i=0,j=0,k=0;
    struct Array *a3 = new Array [a1->length+a2->length];

    while(i<a1->length && j<a2->length)
    {
        if(a1->A[i] < a2->A[j])
        {
         a3->A[k] = a1->A[i];
         k++;
         i++;
        }
        else if(a1->A[i] > a2->A[j])
        {
            a3->A[k] = a2->A[j];
            k++;
            j++;
        }
        else
        {
            j++;i++;
        }
    }
    for(;i<a1->length;i++)
    {
        a3->A[k] = a1->A[i];
        i++; k++;
    }

    
    a3->length = k;
    a3->size = a1->size + a2->size;

    return a3;
}




//         MAIN  FUNCTION
int main()
{
    struct Array arr;
    int ch;
    int x,index;

    cout<<"Enter the size of Array : ";
    cin>>arr.size;

    arr.A = new int[arr.size];
    arr.length = 0;

    do
    {
        cout<<"\n\n\t MENU\n";
        cout<<" 1. Insert \n";
        cout<<" 2. Delete \n";
        cout<<" 3. Search \n";
        cout<<" 4. Sum \n";
        cout<<" 5. Display \n";
        cout<<" 6. Merge \n";
        cout<<" 7. Union \n";
        cout<<" 8. Intersection \n";
        cout<<" 9. Difference \n";
        cout<<"10. Average \n";
        cout<<"11. Exit \n";

        cout<<"Enter your choice : ";
        cin>>ch;

        switch (ch)
        {
            case 1:
                cout<<"Enter an element and index : ";
                cin>>x>>index;
                Insert(&arr,index,x);
                break;
            
            case 2:
                cout<<"Enter index : ";
                cin>>index;
                x=Delete(&arr,index);
                cout<<"Deleted Element is "<<x<<endl;
                break;

            case 3:
                cout<<"Enter element to search : ";
                cin>>x;
                if(isSorted(arr) == 1)
                {
                index = Search(arr,x,0,arr.length);
                cout<<"Element index is "<<index<<endl;
                }
                else
                {
                    Sorting(&arr);
                    index = Search(arr,x,0,arr.length);
                    cout<<"Element index is "<<index<<endl;
                }
                break;

            case 4:
                x = Sum(arr);
                cout<<"Sum is "<<x<<endl;
                break;

            case 5:
                Display(arr);
                break;

            case 6:
                struct Array arr1;
                struct Array arr2;
                struct Array *arr3;

                Initialization(&arr1);
                Initialization(&arr2);

                arr3 = Merge(&arr1,&arr2);
                Display(*arr3);
                break;

            case 7:
                struct Array arr4;
                struct Array arr5;
                struct Array *arr6;

                Initialization(&arr4);
                Initialization(&arr5);

                arr6 = Union(&arr4,&arr5);
                Display(*arr6);
                break;

            case 8:
                struct Array arr7;
                struct Array arr8;
                struct Array *arr9;

                Initialization(&arr7);
                Initialization(&arr8);

                arr9 = Intersection(&arr7,&arr8);
                Display(*arr9);
                break;

            case 9:
                struct Array arr10;
                struct Array arr11;
                struct Array *arr12;

                Initialization(&arr10);
                Initialization(&arr11);

                arr12 = Difference(&arr10,&arr11);
                Display(*arr12);
                break;
 
            case 10:
                x = Avg(arr);
                cout<<"Average is "<<x<<endl;
                break; 

            case 11:
                exit(0);   
        }
    } while (ch<12); 
  return 0;
}
*/



//                  USING CLASS

#include <iostream>
using namespace std;

class Array
{
private:
  int *A;
  int size;
  int length;

public:
  Array()
  {
    size=10;  
    A = new int[10];
    length=0;
  }

  Array(int sz)
  {
    size=sz;
    A=new int[size];
    length=0;
  }

  ~Array()
  {
    delete []A;
  }

  void Insert(int index,int key);
  int Delete(int index);
  void Display();
  void Append(int x);
  int LinearSearch(int x);
  int BinarySearch(int x);
  int Get(int index);
  void Set(int index,int x);
  int Max();
  int Min();
  int Sum();
  float Avg();
  void Reverse();
  void Reverse2();
  void InsertSort(int x);
  int isSorted();
  void Rearrange();
};


void Array::Insert(int index,int key)
{
  if(index>=0 && index<=length)
  {
    for(int i=length;i>index;i--)
    {
      A[i]=A[i-1];
    }
    A[index]=key;
    length++;
  }
}


int Array::Delete(int index)
{
    int x;
  if(index>=0 && index<length)
  {
     x=A[index];
    for(int i=index;i<length-1;i++)
    {
      A[i]=A[i+1];
    }
    length--;
    return x;
  }

  return -1;
}


void Array::Display()
{
  if(length>=0 && length<=size)
  {
    for(int i=0;i<length;i++)
    {
      cout<<A[i]<<" ";
    }

    cout<<endl;
  }
}

void Array::Append(int x)
{
    if(length<size);
    {
        A[length]=x;
        length++;
    }
}



int Array::LinearSearch(int x)
{
    int i=0;
    for(i=0;i<length;i++)
    {
        if(A[i]==x)
         return i;
    }
    return -1;
}



int Array::BinarySearch(int x)
{
    int l,mid,h;
    l=0;
    h=length-1;

    while(l<=h)
    {
        mid = (l+h)/2;
        if(A[mid]==x)
         return mid;
        else if(x<A[mid])
         h=mid-1;
        else
         l=mid+1;
    }

    return -1;
}


void Swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}


int Array::Get(int index)
{
    if(index>=0 && index<length)
      return A[index];
    return -1;
}



void Array::Set(int index,int x)
{
    if(index>=0 && index<length)
    {
        A[index] = x;
    }
}


int Array::Max()
{
    int ma=A[0];
    for(int i=1;i<length;i++)
    {
        if(A[i]>ma)
            ma=A[i];
    }
    return ma;
}


int Array::Min()
{
    int mi=A[0];
    for(int i=1;i<length;i++)
    {
        if(A[i]<mi)
            mi=A[i];
    }

    return mi;
}


int Array::Sum()
{
    int su=0;
    for(int i=0;i<length;i++)
    {
        su+=A[i];
    }
    return su;
}


void Array::Reverse()
{
    int i,j;
    i=0;
    int *B;
    B=new int[length];
    for(i=0,j=length-1;j>=0;i++,j--)
    {
        B[i]=A[j];
    }
    for(i=0;i<length;i++)
        A[i]=B[i];
}



void Array::Reverse2()
{
    int i,j;
    for(i=0,j=length-1;i<j;i++,j--)
    {
        Swap(&A[i],&A[j]);
    }
}


float Array::Avg()
{
    return (float)Sum()/length;
}



int Array::isSorted()
{
    for(int i=0;i<length;i++)
    {
        if(A[i]>A[i+1])
            return 0;
    }
    return 1;
}


void Array::InsertSort(int x)
{
    int i=length-1;
    if(length==size)
        return;
    while(i>=0 && A[i]>x)
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=x;
    length++;
}


int main()
{
  Array *arr1;
  int x,index,sz,choice;

  cout<<"Enter the size of Array : ";
  cin>>sz;

  arr1 = new Array(sz);

  do
  {
      cout<<"\n\t MENU\n";
      cout<<"1.Insert\n";
      cout<<"2.Delete\n";
      cout<<"3.Display\n";
      cout<<"4.Append\n";
      cout<<"5.Search\n";
      cout<<"6.Get\n";
      cout<<"7.Set\n";
      cout<<"8.isSorted\n";
      cout<<"9.Sum\n";
      cout<<"10.Average\n";
      cout<<"11.Maximum\n";
      cout<<"12.Minimum\n";
      cout<<"13.Reverse\n";

      cout<<"Enter your choice : ";
      cin>>choice;

      switch (choice)
      {
          case 1:cout<<"Enter index and number : ";
                 cin>>index>>x;
                 arr1->Insert(index,x);
                 break;

          case 2:cout<<"Enter index to Delete : ";
                 cin>>index;
                 x = arr1->Delete(index);
                 cout<<"Number deleted is "<<x<<endl;
                 break;

          case 3:arr1->Display();
                 break;

          case 4:cout<<"Enter number : ";
                 cin>>x;
                 arr1->Append(x);
                 break;

          case 5:cout<<"Enter number to search : ";
                 cin>>x;
                 index = arr1->LinearSearch(x);
                 cout<<"Element is present at "<<index<<" index.\n";
                 break;

          case 6:cout<<"Enter index to get : ";
                 cin>>index;
                 x = arr1->Get(index);
                 cout<<"Element at index "<<index<<" is "<<x<<endl;
                 break;

          case 7:cout<<"Enter index and number to set : ";
                 cin>>index>>x;
                 arr1->Set(index,x);
                 break;

          case 8:x = arr1->isSorted();
                 if(x==1)
                  cout<<"Array is Sorted\n";
                 else if(x==0)
                  cout<<"Array is not Sorted\n";
                 break;

          case 9:x = arr1->Sum();
                 cout<<"Sum of numbers in Array is "<<x<<endl;
                 break;
          case 10:x = arr1->Avg();
                  cout<<"Average of numbers in Array is "<<x<<endl;
                  break;

          case 11:x = arr1->Max();
                  cout<<"Maximum in Array is "<<x<<endl;
                  break;
          
          case 12:x = arr1->Min();
                  cout<<"Minimum in Array is "<<x<<endl;
                  break;

          case 13:arr1->Reverse();
                  break;
      }
  } while (choice<14);
  
  return 0;
}
