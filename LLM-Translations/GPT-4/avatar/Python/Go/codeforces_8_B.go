package main

import "fmt"

func main() {
	var record_of_movements string
	fmt.Scanln(&record_of_movements)

	x, y := 0, 0
	d_movement := map[rune][2]int{'L': [2]int{0, -1}, 'R': [2]int{0, 1}, 'U': [2]int{1, 0}, 'D': [2]int{-1, 0}}
	d := make(map[[2]int]string)
	d[[2]int{x, y}] = ""
	bug := false

	for _, move := range record_of_movements {
		temp := [2]int{x, y}
		x += d_movement[rune(move)][0]
		y += d_movement[rune(move)][1]

		if _, ok := d[[2]int{x, y}]; !ok {
			for _, step := range d_movement {
				nextX := x + step[0]
				nextY := y + step[1]
				if (nextX != temp[0] || nextY != temp[1]) && d[[2]int{nextX, nextY}] == "" {
					bug = true
					break
				}
			}
		} else {
			bug = true
		}

		if bug {
			break
		}

		d[[2]int{x, y}] = ""
	}

	if bug {
		fmt.Println("BUG")
	} else {
		fmt.Println("OK")
	}
}
//End of Code
