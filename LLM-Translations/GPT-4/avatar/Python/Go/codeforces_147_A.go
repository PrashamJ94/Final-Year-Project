
package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scanln(&s)

	res := []string{}
	punctuation := []string{",", ".", "!", "?"}

	for i := 0; i < len(s); i++ {
		if i >= 1 {
			if string(s[i]) == "" {
				if res[len(res)-1] != "" {
					res = append(res, string(s[i]))
				}
			} else {
				if strings.Contains(strings.Join(punctuation, ""), string(s[i])) {
					if res[len(res)-1] == "" {
						res = res[:len(res)-1]
					}
					res = append(res, string(s[i]))
					res = append(res, "")
				} else {
					res = append(res, string(s[i]))
				}
			}
		} else {
			if string(s[i]) == "" {
				continue
			}
			if strings.Contains(strings.Join(punctuation, ""), string(s[i])) {
				continue
			} else {
				res = append(res, string(s[i]))
			}
		}
	}
	fmt.Println(strings.Join(res, ""))
}
// End of Code


Please note that this is a direct translation, and Go has a different approach and best practices for handling strings and arrays. The code in Python may not behave exactly the same in Go due to language differences. The Go version of the code is also more verbose because Go is statically typed and does not have some of the Python's concise syntax.
