class Solution {
private:
    void solve(int sum,int s,vector<vector<int>>&ans,vector<int>&path,vector<int>& nums, int target){
        if(sum>target){
            return;
        }
        if(sum==target){
            ans.push_back(path);
            return ;
        }
        for(int i=s;i<nums.size();i++){
            if(i>s && (nums[i]==nums[i-1])){
                continue;
            }
            path.push_back(nums[i]);
            solve(sum+nums[i],i,ans,path,nums,target);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>path;
        sort(nums.begin(),nums.end());
        solve(0,0,ans,path,nums,target);
        return ans;
    }
};
