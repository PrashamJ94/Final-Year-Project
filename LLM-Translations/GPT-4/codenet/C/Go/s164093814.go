package main

import (
	"fmt"
	"strings"
)

const (
	M = 1046527
	L = 14
)

var H [M][L]byte

func getChar(ch byte) int {
	switch ch {
	case 'A':
		return 1
	case 'C':
		return 2
	case 'G':
		return 3
	case 'T':
		return 4
	}
	return 0
}

func getKey(str []byte) int {
	var sum int
	p := 1
	for i := 0; i < len(str); i++ {
		sum += p * getChar(str[i])
		p *= 5
	}
	return sum
}

func h1(key int) int { return key % M }
func h2(key int) int { return 1 + (key % (M - 1)) }

func find(str []byte) bool {
	var hash, key int
	key = getKey(str)
	i := 0
	for {
		hash = (h1(key) + i*h2(key)) % M
		if strings.EqualFold(string(H[hash][:]), string(str)) {
			return true
		} else if len(H[hash]) == 0 {
			return false
		}
		i++
	}
	return false
}

func insert(str []byte) bool {
	var hash, key int
	key = getKey(str)
	i := 0
	for {
		hash = (h1(key) + i*h2(key)) % M
		if strings.EqualFold(string(H[hash][:]), string(str)) {
			return true
		} else if len(H[hash]) == 0 {
			copy(H[hash][:], str)
			return false
		}
		i++
	}
	return false
}

func main() {
	var n int
	var str [L]byte
	var com [9]byte

	fmt.Scanf("%d", &n)

	for i := 0; i < M; i++ {
		H[i][0] = 0
	}

	for i := 0; i < n; i++ {
		fmt.Scanf("%s %s", &com, &str)

		if com[0] == 'i' {
			insert(str[:])
		} else {
			if find(str[:]) {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		}
	}
}

// 
