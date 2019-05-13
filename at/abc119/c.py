read = input
# read = Read(False, """


# 8 1000 800 100
# 300
# 333
# 400
# 444
# 500
# 555
# 600
# 666

# """).read
tmp = read()
tmp = list(map(int, tmp.split(' ')))
N,A,B,C = tmp
opt = list(map(int, map(lambda x: read(), range(N))))
def dfs(n,a,b,c):
    ret = 10**7
    if(n == N):
        if(min(a,b,c) == 0):
            return ret
        return abs(A - a) + abs(B - b) + abs(C - c) - 30
    cur = opt[n]
    ret = min(ret, dfs(n+1, a + cur, b, c) + 10)
    ret = min(ret, dfs(n+1, a, b + cur, c) + 10)
    ret = min(ret, dfs(n+1, a, b ,c + cur) + 10)
    ret = min(ret, dfs(n+1, a, b ,c ) + 0)
    return ret
print(dfs(0, 0, 0, 0))
