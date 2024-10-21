class Solution
{
public:
	vector<vector<int>> threeSum(vector<int> &nums){
		int len = nums.size();
		vector<vector<int>> res = vector<vector<int>>(0,vector<int>(0));
		sort(nums.begin(),nums.end());
		for(int i=0;i<len;i++) {
			int cur = 0-nums[i];
			if(i!=0&&nums[i]==nums[i-1]) continue;
			auto list = twoSum(cur,nums,i);
            for(auto m:list)
			    res.push_back(m);
		}
		return res;
	}
	vector<vector<int>> twoSum(int sum,vector<int>& nums,int index) {
		int l = index+1;
		int r = nums.size()-1;
		vector<vector<int>> res = vector<vector<int>>(0,vector<int>(0));
		while(l<r) {
			if(l!=index+1&&nums[l]==nums[l-1]) {
				l++;
				continue;
			}
			if(r!=nums.size()-1&&nums[r]==nums[r+1]) {
				r--;
				continue;
			}
			if(nums[l]+nums[r]<sum) {
				l++;
			}else if(nums[l]+nums[r]>sum) {
				r--;
			}else {
				vector<int> list = vector<int>{nums[index],nums[l],nums[r]};
				res.push_back(list);
				l++;
				r--;
			}
		}
		return res;
	}
};