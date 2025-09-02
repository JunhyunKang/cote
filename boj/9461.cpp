#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void){
    int t;
    cin>>t;
    long a[200];
    long dp[200];
    int i=0;
    for(i=0;i<t;i++){
        int n;
        cin>>n;
        fill_n(a,200,0);
        fill_n(dp,200, 0);
        dp[1]=1;
        dp[2]=1;
        dp[3]=1;
        dp[4]=2;
        dp[5]=2;
        dp[6]=3;
        dp[7]=4;
        int j;
        for(j=8;j<=n;j++){
            dp[j]=dp[j-5] + dp[j-1];
        }
        cout<<dp[n]<<'\n';
    }
    return 0;
}