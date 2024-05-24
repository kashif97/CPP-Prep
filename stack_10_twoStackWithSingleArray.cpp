#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class twoStacks{
    int *arr;
    int size;
    int top1, top2;

    public:
        //constructor
        twoStacks(int n){
            size = n;
            arr = new int[n];
            top1 = n/2+1;
            top2 = n/2;
        }
        void push1(int x){
            if(top1 <= 0){
                cout<<"Stack overflow"<< " By element : " << x << endl;
                return;
            }
            else{
                top1--;
                arr[top1] = x;
            }
        }
        void push2(int x){
            if(top2 >= size-1){
                cout<<"Stack overflow"<< " By element : " << x << endl;
                return;
            }
            else{
                top2++;
                arr[top2] = x;
            }
        }
        int pop1(){
            if(top1 > size/2){
                cout<<"Stack underflow";
                exit(1);
            }
            else{
                int ans;
                ans = arr[top1];
                top1++;
                return ans;
            }
        }
        int pop2(){
            if(top2 == size/2){
                cout<<"Stack underflow";
                exit(1);
            }
            else{
                int ans;
                ans = arr[top2];
                top2--;
                return ans;
            }
        }
};
 
int main(){

    twoStacks ts(5); 
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    cout << "Popped element from stack1 is "<< ": " << ts.pop1() << endl; 
    ts.push2(40); 
    cout << "Popped element from stack2 is "<< ": " << ts.pop2() << endl;
    cout<<endl;
    return 0;
}