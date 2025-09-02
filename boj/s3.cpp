#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

int n;
int arr[30][30];

void rotate(){
    int temp[30][30];
    for(int i =0 ; i<n;i++){
        for(int j =0 ; j<n;j++){
            temp[i][j]=arr[i][j];
        }
    } 
    int m = n/2;
    for(int i =0 ; i<n;i++){
        for(int j =0 ; j<n;j++){
            if(i==n/2 || j==n/2){
                if(i<n/2 && j==n/2){
                    temp[m][i] = arr[i][j];
                }
                else if(i==n/2 && j<n/2){
                    temp[m+(m-j)][m] = arr[i][j];
                }
                else if(i>n/2 && j==n/2){
                    temp[m][i] = arr[i][j];
                }
                else if(i==n/2 && j>n/2){
                    temp[m+(m-j)][m] = arr[i][j];
                }
            }
            else{
                if(i<n/2 && j<n/2){
                    temp[j][m-1-i] = arr[i][j];
                }
                else if(i<n/2 && j>n/2){
                    temp[j-m-1][m*2-i] = arr[i][j];
                }
                else if(i>n/2 && j<n/2){
                    temp[j+m+1][m*2-i] = arr[i][j];
                }
                else if(i>n/2 && j>n/2){
                    temp[j][m*3-i+1] = arr[i][j];

                }

            }
        }
    }
    for(int i =0 ; i<n;i++){
        for(int j =0 ; j<n;j++){
            arr[i][j]=temp[i][j];
        }
    } 
}
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int calcultate(int n){
    queue<pair<int, int>> q;
    int check[30][30];
    memset(check, 0, sizeof(check));

    vector<vector<pair<int,int>>> groups;
    vector<int> combination;
    int count=0;
    for(int i = 0 ; i< n; i++){
        for(int j = 0 ; j< n; j++){
            if(check[i][j]==0){
                int temp = arr[i][j];
                check[i][j]=1;
                q.push({i,j});
                vector<pair<int,int>> tempv;
                while(!q.empty()){
                    int curx= q.front().first;
                    int cury= q.front().second;
                    tempv.push_back({curx, cury});
                    q.pop();
                    for(int d =0;d<4;d++){
                        int nx = curx+dx[d];
                        int ny = cury+dy[d];
                        if(nx>=0&&nx<n&&ny>=0&&ny<n&& temp==arr[nx][ny] && check[nx][ny]==0){
                            check[nx][ny]=1;
                            q.push({nx,ny});
                            
                        }

                    }
                }
                groups.push_back(tempv);
                combination.push_back(count);
                count++;
            }
        }
    }
    int score = 0;
    for(int i =0;i<combination.size()-1;i++){
        for(int j = i+1; j<combination.size();j++){
            int c1 = combination[i];
            int c2 = combination[j];

            int countG1 = groups[i].size();
            int countG2 = groups[j].size();
            int numG1 = arr[groups[i][0].first][groups[i][0].second];
            int numG2 = arr[groups[j][0].first][groups[j][0].second];
            int connect=0;
            for (auto gpair : groups[i]){
                for(int d =0;d<4;d++){
                        int nx = gpair.first+dx[d];
                        int ny = gpair.second+dy[d];
                        if(nx>=0&&nx<n&&ny>=0&&ny<n){
                            pair<int, int> tempP = {nx, ny};
                           
                            if (find(groups[j].begin(), groups[j].end(), tempP) != groups[j].end()) {
                                connect++;
                            }
                        }
                        
                    }
            }
            score += (countG1+countG2)*numG1*numG2*connect;

        }
    }
    return score;

}

int main() {
    // Please write your code here.
    cin>>n;
    for(int i =0 ; i<n;i++){
        for(int j =0 ; j<n;j++){
            cin>>arr[i][j];
        }
    }
    int first = calcultate(n);
    rotate();

    first += calcultate(n);
    rotate();
    first += calcultate(n);
    rotate();
    first += calcultate(n);

    cout<<first;
    return 0;
}