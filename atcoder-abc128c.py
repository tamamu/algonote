N, M = map(int, input().split())
s = [list(map(int, l)) for l in [input().split() for j in range(M)]]
p = list(map(int, input().split()))
ans = 0

for j in range(2 ** N):
    pat = [0 for i in range(N)]
    for k in range(N):
        if ((j >> k) & 1):
            pat[k] = 1
    if sum([1 for i in range(M) if sum([1 for l in s[i][1:] if pat[l-1] == 1]) % 2 == p[i] ]) == M:
        ans += 1
print(ans)
