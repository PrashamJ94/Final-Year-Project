package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type atcoder_AGC029_C struct {
	n int
	a []int
	s map[int]int
}

func main() {
	m := atcoder_AGC029_C{}
	m.solve()
}

func (m *atcoder_AGC029_C) set() {
	reader := bufio.NewReader(os.Stdin)

	nStr, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(nStr))

	m.n = n

	aStr, _ := reader.ReadString('\n')
	aStr = strings.TrimSpace(aStr)
	aStrSlice := strings.Split(aStr, " ")

	m.a = make([]int, n)

	for i, v := range aStrSlice {
		vInt, _ := strconv.Atoi(v)
		m.a[i] = vInt
	}

	m.s = make(map[int]int)
}

func (m *atcoder_AGC029_C) solve() {
	m.set()
	ng := 0
	ok := m.n
	for ok-ng > 1 {
		k := (ng + ok) / 2
		if m.isPossible(k) {
			ok = k
		} else {
			ng = k
		}
	}
	fmt.Println(ok)
}

func (m *atcoder_AGC029_C) isPossible(k int) bool {
	m.s = make(map[int]int)
	current := 0
	for _, ai := range m.a {
		if ai <= current {
			if k == 1 {
				return false
			}
			for key := range m.s {
				if key >= ai {
					delete(m.s, key)
				}
			}
			p := ai - 1
			for {
				if p < 0 {
					return false
				}
				sp, ok := m.s[p]
				if !ok {
					sp = 0
				}
				sp++
				m.s[p] = sp
				if sp == k {
					delete(m.s, p)
					p--
				} else {
					break
				}
			}
		}
		current = ai
	}
	return true
}

// //End of Code.
