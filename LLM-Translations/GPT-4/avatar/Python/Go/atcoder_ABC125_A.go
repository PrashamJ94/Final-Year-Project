package main
import "fmt"

func main() {
    var a int
    var b int
    var t int
    fmt.Scan(&a, &b, &t)

    cookie := 0
    time := float64(a)

    for time <= float64(t) + 0.5 {
        cookie += b
        time += float64(a)
    }
    
    fmt.Println(cookie)
}

// End of Code
