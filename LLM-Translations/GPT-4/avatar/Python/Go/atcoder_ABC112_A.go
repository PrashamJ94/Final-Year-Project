package main

import (
    "fmt"
    "bufio"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter age: ")
    strAge, _ := reader.ReadString('\n')
    age, _ := strconv.Atoi(strings.TrimSpace(strAge))

    if age == 1 {
        fmt.Println("Hello World")
    } else {
        fmt.Print("Enter two numbers: ")
        strNums, _ := reader.ReadString('\n')
        nums := strings.Fields(strNums)
        a, _ := strconv.Atoi(nums[0])
        b, _ := strconv.Atoi(nums[1])
        fmt.Println(a + b)
    }
}
// End of Code
