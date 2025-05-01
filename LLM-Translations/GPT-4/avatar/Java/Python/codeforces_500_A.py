
from typing import List

def dfs(currpos: int, arr: List[int], target: int) -> bool:
    if currpos == target:
        return True
    if currpos == len(arr) + 1:
        return False
    teleport = dfs(currpos + arr[currpos - 1], arr, target)
    if teleport:
        return True
    return False

def main():
    n, goal = map(int, input().split())
    arr = list(map(int, input().split()))
    isFound = dfs(1, arr, goal)
    if isFound:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()


