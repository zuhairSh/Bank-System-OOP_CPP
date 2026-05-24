# 🏦 Bank & Currency Management System (C++ & OOP)

A robust, enterprise-grade console application representing a comprehensive **Bank and Currency Management System**. Built entirely in **C++**, this project reflects advanced software design principles, strict validation mechanisms, and modular architecture.

---

## 🛠️ System Components & Architecture

The system is highly decoupled, cleanly separating core data models, business logic controllers, and presentation screens.

### 1. Core Core Models & Utilities
* **`clsBankClients.h` / `BankClient.cpp`**: Manages customer identities, core accounting logic, and balances.
* **`clsUser.h`**: Represents system employees and administrators with distinct authorization access.
* **`clsCurrency.h` / `Currencies.txt`**: Complete currency models tracking international exchange rates.
* **`clsString.h` / `clsDate.h` / `clsUtil.h`**: Custom standalone utility libraries built from scratch to manipulate data, handle dates, and format inputs.

### 2. Banking Screens (`Library/`)
* **Client Workflows**: Implementation of strict CRUD actions via `clsAddNewClient.h`, `clsFindClientScreen.h`, `clsUpdateClient.h`, and `clsDeleteClient.h`.
* **Transactions Hub**: Facilitates secure financial movements via `clsDepositScreen.h`, `clsWithdrawScreen.h`, and `clsTotalBalance.h`.
* **Transfer Engine**: Supports internal peer-to-peer account transfers, logging audit details permanently via `clsTransfer.h` and `clsTransferLog.h`.

### 3. User & Access Security
* **Access Control**: Handled sequentially via `clsLogin.h`, tracking historical sessions on `LoginRegister.txt`.
* **Administrative Console**: Grants master users the ability to manage operators via `clsManageUsersScreen.h` and `clsListUser.h`.

### 4. Currency Exchange Engine
* **Calculations & Rates**: Active real-time rate viewing and cross-currency conversions using `clsCurrencyList.h`, `clsMainCurrency.h`, and `clsCurrencyCalculator.h`.

---

## 💾 Data Persistence Layer
The application maintains state across restarts by utilizing structured flat-file database storage:
* `Data_Clients.txt` - Stores balances and secure client profiles.
* `Users.txt` - Stores credentials and bitwise permission tags.
* `LoginRegister.txt` - Logs every successful authentication time frame.
* `TransferData.txt` - An immutable ledger capturing P2P financial histories.

---

## 🚀 Key Technical Highlights
* **Object-Oriented Integrity**: Intense usage of Encapsulation, Polymorphism, and Multi-level Inheritance (`clsScreen` $\rightarrow$ `clsMainScreen`).
* **Input Bulletproofing**: Dual-layer filtering handled via generic templates in `clsInputValidation.h` and `clsInputValidation2.h`.
* **Clean Code Structure**: Avoided massive files by adopting a strict "One Class, One File" architectural approach.

---

## 🧑‍💻 Academic Context
This system represents the culmination of advanced software engineering concepts practiced under the **ProgrammingAdvices Roadmap (Level 11)** curated by **Dr. Mohammed Abu-Hadhoud**.
