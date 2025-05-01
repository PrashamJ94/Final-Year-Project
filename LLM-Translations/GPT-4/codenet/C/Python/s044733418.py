
def compare(a, b):
    return b - a

def main():
    array = [int(input()) for _ in range(10)]
    array.sort(key=lambda x: -x)
    for i in range(3):
        print(array[i])

if __name__ == "__main__":
    main()


