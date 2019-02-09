# RSA-Factoring-Challenge

### Problem Statement

Factorize as many numbers as possible into a product of two smaller numbers.

### Implementation

Implementing the Pollard Rho algorithm as seen here:
http://mathforum.org/library/drmath/view/65801.html

### Constraints

* No dependencies
* 5s max to complete calculations
* Required output: n=(p)(q)

### Real World Application?

Prime Factorization (or integer factorization) is a commonly used mathematical problem often used to secure public-key encryption systems. A common practice is to use very large semi-primes (that is, the result of the multiplication of two prime numbers) as the number securing the encryption. In order to break it, they would have to find the prime factorization of the large semi-prime number – that is, two or more **prime numbers** that multiplied together result in the original number.

Source: https://learncryptography.com/mathematics/prime-factorization
