
from typing import List, Tuple

def main():
    map_num = int(input())
    for _ in range(map_num):
        h, w = map(int, input().split())
        battle_town = [input() for _ in range(h)]
        x, y = find_tank(h, w, battle_town)
        bomber_act_num = int(input())
        bomber_act = input()
        x, y = simulate_actions(h, w, battle_town, x, y, bomber_act)
        battle_town = update_tank(h, w, battle_town, x, y)
        print_battle_town(h, w, battle_town)

def find_tank(h: int, w: int, battle_town: List[str]) -> Tuple[int, int]:
    for i in range(h):
        for j in range(w):
            if battle_town[i][j] in "^v<>":
                return i, j
    return -1, -1

def simulate_actions(h: int, w: int, battle_town: List[str], x: int, y: int, bomber_act: str) -> Tuple[int, int]:
    for act in bomber_act:
        if act == 'U':
            battle_town[x] = battle_town[x][:y] + '^' + battle_town[x][y + 1:]
            if x - 1 >= 0 and battle_town[x - 1][y] == '.':
                x -= 1
        elif act == 'D':
            battle_town[x] = battle_town[x][:y] + 'v' + battle_town[x][y + 1:]
            if x + 1 < h and battle_town[x + 1][y] == '.':
                x += 1
        elif act == 'L':
            battle_town[x] = battle_town[x][:y] + '<' + battle_town[x][y + 1:]
            if y - 1 >= 0 and battle_town[x][y - 1] == '.':
                y -= 1
        elif act == 'R':
            battle_town[x] = battle_town[x][:y] + '>' + battle_town[x][y + 1:]
            if y + 1 < w and battle_town[x][y + 1] == '.':
                y += 1
        elif act == 'S':
            move_bomber(h, w, battle_town, x, y)
    return x, y

def move_bomber(h: int, w: int, battle_town: List[str], x: int, y: int):
    directions = {'^': (-1, 0), 'v': (1, 0), '<': (0, -1), '>': (0, 1)}
    dx, dy = directions[battle_town[x][y]]
    nx, ny = x + dx, y + dy
    while 0 <= nx < h and 0 <= ny < w:
        if battle_town[nx][ny] == '*':
            battle_town[nx] = battle_town[nx][:ny] + '.' + battle_town[nx][ny + 1:]
            break
        elif battle_town[nx][ny] == '#':
            break
        nx, ny = nx + dx, ny + dy

def update_tank(h: int, w: int, battle_town: List[str], x: int, y: int) -> List[str]:
    new_battle_town = []
    for i in range(h):
        if i == x:
            new_battle_town.append(battle_town[i][:y] + battle_town[x][y] + battle_town[i][y + 1:])
        else:
            new_battle_town.append(battle_town[i])
    return new_battle_town

def print_battle_town(h: int, w: int, battle_town: List[str]):
    for row in battle_town:
        print(row)
    print()

if __name__ == "__main__":
    main()


