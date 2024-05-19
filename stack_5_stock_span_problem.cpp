//Stack - Stock span problem using Nearest greater element on left side of array
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the elements of array: ";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
    vector<int> vec;
    //in the stack the nearest greater element and the index to it is stored as a pair

    stack<pair<int, int>> st;
    for(int j=0; j<n; j++){
        if(st.size()==0){
            vec.push_back(-1);
        }
        else if(st.size()>0 && arr[j] < st.top().first){
            vec.push_back(st.top().second);
        }
        else if(st.size() > 0 && arr[j] > st.top().first){
            while(st.size()>0 && arr[j] > st.top().first){
                st.pop();
            }
            if(st.size()==0){
                vec.push_back(-1);
            }
            else{
                vec.push_back(st.top().second);
            }
        }
        st.push({arr[j], j});
    }
    //aditya verma stock span problem  16:00
    for(int k=0; k<n; k++){
        vec[k] = k-vec[k];
    }
    for(auto it:vec){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}