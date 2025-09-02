#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[100000];
int main (void){
    
    int n;
    cin>>n;
    int i;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(i=4;i<=n;i++){
        if(i==(int)sqrt(i)*(int)sqrt(i)){
            dp[i] = 1;
        }
        else{
            int k=2;
            int q;
            int j=1;
            int m=0x0ffffff;
            for(j=2;j<=(int)sqrt(i);j++){
                if(m>dp[j*j]+dp[i-j*j])
                    m=dp[j*j]+dp[i-j*j];
            }
            
            dp[i]=m;
        }
    }
    cout<<dp[n]<<'\n';

}