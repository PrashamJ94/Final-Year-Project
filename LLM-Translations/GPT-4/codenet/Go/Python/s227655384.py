
import sys
from io import StringIO
import heapq

def read_long_lines(times):
    result = [None] * times
    for i in range(times):
        line = sys.stdin.readline().rstrip()
        result[i] = line
    return result

class Console:
    def __init__(self):
        self.buffer = StringIO()

    def printf(self, format_str, *args):
        print(format_str % args, end='', file=self.buffer)

    def println(self, s):
        print(s, file=self.buffer)

    def flush(self):
        sys.stdout.write(self.buffer.getvalue())
        self.buffer.close()

def print_list(lst):
    con = Console()
    for i, x in enumerate(lst):
        if i == 0:
            con.printf("%d", x)
        else:
            con.printf(" %d", x)
    con.println("")
    con.flush()

def main():
    con = Console()

    m = set()
    lines = read_long_lines(4)
    a = list(map(int, lines[1].split()))
    for x in a:
        m.add(x)

    result = []
    b = list(map(int, lines[3].split()))
    for x in b:
        if x in m:
            m.remove(x)
        else:
            m.add(x)

    result = sorted(list(m))
    for x in result:
        con.printf("%d\n", x)
    con.flush()

if __name__ == '__main__':
    main()


#
