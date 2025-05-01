
def find_cheapest_ticket(n, data):
    seiki_ryoukin = [0] * n
    waribiki_ryoukin = [0] * n
    saiyasune = [0] * n

    for i in range(n):
        nyuyoku_ticket, pool_ticket, nyuyoku_member, pool_member = data[i]
        
        if nyuyoku_member >= 5 and pool_member >= 2:
            seiki_ryoukin[i] = (((nyuyoku_ticket * nyuyoku_member) + (pool_ticket * pool_member)) * 8) // 10
            saiyasune[i] = seiki_ryoukin[i]
        elif nyuyoku_member >= 5:
            seiki_ryoukin[i] = (nyuyoku_ticket * nyuyoku_member) + (pool_ticket * pool_member)
            waribiki_ryoukin[i] = (((nyuyoku_ticket * nyuyoku_member) + (pool_ticket * 2)) * 8) // 10
            saiyasune[i] = min(seiki_ryoukin[i], waribiki_ryoukin[i])
        elif pool_member >= 2:
            seiki_ryoukin[i] = (nyuyoku_ticket * nyuyoku_member) + (pool_ticket * pool_member)
            waribiki_ryoukin[i] = (((nyuyoku_ticket * 5) + (pool_ticket * pool_member)) * 8) // 10
            saiyasune[i] = min(seiki_ryoukin[i], waribiki_ryoukin[i])
        else:
            seiki_ryoukin[i] = (nyuyoku_ticket * nyuyoku_member) + (pool_ticket * pool_member)
            waribiki_ryoukin[i] = (((nyuyoku_ticket * 5) + (pool_ticket * 2)) * 8) // 10
            saiyasune[i] = min(seiki_ryoukin[i], waribiki_ryoukin[i])

    return saiyasune

if __name__ == '__main__':
    n = int(input())
    data = []
    for _ in range(n):
        data.append(list(map(int, input().split())))

    result = find_cheapest_ticket(n, data)
    for r in result:
        print(r)

#
