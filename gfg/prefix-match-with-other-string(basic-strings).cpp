int klengthpref(string arr[], int n, int k, string str){    
    
    int count = 0;
    
    string klengthstr = str;
    
    if(k<=str.length()){
        klengthstr = str.substr(0,k);
    }
    for(int i = 0;i<n;i++){
        string temp = "";
        
        if(k<=arr[i].length()){
            temp = arr[i].substr(0,k);
        }
        
        if(temp == klengthstr){
            count++;
        }
    }
    return count;
}