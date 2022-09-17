#include <bits/stdc++.h>

using namespace std;

int solve1(int arr[], int start, int end, int &count) {
    if(start == end) return 0;
    if(start == end - 1) {
        if(arr[start] > arr[end]) {
            swap(arr[start], arr[end]);
            return 1;
        }
    }
    int mid = (end - start) / 2;
    count += solve1(arr, start, mid, count);
    count += solve1(arr, mid + 1, end, count);
    for(int j = mid + 1; j <= end; j++) {
        for(int i = start; i <= mid; i++) {
            if(arr[j] < arr[i]) {
                swap(arr[j], arr[i]);
                count += (mid - i);
                break;
            }
        }
    }
    return count;
}
int solve2(int arr[], int start, int end, int &count) {
    if(start == end) return 0;
    if(start == end - 1) {
        if(arr[start] < arr[end]) {
            swap(arr[start], arr[end]);
            return 1;
        }
    }
    int mid = (end - start) / 2;
    count += solve1(arr, start, mid, count);
    count += solve1(arr, mid + 1, end, count);
    for(int j = mid + 1; j <= end; j++) {
        for(int i = start; i <= mid; i++) {
            if(arr[j] > arr[i]) {
                count += (mid - i);
                break;
            }
        }
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    int num[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        cin >> num[i];
    }
    int count = 0;
    count = solve1(arr, 0, n - 1, count);
    int tmp = 0;
    tmp = solve2(num, 0, n - 1, count);
    count = min(count, tmp);
    cout << count << endl;
    return 0;
}
