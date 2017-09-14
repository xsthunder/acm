from random import *
from string import *
r = randint
char = ascii_letters[:26]
num = digits
t = 3
M = 20
A = 10

def ask():
    n = r(6,M)
    print(''.join([choice(num) for i in range(n)]))
    m = r(0,n)
    a = []
    cnt = 0
    while(True):
        b=r(0,10)
        cnt+=b+1
        if(cnt>n):
            break
        a.append(char[b])
    print(''.join(a))
for i in range(0,t):
    ask()

