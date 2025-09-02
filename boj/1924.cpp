#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

enum e{
    SUN, MON, TUE, WED, THU, FRI, SAT
};

int main(void){
    int m,d;
    int a=0;
    cin>>m>>d;
    if(m==1){
        a=0;
    }
    else if(m==2){
        a=31;
    }
        else if(m==3){
        a=31+28;
    }
        else if(m==4){
        a=31+28+31;
    }
        else if(m==5){
        a=31*2+28+30;
    }
        else if(m==6){
        a=31*3+28+30;
    }
        else if(m==7){
        a=31*3+28+30*2;
    }
        else if(m==8){
        a=31*4+28+30*2;
    }
        else if(m==9){
        a=31*5+28+30*2;

    }
        else if(m==10){
        a=31*5+28+30*3;
    }
        else if(m==11){
        a=31*6+28+30*3;
        
    }
        else if(m==12){
        a=31*6+28+30*4;
    }
    a=d+a;
    m = a%7;
        if(m==1){
        cout<<"MON";
    }
    else if(m==2){
        cout<<"TUE";
;
    }
        else if(m==3){
                cout<<"WED";

    }
        else if(m==4){
        cout<<"THU";
    }
        else if(m==5){
        cout<<"FRI";
    }
        else if(m==6){
        cout<<"SAT";
    }
        else if(m==0){
        cout<<"SUN";
    }


    return 0;
}
