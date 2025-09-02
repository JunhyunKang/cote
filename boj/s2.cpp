#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <limits>
#include <cmath>
#include <utility>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int siya[51][51];
int M, N, sr, sc, er, ec;

vector<pair<int, int>> a;
int amap[51][51];

int amove1[51][51];
int amove2[51][51];
int amove3[51][51];
int amove4[51][51];

int realMove[51][51];

int map[51][51];
int check[51][51];


int left();
int right();
int straight();

pair<int,int> findD(int mx, int my){
    memset(amove1, 0 ,sizeof(amove1));
    memset(amove2, 0 ,sizeof(amove2));
    memset(amove3, 0 ,sizeof(amove3));
    memset(amove4, 0 ,sizeof(amove4));


    int maxDol = -1;
    int direction = 0;

    int nx, ny;
    int dols = 0;
    int left, right, up, down;
    //상
    nx = mx-1;
    ny = my;
    if(nx>=0){
        //상좌
        int tempx = nx;
        left = ny-1;
        while(tempx>=0 && left>=0){
            for(int i = tempx ; i>=0 ; i--){
                if(amove1[i][left]==1){
                    
                    for(int j = i-1 ; j>=0 ; j--){
                        amove1[j][left]=1;
                    }
                    if(i-1>=0 && left-1>=0){
                        

                        amove1[i-1][left-1]=1;
                    }
                                        
                    break;
                }

                if(amap[i][left]>0 && amove1[i][left]==0){
                    dols += amap[i][left];
                    amove1[i][left] = -1;

                    
                    int tempX = i-1, tempLeftY = left-1;

                    for(int j = tempX ; j>=0 ; j--){
                        amove1[j][left]=1;
                    }
                    if(tempX>=0 && tempLeftY>=0){
                        amove1[tempX][tempLeftY]=1;

                    }
                    break;

                }
                
                
                else if(amove1[i][left]==0){
                    amove1[i][left] = -1;
                }             
            }

            left--;
            tempx--;
        }
        
        //상상
        tempx = nx;
        int tempinit = -1;
        while(tempx>=0){
            if(amap[tempx][ny]>0 && tempinit!=1){
                dols += amap[tempx][ny];
                amove1[tempx][ny] = -1;
                tempinit = 1;
                tempx--;
            }
            amove1[tempx][ny] = tempinit;
            tempx--;
        }

        //상우
        tempx = nx;
        right = ny+1;
        while(tempx>=0 && right<N){
            for(int i = tempx ; i>=0 ; i--){
                if(amove1[i][right]==1){
                    for(int j = i-1 ; j>=0 ; j--){
                        amove1[j][right]=1;
                    }
                    if(i-1>=0 && right+1<N){                        
                        amove1[i-1][right+1]=1;
                    }                    

                    break;
                } 
                if(amap[i][right]>0 && amove1[i][right]==0){
                    dols += amap[i][right];
                    amove1[i][right] = -1;

                    
                    int tempX = i-1, tempRightY = right+1;

                    for(int j = tempX ; j>=0 ; j--){
                        amove1[j][right]=1;
                    }
                    if(i-1>=0&&right+1<N){
                        amove1[i-1][right+1]=1;
                    }
                    break;
                    
                }
                
                else if(amove1[i][right]==0){
                    amove1[i][right] = -1;
                }             
            }

            right++;
            tempx--;
        }
        
    }
    
    if(dols>maxDol){
        maxDol = dols;
        direction =1;
    }
    
    dols = 0;
////////////////////////////////////////////////////////////////////////////////////////////////
    //하
    nx = mx+1;
    ny = my;
    if(nx<N){
        //하좌
        int tempx = nx;
        left = ny-1;
        while(tempx<N && left>=0){
            for(int i = tempx ; i<N ; i++){
                if(amove2[i][left]==1){

                    for(int j = i+1 ; j<N ; j++){
                        amove2[j][left]=1;
                    }
                    if(i+1<N && left-1>=0){
                        amove2[i+1][left-1]=1;
                    }
                    break;
                }
                if(amap[i][left]>0 && amove2[i][left]==0){
                    dols += amap[i][left];
                    amove2[i][left] = -1;

                    
                    int tempX = i+1, tempLeftY = left-1;

                    for(int j = tempX ; j<N ; j++){
                        amove2[j][left]=1;
                    }
                    if(i+1<N && left-1>=0){
                        amove2[i+1][left-1]=1;
                    }
                    break;
                   
                }
                
                else if(amove2[i][left]==0){
                    amove2[i][left] = -1;
                }             
            }

            left--;
            tempx++;

        }
        //하하
        tempx = nx;
        int tempinit = -1;
        while(tempx<N){
            if(amap[tempx][ny]>0 && tempinit!=1){
                dols += amap[tempx][ny];
                amove2[tempx][ny] = -1;
                tempinit = 1;
                tempx++;

            }
            amove2[tempx][ny] = tempinit;
            tempx++;
        }

        //하우
        tempx = nx;
        right = ny+1;
        while(tempx<N && right<N){
            for(int i = tempx ; i<N ; i++){
                if(amove2[i][right]==1){

                    for(int j = i+1 ; j<N ; j++){
                        amove2[j][right]=1;
                    }
                    if(i+1<N && right+1<N){
                        amove2[i+1][right+1]=1;
                    }
                    break;
                } 
                if(amap[i][right]>0 && amove2[i][right]==0){
                    dols += amap[i][right];
                    amove2[i][right] = -1;

                    
                    int tempX = i+1, tempRightY = right+1;

                    for(int j = tempX ; j<N ; j++){
                        amove2[j][right]=1;
                    }
                    if(i+1<N && right+1<N){
                        amove2[i+1][right+1]=1;
                    }
                    break;
                    
                }
                
                else if(amove2[i][right]==0){
                    amove2[i][right] = -1;
                }             
            }

            right++;
            tempx++;


        }
        
    }

    if(dols>maxDol){
        maxDol = dols;
        direction =2;
    }

    dols = 0;
////////////////////////////////////////////////////////////////////////////////////////////////
    //좌
    nx = mx;
    ny = my-1;
    if(ny>=0){
        //좌하
        int tempy = ny;
        down = nx+1;
        while(tempy>=0 && down<N){
            for(int i = tempy ; i>=0 ; i--){
                if(amove3[down][i]==1){

                    for(int j = i-1 ; j>=0 ; j--){
                        amove3[down][j]=1;
                    }
                    if(i-1>=0 &&down+1<N){
                        amove3[down+1][i-1]=1;
                    }
                    break;
                } 
                if(amap[down][i]>0 && amove3[down][i]==0){
                    dols += amap[down][i];
                    amove3[down][i] = -1;

                    
                    int tempY = i-1, tempDownX = down+1;

                    for(int j = tempY ; j>=0 ; j--){
                        amove3[down][j]=1;
                    }
                    if(i-1>=0 &&down+1<N){
                        amove3[down+1][i-1]=1;
                    }
                    break;
                    
                }
                
                else if(amove3[down][i]==0){
                    amove3[down][i] = -1;
                }             
            }

            down++;
            tempy--;
        }
        //좌좌
        tempy = ny;
        int tempinit = -1;
        while(tempy>=0){
            if(amap[nx][tempy]>0 && tempinit!=1){
                dols += amap[nx][tempy];
                amove3[nx][tempy] = -1;
                tempinit = 1;
                tempy--;
            }
            amove3[nx][tempy] = tempinit;
            tempy--;
        }

        //좌상
        tempy = ny;
        up = nx-1;
        while(tempy>=0 && up>=0){
            for(int i = tempy ; i>=0 ; i--){
                if(amove3[up][i]==1){
                    for(int j = i-1 ; j>=0;j--){
                        amove3[up][j]=1;
                    }
                    if(i-1>=0 && up-1 >=0){
                        amove3[up-1][i-1]=1;
                    }
                    break;
                }  
                if(amap[up][i]>0 && amove3[up][i]==0){
                    dols += amap[up][i];
                    amove3[up][i] = -1;

                    
                    int tempY = i-1, tempUpX = up-1;

                    for(int j = tempY ; j>=0 ; j--){
                        amove3[up][j]=1;
                    }
                    if(i-1>=0 && up-1 >=0){
                        amove3[up-1][i-1]=1;
                    }
                    break;
                    
                }
                
                else if(amove3[up][i]==0){
                    amove3[up][i] = -1;
                }             
            }

            up--;
            tempy--;
        }
        
    }

    if(dols>maxDol){
        maxDol = dols;
        direction =3;
    }

    dols = 0;
////////////////////////////////////////////////////////////////////////////////////////////////
    //우
    nx = mx;
    ny = my+1;
    if(ny<N){
        //우하
        int tempy = ny;
        down = nx+1;
        
        while(tempy<N && down<N){
            for(int i = tempy ; i<N ; i++){
                if(amove4[down][i]==1){
                    for(int j = i+1 ; j<N ; j++){
                        amove4[down][j]=1;
                    }
                    if(i+1<N && down+1<N){
                        amove4[down+1][i+1]=1;
                    }
                    break;
                }  
                if(amap[down][i]>0 && amove4[down][i]==0){
                    
                    dols += amap[down][i];
                    amove4[down][i] = -1;
                    ////////////////////////
                    int tempY = i+1, tempDownX = down+1;

                    for(int j = tempY ; j<N ; j++){
                        amove4[down][j]=1;
                    }
                    if(i+1<N && down+1<N){
                        amove4[down+1][i+1]=1;
                    }
                    break;
                    

                }
                
                else if(amove4[down][i]==0){
                    amove4[down][i] = -1;
                }             
            }

            down++;
            tempy++;
        }
        //우우
        tempy = ny;
        int tempinit = -1;
        while(tempy<N){
            if(amap[nx][tempy]>0 && tempinit!=1){
                dols += amap[nx][tempy];
                amove4[nx][tempy] = -1;
                tempinit = 1;
                tempy++;
            }
            amove4[nx][tempy] = tempinit;
            tempy++;
        }

        //우상
        tempy = ny;
        up = nx-1;
        while(tempy<N && up>=0){
            for(int i = tempy ; i<N ; i++){
                if(amove4[up][i]==1){
                    for(int j =i+1; j<N ; j++){
                        amove4[up][j]=1;
                    }

                    if(i+1<N && up-1>=0){
                        amove4[up-1][i+1]=1;
                    }
                    break;
                } 
                if(amap[up][i]>0 && amove4[up][i]==0){
                    dols += amap[up][i];
                    amove4[up][i] = -1;

                    
                    int tempY = i+1, tempUpX = up-1;

                    for(int j = tempY ; j<N ; j++){
                        amove4[up][j]=1;
                    }
                    if(i+1<N && up-1>=0){
                        amove4[up-1][i+1]=1;
                    }
                    break;
                    
                     
                }
                
                else if(amove4[up][i]==0){
                    amove4[up][i] = -1;
                }             
            }

            up--;
            tempy++;
        }
    }

    if(dols>maxDol){
        maxDol = dols;
        direction =4;
    }

    dols = 0;
    return {direction, maxDol};
    

}

