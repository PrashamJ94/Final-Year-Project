# Here's the translated Python code:

def toggle_case(s):
    result = ""
    for c in s:
        if c.isupper():
            result += c.lower()
        elif c.islower():
            result += c.upper()
        else:
            result += c
    return result

if __name__ == "__main__":
    s = input()
    print(toggle_case(s))


