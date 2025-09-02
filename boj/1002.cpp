#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    int t;
    cin>>t;
    while(t>0){
        int x1,y1,r1,x2,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;

        int r = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        if(r==0){
            if(r1==r2)
                cout<<-1<<'\n';
            else
                cout<<0<<'\n';
        }
        else if(r==(r1+r2)*(r1+r2)){
            cout<<1<<'\n';
        }
        else if(r>(r1+r2)*(r1+r2)){
            cout<<0<<'\n';
        }
        else if(r<(r1+r2)*(r1+r2))
        {
            if(r==(r2-r1)*(r2-r1)){
                cout<<1<<'\n';
            }
            else if(r<(r2-r1)*(r2-r1)){
                cout<<0<<'\n';
            }
            else
               cout<<2<<'\n';
        }
        t--;
    }
    return 0;
}