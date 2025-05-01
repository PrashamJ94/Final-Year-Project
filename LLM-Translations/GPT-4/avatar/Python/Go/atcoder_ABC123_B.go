package main

import (
	"fmt"
	"math"
	"sort"
)

type Meal struct {
	M int
	E int
}

func main() {
	var menu []Meal
	var m, e int
	for i := 0; i < 5; i++ {
		fmt.Scan(&m)
		e = m % 10
		if e == 0 {
			e = 10
		}
		menu = append(menu, Meal{M: m, E: e})
	}
	sort.Slice(menu, func(i, j int) bool {
		return menu[i].E < menu[j].E
	})
	ans := 0
	for _, meal := range menu[1:] {
		ans += int(math.Ceil(float64(meal.M)/10)) * 10
	}
	fmt.Println(ans + menu[0].M)
}
// End of Code.


Please note that the Go code does not behave exactly the same as the Python code. In Python, you are reading from standard input, while in the Go code you are scanning from standard input. In real-world usage, you would need to adapt the Go code for your specific use case.
