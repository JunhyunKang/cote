#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 150000;
int arr_se[MAX][2];
int arr_k[1200];
int main(void){
    int n,m;  
    cin>>n>>m;
    int i;

    for(i=1;i<=n;i++){

        cin>> arr_k[i];
    }
    for(i=1;i<=m;i++){

        cin>> arr_se[i][0]>> arr_se[i][1];
    }
    
    int j=0;
    int check[1200];

    for(i=1;i<=m;i++){
        j=0;
        for(j=1;j<=n;j++){

            check[j]=0;
        }       

        for(j=arr_se[i][0]; j<= arr_se[i][1];j++){
            arr_k[j]++;
        }
        if(i%3==0){
            int d = i;
            for(j=arr_se[d][0]; j<= arr_se[d][1];j++){
                check[j]=1;
            }
            for(j=arr_se[d-1][0]; j<= arr_se[d-1][1];j++){
                check[j]=1;
            }
            for(j=arr_se[d-2][0]; j<= arr_se[d-2][1];j++){
                check[j]=1;
            }
            for(j=1;j<=n;j++){

                if(check[j]==1){
                    arr_k[j]--;
                }
            }     
        }
    }
    for(i=1;i<=n;i++){

        cout << arr_k[i]<<" ";
    }
    cout<<"\n";
    return 0;
}