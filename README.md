# 🏦 Bank Management System (OOP)

A comprehensive Banking Management System developed using **Object-Oriented Programming (OOP)** principles in C++. This system provides a secure and organized environment for managing client accounts and user permissions, while maintaining detailed logs of system operations.

---

## ✨ Key Features

### 👥 Client Management
* **CRUD Operations:** Full capability to Add, Update, and Delete client records.
* **Search & Listing:** Find specific clients and view the complete client database.
* **Financial Transactions:** Perform Deposits, Withdrawals, Transfers between accounts, and view total balances.

### 🔐 User & Security System
* **Secure Login:** Includes a login screen with a 3-attempt security lockout mechanism.
* **User Management:** Full CRUD operations for system users.
* **Permissions System:** An advanced access control system that restricts or grants access to specific screens based on the user's role.
* **Login Register:** Tracks login history (successful and failed attempts), including timestamps and user IDs.
* **Data Protection:** Implementation of security measures for both users and clients.
* **Currency Exchange:** A dedicated module to view, search, and update currency exchange rates, as well as calculate and compare currency values relative to the USD.

---

## 🛠️ OOP Concepts Applied

* **Inheritance:** Utilizes base and derived classes (e.g., `clsScreen` as the base class for UI elements).
* **Encapsulation:** Protects data integrity by managing access modifiers (`private`, `protected`, `public`).
* **Abstraction:** Simplifies complex operations by hiding implementation details behind clean interfaces.
* **Separation of Concerns:** Clearly separates the User Interface (UI) logic from the core Business Logic.

---

## 📂 Project Structure

* **`main.cpp`**: The entry point of the application.
* **`clsScreen.h`**: The base class for all UI screens, ensuring consistent design, headers, and navigation.
* **`clsMainScreen.h`**: The central hub from which all other system screens branch out.
* **`clsBankClient.h` & `clsUser.h`**: Core classes responsible for processing data for clients and users, including file handling.

---

## 🚀 How to Run

### Prerequisites
* A compiler supporting **C++11** or later (e.g., GCC, Clang, or Visual Studio).

