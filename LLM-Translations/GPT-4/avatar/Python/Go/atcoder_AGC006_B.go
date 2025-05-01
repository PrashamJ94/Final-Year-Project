package main

import (
    "fmt"
    "sort"
)

func sub(y []int, debug int) []int {
    for len(y) > 1 {
        var newY []int
        for i := 0; i < len(y)-2; i++ {
            temp := y[i : i+3]
            sort.Ints(temp)
            newY = append(newY, temp[1])
        }
        y = newY
        if debug != 0 {
            fmt.Println("D", y)
        }
    }
    return y
}

func calc(x []int) int {
    y := sub(x, 0)
    if y[0] == 2 {
        sub(x, 1)
        fmt.Println("=", x)
    }
    return y[0]
}

func main() {
    var N, X int
    fmt.Scan(&N, &X)
    if X == 1 || X == N*2-1 {
        fmt.Println("No")
    } else {
        fmt.Println("Yes")
        var xs []int
        if X == N*2-2 {
            for i := N - 1; i <= X+1; i++ {
                xs = append(xs, i)
            }
            for i := 1; i < N-1; i++ {
                xs = append(xs, i)
            }
        } else {
            var ys []int
            for i := 1; i < X-1; i++ {
                ys = append(ys, i)
            }
            for i := X + 3; i < N*2; i++ {
                ys = append(ys, i)
            }
            xs = append(ys[:N-3], X+2, X-1, X, X+1)
            xs = append(xs, ys[N-3:]...)
        }
        for _, x := range xs {
            fmt.Println(x)
        }
    }
}

End of Code.
