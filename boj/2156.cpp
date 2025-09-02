#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int i;
    int dp[20000];
    int a[20000];
    dp[0]=0;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[1]=a[1];
    dp[2]=dp[1]+a[2];
    for(i=3;i<=n;i++){
        dp[i]=max(dp[i-2]+a[i], dp[i-3]+a[i-1]+a[i]);
        dp[i]=max({dp[i-1],dp[i]});    //이부분 생각이 어렵네 위에 dp[2] 채우는 거랑
    }

    cout<<dp[n]<<'\n';   
    
    return 0;
}