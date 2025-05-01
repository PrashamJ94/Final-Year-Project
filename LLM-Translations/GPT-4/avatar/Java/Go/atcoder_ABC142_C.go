package main

import (
	"fmt"
	"sort"
)

type Student struct {
	ID    int
	Order int
}

func main() {
	var N int
	fmt.Scan(&N)

	students := make([]Student, N)

	for i := 0; i < N; i++ {
		var A int
		fmt.Scan(&A)
		students[A-1] = Student{ID: i + 1}
	}

	for i := 0; i < N; i++ {
		students[i].Order = i + 1
	}

	sort.Slice(students, func(i, j int) bool {
		return students[i].ID < students[j].ID
	})

	for i := 0; i < N; i++ {
		fmt.Print(students[i].Order, " ")
	}
}

// //End of Code
