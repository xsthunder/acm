s = input()
y, m, d = map(int, s.split('/'))
f = False
(
    Heisei,
    TBD,
)= (
    'Heisei',
    'TBD',
)
if y < 2019:
    print(Heisei)
elif y == 2019:
    if(m < 4):
        print(Heisei)
    elif m == 4:
        if(d <= 30):
            print(Heisei)
        else :
            print(TBD)
    else :
        print(TBD)
else :
    print(TBD)
