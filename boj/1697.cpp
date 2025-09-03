#include <bits/stdc++.h>

using namespace std;

// 걸으면 +- 1 씩
// 순간이동은 *2 씩

const int MAX = 100000;
vector<int> arr(MAX+1, -1);
int n,k;


queue<int> q;
int main(void){
    cin>>n>>k;
    int answer=0;
    arr[n]=0;

    q.push(n);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur==k){
            break;
        }
        int back = cur-1;
        int front = cur+1;
        int move = cur*2;
        if(back>=0&&arr[back]==-1){
            arr[back]=arr[cur]+1;
            q.push(back);
        }
        if(front<=MAX&&arr[front]==-1){
            arr[front]=arr[cur]+1;
            q.push(front);

        }
        if(move<=MAX&&arr[move]==-1){
            arr[move]=arr[cur]+1;
            q.push(move);
        }
    }

    cout<< arr[k];
    
    return 0;
}