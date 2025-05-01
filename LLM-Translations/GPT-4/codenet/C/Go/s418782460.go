
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	maxString  = 30
	maxLine    = 2000000
	maxHuman   = 200000
)

var (
	sLongInputLine = make([]byte, maxLine+1)
	anComingSec    = make([]int, maxHuman)
)

func main() {

	var (
		sInput              string
		psInput             string
		nHumanNumber        int
		nNextHumanIndex     int
		nWaterLength        int
		nWaterLife          int
		nStart              int
		nStop               int
		nIndex              int
		i                   int
		j                   int
	)

	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	sInput = scanner.Text()
	sInput = strings.TrimSuffix(sInput, "\n")
	psInputSlice := strings.Split(sInput, " ")
	nHumanNumber, _ = strconv.Atoi(psInputSlice[0])
	nWaterLength, _ = strconv.Atoi(psInputSlice[1])

	scanner.Scan()
	sLongInputLine = []byte(scanner.Text())
	sLongInputLine = []byte(strings.TrimSuffix(string(sLongInputLine), "\n"))
	psInput = string(sLongInputLine)
	psInputSlice = strings.Split(psInput, " ")
	for i = 0; i < nHumanNumber; i++ {
		anComingSec[i], _ = strconv.Atoi(psInputSlice[i])
	}

	nStart = anComingSec[0]

	for nNextHumanIndex < nHumanNumber {
		if nNextHumanIndex == nHumanNumber {
			break
		} else {
			nStop = nStart + nWaterLength
			if anComingSec[nNextHumanIndex] < nStop {
				for nNextHumanIndex < nHumanNumber && anComingSec[nNextHumanIndex] < nStop {
					if nStop <= anComingSec[nNextHumanIndex]+nWaterLength {
						nStop = anComingSec[nNextHumanIndex] + nWaterLength
						nNextHumanIndex++
					}
				}
				if nNextHumanIndex == nHumanNumber {
					nWaterLife = nWaterLife + (nStop - nStart)
					break
				}
			}
			nWaterLife = nWaterLife + (nStop - nStart)
			nStart = nStop
			if nStart < anComingSec[nNextHumanIndex] {
				nStart = anComingSec[nNextHumanIndex]
			}
		}
	}
	fmt.Printf("%d\n", nWaterLife)

}

// 
