class Solution {
private:
    bool exist(int x,vector<int>&path){
        for(int i=0;i<path.size();i++){
            if(path[i]==x){
                return true;
            }
        }
        return false;
    }
    vector<vector<int>> remdup(vector<vector<int>> subsets) {
        for (auto& subset : subsets) {
            sort(subset.begin(), subset.end());
        }

        sort(subsets.begin(), subsets.end());

        auto last = unique(subsets.begin(), subsets.end());
        subsets.erase(last, subsets.end());

        return subsets;
    }
    void solve(int in,vector<vector<int>>&ans,vector<int>&path,vector<int>& nums){
        if(in==nums.size()){
            return ;
        }
        for(int i=in;i<nums.size();i++){
            if(!exist(nums[i],path)){
                path.push_back(nums[i]);
                ans.push_back(path);
                solve(in+1,ans,path,nums);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>path;
        ans.push_back({});
        solve(0,ans,path,nums);
        vector<vector<int>>res=remdup(ans);
        return res;
    }
};
