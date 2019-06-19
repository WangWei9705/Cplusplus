/**********************************************************
 * Author        : WangWei
 * Email         : 872408568@qq.com
 * Last modified : 2019-06-19 11:35:49
 * Filename      : test.c
 * Description   : 使用if嵌套模拟银行登录界面
 * *******************************************************/
#include <stdio.h>
#include <stdlib.h>

void menu() {
    printf("****************\n");
    printf("****1、查询余额**\n");
    printf("****2、取款******\n");
    printf("****3、存款******\n");
    printf("****0、退出登录***\n");
}

int main() {

    int pswd = 123456;
    int input;
    int i;
    for(i = 0; i < 3; i++) {
flag2:
        printf("请输入你的6位密码：");
        scanf("%d", &input);
        if(input == pswd) {
            printf("登陆成功！\n");
            menu();
            int choice;
flag1:
            printf("请输入你的选择:");
            scanf("%d", &choice);

            if(choice == 1) {

                printf("您的余额为：0\n");

            } else if(choice == 2) {

                printf("余额不足，无法取款！\n");

            } else if(choice == 3) {

                printf("赶紧去搬砖吧！\n");
            } else if(choice == 0) {
                printf("登出成功！\n");

            }else {
                printf("输入错误，请重新输入!");
                goto flag1;
            }
            break;

        } else {
            printf("密码错误，请重新输入！\n");
            ++i;
            if(i == 3) {
                printf("今日次数已用完，请明日再来！\n");
                break;
            }
            goto flag2;
        }
    }
    return 0;
}
