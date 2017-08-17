#include "../../../../Libraries/std_lib_facilities.h"

/*
Purpose: Calculates prime numbers up to n

p stands for the current prime number. We assign p to a prime number and "mark" its multiples.
Anything left unmarked at the end of the loop must therefore be prime. (Not divisible by anything.)
We essentially eliminate non-prime candidates by accessing them through multiplication, then marking
the number we started on - which was never arrived at via incrementing

Procedure (Sieve of Eratosthenes):

1.) Loop starts on 2, goes up to n (max number)
2.) Count to n in increments of p (i.e. 2p, 3p, 4p . . . n) and mark them - p itself not marked
3.) Find the first number greater than p that is NOT marked (not non-prime) and assign it to p
4.) Unless we have run out of numbers, repeat step 3
5.) Print unmarked list (prime numbers - p)

*/
int main() {
	vector<int> marked;
	vector<int> prime;

	//first prime number
	constexpr int firstPrime = 2;
	//num to count up to
	constexpr int n = 100;

	//initially let p = 2 (first prime number)
	int p = firstPrime;
	//variable to stop p being incremented on first run
	bool firstRun = true;

	//Begin looping from 2 - > MAX
	while(p < n) {
		//if first run, do nothing. Else: identify next non-prime number
		if (firstRun) {
			firstRun = false;
		}
		else {
			//increment p
			p++;
			//check that p is not marked already
			for (int x = 0; x < marked.size(); x++) {
				if (p == marked[x]) {
					p++;
					x = 0;
				}
			}
		}

		//Check to prevent n being stored
		if (p == n) {
			break;
		}
		else {
			//record p (prime number)
			prime.push_back(p);
		}

		//count from p to n, in increments of p
		for (int i = p + p; i < n; i += p) {
			//mark these numbers (not prime) in a list (2p, 3p, etc.)
			marked.push_back(i);
		}
	}

	//print list of prime numbers
	for (int x : prime) {
		cout << x << '\n';
	}

	keep_window_open();
	return 0;
}