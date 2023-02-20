import threading
import numpy as np

# Matrix dimensions
N = 3
M = 3

np.set_printoptions(precision=0, suppress=True)

# Define matrices A and B
A = np.random.randint(1, 10, (N, M))
B = np.random.randint(1, 10, (N, M))

# Define the lock for the result matrix
result_lock = threading.Lock()

# Define the result matrix
result = np.zeros((N, M), dtype=int)

# Define a function for adding two matrices
def add_matrices(start_row, end_row):
    global result
    for i in range(start_row, end_row):
        with result_lock:
            for j in range(M):
                result[i][j] = A[i][j] + B[i][j]

# Define a function for subtracting two matrices
def subtract_matrices(start_row, end_row):
    global result
    for i in range(start_row, end_row):
        with result_lock:
            for j in range(M):
                result[i][j] = A[i][j] - B[i][j]

# Define a function for multiplying two matrices
def multiply_matrices(start_row, end_row):
    global result
    for i in range(start_row, end_row):
        with result_lock:
            result[i] = np.dot(A[i], B)

# Define the number of threads to use
num_threads = 4

# Divide the rows of the matrix among the threads
chunk_size = N // num_threads
print("Matrix A:")
print(A)
print("Matrix B:")
print(B)
# Create the threads for matrix addition
add_threads = []
for i in range(num_threads):
    start_row = i * chunk_size
    end_row = (i + 1) * chunk_size
    if i == num_threads - 1:
        end_row = N
    thread = threading.Thread(target=add_matrices, args=(start_row, end_row))
    add_threads.append(thread)

# Start the threads for matrix addition
for thread in add_threads:
    thread.start()

# Wait for the threads for matrix addition to finish
for thread in add_threads:
    if thread.is_alive():
        thread.join()

# Print the result matrix for matrix addition
print("Result of matrix addition:")
print(result.astype(int))

# Create the threads for matrix subtraction
sub_threads = []
for i in range(num_threads):
    start_row = i * chunk_size
    end_row = (i + 1) * chunk_size
    if i == num_threads - 1:
        end_row = N
    thread = threading.Thread(target=subtract_matrices, args=(start_row, end_row))
    sub_threads.append(thread)

# Start the threads for matrix subtraction
for thread in sub_threads:
    thread.start()

# Wait for the threads for matrix subtraction to finish
for thread in sub_threads:
    if thread.is_alive():
        thread.join()

# Print the result matrix for matrix subtraction
print("Result of matrix subtraction:")
print(result.astype(int))
# Create the threads for matrix multiplication
mul_threads = []
for i in range(num_threads):
    start_row = i * chunk_size
    end_row = (i + 1) * chunk_size
    if i == num_threads - 1:
        end_row = N
    thread = threading.Thread(target=multiply_matrices, args=(start_row, end_row))
    mul_threads.append(thread)

# Start the threads for matrix multiplication
for thread in mul_threads:
    thread.start()

# Wait for the threads for matrix multiplication to finish
for thread in mul_threads:
    thread.join()

# Print the result matrix for matrix multiplication
print("Result of matrix multiplication:")
for row in result:
    print(row)

