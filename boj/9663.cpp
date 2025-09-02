#include <iostream>
#include <algorithm>


using namespace std;

int n, cnt =0;
int isused[16][16];
int arr[16][16];



int main(void){
    
    
    cin>>n;
    int cur =0;

    for(int i =0 ; i <n ;i++){
        if(isused[0][i]){
            continue;
        }
        isused[0][i]=1;
        for(int k =0 ; k <n ;k++){
            isused[k][i] = 1;
            isused[0][k] = 1;
            for(int j = 0 ;j<n;j++){
                if(i-k>=0 && j-k>=0){
                    isused[i-k][j-k] = 1;
                }
                if(i+k<n&&j+k<n){
                    isused[i+k][j+k] = 1;
                }
                if(i+k<n&& j-k>=0){
                    isused[i+k][j-k] = 1;
                }
                if(i-k>=0&&j+k<n){
                    isused[i-k][j+k] = 1;     
                }
            }
        }
        for(int x =1; x<n;x++){
            for(int y=1; y<n;y++){

            }
        }

    }

    for(int i =0 ; i <n ;i++){
        if(cur==n){
            cnt++;
        }

            if(isused[i][j]){
                continue;
            }
            else{
                isused[i][j] =1;
                for(int k =0 ; k <n ;k++){
                    isused[k][j] = 1;
                    isused[i][k] = 1;
                    if(i-k>=0 && j-k>=0){
                        isused[i-k][j-k] = 1;
                    }
                    if(i+k<n&&j+k<n){
                        isused[i+k][j+k] = 1;
                    }
                    if(i+k<n&& j-k>=0){
                        isused[i+k][j-k] = 1;
                    }
                    if(i-k>=0&&j+k<n){

                        isused[i-k][j+k] = 1;     
                    }

                }
                cnt++;
                find(cur+1);


        }
    }


    if(!isused[x][y]){
        isused[x][y]=1;
        for(int i =0 ; i <n ;i++){
            isused[i][x] = 1;
            isused[x][i] = 1;
            if(x-i>0&&x+i<n){
                isused[x-i][x-i] = 1;
                isused[x+i][x+i] = 1;
                isused[x+i][x-i] = 1;
                isused[x-i][x+i] = 1;
            }

        }
        find()
    }
    else{

    }


    int ans = find(0);
    cout<<ans;
    return 0;
}