N, Q = map(int, input().split())
s = input()
state = [[0] for i in range(N)]
for i in range(Q):
    t, d = input().split()
    for j in range(N):
        if s[j] == t:
            if d == 'L':
                if j == 0:
                    state[0] = []
                else:
                    state[j-1].extend(state[j])
                    state[j] = []
            else:
                if j == N-1:
                    state[N-1] = []
                else:
                    state[j+1].extend(state[j])
                    state[j] = []
print(sum([len(i) for i in state]))
