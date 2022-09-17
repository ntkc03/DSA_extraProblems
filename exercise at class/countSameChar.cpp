#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> str;
    for(int i = 0; i < s.size(); i++) {
        if(str.empty() || str.top() == s[i]) {
            str.push(s[i]);
        }
        else{
            int count = 0;
            cout << str.top();
            while(!str.empty()) {
                count++;
                str.pop();
            }
            cout << count;
            str.push(s[i]);
        }
        if(i == s.size() - 1) {
            int count = 0;
            cout << str.top();
            while(!str.empty()) {
                count++;
                str.pop();
            }
            cout << count;
        }
    }
    return 0;
}
