read = input
A,B = map(int , read().split())
if A > B:
    A,B = B,A
if A == B:
    print(A*2)
else :
    print(B*2 - 1)
