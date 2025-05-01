import itertools

def permutation(number):
    return list(itertools.permutations(number))

def main():
    n = int(input())
    lines = []
    for _ in range(2):
        lines.append("".join(input().split()))

    number = "".join(str(i) for i in range(1, n + 1))
    listA = permutation(number)
    sum = 0

    for j in range(len(lines)):
        for i in range(len(listA)):
            if "".join(listA[i]) == lines[j]:
                if sum == 0:
                    sum += i
                else:
                    sum -= i

    print(abs(sum))

if __name__ == "__main__":
    main()


