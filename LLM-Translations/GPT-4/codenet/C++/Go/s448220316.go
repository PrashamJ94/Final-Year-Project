
package main

import (
	"fmt"
	"os"
)

func read() (int, int) {
	var k, f int
	ch, _ := os.Stdin.ReadByte()
	for ch < '0' || ch > '9' {
		if ch == '-' {
			f = -1
		}
		ch, _ = os.Stdin.ReadByte()
	}
	for ch >= '0' && ch <= '9' {
		k = k*10 + int(ch-'0')
		ch, _ = os.Stdin.ReadByte()
	}
	return k * f, 1
}

func write(x int) {
	if x < 0 {
		x = -x
		os.Stdout.Write([]byte("-"))
	}
	if x > 9 {
		write(x / 10)
	}
	os.Stdout.Write([]byte{byte(x%10 + '0')})
}

func writeln(x int) {
	write(x)
	os.Stdout.Write([]byte("\n"))
}

func get(x int, fa []int, v []int) int {
	if x == fa[x] {
		return x
	}
	f := get(fa[x], fa, v)
	v[x] += v[fa[x]]
	fa[x] = f
	return f
}

func main() {
	n, _ := read()
	m, _ := read()
	fa := make([]int, n+1)
	v := make([]int, 2*n+1)

	for i := 1; i <= n; i++ {
		fa[i] = i
	}

	for i := 1; i <= m; i++ {
		l, _ := read()
		r, _ := read()
		vi, _ := read()

		li := get(l, fa, v)
		ri := get(r, fa, v)

		if li != ri {
			v[ri] = vi - v[r] + v[l]
			fa[ri] = li
		} else {
			if v[r]-v[l] != vi {
				fmt.Println("No")
				return
			}
		}
	}
	fmt.Println("Yes")
}
// 


