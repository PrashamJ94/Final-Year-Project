package main

import (
    "fmt"
    "sort"
)

func main() {
    var n int
    fmt.Scan(&n)
    l := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&l[i])
    }
    sort.Ints(l)
    for i := 0; i < n; i++ {
        if exists(l, l[i]+1) && exists(l, l[i]+2) {
            fmt.Println("YES")
            return
        }
    }
    fmt.Println("NO")
}

func exists(slice []int, item int) bool {
    for _, v := range slice {
        if v == item {
            return true
        }
    }
    return false
}
// End of Code


