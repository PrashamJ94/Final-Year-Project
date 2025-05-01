import sys

def read():
    data = sys.stdin.readline().strip()
    if not data:
        return False, 0
    d = int(data)
    return True, d

def solve(d):
    ans = 0
    i = 1
    while i * d < 600:
        x = i * d
        y = x * x
        ans += y * d
        i += 1
    return ans

def main():
    while True:
        has_data, d = read()
        if not has_data:
            break
        print(solve(d))

main()


