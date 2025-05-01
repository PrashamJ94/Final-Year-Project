
package main

import (
	"fmt"
	"math"
)

const (
	INF int64 = 1e9
	h   int   = 19
	w   int   = 15
)

var (
	dx = []int{0, 1, 0, -1, 1, 1, -1, -1}
	dy = []int{1, 0, -1, 0, 1, -1, 1, -1}
	s  = make([]string, 19)
)

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int64) int64 {
	return a / gcd(a, b) * b
}

func dfs(x, y, cnt int, ans *int64) {
	if cnt > 20 {
		return
	}
	if x == h-1 {
		*ans = int64(math.Min(float64(*ans), float64(cnt)))
		return
	}
	for i := 0; i < 8; i++ {
		nx := x + dx[i]
		ny := y + dy[i]
		if nx < 0 || nx >= h || ny < 0 || ny >= w {
			continue
		}
		if s[nx][ny] != 'X' {
			continue
		}
		c := true
		for c && s[nx][ny] == 'X' {
			s[nx] = s[nx][:ny] + "." + s[nx][ny+1:]
			nx += dx[i]
			ny += dy[i]
			if nx < 0 || nx >= h || ny < 0 || ny >= w {
				if nx >= h {
					*ans = int64(math.Min(float64(*ans), float64(cnt+1)))
				}
				c = false
			}
		}
		if c {
			dfs(nx, ny, cnt+1, ans)
		}
		for nx != x || ny != y {
			nx -= dx[i]
			ny -= dy[i]
			s[nx] = s[nx][:ny] + "X" + s[nx][ny+1:]
		}
		s[x] = s[x][:y] + "." + s[x][y+1:]
	}
}

func main() {
	for i := 0; i < h; i++ {
		fmt.Scan(&s[i])
	}
	var sx, sy int
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			if s[i][j] == 'O' {
				sx, sy = i, j
				s[i] = s[i][:j] + "." + s[i][j+1:]
			}
		}
	}
	ans := INF
	dfs(sx, sy, 0, &ans)
	if ans == INF {
		fmt.Println(-1)
	} else {
		fmt.Println(ans)
	}
}


