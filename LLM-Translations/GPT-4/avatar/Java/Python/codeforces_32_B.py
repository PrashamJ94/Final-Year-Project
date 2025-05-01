import sys

def main():
    n = list(input().strip())
    s = False
    result = []
    for i in range(len(n)):
        if n[i] == '.':
            if s:
                result.append(1)
                s = False
            else:
                result.append(0)
        else:
            if s:
                result.append(2)
                s = False
            else:
                s = True
    print("".join(str(x) for x in result))

if __name__ == "__main__":
    main()

