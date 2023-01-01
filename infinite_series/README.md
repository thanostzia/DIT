# Infinite Series

This folder contains programs in C that implement various famous infinite series which approximate π = 3.14... and ln2 = 0.69....
Specifically, the program `s2.c` computes ln2 while the other programs compute π. <br><br>

It is important to note that the data types that were used in these programs (double, long int, char) were specifically used in order to show the results of the approximations
when forcing the compiler to use a specific amount of storage data for each variable. <br><br>

This is also seen by the usage of the do_while loop that is used in all programs, which stops when a very high amount of iterations is reached. In fact, the values that were chosen for the condition of the loops are specifically chosen as they are the highest values needed for non-changing outputs, in case a higher value is chosen.

Example: In line 25 of program `s1.c`, we have the following code:

> while (current > 1.0e-16);

The computed value of π from this program is `3.1415926535897278`, with 100000000 performed. If one were to choose to write the code:

> while (current > 1.0e-17);

the computed value would not change. This is because, even if more interations are being performed (316227767) the data type `double` cannot store a number of higher precision than the one computed from the original code.<br><br>

## Prerequisites

Both the programs `s1.c` and `s1.6` use the math.h library. Therefore, in order to compile these programs, you will need the -lm linker flag, like this:

> $ gcc -o program program.c -lm

Replace "program.c" with the name of the program's source code file and "program" with the desired name for the compiled executable.

*`The -lm option is a linker flag that tells the compiler to link the program with the math library. This is necessary because the math.h header file only provides the function declarations and prototypes, but the actual implementation of the functions is provided by the math library.`*<br><br>


## Mathematical Formulas

The formulas used for these programs were given by the instructor of the course. The prominent used ones are the Leibniz formula for π (or the Madhava–Leibniz series), the Wallis product for π's approximation and variations of these series. The `s2.c` program, which approimates the value of ln2 uses the "Alternating harmonic series".<br><br>

_**Leibniz formula for π:**_

 $$ {\frac{\pi }{4} = \sum_{k=0}^{\infty }\frac{(-1)^k}{2k+1}=1-\frac{1}{3}+\frac{1}{5}-\frac{1}{7}+\frac{1}{9}-...} $$

<br>

_**Wallis product:**_

$$ {\frac{\pi }{2}=\prod_{n=1}^{\infty }\frac{4n^2}{4n^2-1}=\prod_{n=1}^{\infty}\left ( \frac{2n}{2n-1}\cdot\frac{2n}{2n+1} \right )=\left (\frac{2}{1}\cdot \frac{2}{3}  \right )\cdot \left (\frac{4}{3}\cdot \frac{4}{5}  \right )\cdot \left (\frac{6}{5}\cdot \frac{6}{7}  \right )\cdot \left (\frac{8}{7}\cdot \frac{8}{9}  \right )\cdot ...} $$

<br>

_**Alternating harmonic series:**_

$$ {ln2=\sum_{n=1}^{\infty } \frac{(-1)^(n+1)}{n}=1-\frac{1}{2}+\frac{1}{3}-\frac{1}{4}+\frac{1}{5}-...} $$ <br><br>

## Sources

- [Leibniz formula for π](https://en.wikipedia.org/wiki/Leibniz_formula_for_%CF%80)
- [Wallis product](https://en.wikipedia.org/wiki/Wallis_product)
- [Alternating harmonic series](https://en.wikipedia.org/wiki/Harmonic_series_(mathematics)#Alternating_harmonic_series)
