n = int(input())
ret = 0
for i in range(n):
    x, u = input().split(' ')
    x = float(x)
    if(u == 'BTC'):
        x = 380000 * x
    ret = x + ret
print(ret)
