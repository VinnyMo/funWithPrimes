# Fun With Primes

**My original C and early JavaScript experiments with prime numbers, natural decomposition, and the patterns between consecutive primes.**

I worked on these experiments in college, before AI coding tools were part of the process. I'm proud of this work, especially the attempt to divide a sieve's work across threads. This repository keeps the original source available to explore, including the unfinished parts.

For the later interactive browser project, see [`fun_with_primes`](https://github.com/VinnyMo/fun_with_primes). It carries forward these C sources alongside a separate JavaScript Web Worker implementation.

## Start exploring

| If you're curious about… | Start here |
| --- | --- |
| The threaded sieve | [`eratosthenes.c`](eratosthenes.c) and the explanation below |
| Generating and printing a prime list | [`primeList.c`](primeList.c) |
| Natural-number decomposition | [`naturalDecomposition.c`](naturalDecomposition.c) and `eratosthenesFull` |
| Gaps and patterns between primes | [`primeDifference.c`](primeDifference.c) and [`primeSieveDifference.c`](primeSieveDifference.c) |
| Prime frequency over intervals | [`primeFrequency.c`](primeFrequency.c) |
| Early browser experiments | [`javascript/index.html`](javascript/index.html), with primality, factor, and sieve functions |

## How the threaded sieve works

[`threadPartialSieve`](eratosthenes.c#L168-L182) is the worker routine for [`pth_eratosthenesPrime`](eratosthenes.c#L116-L166). The source header credits Vincent T. Mossman and records an update on November 5, 2016; [the corresponding source history](https://github.com/VinnyMo/funWithPrimes/commit/800da4856724b73361f000551546ec318baa4b46) preserves that stage of the experiment.

The design divides the sieve's factor-marking passes among POSIX threads:

1. The caller initializes a shared `int` flag array with one entry per number from 1 through `n`.
2. It starts the number of workers specified by the mutable global `numberOfThreads`, initialized to `4` in this source. There is no automatic CPU-count detection.
3. Each worker starts at index `i = rank + 1`, advances by `numberOfThreads` while `i < sqrt(n)`, and marks larger multiples of `i + 1` as composite. The code skips later passes for even factors.
4. After joining the threads, the caller counts the remaining flags and copies their numbers into an `unsigned long` result array.

All workers operate on the same flag array; they do not own separate number ranges. This reduced sieve is intended to produce a prime list, while `eratosthenesFull` supports the separate natural-decomposition experiments.

## Reading and running the originals

These are individual experiments rather than a single packaged application. Several source headers contain their original build and usage notes. For example, `primeList.c` documents:

```sh
gcc primeList.c -pthread -lm -o primeList
./primeList 100
```

That command requires a C compiler, POSIX threads, and the math library. Treat it as historical guidance rather than a guarantee for every current toolchain. Review the source before running it, start with a small input, and build locally rather than relying on the committed binaries.

The browser files live in [`javascript/`](javascript/). The HTML page loads the accompanying scripts directly and includes an external Google Fonts stylesheet.

### Things to know before reuse

- The threaded sieve leaves the flag for `1` set, so its output includes `1` even though it is not prime.
- Threads can write the same flag-array entries without synchronization. Correctness and thread safety need review before reuse.
- Some experiments are unfinished and may need fixes to compile with a current toolchain.
- `naturalDecomposition.c` and `primeFrequency.c` open their corresponding `.txt` output files for writing, replacing existing contents.
- Timing output is part of the experiments; this repository makes no benchmark or performance guarantee.

The original source, comments, and filenames are preserved here so the work can be read in its own context.

<details>
<summary>Original project artwork</summary>

<img src="images/atom.png" alt="Original Fun With Primes atom artwork" width="320">

</details>
