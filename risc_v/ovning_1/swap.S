    li t0, 7 # load t0 with 7
    li t1, 9 # load t1 with 9

    xor t0, t0, t1 #swap numbers t0 and t1
    xor t1, t1, t0 
    xor t0, t0, t1 #numbers are now swapped

    nop