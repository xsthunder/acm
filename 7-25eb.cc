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
typedef unsigned long long int llu;
int main()
{

#ifdef DEBUG
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int n,k;
	llu gcd,sum,lcm;
	while(scanf("%d%d",&n,&k)!=EOF){
		llu x;
		gcd=1;
		lcm=1;
		for(int i=0;i<n;i++){
			scanf("%llu",&x);
			gcd=__gcd(lcm,x);
			sum=lcm*x;
			lcm=sum/gcd;
			lcm=lcm%k;//防止溢出
		}
//		cout<<lcm<<endl;
//		cout<<(lcm%k)<<endl;
		printf("%s\n",lcm%k==0?"Yes":"No");
	}

	
	//insert code
	return 0;
}
//AC

//AC

