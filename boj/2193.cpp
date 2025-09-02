#include <iostream>
#include <algorithm>

using namespace std;
long long dp[100][2];
int main(void){
    int n;
    cin>>n;
    dp[1][0]=0;
    dp[1][1]=1;
    dp[2][0]=1;
    dp[2][1]=0;
    dp[3][0]=1;
    dp[3][1]=1;
    
    int i;
    for(i=4;i<=n;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    cout<<dp[n][0]+dp[n][1]<<'\n';
    return 0;
}