from functools import reduce
read = input
n = int(read())
A = list(map(int, read().split()))
def gcd(a, b):
#     print(a,b)
    if a > b:
        a,b = b,a
    return a if b %a ==0 else gcd(b%a, a)
def cal(ac, x):
    if len(ac) == 0:
        ac.append(x)
        return ac
    nxt = gcd(ac[-1], x)
    ac.append(nxt)
    return ac
A1 = list(reduce(cal, A, []))
A.reverse()
A2 = list(reduce(cal, A, []))
A2.reverse()
mx = 1
for i in range(n):
    if i == 0:
        mx =max(A2[ 1 ], mx)
        continue
    elif i == n-1:
        mx = max(A1[ -2 ], mx)
        continue
    else: # i < n-1 && i > 0
        nxt = gcd(A1[i-1], A2[i+1])
        mx = max(nxt, mx)
print(mx)
# A.reverse()
# A1, A2, n, A
