//  2-D ARRAY USING POINTER 
//  ROWS ARE CRETED IN STACK BUT COLUMNS ARE CREATED IN HEAP

#include <iostream>
using namespace std;

/*
int main()
{
    int r=0,c=0;
    cout<<"Enter the no of rows and columns to create: ";
    cin>>r>>c;
    int *ptr[r];
    cout<<"\nEnter elements in 2-D array\n";
    for(int i=0;i<r;i++)
    {
        ptr[i]=new int[c];
        cout<<"Enter elemnts of "<<i<<"th row\n";
        for(int j=0;j<c;j++)
         cin>>ptr[i][j];
    }

    cout<<"Elments of array \n";
    for(int i=0;i<r;i++)
    {
        cout<<"Elements of "<<i<<"th row is\n";
        for(int j=0;j<c;j++)
         cout<<ptr[i][j]<<" ";
        
        cout<<endl;
    }
     
     for(int k=0;k<r;k++)
      delete [] ptr[k];

     // delete ptr;
     
      cout<<ptr[0][1]<<endl;
    
    return 0;

}  */



/*

//  2-D ARRAY USING DOUBLE POINTER
//   BOTH ROWS AND COLUMNS ARE CREATE IN HEAP
//  ONLY DOUBLE POINTER IS CREATED IN STACK

int main()
{
    int r,c;
    cout<<"Enter the number of rows and no of columns: ";
    cin>>r>>c;

    int **ptr;
     ptr=new int*[r];
    for(int i=0;i<r;i++)
    {
      ptr[i]=new int[c];
     // cout<<"Enter elemnts in "<<i<<"th row \n";  
      for(int j=0;j<c;j++)
       ptr[i][j]=i+j;
    }

    cout<<"\n\n\n\t  Elements of array are\n";
    for(int i=0;i<r;i++)
    {
        cout<<"Elements of "<<i<<"th row is\n";
        for(int j=0;j<c;j++)
         cout<<ptr[i][j]<<" ";
        
        cout<<endl;
    }
    for(int k=0;k<r;k++)
    delete [] ptr[k];

    delete [] ptr;
    ptr=NULL;
    cout<<ptr[1][0]<<endl;
    return 0;
} */


// 3-D ARRAY USING THREE POINTERS IN HEAP (pointer to pointer to pointer)

int main()
{

    int r1,r2,r3;
    cout<<"Enter r1 r2 and r3 :";
    cin>>r1>>r2>>r3;

    int ***ptr=new int**[r1];

  //  cout<<"Enter elements of 3-D array\n";

    for(int i=0;i<r1;i++)
    {
        ptr[i]=new int*[r2];
      //  cout<<"Enter elements in "<<i<<"th index\n";
        for(int j=0;j<r2;j++)
        {
            ptr[i][j]=new int [r3];
          //  cout<<"Enter elements in "<<j<<"th index\n";
            for(int k=0;k<r3;k++)
             ptr[i][j][k]=i+j+k;
        }
    }


cout<<"\n\n";
    for(int i=0;i<r1;i++)
    {
        //ptr[i]=new int*[r2];
        cout<<"Elements of row of "<<i<<" \n";
        for(int j=0;j<r2;j++)
        {
           // ptr[i][j]=new int [r3];
           cout<<"Elements of row of "<<j<<"th index\n";
            for(int k=0;k<r3;k++)
             cout<<ptr[i][j][k]<<" ";
            cout<<endl;
        }

        cout<<endl;
    }


    cout<<"\n\n";
    for(int i=0;i<r1;i++)
    {
        //ptr[i]=new int*[r2];
        cout<<"Address of row of "<<i<<" \n";
        for(int j=0;j<r2;j++)
        {
           // ptr[i][j]=new int [r3];
           cout<<"Address of column of "<<j<<"th index\n";
            for(int k=0;k<r3;k++)
              cout<<&(ptr[i][j][k])<<"\t\t";
            cout<<endl;
        }

        cout<<endl;
    }

   for(int i=0;i<r1;i++)
   {
       for(int j=0;j<r2;j++)
       {
          
             delete []ptr[i][j];
       }
       delete [] ptr[i];
   }

   delete []ptr;
  
   cout<<ptr[1][1][1];
   return 0;
    
}  