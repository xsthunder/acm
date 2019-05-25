# 并查集
read = input
n, m = map(int, read().split())
f = [-1 for i in range(n + 1)] # 1 ~ n
def find(x):
    if f[x]<0:
        return x
    else :
        f[x] = find(f[x])
        return f[x]
for i in range(m):
    x,y,z = map(int, read().split())
    if abs(x) < abs(y): #合并到x上，保证x是大集合
        x,y = y,x
    fx = find(x)
    fy = find(y)
    if fx == fy:continue # 已经在一个集合，不操作
    f[fx] = f[fx] - 1
    f[fy] = fx
#     print(x,y,fx,fy,f)

ans = 0
for i in range(1, n+1): # 1~n
    if f[i] < 0:
        ans += 1
print(ans)
