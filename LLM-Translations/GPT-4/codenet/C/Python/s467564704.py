
def main():
    input_matrix = []
    for i in range(3):
        row = list(map(int, input().split()))
        input_matrix.append(row)
    
    tc = int(input())
    
    for _ in range(tc):
        testcase = int(input())
        for i in range(3):
            for j in range(3):
                if input_matrix[i][j] == testcase:
                    input_matrix[i][j] = 0
    
    if all(input_matrix[i][i] == 0 for i in range(3)) or all(input_matrix[i][2-i] == 0 for i in range(3)):
        print("Yes")
    elif any(all(input_matrix[i][j] == 0 for j in range(3)) for i in range(3)) or any(all(input_matrix[i][j] == 0 for i in range(3)) for j in range(3)):
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()


