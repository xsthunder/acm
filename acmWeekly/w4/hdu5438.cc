const int TEST=1;
#include<queue>
#include<iostream>
#include<cstring>
#include<vector>
#define IF if(TEST)
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
typedef set<int > VI;
typedef unsigned int U;
const int N=1e4+100;
void pA(int *A,int n){
	IF {for(int i =0  ;i < n;i++){
		printf("%u ", *(A+i));
	}
	printf("\n");
	}
}
VI E[N];
int Da[N];
int B[N];
int G[N];
int De[N];
int n,m,d,dI;
void inp();
void init();
void sol();
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		inp();
		init();
		sol();
	}
}
int UN[N];
void sol(){
	memset(UN,-1,sizeof(UN));
}
void init(){
	queue<int > q;
	for(int i =0 ;i< n;i++){
		if(De[i]==1)q.push(i);
	}
	while(!q.empty()){
		int ind=q.front();
		q.pop();
		switch(De[ind]){
			case 0:break;
			case 1:{
							 for(int t:E[ind]){
								 De[t]--;
								 q.push(t);
							 }
						 }
						 De[ind]--;
						 break;
		}
	}
	pA(De,n);
}
//void init(){
//	IF cout<<"hello init"<<n<<endl;
//	memset(heap,-1,sizeof(-1));
//	for(int i = 0 ;i <n;i++){
//		heap[i]=De[i];
//	}
//	for(int i = n-1;i>0;i--){
//		U &t=heap[(i-1)>>1];
//		U &c=heap[i];
//		if(c<t)swap(t,c);
//	}
//	pA(heap,n);
//	for(int i = 0 ;i < n;i++){
//	}
//}
void inp(){
	scanf("%d%d", &n,&m);
	int f,t;
	for(int i = 0 ;i< n;i++){
		scanf("%d", Da+i);
	}
	for(int i =0 ;i< m;i++){
		scanf("%d%d", &f,&t);
		f--,t--;
		De[f]++,De[t]++;
		E[f].insert(t),E[t].insert(f);
	}
	pA(De,n);
}
