/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-07-07 21:17:18
 * Filename      : day31_2.cpp
 * Description   : 美国节日
 * *******************************************************/
#include <iostream>
using namespace std;
 
int DayOfWeek(int year, int month, int num, int week, bool flag)
{
    int day = 1;
    int step = 1;
    int n = 0;
    int w = 0;
    if(month == 1 || month == 2)
    {
        month += 12;
        --year;
    }
    
    if(!flag)
    {
        day = 31;
        step = -1;
    }
    
    int centyear = year / 100;
    year %= 100;
    for(int i = 1; i <= 31; day += step)
    {
        w = (year + year / 4 + centyear / 4 - 2 * centyear + (26 * (month + 1) / 10) + day - 1);
        w = (w % 7 + 7)% 7;
        if(w == week)
            ++n;
        if(n == num)
            break;
    }
    return day;
}
 
int main()
{
    int year = 0;
    while(cin >> year)
    {
        cout<< year <<"-01-01"<<endl;
        printf("%d-01-%02d\n", year, DayOfWeek(year, 1, 3, 1, 1));
        printf("%d-02-%02d\n", year, DayOfWeek(year, 2, 3, 1, 1));
        printf("%d-05-%02d\n", year, DayOfWeek(year, 5, 1, 1, 0));
        cout<< year <<"-07-04"<<endl;
        printf("%d-09-%02d\n", year, DayOfWeek(year, 9, 1, 1, 1));
        printf("%d-11-%02d\n", year, DayOfWeek(year, 11, 4, 4, 1));
        cout<< year <<"-12-25"<<endl;
        cout<< endl;
    }
    return 0;
}
 

