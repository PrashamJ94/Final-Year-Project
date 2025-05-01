import sys

def main():
    n = int(input().strip())
    s = ".,!? :abc:def:ghi:jkl:mno:pqrs:tuv:wxyz".split(":")
    k = [list(x) for x in s]
    
    for _ in range(n):
        c = input().strip()
        l, a = -1, 0
        result = []
        
        for ch in c:
            if ch != '0':
                a = int(ch) - 1
                l = (l + 1) % len(k[a])
            else:
                if l >= 0:
                    result.append(k[a][l])
                    l = -1
        
        print(''.join(result))

if __name__ == "__main__":
    main()


