#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<climits>

using namespace std;
typedef long long int lli;
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
#endif
	int n,m;
	while(scanf("%d%d", &n,&m)!=EOF)
     {
     	if(n==0||m==0)break;
     	float sum=0;
     	for(lli i=n;i<=m;i++)
     	{
		//printf("i:%lld\n", i);
		//printf("i*i:%lld\n", i*i);
     		sum+=1.0/(i*i);
     	}
     	printf("%.5f\n",sum);
     }

	




	
	//insert code
	return 0;
}
