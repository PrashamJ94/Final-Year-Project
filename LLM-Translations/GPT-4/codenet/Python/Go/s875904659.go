package main

import (
	"fmt"
	"strconv"
	"strings"
)

func bubbleSort(cards []string) []string {
	n := len(cards)
	for i := 0; i < n; i++ {
		for j := n - 1; j > i; j-- {
			if getInt(cards[j]) < getInt(cards[j-1]) {
				cards[j], cards[j-1] = cards[j-1], cards[j]
			}
		}
	}
	return cards
}

func selectionSort(cards []string) []string {
	n := len(cards)
	for i := 0; i < n; i++ {
		mini := i
		for j := i; j < n; j++ {
			if getInt(cards[j]) < getInt(cards[mini]) {
				mini = j
			}
		}
		if mini != i {
			cards[i], cards[mini] = cards[mini], cards[i]
		}
	}
	return cards
}

func getInt(card string) int {
	val, _ := strconv.Atoi(string(card[1]))
	return val
}

func main() {
	var n int
	fmt.Scan(&n)
	var input string
	fmt.Scan(&input)
	cards := strings.Split(input, " ")
	cards2 := make([]string, len(cards))
	copy(cards2, cards)

	bubbleSorted := bubbleSort(cards)
	fmt.Println(strings.Join(bubbleSorted, " "))
	fmt.Println("Stable")

	selectionSorted := selectionSort(cards2)
	fmt.Println(strings.Join(selectionSorted, " "))

	if strings.Join(selectionSorted, " ") == strings.Join(bubbleSorted, " ") {
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}
}
// 
