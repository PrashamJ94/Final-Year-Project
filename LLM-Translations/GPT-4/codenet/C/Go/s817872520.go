package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const INF int = 0x5fffffff

func getint(s []string, idx *int) int {
	n, _ := strconv.Atoi(s[*idx])
	*idx++
	return n
}

func main() {
	var w, i, k, f, close, ans int

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	w, _ = strconv.Atoi(scanner.Text())

	scanner.Scan()
	p := strings.Fields(scanner.Text())

	for ans, f, i = 0, 0, 1; i <= w; i++ {
		a := getint(p, &i)
		if a == 0 {
			f |= 1
		} else if a < 0 {
			f |= 2
		} else {
			ans += a
		}
	}
	if ans == 0 || (f&1) == 0 {
		fmt.Println("0")
		return
	}
	if (f & 2) == 0 {
		fmt.Println(ans)
		return
	}

	b := make([]int, w+1)
	for close, f, i = 0, 0, 1; i <= w; i++ {
		a := getint(p, &i)
		if a == 0 {
			close = INF
			f = -1
		} else if a < 0 {
			if f < 0 || close-(i-f) > -a {
				close = -a
				f = i
			}
		} else {
			if f < 0 {
				b[i] = INF
			} else {
				k = close - (i - f)
				if k < 0 {
					k = 0
				}
				b[i] = k
			}
		}
	}

	for close, f, i = 0, w, w; i >= 1; i-- {
		a := getint(p, &i)
		if a == 0 {
			close = INF
			f = -1
		} else if a < 0 {
			if f < 0 || close-(f-i) > -a {
				close = -a
				f = i
			}
		} else {
			if f < 0 {
				b[i] = INF
			} else {
				k = close - (f - i)
				if k < 0 {
					k = 0
				}
				if k > b[i] {
					b[i] = k
				}
			}
		}
	}

	for ans, i = 0, 1; i <= w; i++ {
		a := getint(p, &i)
		if a > 0 {
			if b[i] > a {
				ans += a
			} else {
				ans += b[i]
			}
		}
	}
	fmt.Println(ans)
}

// 
