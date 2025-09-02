#include <iostream>
#include <algorithm>

using namespace std;
long long dp[2000][10];
int main(void){
    int n;
    cin>>n;
    dp[1][0]=1;
    dp[1][1]=1;
    dp[1][2]=1;
    dp[1][3]=1;
    dp[1][4]=1;
    dp[1][5]=1;
    dp[1][6]=1;
    dp[1][7]=1;
    dp[1][8]=1;
    dp[1][9]=1;

    int i;
    for(i=2;i<=n;i++){
        int j;
        for(j=0;j<10;j++){
            int k;
            int sum=0;
            for(k=j;k>=0;k--){
                sum = (sum+dp[i-1][k])%10007; 
            }
            dp[i][j]=sum%10007;

        }
    }
    long long s=0;
    for(i=0;i<10;i++){
        s = (s+ dp[n][i])%10007;
    }
    cout<< s%10007<<'\n';
    return 0;
}