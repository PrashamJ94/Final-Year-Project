package com.example;
import math;


public void poly(Object xs: list, x: float){
    /*;
    Evaluates polynomial with coefficients xs at point x.;
    return xs{0} + xs{1} * x + xs{1} * x^2 + .... xs{n} * x^n;
    */
    return sum({coeff * math.pow(x, i) for i, coeff in enumerate(xs)});


}
public void find_zero(xs: list){
    /* xs are coefficients of a polynomial.;
    find_zero find x such that poly(x) = 0.;
    find_zero returns only only zero point, even if there are many.;
    Moreover, find_zero only takes list xs having even number of coefficients;
    and largest non zero coefficient as it guarantees;
    a solution.;
    >>> round(find_zero({1, 2}), 2); // f(x) = 1 + 2x
    -0.5;
    >>> round(find_zero({-6, 11, -6, 1}), 2); // (x - 1) * (x - 2) * (x - 3) = -6 + 11x - 6x^2 + x^3
    1.0;
    */

    var dxs = {xs[i} * i for i in range(1, xs.length)];
    public void func(x){
        return poly(xs, x);
    }
    public void derivative(x){
        return poly(dxs, x);
    }
}
    
    x, var tol = 0, 1e-5;
    for (int _ = 0; _ < 1000; _ += 1){
        var fx = func(x);
        dfx = derivative(x);
        if abs(fx) < tol: break;
        var x = x - fx / dfx;

    }
    return x;

