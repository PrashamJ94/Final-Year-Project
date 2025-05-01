package main

import (
	"fmt"
	"strconv"
)

func main() {
	var h, w, ka int
	fmt.Scan(&h, &w, &ka)

	mat := make([]string, h)
	for i := 0; i < h; i++ {
		fmt.Scan(&mat[i])
	}

	ans := 0
	for i := 0; i < (1 << (h + w)); i++ {
		b := strconv.FormatInt(int64(i), 2)
		b = fmt.Sprintf("%0*s", h+w, b)
		rs := b[:h]
		cs := b[h:]
		ct := 0
		for l := 0; l < h; l++ {
			for k := 0; k < w; k++ {
				if mat[l][k] == '#' && rs[l] == '0' && cs[k] == '0' {
					ct++
				}
			}
		}
		if ct == ka {
			ans++
		}
	}
	fmt.Println(ans)
}

// 
