
import sys

def strrstr(string, pattern):
    offset = 0
    lastP = None

    while True:
        searchResult = string[offset:].find(pattern)
        if searchResult != -1 and string[offset] != '\0':
            lastP = string[offset + searchResult:]
            offset += 1
        else:
            break

    return lastP

def main():
    patternBase = "keyence"
    
    S = input().strip()

    len_S = len(S)
    found = False

    for offset in range(len(patternBase)):
        top = patternBase[:offset]
        bottom = patternBase[offset:]

        topSearch = S.find(top)
        if topSearch != -1:
            bottomSearch = strrstr(S[topSearch + offset:], bottom)
            if bottomSearch is not None:
                sepCount = 0

                if topSearch != 0:
                    sepCount += 1
                if topSearch + offset != S.find(bottom, topSearch + offset):
                    sepCount += 1
                if bottomSearch[len(bottom):] != '':
                    sepCount += 1

                if sepCount <= 1:
                    found = True
                    break

    print("YES" if found else "NO")

if __name__ == "__main__":
    main()


#
