package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var str string
	for {
		_, err := fmt.Scan(&str)
		if err != nil {
			break
		}
		strArr := strings.Split(str, ",")
		l := make([]int, 10)
		d := 0
		for i := 0; i < 10; i++ {
			l[i], _ = strconv.Atoi(strArr[i])
			d += l[i]
		}
		v := []int{toInt(strArr[10]), toInt(strArr[11])}
		t := float64(d) / float64(v[0]+v[1])
		d = 0
		for i := 0; i < 11; i++ {
			if float64(v[0])*t <= float64(d) {
				fmt.Println(i)
				break
			} else {
				d += l[i]
			}
		}
	}
}

func toInt(s string) int {
	i, err := strconv.Atoi(s)
	if err != nil {
		return 0
	}
	return i
}

// 
