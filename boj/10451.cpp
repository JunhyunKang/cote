#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

const int MAX = 1500;
int arr_i[MAX];
int check[MAX];

void search(int s, int i){
    check[i]=1;
    if(s == arr_i[i]){
        return;
    }
    search(s, arr_i[i]);
}

int main(void){
    int t;
    cin>>t;
    int q=0;
    for(q=0;q<t;q++){
        int n=0;
        int i;
        int count = 0;
        cin>>n;
        for(i=1;i<=n;i++){
            cin>>arr_i[i];
            check[i]=0;        
        }
        for(i=1;i<=n;i++){
            if(check[i]==0){
                search(i, i);
                count++;
            }
        }
        cout<<count<<"\n";
    }

    return 0;
}