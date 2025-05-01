
package main

import (
    "fmt"
    "bufio"
    "os"
    "strconv"
    "strings"
)

func main() {
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    n, _ := strconv.Atoi(scanner.Text())
    scanner.Scan()
    wStr := strings.Split(scanner.Text(), " ")
    w := make([]int, n)
    x := 0
    for i, str := range wStr {
        w[i], _ = strconv.Atoi(str)
        x += w[i]
    }
    d := make([]int, 0)
    for i := 0; i < n; i++ {
        if float64(x - w[i]) / float64(n - 1) == float64(w[i]) {
            d = append(d, i + 1)
        }
    }
    fmt.Println(len(d))
    for _, v := range d {
        fmt.Printf("%d ", v)
    }
} // End of Code


