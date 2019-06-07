/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-07 11:16:44
 * Filename      : day16_2.cpp
 * Description   : 扑克牌大小
 * *******************************************************/
#include<iostream>
#include<string>
using namespace std;

// 根据空格来区分牌的类型
int delspace(string s)
{
	int res = 1;
	int n = s.find(' ');
	while (n != -1)
	{
		s = s.substr(n + 1);
		n = s.find(' ');
		res++;
	}
	return res;
}

int main()
{
	string str;
	string poker = "345678910JQKA2";
	while (getline(cin, str))
	{
		int n = str.find('-');
		string s1 = str.substr(0, n);
		string s2 = str.substr(n + 1);
		
		// 有一方为火箭就直接输出
		if (s1 == "joker JOKER" || s2 == "joker JOKER")
		{
			cout <<  "joker JOKER" << endl;
            continue;
		}
	
		int n1 = delspace(s1);
		int n2 = delspace(s2);

		// 如果一方有炸弹，并且另一方无炸弹，则输出有炸弹的一方
		if (n1 == 4 && n2 != 4)
		{
			cout << s1 << endl;
		}
		else if (n1 != 4 && n2 == 4)
		{
			cout << s2 << endl;
		}
		else if (n1 != n2)
		{
			cout << "ERROR" << endl;
		}
		else if (n1 == 1)
		{
			if (poker.find(s1)<poker.find(s2))
			{
				cout << s2 << endl;
			}
			else
			{
				cout << s1 << endl;
			}
		}
		else
		{
			int p1 = poker.find(s1.substr(0, s1.find(' ')));
			int p2 = poker.find(s2.substr(0, s2.find(' ')));
			if (p1<p2)
			{
				cout << s2 << endl;
			}
			else
			{
				cout << s1 << endl;
			}
		}
	}
	system("pause");
	return 0;
} 
