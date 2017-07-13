#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
#ifdef XS
	const int Te=1;
#include<De>
#else 
	const int Te=0;
#endif
using namespace std;
#define IF if(Te)
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
	//freopen("poj1182.in.max","r",stdin);
	try{
		//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
		inp();
	}
	catch(... ){
		IF printf("%s","exception");
	}//for compatibility with cygwin c++ runtime
	return 0;
}
int n,k;
const int N = 5e4+1e3;
int p[N];
int w[N];
P find(int x){
	P ans;
	if(p[x]>0){
		ans = find(p[x]);
		p[x]=ans.first;
		w[x]+=ans.second;
		w[x]%=3;
		ans.second = w[x];
		return ans;
	}
	else return P(x,0);
}
void uni(int x,P fax,int y,P fay,int d){
	if(p[fax.first]<p[fay.first]){//fay i bigger set
		swap(x,y);
		swap(fax,fay);
		d = d?2:0;
	}
	p[fay.first]+=p[fax.first];
	p[fax.first]=fay.first;
	w[fax.first]= (3-fax.second + d + fay.second)%3;
	p[x]=fay.first;
	w[x]=d+fay.second;
	w[x]%=3;
}
void inp(){
	scanf("%d%d", &n,&k);
	int cnt=0;
	memset(p,-1,sizeof(p));
	MS(w);
	while(k--){
		int d,x,y;
		scanf("%d%d%d", &d,&x,&y);
		if(x>n||y>n){
			cnt++;
			continue;
		}
		if(d==2&&x==y){
			cnt++;
			continue;
		}
		d--;
		P fax = find(x);
		P fay = find(y);
		if(fax.first==fay.first){
#ifdef XS
			IF cout<<"fax"<<' '<<fax;
			IF cout<<"fay"<<' '<<fay<<endl;
#endif
			if(fax.second!=(fay.second+d)%3) cnt++;
		}
		else {
			uni(x,fax,y,fay,d);
		}

#ifdef XS
		pA(p,10);
		pA(w,10);
#endif
		IF cout<<d<<' '<<x<<' '<<y<<' '<<cnt<<endl;
	}
	printf("%d\n",cnt);
}
//poj1182.cc by xsthunder at Wed Jul 12 20:48:10 2017

//AC at Thu Jul 13 09:20:39 2017
 
