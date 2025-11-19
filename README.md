# 📚 Library Management System (C Language)

A simple and efficient **Library Management System** built using **C
language**, designed to perform basic operations such as adding,
displaying, searching, deleting, and updating books.\
The system uses **binary file handling** (`library.dat`) to store and
manage book records.

##  Features

### ✔ Add Book

Add a new book with: - Book ID\
- Title\
- Author\
- Quantity

### ✔ Display All Books

Shows a list of all books stored in the library database.

### ✔ Search Book

Search for a book using **Book ID** and display complete details.

### ✔ Delete Book

Remove a specific book from the library database using Book ID.

### ✔ Update Book

Modify an existing book's: - Title\
- Author\
- Quantity

### ✔ File Handling

All data is stored in a binary file named **`library.dat`**, allowing
persistence even after the program exits.

## 🧠 Concepts Used

-   Structures in C\
-   File Handling (`fopen`, `fread`, `fwrite`, `fseek`, `remove`,
    `rename`)\
-   Loops & Conditional Statements\
-   Switch-case Menu Driven Program\
-   String Handling (`fgets`, `strcspn`, `getchar`)

## 📁 File Structure

    /Library-Management-System
    │
    ├── library.c          # Main source code
    ├── library.dat        # Auto-generated book database file
    └── README.md          # Project documentation

## 🛠 How to Run

### 1️⃣ Compile the program

    gcc library.c -o library

### 2️⃣ Run the executable

    ./library

##  Sample Menu

    ===== Library Management System =====
    1. Add Book
    2. Display All Books
    3. Search Book
    4. Delete Book
    5. Update Book
    6. Exit
    Enter your choice:

## 🎯 Future Enhancements (Optional)

You can extend this project by adding: - User login system\
- Category-wise book management\
- Issue/return book system\
- Auto-increment book ID\
- Use JSON/CSV instead of binary files\
- Graphical interface (using GTK or web-based UI)

## 👨‍💻 Author

**Sabyasachi Jena**\
Library Management System in C -- Simple, Clean & Functional.


![image alt](https://github.com/sabyasachijena2007-design/LIBRARY-MANAGEMENT-SYSYTEM/blob/523290fd5a48078c4855195842cb270480633028/c%20output.jpg)

