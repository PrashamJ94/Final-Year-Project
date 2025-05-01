
package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	var a = make([]float64, n)
	for i:= 0; i < n; i++ {
		fmt.Scanf("%f", &a[i])
	}
	var sum float64 = 0
	for _, v := range a {
		sum += v
	}
	if int(sum)%(n*(n+1)/2) != 0 {
		fmt.Println("NO")
	} else {
		var k = sum / float64(n*(n+1)/2)
		a = append(a, a[0])
		var sum1 float64 = 0
		var sum2 float64 = 0
		for i:=0; i<len(a)-1; i++ {
			sum1 += float64(int(k) - int(a[i+1]) + int(a[i])) % float64(n)
			sum2 += float64(int(k) - int(a[i+1]) + int(a[i])) / float64(n)
		}
		if int(sum1) != 0 || int(sum2) != n {
			fmt.Println("NO")
		} else {
			fmt.Println("YES")
		}
	}
}
// End of Code


Please note the above code is a direct translation of your Python code into Go. It assumes you are entering the number of elements (n) and the array elements (a) through the console.
