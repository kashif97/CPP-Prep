//program to print balanced paranthesis
#include <iostream>
#include <stack>
#include <string>
#include <set>
using namespace std;
void solve(string output, int open, int close){
    if(open == 0 && close == 0){
        cout<<output<<endl;
        return;
    }
    else{
        if(open > 0){
            string op1 = output;
            op1.push_back('(');
            solve(op1, open-1, close);
        }
        if(close > open){
            string op2 = output;
            op2.push_back(')');
            solve(op2, open, close-1);
        }
    }
    
}

int main() {
    int n;
    cout<<"Enter the number of  paranthesis pairs: ";
    cin>>n;
    string output = " ";
    int open = n;
    int close = n;
    solve(output, open, close);
    return 0;
}
