#include <iostream>
#include <algorithm>

using namespace std;

int a[500];
int dp[500];

int main(void){
    int n;
    cin>>n;
    int i;
    for(i=1; i<=n;i++){
        cin>>a[i];
    }
    dp[0]=0;
    dp[1]=a[1];
    dp[2]=a[2]+a[1];
    for(i=3;i<=n;i++){
        dp[i]= max(dp[i-2]+a[i], dp[i-3]+a[i-1]+a[i]);
    }
    cout<<dp[n]<<'\n';
}