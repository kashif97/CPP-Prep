//Stack - Rain water Trapping
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
stack<int> s, ss;

void push(int a){
    
    if(s.empty() || a <= ss.top()){
        ss.push(a);
    }
    s.push(a);
    return;
}

int pop(){
    if(s.empty()){
        return -1;
    }
    else{
        int ans = s.top();
        s.pop();
        if(ans == ss.top()){
            ss.pop();
        }
        return ans;
    }
    
}

int getMin(){
    if(ss.empty()){
        return -1;
    }
    else{
        return ss.top();
    }
}

int main() {
    push(18);
    int min1 = getMin();
    cout<<min1<<endl;
    push(19);
    push(20);
    int temp1 = pop();
    cout<<temp1<<endl;
    push(15);
    int min2 = getMin();
    cout<<min2<<endl;
    push(16);
    int min3 = getMin();
    cout<<min3<<endl;
    return 0;
}