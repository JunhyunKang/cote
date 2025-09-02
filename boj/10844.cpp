#include <iostream>
#include <algorithm>

using namespace std;

long long ans[200][10];

int main(void){    
    int n;
    cin>>n;
    int i;
    ans[1][0]=0;
    ans[1][1]=1;
    ans[1][2]=1;
    ans[1][3]=1;
    ans[1][4]=1;
    ans[1][5]=1;
    ans[1][6]=1;
    ans[1][7]=1;
    ans[1][8]=1;
    ans[1][9]=1;

    for(i=2;i<=n;i++){
        int j;
        for(j=0;j<10;j++){
            if(j==0){
                ans[i][j]=ans[i-1][j+1]%1000000000;
            }
            else if(j==9){
                ans[i][j]=ans[i-1][j-1]%1000000000;
            }
            else{
                ans[i][j]= (ans[i-1][j-1]+ans[i-1][j+1])%1000000000;
            }
        }

    }
    long long sum=0;
    for(i=0;i<10;i++){
        sum = (sum +ans[n][i])%1000000000;
    }
    cout<<sum%1000000000<<'\n';
    
}