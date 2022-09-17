#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string l, string r) {
    if(l.size() == r.size()){
        for(int i = 0; i < l.size(); i++) {
            return l[i] < r[i];
        }
    }
    return l.size() < r.size();
}
int main() {
    int n;
    cin >> n;
    vector<string> str(n);
    for(int i = 0; i < n; i++) {
        cin >> str[i];
        string line;
        getline(cin, line);
    }
    sort(str.begin(), str.end(), compare);
    for(auto i: str) {
        cout << i << endl;
    }
    return 0;
}
