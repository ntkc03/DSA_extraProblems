#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> str;
    for(auto i: s) {
        str.push(i);
    }
    for(auto i: s) {
        if (i != str.top()) {
            cout << "Not symmetrical." << endl;
            break;
        }
        else {
            str.pop();
        }
    }
    if(str.empty()) cout << "Symmetrical." << endl;
    return 0;
}
