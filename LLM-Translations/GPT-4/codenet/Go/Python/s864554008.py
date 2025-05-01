
def main():
    d = new_data()
    if d.exist():
        print("Yes")
    else:
        print("No")

def new_data():
    n, m = map(int, input().split())
    n_img = [input() for _ in range(n)]
    m_img = [input() for _ in range(m)]

    return Data(n=n, m=m, n_img=n_img, m_img=m_img)

class Data:
    def __init__(self, n, m, n_img, m_img):
        self.n = n
        self.m = m
        self.n_img = n_img
        self.m_img = m_img

    def exist(self):
        for i in range(self.n - self.m + 1):
            for j in range(self.n - self.m + 1):
                if self.match(i, j):
                    return True
        return False

    def match(self, x, y):
        for i in range(self.m):
            for j in range(self.m):
                if self.n_img[x+i][y+j] != self.m_img[i][j]:
                    return False
        return True

if __name__ == "__main__":
    main()


