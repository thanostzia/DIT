# Introduction to Programming

This repository contains all projects, assignments, and exercises from the Introduction to Programming course at the Department of Informatics and Telecommunications.

<br>

 ## Contents
	

  
 - **Assignment 1 _(mertens_function)_:** Program written in C which computes all values of the Mertens function in a given range of numbers and afterwards performs the tasks of computing the function's zero points while also computing the perfect, abundant and deficient numbers in a given range.
 
> The subject of this assignment is related to prime numbers, the factorization of integers, that is, the analysis of their decomposition into the product of prime factors, as well as the concept of divisibility in integers.
 
<br>
 
 - **Assignment 2 _(netpbm_convert)_:** Program written in C which converts RGB images to Grayscale and Grayscale images to Black-and-White (B/W). The images must respect the NetPBM format, either for Binary or ASCII encoding (Magic Number = [1, 6], format extensions: .ppm, .pgm, .pbm).
 
> The subject of this assignment is the processing of images that follow the NetPBM format and the implementation of specific functions on them. 
 The reason that this particular format was adopted is that it does not require the full storage of the data of an image, or even part of it, in order to be able to process it. 
 Simple functions on images that follow this format can be implemented simply by reading a repeatedly limited amount of data of the image from the input, through getchar(), without using arrays for the storage of this data.
	
<br>

## Prerequisites

To make use of the .c files, you will first need to compile them and afterwards run the created executable programs. It is advisory to use the gcc compiler provided by the GNU Project.<br><br>

In order to compile a .c file, follow the syntax:

    $ gcc -o program program.c
    
Replace "program.c" with the name of the program's source code file and "program" with the desired name for the compiled executable.<br><br>

Once the program has been compiled, you can run it using the following command:

    % ./program

<br>	
    
## Contributors

- [Athanasios Tziachanas](https://github.com/thanostzia)
