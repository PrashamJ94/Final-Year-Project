package main

import "fmt"

func main() {
	var hcell, wcell, hpaint, wpaint, nblack, nwhite int
	//順にマス行、マス列、塗る行、塗る列、塗られたマス、白いマス
	fmt.Scan(&hcell, &wcell)
	fmt.Scan(&hpaint, &wpaint)
	nblack = (wcell * hpaint) + (hcell * wpaint) - (hpaint * wpaint)
	nwhite = (hcell * wcell) - nblack
	fmt.Printf("%d\n", nwhite)
}

// 
