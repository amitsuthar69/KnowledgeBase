int dfs(vector<int>& arr, int k, int n, vector<vector<int>>&dp) {
	if (k==0) return 1;
  if (n==0) return arr[0] == k;
	if (dp[n][k] != -1) return dp[n][k];

	int notTake = dfs(arr, k, n-1, dp);
	int take = 0;
	if (arr[n] <= k) take = dfs(arr, k-arr[n], n-1, dp);

	return dp[n][k] = take + notTake;
}

int findWays(vector<int>& arr, int k){
	int n = arr.size();
	vector<vector<int>>dp(n, vector<int>(k+1, -1));
  return dfs(arr, k, n-1, dp);
}
