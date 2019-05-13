from functools import reduce
read = input
n = int(read())
A = list(map(int, read().split()))
if any(map(lambda x:x==0, A)):
    A = map(abs, A)
    print(sum(A))
else:
    cnt = reduce(lambda ac,x:ac + 1 if x < 0 else ac, A, 0)
    if cnt % 2 == 0:
        A = list(map(abs, A))
        print(sum(A))
    else :
        A = list(map(abs, A))
        print(sum(A) - 2*min(A))
