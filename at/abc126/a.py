read = input
n, k = map(int, read().split())
s = read()
k -= 1
s= s[:k] + str.lower(s[k]) + s[k+1:]
print(s)
