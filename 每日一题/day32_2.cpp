/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-09 15:13:49
 * Filename      : day32_2.cpp
 * Description   :淘宝网店 
 * *******************************************************/
#include<iostream>
#include<vector>
using namespace std;

vector<int> str = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int main()
{
	int year, mouth, day;
	int year2, mouth2, day2;
	while (cin >> year >> mouth >> day >> year2 >> mouth2 >> day2)
	{
		int sum = 0;
		for (int i = year; i < year2; i++)
		{
			if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
				sum += 580;
			else
				sum += 579;
		}
		//减去起始时间之前的收入
		for (int i = 1; i <= mouth; i++)
		{
			int daytmp = 0;
			if (i == mouth)
				daytmp = day - 1;
			else
			{
				daytmp = str[i];
				if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && i == 2)
					daytmp++;
			}
			if (i == 2 || i == 3 || i == 5 || i == 7 || i == 11)
			{
				sum -= daytmp;
			}
			else
				sum -= (daytmp * 2);
		}
		//加上结束时间之前的收入
		for (int i = 1; i <= mouth2; i++)
		{
			int daytmp = 0;
			if (i == mouth2)
				daytmp = day2;
			else
			{
				daytmp = str[i];
				if (((year2 % 4 == 0 && year2 % 100 != 0) || year2 % 400 == 0) && i == 2)
					daytmp++;
			}
			if (i == 2 || i == 3 || i == 5 || i == 7 || i == 11)
			{
				sum += daytmp;
			}
			else
				sum += (daytmp * 2);
		}
		cout << sum << endl;
	}
	return 0;
}
