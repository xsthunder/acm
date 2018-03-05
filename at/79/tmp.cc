#include<cstdio>
#include<iostream>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<utility>
#ifdef XS
	#include<De>
#endif
using namespace std;
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	try{
		while(1)
		inp();
	}
	catch(... ){
#ifdef XS
		printf("%s","exception");
#endif
	}//for compatibility with cygwin c++ runtime
	return 0;
}
void inp(){
	int sum  = 10;
	cin>>sum;
	int n = 2;
	for(int i = 0;i < sum;i++){
		priority_queue<int> pq;
		if(sum-i<i)break;
		pq.push(i),pq.push(sum - i);
		int cnt = 0;
		while(pq.top() >=n){
			int x = pq.top();pq.pop();
			int y = pq.top();pq.pop();
			x -= n;y+=1;
			cnt++;
			pq.push(x),pq.push(y);
		}
		printf("%d,%d :%d\n", i,sum - i, cnt);
	}
}
//tmp.cc by xsthunder at Sat Jul 29 21:15:39 2017

