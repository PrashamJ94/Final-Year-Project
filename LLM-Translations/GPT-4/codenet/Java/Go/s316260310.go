package main

import (
	"bufio"
	"fmt"
	"io"
	"math/big"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := NewReader(bufio.NewReader(os.Stdin))
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	tc := 1
	for tce := 1; tce <= tc; tce++ {
		N, _ := reader.ReadInt()
		K, _ := reader.ReadInt64()
		A, _ := reader.ReadIntArray(N)

		straight := make([]int, 0)
		cycle := make([]int, 0)
		vis := make([]bool, N)
		curr := 0
		for !vis[curr] {
			vis[curr] = true
			curr = A[curr] - 1
		}

		st := 0
		for st != curr {
			straight = append(straight, st)
			st = A[st] - 1
		}

		cycle = append(cycle, curr)
		curr = A[curr] - 1
		for curr != cycle[0] {
			cycle = append(cycle, curr)
			curr = A[curr] - 1
		}

		if K < int64(len(straight)) {
			fmt.Fprintln(writer, straight[K]+1)
		} else {
			K -= int64(len(straight))
			fmt.Fprintln(writer, cycle[K%int64(len(cycle))]+1)
		}
	}
}

type Reader struct {
	reader *bufio.Reader
}

func NewReader(reader *bufio.Reader) *Reader {
	return &Reader{reader}
}

func (r *Reader) ReadInt() (int, error) {
	str, err := r.reader.ReadString(' ')
	if err != nil && err != io.EOF {
		return 0, err
	}
	n, err := strconv.Atoi(strings.TrimSpace(str))
	if err != nil {
		return 0, err
	}
	return n, nil
}

func (r *Reader) ReadInt64() (int64, error) {
	str, err := r.reader.ReadString(' ')
	if err != nil && err != io.EOF {
		return 0, err
	}
	n, err := strconv.ParseInt(strings.TrimSpace(str), 10, 64)
	if err != nil {
		return 0, err
	}
	return n, nil
}

func (r *Reader) ReadIntArray(size int) ([]int, error) {
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		num, err := r.ReadInt()
		if err != nil {
			return nil, err
		}
		arr[i] = num
	}
	return arr, nil
}

func (r *Reader) ReadInt64Array(size int) ([]int64, error) {
	arr := make([]int64, size)
	for i := 0; i < size; i++ {
		num, err := r.ReadInt64()
		if err != nil {
			return nil, err
		}
		arr[i] = num
	}
	return arr, nil
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func pow(base, exp, mod int64) int64 {
	base %= mod
	ret := int64(1)
	for exp > 0 {
		if exp&1 == 1 {
			ret = (ret * base) % mod
		}
		base = (base * base) % mod
		exp >>= 1
	}
	return ret
}

// 
