
def main(s):
    count = 0
    counter = [0]

    if s == "":
        return

    for char in s:
        if char in ["A", "C", "G", "T"]:
            count += 1
        else:
            counter.append(count)
            count = 0

    counter.append(count)
    counter.sort()
    print(counter[-1])

s = input()
main(s)

#
