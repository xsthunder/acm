#include<iostream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;
#define iF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#ifdef XS
    #include<De>
    const int Te=1;
#else 
    const int Te=0;
#endif

typedef unsigned U;
typedef pair<int,int > P;
void inp();
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1)inp();
    return 0;
}
typedef long long ll;
const ll mod = 1e9+7;
const ll N  =2e5;
ll a[N];
void inp(){
    int n,l;
    if(!(cin>>n>>l))exit(0);
    MS(a);
    a[0]=1;
    for(int i =1;i<=n;i++){
        int cnt =0;
        for(int j = i-1;j>=0&&cnt<l;j--){
            a[i]+=a[j];
            cnt++;
            a[i]%=mod;
        }
    }
    //pA(a,n+1,3);
    cout<<a[n]<<endl;
}
//Cslow.cc by xsthunder at Fri May 26 19:10:55 2017
