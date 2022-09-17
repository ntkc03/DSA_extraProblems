#include <iostream>
#include <queue>
#include <string>

using namespace std;
int maxSum(const int &sum1, const int &sum2, const int &sum3) {
    return max(sum1, max(sum2, sum3));
}
int solve (queue<int> arr1, queue<int> arr2, queue<int> arr3, int sum1, int sum2, int sum3) {
    int target = 0;
    while(!arr1.empty() && !arr2.empty() && !arr3.empty()) {
        if(maxSum(sum1, sum2, sum3) == sum1) {
            target = sum1 - arr1.front();
        }
        else if(maxSum(sum1, sum2, sum3) == sum2) {
            target = sum2 - arr2.front();
        }
        else {
            target = sum3 - arr3.front();
        }
        while(!arr1.empty() && sum1 > target) {
            sum1 -= arr1.front();
            arr1.pop();
        }
        while(!arr2.empty() && sum2 > target) {
            sum2 -= arr2.front();
            arr2.pop();
        }
        while(!arr3.empty() && sum3 > target) {
            sum3 -= arr3.front();
            arr3.pop();
        }
        if(sum1 == sum2 && sum1 == sum3) break;

    }
    return target;
}
int main() {
    int n1, n2, n3;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    cin >> n1 >> n2 >> n3;
    queue<int> arr1, arr2, arr3;
    while(n1 > 0) {
        int tmp;
        cin >> tmp;
        arr1.push(tmp);
        sum1 += tmp;
        n1--;
    }
    while(n2 > 0) {
        int tmp;
        cin >> tmp;
        arr2.push(tmp);
        sum2 += tmp;
        n2--;
    }
    while(n3 > 0) {
        int tmp;
        cin >> tmp;
        arr3.push(tmp);
        sum3 += tmp;
        n3--;
    }
    cout << solve(arr1, arr2, arr3, sum1, sum2, sum3) << endl;
    return 0;
}
