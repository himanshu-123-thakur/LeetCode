******** Largest number is 2^31 -1 
******** Smaleest number is -2^31


******** How computer stores -ve number 
            in a 32 bit machine the 32 bit is reserved for sign
            if +ve 0
            if -ve 1

    if x = -13
    computer conver to 2's complement 
    00.......1101
    11.......0010
    ADD 1
    00.......0001
    -----
    11.......0011 

    32 bit is 1 which tells us it is a negative number 



*********1's and 2's Compliment 
13 = 1101
1 compliment = flip the bits 
                0010

2 compliment = flip the bits 
                0010
                add 1
                0001
ans =           0011


*********XOR Operator
    13^7
    1101
    0111
    ----
    1010

if number of 1 -> EVEN = 0
if number of 1 -> ODD = 1

*************** RIGHT SHIFT 

    any number n right shift by k is (n/pow(2,k))


*************** LEFT SHIFT
    any number n left shift by k is  n * pow(2,k)

    cannot left shist the INT_MAX as it changes sign bit too
    it gives us overflow issue


***************** OPRATION
    any (NUMBER & NUMBER-1) XOR (NUMBER) ====> GIVES US A NUMBER IN WHICH THE RIGHMIST BIT IS SET OF ORGINAL NUMBER