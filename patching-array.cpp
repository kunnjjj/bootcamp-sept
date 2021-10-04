// https://leetcode.com/problems/patching-array/
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        long long N=nums.size();
        long long int sum=0;
        int i=0;
        // sum>=n
        //     [1.....n]
        // 1....10  12
        //     yes
        long long ans=0;
        while(sum < n)
        {
            if(i<N && sum + 1 >= nums[i])
            {
                sum+=nums[i];
                i++;
            }
            else
            {
                ans++;
                sum+=(sum+1);
            }
        }
        return ans;
    }
};