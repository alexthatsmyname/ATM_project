# ATM_project
Short console-based application imitating a virtual ATM in C++ 

---

This C++ project is an ATM (Automated Teller Machine) simulation that emulates basic banking functionalities. Users can set a PIN, perform transactions such as deposit and withdrawal, check their balance, select a currency, and switch between currencies.

## Features

- **PIN Management:**
  - Users can set a personal identification number (PIN) for accessing the ATM functionalities.
  - PIN authentication is implemented to ensure secure access to the system.

- **Transaction Operations:**
  - Deposit: Users can deposit money into their account.
  - Withdrawal: Users can withdraw money from their account, with a balance check to prevent overdrawing.

- **Currency Selection:**
  - Users can choose their preferred currency from a list, including RON, EUR, USD, and HUF.

- **Balance Checking:**
  - Users can check their account balance in the selected currency.

- **Currency Switching:**
  - Users can switch between currencies, with automatic conversion of the balance.

## Usage

1. Run the program.
2. Set your PIN when prompted.
3. Perform transactions, check balance, and switch currencies as needed.

## How to Run

Compile the source code using a C++ compiler and execute the compiled binary.

```bash
g++ atm_simulation.cpp -o atm_simulation
./atm_simulation
```

## Requirements

- C++ compiler

## Contributing

Contributions are welcome! Feel free to open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

---

Feel free to customize this template based on additional details you want to provide or specific instructions for running the project.
