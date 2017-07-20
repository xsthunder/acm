import random
r = random.randint
M = 10
N = 10
def p(x):
    if(type(x)==type(1)):
        x = str(x)
    print (x,sep='',end='')
def sam():
    n = r(1,N)
    m = r(1,M)
    p(n)
    p('\n')
    for i in range(2,n+1):
        p(i)
        p(' ')
        p(r(1,i-1))
        p('\n')
    p(m)
    p('\n')
    for i in range(0,m):
       opt = r(0,1)
       if(opt==0):
           p('Q')
           p(' ')
           i = r(1,n)
           p(i)
       else:
           p('C')
           p(' ')
           i = r(1,n)
           p(i)
       p('\n')
sam()
