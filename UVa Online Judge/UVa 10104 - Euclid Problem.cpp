// UVa 10104 - Euclid Problem.cpp
// Direct Application of The Extended Euclid Method
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
using namespace std;

long long int Extended_Euclid(long long int A,long long int B, long long int *X,long long int *Y)
{
	long long int x, y, u, v, m, n, divisor, divident, quotient, remainder;
	// B = A(0) + B(1)
	x = 0;  // x [i-2]
	y = 1;  // y [i-2]

	// A = A(1) + B(0)
	u = 1;  /// x[i-1]
	v = 0;  /// y[i-1]

	divisor = A;
	divident = B;

	while (divisor != 0)
	{
		// b = aq + r and 0 <= r < a 
		quotient = divident / divisor;

		/// GCD function
		remainder = divident % divisor;
		divident = divisor;
		divisor = remainder;

		// r = A(x - uq) + B(y - vq) 
		m = x - (u * quotient);      // m = x[i] = (x - uq)
		n = y - (v * quotient);      //  n = y[i] = (y - vq)
		x = u;            // updating x[i-1] = x[i-2]
		y = v;            // updating y[i-1] = y[i-2]
		u = m;          // updating x[i] = x[i-1]
		v = n;           // updating y[i] = y[i-1]
	}

	// Ax + By = gcd(A, B)
	if (A == B) {
		*X = y;
		*Y = x;
	}
	else {
		*X = x;
		*Y = y;
	}
	
	return divident;
}

int main()
{
	long long int A, B, X, Y;
	
	while (scanf("%lld%lld", &A, &B) != EOF) {
		printf("%lld %lld %lld\n",X,Y, Extended_Euclid(A, B, &X, &Y));
	}
}

