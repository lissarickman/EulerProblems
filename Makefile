# make all Euler problems
# allEuler: 
allEuler: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18

# make Euler problem 1
# Fizzbuzz
1: 1.out
1.out: euler1.o
	g++ euler1.o -o 1.out

euler1.o: euler1.cc eulerUtilities.h eulerNumbers.h
	g++ -c euler1.cc

# make Euler problem 2
# Even Fibonacci numbers
2: 2.out
2.out: euler2.o
	g++ euler2.o -o 2.out

euler2.o: euler2.cc eulerNumbers.h
	g++ -c euler2.cc

# make Euler problem 3
# Largest prime factor
3: 3.out
3.out: euler3.o
	g++ euler3.o -o 3.out

euler3.o: euler3.cc eulerUtilities.h eulerNumbers.h
	g++ -c euler3.cc

# make Euler problem 4
# Largest palindrome product
# Find the largest palindrome made from the product of two 3-digit numbers.
4: 4.out
4.out: euler4.o
	g++ euler4.o -o 4.out

euler4.o: euler4.cc eulerNumbers.h eulerUtilities.h
	g++ -c euler4.cc

# make Euler problem 5
# Smallest multiple
# What is the smallest positive number that is evenly divisible by 
# all of the numbers from 1 to XX?
# Note: XX = 20 if not given
5: 5.out
5.out: euler5.o
	g++ euler5.o -o 5.out

euler5.o: euler5.cc eulerNumbers.h
	g++ -c euler5.cc

# make Euler problem 6
# Sum square difference
6: 6.out
6.out: euler6.o
	g++ euler6.o -o 6.out

euler6.o: euler6.cc eulerNumbers.h
	g++ -c euler6.cc

# make Euler problem 7
# 10001st prime
7: 7.out
7.out: euler7.o
	g++ euler7.o -o 7.out

euler7.o: euler7.cc eulerUtilities.h
	g++ -c euler7.cc

# make Euler problem 8
# Largest product in a series
8: 8.out
8.out: euler8.o
	g++ euler8.o -o 8.out
	
euler8.o: euler8.cc eulerNumbers.h
	g++ -c euler8.cc
	
# make Euler problem 9
# Special Pythagorean triplet
9: 9.out
9.out: euler9.o
	g++ euler9.o -o 9.out

euler9.o: euler9.cc eulerNumbers.h
	g++ -c euler9.cc

# make Euler problem 10
# Summation of primes
10: 10.out
10.out: euler10.o
	g++ euler10.o -o 10.out

euler10.o: euler10.cc eulerNumbers.h
	g++ -c euler10.cc

# make Euler problem 11
# Largest product in a grid
11: 11.out
11.out: euler11.o
	g++ euler11.o -o 11.out

euler11.o: euler11.cc eulerNumbers.h
	g++ -c euler11.cc

# make Euler problem 12
# Highly divisible triangular number
12: 12.out
12.out: euler12.o
	g++ euler12.o -o 12.out

euler12.o: euler12.cc eulerNumbers.h eulerUtilities.h
	g++ -c euler12.cc

# make Euler problem 13
# Large sum
13: 13.out
13.out: BigUnsigned.o BigInteger.o BigIntegerAlgorithms.o BigUnsignedInABase.o BigIntegerUtils.o euler13.o
	g++ BigUnsigned.o BigInteger.o BigIntegerAlgorithms.o BigUnsignedInABase.o BigIntegerUtils.o euler13.o -o 13.out
	
euler13.o: euler13.cc eulerNumbers.h bigint/BigIntegerLibrary.hh
	g++ -c euler13.cc
	
BigUnsigned.o: bigint/BigUnsigned.cc bigint/BigUnsigned.hh
	g++ -c bigint/BigUnsigned.cc

BigInteger.o: bigint/BigInteger.hh bigint/BigInteger.cc
	g++ -c bigint/BigInteger.cc

BigIntegerAlgorithms.o: bigint/BigIntegerAlgorithms.hh bigint/BigIntegerAlgorithms.hh bigint/BigInteger.hh
	g++ -c bigint/BigIntegerAlgorithms.cc

BigUnsignedInABase.o: bigint/BigUnsignedInABase.cc bigint/BigUnsignedInABase.hh
	g++ -c bigint/BigUnsignedInABase.cc

BigIntegerUtils.o: bigint/BigIntegerUtils.cc bigint/BigIntegerUtils.hh
	g++ -c bigint/BigIntegerUtils.cc

# make Euler problem 14
# Longest Collatz sequence
14: 14.out
14.out: euler14.o
	g++ euler14.o -o 14.out

euler14.o: eulerNumbers.h euler14.cc
	g++ -c euler14.cc

# make Euler problem 15
# Lattice paths
15: 15.out
15.out: euler15.o
	g++ euler15.o -o 15.out

euler15.o: eulerNumbers.h euler15.cc
	g++ -c euler15.cc

# make Euler problem 16
# Power digit sum
16: 16.out
16.out: bigint/BigUnsigned.o bigint/BigInteger.o bigint/BigIntegerAlgorithms.o bigint/BigUnsignedInABase.o bigint/BigIntegerUtils.o euler16.o
	g++ bigint/BigUnsigned.o bigint/BigInteger.o bigint/BigIntegerAlgorithms.o bigint/BigUnsignedInABase.o bigint/BigIntegerUtils.o euler16.o -o 16.out

euler16.o: euler16.cc eulerNumbers.h bigint/BigIntegerLibrary.hh
	g++ -c euler16.cc

#Problem 17
#Number letter counts
17: 17.out
17.out: euler17.o 
	g++ euler17.o -o 17.out
euler17.o: eulerNumbers.h eulerUtilities.h euler17.cc
	g++ -c euler17.cc


#Problem 18
# Maximum path sum I
18: 18.out
18.out: euler18.o
	g++ euler18.o -o 18.out
euler18.o: euler18.cc eulerNumbers.h
	g++ -c euler18.cc

# make clean
clean:
	rm *.o *~.* *.out

