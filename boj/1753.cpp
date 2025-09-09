#include <bits/stdc++.h>

using namespace std;

int v,e,k;

vector<pair<int,int>> arr[20001];
int d[20001];
int main(void){
    cin>>v>>e>>k;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,k});
    for(int i=0;i<e;i++){
        int n1, n2, w;
        cin>>n1>>n2>>w;
        arr[n1].push_back({w,n2});

    }

    while(!pq.empty()){
        int value = pq.top().first;
        int n = pq.top().second;
        pq.pop();
        
        if(d[n]==value){

            for(pair<int,int> p: arr[n]){
                int w = p.first;
                int n2 =p.second;
                if(d[n2]==0||d[n2]>w+d[n]){
                    d[n2]=w+d[n];
                    pq.push({w+d[n],n2});
                }
                
            }
        }
    }
    for(int i =1; i<v+1 ;i++){
        if(i!=k && d[i]==0){
            cout<<"INF"<<'\n';
        }
        else{
            cout<<d[i]<<'\n';
        }
    }



    
    return 0;
}