#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int getValue(char c)
{
	if (c == 'I')
		return 1;
	else if (c == 'V')
		return 5;
	else if (c == 'X')
		return 10;
	else if (c == 'L')
		return 50;
	else if (c == 'C')
		return 100;
	else if (c == 'D')
		return 500;
	else if (c == 'M')
		return 1000;
	else
		return -1;
}

int computeVal(string s)
{
	int sum = 0;
	if (s.size() == 1)
		return getValue(s[0]);
	int i;
	for (i = 1; i <= s.size(); i++)
	{
		if (getValue(s[i-1]) >= getValue(s[i]))
			sum += getValue(s[i-1]);
		else
		{
			sum += getValue(s[i]) - getValue(s[i-1]);
			i++;
		}
	}
	return sum;
}

void solving(int v)
{
	string s;
	while (v >= 1000)
	{
		cout << "M";
		v -= 1000;
	}
	while (v >= 100)
	{
		if (v >= 900)
		{
			cout << "CM";
			v -= 900;
		}
		else if (v >= 500)
		{
			cout << "D";
			v -= 500;
		}
		else if (v>=400)
		{
			cout << "CD";
			v -= 400;
		}
		else
		{
			cout << "C";
			v -= 100;
		}
	}
	while (v >= 10)
	{
		if (v >= 90)
		{
			cout << "XC";
			v -= 90;
		}
		else if (v >= 50)
		{
			cout << "L";
			v -= 50;
		}
		else if (v >= 40)
		{
			cout << "XL";
			v -= 40;
		}
		else
		{
			cout << "X";
			v -= 10;
		}
	}
	while (v != 0)
	{
		if (v == 9)
		{
			cout << "IX";
			v = 0;
		}
		else if (v >= 5)
		{
			cout << "V";
			v -= 5;
		}
		else if (v == 4)
		{
			cout << "IV";
			v = 0;
		}
		else
		{
			cout << "I";
			v -= 1;
		}
	}
	cout << endl;
}

int main()
{
	string a, b;
	while (cin >> a && a != "#")
	{
		cin >> b;
		int val_a, val_b;
		val_a = computeVal(a);
		val_b = computeVal(b);

		//cout << "val_a = " << val_a << endl;
		//cout << "val_b = " << val_b << endl;
		val_a = abs(val_a - val_b);
		if (val_a == 0)
			cout << "ZERO" << endl;
		else
			solving(val_a);
	}
}