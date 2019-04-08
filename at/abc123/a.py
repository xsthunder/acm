read = input
a = [read() for i in range(5)]
a = list(map(int, a))
k = int(read())
if a[4] - a[0] > k:
    print(':(')
else :
    print('Yay!')
