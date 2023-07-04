#include <iostream>
using namespace std;

// HERE  DIAGONAL ELEMENTS ARE STORED IN 1-D ARRAY
/*Array ->  5 8 9 12
  index ->  0 1 2 3
*/

class Diagonal{
    private:
        int size;
        int *A;
    public:
        Diagonal(){                 // default constructor
            size=2;
            A=new int[2];
        }
        Diagonal(int size){         // paramatrized constructor
            this->size=size;
            A=new int[size];
        }

        void Set(int r,int c,int num);      // fun to set data
        int Get(int r,int c);               // fun to get data
        void Display();                     // fun to show data

        ~Diagonal(){                    // distructor
            delete []A;
        }
};

void Diagonal::Set(int r,int c,int num){
    if(r==c)
        A[r-1]=num;
}


int Diagonal::Get(int r,int c){
    if(r==c)
        return A[r-1];
    else
        return 0;
}


void Diagonal::Display(){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i==j)
                cout<<A[i]<<" ";             // i=1 & j=1 then A[i-1]  
            else                                // & i<=size & j<=size
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main(){

    Diagonal obj1(4);

    obj1.Set(1,1,5);
    obj1.Set(2,2,8);
    obj1.Set(3,3,9);
    obj1.Set(4,4,12);

    obj1.Display();
    return 0;
}