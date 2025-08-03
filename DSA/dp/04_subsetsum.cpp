// Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

bool dfs(vector<int>&arr, int sum, int n, vector<vector<int>>&dp) {
  // if we exhausted the array without finding anything, return false
  if (n==0) return false;

  // if sum gets 0, it means we substracted some elements which adds to target sum
  // in such case, we return true
  if (sum==0) return true;

  // early return already solved sub-problem
  if (dp[n][sum] != -1) return dp[n][sum];

  // can only include an element if its <= target sum
  if (arr[n-1] <= sum) {
    return 
      dp[n][sum] = 
        // if we consider this number, we need to reduce the sum with current number
        dfs(arr, sum-arr[n-1], n-1, dp) || 
        // if we ignore this number, we do nothing but trim search space
        dfs(arr, sum, n-1, dp);
  }

  // if current number is invalid, skip it.
  return dp[n][sum] = dfs(arr, sum, n-1, dp);
}

bool isSubsetSum(vector<int>& arr, int sum) {
  int n = arr.size();
  vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
  return dfs(arr, sum, n, dp);
}
