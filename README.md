# Bank Management System in C++

A simple console-based Bank Management System developed using **C++**, **Object-Oriented Programming (OOP)** concepts, and **File Handling**.  
This project allows users to create and manage bank accounts directly from the terminal.

---

## Features

- Create New Bank Account
- Search Account by Account Number
- Deposit Money
- Withdraw Money
- Check Account Balance
- Display All Accounts
- Delete Account
- Persistent Data Storage using File Handling
- Minimum Balance Validation

---

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- File Handling
- Standard Template Library (STL)

---

## OOP Concepts Used

- Classes and Objects
- Encapsulation
- Static Data Members
- Member Functions
- Arrays of Objects

---

## File Handling

This project stores all account data in a text file:

```txt
accounts.txt
```

### Data Format

```txt
AccountNumber|Name|Phone|Balance
```

### Example

```txt
1000|Anubhav|9876543210|5000
```

---

## Project Structure

```txt
Bank-Management-System/
│
├── code.cpp
├── accounts.txt
└── README.md
```

---

## How to Compile and Run

### Compile

```bash
g++ code.cpp -o bank
```

### Run

#### Linux / Mac

```bash
./bank
```

#### Windows

```bash
bank.exe
```

---

## Main Menu

```txt
1. Create Account
2. Search Account
3. Deposit Money
4. Withdraw Money
5. Check Balance
6. Show All Accounts
7. Delete Account
8. Exit
```

---

## Rules Implemented

- Minimum opening balance must be ₹500
- Withdrawal is allowed only if ₹500 minimum balance remains
- Invalid deposit or withdrawal amounts are rejected
- Every account gets a unique account number automatically

---

## Example Output

### Create Account

```txt
Enter Name: Anubhav
Enter Phone Number: 9876543210
Enter Initial Balance: 5000

Account Created Successfully
Your Account Number is: 1000
```

### Deposit Money

```txt
Enter Account Number: 1000
Enter Amount: 2000

Amount Successfully Deposit
```

### Withdraw Money

```txt
Enter Account Number: 1000
Enter Amount: 1000

Withdraw Successful
```

---

## Future Improvements

- Add Password/PIN Authentication
- Use Dynamic Memory Allocation or Vectors
- Add Interest Calculation
- Add Transaction History
- Add Admin Panel
- Convert into GUI Application
- Store Data using Database (MySQL)

---

## Learning Outcomes

Through this project, I learned:

- Basics of Object-Oriented Programming
- Working with Classes and Objects
- File Handling in C++
- Data Storage and Retrieval
- Building Menu-Driven Console Applications
- Implementing Banking Logic

---

## Author

Anubhav Gahlaut

---

## License

This project is for educational purposes only.
