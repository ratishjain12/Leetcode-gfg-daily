vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col){
    //Your code here
    vector<vector<int>>ans;
    
    map<vector<int>,int>mp;
    
    for(int i = 0;i<row;i++){
        vector<int>temp;
        for(int j = 0;j<col;j++){
            temp.push_back(M[i][j]);
        }
        
        mp[temp]++;
        if(mp[temp] == 1){
            ans.push_back(temp);
        }
    }
    
    return ans;
}