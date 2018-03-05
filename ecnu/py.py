from string import *
p = 0;
P = 26;
for i in range(0,100000):
    print(ascii_letters[p],end='')
    p = ( p + 1 ) %P

