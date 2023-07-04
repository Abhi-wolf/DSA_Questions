#include <bits/stdc++.h>

using namespace std;

int main()

{
	int r1,c1,r2,c2,r3,c3;
	cout<<"Enter no of rows and no of columns of first matrix: ";
	cin>>r1>>c1;

	cout<<"Enter no of rows and no of columns of second matrix: ";
	cin>>r2>>c2;

	if(c1!=r2)
		cout<<"Not Possible";
	else
	{
		int mat1[r1][c1];
		int mat2[r2][c2];

		cout<<"Enter elements of first matrix\n";
		for(int i=0;i<r1;i++)
		{
			for(int j=0;j<c1;j++)
			{
				cin>>mat1[i][j];
			}
		}

		cout<<"Enter elements of second matrix\n";
		for(int i=0;i<r2;i++)
		{
			for(int j=0;j<c2;j++)
			{
				cin>>mat2[i][j];
			}
		}


		int mat3[r1][c2];

		for(int i=0;i<r1;i++)
		{
			for(int j=0;j<c2;j++)
			{
				mat3[i][j]=0;
				for(int k=0;k<r2;k++)
				{
					mat3[i][j]+=mat1[i][k]*mat2[k][j];
				}
			}
		}

		cout<<"Elements of third matrix\n";
		for(int i=0;i<r1;i++)
		{
			for(int j=0;j<c2;j++)
			{
				cout<<mat3[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
