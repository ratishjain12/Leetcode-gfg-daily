//##doubt in this problem
int leastInterval(int N, int K, vector<char> &tasks) {
    // code here
    int freq[26] = {0};
    int maxfreq = INT_MIN;
    for(int i = 0;i<tasks.size();i++){
        freq[tasks[i]-'A']++;
        maxfreq = max(maxfreq,freq[tasks[i] - 'A']);
    }
    
    int ans = (K+1)*(maxfreq-1);
    for(int i = 0;i<26;i++){
        if(freq[i] == maxfreq){
            ans++;
        }
    }
    return max(N,ans);
}