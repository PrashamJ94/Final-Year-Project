import sys

def main():
    s = input().strip()
    if s == "Sunny":
        print("Cloudy")
    elif s == "Cloudy":
        print("Rainy")
    else:
        print("Sunny")

if __name__ == "__main__":
    main()


