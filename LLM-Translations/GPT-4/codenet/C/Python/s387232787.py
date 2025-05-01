
def count_characters(input_string):
    counts = [0] * 26

    for char in input_string:
        if 'a' <= char <= 'z':
            counts[ord(char) - ord('a')] += 1
        elif 'A' <= char <= 'Z':
            counts[ord(char) - ord('A')] += 1

    return counts

if __name__ == "__main__":
    input_string = input()
    counts = count_characters(input_string)

    for i in range(26):
        print(chr(ord('a') + i), ':', counts[i])

#
