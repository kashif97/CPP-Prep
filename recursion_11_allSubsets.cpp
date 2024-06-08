class Solution {
private:
    void generateSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>> &result){
        if(index == nums.size()){
            result.push_back(current);
            return;
        }
        else{
            vector<int> curr1(current);
            vector<int> curr2(current);
            curr2.push_back(nums[index]);
            generateSubsets(index+1, nums, curr1, result);
            generateSubsets(index+1, nums, curr2, result);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generateSubsets(0, nums, current, result);
        return result;
    }
};