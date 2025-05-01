package main
import (
    "fmt"
    "sort"
)

type item struct {
    S, R, H, C, index int
}

func main() {
    var n int
    fmt.Scan(&n)
    inputArray := make([]item, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&inputArray[i].S, &inputArray[i].R, &inputArray[i].H, &inputArray[i].C)
        inputArray[i].index = i + 1
    }
    sort.Slice(inputArray, func(i, j int) bool {
        return inputArray[i].C < inputArray[j].C
    })
    minimumCost := 100000
    inputNumber := 0
    for _, current_item := range inputArray {
        if current_item.C > minimumCost {
            break
        }
        outdated := false
        for _, other_item := range inputArray {
            if other_item.S > current_item.S && other_item.R > current_item.R && other_item.H > current_item.H {
                outdated = true
                break
            }
        }
        if !outdated {
            minimumCost = current_item.C
            inputNumber = current_item.index
            break
        }
    }
    fmt.Println(inputNumber)
} // End of Code
