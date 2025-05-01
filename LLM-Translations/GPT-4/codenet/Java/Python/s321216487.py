import sys

def main():
    S = input().strip()

    for i in range(len(S) + 1):
        for j in range(len(S) + 1):
            begin = S[:i]
            end = S[j:]
            answer = begin + end

            if answer == "keyence" or begin == "keyence" or end == "keyence":
                print("YES")
                return

    print("NO")


if __name__ == "__main__":
    main()


