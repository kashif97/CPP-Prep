//Stack - Nearest greater element on right side of array
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> vec;
    stack<int> st;
    for(int i=0;i<n; i++){
        if(st.size()==0){
            vec.push_back(-1);
        }
        else if(st.size()>0 && arr[i] > st.top()){
            vec.push_back(st.top());
        }
        else if(st.size()>0 && arr[i] <= st.top()){
            while(st.size()>0 && arr[i] <= st.top()){
                st.pop();
            }
            if(st.size()==0){
                vec.push_back(-1);
            }
            else{
                vec.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }
    for(auto it: vec){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}