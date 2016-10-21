#include<cstdio>
#include<ctime>
#include<iostream>
#include<cstdlib>
#include<cctype>
#include<climits>
using namespace std;
int main()
{
	srand(time(0));
	int t;
	cout<<(t=rand()%1000000);
	cout<<endl;
}
