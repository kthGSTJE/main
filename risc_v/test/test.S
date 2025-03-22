        addi t0, zero, 0xFFE
        addi t1, zero, 0x004
do:     srli t1, t1, 0x01
        addi t0, t0, 0x01
        bnez t0, do

        nop