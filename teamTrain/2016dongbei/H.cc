#include<iostream>
#include<list>
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
	int t;
	cin>>t;
	for(int i =1;i<=t;i++){
		cout<<"Case #"<<i<<":\n";
		inp();
	}
	return 0;
}
char s [ 30];
const int N  = 5e5;
int zero[N];
int cnt = 0;
void inp(){
	int n,x;
	cnt = 0;
	int M = N /2;
	int f,e;
	f=M;
	e=M-1;
	int zl=M;
	int zr=M-1;
	MS(zero);
	cin>>n;
	int flag = 1;
	while(n--){
		cin>>s;
		switch(s[0]){
			case 'P':
				if(s[1]=='U'){
					cin>>x;
					if(!x){
						if(flag) zero[++zr]=++e;
						else zero[--zl]=--f;
					}
					else {
						if(flag)e++;
						else f--;
					}
				}
				else {
					if(flag){
						if(zr>=zl)
							if(zero[zr]==e)zr--;
						e--;
					}
					else {
						if(zr>=zl)
							if(zero[zl]==f)zl++;
						f++;
					}
				}
				break;
			case 'Q':
				if(f>e){
					cout<<"Invalid.\n";
					break;
				}
				else {
					int cnt;
					if(zl>zr){
						cnt=e-f+1;
						cnt=(cnt&1);
					}
					else 
					{
						if(flag){
							cnt=e-zero[zr];
							if(zero[zr]-f==0)
							cnt=(cnt%2?0:1);
						}
						else {
							cnt=zero[zl]-f;
						}
						//cout<<' '<<cnt<<endl;
						cnt=(cnt%2?0:1);
					}
					cout<<cnt<<endl;
				}
				break;
			case 'R':
				flag=!flag;
				break;
		}
	}
}
//H.cc by xsthunder at Tue May 16 20:39:44 2017

