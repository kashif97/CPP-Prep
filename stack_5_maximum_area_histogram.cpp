//Stack - Maximum area histogram
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
    for(int i=0;i<n; i++){
        cin>>arr[i];
    }
    vector<int> nsr, nsl, width, results;
    stack<pair<int, int>> st;
    //nearest smaller to left index vector calculation
    for(int j=0; j<n; j++){
        if(st.size()==0){
            nsl.push_back(-1);
        }
        else if(st.size()>0 && arr[j] > st.top().first){
            nsl.push_back(st.top().second);
        }
        else if(st.size()>0 && arr[j] <= st.top().first){
            while(st.size() > 0 && arr[j] <= st.top().first){
                st.pop();
            }
            if(st.size()==0){
                nsl.push_back(-1);
            }
            else{
                nsl.push_back(st.top().second);
            }
        }
        st.push({arr[j], j});
    }
    cout<<"Nearest smaller to left vector is: ";
    for(auto it: nsl){
        cout<<it<<" ";
    }
    cout<<endl;
    while(!st.empty()){
        st.pop();
    }

    //nearest smaller to right index vector calculation
    for(int j=n-1; j>=0; j--){
        if(st.size()==0){
            nsr.push_back(n);
        }
        else if(st.size()>0 && arr[j] > st.top().first){
            nsr.push_back(st.top().second);
        }
        else if(st.size()>0 && arr[j] <= st.top().first){
            while(st.size() > 0 && arr[j] <= st.top().first){
                st.pop();
            }
            if(st.size()==0){
                nsr.push_back(n);
            }
            else{
                nsr.push_back(st.top().second);
            }
        }
        st.push({arr[j], j});
    }
    cout<<"Nearest smaller to right vector is: ";
    reverse(nsr.begin(), nsr.end());
    for(auto it: nsr){
        cout<<it<<" ";
    }
    cout<<endl;
    int wide;
    for(int l=0; l<n; l++){
        wide = nsr[l]-nsl[l]-1;
        width.push_back(wide);
    }
    int area;
    for(int k=0; k<n; k++){
        area = arr[k]*width[k];
        results.push_back(area);
    }
    auto maxElement = max_element(results.begin(), results.end());
    cout<<"The maximum area under the histogram is: "<<*maxElement;
    cout<<endl;
}