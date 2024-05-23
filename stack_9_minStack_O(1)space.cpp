//Stack - minStack with O(1) space
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
stack<int> st;
int minElement;

void push(int a){
    if(st.size() == 0){
        st.push(a);
        minElement = a;
        return;
    }
    else{
        if(minElement < a){
            st.push(a);
        }
        else{
            st.push(2*a-minElement);
            minElement = a;
        }
        return;
    }
}

int pop(){
    if(st.size()==0){
        return -1;
    }
    else{
        int ans;
        if(st.top() > minElement){
            ans = st.top();
            st.pop();
            return ans;
        }
        else{
            ans = 2*minElement-st.top();
            st.pop();
            return ans;
        }
    }
}

int getMin(){
    if(st.size() == 0)
        return -1;
    else
        return minElement;
}

int main() {
    push(5);
    push(3);
    int min1 = getMin();
    cout<<min1<<endl;
    push(7);
    int min2 = getMin();
    cout<<min2<<endl;
    push(3);
    int min3 = getMin();
    cout<<min3<<endl;
    int result = pop();
    cout<<result<<endl;
    push(1);
    int min4 = getMin();
    cout<<min4<<endl;
    cout<<st.top()<<endl;
    return 0;
}