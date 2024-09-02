//Connor Toro
//CS220 Midterm part 1
//stores the greatest value between R1, R2, and R3 in R0

//R0 : Answer 
//R1 : value to be evaluated
//R2 : value to be evaluated
//R3 : value to be evaluated


//set R0 to 0
@R0 //select ram 0
M=0 //set ram 0 to 0

//set R1 to 7
@7    //select 7
D=A   //save value of 7 to D
@R1   //select ram 1
M=D   //save D(7) into ram 1

//set R2 to 11
@11   //select 11
D=A   //save value of 11 into D
@R2   //select ram 2
M=D   //save D(11) into ram 2

//set R3 to 5
@5    //select 5
D=A   //save value of 5 into D
@R3   //select ram 3
M=D   //save D(5) into ram 3

//Compare R1 and R2, save in D
@R1    //select ram 1
D=M    //save contents of ram 1 into D
@R2    //select ram 2
D=D-M  //save contents of R1 - R2 into D 

//Jump to block if r1 is greater than r2
@GREATER_IS_R1 //jump to GREATER_IS_R1...
D;JGT          //...if ram 1 is greater (D is greater than 0)

//Save R2 to D if it's greater, jump to end of first comparison block
@R2    //select ram 2
D=M    //save ram 2 contents into D
@FIRST_COMPARISON_END //jump to end of first comparison block...
0;JMP                 //...always

//Save R1 to D if it's greater block
(GREATER_IS_R1)  //if R1 is greater block
@R1    //select ram 1
D=M    //save contents of ram 1 into D

//End of first comparison block, save either R1 or R2 to R0 (which ever one was greater)
(FIRST_COMPARISON_END)
@R0  //select ram 0
M=D  //save D into ram 0

//Compare R3 ro R0, jump to end if R0 is greater
@R3    //select ram 3
D=D-M  //save D-M into D (ram 0 - ram 3)
@END   //jump to end...
D;JGT  //...if D is greater than 1 (ram 0 is largest)

//R3 is greater than R0, so save R3 into R0
@R3   //select ram 3
D=M   //save contents of ram 3 into D
@R0   //select ram 0
M=D   //save D into ram 0

//infinite end loop
(END)
@END  //jump to END...
0;JMP //...always
