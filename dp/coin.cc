int main(){
  vector<int> dp(10000, 0);  // max. value
  int coin[5] = {50,25,10,5,1};
  dp[0] = 1; //not taking any coins also an option
  for(int j=0; j<5; j++){
    for(int i=1; i < dp.size(); i++){
      if(i >= coin[j])
        dp[i] += dp[i - coin[j]]; // using dynamic approach
      
  // multiple cases
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; i++){
    int d;
    cin >> d;
    cout << dp[d] << endl;
  }
}