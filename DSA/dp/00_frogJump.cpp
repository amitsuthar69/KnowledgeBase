/*
Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair 
and wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. 
The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for 
the frog to reach the top.
*/


// Memoization = Top-Down --> We start with the whole problem, trim it down to the base case and then return from leaf nodes.
int solve_memoization(vector<int>&h, int n, vector<int>&dp) {
  if (n==0) return 0;
  if (dp[n] != -1) return dp[n];
  
  int lc = solve(h, n-1, dp) + abs(h[n] - h[n-1]);
  int rc = INT_MAX;
  if (n-2>=0){
    rc = solve(h, n-2, dp) + abs(h[n] - h[n-2]);
  }
  return dp[n] = min(lc, rc);
}

// Tabulation = Bottom-up --> we build the dp on the fly with smaller sub-problems.
int solve_tabulation(vector<int>& h) {
  int n = h.size();
  vector<int>dp(n, 0);
  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    int lc = dp[i-1] + abs(h[i] - h[i-1]);
    int rc = INT_MAX;
    if (i > 1) rc = dp[i-2] + abs(h[i] - h[i-2]);
    dp[i] = min(lc, rc);
  }
  return dp[n-1];
}

// Space OPtimization = For such kind of problems where state changes between i-1 and i-2, we can just use 2 variables.
int solve_tabulation(vector<int>& h) {
  int prev = 0;
  int prev2 = 0;

  for (int i = 1; i < n; i++) {
    int lc = prev + abs(h[i] - h[i-1]);
    int rc = INT_MAX;
    if (i > 1) rc = prev2 + abs(h[i] - h[i-2]);
    
    int mini = min(lc, rc);
    prev2 = prev;
    prev = mini;
  }

  return prev;
}

int minCost(vector<int>& h) {
  int n = h.size();
  vector<int>dp(n+1, -1);
  return solve_memoization(h, n-1, dp);
}
