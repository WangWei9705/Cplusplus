// write your code here cpp
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void Judge(vector<vector<char>> map) {
    bool flag = false;
    char chess;
    for(int i = 0; i < 20; i++) {
        if(flag) {
            break;
        }
        for(int j = 0; j < 20; j++) {
            if(map[i][j] == '.') {
                continue;
            }
            chess = map[i][j];
            map[i][j] = '.';
            
            // 横向
            int count = 1;
            int x = i + 1;
            while(x < 20 && map[x][j] == chess) {
                map[x][j] = '.';
                count++;
                x++;
            }
            
            if(count >= 5) {
                flag = true;
                break;
            }
            
            // 纵向
            count = 1;
            int y = j+1;
            while(j < 20 && map[i][y] == chess){
                map[i][y] = '.';
                count++;
                y++;
            }
             if(count >= 5) {
                flag = true;
                break;
            }
            
            // 斜边
            count = 1;
            x = i + 1;
            y = j + 1;
            while(x < 20 && y < 20 && map[x][y] == chess) {
                map[x][y] = '.';
                count++;
                x++;
                y++;
            }
            
            if(count >= 5) {
                flag = true;
                break;
            }
            
        }
    }
    
    if(flag) {
        cout << "Yes" <<endl;
    } else {
        cout << "No" << endl;
    }
}


int main() {

     vector<vector<char>> map(20, vector<char>(20));
 
    char c;
    while ((c = getchar()) != EOF)
    {
       ungetc(c,stdin);
        for (int i = 0; i < 20; ++i)
        {
            for (int j = 0; j < 20; ++j)
            {
                c = getchar();
                map[i][j] = c;
            }
            getchar();
        }
        Judge(map);
    }
    return 0;
}
