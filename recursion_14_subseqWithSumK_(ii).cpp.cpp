//printing only one subsequence 
//recursion pattern
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool printSubseq(int index, vector<int> &ans, int s, int sum, int arr[], int n){
    if(index == n){
        if(s == sum){
            for(auto it: ans){
                cout<<it<<" ";
            }
            cout<<endl;
            return true;
        }
        return false;
    }
    else{
        ans.push_back(arr[index]);
        s += arr[index];
        if(printSubseq(index+1, ans, s, sum, arr, n) == true)
            return true;
        s -= arr[index];
        ans.pop_back();
        if(printSubseq(index+1, ans, s, sum, arr, n) == true)
            return true;
        return false;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    vector<int> ans;
    printSubseq(0, ans, 0, sum, arr, n);
    return 0;

}
