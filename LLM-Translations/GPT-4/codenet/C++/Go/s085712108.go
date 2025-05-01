package main

import (
	"fmt"
	"strconv"
)

const MOD = 7007

type QUEUE struct {
	a, b, c, tot int
}

var F = [6][3]int{{1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 0, 0}, {0, 2, 0}, {0, 0, 2}}
var Hash [MOD][]int

func HASH(n int) bool {
	for _, v := range Hash[n%MOD] {
		if n == v {
			return false
		}
	}
	Hash[n%MOD] = append(Hash[n%MOD], n)
	return true
}

func main() {
	var Push QUEUE
	Push.tot = 0
	var que []QUEUE
	fmt.Scanf("%d%d%d", &Push.a, &Push.b, &Push.c)
	que = append(que, Push)

	for len(que) > 0 {
		Fro := que[0]
		if Fro.a == Fro.b && Fro.b == Fro.c {
			fmt.Printf("%d\n", Fro.tot)
			return
		}
		for i := 0; i < 6; i++ {
			Push = Fro
			Push.tot++
			Push.a += F[i][0]
			Push.b += F[i][1]
			Push.c += F[i][2]
			n := strconv.Itoa(Push.a*10000 + Push.b*100 + Push.c)
			if !HASH(int(n)) {
				continue
			}
			que = append(que, Push)
		}
		que = que[1:]
	}
}

// 
