#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>

using namespace std;
const int maxn=80+10;
map<char, double>atom;
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int TK;
	char s[maxn];
	atom['C']=12.01;
	atom['H']=1.008;
	atom['O']=16.00;
	atom['N']=14.01;
	scanf("%d",&TK);
	while(TK--)
	{
		scanf("%s",s	);
		printf("%s",s);
		double prv=0;
		double sum=0;
		int i=0;
		for(;s[i]!='\0';i++);
		{
			char c=s[i];
			printf("%c\n",c);

			if(isdigit(c))sum+=(s[i]-1)*prv;
			else 
			{
				prv=s[i];
				sum+=prv;
			}
		}
		printf("%.3f",sum);

	}

	

	




	
	//insert code
	return 0;
}
