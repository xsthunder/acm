
file  =open ("poj1182.in.max", "w")
def w(x):
    if(type(x)!=type('1')):
        x = str(x)
    file.write(x)
n = 50000
w(n)
w(' ')
k = 49999
w(k)
w('\n')
for i in range(1,n):
    w(2)
    w(' ')
    w(i)
    w(' ')
    w(i+1)
    w('\n')
file.close()


