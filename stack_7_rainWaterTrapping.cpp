//Stack - Rain water Trapping
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> maxLeft(n), maxRight(n);

    // Fill maxLeft
    maxLeft[0] = arr[0];
    for (int j = 1; j < n; j++) {
        maxLeft[j] = max(maxLeft[j - 1], arr[j]);
    }

    // Fill maxRight
    maxRight[n - 1] = arr[n - 1];
    for (int k = n - 2; k >= 0; k--) {
        maxRight[k] = max(maxRight[k + 1], arr[k]);
    }

    // Calculate the trapped water
    int finalAns = 0;
    vector<int> results(n), resultArray(n);
    for (int l = 0; l < n; l++) {
        resultArray[l] = min(maxRight[l], maxLeft[l]) - arr[l];
        finalAns += resultArray[l];
    }

    cout << endl;
    cout << "The final output of the array is: " << finalAns << endl;
    return 0;
}
