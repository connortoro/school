
//C_PUSH constant
@111
D=A
@SP
A=M
M=D
@SP
M=M+1

//C_PUSH constant
@333
D=A
@SP
A=M
M=D
@SP
M=M+1

//C_PUSH constant
@888
D=A
@SP
A=M
M=D
@SP
M=M+1

//C_POP static
@24
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D

//C_POP static
@19
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D

//C_POP static
@17
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D

//C_PUSH static
@19
D=M
@SP
A=M
M=D
@SP
M=M+1

//C_PUSH static
@17
D=M
@SP
A=M
M=D
@SP
M=M+1

//sub
@SP
AM=M-1
D=M
A=A-1
M=M-D

//C_PUSH static
@24
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
