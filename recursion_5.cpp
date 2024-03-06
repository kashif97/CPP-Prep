#include <iostream>
//program to print permutation with subspaces

#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void solve(string input, string output){
    if(input.empty()){ // Check if input is empty
        cout << output << " ";
        return;
    }
    else{
        string op1 = output;
        string op2 = output;
        op1.push_back('_');
        op1.push_back(input[0]);
        op2.push_back(input[0]);
        input.erase(input.begin()+0);
        solve(input, op1);
        solve(input, op2);
        return;
    }
}

int main() {
    string input;
    cin >> input;
    if(!input.empty()){ // Check if input is not empty before accessing input[0]
        string output = " ";
        output.push_back(input[0]);
        input.erase(input.begin()+0);
        solve(input, output);
    }
    return 0;
}
