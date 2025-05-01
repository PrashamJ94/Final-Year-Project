package main

import (
    "fmt"
    "math/big"
)

func combi(N, K int) *big.Int {
    a := big.NewInt(1)
    for i := 0; i < K; i++ {
        a.Mul(a, big.NewInt(int64(N-i)))
    }
    for j := 0; j < K; j++ {
        a.Div(a, big.NewInt(int64(j+1)))
    }
    return a
}

func main() {
    var N, P int
    fmt.Scan(&N, &P)
    ans := 0
    lis := make([]int, N)
    for i := range lis {
        fmt.Scan(&lis[i])
    }
    ls := make([]int, N)
    for a := range lis {
        ls[a] = lis[a] % 2
    }
    one := 0
    zero := 0
    for _, l := range ls {
        if l == 1 {
            one++
        } else {
            zero++
        }
    }
    pattern_a := big.NewInt(0)
    pattern_b := big.NewInt(0)
    for j := 0; j <= zero; j++ {
        pattern_b.Add(pattern_b, combi(zero, j))
    }
    time := 0
    for time <= one {
        if time%2 == P {
            pattern_a.Add(pattern_a, combi(one, time))
        }
        time++
    }
    fmt.Println(pattern_a.Mul(pattern_a, pattern_b))
}

// End of Code.
