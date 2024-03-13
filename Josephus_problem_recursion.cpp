
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void solve(vector<int> &vec, int k, int index){
    if(vec.size() == 1){
        cout<<vec[0]<<endl;
        return;
    }
    else{
        int erased_value = (index +k) % vec.size();
        vec.erase(vec.begin()+erased_value);
        solve(vec, k, erased_value);
        return;
    }
}

int main() {
    int n, k;
    cout<<"Enter the value of n: ";
    cin>>n;
    vector<int> vec(n);
    cout<<"Enter the value of k: ";
    cin>>k;
    for(int i=0; i<n; i++){
        vec[i] = i+1;
    }
    k--;
    int index = 0;
    solve(vec, k, index);
    return 0;
}
