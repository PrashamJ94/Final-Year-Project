import sys

def main():
    N = int(input().strip())
    s = [input().strip() for _ in range(N)]
    a_num = 0
    b_num = 0
    flag = True
    ans = 0
    for string in s:
        if string[0] == "B":
            b_num += 1
        if string[-1] == "A":
            a_num += 1
        if string[0] == "B" or string[-1] == "A":
            if not (string[0] == "B" and string[-1] == "A"):
                flag = False
        ans += string.count("AB")
    ans += min(a_num, b_num)
    if min(a_num, b_num) != 0 and flag:
        ans -= 1
    print(ans)

if __name__ == "__main__":
    main()


