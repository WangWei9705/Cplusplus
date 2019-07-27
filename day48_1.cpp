// write your code here cpp
#include<string>
#include <iostream>
using namespace std;

string Parse(string str) {
    if(str.empty()) {
        return NULL;
    }
    
    string temp;
    for(size_t i = 0; i < str.size(); i++) {
        if(str[i] == ' ') {
            continue;
        }
        if(str[i] >= '0' && str[i] <= '9') {
            temp += str[i];
        }
    }
    return temp;
}


int main() {
    string str;
    while(getline(cin, str)) {
        cout << Parse(str) << endl;
    }
    return 0;
}
