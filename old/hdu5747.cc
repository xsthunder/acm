#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
using namespace std;
const int inf=0x7fffffff;
//int main()
//{
//
//#ifdef DEBUG
////	freopen("in", "r", stdin);
////	freopen("out", "w", stdout);
//#endif
//	int T;
//	scanf("%d",&T);
//	while(T--)
//	{
//		unsigned long sum=0;
//		unsigned long n,m;
//		unsigned long mask;
//		scanf("%lu%lu",&n,&m);
//		mask=1;
//		for(unsigned long i=0;i<m;i++){
//			sum+=mask&n;
//			n=n>>1;
//			if(n==0)break;
//		}
//		sum+=n;
//		printf("%lu\n",sum);
//	}
//
//	
//	//insert code
//	return 0;
//}
//////AC



int main(){
	int n,m;
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		if(m>=31)m=31;
		cout<<((n>>m)+__builtin_popcount(n&((-1<<m)^(-1))))<<endl;

	}
}
//AC

