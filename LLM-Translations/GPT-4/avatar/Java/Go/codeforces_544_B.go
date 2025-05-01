
package main

import "fmt"
import "bufio"
import "os"
import "strconv"
import "strings"

func main() {
    reader := bufio.NewReader(os.Stdin)
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)
    inputs := strings.Split(input, " ")
    n, _ := strconv.Atoi(inputs[0])
    count, _ := strconv.Atoi(inputs[1])
    printIsland(n, count)
}

func printIsland(n int, count int) {
    a := (n + 1) / 2
    b := n / 2
    max := a * a + b * b
    if count > max {
        fmt.Println("NO")
        return
    }
    fmt.Println("YES")
    for i := 0; i < n; i++ {
        var sb strings.Builder
        for j := 0; j < n; j++ {
            if (i + j) % 2 == 0 && count > 0 {
                sb.WriteString("L")
                count--
            } else {
                sb.WriteString("S")
            }
        }
        fmt.Println(sb.String())
    }
}

// //End of Code
