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
	cout<<(t=rand()%10+1);
	cout<<endl;
	for(int i=0;i<t;i++){
		cout<<rand()%int(1e9+1)<<' ';

	}
	cout<<endl;
	for(int i=0;i<t;i++){
		cout<<rand()%int(1e7)+1<<' ';

	}
}
