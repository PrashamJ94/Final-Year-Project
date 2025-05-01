package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type Point2D struct {
	x, y float64
}

type Vector struct {
	Point2D
}

const EPS = 1e-10

func NewPoint2D(x, y float64) *Point2D {
	return &Point2D{x, y}
}

func (p *Point2D) equals(a, b float64) bool {
	return math.Abs(a-b) < EPS
}

func (p *Point2D) sum(b *Point2D) *Point2D {
	return NewPoint2D(p.x+b.x, p.y+b.y)
}

func (p *Point2D) diff(b *Point2D) *Point2D {
	return NewPoint2D(p.x-b.x, p.y-b.y)
}

func (p *Point2D) multiple(k float64) *Point2D {
	return NewPoint2D(p.x*k, p.y*k)
}

func (p *Point2D) norm() float64 {
	return p.x*p.x + p.y*p.y
}

func (p *Point2D) abs(a *Point2D) float64 {
	return math.Sqrt(a.norm())
}

func NewVector(p *Point2D) *Vector {
	return &Vector{*p}
}

func (v *Vector) dot(a, b *Point2D) float64 {
	return a.x*b.x + a.y*b.y
}

func (v *Vector) cross(a, b *Point2D) float64 {
	return a.x*b.y - a.y*b.x
}

func judgeClockwise(p0, p1, p2 *Point2D) string {
	v := &Vector{}
	a := p1.diff(p0)
	b := p2.diff(p0)

	if v.cross(a, b) > EPS {
		return "COUNTER_CLOCKWISE"
	}
	if v.cross(a, b) < -EPS {
		return "CLOCKWISE"
	}
	if v.dot(a, b) < -EPS {
		return "ONLINE_BACK"
	}
	if a.norm() < b.norm() {
		return "ONLINE_FRONT"
	}

	return "ON_SEGMENT"
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	line := strings.Split(scanner.Text(), " ")
	p0 := NewPoint2D(parseFloat(line[0]), parseFloat(line[1]))
	p1 := NewPoint2D(parseFloat(line[2]), parseFloat(line[3]))

	scanner.Scan()
	q := parseInt(scanner.Text())

	for i := 0; i < q; i++ {
		scanner.Scan()
		line = strings.Split(scanner.Text(), " ")
		p2 := NewPoint2D(parseFloat(line[0]), parseFloat(line[1]))
		fmt.Println(judgeClockwise(p0, p1, p2))
	}
}

func parseFloat(s string) float64 {
	value, _ := strconv.ParseFloat(s, 64)
	return value
}

func parseInt(s string) int {
	value, _ := strconv.Atoi(s)
	return value
}

// 
