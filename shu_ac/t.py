import os
for i in range(1,1000000000):
    f=open('in','r')
    f.write(i)
    f.close()
    os.system('./I.exe < in')
