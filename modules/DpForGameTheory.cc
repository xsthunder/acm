//DpForGameTheory.cc by xsthunder
//硬币模型
#include<cstdio>
const int MAX_K=100;
const int MAX_X=100;
int X,K,A[MAX_K+1];
bool win[MAX_X+1];
void solve (){
	win[0]=0;

	for(int j=0;j<=X;j++){
		win[j]=0;
		for(int i=0;i<K;i++){
			//必胜必败态转移
			win[j]|=A[i]<=j&&!win[j-A[i]];
		}
	}
	if(win[X])puts("Alice");
	else puts("Bob");
}
