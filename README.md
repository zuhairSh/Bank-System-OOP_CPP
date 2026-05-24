# 🏦 Comprehensive Bank & Currency Management System

A production-ready, console-based desktop application written in **C++** that simulates a full-scale banking institution combined with a real-time currency exchange platform. This project showcases advanced software design, secure user authentication, financial transaction tracking, and object-oriented programming (OOP) at an elite level.

---

## 🌟 Project Overview & Core Concept
The purpose of this project is to provide a fully integrated system for managing a bank's daily operations. It allows bank employees (Users) to securely log in, manage client bank accounts, execute financial transactions (deposits, withdrawals, transfers), and perform multi-currency conversions using an integrated currency exchange engine. 

All data is permanently saved and updated across sessions using structured flat-file databases.

---

## ⚡ Key Features

### 👤 1. Full Client Management (CRUD)
* **Create Accounts:** Easily open new bank accounts with secure validation.
* **Search & Find:** Fast lookup for any client using their unique Account Number.
* **Update & Delete:** Modify client information dynamically or close accounts with strict safety checks.
* **Client Ledger:** Generate complete lists displaying all clients and their total balances.

### 💸 2. Financial Transactions Hub
* **Deposits & Withdrawals:** Process direct cash deposits and withdrawals into client accounts seamlessly.
* **Total Balances Report:** A dedicated overview showing the sum of all assets currently held in the bank.
* **Secure P2P Transfers:** Transfer funds safely between two distinct bank accounts.
* **Transfer Log Audit:** The system maintains an immutable history ledger capturing every single transfer operation (Sender, Receiver, Amount, and Timestamp) for accountability.

### 🔐 3. User Authentication & Permissions System
* **Secure Login Shield:** Restricts system access only to authorized employees with a tracking mechanism that logs login times and attempts.
* **Granular Permissions:** Admins can grant or deny access to specific screens (e.g., an employee might have permission to deposit money but is blocked from deleting users or clients).

### 💱 4. Advanced Currency Exchange Engine
* **Global Currency Lookup:** View an updated list of international currencies with their official exchange rates relative to the US Dollar ($USD$).
* **Live Currency Calculator:** Instantly convert amounts between any two international currencies using accurate, real-time logic.
* **Rate Updater:** Seamlessly modify exchange rates directly from the administrative panel.

---

## 🧠 Technical Highlights & Concepts Used
* **Bulletproof Input Validation:** The system is completely crash-proof. Every numeric entry, date, or character input is automatically checked using advanced C++ templates to reject invalid inputs.
* **Strict Object-Oriented Design (OOP):** Deep implementation of Encapsulation, Polymorphism, and Multi-level Inheritance to ensure the code is modular and clean.
* **Architecture:** Adheres to a strict "One Class, One File" architectural pattern, splitting the business logic completely away from UI screens.

---

## 🧑‍💻 Development Context
This system represents the ultimate capstone project of the **ProgrammingAdvices Roadmap (Level 11)**, engineered under the guidance of **Dr. Mohammed Abu-Hadhoud**.
