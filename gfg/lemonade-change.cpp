bool lemonadeChange(int N, vector<int> &bills) {
    // code here
    int cnt5 = 0, cnt10 = 0,cnt20 = 0;
    for(int i = 0;i<N;i++){
        if(bills[i] == 5){
            cnt5+=1;
        }
        
        if(bills[i] == 10){
            cnt10+=1;
            if(cnt5>0){
                cnt5-=1;
            }else{
                return false;
            }
            
        }
        
        if(bills[i] == 20){
            cnt20+=1;
            if(cnt10 > 0 && cnt5 > 0){
                cnt10-=1;
                cnt5-=1;
            }else if(cnt5 > 3){
                cnt5-=3;
            }else{
                return false;
            }
            
        }
    }
    return true;
}