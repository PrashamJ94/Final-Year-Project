
package main

import (
	"fmt"
	"strings"
	"strconv"
)

func main() {
	var input string
	fmt.Scanln(&input)
	pieces := make([][2]string, 0)
	inputs := strings.Split(input, " ")
	for i := 0; i < len(inputs); i += 2 {
		pieces = append(pieces, [2]string{inputs[i], inputs[i+1]})
	}
	fmt.Println(Bob_sMaxStrength(pieces))
}

func Bob_sMaxStrength(pieces [][2]string) int {
	pScore := 0
	sScore := 0
	pMaxScore := 0
	sMaxScore := 0
	for _, piece := range pieces {
		if piece[1] == "B" {
			value, _ := strconv.Atoi(piece[0])
			pScore += value
			if pScore > pMaxScore {
				pMaxScore = pScore
			}
		} else {
			value, _ := strconv.Atoi(piece[0])
			pScore -= value
		}
	}
	for i := len(pieces) - 1; i >= 0; i-- {
		if pieces[i][1] == "A" {
			value, _ := strconv.Atoi(pieces[i][0])
			sScore += value
			if sScore > sMaxScore {
				sMaxScore = sScore
			}
		} else {
			value, _ := strconv.Atoi(pieces[i][0])
			sScore -= value
		}
	}
	if pMaxScore > sMaxScore {
		return pMaxScore
	}
	return sMaxScore
}

// End of Code
