// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.


(RESTART)
@SCREEN
D=A
@0
M=D	//PUT SCREEN START LOCATION IN RAM0

///////////////////////////
(KBDCHECK)

@KBD      //go to kbd
D=M       //save kbd to D
@BLACK    //go to black block..
D;JGT     //..if kbd is > 0
@WHITE    //go to white block..
D;JEQ     //..if kbd is 0

@KBDCHECK //else repeat
0;JMP     //go back to kbdcheck


(BLACK)  //black block
@1       //go to RAM[1]
M=-1	 //set it to -1(black)
@CHANGE  //go to change block..
0;JMP    //..always

(WHITE)  //white block
@1       //go to RAM[1]
M=0	     //set it to 0(white)
@CHANGE  //go to change block..
0;JMP    //..always

(CHANGE) //change block
@1	     //go to RAM[1] --> where color is stored
D=M	     //save color into D

@0       //go to RAM[0] --> address of pixel to change
A=M	     //set A(curr address) to RAM[0] value
M=D	     //set its pixel value to black or white

@0       //go to RAM[0] --> pixel address
D=M+1	 //save next pixel to change into D
@KBD     //go to KBD
D=A-D	 //D = A(mem location num) - D(next pixel to change)
         //kbd is located after all of the pixel registers, so this will find out if we are on the last pixel

@0       //go to RAM[0](address)
M=M+1	 //increment to next pixel
A=M      //save value to A(curr address)

@CHANGE  //go to change block..
D;JGT  	 //..if D > 0


@RESTART //restart program..
0;JMP    //..always