
from collections import deque

MOD = 7007

class State:
    def __init__(self, a, b, c, tot):
        self.a = a
        self.b = b
        self.c = c
        self.tot = tot

F = [
    (1, 1, 0),
    (1, 0, 1),
    (0, 1, 1),
    (2, 0, 0),
    (0, 2, 0),
    (0, 0, 2)
]

hash_map = {}
def hash_function(state):
    n = state.a * 10000 + state.b * 100 + state.c
    return n % MOD

def is_visited(state):
    n = hash_function(state)
    if n in hash_map:
        return True
    hash_map[n] = True
    return False

def main():
    a, b, c = map(int, input().split())
    initial_state = State(a, b, c, 0)
    queue = deque([initial_state])

    while queue:
        current_state = queue.popleft()
        if current_state.a == current_state.b == current_state.c:
            print(current_state.tot)
            return

        for fi in F:
            next_state = State(current_state.a + fi[0], current_state.b + fi[1], current_state.c + fi[2], current_state.tot + 1)
            if not is_visited(next_state):
                queue.append(next_state)

if __name__ == "__main__":
    main()

#


