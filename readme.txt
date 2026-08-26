========================================
       E-COMMERCE STORE MANAGEMENT
========================================

DESCRIPTION:
This is a simple Store Management System developed
using C++. The system allows the user to manage
products using Object-Oriented Programming (OOP),
dynamic memory allocation, and vectors.

----------------------------------------
FEATURES:
----------------------------------------

[1] ADD PRODUCT
    - Add a new product.
    - Enter product name, price, and stock.
    - Prevents invalid price and stock values.

[2] VIEW PRODUCT
    - Displays all products.
    - Shows product name, price, and stock.

[3] UPDATE PRODUCT
    - Select an existing product.
    - Update its name, price, and stock.

[4] DELETE PRODUCT
    - Select a product to delete.
    - Removes the product from the system.

[5] EXIT
    - Exits the program.
    - Frees dynamically allocated memory.

----------------------------------------
TECHNOLOGIES USED:
----------------------------------------

Language:
C++

Concepts:
- Object-Oriented Programming (OOP)
- Classes and Objects
- Encapsulation
- Constructors
- Getters and Setters
- Dynamic Memory Allocation
- Pointers
- Vectors
- Loops
- Conditional Statements
- Input Validation
- Memory Management

----------------------------------------
HOW TO RUN:
----------------------------------------

1. Compile the C++ source code.
2. Run the compiled program.
3. Select an option from the main menu.
4. Follow the instructions shown on the screen.

----------------------------------------
DATA STRUCTURE:
----------------------------------------

The system uses:

vector<Product*> products;

The vector stores pointers to dynamically
allocated Product objects.

Products are created using:

new Product(...)

and deleted using:

delete products[index];

----------------------------------------
MEMORY MANAGEMENT:
----------------------------------------

Dynamic memory is released when a product is
deleted and when the program exits.

This prevents memory leaks caused by dynamically
allocated Product objects.

----------------------------------------
LIMITATIONS:
----------------------------------------

- Products are stored only while the program is running.
- Data is not yet saved to a file.
- No login or user authentication.
- No transaction or payment system yet.

----------------------------------------
FUTURE IMPROVEMENTS:
----------------------------------------

- Add file handling for permanent data storage.
- Add search product functionality.
- Add selling/checkout functionality.
- Add restock functionality.
- Add payment records.
- Add product categories.
- Add product IDs.
- Add customer management.

========================================