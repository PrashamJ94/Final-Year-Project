package main

import (
	"fmt"
	"strconv"
)

func main() {
	var strn string
	fmt.Scan(&strn)
	n, _ := strconv.Atoi(strn)
	shichigolist := []string{"3", "5", "7"}
	shichigo := make([][]string, len(strn))
	for i := 0; i < len(strn); i++ {
		if i == 0 {
			for _, j := range shichigolist {
				shichigo[i] = append(shichigo[i], j)
			}
		} else {
			for _, j := range shichigo[i-1] {
				for _, k := range shichigolist {
					shichigo[i] = append(shichigo[i], j+k)
				}
			}
		}
	}
	target := len(strn) - 1
	for i := 0; i < len(strn); i++ {
		for _, j := range shichigo[i] {
			if i == target {
				num, _ := strconv.Atoi(j)
				if num > n || !containsAll(j, "3", "5", "7") {
					shichigo[target] = remove(shichigo[target], j)
				}
			} else {
				if !containsAll(j, "3", "5", "7") {
					shichigo[i] = remove(shichigo[i], j)
				}
			}
		}
	}

	result := 0
	for i := 0; i < len(strn); i++ {
		result += len(shichigo[i])
	}
	fmt.Println(result)
}

func containsAll(s string, chars ...string) bool {
	for _, char := range chars {
		if !contains(s, char) {
			return false
		}
	}
	return true
}

func contains(s, substr string) bool {
	return len(s) >= len(substr) && s[0:len(substr)] == substr
}

func remove(slice []string, s string) []string {
	index := -1
	for i, item := range slice {
		if item == s {
			index = i
			break
		}
	}
	if index >= 0 {
		return append(slice[:index], slice[index+1:]...)
	}
	return slice
}

// 
