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
	freopen("poj2823.in","r",stdin);
	try{
		//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
		inp();
	}
	catch(... ){
		IF printf("%s","exception");
	}//for compatibility with cygwin c++ runtime
	return 0;
}
const int N = 1e6+1e5;
int a[N];
P heap[N];
int n,k;
int whe[N];

void up(int i){

}
int ppcnt=1;
void pp(){
	printf("pp:%d\n",ppcnt++);
	for(int i =1;i<=k;i++){
		printf("%d:(%d,%d)\n", i,heap[i].first,heap[i].second);
	}
}
template<typename T>
void Faheap(T cmp){
	for(int i =1;i<=k;i++){
		heap[i].first=a[i];
		heap[i].second= i;
	}
	for(int i = k/2;i>=1;i--){
		int tar = i;
		if(cmp(heap[tar],heap[i*2]))tar = i*2;
		if(i*2+1<=k&&cmp(heap[tar],heap[i*2+1]))tar = i*2+1;
		swap(heap[tar],heap[i]);
	}
	for(int i =1;i<=k;i++){
		whe[heap[i].second]=i;
	}
	
	int * bit = a + 1;
	int *eit = a + k + 1;
	int *end =  a + n + 1;
	while(eit!=end){
		printf("%d ",  heap[1].first);
		int del = whe[(bit - a)];
		heap[del] = P(*(eit),eit-a);
		whe[eit-a]=del;
		eit++;
		bit++;
		//down 
		for(int p = del;2*p<=k;){
			int tar = p ;
			if(cmp(heap[tar],heap[p*2]))tar = p*2;
			if(2*p+1<=k&&cmp(heap[tar],heap[p*2+1])) tar = p*2+1;
			if(tar==p)break;
			swap(whe[heap[tar].second],whe[heap[p].second]);
			swap(heap[tar],heap[p]);
			p=tar;
		}
		//up
		while(1){
			int p= del/2;
			if(!p)break;
			if(cmp(heap[p],heap[del])){
				swap(whe[heap[p].second],whe[heap[del].second]);
				swap(heap[p],heap[del]);
			}
			else break;
			del/=2;
		}
		//pp();
	}
	printf("%d",  heap[1].first);
}
void inp(){
	scanf("%d%d", &n,&k);
	for(int i = 1 ;i<=n;i++){
		scanf("%d", &a[i]);
	}
	greater<P> g;
	less<P> l;
	Faheap(g);
	printf("\n");
	Faheap(l);
	//printf("\n");
}
//poj2823.cc by xsthunder at Tue Jul 11 16:00:00 2017

//AC at Tue Jul 11 22:35:18 2017
 
