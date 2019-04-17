read = input
n,k = map(int, read().split())
a = read()
a = '1' + a + '1'
# -1 if use 0, -1 if use len(a) -1
pstart = 0
pcnt = 0
ptype = '1'
b = []
# (start, end, cnt)
for tp in enumerate(a):
    i, c = tp
    if ptype == c:
        pcnt = pcnt + 1
    else :
        b.append((pstart, i-1, pcnt))
        pstart = i
        ptype = c
        pcnt = 1
b.append((pstart, i, pcnt))
# print(b)
if k >= len(b)//2:
    print(sum(map(lambda tp:tp[2], b)) - 2)
else :
    start = 0
    end = k * 2
    ans = 0
    S = [0 for i in range(len(b)+10)]
    S[0] = b[0][2]
    for i in range(1, len(b)):
        S[i] = S[i-1] + b[i][2]
    while(end <= len(b) - 1):
        tmp = S[end] - (S[start - 1] if start - 1>=0 else 0)
        if b[start][0] == 0:
            tmp = tmp - 1
        if b[end][1] == len(a)-1:
            tmp = tmp -1
#         print(start, end ,tmp)
        ans = max(ans, tmp)
        start = start + 2
        end = end + 2
    print(ans)