pair<int, int> makeMove(int arr[][51], int tx, int ty){

    int attack=0, hap=0;
    for(int i  =0 ; i<M ; i++){
        int x = a[i].first, y=a[i].second;
        if(x!=-1 && y!=-1 && arr[x][y]>=0){
            if(tx-x<0 && x-1>=0 && arr[x-1][y]>=0){
                int nx = x -1;
                a[i]={nx,y};
                amap[x][y]--;
                
                if(tx==nx&&ty==y){
                    attack++;
                    a[i] = {-1,-1};
                    amap[tx][ty]=0;
                }
                else{
                    amap[nx][y]++;
                }
                
                hap++;
            }
            else if(tx-x>0&& x+1<N &&arr[x+1][y]>=0){
                int nx = x + 1;
                a[i]={nx,y};
                amap[x][y]--;
                
                if(tx==nx&&ty==y){
                    attack++;
                    a[i] = {-1,-1};
                    amap[tx][ty]=0;
                }
                else{
                    amap[nx][y]++;
                }
                hap++;

            }
            else if(ty-y<0&& y-1>=0 &&arr[x][y-1]>=0){
                int ny = y -1;
                a[i]={x,ny};
                amap[x][y]--;
                
                if(tx==x&&ty==ny){
                    attack++;
                    a[i] = {-1,-1};
                    amap[tx][ty]=0;
                }
                else{
                    amap[x][ny]++;
                }
                hap++;

            }
            else if(ty-y>0&& y+1<N&&arr[x][y+1]>=0){
                int ny = y +1;
                a[i]={x,ny};
                amap[x][y]--;
                if(tx==x&&ty==ny){
                    attack++;
                    a[i] = {-1,-1};
                    amap[tx][ty]=0;
                }
                else{
                    amap[x][ny]++;
                }
                hap++;
            }
        }
    }
    for(int i  =0 ; i<M ; i++){
        int x = a[i].first, y=a[i].second;
        if(x!=-1 && y!=-1 && arr[x][y]>=0){
            if(ty-y<0&& y-1>=0 &&arr[x][y-1]>=0){
                int ny = y -1;
                a[i]={x,ny};
                amap[x][y]--;
                
                if(tx==x&&ty==ny){
                    attack++;
                    a[i] = {-1,-1};
                    amap[tx][ty]=0;
                }
                else{
                    amap[x][ny]++;
                }
                hap++;
            }
            else if(ty-y>0&& y+1<N&&arr[x][y+1]>=0){
                int ny = y +1;
                a[i]={x,ny};
                amap[x][y]--;
                if(tx==x&&ty==ny){
                    attack++;
                    a[i] = {-1,-1};
                    amap[tx][ty]=0;
                }
                else{
                    amap[x][ny]++;
                }
                hap++;
            }
            else if(tx-x<0 && x-1>=0 &&arr[x-1][y]>=0){
                int nx = x -1;
                a[i]={nx,y};
                amap[x][y]--;
                if(tx==nx&&ty==y){
                    attack++;
                    a[i] = {-1,-1};
                    amap[tx][ty]=0;
                }
                else{
                    amap[nx][y]++;
                }
                hap++;
            }
            else if(tx-x>0&& x+1<N &&arr[x+1][y]>=0){
                int nx = x + 1;
                a[i]={nx,y};
                amap[x][y]--;
                if(tx==nx&&ty==y){
                    attack++;
                    a[i] = {-1,-1};
                    amap[tx][ty]=0;
                }
                else{
                    amap[nx][y]++;
                }
                
                hap++;

            }
            
        }
    }
    return {hap,attack};
}


