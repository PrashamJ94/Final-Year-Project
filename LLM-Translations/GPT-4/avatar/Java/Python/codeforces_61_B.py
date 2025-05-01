import re
from itertools import permutations

def main():
    word1 = re.sub(r"[^a-zA-Z]", "", input().strip().lower())
    word2 = re.sub(r"[^a-zA-Z]", "", input().strip().lower())
    word3 = re.sub(r"[^a-zA-Z]", "", input().strip().lower())
    perms = [''.join(p) for p in permutations([word1, word2, word3])]
    students = int(input().strip())
    
    for _ in range(students):
        testCase = re.sub(r"[^a-zA-Z]", "", input().strip().lower())
        if testCase in perms:
            print("ACC")
        else:
            print("WA")

if __name__ == "__main__":
    main()


