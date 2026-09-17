# 🚗 Car Rental Management System

A fully functional, console-based Car Rental System written in C++. This project demonstrates the use of Object-Oriented Programming (OOP) concepts and File Handling to manage car rentals, generate invoices, and securely store customer records.

## 🌟 Key Features
* **🔐 Secure Admin Login:** Includes a password-protected entry system (with `*` masking for typed characters) to ensure only authorized personnel can access the system.
* **🚘 Multiple Car Categories:** Users can select from various car types including Hatchback (Maruti Swift), Sedan (Honda City), SUV (Mahindra Thar), and Luxury (Audi A4), each with specific daily rates.
* **🧾 Automated Invoicing:** Automatically calculates the total payable amount based on the selected car's daily rate and the rental duration, generating a formatted official invoice.
* **💾 Database Storage (File Handling):** Saves all rental transaction details into a binary file (`RENTAL.DAT`). The data persists even after the program is closed.
* **📜 Record Management:** Allows the admin to read and display all past rental records fetched directly from the database file.

## 💻 Tech Stack & Environment
* **Language:** C++
* **Core Concepts:** Classes & Objects, Binary File I/O (`fstream.h`), Interactive Switch-Case Menus.
* **Compiler Base:** This code is written using classic Turbo C++ syntax (includes headers like `<conio.h>`, `<dos.h>`, and uses `void main()`).

*(Note for Modern C++ Users: To compile this on standard modern environments like VS Code/MinGW, proprietary headers like `<conio.h>` and `<dos.h>` will require standard alternatives, and `void main()` should be replaced with `int main()`.)*

## 🚀 How to Run the System
1. Compile and execute the program in a Turbo C++ environment.
2. At the login screen, enter the Admin password (default is set to `admin`).
3. From the Main Menu:
   * Select **1** to rent a new car, enter customer details, and generate an invoice.
   * Select **2** to view a complete log of all past rentals.
   * Select **3** to exit the application safely.
