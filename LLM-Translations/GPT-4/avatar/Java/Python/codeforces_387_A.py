import datetime

def main():
    s = input().split(":")
    t = input().split(":")
    x = datetime.time(int(s[0]), int(s[1]))
    y = datetime.time(int(t[0]), int(t[1]))
    x_minutes = x.hour * 60 + x.minute
    y_minutes = y.hour * 60 + y.minute
    diff = x_minutes - y_minutes
    if diff < 0:
        diff += 24 * 60
    result = "{:02d}:{:02d}".format(diff // 60, diff % 60)
    print(result)

if __name__ == '__main__':
    main()


