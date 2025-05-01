package main

import "fmt"

func main() {
    var N int
    fmt.Scan(&N)
    ans := make([]int, 2)

    for i := 1; i <= N; i++ {
        if (i*(i+1))/2 < N {
            continue
        } else {
            ans[0] = i - 1
            ans[1] = (i*(i+1))/2 - N
            break
        }
    }
    for i := 0; i <= ans[0]; i++ {
        if i + 1 != ans[1] {
            fmt.Println(i + 1)
        }
    }
}
// 
