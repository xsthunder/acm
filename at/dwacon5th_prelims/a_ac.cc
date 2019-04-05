#include<cstdio>
#include<cmath>

const int N = 200;
int A[N];
int main(){
    int n;scanf("%d", &n);
    for(int i=0 ;i<n;i++){
        scanf("%d", &A[i]);
    }
    int sum = 0;
    for(int i =0;i<n;i++ ){
        sum += A[i];
    }
    int ans = 0;
    int lost = abs(A[0]*n - sum);
    for(int i =0;i<n;i++){
        int tmp = abs(A[i]*n - sum);
        if( tmp < lost ){
            lost = tmp;
            ans = i;
        }
    }
    printf("%d", ans);
    return 0;
}
