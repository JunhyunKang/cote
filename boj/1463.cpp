#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int d[10000000];
int main(void){
    int n;
    cin>>n;
    int check1=0, check2=0, check3;
    int i=0;
    d[0]=0;
    d[1]=0;
    d[2]=1;
    d[3]=1;
    for(i=4;i<n+10;i++){
        check1=1000000000;
        check2=1000000000;
        check3=1000000000;
        if(i%2==0){
            check1=d[i/2]+1;
        }
        if(i%3==0){
            check2=d[i/3]+1;
        }
        check3=d[i-1]+1;
        d[i]=min({check1, check2, check3});
    }
    cout<<d[n]<<'\n';
    return 0;
}