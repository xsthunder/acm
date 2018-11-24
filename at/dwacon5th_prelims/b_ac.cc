    #include<cstdio>
    #include<cmath>
    #include<algorithm>
    #include<vector>
    using namespace std;
    typedef long long ll;
    const int N = 1e6+ 5;
    ll S[N] , A[N];
    vector<ll> B[70];
    ll cal(vector<ll> &, int,int, ll);
    ll lsb(int b){
        return 1LL<<b;
    }
    int main(){
        int ncount;
        int n,k;scanf("%d%d", &n, &k);
        for(int i =0, x ;i<n;i++){
            scanf("%d", &x);
            if(i == 0){
                S[i]=x;
            }
            else {
                S[i] = S[i-1] + x;
            }
        }
        ncount = 0;
        for(int i =0;i<n;i++){
            for(int j =i;j<n;j++){
                A[ncount++] = S[j] - (i>0?S[i-1]:0);
                ////printf("%d %lld\n", ncount-1, A[ncount-1]);
            }
        }
        sort(A, A + ncount);
        reverse(A, A +ncount);
        for(int b = 0;b<63;b++){
            for(int i = 0;i<ncount; i++){
                if(lsb(b) & A[i]){
                    //printf("b %d A[%d]:%lld\n", b, i, A[i]);
                    B[b].push_back(A[i]);
                }
            }
        }
        ll ans = 0;
        for(int b = 63;b >=0;b--){
            if((int)B[b].size()>=k){
        //        printf("main b %d\n", b);
                ans = cal(B[b], k, b, lsb(b));
                break;
            }
        }
        printf("%lld", ans);
        return 0;
    }
    ll cal(vector<ll> &A, int k,int bz,ll ans){
        //for(auto x:A)printf("%lld\n", x);
        //printf("size: %lu, bz: %d, ans:%lld \n",A.size(), bz, ans);
        if(bz == 0){return ans;}
        vector<ll> B[70];
        int ncount = (int)A.size();
        for(int b = 0;b<bz;b++){
            for(int i = 0;i<ncount; i++){
                if(lsb(b) & A[i]){
                    B[b].push_back(A[i]);
                }
            }
        }
        for(int b = bz-1;b >=0;b--){
            if((int)B[b].size()>=k){
                return cal(B[b], k, b, ans | lsb(b));
            }
        }
        return ans;
    }
