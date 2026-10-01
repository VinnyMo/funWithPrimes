![UNI](images/atom.png?raw=true)

# Research on the Nature of Prime Numbers
For the most part I have been focused on Natural Decomposition (see Wiki), difference between consecutive primes, and patterns that arise.

## Where this started

This is Vincent T. Mossman's original Fun With Primes research project, preserved as a legacy showcase of C and early JavaScript experiments.

For the later interactive browser app, see [`fun_with_primes`](https://github.com/VinnyMo/fun_with_primes). That legacy learning project carries forward these C sources alongside a separate JavaScript Web Worker implementation.

## `threadPartialSieve`: dividing sieve work across threads

[`threadPartialSieve`](eratosthenes.c#L168-L182) is the worker routine for [`pth_eratosthenesPrime`](eratosthenes.c#L116-L166), the threaded prime-list experiment in `eratosthenes.c`. The source header credits Vincent T. Mossman and records an update on November 5, 2016.

The design divides the sieve's factor-marking passes among threads:

1. The caller initializes a shared `int` flag array with one entry per number from 1 through `n`.
2. It starts four POSIX threads (`pthreads`, configured by `numberOfThreads`). Each worker starts at index `i = rank + 1`, advances by `numberOfThreads` while `i < sqrt(n)`, and marks larger multiples of `i + 1` as composite. The code skips later passes for even factors.
3. After joining the threads, the caller counts the remaining flags and copies their numbers into an `unsigned long` result array.

All workers operate on the same flag array; they do not own separate number ranges. This reduced sieve is intended to produce a prime list, while `eratosthenesFull` supports the separate natural-decomposition experiments.

This is historical experimental code. The flag for 1 remains set, and threads can write the same array entries without synchronization. Review correctness and thread safety before reuse; this README makes no performance or correctness guarantee.

## Explore the original experiments

- [`primeList.c`](primeList.c) calls the threaded sieve and prints its output
- [`naturalDecomposition.c`](naturalDecomposition.c) explores natural-number decomposition
- [`primeDifference.c`](primeDifference.c), [`primeSieveDifference.c`](primeSieveDifference.c), and [`primeFrequency.c`](primeFrequency.c) explore prime gaps and frequency
- [`javascript/`](javascript/) contains earlier browser experiments

Several source headers contain original build and usage notes. Treat those as historical guidance: the programs may need fixes for a current toolchain, and some write output files.
