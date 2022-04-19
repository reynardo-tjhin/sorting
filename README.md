# sorting

Implemented 6 different kinds of sorting algorithms:
1. Selection Sort
2. Bubble Sort
3. Insertion Sort
4. Counting Sort
5. Heap Sort
6. Merge Sort

*All the algorithms are implemented by me.
However, the ideas or concepts are taken from USYD COMP2123 Semester 1 2020 Lectures 5, 10 and 11
and from https://www.geeksforgeeks.org/sorting-algorithms/

Based on a quick analysis
The fastest algorithm is using "Selection Sort".
While the slowest algorithm is using "Bubble Sort".
There are many factors that may affect the accuracy of the times including the bussiness of the processor/ALU.

This quick analysis only tests on positive integers.
This means that counting sort may not be used in most scenarios.

The Time complexities of each algorithm is:

| Algorithms     | Worst Case Time Complexity |
|----------------|----------------------------|
| Selection Sort | O(n^2)                     |
| Bubble Sort    | O(n^2)                     |
| Insertion Sort | O(n^2)                     |
| Counting Sort  | O(n)                       |
| Heap Sort      | O(nlogn)                   |
| Merge Sort     | O(nlogn)                   |

## running the program

Run the program by running this code in your terminal
```
gcc -Wall -Werror -fsanitize=address,leak sort_positive_integers.c -o sort_positive_integers
./sort_positive_integers
```
Or you can run the `compile.sh` file
```
./compile.sh
```