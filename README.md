# T-Shirt Sales System (C++ Console Application)

---

# Project Description

The T-Shirt Sales System is a console-based application that simulates a simple retail ordering system. Users can select T-shirt sizes (XS to XL), choose colours (Red, Blue, Black), and purchase items based on available stock.

The system manages stock levels, validates user input, calculates total price, and displays purchase details.

---

# Features

## 1. Display Menu
- Displays system introduction
- Provides user instructions
- Allows user to choose actions:
  - View stock availability
  - Purchase T-shirt
  - Exit system

---

## 2. Purchase Order System
- Allows user to select:
  - Size (XS, S, M, L, XL)
  - Colour (Red, Blue, Black)
  - Quantity
- Validates user input
- Checks stock availability before purchase

---

## 3. Input Loop
- Program runs in a loop until user chooses to exit
- Continuously allows new transactions

---

## 4. Stock Availability Check
- Ensures sufficient stock exists before confirming purchase
- Displays error message if stock is insufficient

---

## 5. Stock Update
- Automatically updates stock after successful purchase
- Prevents overselling of T-shirts

---

## 6. Purchase Summary
Displays:
- Selected size
- Selected colour
- Quantity purchased
- Price per T-shirt
- Subtotal amount

---

# Programming Concepts Used

This project demonstrates the use of:

- ✔ Selection statements (if-else, switch-case)
- ✔ Looping (do-while loops)
- ✔ Functions (modular programming)
- ✔ Arrays (multi-dimensional stock storage)

---

# Stock Structure

| Size | Red | Blue | Black | Price |
|------|-----|------|--------|--------|
| XS | 30 | 30 | 30 | RM25 |
| S  | 50 | 50 | 50 | RM25 |
| M  | 50 | 50 | 50 | RM30 |
| L  | 30 | 30 | 30 | RM30 |
| XL | 20 | 20 | 20 | RM35 |

---

# Program Validation

The system includes validation for:
- Invalid size input
- Invalid colour input
- Quantity exceeding stock
- Negative or zero quantity input

Error messages are displayed when invalid input is detected.

---