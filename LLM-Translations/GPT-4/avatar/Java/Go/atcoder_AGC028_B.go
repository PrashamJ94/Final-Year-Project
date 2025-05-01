
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(readLine(reader))
	a := make([]int, n)
	sa := strings.Split(readLine(reader), " ")

	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(sa[i])
	}

	mod := 1000000007
	p := 1
	for i := 2; i <= n; i++ {
		p = p * i % mod
	}

	q := make([]int64, n)
	q[0] = 1
	for i := 1; i < n; i++ {
		q[i] = (q[i-1] + modinv(int64(i+1), mod)) % int64(mod)
	}

	var ans int64
	for i := 0; i < n; i++ {
		val := q[i] + q[n-i-1] - 1
		val *= int64(a[i])
		val %= int64(mod)
		val *= int64(p)
		val %= int64(mod)
		ans += val
		ans %= int64(mod)
	}

	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	line, _, _ := reader.ReadLine()
	return string(line)
}

func modinv(a int64, m int) int64 {
	var b, u, v, tmp int64
	b = int64(m)
	u = 1
	v = 0

	for b > 0 {
		t := a / b
		a -= t * b
		tmp = a
		a = b
		b = tmp
		u -= t * v
		tmp = u
		u = v
		v = tmp
	}

	u %= int64(m)
	if u < 0 {
		u += int64(m)
	}
	return u
}

//End of Code.
