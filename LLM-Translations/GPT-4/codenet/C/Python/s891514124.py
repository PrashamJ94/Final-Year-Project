def main():
    S = int(input())

    if S < 60:
        print(f"0:0:{S}")
      
    elif S < 3600:
        print(f"0:{S//60}:{S%60}")
      
    else:
        print(f"{S//3600}:{(S%3600)//60}:{(S%60)%60}")

if __name__ == "__main__":
    main()


