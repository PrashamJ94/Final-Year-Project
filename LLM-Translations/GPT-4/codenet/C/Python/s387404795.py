def main():
    str_input = input()
    p_input = input()
    
    str_concat = str_input + str_input
    
    slen = len(str_concat)
    plen = len(p_input)
    
    flag = 0
    for i in range(slen - plen):
        if str_concat[i:i+plen] == p_input:
            flag = 1
            
    if flag:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()


