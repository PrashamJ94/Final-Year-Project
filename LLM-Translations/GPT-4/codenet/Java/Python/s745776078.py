import sys
from sys import stdin, stdout
import numpy as np

def main():
    n, m = map(int, input().split())
    A = []
    for i in range(n):
        A.append(list(map(int, input().split())))

    b = list(map(int, input().split()))
    A = np.array(A)
    b = np.array(b)

    for i in range(n):
        c = np.dot(A[i], b)
        print(c)

main()

