// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        26 Nov 2021
//  @Detail  :        Get the Maximum Score (LeetCode)
//  ============================
//  -->

class Solution {
public:
    int mod = 1000000007;
    
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> inter;
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        while(i < n && j < m)
        {
            if(nums1[i] == nums2[j])
            {
                inter.push_back({i, j});
                i++;    j++;
            }
            else if(nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        
        if(inter.empty())
            return max(accumulate(nums1.begin(), nums1.end(), 0), accumulate(nums2.begin(), nums2.end(), 0));
        
        int num1Idx = 0, num2Idx = 0, pre1Idx = 0, pre2Idx = 0;
        
        int result = 0;
        for(int i = 0; i < inter.size(); i++)
        {
            result = (result +  max(accumulate(nums1.begin() + pre1Idx, nums1.begin() + inter[i][0] + 1 , 0ll),
                           accumulate(nums2.begin() + pre2Idx, nums2.begin() + inter[i][1] + 1 , 0ll))) % mod;
            pre1Idx = inter[i][0] + 1;
            pre2Idx = inter[i][1] + 1;
        }
        result = (result + max(accumulate(nums1.begin() + pre1Idx, nums1.end() , 0ll),
                           accumulate(nums2.begin() + pre2Idx, nums2.end() , 0ll))) % mod;
        return result;
    }
};
