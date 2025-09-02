#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int a[2000];
    int dp[2000];
    int i;
    
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    
    dp[1]=a[1];
    
    for(i=2;i<=n;i++){
        int c_max=0;
        int j;
        for(j=i-1;j>=1;j--){
            if(a[i]>a[j]){
                if(c_max < dp[j]){
                    c_max = dp[j];
                }
            }
        }
        dp[i]=c_max+a[i];
    }
    int max=0;
    for(i=1;i<=n;i++){
        if(max<dp[i]){
            max=dp[i];
        }
    }
    cout<<max<<'\n';
}