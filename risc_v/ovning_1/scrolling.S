.text
main:   li s0, 0x0000 #load bitmap into register
        li s1, 0xAE20
        li s2, 0xA820
        li s3, 0xEE20
        li s4, 0xA8A0
        li s5, 0xAE40
        li s6, 0x0000
        li s7, 0x0000
        li s8, 0x0000
        li s9, 0x0000
        li s10, 0x0000
        li s11, 0x0000

shift:  li a0, 0x110
        li a1, 0xB
        add a2, zero, s0
        ecall
        li a1, 0xA
        add a2, zero, s1
        ecall
        li a1, 0x9
        add a2, zero, s2
        ecall
        li a1, 0x8
        add a2, zero, s3
        ecall
        li a1, 0x7
        add a2, zero, s4
        ecall
        li a1, 0x6
        add a2, zero, s5
        ecall
        li a1, 0x5
        add a2, zero, s6
        ecall
        li a1, 0x4
        add a2, zero, s7
        ecall
        li a1, 0x3
        add a2, zero, s8
        ecall
        li a1, 0x2
        add a2, zero, s9
        ecall
        li a1, 0x1
        add a2, zero, s10
        ecall
        li a1, 0x0
        add a2, zero, s11
        ecall

check:  li t1, 0x0001
        and t2, t1, s1
        bgt t2, zero, rev # if t2 > zero then target

        srli s1, s1, 1
        srli s2, s2, 1
        srli s3, s3, 1
        srli s4, s4, 1
        srli s5, s5, 1
        
        j shift

rev:    li a0, 0x110
        li a1, 0xB
        add a2, zero, s0
        ecall
        li a1, 0xA
        add a2, zero, s1
        ecall
        li a1, 0x9
        add a2, zero, s2
        ecall
        li a1, 0x8
        add a2, zero, s3
        ecall
        li a1, 0x7
        add a2, zero, s4
        ecall
        li a1, 0x6
        add a2, zero, s5
        ecall
        li a1, 0x5
        add a2, zero, s6
        ecall
        li a1, 0x4
        add a2, zero, s7
        ecall
        li a1, 0x3
        add a2, zero, s8
        ecall
        li a1, 0x2
        add a2, zero, s9
        ecall
        li a1, 0x1
        add a2, zero, s10
        ecall
        li a1, 0x0
        add a2, zero, s11
        ecall

check2: li t1, 0x8000
        and t2, t1, s1
        bgt t2, zero, shift # if t2 > zero then target


        slli s1, s1, 1
        slli s2, s2, 1
        slli s3, s3, 1
        slli s4, s4, 1
        slli s5, s5, 1

        j rev

