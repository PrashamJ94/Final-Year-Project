import sys

def main():
    memo = [0] * 26

    for line in sys.stdin:
        str = line.strip()
        if len(str) == 0:
            break
        for c in str:
            if 'a' <= c <= 'z':
                memo[ord(c) - ord('a')] += 1
            elif 'A' <= c <= 'Z':
                memo[ord(c) - ord('A')] += 1
            else:
                continue

    for i in range(26):
        print(f"{chr(i + ord('a'))} : {memo[i]}")

if __name__ == "__main__":
    main()


