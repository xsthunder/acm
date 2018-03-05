#include<cstdio>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
typedef pair<int ,int > P;
typedef double db;
void inp();
int main(){
	freopen("tmp.in","r",stdin);
    while(1)inp();
    return 0;
}
const int N = 200;
int vis[N][N][N];
struct Node{
    int d[3];
    Node(int a,int b,int c){
        d[0] = a,d[1]=b,d[2]=c;
    }
    int operator[](int i){
        return d[i];
    }
};
void inp(){
    int s,n,m;scanf("%d%d%d",&s,&n,&m);if(!s&&!n&&!m)exit(0);
    int full[3];
    full[0]=s,full[1]=n,full[2]=m;
    if(n == m){ printf("1\n"); return; }
    if(s&1){ printf("NO\n"); return; }
    memset(vis,-1,sizeof(vis));
    vis[s][0][0] = 0;
    queue<Node> q;
    q.push(Node(s,0,0));
    while(!q.empty()){
        Node node = q.front();q.pop();
        for(int c = 0;c<3;c++){
            if(!node[c])continue;//chu wei kong
            for(int r = 0;r<3;r++){
                Node now(0,0,0);
                if(c == r)continue;//chu shi ru
                if(node[r] == full[r])continue;//ru yi man
                int ex = -1;
                for(int i = 0;i<3;i++){ if(i == c || i == r)continue;ex=i;}
                now.d[ex]=node[ex];
                int tmp = min(node[c], full[r] - node[r]);
                now.d[r] = node[r] + tmp;
                now.d[c] = node[c] - tmp;
                if(vis[now[0]][now[1]][now[2]]>=0)continue;
                tmp = vis[now[0]][now[1]][now[2]] = vis[node[0]][node[1]][node[2]]+1;
                q.push(now);
                sort(now.d,now.d+3);
                if(now[0] + now[1] == now[2]){
									if(now[0])tmp++;
                    printf("%d\n",tmp);
                    return;
                }
            }
        }
    }
    printf("NO\n");
    return;
}

