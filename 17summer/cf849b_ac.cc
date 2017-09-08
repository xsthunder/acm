#include<cstdio>
#include<cmath>
#include<set>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
const double eps = 1e-10;
struct Cmp{
	public :bool operator ()(const double &a,const double &b)const {
		if(fabs(a-b)<=eps)return 0;
		else return a-b<0;
	}
};
bool cmp(double a,double b){
	if(fabs(a-b)<=eps)return 1;
	else return 0;
}
typedef set<double> S;
S s;
const int N = 2000;
int n;
int a[N];
const int inf=1e9;
bool jud(int Y,double k,int X){
	int Y2=inf,X2=inf;
	for(int i= 0;i<n;i++){
		if(cmp(a[i]-Y,k*(i-X))){
			continue;
		}
		else {
			if(Y2==X2&&X2==inf){
				Y2=a[i],X2=i;
			}
			else {
				if(cmp(a[i]-Y2,k*(i-X2))){
					continue;
				}
				else return 0;
			}
		}
	}
	if(Y2==X2&&X2==inf)return 0;
	else return 1;
}
void inp(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
double k;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			k=double(a[j]-a[i])/double(j-i);
			if(s.count(k))continue;
			s.insert(k);
			if(jud(a[i],k,i)){
				puts("yes");
				return ;
			}
		}
	}
	puts("no");
}
//cf849b.cc by xsthunder at Mon Sep  4 15:43:10 2017

//AC at Mon Sep  4 16:08:51 2017
 
