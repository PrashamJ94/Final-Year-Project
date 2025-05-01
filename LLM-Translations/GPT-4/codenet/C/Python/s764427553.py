def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def count_primes(n):
    count = 0
    for i in range(n, 0, -1):
        if is_prime(i):
            count += 1
    return count

def main():
    test_cases = 30
    while test_cases > 0:
        try:
            n = int(input())
            print(count_primes(n))
            test_cases -= 1
        except EOFError:
            break

if __name__ == "__main__":
    main()


