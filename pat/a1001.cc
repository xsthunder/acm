const bool test=1;
#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
const int inf=0x7fffffff;
#define IF if(test)
#define FI if(!test)
#define gts(s) fgets((s),sizeof(s),stdin)
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
void sol(){
  int a,b;
  scanf("%d%d",&a,&b);
  //cout<<a+b;
  vector <char > vi;
  if(a+b<0)cout<<'-';
  int num=abs(a+b);
  //cout<<num<<endl;
  int cnt=0;
  if(num==0)vi.push_back('0');
  while(num!=0){
    int x=num%10;
    num/=10;
    vi.push_back(x+'0');
    cnt++;
    if(cnt==3){
      if(num==0)break;
      vi.push_back(',');
      cnt=0;
    }
  }
  for(auto  it=vi.rbegin();it!=vi.rend();it++)
  {
    cout<<*it;
  }
  cout<<endl;
}
int main()
{
  sol();
  return 0;
}
//a1001.cc
//generated automatically at Sun Nov  6 12:27:52 2016
//by xsthunder
