//to print all subsets of a string given
#include <iostream>
#include <stack>
#include <string>
using namespace std;

void subsets(string input, string output){
    if(input.size() == 0){
        cout<<output<<endl;
    }
    else{
        string op1 = output;
        string op2 = output;
        op2.push_back(input[0]);
        input.erase(input.begin()+0);
        subsets(input, op1);
        subsets(input, op2);
    }
}

int main() {
    string input;
    string output = " ";
    cin>>input;
    subsets(input, output);
    return 0;
}
