//problem-link: https://leetcode.com/problems/tallest-billboard/description/
// rods.length <= 21;
// rods height <= 5001;
// -5001<=diff<=5001;
int solve(int idx,int diff,vector<int>& rods,vector<vector<int>>&dp){
    if(idx == rods.size()){
        if(diff == 0){ // if diff is zero then retun 0
            return 0;
        }
        return INT_MIN; // return minimum number 
    }

    if(dp[idx][diff+5001] != -1){ // +5001 to ensure there is no negative difference
        return dp[idx][diff+5001];
    }

    int ltake = rods[idx] + solve(idx+1,diff+rods[idx],rods,dp); // either take in left support
    int rtake = solve(idx+1,diff-rods[idx],rods,dp); // or take in right support
    int none = solve(idx+1,diff,rods,dp); // else none

    return dp[idx][diff+5001] = max(max(ltake,rtake),none); //max of all choices

}
int tallestBillboard(vector<int>& rods) {
    vector<vector<int>>dp(21,vector<int>(2*5001,-1));
    return solve(0,0,rods,dp);
}