.text
main:   

1:      li a1, 0
        li a0, 0xFF         #Prepare to write GPIOB...
        li a2, 0x07         # ...the 3 lsb...
        call sequence_select
2:      j 1b                # Repeat forever

sequence_select:                #om a1 == 1,2,3,4 så ändra till något annat
        addi sp, sp, -4         #make room on the stack
        sw ra, 0(sp)            #for future returns

        mv t0, a1               #t0: temp a1
        mv t1, zero             #t1: counter
        li t3, 4                #t3: sequence is 4 long
switch: 
case0:  bne t0, t1, case1       #if a1 == 0 then 
        la t2, pattern1
1:      lb t5, 0(t2)
        mv a1, t5               #set a1 to to value
        call invert
        call gpiooc             #write to B
        call delay              #250ms delay
        addi t3, t3, -1         #reduce counter
        addi t2, t2, 1
        bne t3, zero, 1b # if t3 !zerot1 then target
        
        j end
case1:  addi t1, t1, 1          #counter++
        bne t0, t1, case2       #if a1 == 1 then
        li a1, 6                #set a1 to 101
        j end
case2:  addi t1, t1, 1          #counter++
        bne t0, t1, case3       #if a1 == 2 then
        li a1, 5                #set a1 to 011
        j end
case3:  addi t1, t1, 1          #counter++
        bne t0, t1, case4       #if a1 == 3 then
        li a1, 4                #set a1 to 110
        j end
case4:  addi t1, t1, 1          #counter++
        bne t0, t1, case5       #if a1 == 4 then
        li a1, 3                #set a1 to 110
        j end
case5:  addi t1, t1, 1          #counter++
        bne t0, t1, case6         #if a1 == 5 then
        li a1, 2                #set a1 to 110
        j end
case6:  addi t1, t1, 1          #counter++
        bne t0, t1, case7       #if a1 == 6 then
        li a1, 1                #set a1 to 110
        j end
case7:  addi t1, t1, 1          #counter++
        bne t0, t1, end         #if a1 == 7 then
        li a1, 0                #set a1 to 110


end:    lw ra, 0(sp)
        addi sp, sp, 4          #make room on the stack
        ret



delay: 
        li t6, 1

do:     addi t6, t6, -1
        bne t6, zero, do # if t6 != t1 then do
        

        ret

gpiooc:
    nop
    ret

invert: 
        blt t0, t4, go # if t0 < t1 then target
        
        xor a1, a1, t0
go:     ret





.data
pattern1:   .byte 0, 1, 2, 3
pattern2:   .byte 0, 2, 1, 3
pattern3:   .byte 0, 3, 0, 2
pattern4:   .byte 1, 3, 2, 3
