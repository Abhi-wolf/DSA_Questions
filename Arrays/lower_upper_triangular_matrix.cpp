#include <iostream>
using namespace std;

class upper_tri{
    private:
        int size1;
        int *A;
    public:
        upper_tri(){
            size1=2;
            A=new int[size1];
        }
        upper_tri(int n){
            size1=n;
            A=new int[size1];
        }

        void Set(int r,int c,int num);
        int Get(int r,int c);
        void Display();

        ~upper_tri(){
            delete []A;
        }
};

void upper_tri::Set(int r,int c,int num){
    int index=0;
    if(c<=r){
        index=r*(r-1)/2 + (c-1);
        A[index] = num;
    }
}


int upper_tri::Get(int r,int c){
    int index=0;
    if(c<=r){
        index=r*(r-1)/2 + (c-1);
        return A[index];
    }
    else
        return 0;
}


void upper_tri::Display(){
    int index=0;
    for(int i=1;i<=size1;i++){
        for(int j=1;j<=size1;j++){
            if(j<=i){
                index= (i*(i-1)/2) + (j-1);
                cout<<A[index]<<" "; 
            }
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}


int main(){
    upper_tri obj1(4);

    obj1.Set(1,1,1);
    obj1.Set(2,1,2);
    obj1.Set(2,2,3);
    obj1.Set(3,1,4);
    obj1.Set(3,2,5);
    obj1.Set(3,3,6);
    obj1.Set(4,1,7);
    obj1.Set(4,2,8);
    obj1.Set(4,3,9);
    obj1.Set(4,4,10);


    obj1.Display();

    return 0;
}