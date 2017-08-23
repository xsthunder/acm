import random
r = random.randint
t = 2
M = 100000
N = 20000
A = 1
B = 1000000000


def p(x):
    if(type(x)==type(1)):
        x = str(x)
    print (x,sep='',end='')
def sam():
    version = 0;
    n = r(1,N)
    m = r(1,M)
    n=N
    m=M

    print("%d %d"%(n,m))
    for i in range(0,n):
        p(r(A,B))
        p(' ')
    p('\n')
    for i in range(2,n+1):
        p(r(1,i-1))
        p(' ')
        p(i)
        p('\n')
    for i in range(0,m):
        a=r(1,B)
        print("%d %d %d %d"%(r(1,n),r(1,n),a,r(a,B)))
    p('\n')

for i in range(0,t):
    sam()
    p('\n')
