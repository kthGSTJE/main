loop:
    li t0, 9 #load 9 into t0
    li t1, 5 #load 7 into t1
    li t2, 7 #load 5 into t2
    j loop
    xor s0, t0, t1
    xor s0, s0, t2
    nop

    li # Load immediate
    add sub #Addition Subtraktion

    #maska 0101 0010 1101 AND 0000 1111 0000 -> 0000 0010 0000
    #Linker directives .section.X (text,data,rodata,bss,global)
    # "variabler": '.byte 0' - 1B '.word 0' - 4B
    #'la' - load adress, Load Byte(unsigned) - 'lb(u) t1, 0x000(t0), lw - load word 4B
    #.equ, .equ BASE, .equ REG

    #branch
    beq t0, t1, target; # if t0 == t1 then target
    bne t0, t1, target # if t0 != t1 then target
    blt t0, t1, target # if t0 < t1 then target
    bge t0, t1, target # if t0 >= t1 then target
    bltu
    bgeu    

    #måste finnas i register ^^^^^^^

    #la, sb för att hämta/lagra i minnet
    #GPIO - general purpose
    #7 minnesadresser per
    #info finns i HW o SW - spec
    #wired and
    #0x4001 0800, 4 bitar per pinben
    #GPIO måste slås på
    
    #subrutiner för GPIO
    #GPIOI initialize - setup
    #GPIOBO bit operation, - bitmönster och för vilka bitar
    #GPIOBC bit clear
    #GPIOOC output control - använd gärna inte

    #kan inte nästla subrutiner vanligtvis
    #push/pop stackmodellen kan användas för att nästla subrutiner

    #parallella io
    #lampor = Rader 0-2
    #gpio9-15 column
    #mönster 0xRRXC R = row , C = column (x000)
    #timers (5&6)
    

    #F6 C-programmering
    #bitwise and & - endast ett & tecken
    #bitwise or
    #assemblerkod synlig för c .global
    #byte = char i C
    #FSM
    #enum
    #vad fan är DAC
    #digital analog conversion?
    #channel0 ska användas

    #lab3 dimmer
    #knappsats
    #2-3 programmerade ska funka för 0-1
    #lab3 niv 2
    #trafik

    #F7 A/D PID Regulators
    #succesiv approx
    #sample hold
    #pa3 adc
    #adc syncront
    #fixed point
    #pid reglering 
    #exceptions
    #interrupt
    
    #F8 Seriell kommunikation
    #teckenminne
    #LCD 160x80
    #4 trådar - SPI
    #full duplex
    #en master
    #multiple slaves
    #3 kontroller
    #SPI1
    #3 trådar - Microwire
    #2 Trådar - Inter Integrated Circuit - I2C
    #Synkron, halv duplex
    #Flera master
    #SD-Kort
    #ACK

    #Blockarande lösning
    #Cirkulär buffert - WR_Queue
    #I/O Expander - fler pinnar
     
    #LAB 4
    #Nivå 1
    #oledfont.h
    #125 sista tecknet
    #Lägg in 5 nya tecken
    #LCD_ShowChar

    #Nivå 2
    #dela in i 8x8 delar

    #lcd.h
    #oled.h
    #röd display
    #clean
    #LCD_Clear - färg

    #F9 Seriell kommunikation forts.

    #HAL - hardware abstract layer, buffert
    #2 trådar, I2C
    #synkron, halv duplex
    #multiple master

    #CAN
    #ASync, halvduplex
    #noise tolerant
    #långsam
    #frames för komm

    #EIA RS232/V24
    #asynk, full duplex
    #ingen klocksignal??, mottagar klocka
    #UART
    #TBE RBNE
    #Baud
    #RS422, RS485

    #1-Wire
    #singallängd

    #Wireless
    #Fart och avstånd
    #AT-kommandon, cmd/data mode
    #RFID fält

    #LAB 5
    #putch varning
    #pustr varning
    #u0_TX_queue
    #MAIN 
    #
    #


    #mhm mhm mhm mhm mhm mhm mhm mhm mhm mhm mhm mhm mhm mhm mhm mhm mhm mhm mhm hmmm hmmm mhm mhm mhm mh mm hmm hmm hmmhmhm mycket spännande
    #avbryt avbrott avbrott som avbryter avbrotten det här är mest smörja

    #mekaniskt interface(kontakt), elektriskt interface(ström), procedurellt interface
    #

    #F10 Design
    #datautbyte, ping-pong - 2 minnesarea
    