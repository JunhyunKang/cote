#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
const int MAX = 200005;
int arr[MAX];
int main(void){
    // int n=1,k=100000;
    int n,k;
    cin>>n>>k;
    


    queue<int> q;

    q.push(n);

    int ans=0;
    while(!q.empty()){
        arr[q.front()]=ans;
        if(q.front() == k){
            
            break;
        }

        if(arr[q.front()*2]==0){
            q.push(q.front()*2);

        }
    
        if(arr[q.front()+1]==0){
            q.push(q.front()+1);

        }

        if(arr[q.front()-1]==0){
            q.push(q.front()-1);

        }
        q.pop();   
        ans++;
    }
    int cnt=0;
    int s=0;
    while(ans-s>0){
        cnt++;
        s=s+pow(3, cnt);
    }
    cout<<cnt;
    return 0;
}