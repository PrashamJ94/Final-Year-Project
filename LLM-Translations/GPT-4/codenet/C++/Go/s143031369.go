
package main

import (
	"fmt"
	"math"
	"sort"
)

const eps = 1e-8

type Point struct {
	x, y float64
}

func sig(d float64) int {
	if math.Abs(d) < eps {
		return 0
	}
	if d < 0 {
		return -1
	}
	return 1
}

func dot(o, a, b Point) float64 {
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y)
}

func cross(o, a, b Point) float64 {
	return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y)
}

func btw(x, a, b Point) int {
	return sig(dot(x, a, b))
}

func dis(a, b Point) float64 {
	return math.Sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))
}

func cos(o, a, b Point) float64 {
	return dot(o, a, b) / dis(o, a) / dis(o, b)
}

func jarvis(p []Point, n int) []int {
	ch := make([]int, n)
	minIdx := 0
	for i := 1; i < n; i++ {
		if p[i].x < p[minIdx].x {
			minIdx = i
		}
	}
	ch[0] = minIdx
	l := minIdx
	d := 1
	for {
		o := l
		for i := 0; i < n; i++ {
			t := sig(cross(p[o], p[l], p[i]))
			if t > 0 || (t == 0 && btw(p[l], p[o], p[i]) <= 0) {
				l = i
			}
		}
		ch[d] = l
		d++
		if l == ch[0] {
			break
		}
	}
	return ch[:d-1]
}

func main() {
	var n, xx, yy int
	fmt.Scan(&n)
	p := make([]Point, n)
	ang := make([]float64, n)
	ans := make([]float64, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&xx, &yy)
		p[i] = Point{float64(xx), float64(yy)}
	}

	if n == 2 {
		fmt.Println("0.5")
		fmt.Println("0.5")
	} else {
		ch := jarvis(p, n)
		if len(ch) == 2 {
			ans[ch[0]] = 0.5
			ans[ch[1]] = 0.5
		} else {
			for _, idx := range ch {
				i := sort.SearchInts(ch, (idx-1+len(ch))%len(ch))
				j := sort.SearchInts(ch, (idx+1)%len(ch))
				ang[idx] = math.Pi - math.Acos(cos(p[idx], p[ch[i]], p[ch[j]]))
			}
			for i := 0; i < n; i++ {
				ans[i] = ang[i] / 2.0 / math.Pi
			}
		}
		for i := 0; i < n; i++ {
			fmt.Printf("%.20f\n", ans[i])
		}
	}
}


