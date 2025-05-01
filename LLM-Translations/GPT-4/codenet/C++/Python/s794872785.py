import sys
from collections import Counter

def main():
    strings = []
    for line in sys.stdin:
        strings.extend(line.strip().split())

    max_len_word = max(strings, key=len)
    most_common_word = Counter(strings).most_common(1)[0][0]

    print(f"{most_common_word} {max_len_word}")

if __name__ == "__main__":
    main()


