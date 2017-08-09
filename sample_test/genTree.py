import random
r = random.randint
t = 3
M = 10
N = 10
A = 10
D = 10

def p(x):
    if(type(x)==type(1)):
        x = str(x)
    print (x,sep='',end='')
def sam():
    version = 0;
    n = r(1,N)
    p(n)
    p('\n')
    for i in range(2,n+1):
        p(r(1,i-1))
        p(' ')
        p(i)
        p('\n')
    p('\n')
for i in range(0,3):
    sam()
    p('\n')
