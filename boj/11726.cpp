#include <iostream>
#include <algorithm>

using namespace std;

int ans[2000];
int main(void){
    int n;
    cin>>n;
    
    ans[1]=1;
    ans[2]=2;
    ans[3]=3;
    ans[4]=5;
    int i;
    for(i=5;i<=n;i++){
        ans[i] = (ans[i-2] + ans[i-3]*2 + ans[i-4]) % 10007;
    }

    cout<<ans[n]<<'\n';

}