package main

import (
	"fmt"
	"math"
)

func main() {
	var A, B, H, M int
	fmt.Scan(&A, &B, &H, &M)

	mkaku := float64(M * 6)
	hkaku := float64(H*30) + float64(M)/2

	kaku := mkaku - hkaku
	dkaku := math.Abs(math.ToRadians(kaku))

	AA2 := float64(A * A)
	BB2 := float64(B * B)
	CC := AA2 + BB2
	DD := math.Cos(dkaku) * 2 * float64(A) * float64(B)

	ans2 := CC - DD
	ans := math.Sqrt(ans2)

	fmt.Println(ans)
}

// //End of Code
