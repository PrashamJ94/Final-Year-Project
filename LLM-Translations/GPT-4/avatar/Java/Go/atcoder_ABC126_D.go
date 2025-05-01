
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Point struct {
	name    int
	friends map[*Point]int
}

func NewPoint(name int) *Point {
	return &Point{
		name:    name,
		friends: make(map[*Point]int),
	}
}

func (p *Point) BecomeFriend(p2 *Point, length int) {
	p.friends[p2] = length
}

var colors []int

func dfs(p *Point, length int) {
	if colors[p.name] != -1 {
		return
	}
	if length%2 == 0 {
		colors[p.name] = 0
	} else {
		colors[p.name] = 1
	}
	for friend, length2 := range p.friends {
		dfs(friend, length+length2)
	}
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	m := n - 1
	colors = make([]int, n)
	for i := range colors {
		colors[i] = -1
	}
	points := make([]*Point, n)
	for i := range points {
		points[i] = NewPoint(i)
	}
	for m > 0 {
		sc.Scan()
		fields := strings.Fields(sc.Text())
		me, _ := strconv.Atoi(fields[0])
		you, _ := strconv.Atoi(fields[1])
		length, _ := strconv.Atoi(fields[2])
		me--
		you--
		points[me].BecomeFriend(points[you], length)
		points[you].BecomeFriend(points[me], length)
		m--
	}
	dfs(points[0], 0)
	for _, c := range colors {
		fmt.Println(c)
	}
}

// //End of Code


