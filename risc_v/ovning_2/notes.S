.text
main:   call funct              #jump to target
        add t1, zero, t1        #here
        add t1, zero, t1        #is
        add t1, zero, t1        #some code

funct:  add t1, zero, t1        #here
        add t1, zero, t1        #is
        add t1, zero, t1        #some more code

        ret                     #returns to where function was called