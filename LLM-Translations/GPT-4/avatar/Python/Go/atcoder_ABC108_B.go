package main
import (
	"fmt"
	"strconv"
	"strings"
	"bufio"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	p, _ := reader.ReadString('\n')
	p = strings.TrimSuffix(p, "\n")
	coordinates := strings.Split(p, " ")
	x1, _ := strconv.Atoi(coordinates[0])
	y1, _ := strconv.Atoi(coordinates[1])
	x2, _ := strconv.Atoi(coordinates[2])
	y2, _ := strconv.Atoi(coordinates[3])
	DIF1 := x2 - x1
	DIF2 := y2 - y1
	x3 := x2 - DIF2
	y3 := y2 + DIF1
	x4 := x1 - DIF2
	y4 := y1 + DIF1
	fmt.Printf("%d %d %d %d\n", x3, y3, x4, y4)
}

// End of Code
