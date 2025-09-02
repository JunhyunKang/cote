#include <iostream>
#include <algorithm>

using namespace std;
int main(void){
    int t;
    cin>>t;
    int i;
    int dp[2][220000];
    int ans[t];
    int a[2][220000];
    for(i=0;i<t;i++){
        int n;
        cin>>n;
        int j=0;
        for(j=1;j<=n;j++)
            cin>>a[0][j];
        for(j=1;j<=n;j++)
            cin>>a[1][j];
        dp[0][0]=0;
        dp[1][0]=0;
        dp[0][1]=a[0][1];
        dp[1][1]=a[1][1];
        for(j=2;j<=n;j++){
            dp[0][j] = max(dp[1][j-2], dp[1][j-1])+a[0][j];
            dp[1][j]= max(dp[0][j-2], dp[0][j-1])+a[1][j];
        }
        ans[i]=max(dp[0][n],dp[1][n]);
        
    }
    for(i=0;i<t;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;

}