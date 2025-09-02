#include <iostream>
#include <algorithm>

using namespace std;

int ans[2000];

int main(void){
    int n;
    cin>>n;
    int i;
    ans[1]=1;
    ans[2]=3;
    ans[3]=5;
    for(i=4;i<=n;i++){
        ans[i]=(ans[i-1] + ans[i-2]*2)%10007;
    }
    cout<<ans[n]<<'\n';
}