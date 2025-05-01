Here is the translated Go code from the provided Java code:


package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(readLine(reader))
    answer := make([]int, n)
    left := make(map[int]bool)
    for i := 0; i < n; i++ {
        left[i] = true
    }
    q, _ := strconv.Atoi(readLine(reader))
    for q > 0 {
        parts := strings.Split(readLine(reader), " ")
        l, _ := strconv.Atoi(parts[0])
        r, _ := strconv.Atoi(parts[1])
        win, _ := strconv.Atoi(parts[2])
        for i := l - 1; i <= r-1 && left[i]; i++ {
            answer[i] = win
            delete(left, i)
        }
        answer[win-1] = 0
        left[win-1] = true
        q--
    }
    var ans strings.Builder
    for i := 0; i < n; i++ {
        ans.WriteString(strconv.Itoa(answer[i]))
    }
    fmt.Println(ans.String())
}

func readLine(reader *bufio.Reader) string {
    str, _ := reader.ReadString('\n')
    return strings.Trim(str, "\n")
}

// //End of Code
