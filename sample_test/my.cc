
#include <bits/stdc++.h>
using namespace std;
const int N = 400;
int a[N], b[N], s_a[N], s_b[N];
char str[N];
int len, cnt, ans;
int Max[N];

void dfs(int now, int st, int ret) {
	if(now >= cnt + 1) {
		ans = max(ans, ret);
		return;
	}
	for(int i=st;i + b[now] <= len + 1;i++) {
		int ed = i + b[now];
		
		int left = len - ed + 1;
		if(s_b[cnt] - s_b[now] > left)continue;
		
		int tmp = ret + s_a[ed - 1] - s_a[i - 1];
		if(now >= 2) {
			if(tmp <= Max[now])continue;
			else Max[now] = tmp;
		}
		//if(now == 2)cout<<ed - 1<<" "<<i - 1<<endl;
		//if(now == 1)cout<<tmp<<endl;
		dfs(now + 1, ed, tmp);
	}
}
int main() {
//	freopen("in.txt","r",stdin);
	while(cin.getline(str + 1, 300, '\n')) {
		memset(s_a, 0, sizeof(s_a));
		memset(s_b, 0, sizeof(s_b));
		memset(Max, -1, sizeof(Max));
		ans = 0;
		
		
		len = strlen(str + 1);
		//cout<<str+1<<" "<<len<<endl;
		for(int i=1;i<=len;i++)a[i] = str[i] - '0';
		for(int i=1;i<=len;i++)s_a[i] = s_a[i - 1] + a[i];
		
		cin.getline(str + 1, 300, '\n'); 
		cnt = strlen(str + 1);
		//cout<<str+1<<" "<<cnt<<endl;
		for(int i=1;i<=cnt;i++)b[i] = str[i] - 'a' + 1;
		for(int i=1;i<=cnt;i++)s_b[i] = s_b[i - 1] + b[i];
		//cout<<s_b[cnt]<<endl;
		dfs(1, 1, 0);
		
		cout<<ans<<endl;
	}
	return 0;
}
