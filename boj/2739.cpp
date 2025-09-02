#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int i;
    for(i=0;i<9;i++){
        cout<<n<<" * "<<i+1<<" = "<<n*(i+1)<<'\n';
    }
    return 0;
}