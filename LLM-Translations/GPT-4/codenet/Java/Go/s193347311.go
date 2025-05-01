package main

import (
	"fmt"
	"strings"
	"bufio"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	var intLoop int
	fmt.Scan(&intLoop)
	strTaro := ""
	strHana := ""
	intTaro := 0
	intHana := 0

	for i := 0; i < intLoop; i++ {
		scanner.Scan()
		strTaro = scanner.Text()
		scanner.Scan()
		strHana = scanner.Text()
		intJudge := strings.Compare(strTaro, strHana)
		if intJudge < 0 {
			intHana += 3
		} else if intJudge == 0 {
			intTaro++
			intHana++
		} else if 0 < intJudge {
			intTaro += 3
		}
	}
	fmt.Println(intTaro, intHana)
}
// 
