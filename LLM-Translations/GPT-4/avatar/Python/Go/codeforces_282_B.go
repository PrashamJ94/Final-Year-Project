package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	var firstline int
	fmt.Scan(&firstline)
	total := 0
	memory := make([]string, 0)
	reader := bufio.NewReader(os.Stdin)
	
	for x := 0; x < firstline; x++ {
		input, _ := reader.ReadString('\n')
		nums := strings.Fields(input)
		A, _ := strconv.Atoi(nums[0])
		G, _ := strconv.Atoi(nums[1])
		
		if total + A <= 500 {
			total += A
			memory = append(memory, "A")
		} else {
			total -= G
			memory = append(memory, "G")
		}
	}
	fmt.Println(strings.Join(memory, ""))
}
// End of Code
