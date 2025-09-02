#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void){
    int n = 5;
    int m = n/2;
    int arr[n][n];
    memset(arr, 0, sizeof(arr));
    arr[m][m]=1;
    int flag = 0;
    int max=1, count=0;
    int curx = m, cury =m;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int dxx[4]={1,0,-1,0};
    int dyy[4]={0,1,0,-1};
    int change=0;
    int d = 0;
    for(int i =0;i<50;i++)
    {
        int nx,ny;
        
        if(change==0){
            count++;
            nx = curx+dx[d];
            ny = cury+dy[d];

            arr[nx][ny]=arr[curx][cury];
            arr[curx][cury]=0;
            curx = nx;
            cury = ny;
            if(count == max){
                count=0;
                
                d=(d+1)%4;
                
                if(flag==0){
                    flag=1;

                }   
                else{
                    max++;
                    flag=0;
                }             
            }

        }

        if(change==1){
            count++;
            nx = curx+dxx[d];
            ny = cury+dyy[d];

            arr[nx][ny]=arr[curx][cury];
            arr[curx][cury]=0;
            curx = nx;
            cury = ny;
            if(count == max){
                count=0;
                
                d=(d+1)%4;
                
                if(flag==0){
                    flag=1;

                }   
                else{
                    max--;
                    flag=0;
                }             
            }
            
        }

        if(nx==0 && ny==0){
            d=0;
            change=1;
            count=1;
            flag=1;
        }
        if(nx==m&&ny==m){
            change=0;
            d=0;
            count=0;
            flag=0;
        }
        for(int j =0;j<5;j++){
            for(int k =0;k<5;k++){
                cout<<arr[j][k];
            }
            cout<<"\n";
        }
        cout<<"\n";

    }

}