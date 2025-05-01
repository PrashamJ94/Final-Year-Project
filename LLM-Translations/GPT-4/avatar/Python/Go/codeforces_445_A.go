package main

import (
    "fmt"
    "bufio"
    "os"
    "strings"
)

func main() {
    var n, m int
    fmt.Scan(&n, &m)

    l := make([][]rune, n)

    scanner := bufio.NewScanner(os.Stdin)
    for i := 0; i < n; i++ {
        scanner.Scan()
        s := []rune(scanner.Text())

        for j := 0; j < m; j++ {
            if s[j] == '.' {
                if (i+j)&1 == 1 {
                    s[j] = 'W'
                } else {
                    s[j] = 'B'
                }
            }
        }
        l[i] = s
    }

    for _, c := range l {
        fmt.Println(strings.Join(strings.Fields(fmt.Sprint(c)), ""))
    }
}

// End of Code
