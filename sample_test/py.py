from random import *
from string import *
r = randint
T = 5
S = 20
def ask():
    s = r(1,S);
    N = s;
    n = r(1,s);
    m = s - n;
    print(s,n,m);
    
for i in range(T):
    ask();
print(0,0,0);
