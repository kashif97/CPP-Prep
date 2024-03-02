#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> &vec, int ele){
    if(vec.size()==0 || vec.back() <= ele){
        vec.push_back(ele);
        return;
    }
    else{
        int temp2 = vec[vec.size() - 1];
        vec.pop_back();
        insert(vec, ele);
        vec.push_back(temp2);
        return;
    }
}

void sort(vector<int> &vec){
    if(vec.size() == 1){
        return;
    }
    else{
        int temp = vec[vec.size()-1];
        vec.pop_back();
        sort(vec);
        insert(vec, temp);
    }
}

int main() {
    vector<int> vec;
    int n;
    cout << "Enter the size of vector";
    cin>>n;
    
    for(int i; i<n; i++){
        int element;
        cin>>element;
        vec.push_back(element);
    }
    sort(vec);
    
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    
    return 0;
}

