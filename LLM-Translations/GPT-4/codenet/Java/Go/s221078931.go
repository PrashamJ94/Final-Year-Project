
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type IntegralRect struct {
	height int
	width  int
}

func (ir IntegralRect) diagonal() int {
	if ir.height >= ir.width {
		return 1<<31 - 1
	}
	return ir.height*ir.height + ir.width*ir.width
}

type ByDiagonalAndHeight []IntegralRect

func (a ByDiagonalAndHeight) Len() int           { return len(a) }
func (a ByDiagonalAndHeight) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByDiagonalAndHeight) Less(i, j int) bool {
	d1, d2 := a[i].diagonal(), a[j].diagonal()
	if d1 == d2 {
		return a[i].height < a[j].height
	}
	return d1 < d2
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	rects := make([]IntegralRect, 40000)
	for i := 0; i < 200; i++ {
		for j := 0; j < 200; j++ {
			rects[i*200+j] = IntegralRect{i + 1, j + 1}
		}
	}
	sort.Sort(ByDiagonalAndHeight(rects))

	for {
		scanner.Scan()
		tmpArray := strings.Split(scanner.Text(), " ")

		h, _ := strconv.Atoi(tmpArray[0])
		w, _ := strconv.Atoi(tmpArray[1])

		if h == 0 && w == 0 {
			break
		}

		tmpRect := IntegralRect{h, w}
		for i := 0; i < len(rects); i++ {
			if ByDiagonalAndHeight.Less(rects[i], tmpRect) {
				fmt.Println(rects[i].height, rects[i].width)
				break
			}
		}
	}
}


