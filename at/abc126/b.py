read = input
s = read()
a, b = map(int , [s[:2], s[2:]])
YYMM = False
MMYY = False
if 1 <= b and b <= 12:
    YYMM = True
if 1 <= a and a <= 12:
    MMYY = True
if YYMM and MMYY :
    print('AMBIGUOUS')
elif YYMM and not MMYY:
    print('YYMM')
elif not YYMM and MMYY:
    print('MMYY')
else :
    print('NA')
