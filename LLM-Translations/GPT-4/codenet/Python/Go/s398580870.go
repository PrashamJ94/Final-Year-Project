package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scanf("%d %d", &n, &k)
	if k%2 == 1 {
		fmt.Println((n / k) * (n / k) * (n / k))
	} else {
		fmt.Println((n/k)*(n/k)*(n/k) + ((n+k/2)/k)*((n+k/2)/k)*((n+k/2)/k))
	}
}
// 
