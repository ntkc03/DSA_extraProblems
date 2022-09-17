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
    while (!str.empty())
    {
        cout << str.top();
        str.pop();
    }
    return 0;
}
