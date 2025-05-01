package main

import (
	"fmt"
	"container/list"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	q1 := list.New()
	q2 := list.New()

	for i := 1; i <= n; i++ {
		var temp int
		fmt.Scan(&temp)
		q1.PushBack(temp)
		q2.PushBack(i)
	}

	ans := 0
	for q1.Len() > 0 {
		if q1.Front().Value.(int) <= m {
			ans = q2.Front().Value.(int)
			q1.Remove(q1.Front())
			q2.Remove(q2.Front())
		} else {
			x := q1.Front().Value.(int)
			val := x - m
			q1.Remove(q1.Front())
			q1.PushBack(val)

			val2 := q2.Front().Value.(int)
			q2.Remove(q2.Front())
			q2.PushBack(val2)
		}
	}

	fmt.Println(ans)
}

// //End of Code
