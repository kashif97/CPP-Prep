//to print all possible cases of lower and upper of given input (ab) o/p:ab, Ab, aB. AB, input only given in lowercase
#include <iostream>
#include <stack>
#include <string>
#include <set>
using namespace std;
void permute(string input, string output, set<string> &st){
    if(input.size() == 0){
        cout<<output<<" ";
        st.insert(output);
        return;
    }
    else{
        string op1 = output;
        string op2 = output;
        op1.push_back(input[0]);
        op2.push_back(toupper(input[0]));
        input.erase(input.begin()+0);
        permute(input, op1, st);
        permute(input, op2, st);
        return;
    }
}

int main() {
    string input;
    string output = " ";
    cin>>input;
    set<string> st;
    permute(input, output, st);
    cout << endl;
    for (const string &subset : st) {
        cout << subset << " ";
    }
    cout << endl;
    return 0;
}
