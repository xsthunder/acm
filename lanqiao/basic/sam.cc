#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    double x1,x2,y1,y2;
    double x3,x4,y3,y4;
    double m1,n1;
    double m2,n2;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    m1 = max(min(x1,x2),min(x3,x4));
    n1 = max(min(y1,y2),min(y3,y4));
    m2 = min(max(x1,x2),max(x3,x4));
    n2 = min(max(y1,y2),max(y3,y4));
    if(m1 < m2 && n1 < n2){
        printf("%.2lf\n",(m2 - m1) * (n2 - n1));
    }
    else 
        printf("0.00\n");
    return 0;
} 
