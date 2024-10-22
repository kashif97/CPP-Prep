//Printing the subarray with maximum sum
//Kadane's Algorithm
#include <iostream>
#include <bits/stdc++.h>


using namespace std;
void solve(vector<int> &vec, int n){
    int sum = 0, maxi = INT_MIN, start=-1, ansStart = -1, ansEnd = -1;
    for(int i=0; i<n; i++){
        if(sum == 0){
            start = i;
        }
        sum += vec[i];
        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum<0) sum=0;
    }
    for(int k=ansStart; k<=ansEnd; k++){
        cout<<vec[k]<<" ";
    }
    cout<<endl;

}

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    solve(vec, n);
    return 0;
}