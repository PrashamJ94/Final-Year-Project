package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n := scanner.Text()
	scanner.Scan()
	s := scanner.Text()
	words := strings.Fields(s)
	wordCount := make(map[string]int)
	for _, word := range words {
		wordCount[word]++
	}
	maxCount := 0
	var maxWord string
	for word, count := range wordCount {
		if count > maxCount {
			maxCount = count
			maxWord = word
		} else if count == maxCount {
			for i := len(words) - 1; i >= 0; i-- {
				if words[i] == word {
					maxWord = word
					break
				}
			}
		}
	}
	fmt.Println(maxWord)
}

// End of Code

This Go code does the same as your Python code. It reads from stdin to get the number of words and the words themselves. It counts the occurrences of each word and keeps track of the word with the maximum count, updating it whenever it finds a word with a count equal to the current maximum that appears later in the list.
