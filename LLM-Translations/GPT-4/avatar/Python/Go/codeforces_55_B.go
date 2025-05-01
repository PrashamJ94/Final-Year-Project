package main

import (
    "fmt"
    "strings"
    "strconv"
)

func rememberTheNumber(nums []int, i int, operations []string, ans *int) {
    if i >= 3 {
        return
    }
    for j := 0; j < 4; j++ {
        for k := j + 1; k < 4; k++ {
            if nums[j] != -1 && nums[k] != -1 {
                s := nums[j]
                nums[j] = -1
                t := nums[k]
                if operations[i] == "+" {
                    nums[k] = s + t
                } else if operations[i] == "*" {
                    nums[k] = s * t
                }
                if i == 2 && nums[k] < *ans {
                    *ans = nums[k]
                }
                rememberTheNumber(nums, i+1, operations, ans)
                nums[j] = s
                nums[k] = t
            }
        }
    }
}

func main() {
    var input string
    fmt.Scanln(&input)
    numsStr := strings.Split(input, " ")
    var nums []int
    for _, numStr := range numsStr {
        num, _ := strconv.Atoi(numStr)
        nums = append(nums, num)
    }

    fmt.Scanln(&input)
    operations := strings.Split(input, " ")

    ans := 10000000000000000000000000
    rememberTheNumber(nums, 0, operations, &ans)
    fmt.Println(ans)
}
// End of Code

