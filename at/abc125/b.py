read = input
n = int(read())
V = map(int, read().split())
C = map(int, read().split())
A = list(zip(V,C))
mx = 0
for (v,c) in A:
    if v > c:
        mx += v - c
print(mx)
