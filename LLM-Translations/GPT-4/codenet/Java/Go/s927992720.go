package main

import (
    "fmt"
    "os"
    "bufio"
    "strconv"
    "strings"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)

    for {
        scanner.Scan()
        input := strings.Split(scanner.Text(), " ")
        a, _ := strconv.Atoi(input[0])
        op := input[1]
        b, _ := strconv.Atoi(input[2])

        if op == "?" {
            break
        }
        if op == "+" {
            fmt.Println(a + b)
        }
        if op == "-" {
            fmt.Println(a - b)
        }
        if op == "*" {
            fmt.Println(a * b)
        }
        if op == "/" {
            fmt.Println(a / b)
        }
    }
}
// 
