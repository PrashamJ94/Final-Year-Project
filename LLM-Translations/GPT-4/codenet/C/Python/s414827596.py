
import sys

def main():
    for line in sys.stdin:
        a, b, c, d, e, f = map(int, line.split())
        y = (c * d - f * a) / (b * d - e * a)
        x = (c * e - f * b) / (a * e - d * b)
        if y <= 0 and y > -0.0005:
            y = 0
        if x <= 0 and x > -0.0005:
            x = 0
        print(f"{x:.3f} {y:.3f}")

if __name__ == "__main__":
    main()

#
