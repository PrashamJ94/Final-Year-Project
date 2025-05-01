import sys

def main():
    sec, per_num, max_sec = map(int, sys.stdin.readline().split())
    max_sec += 0.5
    ans_num = 0
    i = sec
    while i < max_sec:
        ans_num += per_num
        i += sec
    print(ans_num)

if __name__ == "__main__":
    main()


