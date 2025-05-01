package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	_, _ = fmt.Scan(&n)

	t := make([]int, n+1)
	tStr := ""
	_, _ = fmt.Scanln(&tStr)
	tStr = strings.TrimSuffix(tStr, "\n")
	tStrArr := strings.Split(tStr, " ")
	for i, v := range tStrArr {
		t[i+1], _ = strconv.Atoi(v)
	}

	a := make([]int, n+1)
	aStr := ""
	_, _ = fmt.Scanln(&aStr)
	aStr = strings.TrimSuffix(aStr, "\n")
	aStrArr := strings.Split(aStr, " ")
	for i, v := range aStrArr {
		a[i+1], _ = strconv.Atoi(v)
	}

	ans, cnt := make([]int, 0), make([]int, n+1)
	for _, v := range a {
		cnt[v]++
	}
	for i := 1; i <= n; i++ {
		if t[i] == 1 {
			crt := []int{i}
			x := a[i]
			for cnt[x] == 1 {
				crt = append(crt, x)
				x = a[x]
			}
			if len(crt) > len(ans) {
				ans = crt[:]
			}
		}
	}

	for i := 0; i < len(ans)/2; i++ {
		j := len(ans) - i - 1
		ans[i], ans[j] = ans[j], ans[i]
	}

	fmt.Println(len(ans))
	fmt.Println(strings.Trim(strings.Replace(fmt.Sprint(ans), " ", " ", -1), "[]"))
}

// End of Code

