
package main

import (
	"fmt"
	"math"
	"os"
)

type ll = int64

func gcd(a, b ll) ll {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b ll) ll {
	return a / gcd(a, b) * b
}

func getPrimeFactor(n ll) map[ll]ll {
	res := make(map[ll]ll)
	for i := ll(2); i*i <= n; i++ {
		for n%i == 0 {
			res[i]++
			n /= i
		}
	}
	if n != 1 {
		res[n] = 1
	}
	return res
}

func isPrimeNumber(num ll) bool {
	if num <= 2 {
		return true
	} else if num%2 == 0 {
		return false
	}

	sqrtNum := math.Sqrt(float64(num))
	for i := 3; i <= int(sqrtNum); i += 2 {
		if num%ll(i) == 0 {
			return false
		}
	}

	return true
}

func modinv(a, m ll) ll {
	b, u, v := m, ll(1), ll(0)
	for b != 0 {
		t := a / b
		a -= t * b
		a, b = b, a
		u -= t * v
		u, v = v, u
	}
	u %= m
	if u < 0 {
		u += m
	}
	return u
}

func main() {
	var N, K ll
	fmt.Scan(&N, &K)

	A := make([]ll, N+1)
	for i := 1; i <= int(N); i++ {
		fmt.Scan(&A[i])
	}

	cur := ll(1)
	dic := make([]ll, N+1)
	for i := range dic {
		dic[i] = -1
	}
	flg := false
	for i := 1; i <= int(K); i++ {
		if dic[cur] < 0 || flg {
			dic[cur] = ll(i)
			cur = A[cur]
		} else if !flg {
			tmp := K - (dic[cur] - 1)
			tmp %= i - int(dic[cur])
			i = int(K) - tmp
			flg = true
		}
	}

	fmt.Println(cur)
	os.Exit(0)
}

// 
