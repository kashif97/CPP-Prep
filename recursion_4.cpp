//to print all unique subsets of a string given
#include <iostream>
#include <stack>
#include <string>
#include <set>
using namespace std;
set<string> subsets(string input, string output){
    if(input.size() == 0){
        set<string> st1;
        st1.insert(output);
        return st1;
    }
    else{
        string op1 = output;
        string op2 = output;
        op2.push_back(input[0]);
        input.erase(input.begin()+0);
        set<string> st1 = subsets(input, op1);
        set<string> st2 = subsets(input, op2);
        st1.insert(st2.begin(), st2.end());
        return st1;
    }
}

int main() {
    string input;
    string output = " ";
    cin>>input;
    set<string> st = subsets(input, output);
    for (const string& elem : st) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}
