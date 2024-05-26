#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

bool duplicateParantheses(string str){
    stack<char> st;
    for(char c : str){
        if(c == ')'){
            if(st.top() != '('){
                while(st.top() != '('){
                    st.pop();
                }
                st.pop();
            }
            else{
                return true;
            }
        }
        else{
            st.push(c);
        }
    }
    return false;
}

int main(){
    string input;
    cout<<"Enter the string: ";
    cin>>input;
    bool var = duplicateParantheses(input);
    cout<<var<<endl;
    return 0;
}