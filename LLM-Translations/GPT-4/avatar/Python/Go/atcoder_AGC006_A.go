
package main
import (
	"fmt"
	"bufio"
	"os"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n := scanner.Text()
	scanner.Scan()
	s := strings.Split(scanner.Text(), "")
	scanner.Scan()
	t := strings.Split(scanner.Text(), "")
	cnt := 0
	if strings.Join(s, "") == strings.Join(t, "") {
		fmt.Println(n)
	} else {
		for i := 0; i < len(s); i++ {
			for j := 0; j < len(s) - i; j++ {
				if s[i + j] != t[j] {
					break
				}
				if j == len(s) - i - 1 {
					cnt = len(s) - i
				}
			}
		}
		fmt.Println(2 * len(s) - cnt)
	}
}
// End of Code

Please note that error checking has been omitted for brevity. It's recommended to handle errors in your actual code appropriately.
