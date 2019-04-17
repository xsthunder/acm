read = input
n = int(read())
A = list(map(int, read().split()))
cnt = 0
for p in enumerate(A):
    i, x = p
    if i == 0:
        cnt = cnt + 1
    elif x >= max(A[0:i]):
        cnt = cnt + 1
print(cnt)
