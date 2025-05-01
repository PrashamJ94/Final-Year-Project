package main

import (
	"fmt"
	"strings"
)

func main() {
	var s, t string
	fmt.Scan(&s, &t)

	freqs := make(map[rune]int)
	freqt := make(map[rune]int)

	var yay, whoops int

	for _, letra := range s {
		freqs[letra]++
	}

	for _, letra := range t {
		freqt[letra]++
	}

	for letra := range freqs {
		for freqs[letra] > 0 && freqt[letra] > 0 {
			yay++
			freqs[letra]--
			freqt[letra]--
		}
	}

	for letra := range freqs {
		for freqs[letra] > 0 {
			if strings.IsLower(string(letra)) && freqt[rune(strings.ToUpper(string(letra)))] > 0 {
				whoops++
				freqs[letra]--
				freqt[rune(strings.ToUpper(string(letra)))]--
			} else if strings.IsUpper(string(letra)) && freqt[rune(strings.ToLower(string(letra)))] > 0 {
				whoops++
				freqs[letra]--
				freqt[rune(strings.ToLower(string(letra)))]--
			} else {
				break
			}
		}
	}

	fmt.Println(yay, whoops)
}
// End of Code


Please note that in Go, strings are a sequence of bytes, which are not the same as characters. If you want to range over a string by characters (or "runes" in Go), you need to convert the string to a slice of runes.
