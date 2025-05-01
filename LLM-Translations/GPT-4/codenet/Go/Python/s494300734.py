
def main():
    s = input().strip()
    
    ans = "No"
    if s.index("C") < s.rindex("F") and "C" in s:
        ans = "Yes"
    if "C" not in s:
        ans = "No"
    
    print(ans)

if __name__ == "__main__":
    main()

#

