f = open('poj3723.in','w')
i = 0
os = 10000
re = 50000
f.write('1\n')
s = str(os)+' '+str(os)+' '+str(os)+'\n'
f.write(s)
for i in range(0,os):
    s = str(i) + ' ' + str(i) +" 100" + '\n'
    f.write(s)

f.close();
