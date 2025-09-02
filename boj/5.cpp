#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(void){
    int x, y;
    cin>>x>>y;
    if(x<2 || y <2){
        cout<<-1<<'\n';
        return 0;
    }
    int check[x][y];
    int i,j;
    for(i=1;i<=x;i++){
        for(j=1;j<=y;j++){
            check[i][j]=0;
        }
    } //초기화
    check[1][1]=1;
    queue<pair<int, int>> q;
    q.push(pair<int,int>(1,1));
    int count=-1;
    int ccc=0;
    while(!q.empty()){
        //8가지 경우
            //1-> x+1 y+2  
            //2-> x+2 y+1 
            //3-> x+2 y-1
            //4-> x+1 y-2  
            //5-> x-1 y-2 
            //6-> x-2 y-1
            //7-> x-2 y+1  
            //8-> x-1 y+2
        int j =0;
        for(j=0; j<q.size();j++){  //-> bfs 레벨 찾는 방법 자식 수 많금 반복으로 해결해주기
            int xx = q.front().first;
            int yy = q.front().second;
            q.pop();
            if(xx+1<=x && yy+2<=y && check[xx+1][yy+2]==0 ){
                check[xx+1][yy+2]=1;
                q.push(pair<int,int>(xx+1,yy+2));
            }
            if(xx+2<=x && yy+1<=y && check[xx+2][yy+1]==0 ){
                check[xx+2][yy+1]=1;
                q.push(pair<int,int>(xx+2,yy+1));
            }
            if(xx+2<=x && yy-1>=1 && check[xx+2][yy-1]==0 ){
                check[xx+2][yy-1]=1;
                q.push(pair<int,int>(xx+2,yy-1));
            }
            if(xx+1<=x && yy-2>=1 && check[xx+1][yy-2]==0 ){
                check[xx+1][yy-2]=1;
                q.push(pair<int,int>(xx+1,yy-2));
            }
            if(xx-1>=1 && yy-2>=1 && check[xx-1][yy-2]==0 ){
                check[xx-1][yy-2]=1;
                q.push(pair<int,int>(xx-1,yy-2));
            }   
            if(xx-2>=1 && yy-1>=1 && check[xx-2][yy-1]==0 ){
                check[xx-2][yy-1]=1;
                q.push(pair<int,int>(xx-2,yy-1));
            }
            if(xx-2>=1 && yy+1<=y && check[xx-2][yy+1]==0 ){
                check[xx-2][yy+1]=1;
                q.push(pair<int,int>(xx-2,yy+1));
            }
            if(xx-1>=1 && yy+2<=y && check[xx-1][yy+2]==0 ){
                check[xx-1][yy+2]=1;
                q.push(pair<int,int>(xx-1,yy+2));
            }
        }
        count++;
    }
    int bb=0;
    for(i=1;i<=x;i++){
        for(j=1;j<=y;j++){
            if(check[i][j]==0){
                bb++;
            }
        }
    } 
    if(bb==0){
        cout<<"T"<<count<<'\n';
    }
    else{
        cout<<"F"<<count<<'\n';
    }
    return 0;
}