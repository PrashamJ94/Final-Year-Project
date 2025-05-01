import sys

def main():
    N = int(input().strip())
    words = [input().strip() for _ in range(N)]
    ans = True
    past = set()

    for i, word in enumerate(words):
        if word in past:
            ans = False
            break
        past.add(word)

        if i != 0:
            if next_char != word[0]:
                ans = False
                break
        next_char = word[-1]

    if ans:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()


