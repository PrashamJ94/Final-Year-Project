Here is the translation of your Java code to Python:


import sys

def main():
    n = int(input().strip())
    input_str = input().strip()
    max_len = -1
    msg_len = [0] * (len(input_str) // 2)
    count = 0
    idx = 0
    for i in range(len(input_str)):
        c = input_str[i]
        if c in ['.', '?', '!']:
            msg_len[idx] = count + 1
            idx += 1
            if count > max_len:
                max_len = count
            count = 0
            i += 1
        else:
            count += 1
    if max_len > n:
        print("Impossible")
    else:
        ans = 0
        i = 0
        while i < idx:
            l = msg_len[i]
            while i < idx - 1 and l + msg_len[i + 1] + 1 <= n:
                l += msg_len[i + 1] + 1
                i += 1
            ans += 1
            i += 1
        print(ans)

if __name__ == "__main__":
    main()


