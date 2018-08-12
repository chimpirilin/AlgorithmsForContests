from math import sqrt

sieve_size = 0
primes=[]
flags = [True]*50009

def sieve(upperbound):
	sieve_size = upperbound+1
	flags[0] = False
	flags[1] = False
	for i in range(2, sieve_size+1):
		if flags[i] == True:
			for j in range (i*i, sieve_size+1, i):
				flags[j] = False
			primes.append(i)

def primeFactors(n):
	lim = sqrt(n)
	factors =[]
	index=0
	primeF=primes[index]
	while(primeF<=lim):
		rep = 0
		while(n%primeF==0):
			n/=primeF
			rep+=1
		if rep!=0:
			factors.insert(0, (primeF, rep))
		index+=1
		primeF=primes[index]
	if n!=1:
		factors.insert(0, (n, 1))
	return factors

def main():
	sieve(50000)

main()