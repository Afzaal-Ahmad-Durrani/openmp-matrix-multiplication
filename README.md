# **OpenMP Matrix Multiplication**
![C](https://img.shields.io/badge/C-8A2BE2?style=flat)
![OpenMP](https://img.shields.io/badge/OpenMP-8A2BE2?style=flat)

A high-performance, parallelized implementation of matrix multiplication written in C using the OpenMP (Open Multi-Processing) API.

This program dynamically generates two matrices with random floating-point numbers, multiplies them concurrently utilizing a user-specified number of CPU threads, and outputs the resulting matrix.

## **Prerequisites**

To compile and run this project, you will need:
- A C compiler that supports OpenMP (e.g, GCC, Clnag or MSVC).
- A Linux/macOS terminal or Windows Subsystem for Linux (WSL).

## **Compilation**

1. **Clone the repository:**
    ```bash
    git clone https://github.com/Afzaal-Ahmad-Durrani/openmp-matrix-multiplication.git
    cd openmp-matrix-multiplication
    ```

2. **Compile the code using <code>GCC</code>**:
    ```bash
    gcc matrix_mult_omp.c -o matrix_mult_omp -fopenmp
    ```

## **Usage**

The executable requires exactly 5 command-line arguments to run.
```bash
./matrix_mult_omp <thread_count> <row1> <col1> <row2> <col2>
```

### Arguments
- <code>thread_count</code>: The number of OpenMP threads to spawn.
- <code>row1</code>: Number of rows for Matrix A.
- <code>col1</code>: Number of columns for Matrix A.
- <code>row2</code>: Number of rows for Matrix B.
- <code>col2</code>: Number of columns for Matrix B.

### Example Run:
To multiply a <code>1000x500</code> matrix by a <code>500x800</code> matrix using 4 threads:

```bash
./matrix_mult_omp 4 1000 500 500 800
```

