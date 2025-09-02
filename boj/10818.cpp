#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int i, w;
    vector <int> a;

    for(i=0;i<n;i++){
        cin>>w;
        a.push_back(w);

    }
    sort(a.begin(), a.end());
    cout<<a.front()<<" "<<a.back()<<'\n';
    return 0;
}