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
	cout<<(t=rand()%40+1)<<endl;;
	for(int  i=0;i<t;i++){
		cout<<(rand()%50+1)<<' ';
	}
	cout<<endl;
	cout<<0<<endl;
}
