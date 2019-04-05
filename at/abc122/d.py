n = int(input())
P = 10**9 + 7
memo = [{} for i in range(n + 1)]
def ok(last4):
    if last4.count('AGC') >= 1:return False
    for i in range(3):
        t = list(last4)
        t[i], t[i+1] = t[i+1] , t[i]
        if ''.join(t).count('AGC') >= 1:
            return False
    return True

def dfs(cur, last3):
    if cur == n:
        return 1
    if last3 in memo[cur]:
        return memo[cur][last3]
    ret = 0
    for c in 'AGCT':
        if(ok(last3+c)):
            ret = (ret + dfs(cur + 1, last3[1:]+c))%P
    memo[cur][last3] = ret
    return ret
print(dfs(0, 'TTT'))
