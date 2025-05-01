
from sys import stdin

def main():
    t, m = map(int, input().split())
    memory = [0] * m
    alloc_idx = 0

    for _ in range(t):
        cmd = input().split()

        if cmd[0] == "alloc":
            n = int(cmd[1])
            len = 0
            can_alloc = False

            for i in range(m):
                if memory[i] == 0:
                    len += 1
                else:
                    len = 0

                if len == n:
                    can_alloc = True
                    len = i - n + 1
                    break

            if can_alloc:
                alloc_idx += 1
                for i in range(len, len + n):
                    memory[i] = alloc_idx
                print(alloc_idx)
            else:
                print("NULL")

        elif cmd[0] == "erase":
            x = int(cmd[1])
            if x <= 0:
                print("ILLEGAL_ERASE_ARGUMENT")
            else:
                has_erased = False
                for i in range(m):
                    if memory[i] == x:
                        memory[i] = 0
                        has_erased = True

                if not has_erased:
                    print("ILLEGAL_ERASE_ARGUMENT")

        elif cmd[0] == "defragment":
            d = 0
            for i in range(m):
                if memory[i] == 0:
                    d += 1
                else:
                    memory[i - d] = memory[i]

            for i in range(m - d, m):
                memory[i] = 0

        else:
            print("h")

if __name__ == "__main__":
    main()

##End of Code
