package main

import (
	"fmt"
	"math/big"
	"strconv"
)

func main() {
	var W, H int
	for {
		fmt.Scan(&W, &H)
		if W == 0 && H == 0 {
			break
		}

		mapData := make([]string, H)
		for h := 0; h < H; h++ {
			fmt.Scan(&mapData[h])
		}

		dp := make([][]*big.Int, H)
		for i := range dp {
			dp[i] = make([]*big.Int, W)
		}

		for h := 0; h < H; h++ {
			for w := 0; w < W; w++ {
				hprev := big.NewInt(0)
				if h >= 1 {
					hprev = dp[h-1][w]
				}
				wprev := big.NewInt(0)
				if w >= 1 {
					wprev = dp[h][w-1]
				}
				if mapData[h][w] >= '0' && mapData[h][w] <= '9' {
					max := big.NewInt(0)
					if hprev.Cmp(wprev) > 0 {
						max = hprev
					} else {
						max = wprev
					}
					num, _ := strconv.Atoi(string(mapData[h][w]))
					dp[h][w] = new(big.Int).Add(new(big.Int).Mul(max, big.NewInt(10)), big.NewInt(int64(num)))
				} else {
					dp[h][w] = big.NewInt(0)
				}
			}
		}

		max := big.NewInt(0)
		for h := 0; h < H; h++ {
			for w := 0; w < W; w++ {
				if dp[h][w].Cmp(max) > 0 {
					max = dp[h][w]
				}
			}
		}
		fmt.Println(max)
	}
}

// 
