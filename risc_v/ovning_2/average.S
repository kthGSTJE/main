.text
main:   la t1, buf                      #values to compute
        li t2, 8                        #amount of values
        li t3, 0x10                     #lower end extreme, 16
        li t4, 0x30                     #upper end extreme, 48
        li t5, 0                        #sum total of values

do:     lb t6, 0(t1)                    #load next value
        bge t6, t3, max                 #if t6 >= 16 then check t6<=48
        mv t6, t3                       #else t6 = 16 
max:    ble t6, t4, sum                 #if t6 <= 48 then add it
        mv t6, t4                       #else t6 = 48
sum:    add t5, t5, t6                  #add value to total sum

        addi t1, t1, 1                  #next measure value
        addi t2, t2, -1                 #reduce counter
        bne t2, zero, do                #repeat for amount of values
        
        srli t5, t5, 3                  #divide by 8 (2^3)
        sb t5, 0(t1)                    #save average into memory
        nop


.data
buf:    .byte 24,22,23,21,12,23,50,22   #measurement values


