
def sosuubunnpu():
    prime_or_not = [0] * 1001
    prime_list = [0] * 1001
    prime_counter = 0

    for i in range(1, 1001):
        prime_or_not[i] = 0

    for i in range(2, 1001):
        for j in range(2, 1000 // i + 1):
            if prime_or_not[i] == 0:
                prime_or_not[i * j] = 1

    for i in range(2, 1001):
        if prime_or_not[i] == 0:
            prime_list[prime_counter] = i
            prime_counter += 1

    return prime_list, prime_counter

def innsuubunnkai(N, n):
    time = 0
    while True:
        if N % n == 0:
            N = N // n
            time += 1
        else:
            break

    return time, N

def main():
    prime_list, prime_counter = sosuubunnpu()
    N = int(input())
    prime_num = [0] * 1001
    result = 1

    for current_num in range(2, N + 1):
        N_temp = current_num
        for i in range(prime_counter):
            time, N_temp = innsuubunnkai(N_temp, prime_list[i])
            prime_num[i] += time

    for i in range(prime_counter):
        result = (result * (prime_num[i] + 1)) % 1000000007

    print(result)

if __name__ == '__main__':
    main()


