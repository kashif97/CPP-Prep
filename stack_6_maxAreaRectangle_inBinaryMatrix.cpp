//Stack - Maximum area histogram
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int MAH(vector<int> &vec){
    vector<int> nsr, nsl, width, results;
    stack<pair<int, int>> st;
    int n = vec.size();
    //nearest smaller to left index vector calculation
    for(int j=0; j<n; j++){
        if(st.size()==0){
            nsl.push_back(-1);
        }
        else if(st.size()>0 && vec[j] > st.top().first){
            nsl.push_back(st.top().second);
        }
        else if(st.size()>0 && vec[j] <= st.top().first){
            while(st.size() > 0 && vec[j] <= st.top().first){
                st.pop();
            }
            if(st.size()==0){
                nsl.push_back(-1);
            }
            else{
                nsl.push_back(st.top().second);
            }
        }
        st.push({vec[j], j});
    }
    while(!st.empty()){
        st.pop();
    }

    //nearest smaller to right index vector calculation
    for(int j=n-1; j>=0; j--){
        if(st.size()==0){
            nsr.push_back(n);
        }
        else if(st.size()>0 && vec[j] > st.top().first){
            nsr.push_back(st.top().second);
        }
        else if(st.size()>0 && vec[j] <= st.top().first){
            while(st.size() > 0 && vec[j] <= st.top().first){
                st.pop();
            }
            if(st.size()==0){
                nsr.push_back(n);
            }
            else{
                nsr.push_back(st.top().second);
            }
        }
        st.push({vec[j], j});
    }
    reverse(nsr.begin(), nsr.end());
    // for(auto it: nsr){
    //     cout<<it<<" ";
    // }
    int wide;
    for(int l=0; l<n; l++){
        wide = nsr[l]-nsl[l]-1;
        width.push_back(wide);
    }
    int area;
    for(int k=0; k<n; k++){
        area = vec[k]*width[k];
        results.push_back(area);
    }
    auto maxElement = max_element(results.begin(), results.end());
    return *maxElement;
}

int main(){
    int row, col;
    cout<<"Enter the number of rows: ";
    cin>>row;
    cout<<endl;
    cout<<"Enter the number of coloumns: ";
    cin>>col;
    vector<vector<int>> arr(row, vector<int> (col));
    cout<<"Enter the elements: ";
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }

    vector<int> temp;
    for(int j=0; j<col; j++){
        temp.push_back(arr[0][j]);
    }
    int max_area = MAH(temp);
    //MAH - Maximum Area Histogram
    for(int r=1; r<row; r++){
        for(int c=0; c<col; c++){
            if(arr[r][c]!=0){
                temp[c] = temp[c]+arr[r][c];
            }
            else{
                temp[c]=0;
            }
        }
        max_area = max(max_area, MAH(temp));
    }
    cout<<"The maximum area in the histogram is the: "<<max_area;
    cout<<endl;
    return 0;
}