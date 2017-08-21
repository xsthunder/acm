#include<cstdio>
#include<stack>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int cur,wid;
        typedef long long ll;
        ll ma=-1;
        for(int i = 0;i<heights.size();i++){
            if(s.empty()||heights[s.top()]<heights[i])s.push(i);
            else {
                while(!s.empty()&&heights[s.top()]>heights[i]){
                    cur=s.top(),s.pop();
                    wid=s.empty()?i:(i-s.top()-1);
                    printf("in %d,cur%d %d\n",i,cur,ll(heights[cur])*wid);
                    ma=max(ma,ll(heights[cur])*wid);
                }
                s.push(heights[i]);
            }
        }
        return ma;
    }
};

int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
void inp(){
	Solution s;
	vector<int > v{2,1,5,6,2,3};
	s.largestRectangleArea(v);
}
//leetcode84.cc by xsthunder at Mon Aug 21 21:39:29 2017

