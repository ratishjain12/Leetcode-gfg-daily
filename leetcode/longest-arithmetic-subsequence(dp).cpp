int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size();
    if(n<=2){ // as minimum length of longest arithmetic subsequence is 2
        return n;
    }
    int longest = 2;
    vector<unordered_map<int,int>>dp(n);
    for(int i=0;i<n;i++){
        for(int j = 0;j<i;j++){
            int diff = nums[i] - nums[j]; // for each element ending at i we check diff with previous elements
            dp[i][diff] = dp[j].count(diff)?  dp[j][diff]+1 : 2; // if diff already exists for previous element then add 1 for i as assign 2
            longest = max(longest,dp[i][diff]); // calculate the longest length
        }
    }
    return longest;
}