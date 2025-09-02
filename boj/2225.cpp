#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
long long dp[400][400];
int main(void){
    int n, k;
    cin>>n>>k;
    int i;
    dp[1][0]=1;
    dp[1][1]=1;
    for(i=0;i<400;i++){
        dp[1][i]=1;
    }
    for(i=2;i<=k;i++){
        int j;
        for(j=0;j<=n;j++){
            long long r, sum=0;
            for(r=j;r>=0;r--){
                sum = (dp[i-1][r] + sum)%1000000000;
            }
            
            dp[i][j]=sum%1000000000;

        }

    }
    cout<< dp[k][n]%1000000000;
} 

