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
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	int ans;
	while(n--){
		int x;
		char a,b;
		scanf("%d:%c%c", &x,&a,&b);
		if(a!='0'||b!='0')ans=0;
		else {
			if(x<=12)ans=12+x;
			else {
				ans=x-12;
			}
		}
		cout<<ans<<endl;

	}

	
	//insert code
	return 0;
}
//7-27e.cc

//AC

