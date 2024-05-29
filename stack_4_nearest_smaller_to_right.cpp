#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // For reverse

using namespace std;

class Solution {
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n) {
        stack<long long> st;
        vector<long long> result(n);
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[i] >= st.top()) {
                st.pop();
            }
            if(st.empty()) {
                result[i] = -1;
            } else {
                result[i] = st.top();
            }
            st.push(arr[i]);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<long long> arr = {1, 3, 2, 4};
    vector<long long> result = sol.nextLargerElement(arr, arr.size());

    for(long long x : result) {
        cout << x << " ";
    }

    return 0;
}
