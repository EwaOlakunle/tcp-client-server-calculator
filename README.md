# tcp-client-server-calculator
Extending a TCP starter system to implement a robust, error-checked application-layer protocol in C.

# TCP Network Protocol Implementation

##  Project Context
This project was developed as part of the **COMP 2560 Systems Programming** curriculum at the **University of Windsor**. While the basic TCP socket boilerplate was provided as a starter system, my focus was on designing and implementing a robust application-layer protocol and enhancing server-side security. 

## My Contributions (The "Hardening" Phase)
I transformed a simple addition-only server into a multi-functional calculator by implementing the following:

### 1. Protocol Design
Extended the communication logic to support a structured request format: `<operation> <number1> <number2>`. 

### 2. Arithmetic Engine
Implemented server-side logic for:
* `add` (Addition) 
* `sub` (Subtraction) 
* `mul` (Multiplication) 
* `div` (Division)

  
### 3. Defensive Programming & Error Handling
To ensure server stability and security, I implemented strict input validation: 

* **Logic Protection:** Added checks for **Division by Zero** to prevent server crashes. 
* **Input Sanitization:** Used `sscanf` to validate that only the expected number of arguments are processed. 
***Standardized Error Reporting:** Developed a response protocol (`ERR <message>`) for unsupported operations. 

## How to Run
```bash
gcc server.c -o server
gcc client.c -o client
./server
./client



