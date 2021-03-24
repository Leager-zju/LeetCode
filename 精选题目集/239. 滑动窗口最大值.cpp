class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) return nums;

        int n = nums.size(), i;
        deque<int> Q;
        for(i = 0; i < k; i++){
            while(!Q.empty() && nums[i] > nums[Q.back()]){
                Q.pop_back();
            }
            Q.push_back(i);
        }
        vector<int> ans;
        ans.push_back(nums[Q.front()]);

        for(i = k; i < n; i++){
            while(!Q.empty() && nums[i] > nums[Q.back()]){
                Q.pop_back();
            }
            while(!Q.empty() && Q.front() <= i-k){
                Q.pop_front();
            }
            Q.push_back(i);
            ans.push_back(nums[Q.front()]);
        }
        return ans;
    }
};
