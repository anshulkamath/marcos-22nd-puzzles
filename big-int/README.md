# Big Int Puzzle
We meet again, Mr. MacOS. It's been too long.
I hope you're intimidated by the abundance of files here... I think you have a feeling of what I'm going to ask.
If you remember back to the second semester of your junior year of college, your roommate was weirdly obsessed with this "big int" project.
I bet that you were so thankful that you would never have to deal with the problems that he had to deal with... the constant memory issues,
the testing infrastucture, having to program in C... what a nightmare!

Well, unfortunately I must be the (we bare) bearer of bad news.
Your mission, should you choose to accept it, is to implement add and subtract for both big integers and modular arithmetic (denoted by `TODO`s).

You will test these functions with the command `make test`, and upon completion of said functions, you will be given your key phrase.
Good luck!

## Big Int Representations
I know that you know how to represent numbers of arbitrary bases, but I'm going to explain it once more for the people who don't.
Let's start with a simple case - base 10.
I'm sure that you agree we can represent any base 10 number as a list of digits 0-9.
The `1` in the 10s place indicates the corresponding multiple of that power of 10.
Also, we call the "places" (i.e. 10s place, 1s place) limbs.

Now, let's try a slightly harder example: base 256.
These are simply 8-bit numbers.
So, if we wanted to represent 255 in base 256, it would simply be 255, or `[0xff]` in the first limb of the array.
However, if we wanted to represent 256, it would be the 2-limb number `[1, 0]`.
Similarly, if we wanted to resresent 257, it would simply be 2-limb number `[1, 1].`
Now, we have a mechanism for expressing arbitrarily large integers in software, and are no longer confined to the physical 8-bit hardware limit.

In the Big Int puzzle, you are going to be working with base 32-bits (keep in mind, the integers are all unsigned).
Hence, each limb can be scaled by any integer from [0, 2^32-1].
In other words, representing any **single digit** would be `[0x12345678]`, where each limb contains a 32-bit unsigned integer.

## Overflow
When working with arithmetic, notice that overflow/underflowing is essentially the same as modding by the base raised to the highest corresponding limb.
For example, suppose we are working in base 10: 9 + 8 = 7 (mod 10). Similarly, in base 4 (binary): 11 + 10 = 01 (base 4).
When underflowing, consider the example 01 - 10 = 11 (mod 4).
