#include <bits/stdc++.h>

using namespace std;
struct Student{
    int age;
    int num;
};

struct Compare{
    bool operator()(const Student& a, const Student& b){
        return a.age > b.age;
    }
};
priority_queue<Student, vector<Student>, Compare> pqpq;
sort(a.begin(), a.end(), greater<>());
priority_queue<int, vector<int>, greater<int>> llpqpq;

int n;
int arr[100002];
int main(void){
    priority_queue<int, vector<int>, greater<int>> pq;
    cin>>n;

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        pq.push(tmp);

    }
    long long sum =0;
    long long ans=0; 
    long long tmp=0;
    if(n==1){
        ans=0;
    }
    else{
        while(pq.size()>1){
            int t1 = pq.top();
            pq.pop();
            int t2 = pq.top();
            pq.pop();
            ans = ans + t1+t2;
            pq.push(t1+t2);
        }
    }
    cout<<ans;

    return 0;
}


