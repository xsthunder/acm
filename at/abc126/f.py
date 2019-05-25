# 数论
read = input
rn = lambda :map(int, read().split())
m,k = rn()
import math
N = 2**(m) - 1 # 0~N
r = [i for i in range(N+1)] # 0~N
if k > N:
    print(-1)
# elif N == 1 and k == 0:
#     print(0, 0)
elif N == 1 and k == 1:
    print('-1')
elif k ==  0:
    for i in r:
        print(i, end=' ')
    r.reverse()
    for i in r:
        print(i, end=' ')
elif N == 2 and k == 1:
    print(-1)
else:
    for i in r:
        if i == k:continue
        print(i, end=' ')
    print(k, end=' ')
    r.reverse()
    for i in r:
        if i == k:continue
        print(i, end=' ')
    print(k, end=' ')
    
