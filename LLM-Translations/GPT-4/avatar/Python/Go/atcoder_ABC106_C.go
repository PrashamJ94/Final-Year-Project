package main

import (
    "fmt"
    "bufio"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    s, _ := reader.ReadString('\n')
    s = strings.TrimSpace(s)
    kInput, _ := reader.ReadString('\n')
    k, _ := strconv.Atoi(strings.TrimSpace(kInput))

    l := 0
    for _, c := range s {
        if string(c) != "1" {
            break
        }
        l += 1
    }
    if l >= k {
        fmt.Println(1)
    } else {
        fmt.Println(string(s[l]))
    }
}
// End of Code
