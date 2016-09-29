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

	for(int i=100;i<=999;i++)
	{
		int a=i%10;
		int aa=i%100/10;
		int aaa=i/100;
		if(i==a*a*a+aa*aa*aa+aaa*aaa*aaa)printf("%d\n",i);
	}
	
	




	
	//insert code
	return 0;
}
