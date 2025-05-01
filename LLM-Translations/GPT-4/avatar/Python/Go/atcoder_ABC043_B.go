package main

import (
    "fmt"
    "bufio"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter text: ")
    text, _ := reader.ReadString('\n')

    result := ""
    for _, c := range text {
        if c == '0' || c == '1' {
            result += string(c)
        } else if c == 'B' && len(result) != 0 {
            result = result[:len(result)-1]
        }
    }
    fmt.Println(result)
}
// End of Code
