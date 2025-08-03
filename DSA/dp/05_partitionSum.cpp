bool dfs(vector<int>& nums, int n, int sum, vector<vector<int>>& dp) {
  if (sum == 0) return true;
  if (n == 0) return false;
  
  if (dp[n][sum] != -1) return dp[n][sum];
  if (nums[n - 1] > sum) return dp[n][sum] = dfs(nums, n - 1, sum, dp);
  else return dp[n][sum] = dfs(nums, n - 1, sum - nums[n - 1], dp) || dfs(nums, n - 1, sum, dp);
}

bool canPartition(vector<int>& nums) {
  int n = nums.size(); int sum = 0;
  for (auto num : nums) sum += num;
  if (sum % 2 != 0) return false;

  else {
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    return dfs(nums, n, sum / 2, dp);
  }
}

/*
- We have to check if we can divide the array in 2 halves such that they have equal sum.
- Which means, if the entire arrays sums up to S, then each half must sum S/2.
- If any one of the subset half sums to S/2, then the other too.
- This logic boils down this problem to subset sum problem with sum S/2.
- Also, the sum S has to be an even number inorder to have 2 subsets with S/2 sums.
*/