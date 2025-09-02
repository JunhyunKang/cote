#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(void){
    queue<int> q;
    stack<int> s;
    q.push(1);
    q.push(2);
    s.push(1);
    s.push(2);
    
    int x =0;
    cout<<q.front()<<" " <<s.top()<<"\n";
    q.pop();
	s.pop();
    cout<<q.front()<<" " <<s.top();

    return 0;
}