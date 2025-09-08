#include <bits/stdc++.h>

using namespace std;



int n,m;
int main(void){
    cin>>n>>m;

    int arr[n+1][n+1];
    int nxt[n+1][n+1];

    memset(arr, 0, sizeof(arr));
    memset(nxt, 0, sizeof(nxt));

    for(int i =0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(arr[a][b]!=0){
            if(arr[a][b]>c){
                arr[a][b]=c;
                nxt[a][b]=b;
            }
        }
        else{
            arr[a][b]=c;
            nxt[a][b]=b;
        }
    }  

    for(int i=1;i<n+1;i++){
        for(int s=1;s<n+1;s++){
            for(int e=1;e<n+1;e++){
                if(s!=i && e!=i && s!=e){
                    if(arr[s][i]>0 && arr[i][e]>0){
                        if(arr[s][e]==0 || arr[s][e] > arr[s][i]+arr[i][e]){
                            arr[s][e]=arr[s][i]+arr[i][e];
                            nxt[s][e] = nxt[s][i];
                    
                        }
                    }

                }
            }
        }
    
    }
    for(int i=1;i<n+1;i++){
        for(int s=1;s<n+1;s++){
            cout<<arr[i][s]<<" ";
        }
        cout<<"\n";
    
    }
    

    for(int i=1;i<n+1;i++){
        for(int s=1;s<n+1;s++){
            if(arr[i][s]==0)
            {
                cout<<0;
            }
            else{
                /////////
                int tmp=i;
                int cnt=2;
                vector<int> v;
                v.push_back(i);
                
                while(nxt[tmp][s]!=s){
                    cnt++;
                    int t = nxt[tmp][s];
                    v.push_back(t);
                    tmp=t;
                }
                v.push_back(s);
                cout<<cnt<<" ";
                for(int tv : v){
                    cout<<tv<<" ";
                }
            }
            cout<<"\n";
        }
    
    }
    
    return 0;
}