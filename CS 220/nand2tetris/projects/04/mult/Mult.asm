// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.


@2	  //go to RAM[2] --> where answer goes
M=0	  // set RAM[2] to 0

@0    //go to RAM[0]
D=M   //D = RAM[0]
@END  //go to END
D;JEQ //if RAM[0] is 0

@1    //go to RAM[1]
D=M   //D = RAM[1]
@END  //go to END
D;JEQ //if RAM[1] is 0

@0	  //go to RAM[0]
D=M	  //D = RAM[0]
@3	  //go to RAM[3] 
M=D	  //set RAM[3] = RAM[0], save value


(LOOP)//start loop
@1	  //go to RAM[1], 2nd num to multiply
D=M	  //save it to D

@2	  //go to RAM[2], where answer will be stored
M=D+M //RAM[2] += RAM[1]

@3	  //go to RAM[3], where intial RAM[0] was stored 
M=M-1 //RAM[3]--

D=M	  //D = RAM[3]
@LOOP //go to start of loop
D;JGT //if D is greater than zero


(END) // end block
@END  //go to end
0;JMP //always, loop forever