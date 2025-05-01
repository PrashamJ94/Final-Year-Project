package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)
	dotIndex := strings.Index(str, ".")

	if str[dotIndex-1] == '9' {
		fmt.Println("GOTO Vasilisa.")
	} else if str[dotIndex+1]-'0' > 4 {
		_str := str[0:dotIndex]
		n, _ := strconv.Atoi(_str)
		bigNum := big.NewInt(int64(n))
		bigNum.Add(bigNum, big.NewInt(1))
		fmt.Println(bigNum.String())
	} else {
		fmt.Println(str[0:dotIndex])
	}
}

// //End of Code.
