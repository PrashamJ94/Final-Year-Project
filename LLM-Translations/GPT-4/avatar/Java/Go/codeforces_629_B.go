
package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	
	FfriendPerDay := make([]int, 367)
	MfriendPerDay := make([]int, 367)
	answer := 0
	
	for i := 0; i < n; i++ {
		var c byte
		var a, b int
		fmt.Scanf("%c %d %d\n", &c, &a, &b)
		
		for j := a; j <= b; j++ {
			if c == 'M' {
				MfriendPerDay[j]++
			} else {
				FfriendPerDay[j]++
			}
			if MfriendPerDay[j] < FfriendPerDay[j] {
				if MfriendPerDay[j] > answer {
					answer = MfriendPerDay[j]
				}
			} else {
				if FfriendPerDay[j] > answer {
					answer = FfriendPerDay[j]
				}
			}
		}
	}
	fmt.Println(answer * 2)
}

// //End of Code


This Go code does the same thing as the Java code. It reads n from the input, then loops n times reading a character and two integers each time. Depending on the value of the character, it increments the corresponding element of one of the two arrays. It then compares the two arrays, and if one value is smaller than the other, it checks if the smaller value is larger than the current answer, and if so, updates the answer. Finally, it prints twice the answer. Note that the Go code uses `fmt.Scan` and `fmt.Scanf` for reading input, and `fmt.Println` for output.
