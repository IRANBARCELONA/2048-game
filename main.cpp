#include <iostream>
#include <limits>
using namespace std;
int main() {

    int a,b[2],c,d;
    int max=numeric_limits<int>::min();
    int min=numeric_limits<int>::max();
    for (int i=0;i<2;i++){
        cin>>b[i];
        if(max<b[i])
            max=b[i];
        if(min>b[i])
            min=b[i];
        if(b[i]>min and b[i]<max)
            a=b[i];
    }
    if(max!=min){
        min=max;
        d++;
        if(a!=max){
            c=b;
            d++;
        }
    }
    else if(b!=c){
        b=c;
        d++;
    }
    cout<<d;
    return 0;
}
