#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>

using namespace std;

int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int TK,a,b;
	scanf("%d",&TK);
	while(TK--)
	{
		scanf("%d%d",&a,&b);
		if(a>b)printf(">\n");
		if(a==b)printf("=\n");
		if(a<b)printf("<\n");
	}

	




	
	//insert code
	return 0;
}
