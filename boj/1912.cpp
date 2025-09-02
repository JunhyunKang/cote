#include <iostream>
#include <algorithm>

using namespace std;

int a[200000];
int dp[200000];
int main(void){
    int n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[1]=a[1];
    for(i=1;i<=n;i++){
        dp[i]=max(dp[i-1]+a[i],a[i]);
    }
    int max=INT16_MIN;
    for(i=1;i<=n;i++){
        if(max<dp[i])
            max=dp[i];
    }
    cout<<max<<'\n';    
}