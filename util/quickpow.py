from math import *
def qp(x,p,mod=0):#quickpow
    if(type(x) != type(2) or type(p)!=type(2) or type(mod)!=type(2)):
        print("qp :err type%s %s %s"%(type(x),type(p),type(mod)))
        return 
    b = 1
    while(p>0):
        if(p&1==1):
            b*=x
        p>>=1
        x*=x
        if(mod>0):
            b%=mod
            x%=mod
    return b
def isp(p):#is prime
    if p <=1:
        return False
    if p == 2:
        return True
    for i in range(2,int(sqrt(p))+1):
        if(p%i):
            return True
    return False
def getpfac(x):#get primtive factor
    if(type(x)!=type(2)):
            print("getpfac:err %d",type(x))
    if(x<0):
        x= -x
    mp = {}
    for i in range(2,int(sqrt(x))):
        if x%i == 0:
            mp[i]=1
            x/=i
            while(x%i==0 and x>0):
                x/=i
                x = int(x)
                i = int(i)
                mp[i]+=1
    if(x>1):
        mp[x]=1
    return mp

def getp(x):
    if(type(x)!=type(2)):
            print("getp:err %d",type(x))
            return []
    if(x<=1):
        return []
    if(x>=1e7):
        getp("getp:%d too large"%x)
        return []
    mp = {}
    l = []
    for i in range(2,x+1):
        if i in mp:
            continue
        tmp = i
        l.append(tmp)
        while(tmp<=x):
            mp[tmp] = 1
            tmp+=i
    return l

def ispr(g,p):#if primitive root
    if(type(g) is not type(2) or type(p) is not type(2)):
        print("isPR:err type%s %s"%(type(x),type(p)))
        return 
    if(not isp(p)):
        print("p:%d is not prime"%p)
        return False
    cnt1 = 0
    l = list(getpfac(p-1).keys())
    for i in l:
        if(qp(g,i,p)==1):
            return False
    return True
#print(ispr(3,998244353))
#print(getpfac(998244353-1))
print((getp(int(31622))))
