#include <iostream>
#include <string>
using namespace std;

int binarySearch(const string arr[], int size, const string& key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int e;
    cin >> e;

    string n1[e];
    for (int i = 0; i < e; i++) {
        cin >> n1[i];
    }

    int q;
    cin >> q;

    string n2[q];
    for (int i = 0; i < q; i++) {
        cin >> n2[i];
    }

    for (int i = 0; i < q; i++) {
        int index = binarySearch(n1, e, n2[i]);

        if (index == -1) {
            cout << "-\n";
        } else {
            cout << "+\n";
        }
    }

    return 0;
}