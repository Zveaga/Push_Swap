THIS README IS A WORK-IN-PROGRESS...
# Push_Swap 
The goal of push_swap is to write a program that sorts numbers and displays them on the standard output.

## Return Value

## Key Concepts
- Linked Lists
- Data Sorting Algorithms
- 

## How To Use
Clone the repository:
```
git clone 
```
Move inside the directory:
```
cd 
```
Compile:
```
make
```
This will create an executable called ``.

Run it:
```
./
```

## The Requirements

We are given 2 stacks at the begining:
- Stack `a` contains a random amount of negative and/or positive numbers which cannot be duplicated.
- Stack `b` is empty.

The goal is to sort in ascending order all the numbers from stack `a`. To do so, we can only use the following operations:

`sa (swap a)`: Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
`sb (swap b)`: Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
`ss` : sa and sb at the same time.
`pa (push a)`: Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
`pb (push b)`: Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
`ra (rotate a)`: Shift up all elements of stack a by 1.
The first element becomes the last one.
`rb (rotate b)`: Shift up all elements of stack b by 1.
The first element becomes the last one.
`rr` : ra and rb at the same time.
`rra (reverse rotate a)`: Shift down all elements of stack a by 1.
The last element becomes the first one.
`rrb (reverse rotate b)`: Shift down all elements of stack b by 1.
The last element becomes the first one.
`rrr` : rra and rrb at the same time.



