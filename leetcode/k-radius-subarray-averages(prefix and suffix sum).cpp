vector<int> getAverages(vector<int>& nums, int k) {
    vector<int>ans;
    int n  = nums.size();
    vector<long long int>prefixArr(n);
    vector<long long int>suffixArr(n);
    prefixArr[0] = nums[0];
    for(int i = 1;i<n;i++){
        prefixArr[i] = prefixArr[i-1] + nums[i];
    }
    suffixArr[n-1] = nums[n-1];
    for(int i = n-2;i>=0;i--){
        suffixArr[i] = suffixArr[i+1] + nums[i];
    }

    for(int i = 0;i<n;i++){
        if(i-k < 0 || i+k >= n){
            ans.push_back(-1);
        }else{
            long long int sum =(long long int)((prefixArr[i+k] - prefixArr[i]) + (suffixArr[i-k]-suffixArr[i]) + nums[i]);
            sum = sum/(2*k+1);
            ans.push_back(sum);
        }
    }
    return ans;
}