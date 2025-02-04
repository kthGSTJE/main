main:
        li a1, 0x0000AAAA
        li a2, 0x0000F0F0
        and a1, a1, a2
        xor a2, a2, a1
        slli a2, a2, 16
        or a1, a1, a2
        nop