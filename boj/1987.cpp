#include<bits/stdc++.h>
using namespace std;

char arr[21][21];
int check[21][21];
int func(int r, int c, int x, int y, int cnt, vector<int> used){
    if(cnt==r*c || cnt>25){
        return cnt;
    }

    if(x<r && x>=0 && y<c && y>=0){
        int idx = (int)arr[x][y]-65;
        if(used[idx]==0){
            
            used[idx]=1;
            int m1=0,m2=0,m3=0,m4=0;
            if(x+1<r && used[(int)arr[x+1][y]-65]==0)
            m1 = func(r, c, x+1, y, cnt+1, used);
            if(y+1<c && used[(int)arr[x][y+1]-65]==0)
            m2= func(r, c, x, y+1, cnt+1, used);
            if(x-1>=0 && used[(int)arr[x-1][y]-65]==0)
                m3=func(r, c, x-1, y, cnt+1, used);
            if(y-1>=0 && used[(int)arr[x][y-1]-65]==0)
                m4=func(r, c, x, y-1, cnt+1, used);
        
            int mm1 = max(m1, m2);
            int mm2 = max(m3, m4);
            if(mm1==0 && mm2==0){
                return cnt+1;
            }
            return max(mm1,mm2);
        }

        return cnt;
    }
    return cnt;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int r,c;
    cin>>r>>c;
    for(int i =0;i<r;i++){
        for(int j =0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    vector<int> used(30, 0);
    memset(check, -1, sizeof(check));
    int cnt = func(r, c, 0, 0, 0, used);
    
    cout<<cnt;
    return 0;
}