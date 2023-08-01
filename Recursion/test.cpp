#include <iostream>
#include <math.h>
using namespace std;

float fun(int num1, int num2, int num3, int num4)
{
	return sqrt((num3 - num1) * (num3 - num1) + (num4 - num2) * (num4 - num2));
}

int main()
{
	// your code goes here
	int n;
	cin >> n;

	while (n--)
	{
		int t;
		cin >> t;

		int a, b, c, x, y, z;
		cin >> a >> b >> c >> x >> y >> z;
		float s1 = fun(a, b, c, x);
		float s2 = fun(c, x, y, z);
		cout << s1 << " " << s2 << endl;
		if (s1 <= t)
		{
			if (s2 <= t)
				cout << "yes \n";
			else
				cout << "no \n";
		}
		else
			cout << "no \n";
	}
	return 0;
}