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
	int n = rand()%10+2;
	int k = rand()%(n/2)+1;
	cout<<n<<' '<<k<<endl;
	for(int i =0;i<n;i++)cout<<rand()%100<<' ';
	cout<<endl;
}
