# CPP Module 01 - Memory Allocation, Pointers to Members, References, and Switch Statement

## 📌 Project Overview
This project is part of the C++ modules at 42 School. The main objective of **C++ Module 01** is to transition from C-style memory management to C++ paradigms, focusing heavily on understanding the differences between **Stack** and **Heap** allocation, mastering **References** (`&`), and discovering **Pointers to Member Functions** to design scalable, clean Object-Oriented code without relying on massive conditional structures.

---

## 🧠 Core Concepts Learned
* **Memory Lifetimes:** Deep understanding of the Stack (automatic allocation/deallocation) versus the Heap (manual allocation using `new` and `delete`).
* **Pointers vs. References:** Learning when an object must exist (Reference) vs. when it is optional or modifiable (Pointer).
* **Memory Leaks Prevention:** Ensuring every dynamic allocation (`new` / `new[]`) is perfectly paired with its corresponding deletion (`delete` / `delete[]`).
* **Pointers to Member Functions:** Storing and executing class methods dynamically using function pointer arrays and the `this->*` syntax.
* **File Streams:** Manipulating files using C++ standard library streams (`std::ifstream` and `std::ofstream`).

---

## 📂 Exercises Breakdown

### Exercise 00: BraiiiiiiinnnzzzZ (Stack vs Heap)
* **Goal:** Implement a `Zombie` class and determine whether it is better to allocate zombies on the Stack or on the Heap depending on the use case.
* **Key Concept:** * `newZombie()` allocates on the **Heap** using `new` so the zombie survives outside the function scope.
  * `randomChump()` allocates on the **Stack**, meaning the zombie automatically dies when the function ends.
* **Takeaway:** The Heap gives you lifetime control but requires manual `delete` cleanup, whereas the Stack is self-managing and faster.

### Exercise 01: Moar brainz! (Array Allocation)
* **Goal:** Allocate an entire horde of $N$ zombies in a single memory allocation.
* **Key Concept:** Using `new[]` to allocate memory in a contiguous block. 
* **Takeaway:** When allocating an array dynamically, you must initialize the objects after allocation and safely free the entire block using `delete[]` to prevent memory leaks.

### Exercise 02: HI THIS IS BRAIN (Demystifying References)
* **Goal:** Create a string, a pointer to the string, and a reference to the string, then print their memory addresses and values.
* **Key Concept:** A **Reference** (`&`) is not a new variable; it is just an *alias* or a permanent nickname for an existing variable. It shares the exact same memory address and cannot be re-assigned or be `NULL`, unlike a pointer.

### Exercise 03: Unnecessary violence (Pointers vs References in Design)
* **Goal:** Implement a `Weapon` class and two human classes (`HumanA` and `HumanB`) that attack using that weapon.
* **Key Concept:**
  * `HumanA` always has a weapon $\rightarrow$ Uses a **Reference** (`Weapon&`).
  * `HumanB` can start unarmed and get a weapon later $\rightarrow$ Uses a **Pointer** (`Weapon*`).
* **Takeaway:** References guarantee that an attribute *must* exist from the start, while pointers allow for optional, missing, or modifiable states (`NULL`).

### Exercise 04: Sed is for losers (File Manipulation)
* **Goal:** Write a program that takes a filename and two strings (`s1` and `s2`), then creates a new file replacing every occurrence of `s1` with `s2`, without using `std::string::replace`.
* **Key Concept:** Using C++ file streams (`std::ifstream`/`std::ofstream`) and manual string manipulation loops using `std::string::find()` and string concatenation.

### Exercise 05: Harl 2.0 (Pointers to Member Functions)
* **Goal:** Create a class `Harl` that complains at 4 levels (`DEBUG`, `INFO`, `WARNING`, `ERROR`) without using a massive chain of `if/else if` statements.
* **Key Concept:** Implementing a look-up table mapping string levels to **Pointers to Member Functions** (`void (Harl::*funcs[])(void)`).
* **Takeaway:** Highly scalable design pattern that avoids spaghetti code by executing class methods dynamically using the `(this->*funcs[i])()` syntax.

---

## 🛠️ Compilation and Usage

The project is compiled strictly in **C++98** using the following flags:
```bash
-Wall -Wextra -Werror -std=c++98
