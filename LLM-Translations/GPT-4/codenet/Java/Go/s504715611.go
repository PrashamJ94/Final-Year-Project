package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

type UnionFind struct {
	Parent []int
}

func NewUnionFind(n int) *UnionFind {
	uf := &UnionFind{Parent: make([]int, n)}
	for i := range uf.Parent {
		uf.Parent[i] = -1
	}
	return uf
}

func (uf *UnionFind) root(A int) int {
	if uf.Parent[A] < 0 {
		return A
	}
	uf.Parent[A] = uf.root(uf.Parent[A])
	return uf.Parent[A]
}

func (uf *UnionFind) size(A int) int {
	return -uf.Parent[uf.root(A)]
}

func (uf *UnionFind) connect(A, B int) bool {
	A = uf.root(A)
	B = uf.root(B)
	if A == B {
		return false
	}
	if uf.size(A) < uf.size(B) {
		A, B = B, A
	}
	uf.Parent[A] += uf.Parent[B]
	uf.Parent[B] = A
	return true
}

var (
	scanner = bufio.NewScanner(os.Stdin)
	writer  = bufio.NewWriter(os.Stdout)
)

func main() {
	defer writer.Flush()

	scanner.Split(bufio.ScanWords)

	str := next()
	fmt.Println(str[2] == str[3] && str[4] == str[5])
}

func next() string {
	scanner.Scan()
	return scanner.Text()
}

func nextInt() int {
	i, _ := strconv.Atoi(next())
	return i
}

func nextLong() int64 {
	i, _ := strconv.ParseInt(next(), 10, 64)
	return i
}

func nextDouble() float64 {
	f, _ := strconv.ParseFloat(next(), 64)
	return f
}

func lowerBound(a []int, key int) int {
	left, right := 0, len(a)
	for right-left > 1 {
		mid := (right + left) / 2
		if a[mid] < key {
			left = mid
		} else {
			right = mid
		}
	}
	return left
}

func upperBound(a []int, key int) int {
	left, right := 0, len(a)
	for right-left > 1 {
		mid := (right + left) / 2
		if a[mid] <= key {
			left = mid
		} else {
			right = mid
		}
	}
	return left
}

func isPrime(n int64) bool {
	if n == 2 {
		return true
	}
	if n < 2 || n%2 == 0 {
		return false
	}
	d := int64(math.Sqrt(float64(n)))
	for i := int64(3); i <= d; i += 2 {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func upperDivision(a, b int) int {
	if a%b == 0 {
		return a / b
	}
	return a/b + 1
}

func lupperDivision(a, b int64) int64 {
	if a%b == 0 {
		return a / b
	}
	return a/b + 1
}

func setArray(a int) []int {
	b := make([]int, a)
	for i := range b {
		b[i] = nextInt()
	}
	return b
}

func lsetArray(a int) []int64 {
	b := make([]int64, a)
	for i := range b {
		b[i] = nextLong()
	}
	return b
}

func reverse(str string) string {
	ch := []byte(str)
	length := len(ch)
	for i := 0; i < upperDivision(length, 2); i++ {
		ch[i], ch[length-1-i] = ch[length-1-i], ch[i]
	}
	return string(ch)
}

func printArray(que []int) {
	fmt.Println(strings.Trim(fmt.Sprint(que), "[]"))
}

func doubleSort(a [][]int) [][]int {
	sort.Slice(a, func(i, j int) bool {
		return a[i][0] < a[j][0]
	})
	return a
}

func ldoubleSort(a [][]int64) [][]int64 {
	sort.Slice(a, func(i, j int) bool {
		return a[i][0] < a[j][0]
	})
	return a
}

func modpow(x, n, mo int64) int64 {
	ans := int64(1)
	for n > 0 {
		if n&1 == 1 {
			ans = (ans * x) % mo
		}
		x = (x * x) % mo
		n >>= 1
	}
	return ans
}

func revch(ch []byte) []byte {
	ret := make([]byte, len(ch))
	for i, j := len(ch)-1, 0; i >= 0; i, j = i-1, j+1 {
		ret[j] = ch[i]
	}
	return ret
}

func revint(ch []int) []int {
	ret := make([]int, len(ch))
	for i, j := len(ch)-1, 0; i >= 0; i, j = i-1, j+1 {
		ret[j] = ch[i]
	}
	return ret
}

func warshallFloyd(v [][]int, n int) {
	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				v[i][j] = min(v[i][j], v[i][k]+v[k][j])
			}
		}
	}
}

func modint(a, m int64) int64 {
	b, u, v := m, int64(1), int64(0)
	for b != 0 {
		t := a / b
		a -= t * b
		a, b = b, a
		u -= t * v
		u, v = v, u
	}
	u %= m
	if u < 0 {
		u += m
	}
	return u
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// 
