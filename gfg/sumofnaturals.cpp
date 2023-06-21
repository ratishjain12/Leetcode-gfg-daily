int sumOfNaturals(int n) {
    // code here
    long long int mod = pow(10,9) + 7;
    long long int sum = 0;
    for(int i = 1;i<=n;i++){
        sum += i;
    }
    
    return sum%mod;
}