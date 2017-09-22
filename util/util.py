from math import *
def quickPow(x,p,mod=0):#quickpow
    if(type(x) != type(2) or type(p)!=type(2) or type(mod)!=type(2)):
        print("qp :err type%s %s %s"%(type(x),type(p),type(mod)))
        return -1 
    b = 1
    while(p>0):
        if(p&1==1):
            b*=x
        p>>=1
        x*=x
        if(mod>0):
            b%=mod
            x%=mod
        x=int(x)
        p=int(p)
    #print(b)
    return int(b)
def isPrime(p):#is prime
    if(type(p)!=type(2)):
            print("getpfac:err %d",type(p))
    if p <=1:
        return False
    if p == 2:
        return True
    for i in range(2,int(sqrt(p))+1):
        if(p%i):
            return True
    return False
def getPrimitiveFactor(x):#get primtive factor
    if(type(x)!=type(2)):
            print("getpfac:err %d",type(x))
    if(x<0):
        x= -x
    mp = {}
    for i in range(2,int(sqrt(x))+1):
        if x%i == 0:
            mp[i]=1
            x//=i
            while(x%i==0 and x>0):
                x//=i
                x = int(x)
                i = int(i)
                mp[int(i)]+=1
    if(x>1):
        mp[int(x)]=1
    return mp

def getPrime(x):
    if(type(x)!=type(2)):
            print("getp:err %d",type(x))
            return []
    if(x<=1):
        return []
    if(x>=1e7):
        print("getp:%d too large"%x)
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

def isPrimitiveRoot(g,p):#if primitive root
    if(type(g) is not type(2) or type(p) is not type(2)):
        print("isPR:err type%s %s"%(type(x),type(p)))
        return 
    if(not isPrime(p)):
        print("p:%d is not prime"%p)
        return False
    cnt1 = 0
    l = list(getPrimitiveFactor(p-1).keys())
    for i in l:
        if(quickPow(g,i,p)==1):
            return False
    return True
def getPrimitiveRoot(p):#pass nod51 test
    p=int(p)
    if(not isPrime(p)):
        print("p is not prime!")
        return None
    l = list(getPrimitiveFactor(p-1))
    #print(l)
    for g in range(2,p-1+1):
        flag = True
        for i in l:
            if(int(quickPow(g,int((p-1)/i),p))==1):
                flag=False
                break
        if(flag):
            return g
    return None
def kantor(a):
    if(type(a)!=type([])):
        print("kantor:err exp list got %s"%type(a))
        return None
    n=len(a)
    if(n==0):
        print("kantor:err list len =0")
        return None
    for e in a:
        if(type(e)!=type(2)):
            print("kantor:err exp ele type int got %s"%type(e))
            return None
    b = sorted(a)
    for i in range(0,n-1):
        if(b[i]==b[i+1]):
            print("kantor:err replicate element %d"%b[i])
            return None
    fac=[1]
    ans=0
    for i in range(1,n):
        fac.append(fac[i-1]*i)
    print(fac)
    for i in range(0,n):
        e=a[i]
        cnt=0
        for j in range(i+1,n):
            if a[j]<e:
                cnt+=1
        ans+=cnt*fac[n-i-1]
    return ans
def Ikantor(num,n):
    num = int(num)
    n=int(n)
    if(n==0):
        print("Ikantor err : n==0")
        return None
    fac=[1]
    for i in range(1,n+1):
        fac.append(fac[i-1]*i)
    if(num<0 or num>=fac[n]):
        print("Ikantor err :wrong range for num:%d in [0,%d]"(num,fac[n]-1))
    ans=[]
    wait=[]
    for i in range(1,n+1):
        wait.append(i)
    for i in range(0,n):
        c = n-i-1
        a = int(num/fac[c])
        r = num%fac[c]
        num=r
        ans.append(wait[a])
        wait.pop(a)
    return ans

#a = []
#b = ['3']
#c=[1,2]
#d=[2,1]
#e=[4,4]
#kantor(a)
#kantor(b)
#print(c,kantor(c))
#print(d,kantor(d))
#print(e,kantor(e))
#a=[1,3,4,2]
#print(a,kantor(a))
#num=3
#print(num,Ikantor(num,4))
