# Matrix-Vector Multiplication in C++ (MxV)

## Overview

This repository contains a C++17 implementation of a matrix-vector multiplication exercise, originally completed as part of a technical recruitment process.

The program supports dense matrices and sparse matrices stored in Compressed Sparse Row (CSR) format. 
It multiplies a square matrix by an all-ones vector and verifies the result against the sum of each matrix row.

The original exercise requirements are included in [`instructions.txt`](instructions.txt).

## Implementation

The project uses an abstract base class to provide a common interface for dense and sparse matrix implementations.

The sparse implementation uses CSR storage to represent non-zero coefficients efficiently.

## Build and Run

The project uses GNU Make and requires a C++17-compatible compiler.

```bash
make
./build/a.out
```

The program prompts for the path to an input file. 
Sample files are available in the `input/` directory.

## Input Format

The first line specifies the matrix representation (`Full matrix` or `Sparse matrix`), followed by the dimension of the square matrix.

For sparse matrices, each subsequent entry contains a one-based row index, a one-based column index, and a coefficient. 
Entries are expected to be grouped by row in ascending order.

## Project Background

This repository documents a self-contained technical exercise rather than a general-purpose numerical library. 
The original implementation has received minor updates for type safety, polymorphic class design, and input handling.