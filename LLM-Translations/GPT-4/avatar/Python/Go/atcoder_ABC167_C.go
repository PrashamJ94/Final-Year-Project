package main

import (
    "fmt"
    "sort"
)

func main() {
    var n, m, x int
    fmt.Scan(&n, &m, &x)
    
    c := make([][]int, n)
    for i := range c {
        c[i] = make([]int, m+1)
        for j := range c[i] {
            fmt.Scan(&c[i][j])
        }
    }
    
    ans := 1 << 60

    for bit := 0; bit < (1 << n); bit++ {
        s := make([]int, m)
        cost := 0
        for i := 0; i < n; i++ {
            if (bit >> i) & 1 == 1 {
                cost += c[i][0]
                for j := 0; j < m; j++ {
                    s[j] += c[i][j+1]
                }
            }
        }
        ok := true
        for _, val := range s {
            if val < x {
                ok = false
            }
        }
        if ok {
            ans = min(ans, cost)
        }
    }
    if ans == 1<<60 {
        fmt.Println(-1)
    } else {
        fmt.Println(ans)
    }
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
// End of Code


Please note, Go has a different way of handling inputs and outputs compared to Python. The language also lacks some Python features like list comprehension and built-in combinations function. So, I've used bitwise operations to generate and iterate through the combinations. The equivalent of numpy arrays in Go is slices.
