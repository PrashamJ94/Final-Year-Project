
package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	NM := strings.Split(scanner.Text(), " ")
	N, _ := strconv.Atoi(NM[0])
	M, _ := strconv.Atoi(NM[1])
	balls := make([][]int, N)
	for i := 0; i < N; i++ {
		balls[i] = []int{1, 0}
	}
	balls[0] = []int{0, 1}
	for i := 0; i < M; i++ {
		scanner.Scan()
		xy := strings.Split(scanner.Text(), " ")
		x, _ := strconv.Atoi(xy[0])
		y, _ := strconv.Atoi(xy[1])
		wX, rX := balls[x-1][0], balls[x-1][1]
		wY, rY := balls[y-1][0], balls[y-1][1]
		if wX >= 1 && rX >= 1 {
			balls[x-1][0] -= 1
			balls[y-1][1] += 1
		} else if wX == 0 {
			balls[x-1][1] -= 1
			balls[y-1][1] += 1
		} else {
			balls[x-1][0] -= 1
			balls[y-1][0] += 1
		}
	}
	ans := 0
	for i := 0; i < N; i++ {
		if balls[i][1] != 0 {
			ans += 1
		}
	}
	fmt.Println(ans)
}
//End of Code


