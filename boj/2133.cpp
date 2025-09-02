#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long dp[40];
int main(void){
    int n;
    cin>>n;
    if(n%2 != 0){
        cout<<0<<'\n';
        return 0;
    }
    dp[2]=3;
    dp[4]=11;
    int i;
    
    for(i=6;i<=n;i+=2){
        int sum=0;
        int j= i-2;
        sum = sum + dp[j]*dp[2];
        for(j=i-4;j>0;j=j-2){
            sum = sum + dp[j]*2;
        }
        sum += 2;
        
        dp[i]=sum;
    }

    cout<<dp[n]<<'\n'; 
    return 0;  
}