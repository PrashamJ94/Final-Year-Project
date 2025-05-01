package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	
	scanner.Scan()
	N, _ := strconv.Atoi(scanner.Text())
	a := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}
	
	leftl := make([]int, N)
	rightl := make([]int, N)
	que := []int{}
	index := 0
	
	for index < N {
		for len(que) > 0 && a[que[0]] > a[index] {
			ind := que[0]
			que = que[1:]
			rightl[ind] = index - ind - 1
		}
		que = append([]int{index}, que...)
		index++
	}
	
	for len(que) > 0 {
		ind := que[0]
		que = que[1:]
		rightl[ind] = N - ind - 1
	}
	
	index = N - 1
	
	for index >= 0 {
		for len(que) > 0 && a[que[0]] > a[index] {
			ind := que[0]
			que = que[1:]
			leftl[ind] = ind - index - 1
		}
		que = append([]int{index}, que...)
		index--
	}
	
	for len(que) > 0 {
		ind := que[0]
		que = que[1:]
		leftl[ind] = ind
	}
	
	ans := int64(0)
	for i := 0; i < N; i++ {
		ans += int64(a[i]) * int64(leftl[i]+1) * int64(rightl[i]+1)
	}
	
	fmt.Println(ans)
}

// //End of Code.
