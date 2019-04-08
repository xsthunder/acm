read = input
n = int(read())
a = [read() for i in range(5)]
a = list(map(int, a))
a = min(a)
if n % a == 0:
    n = n // a
else :
    n = n // a + 1
print( n + 5 - 1 )
