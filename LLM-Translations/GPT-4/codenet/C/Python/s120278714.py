
class Node:
    def __init__(self, l=-1, r=-1, par=-1):
        self.l = l
        self.r = r
        self.par = par

def init(n):
    return [Node() for _ in range(n)]

def pre_order(n, p):
    if p != -1:
        print(f" {p}", end="")
        pre_order(n, n[p].l)
        pre_order(n, n[p].r)

def in_order(n, p):
    if p != -1:
        in_order(n, n[p].l)
        print(f" {p}", end="")
        in_order(n, n[p].r)

def post_order(n, p):
    if p != -1:
        post_order(n, n[p].l)
        post_order(n, n[p].r)
        print(f" {p}", end="")

def main():
    n = int(input())
    nodes = init(n)

    for _ in range(n):
        id, l, r = map(int, input().split())

        if l != -1:
            nodes[id].l = l
            nodes[l].par = id
        if r != -1:
            nodes[id].r = r
            nodes[r].par = id

    for i in range(n):
        if nodes[i].par == -1:
            p = i
            break

    print("Preorder")
    pre_order(nodes, p)
    print()

    print("Inorder")
    in_order(nodes, p)
    print()

    print("Postorder")
    post_order(nodes, p)
    print()

if __name__ == "__main__":
    main()


