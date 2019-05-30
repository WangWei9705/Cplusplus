/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-05-30 22:28:30
 * Filename      : day10_2.cpp
 * Description   : 密码等级判断
 * *******************************************************/
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int score = 0;

    if(str.size() <=4) {
        score += 5;
    } else if(str.size() <= 7) {
        score += 10;
    } else {
        score += 25;
    }

    // 统计字母个数，数字个数，符号个数
    int a_flag = 0, A_flag = 0,num_count = 0, ch_count = 0;
    for(size_t i = 0; i < str.size(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            a_flag = 1;
        } else if(str[i] >= 'A' && str[i] <= 'Z') {
            A_flag = 1;
        } else if(str[i] >= '0' && str[i] <= '9') {
            num_count++;
        } else {
            ch_count++;
        }
    }

    // 字母得分
    if((a_flag == 1 && A_flag == 0) && (a_flag == 0 && A_flag == 1)) {
        score += 10;
    } else if(a_flag == 1 && A_flag == 1) {
        score += 20;
    }

    // 数字得分
    if(num_count == 1) {
        score += 10;
    } else if(num_count > 1) {
        score += 20;
    }

    // 符号得分
    if(ch_count == 1) {
        score += 10;
    } else if(ch_count > 1) {
        score += 25;
    }


    // 奖励得分
    if(a_flag ==1 && A_flag == 1 && num_count >= 1&& ch_count >= 1) {
        score += 5;
    } else if((a_flag == 1 ||A_flag == 1) && num_count >=1 && ch_count >= 1) {
        score += 3;
    } else if((a_flag == 1 || A_flag == 1) && num_count >= 1) {
        score += 2;
    }


    // 最终评定
    if(score >= 90) {
        cout << "A" << endl;
    } else if(score >= 80) {
        cout << "B" << endl;
    } else if(score >= 70) {
        cout << "C" << endl;
    } else if(score >= 60) {
        cout << "D" << endl;
    } else if(score >= 50) {
        cout << "E" << endl;
    } else if(score >= 25) {
        cout << "F" << endl;
    }else {
        cout << "G" << endl;
    }

    return 0;
}

