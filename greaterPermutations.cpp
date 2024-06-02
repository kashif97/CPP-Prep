//Count natural numbers whose all permutation are greater than that number
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isIncreasing(int i){
	string str = to_string(i);
	for(int i=0; i<str.length(); i++){
		for(int j=i+1; j<str.length(); j++){
			if(str[i] > str[j]){
				return false;
			}
		}
	}
	return true;
}

int countPermutations(int n){
	int count = 0;
	for(int i=1; i<=n; i++){
		if(isIncreasing(i)){
			count++;
		}
	}
	return count;
}

int main(){
	int n;
	cout<<"Enter the nalue of n: ";
	cin>>n;
	int result = countPermutations(n);
	cout<<result<<endl;
	return 0;
}