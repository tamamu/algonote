import numpy as np
N = int(input())
A = list(map(int, input().split()))
print(" ".join(map(str, np.argsort(A)+1)))
