package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var inp int
	fmt.Scan(&inp)

	var listaStr string
	fmt.Scan(&listaStr)

	listaSplit := strings.Split(listaStr, " ")
	lista := make([]int, len(listaSplit))

	for i, v := range listaSplit {
		lista[i], _ = strconv.Atoi(v)
	}

	for i := range lista {
		if i == 0 {
			fmt.Printf("%d %d\n", lista[i+1]-lista[i], lista[len(lista)-1]-lista[i])
			continue
		} else if i == len(lista)-1 {
			fmt.Printf("%d %d\n", lista[len(lista)-1]-lista[len(lista)-2], lista[len(lista)-1]-lista[0])
			continue
		} else if lista[i]-lista[i-1] > lista[i+1]-lista[i] {
			fmt.Printf("%d ", lista[i+1]-lista[i])
		} else {
			fmt.Printf("%d ", lista[i]-lista[i-1])
		}

		if lista[len(lista)-1]-lista[i] > lista[i]-lista[0] {
			fmt.Printf("%d\n", lista[len(lista)-1]-lista[i])
		} else {
			fmt.Printf("%d\n", lista[i]-lista[0])
		}
	}
} // End of Code

