package main

import (
    "fmt"
)

func main() {
    var t, s, q int
    fmt.Scan(&t, &s, &q)

    ans := 0
    for s < t {
        s *= q
        ans += 1
    }
    fmt.Println(ans)
} 
// End of Code
