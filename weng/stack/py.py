import random
file = open("poj2823.in","w")
def w(x):
    if(type(x)!=type('1')):
        x=str(x)
    file.write(x)
n = 1000000
k = 100000
w(n)
w(' ')
w(k)
w('\n')
for i in range(0,n):
    w(i)
    w(' ')
    #print(i)
w('\n')
    
