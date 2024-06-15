#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printSubseq(int index, vector<int> &ans, int s, int sum, int arr[], int n){
    if(index == n){
        if(s == sum){
            for(auto it: ans){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    else{
        ans.push_back(arr[index]);
        s += arr[index];
        printSubseq(index+1, ans, s, sum, arr, n);
        s -= arr[index];
        ans.pop_back();
        printSubseq(index+1, ans, s, sum, arr, n);
        return;
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
    for(auto itr: ans){
        cout<<itr<<" ";
    }
    cout<<endl;
    return 0;

}