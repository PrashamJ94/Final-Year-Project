package main
import (
    "fmt"
    "sort"
)

func main() {
    var n int
    fmt.Scan(&n)

    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&a[i])
    }

    sort.Sort(sort.Reverse(sort.IntSlice(a)))

    pre := int(^uint(0) >> 1)
    ans := 0

    for j := 0; j < n; j++ {
        if pre - 1 < a[j] {
            ans += pre - 1
            pre = pre - 1
        } else {
           ans += a[j]
           pre = a[j]
        }
        if pre < 0 {
            pre = 0
        }
    }
    fmt.Println(ans)
} // End of Code
