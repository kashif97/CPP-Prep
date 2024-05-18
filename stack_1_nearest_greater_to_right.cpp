//Stack - Nearest greater element on right side of array
//Brute force
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
// int main() {
//     int n;
//     cout<<"Enter the size of array: ";
//     cin>>n;
//     cout<<"Enter the elements of array: ";
//     int arr[n];
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//         cout<<" ";
//     }
//     int arr1[n];
//     for (int p = 0; p < n; ++p) {
//         arr1[p] = -1;
//     }

//     for(int k=0; k<n; k++){
//         for(int l=k+1; l<n; l++){
//             if(arr[k]<arr[l]){
//                 arr1[k] = arr[l];
//                 break; 
//             }
//         }
//     }
//     for(int j=0; j<n; j++){
//         cout<<arr1[j]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// stack implementation

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
    for(int j=n-1;j>-1;j--){
        if(st.size()==0){
            vec.push_back(-1);
        }
        else if(st.size()>0 && arr[j]<st.top()){
            vec.push_back(st.top());
        }
        else if(st.size()>0 && arr[j]>=st.top()){
            while(st.size()>0 && arr[j]>=st.top()){
                st.pop();
            }
            if(st.size()==0){
                vec.push_back(-1);
            }
            else{
                vec.push_back(st.top());
            }
        }
        st.push(arr[j]);
    }
    reverse(vec.begin(), vec.end());
    for(auto it: vec){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}
