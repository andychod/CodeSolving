// 沒過，但看似正確
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct group{
	char Word = 'Z';
	int val = 0;
};

bool sortWord(group i, group j){ return (i.Word < j.Word); }
bool sortVal(group i, group j){return (i.val > j.val); }

int main(){
	int lines;
	cin >> lines;
	cin.ignore();
	string s;

	group ans[26];

	while (lines--)
	{
		getline(cin, s);
		for (int i = 0; i < s.size(); i++)
		{
			s[i] = toupper(s[i]);
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				int index = s[i] - 'A';
				ans[index].val++;
				ans[index].Word = s[i];
			}
		}
	}
	sort(ans, ans + 26, sortWord);
	sort(ans, ans + 26, sortVal);
	for (int i = 0; i < 26; i++)
	{
		if (ans[i].val != 0)
			cout << ans[i].Word << " " << ans[i].val << endl;
	}
	return 0;
}
