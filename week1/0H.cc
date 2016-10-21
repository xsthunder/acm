#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#define MS(s) memset((s),0,sizeof((s)))
const int N=1e5+100;
int max(int a,int b){
	if(a>b)return a;else return b;
}
int du[N];
int val[N];
void sol(){
	int Tcase;
	scanf("%d",&Tcase);
	while(Tcase--){
		MS(du);MS(val);
		int dd;
		int n,m;
		int f;
		int ans=0;
		int ma=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			int t;
			scanf("%d",&t);
			val[i]=t;
		}
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			du[a]++;du[b]++;
		}
		dd=0;
		f=0;
		for(int i=1;i<=n;i++){
			if(du[i]%2)dd++;
		}
		//IF cout<<"dd:"<<dd;
		if(dd==0||dd==2)f=1;
		if(!f){
			printf("Impossible\n");continue;
		}
		for(int i=1;i<=n;i++){
			if(((du[i]+1)/2)%2==1)ans^=val[i];
		}
		if(!dd){
			for(int i=1;i<=n;i++){
				int t=ans^val[i];
				ma=max(ma,t);
			}
			ans=ma;
		}
		printf("%d\n",ans);
	}
}
int main(){
	sol();
}
