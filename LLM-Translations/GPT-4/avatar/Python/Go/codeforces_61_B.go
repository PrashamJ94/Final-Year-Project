package main

import (
	"fmt"
	"strings"
	"bufio"
	"os"
	"strconv"
	"sort"
	"math"
)

func valid(i, j, n, m int) bool {
	return i >= 0 && i < n && j >= 0 && j < m
}

func sumn(i, n int) float64 {
	return float64(n-i) * float64(i+n) / 2.0
}

func sqfun(a, b, c float64) float64 {
	return (-b + math.Sqrt(b*b-4*a*c)) / (2 * a)
}

func f(s string) string {
	s = strings.ToLower(s)
	s = strings.Replace(s, "-", "", -1)
	s = strings.Replace(s, ";", "", -1)
	s = strings.Replace(s, "_", "", -1)
	return s
}

func permutations(arr []string) [][]string {
	var helper func([]string, int)
	res := [][]string{}

	helper = func(arr []string, n int) {
		if n == 1 {
			tmp := make([]string, len(arr))
			copy(tmp, arr)
			res = append(res, tmp)
		} else {
			for i := 0; i < n; i++ {
				helper(arr, n-1)
				if n%2 == 1 {
					tmp := arr[i]
					arr[i] = arr[n-1]
					arr[n-1] = tmp
				} else {
					tmp := arr[0]
					arr[0] = arr[n-1]
					arr[n-1] = tmp
				}
			}
		}
	}
	helper(arr, len(arr))
	return res
}

func solve() {
	scanner := bufio.NewScanner(os.Stdin)
	var l []string
	for i := 0; i < 3; i++ {
		scanner.Scan()
		l = append(l, f(scanner.Text()))
	}
	t := permutations(l)
	var l2 []string
	for _, i := range t {
		l2 = append(l2, strings.Join(i, ""))
	}
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	for i := 0; i < n; i++ {
		scanner.Scan()
		s := f(scanner.Text())
		if sort.SearchStrings(l2, s) < len(l2) {
			fmt.Println("ACC")
		} else {
			fmt.Println("WA")
		}
	}
}

func main() {
	solve()
}

// End of Code.

