class Solution {
public:
    void perm(vector<int>& arr,vector<int>&ds,vector<int> &mp, vector<vector<int>>&ans){
        if(ds.size()==arr.size()){
            ans.push_back(ds);
            return ;
        }
        for(int i=0;i<arr.size();i++){
            if(!mp[i]){
                mp[i]=1;
                ds.push_back(arr[i]);
                perm(arr,ds,mp,ans);
                ds.pop_back();
                  mp[i]=0;



            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int> ds;
        vector<int> mp(nums.size(),0);
        perm(nums,ds,mp,ans);
        return ans;
    }
};