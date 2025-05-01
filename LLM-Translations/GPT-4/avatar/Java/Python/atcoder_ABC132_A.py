
from collections import Counter

def main():
    s = input().strip()
    char_count = Counter(s)

    ok = True
    for count in char_count.values():
        if count != 2:
            ok = False
            break

    if ok and len(char_count) == 2:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()


