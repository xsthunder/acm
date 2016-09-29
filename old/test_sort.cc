#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<cassert>

using namespace std;

void fill_random_int(vector<int>&v,int  cnt)
{
	
	v.clear();
	for(int i=0;i<cnt;i++)
	{
		v.push_back(rand());
	}
}
void test_sort(vector<int>&v)
{
	sort(v.begin(), v.end());

	v[2]=v[200];
	for(int i=0;i<v.size()-1;i++)
	{
		assert(v[i]<=v[i+1]);
		cout<<i<<" "<<v[i]<<endl;
	}
}
int main()
{
	srand(time(0));
//	freopen("in", "r", stdin);
	//insert code
	vector<int>v;
	fill_random_int(v,10000);
	test_sort(v);
	
	//insert code
	return 0;
}
