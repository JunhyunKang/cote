#include <bits/stdc++.h>

using namespace std;

int v,e,k;

vector<pair<int,int>> arr[1001];
int d[1001];
int pre[1001];
int main(void){
    cin>>v>>e;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i=0;i<e;i++){
        int n1, n2, w;
        cin>>n1>>n2>>w;
        arr[n1].push_back({w,n2});
        
        
    }
    int end;
    cin>>k>>end;
    pq.push({0,k});
    
    while(!pq.empty()){
        int value = pq.top().first;
        int n = pq.top().second;
        pq.pop();
        
        if(d[n]==value){

            for(pair<int,int> p: arr[n]){
                int w = p.first;
                int n2 =p.second;
                if((n2!=k&&d[n2]==0)||d[n2]>w+d[n]){
                    d[n2]=w+d[n];
                    pre[n2]=n;
                    
                    pq.push({w+d[n],n2});
                }
                
            }
        }
    }

    cout<<d[end]<<'\n';
    vector<int> r;
    int t = end;
    r.push_back(t);
    int cnt=2;
    while(pre[t]!=k){
        r.push_back(pre[t]);
        t = pre[t];
        cnt++;
    }
    
    cout<<cnt<<"\n";
    
    cout<<k<<" ";
    for(int i = r.size()-1; i>=0 ;i--){
        cout<<r[i]<<" ";
    }

   
    return 0;
}