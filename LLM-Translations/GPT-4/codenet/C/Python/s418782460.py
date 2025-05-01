
from sys import stdin

def main():
    s_input = input().strip().split()
    n_human_number = int(s_input[0])
    n_water_length = int(s_input[1])

    an_coming_sec = list(map(int, input().strip().split()))

    n_start = an_coming_sec[0]
    n_next_human_index = 0
    n_water_life = 0

    while n_next_human_index < n_human_number:
        if n_next_human_index == n_human_number:
            break
        else:
            n_stop = n_start + n_water_length
            if an_coming_sec[n_next_human_index] < n_stop:
                while n_next_human_index < n_human_number and an_coming_sec[n_next_human_index] < n_stop:
                    if n_stop <= an_coming_sec[n_next_human_index] + n_water_length:
                        n_stop = an_coming_sec[n_next_human_index] + n_water_length
                        n_next_human_index += 1
                if n_next_human_index == n_human_number:
                    n_water_life = n_water_life + (n_stop - n_start)
                    break
            n_water_life = n_water_life + (n_stop - n_start)
            n_start = n_stop
            if n_start < an_coming_sec[n_next_human_index]:
                n_start = an_coming_sec[n_next_human_index]

    print(n_water_life)

if __name__ == "__main__":
    main()