int main() {
    // Please write your code here.
    ios::sync_with_stdio(false); 
    cin.tie(NULL);  
    cout.tie(NULL);

    cin>>N>>M;
    cin>>sr>>sc>>er>>ec;

    
    memset(check, -1, sizeof(check));

    memset(amap, 0, sizeof(amap));

    for(int i  =0 ; i<M ; i++){
        int x, y;
        cin>>x>>y;
        a.push_back({x,y});
        amap[x][y]++;
    }

    // for(int i =0 ; i<N;i++){
    //     for(int j =0 ; j<N;j++){
    //         cout<<amap[i][j]<<"\t";
    //     }
    //     cout<<"\n";
    // }

    for(int i  =0 ; i<N ; i++){
        for(int j =0 ; j<N ; j++){
            int tempm;
            cin>>tempm;
            map[i][j] = tempm;
            if(tempm==1){
                check[i][j] = -2;
            }
        }
    }
        
    queue<pair<int, int>> mqueue;
    check[er][ec]=0;
    mqueue.push({er, ec});
    while(!mqueue.empty()){
        int curx = mqueue.front().first;
        int cury = mqueue.front().second;
   
        mqueue.pop();

        for(int i =0; i<4;i++){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<N && check[nx][ny]==-1 && map[nx][ny]!=1){
                check[nx][ny]= check[curx][cury]+1;
                mqueue.push({nx, ny});
            }
        }
    }
    if(check[sr][sc]==-1){
        cout<<"-1";
        return 0;
    }
    int w = check[sr][sc];
    int tx=sr;
    int ty = sc;
    while(true){
        int moves=0;
        int dol =0;
        int attacks=0;

        int x =tx;
        int y = ty;

        



        for(int i =0;i<4;i++){
            int curx = x+dx[i];
            int cury = y+dy[i];

            if(curx>=0 && curx<N && cury>=0 &&cury<N &&check[curx][cury]==check[x][y]-1){
                tx=curx;
                ty=cury;
                break;
            }
        }
        
        for(int i=0;i<M;i++){
            if(tx==a[i].first && ty == a[i].second){
                a[i]={-1,-1};

            }
        }
        amap[tx][ty] = 0;

        if(tx==er && ty ==ec){
            cout<<0;
            break;
            return 0;
        }

        //2   d 2상 -2하 1좌 -1우
        pair<int,int> d = findD(tx, ty);
        dol = d.second;


        //3 상하좌우 , 좌우상하
        pair<int,int> ans;
        if(d.first==1){
            ans=makeMove(amove1, tx, ty);
        }
        else if(d.first==2){
            ans=makeMove(amove2, tx, ty);

        }
        else if(d.first==3){
            ans=makeMove(amove3, tx, ty);

        }
        else if(d.first==4){
            ans=makeMove(amove4, tx, ty);

        }

        
        cout<<ans.first<<" "<<dol<<" "<<ans.second<<"\n";
        w--;
    }
    
    return 0;
}