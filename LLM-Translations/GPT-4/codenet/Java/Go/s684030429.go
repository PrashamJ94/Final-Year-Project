package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	fmt.Println(int(math.Max(0, float64(a-2*b))))
}

func imax(a []int) int {
	max := math.MinInt32
	for _, v := range a {
		if max < v {
			max = v
		}
	}
	return max
}

func stoi(s string) (int, error) {
	return strconv.Atoi(s)
}

func stod(s string) (float64, error) {
	return strconv.ParseFloat(s, 64)
}

func lmin(a []int64) int64 {
	min := int64(math.MaxInt64)
	for _, v := range a {
		if min > v {
			min = v
		}
	}
	return min
}

func imin(a []int) int {
	min := math.MaxInt32
	for _, v := range a {
		if min > v {
			min = v
		}
	}
	return min
}

func lmax(a []int64) int64 {
	max := int64(math.MinInt64)
	for _, v := range a {
		if max < v {
			max = v
		}
	}
	return max
}

func ibs(a []int, toFind int) bool {
	found := false
	for _, v := range a {
		if v == toFind {
			found = true
			break
		}
	}
	return found
}

func lbs(a []int64, toFind int64) bool {
	found := false
	for _, v := range a {
		if v == toFind {
			found = true
			break
		}
	}
	return found
}

func stb(s string) int {
	sum := 0
	k := 0
	for i := len(s) - 1; i >= 0; i-- {
		num, _ := strconv.Atoi(string(s[i]))
		sum += num * int(math.Pow(2, float64(k)))
		k++
	}
	return sum
}

// 
