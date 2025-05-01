package main

import (
	"fmt"
	"time"
)

func main() {
	var s, t string
	fmt.Scan(&s, &t)

	x, _ := time.Parse("15:04", s)
	y, _ := time.Parse("15:04", t)

	xd := x.Hour()*60 + x.Minute()
	yd := y.Hour()*60 + y.Minute()

	diff := xd - yd
	if diff < 0 {
		diff += 24 * 60
	}

	hours := diff / 60
	minutes := diff % 60

	fmt.Printf("%02d:%02d\n", hours, minutes)
}

// //End of Code
