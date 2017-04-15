const bool TEST=0;
#include<iostream>
#include<bitset>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
#include<sstream>
#include<stack>
const int inf=0x7fffffff;
#define IF if(TEST)
#define FI if(!TEST)
#define gts(s) fgets((s),sizeof(s),stdin)
#define ALL(s) (s).begin(),(s).end()
#define MK(a,b) make_pair((a),(b))
typedef long long int LL;
typedef unsigned int U;
typedef unsigned long long ULL;
using namespace std;
typedef pair<int,int> Point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ cout<<*(begin++); } printf("\n"); }
int G[30][30];
bool test(U n,U N){
	IF cout<<N;
	int b=0,g=0;
	U mask=1;
	for(U  i = 0 ; i < n ;i++){
		if(mask&N)g++;
		else b++;
		mask=mask<<1;
	}
	if(g>b){
		mask=1;
		for( U i = 0 ;i < n;i++){
			IF {
				if(N==5){
					printf("i:%d mask:%d\n",i,mask);
				}
			}
			if(mask&N){
				U submask=1;
				for(U subi=0;subi<n;subi++){
					bool cur= submask&N;
					IF {
						if(N==5){
							printf("subi:%d submask:%d\n",subi,submask);
						}
					}
					if((bool )G[i][subi]!=cur)return 0;
					submask=submask<<1;
				}
			}
			mask=mask<<1;
		}
		return 1;
	}
	else {
		IF {
			cout<<"exit test due to g<=b N:"<<N<<endl;
		}
		return 0;
	}
	return 1;
};
void sol(){
	U n ; 
	cin>>n;
	U N;
	for(U i = 0 ;i < n;i++){
		for( U j = 0 ; j < n;j++){
			scanf("%d", &G[i][j]);
		}
	}
	N=(1<<n)-1;
	while(!test(n,N)){
		N--;
		if(N==0){
			IF cout<<"exit duto N = 0 ";
			exit(2);
		}
	}
	U mask = 1; 
	bool fflag=0;
	for(U i = 0 ;i< n;i++){
		if(mask&N){
			if(fflag)cout<<' ';
			fflag=1;
			cout<<i+1;
		}
		mask=mask<<1;
	}
}
int main()
{
	sol();
	return 0;
}
//64.cc
//generated automatically at Sat Feb  4 15:11:04 2017
//by xsthunder

