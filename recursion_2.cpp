// cpp program to eliminate the middle element from the stack

#include <iostream>
#include <stack>
#define n 5
using namespace std;

void del(stack<int> &st, int temp){
    if(st.empty() || temp==1){
        st.pop();
        return;
    }
    else{
        int temp2 = st.top();
        st.pop();
        del(st, temp-1);
        st.push(temp2);
    }
}

int main()
{
    int count = 0;
    stack<int> st;
    int var;
    for(int i=0; i<n; i++){
        cin>>var;
        st.push(var);
        count++;
    }
    int middle = (count/2)+1;
    del(st, middle);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}
