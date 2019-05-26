N = int(input())
SP = [(j+1,x[0],int(x[1])) for j,x in enumerate([input().split() for i in range(N)])]
SP.sort(key=lambda x: x[2], reverse=True)
SP.sort(key=lambda x: x[1])
for x in SP:
    print(x[0])
