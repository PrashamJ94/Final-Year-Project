
from sys import stdin

def main():
    a, tA = map(int, stdin.readline().split())
    b, tB = map(int, stdin.readline().split())
    timing = stdin.readline().strip()
    hrs = int(timing[:2])
    mins = int(timing[3:])
    
    sim_departure = hrs * 60 + mins
    sim_arrival = sim_departure + tA
    
    counter = 0
    for i in range(300, 1440, b):
        bus_departure = i
        bus_arrival = i + tB
        if bus_departure >= sim_arrival or sim_departure >= bus_arrival:
            continue
        counter += 1
    
    print(counter)

if __name__ == "__main__":
    main()


