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


using namespace std;

struct mtr{
	int fir,sec;
};
mtr s[26+5];
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{scanf("%*c%d%d",&s[i].fir,&s[i].sec);}
	string st;
	while(cin>>st)
	{
		stack<mtr> sm;
		int sum=0;
		cout<<st<<endl;
		for(auto it=st.begin();it!=st.end();it++)
		{
			if(*it==')')
			{
				mtr B=sm.top();sm.pop();
				mtr A=sm.top();sm.pop();
				if(A.sec!=B.fir)printf("error\n");
				else 
				{
					mtr C;
					C.fir=A.fir;
					C.sec=B.sec;
					sm.push(C);
					sum+=A.fir*A.sec*B.sec;
				}
			}
			else sm.push(s[*it-'A']);
		}
		printf("%d\n",sum);
	}


	
	//insert code
	return 0;
}
