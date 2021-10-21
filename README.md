## the project
# brief description
The aim of this project is to write an algorithm which will sort in ascending order
numbers in a stack (a), using a limited set of operations and one additional stack (b).

# allowed operations
sa:	Swap the first two elements at the top of stack a (only if stack len >= 2).
sb:	Swap the first two elements at the top of stack b (only if stack len >= 2).
ss:	sa and sb at the same time.
pa:	Push the first element at the top of stack b to the top of stack a (only if b is not empty).
pb:	Push the first element at the top of stack a to the top of stack b (only if a is not empty).
ra:	Rotate stack a by shifting up all elements by 1. The first element becomes the last one.
rb:	Rotate stack b by shifting up all elements by 1. The first element becomes the last one.
rr: ra and rb at the same time.
rra: Reverse rotate a by shifting down all elements by 1. The last element becomes the first one.
rrb: Reverse rotate b by shifting down all elements by 1. The last element becomes the first one.
rrr: rra and rrb at the same time.

This sorting algorithm uses all operations except for rr and rrr.

## the algorithm
This sorting algorithm is an adaptation of quicksort. Prior to running the algorithm,
the numbers in the stack are pre-sorted using selection sort, in order to retrieve the
correct indices and use these for the further calculations (so that the avg is also the
median). 
log2(n) chunks of numbers to stack B. These initial chunks are sorted in ascending 
order, meaning that any number in chunk 0 will be lower than any number in chunk 1. 
Any number in chunk 1 will be lower than any of the numbers in chunk 2.

At this point we have an empty stack A and a stack B containing log2(n) number of 
chunks. The separate chunks are sorted, but the numbers within these chunks are not 
sorted yet.

Within-chunk sorting is done one chunk at a time, by repeatedly splitting the chunk 
into two chunks (original chunk and a new chunk), until there are no more than 2 
numbers left in the original chunk. Once this happens, the remaining numbers are 
swapped if necessary and set as sorted.

## running the checker
The following command will run the push_swap checker and do a word count to see 
the number of operations:

ARG=(`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`); ./push_swap $ARG | ./checker_Mac $ARG && ./push_swap $ARG | wc -l