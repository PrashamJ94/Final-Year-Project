
def B():
    x = int(input())
    i = 0
    sum = 100
    while sum < x:
        i += 1
        sum += sum // 100
    print(i)

if __name__ == "__main__":
    B()


