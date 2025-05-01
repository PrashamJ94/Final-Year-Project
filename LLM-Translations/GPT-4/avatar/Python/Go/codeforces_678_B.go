package main

import (
    "fmt"
    "bufio"
    "os"
    "strconv"
)

func leapyear(n int) string {
    if n % 400 == 0 || (n % 4 == 0 && n % 100 != 0) {
        return "y"
    } else {
        return "n"
    }
}

func main() {
    reader := bufio.NewReader(os.Stdin)
    input, _ := reader.ReadString('\n')
    n, _ := strconv.Atoi(input[:len(input)-1])
    d := "f"
    var ans string
    if n % 400 == 0 || (n % 4 == 0 && n % 100 != 0) {
        ans = "ly"
    } else {
        ans = "nly"
    }
    for {
        if n % 400 == 0 || (n % 4 == 0 && n % 100 != 0) {
            switch d {
            case "m", "t", "w", "th", "f", "sa", "s":
                d = map[string]string{"m": "t", "t": "w", "w": "th", "th": "f", "f": "sa", "sa": "s", "s": "m"}[d]
                n += 1
            }
        } else {
            switch d {
            case "m", "t", "w", "th", "f", "sa", "s":
                d = map[string]string{"m": "t", "t": "w", "w": "th", "th": "f", "f": "sa", "sa": "s", "s": "m"}[d]
                n += 1
            }
        }
        if (d == "f" && ans == "ly" && leapyear(n) == "y") || (d == "f" && ans == "nly" && leapyear(n) == "n") {
            break
        }
    }
    fmt.Println(n)
}

// End of Code.
