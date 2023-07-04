#include <iostream>
using namespace std;

int main()
{
  /* 
   // USING SINGLE POINTER 
    int *p[4];           // THIS IS CREATED IN HEAP
    p[0]=new int[3];      // BUT THESE 3 ARRAYS ARE CREATED IN HEAP 
    p[1]=new int[3];
    p[2]=new int[3];
    p[3]=new int[3];

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            p[i][j]=i+j+1;
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<p[i][j]<<" ";
        }
        cout<<"\n";
    } 
    delete []p; */


// USING DOUBLE POINTER 
    int **q;        // CREATED IN STACK
    q=new int*[3];    // BUT THESE 4 ARE CREATED IN HEAP
    q[0]=new int[4];
    q[1]=new int[4];
    q[2]=new int[4];


   for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            q[i][j]=i+j+1;
        }
        
    }


    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<q[i][j]<<" ";
        }

        cout<<endl;
    }
   
    delete []q;
    return 0;
}