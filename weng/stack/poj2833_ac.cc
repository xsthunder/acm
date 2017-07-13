#include<iostream>
#include<queue>
#include<algorithm>
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
	//freopen("poj2833.in","r",stdin);
	try{
		//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
		while(1)inp();
	}
	catch(... ){
		IF printf("%s","exception");
	}//for compatibility with cygwin c++ runtime
	return 0;
}
template <typename CMP>
struct Heap
{
	CMP cmp;
	int size,max;
	ll a[20];
	Heap(const int max){
		this->size=0;
		this->max =max;
		this->a[0]=0;
		return;
	}
	void down(){
		for(int p = 1,tar;p*2<=this->size;p=tar){
			tar = p;
			if(cmp(this->a[tar],this->a[2*p]))tar=2*p;
			if(2*p+1<=this->size&&cmp(this->a[tar],this->a[2*p+1]))tar = 2*p+1;
			if(tar==p)break;
			swap(this->a[tar],this->a[p]);
		}
	}
	void up(int n){
		for(int p = n/2,tar;p>0;p/=2,n/=2){
			tar = p ;
			if(cmp(this->a[tar],this->a[n]))tar = n;
			if(tar==p)break;
			swap(this->a[tar],this->a[p]);
		}
	}
	void pop(){
		this->a[1]=this->a[this->size];
		this->size--;
		this->down();
	}
	void push(ll val){
		if(this->size==this->max){
			if(!cmp(this->a[1],val))
				this->pop();
			else return;
		}
		this->a[++this->size]=val;
		this->up(this->size);
	}
	ll sum(){
		ll s = 0;
		for(int i =1;i<=this->size;i++){
			s+=this->a[i];
		}
		return s;
	}
};
void inp(){
	int n1,n2,n;
	if(!~scanf("%d%d%d",&n1,&n2,&n)||!n1||!n2||!n)exit(0);

	Heap<less<int> >  hl(n2);//max heap
	Heap<greater<int> > hg(n1);//min heap

	int x;
	ll sum =0;
	for(int i =0;i<n;i++){
		scanf("%d",&x);
		sum+=x;
		hl.push(x);
		hg.push(x);
	}
//	pA(hl.a,hl.size+1,10);
//	pA(hg.a,hg.size+1,10);
	sum-=(hl.sum()+hg.sum());
	printf("%.6lf\n", (double)sum/(n-n1-n2));
}
//poj2833.cc by xsthunder at Tue Jul 11 22:44:12 2017

//AC at Wed Jul 12 09:42:52 2017
 
