#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>

using namespace std;

int white(int num)
{
	while(num--)
	{
		printf(" ");
	}
	return 0;
}
int sharp(int num)
{
	while(num--)
	{
		printf("#");

	}
	printf("\n");
	return 0;
}
int main()
{

	int n;
	while(scanf("%d", &n)==1)
	{
		for(int i=n;i>=1;i--)
		{
			white(n-i);
			sharp(2*i-1);
		}
	}
	




	
	//insert code
	return 0;
}
