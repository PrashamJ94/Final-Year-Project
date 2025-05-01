
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	cStr := strings.Split(scanner.Text(), " ")
	c := make([]int, n)
	for i := 0; i < n; i++ {
		c[i], _ = strconv.Atoi(cStr[i])
	}

	mod := 1000000007
	if n == 1 {
		fmt.Println((c[0] * 2) % mod)
		return
	}
	sort.Ints(c)
	b := power(2, n)
	a := power(2, n-2)
	ans := int64(0)
	for i := 2; i <= n+1; i++ {
		val := (a * int64(i)) % int64(mod)
		val *= int64(c[n+1-i])
		val %= int64(mod)
		ans += val
		ans %= int64(mod)
	}
	ans *= int64(b)
	ans %= int64(mod)
	fmt.Println(ans)
}

func power(x, n int) int64 {
	if n == 0 {
		return 1
	}
	mod := 1000000007
	val := power(x, n/2)
	val = (val * val) % int64(mod)
	if n%2 == 1 {
		val = (val * int64(x)) % int64(mod)
	}
	return val
}

// //End of Code.
