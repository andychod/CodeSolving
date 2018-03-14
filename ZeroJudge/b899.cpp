#include<iostream>
#include<algorithm>
using namespace std;

struct Points{
	int x = 0;
	int y = 0;
};

int main()
{
	Points p[3];

	while (1)
	{
		for (int i = 0; i < 3; i++)
			cin >> p[i].x >> p[i].y;

		int r[3];
		for (int i = 0; i < 2; i++)
			r[i] = (p[i].x - p[i + 1].x) * (p[i].x - p[i + 1].x) +
			(p[i].y - p[i + 1].y) * (p[i].y - p[i + 1].y);
		r[2] = (p[2].x - p[0].x) * (p[2].x - p[0].x) +
			(p[2].y - p[0].y) * (p[2].y - p[0].y);

		if (r[0] == r[1])
			cout << p[0].x + p[2].x - p[1].x << " " << p[0].y + p[2].y - p[1].y;
		else if (r[0] == r[2])
			cout << p[1].x + p[2].x - p[0].x << " " << p[1].y + p[2].y - p[0].y;
		else
			cout << p[0].x + p[1].x - p[2].x << " " << p[0].y + p[1].y - p[2].y;
		cout << endl;
	}
}