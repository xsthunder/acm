

#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rev(i,a,b) for(int i=(a);i>=(b);i--)
#define clr(a,x) memset(a,x,sizeof a)
#define inf 0x3f3f3f3f
typedef long long LL;
using namespace std;

const int mod=1e9 +7;
const int maxn=2005;
const int maxm=4005;
int a[maxn],tmp[maxn];
int ans;

void Merge(int l,int m,int r)
{
    int i=l;
    int j=m+1;
    int k=l;
    while(i<=m&&j<=r)
    {
        if(a[i]>a[j])
        {
            tmp[k++]=a[j++];
            ans+=m-i+1;
        }
        else
        {
            tmp[k++]=a[i++];
        }
    }
    while(i<=m)tmp[k++]=a[i++];
    while(j<=r)tmp[k++]=a[j++];
    for(int i=l;i<=r;i++)
        a[i]=tmp[i];
}

void Merge_sort(int l,int r)
{
    if(l<r)
    {
        int m=(l+r)>>1;
        Merge_sort(l,m);
        Merge_sort(m+1,r);
        Merge(l,m,r);
    }
}

int main()
{
    int t,n,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        ans=0;
        Merge_sort(0,n-1);
        printf("Scenario #%d:\n%d\n\n",cas++,ans);
    }
    return 0;
}