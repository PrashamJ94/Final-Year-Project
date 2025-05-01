
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	m := readInt(scanner)
	n := readInt(scanner)
	manju := make([]int, m)
	for i := 0; i < m; i++ {
		manju[i] = readInt(scanner)
	}
	boxlen := make([]int, n)
	boxcost := make([]int, n)
	for i := 0; i < n; i++ {
		boxlen[i] = readInt(scanner)
		boxcost[i] = readInt(scanner)
	}

	sort.Ints(manju)

	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}

	for i := m - 1; i >= 0; i-- {
		for j := n - 1; j >= 0; j-- {
			len := int(math.Min(float64(i+boxlen[j]), float64(m)))
			cnt := 0
			for k := i; k < len; k++ {
				cnt += manju[m-1-k]
			}
			dp[i][j] = int(math.Max(float64(dp[i][j]), float64(dp[len][j+1]+cnt-boxcost[j])))
			dp[i][j] = int(math.Max(float64(dp[i][j]), float64(dp[i][j+1])))
		}
	}

	fmt.Println(dp[0][0])
}

func readInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	res, _ := strconv.Atoi(scanner.Text())
	return res
}


