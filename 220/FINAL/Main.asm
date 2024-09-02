//   int[] numbers = {10, 23, 19, 34, 54, 23, 76, 39, 65, 24, 8, 0, 12, 55};
//   int sum = 0;
//   int sum1 = 0;
//   for(int i = 0; i < numbers.length; i++) {
//       if(numbers[i] <= 0) {
//           sum1 = sum1 + numbers[i] + numbers[i];
//       } else {
//           sum = sum + numbers[i];
//       }
//   }


// note: I didn't implement the middle else if statement in the java code,
// because it can never be reached, and therefore shouldn't be included,
// unless I am missing something

//------------------INITIALIZE ARRAY------------------------

//arr[0] = 10
@10    
D=A   
@arr  
M=D   

//arr[1] = 23
@23     
D=A    
@arr+1 
M=D    

//arr[2] = 19
@19      
D=A     
@arr+2  
M=D    

//arr[3] = 34
@34    
D=A     
@arr+3  
M=D     

//arr[4] = 54
@54    
D=A    
@arr+4 
M=D

//arr[5] = 23
@23
D=A    
@arr+5 
M=D    

//arr[6] = 76
@76  
D=A    
@arr+6 
M=D    

//arr[7] = 39
@39  
D=A    
@arr+7 
M=D    

//arr[8] = 65
@65    
D=A    
@arr+8 
M=D    

//arr[9] = 24
@24    
D=A    
@arr+9 
M=D    

//arr[10] = 8
@8   
D=A    
@arr+10
M=D    

//arr[11] = 0
@0    
D=A    
@arr+11
M=D    

//arr[12] = 12
@12    
D=A    
@arr+12 
M=D    

//arr[13] = 55
@55    
D=A    
@arr+13 
M=D

//INITIALIZE SUMS
@0
D=A
@sum 
M=D
@sum1
M=D

//INITIALIZE SIZE AND INCREMENTER
@14
D=A
@SIZE
M=D

@0
D=A
@i
M=D

//----------------------MAIN LOOP-------------------------------
(LOOP)

//END LOOP IF DONE
@i    
D=M    
@SIZE  
D=M-D  
@END   
D;JEQ  

//D = arr[i]
@arr    
D=A     
@i      
A=D+M   
D=M

//IF arr[i] IS NEGATIVE GO TO NEG INSTRUCTION
@NEG
D;JLE

//sum = sum + arr[i]
@sum
M=M+D
@INCREMENT
0;JMP

(NEG)
@sum1
M=M+D
M=M+D
@INCREMENT
0;JMP


//INCREMENT AND RESTART LOOP
(INCREMENT)
@i     
M=M+1  
@LOOP  
0;JMP  

//----------------------END-------------------------------
(END)
@END    //jump to end...
0;JMP   //...always