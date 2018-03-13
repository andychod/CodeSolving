#include<iostream>
using namespace std;

void solving(long long a, long long &temp)
{
	temp++;
	if (a != 1)
	{
		if (a % 2 == 1)
			a = 3 * a + 1;
		else
			a = a / 2;
		solving(a, temp);
	}
}

int main()
{
	long long a, b, maxV, temp;
	
	while (cin >> a >> b)
	{
		maxV = 1;
		for (long long i = a; i <= b; i++)
		{
			temp = 0;
			solving(i, temp);
			maxV = maxV > temp ? maxV : temp;
		}
		cout << a << " " << b << " " << maxV << endl;
	}
}