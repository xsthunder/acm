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
	int n = rand()%10000;
	int l = rand()%n;
	cout<<n<<' '<<l<<endl;
}
