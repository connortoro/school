//Connor Toro
//CS220 Midterm part 2
//Create an array, and then loop through it and store the largest value into R0


//intialize RAM[0] to -1
@R0    //select ram 0
M=-1   //set ram 0 to -1

//initialize SIZE to 5
@5     //select 5
D=A    //save value of 5 into D
@SIZE  //select SIZE variable
M=D    //set SIZE to D(5)

//intialize incrementer to 0
@i    //select i variable
M=0   //set i to 0

//------------------INITIALIZE ARRAY------------------------

//arr[0] = 1
@1    //select 1
D=A   //save value of 1 into D
@arr  //select arr[0]
M=D   //save D(1) into arr[0]

//arr[1] = 3
@3     //select 3
D=A    //save value of 3 into D
@arr+1 //select arr[1]
M=D    //save D(3) into arr[1]

//arr[2] = 9
@9      //select 9
D=A     //save value of 9 into D
@arr+2  //select arr[2]
M=D     //save D(9) into arr[2]

//arr[3] = 7
@7      //select 7
D=A     //save value of 7 into D
@arr+3  //select arr[3]
M=D     //save D(7) into arr[3]

//arr[4] = 5
@5     //select 5
D=A    //save value of 5 into D
@arr+4 //select arr[4]
M=D    //save D(5) into arr[4]

//---------------------MAIN LOOP---------------------------
(LOOP)

//END LOOP IF DONE
@i     //select i
D=M    //save i contents into D
@SIZE  //select SIZE
D=M-D  //D = SIZE - i
@END   //jump to end...
D;JEQ  //...if D is 0


//COMPARE
//get D = arr[i]
@arr    //select arr
D=A     //save address into D
@i      //select i
A=D+M   //set address to arr + i
D=M     //save arr[i] into D

//R0 > arr[i] ? @INCREMENT : continue
@R0         //select ram 0
D=D-M       //D = arr[i] - RAM[0]
@INCREMENT  //jump to INCREMENT block...
D;JLE       //...if D < 0 (R0 is bigger than arr[i])

//arr[i] is larger than R0
@arr    //select arr
D=A     //save address into D
@i      //select i
A=D+M   //address = arr + i
D=M     //D = arr[i]
@R0     //select ram 0
M=D     //ram 0 = arr[i]

//INCREMENT i, RESTART LOOP
(INCREMENT)
@i     //select i
M=M+1  //i++
@LOOP  //jump to start of loop...
0;JMP  //...always


//----------------------END-------------------------------
(END)
@END    //jump to end...
0;JMP   //...always