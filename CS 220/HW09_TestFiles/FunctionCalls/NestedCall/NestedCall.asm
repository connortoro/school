
//C_PUSH constant
@4000
D=A
@SP
A=M
M=D
@SP
M=M+1

//C_POP pointer
@THIS
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D

//C_PUSH constant
@5000
D=A
@SP
A=M
M=D
@SP
M=M+1

//C_POP pointer
@THAT
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D

//C_POP temp
@R5
D=M
@6
D=D+A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D

//C_PUSH constant
@4001
D=A
@SP
A=M
M=D
@SP
M=M+1

//C_POP pointer
@THIS
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D

//C_PUSH constant
@5001
D=A
@SP
A=M
M=D
@SP
M=M+1

//C_POP pointer
@THAT
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D

//C_PUSH constant
@200
D=A
@SP
A=M
M=D
@SP
M=M+1

//C_POP local
@LCL
D=M
@1
D=D+A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D

//C_PUSH constant
@40
D=A
@SP
A=M
M=D
@SP
M=M+1

//C_POP local
@LCL
D=M
@2
D=D+A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D

//C_PUSH constant
@6
D=A
@SP
A=M
M=D
@SP
M=M+1

//C_POP local
@LCL
D=M
@3
D=D+A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D

//C_PUSH constant
@123
D=A
@SP
A=M
M=D
@SP
M=M+1

//C_POP temp
@R5
D=M
@5
D=D+A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D

//C_PUSH local
@LCL
D=M
@0
A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1

//C_PUSH local
@LCL
D=M
@1
A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1

//C_PUSH local
@LCL
D=M
@2
A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1

//C_PUSH local
@LCL
D=M
@3
A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1

//C_PUSH local
@LCL
D=M
@4
A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=M+D

//add
@SP
AM=M-1
D=M
A=A-1
M=M+D

//add
@SP
AM=M-1
D=M
A=A-1
M=M+D

//add
@SP
AM=M-1
D=M
A=A-1
M=M+D

//C_PUSH constant
@4002
D=A
@SP
A=M
M=D
@SP
M=M+1

//C_POP pointer
@THIS
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D

//C_PUSH constant
@5002
D=A
@SP
A=M
M=D
@SP
M=M+1

//C_POP pointer
@THAT
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D

//C_PUSH argument
@ARG
D=M
@0
A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1

//C_PUSH constant
@12
D=A
@SP
A=M
M=D
@SP
M=M+1

//add
@SP
AM=M-1
D=M
A=A-1
M=M+D
