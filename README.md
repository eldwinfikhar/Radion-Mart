# Radion Mart (Terminal-Based C++ Application)

Radion Mart is a command-line shopping management program written in C++.  
It simulates a simple store workflow where you can manage customers, items, and purchase relationships directly from the terminal.

## Overview

This project implements a **multi-list data structure**:

- A linked list of customers
- A linked list of items
- A relation list per customer to store purchased items

The app is menu-driven and runs entirely in the terminal (no GUI).

## Main Features

1. Insert customer data
2. Insert item data
3. Record purchases for a customer
4. Display all customers (with or without purchase details)
5. Display all items
6. Delete a customer
7. Delete one purchase record from a customer
8. Search buyers of a specific item
9. Count number of purchased items by a customer

## Project Structure

```text
Radion-Mart/
├── Code/
│   ├── main.cpp          # Main menu flow and user interaction
│   ├── shopping.h        # Data structures, macros, function declarations
│   ├── shopping.cpp      # Core linked-list and relation operations
│   └── Tubes...cbp       # Code::Blocks project file
└── inputan.txt           # Sample terminal input sequence
```

## Requirements

- C++ compiler (g++, MinGW, or equivalent)
- Terminal/command prompt
- (Optional) Code::Blocks IDE for opening the `.cbp` project file

## Build and Run (g++)

From the repository root:

```bash
g++ -std=c++11 -Wall -Wextra -o radion-mart ./Code/main.cpp ./Code/shopping.cpp
./radion-mart
```

On Windows (Command Prompt):

```bat
g++ -std=c++11 -Wall -Wextra -o radion-mart.exe .\Code\main.cpp .\Code\shopping.cpp
radion-mart.exe
```

## Running in Code::Blocks

1. Open `Code/TubesSTD_IT-46-02_Kelompok05.cbp`
2. Build the project
3. Run the Debug/Release target in the IDE terminal console

## Input Notes

- Program input is interactive via terminal prompts.
- The file `inputan.txt` contains a full dummy input sequence you can copy-paste into the terminal.
- Because the program uses `cin >>`, values are token-based:
  - Use underscores (`_`) instead of spaces in names (example: `Arduino_Uno_R3`).

## Example Flow

Typical usage order:

1. Insert customers
2. Insert items
3. Record purchases
4. Show data / search / count
5. Delete customer or purchase if needed
6. Exit with menu option `0`

## Data Model Summary

- **Customer node**: `nama`, `id`, `pembelian` (total purchase value)
- **Item node**: `nama`, `jenis`, `harga`
- **Relation node**: connects one customer to one purchased item

This design demonstrates linked-list operations such as insertion, search, traversal, and deletion in a small terminal-based store system.

## Known Limitations

- No persistent storage (all data is in memory while the app runs).
- No input validation for many invalid/non-existing references.
- Single-threaded, local terminal execution only.

## Authoring Context

This repository appears to be an academic data-structure project focused on multi-list implementation and pointer-based operations in C++.
