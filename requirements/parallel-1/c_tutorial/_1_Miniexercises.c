1. Miniexercises

    1.1 Hello World

    - Log in to a CIP - pool computer with your BT credentials.- Start a text editor and insert the following C source code :

#include <stdio.h>

    int main(int argc, char **args)
{
  printf("Hello World!\n");
  return 0;
}

- Save the file to your home directory as hello_world.c - Open the terminal !-Now enter gcc hello_world.c - o hello_world to compile the Hello World program !-Now enter./ hello_world to run this program !

                                                                                                                1.2 Sizeof exercise

    - Write a C program that uses the sizeof operator to print the
          size of int,
    float, and double data types, as well as the sizes of their respective pointers int *, float *, and double *!-Note:You can print an integer variable with the name number
                                                                                                                           on the console by
                                                                                                                 using:

                                                                                                                     printf("The number is %i\n", number);

1.3 Factorial Calculation

    - The factorial of a natural number can be recursively defined
          as follows:

{ 1 if n = 0
	  fac(n) =  {
				{ n * fac(n-1) if n > 0

    - Implement a recursive function that calculates the factorial 
      based on its recursive definition!
    - Optional: Implement a function that calculates the factorial 
      iteratively!
    - Test your function(s)! 
    - Write a main function that calculates the factorial of several 
      integers and then prints them!


1.4 Swap Function

    - Implement a swap function for integers. 
    - It should accept two pointers to the integers to be swapped. 
    - Then, by dereferencing the passed pointers, it should swap the 
      values of the two integers.
    - Test your swap function again with an appropriate main function.
