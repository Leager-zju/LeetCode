给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回滑动窗口中的最大值。

示例：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

// 思路：单调队列。使用双端队列存放下标，保证队列呈递减。当前滑动窗口最大值即队首下标在nums中对应的元素。

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
