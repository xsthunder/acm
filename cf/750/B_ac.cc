const bool test=1;
#include<iostream>
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
const int inf=0x7fffffff;
#define IF if(test)
#define FI if(!test)
#define gts(s) fgets((s),sizeof(s),stdin)
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
const int north=20000;
const int south=0;
bool check1(int cur){
	if(cur>north||cur<south)return false ;
	else return true;
}
void sol(){
	int n;
	cin>>n;
	int cur=north;
	int d;
	string s;
	bool flag=1;
	while(n--){
		cin>>d>>s;
		switch(s[0]){
			case 'S':d=-d;
			case 'N':
							 cur+=d;
							 if(!check1(cur)){
								 flag=0;
							 }
							 break;
			case 'E':
			case 'W':
							 if(cur==north||cur==south){
								 flag=0;
							 }
							 break;
		}
	}
	if(cur!=north)flag=0;
	cout<<(flag?"YES":"NO")<<endl;
}
int main()
{
	sol();
	return 0;
}
//A_ac.cc
//generated automatically at Mon Jan  2 22:59:19 2017
//by xsthunder

