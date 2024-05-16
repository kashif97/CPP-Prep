//Josephus problem - Recursion
#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;
void solve(int index, int k, vector<int> &vec, int &ans){
    if(vec.size()==1){
        ans = vec[0];
        return;
    }
    else{
        index = (index + k)%vec.size();
        vec.erase(vec.begin()+index);
        solve(index, k, vec, ans);
        return;
    }
}

int main() {
    int total, index=0, ans=-1;
    cin>>total;
    int k;
    cin>>k;
    vector<int> vec;
    for(int i=0;i<total;i++){
        vec.push_back(i+1);
    }
    solve(index, k-1, vec, ans);
    cout<<"The position which will remain alive: "<<ans<<endl;
    return 0;
}