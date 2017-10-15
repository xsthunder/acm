#include<cstdio>
#include<list>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<double ,double> P;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	while(1)inp();
	return 0;
}
const int N = 2e5;
const double eps = 1e-10;
struct L{
	P a, b;int id;
}ls[N];
#define X first
#define Y second
double operator * (P a,P b){ return a.X*b.Y-a.Y*b.X; }
P operator -(P a,P b){ return P(a.X-b.X,a.Y-b.Y); }
int dcmp(double a){
	if(fabs(a)<eps)return 0;
	if(a<0)return -1;
	return a>0;
}
bool _inter(L a,L b){
	return dcmp(((b.b-a.a)*(a.b-a.a))
		*((b.a-a.a)*(a.b-a.a)))<0;
}
bool inter(L a,L b){
	return _inter(a,b)&&_inter(b,a);
}
list <L > List;
list <L >::iterator it;
void inp(){
	int n;scanf("%d",&n);if(!n)exit(0);
	List.clear();
	L l ;
	for(int i=0;i<n;i++){
		l.id=i,scanf("%lf%lf%lf%lf",&l.a.X,&l.a.Y,&l.b.X,&l.b.Y);
		for(it = List.begin();it!=List.end();){
			if(inter(*it,l)){ List.erase(it++); }
			else it++;
		}
		
		List.push_back(l);
	}
	int f = 1;
	printf("Top sticks: ");
	for(it = List.begin();it!=List.end();it++){
		if(!f){ printf(", "); }
		f = 0;
		printf("%d",it->id+1);
	}
	printf(".\n");
}
//poj2653.cc by xsthunder at Sun Oct 15 20:16:23 2017

//AC at Sun Oct 15 20:55:36 2017
 
