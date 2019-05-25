import math
log2 = math.log2
ceil = math.ceil # 向下取整
read = input
n,k = map(int, read().split())
ans = 0.0
for i in range(1, n+1):
    if i >= k:
        ans += 1
    else :
        ans += 0.5 ** ceil(log2(k/i))
ans /= n
print('%.12f'%ans)
