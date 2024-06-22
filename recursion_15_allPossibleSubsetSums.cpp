class Solution {
  private:
    void solve(int index, int sum, int n, vector<int> &arr, vector<int> &result){
        if(index == n){
            result.push_back(sum);
            return;
        }
        else{
            solve(index+1, sum, n, arr, result);
            solve(index+1, sum+arr[index], n, arr, result);
        }
    }
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> result;
        solve(0, 0, n, arr, result);
        return result;
    }
};
