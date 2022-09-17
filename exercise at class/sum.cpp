#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int compare(pair<int, int> l, pair<int, int> r) {
    if(l.second == r.second){
        return l.first < r.first;
    }
    return l.second < r.second;
}
int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    vector<pair<int, int>> digitSum;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        int tmp = num[i];
        while(tmp > 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        digitSum.push_back(make_pair(num[i], sum));
    }
    sort(digitSum.begin(), digitSum.end(), compare);
    for(auto i: digitSum) {
        cout << i.first << endl;
    }
    return true;
}
