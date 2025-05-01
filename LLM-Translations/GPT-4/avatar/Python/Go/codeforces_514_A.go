
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var ip string
	fmt.Scan(&ip)

	st := ""
	if len(ip) != 1 {
		if string(ip[0]) == "9" {
			st = "9"
			ip = ip[1:]
		}
		for _, i := range ip {
			num, _ := strconv.Atoi(string(i))
			if num > 4 {
				n := 9 - num
				st += strconv.Itoa(n)
			} else {
				st += string(i)
			}
		}
	} else {
		st = ip
	}

	fmt.Println(st)
}
// End of Code


The Go code does a similar job as the Python code you provided. It takes a string input, checks each digit, and if the digit is larger than 4, it subtracts it from 9 and appends the result to the new string. If the digit is less than or equal to 4, it appends the digit to the new string. If the input string only has a length of 1, it skips the process and directly assigns the input to the new string. At the end, it prints out the new string.
