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
#include<cassert>
using namespace std;
const int N =1e5+100;
int right[N],left[N],a[N];
int inv,n,m;
void link(int L,int R)
{
	right[L]=R;
	left[R]=L;
}
void show()
{
	for(int i=0;i<=n+1;i++) printf("%d left:%d right:%d\n",i,left[i],right[i]);
}
void showline()
{
	char ch='m';
	int i;
	for(i=1;i<=n;i++)
	{
		if(left[i]==0)ch='l';
	}
	assert(ch!='1');
	int cnt=0;
	for(int num=0;num!=-1;)
	{
		num=left[i];
		a[cnt]=num;
		cnt++;
		a[cnt]=i;
		cnt++;
		num=right[i];
	}
	for(int i=0;i<=n;i++)
		printf(" %d", a[i]);
}
int main()
{

#ifdef DEBUG
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		inv=0;
		int Ks=0;
		printf("Case %d: ",++Ks);
		//initial
		for(int i=0;i<=n+1;i++)
		{
			right[i]=i+1;
			left[i]=i-1;
		}
		show();
		while(m--)
		{
			int ask,x,y;
			scanf("%d",&ask);
			if(ask==4){inv=!inv;continue;}
			int temxl,temxr,temyl,temyr;
			scanf("%d%d",&x,&y);
			switch(ask)
			{
				case 1:
					if(right[x]==y)break;
					temxl=left[x];
					temxr=right[x];
					temyl=left[y];
					temyr=right[y];
					link(temxl,temxr);
					link(temyl,x);
					link(x,y);
					break;
				case 2:
					if(left[x]==y)break;
					temxl=left[x];
					temxr=right[x];
					temyl=left[y];
					temyr=right[y];
					link(y,x);
					link(temxl,temxr);
					link(x,temyr);
					break;
				case 3:
					temxl=left[x];
					temxr=right[x];
					temyl=left[y];
					temyr=right[y];
					link(temxl,y);
					link(y,temxr);
					link(temyl,x);
					link(x,temyr);
					break;
				default:
					exit(1);
					break;
					
			}
		show();
		}
	}
	//insert code
	return 0;
}
