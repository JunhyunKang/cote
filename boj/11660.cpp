#include <bits/stdc++.h>

using namespace std;


int n,m;
int arr[1030][1030];
int hap[1030][1030];

vector<pair<int,int>> p1;
vector<pair<int,int>> p2;

int main(void){
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];

        }
    }

    for(int i=1;i<=m;i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        p1.push_back({x1,y1});
        p2.push_back({x2,y2});
    }
    hap[1][1]=arr[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1&&j==1){
                continue;
            }
            else if(i==1){
                hap[i][j] =arr[i][j]+ hap[i][j-1];
            }
            else if(j==1){
                hap[i][j] =arr[i][j]+ hap[i-1][j];

            }
            else{
                hap[i][j] = arr[i][j]+ hap[i-1][j] + hap[i][j-1] - hap[i-1][j-1];
            }

        }
    }

    
    for(int i=0; i<p1.size();i++){
        int x1 = p1[i].first;
        int y1 = p1[i].second;
        int x2 = p2[i].first;
        int y2 = p2[i].second;

        int answer=hap[x2][y2]-hap[x1-1][y2]-hap[x2][y1-1]+hap[x1-1][y1-1];
        
        cout<<answer<<"\n";
    }

   
    return 0;
}