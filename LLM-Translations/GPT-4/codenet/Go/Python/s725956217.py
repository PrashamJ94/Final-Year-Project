import bisect

def min(a, b):
    return a if a < b else b

class Shop:
    def __init__(self, a, b):
        self.a = a
        self.b = b

def main():
    N, M = map(int, input().split())
    shops = [Shop(*map(int, input().split())) for _ in range(N)]
    shops.sort(key=lambda shop: shop.a)

    total = 0
    for shop in shops:
        n = min(shop.b, M)
        total += n * shop.a
        M -= n
        if M == 0:
            break

    print(total)

if __name__ == '__main__':
    main()


