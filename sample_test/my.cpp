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
int inp();
int main(){
	//freopen("mergesort.in","r",stdin);
	try{
		int n;scanf("%d",&n);for(int i=1;i<=n;i++)
		printf("Scenario #%d:\n%d\n\n",i,inp());
	}
	catch(... ){
		IF printf("%s","exception");
	}//for compatibility with cygwin c++ runtime
	return 0;
}
const int N = 2000;
int a[N];
int tmp[N];
int merge(const int L,const int mid,const int r){
	int ans = 0; 
	int cnt = L;
	int l =cnt;
	int m = mid;
	while(l<mid&&m<r){
		if(a[l]<=a[m])(tmp[cnt++]=a[l]),l++;
		else (ans+=mid-l),(tmp[cnt++]=a[m]),m++;
	}
	while(l<m)tmp[cnt++]=a[l++];
	while(m<r)tmp[cnt++]=a[m++];
	memcpy(a+L,tmp+L,sizeof(int)*(r-L));
	return ans;
}
int mergeSort(int l,int r){
	if(r==l+1){
		return 0;
	}
	int mid = (l+r)/2;
	int ans = 0;
	ans +=mergeSort(l,mid);
	ans+= mergeSort(mid,r);
	ans +=merge(l,mid,r);
//	IF printf("%d %d %d \n",l, r, ans);
	return ans;
}
int inp(){
	int n;
	scanf("%d", &n);
	for(int i =0;i<n;i++){
		scanf("%d", &a[i]);
	}
	int ans = mergeSort(0,n);
	//pA(a,n);
	return ans ;
}
//mergesort.cc by xsthunder at Sat Jul  8 16:04:31 2017
