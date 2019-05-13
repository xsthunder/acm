    read = input
    a,b,t = map(int, read().split())
    ac = 0
    for i in range(a, t+1, a):
        ac += b
    print(ac)
