read = input
s = read()
a = []
pc = '0' if s[0] == '1' else '1'
pcnt = 0
for c in s:
    if pc == c:
        a.append(pcnt)
        pcnt = 1
    else :
        pcnt = pcnt + 1
    pc = c
a.append(pcnt)
# print(a, s)
odd = sum(map(lambda tp:tp[1], filter(lambda tp:tp[0] % 2 != 0, enumerate(a))))
even = sum(map(lambda tp:tp[1], filter(lambda tp:tp[0] % 2 == 0, enumerate(a))))
print(min(odd, even))
