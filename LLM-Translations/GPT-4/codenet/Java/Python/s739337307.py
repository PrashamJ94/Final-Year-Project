import sys

def main():
    n, m = map(int, input().split())
    map_dict = {}

    count_ac = 0
    count_wa_all = 0

    for i in range(m):
        question, wa_or_ac = input().split()
        question = int(question)

        if question not in map_dict:
            if wa_or_ac == "WA":
                map_dict[question] = 1
            else:
                map_dict[question] = -1
                count_ac += 1
        else:
            count_wa = map_dict[question]
            if count_wa < 0:
                continue
            else:
                if wa_or_ac == "WA":
                    map_dict[question] = count_wa + 1
                else:
                    map_dict[question] = -count_wa
                    count_ac += 1
                    count_wa_all += count_wa

    print(count_ac, count_wa_all)

if __name__ == "__main__":
    main()


