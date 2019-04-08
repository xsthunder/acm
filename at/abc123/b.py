read = input
a = [read() for i in range(5)]
a = list(map(int, a))
if all(map(lambda x: x%10 == 0, a)):
    print(sum(a))
else :
    g10 = list(filter(lambda x:x%10 > 0 , a))
    l10 = list(filter(lambda x:x%10 == 0 , a))
    m = min(g10, key=lambda x:x%10)
    g100= list(map(lambda x:x//10*10 + 10, g10))
    print(sum(g100)  +sum(l10)- m//10*10 - 10 + m) # cann't use [*arr] in 3.4


