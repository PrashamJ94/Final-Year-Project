def main():
    n = int(input())

    as_ = input().split()
    as_ = [int(a) for a in as_]

    bs = input().split()
    bs = [int(b) for b in bs]

    sum_ = 0
    for i in range(n):
        a = as_[i]
        b = bs[i]
        if a <= b:
            sum_ += a
            b -= a
            if i + 1 <= n:
                an = as_[i + 1]
                if an <= b:
                    sum_ += an
                    as_[i + 1] = 0
                else:
                    sum_ += b
                    as_[i + 1] -= b
        else:
            sum_ += b
    print(sum_)

if __name__ == '__main__':
    main()


