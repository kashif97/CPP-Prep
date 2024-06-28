//pattern to count the number of all subsequences
//recursion
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int printSubseq(int index, int s, int sum, int arr[], int n){
    if(index == n){
        if(s == sum){
            return 1;
        }
        return 0;
    }
    else{
        s += arr[index];
        int l = printSubseq(index+1, s, sum, arr, n);
        s -= arr[index];
        int r = printSubseq(index+1, s, sum, arr, n);
        return l+r;
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
    cout<<"The sum of the all the subsequences which sums to K are: ";
    cout<< printSubseq(0, 0, sum, arr, n);
    cout<<endl;
    return 0;

}