#include <iostream>
#include <algorithm>

using namespace std;
int main(void){
    int n;
    cin>>n;
    int dp[2000];
    int a[2000];
    int b[2000];
    
    int i;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }

    fill_n(dp, 2000, 1);
    fill_n(b, 2000, 1);
    for(i=2;i<=n;i++){
        int j;
        int max=0;
        for(j=i-1;j>0;j--){
            if(a[i]>a[j]){
                if(max<dp[j])
                {
                    dp[i]=dp[j]+1;
                    max=dp[j];
                }    
            } 
        }

    }
    for(i=n;i>=1;i--){
        int j;
        int max=0;
        for(j=n;j>i;j--){
            if(a[i]>a[j]){
                if(max<b[j])
                {
                    b[i]=b[j]+1;
                    max=b[j];
                }    
            } 
        }
        
    }

    int max=0;
    for(i=1;i<=n;i++){
       if(max<dp[i]+b[i])
            max=dp[i]+b[i];
    }
    cout<<max-1<<'\n';              
}