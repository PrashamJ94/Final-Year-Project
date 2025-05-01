
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	s, _ := r.ReadString('\n')
	fmt.Printf("%c", s[0]+1)
}

type RemRing struct {
	module int64
}

func NewRemRing(module int64) *RemRing {
	return &RemRing{module}
}

func (rr *RemRing) sum(a, b int64) int64 {
	return (a + b + rr.module) % rr.module
}

func (rr *RemRing) sub(a, b int64) int64 {
	return (a - b + rr.module) % rr.module
}

func (rr *RemRing) prod(a, b int64) int64 {
	return (a * b) % rr.module
}

func (rr *RemRing) div(a, b int64) int64 {
	return (a * rr.inv(b)) % rr.module
}

func (rr *RemRing) inv(a int64) int64 {
	b := rr.module
	u := int64(1)
	v := int64(0)
	for b > 0 {
		t := a / b
		a -= t * b
		u -= t * v
		z := a
		a = b
		b = z
		z = u
		u = v
		v = z
	}
	u %= rr.module
	if u < 0 {
		u += rr.module
	}
	return u
}
// //End of Code


