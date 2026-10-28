<h1 align="center">🚀 CPP Modules</h1>

<p align="center">
  <b>Modules 00 → 09 · C++98 · 1337 / 42 Network</b><br>
  A complete journey through Object-Oriented Programming in C++.
</p>

<p align="center">
  <img src="https://img.shields.io/badge/language-C%2B%2B98-blue" alt="C++98">
  <img src="https://img.shields.io/badge/school-1337%20%7C%2042-black" alt="1337">
  <img src="https://img.shields.io/badge/modules-10%2F10-brightgreen" alt="Modules">
  <img src="https://img.shields.io/badge/status-completed-success" alt="Status">
</p>

---

## 📑 Table of Contents

- [About](#-about)
- [Progress](#-progress)
- [Repository Structure](#-repository-structure)
- [Compilation & Usage](#-compilation--usage)
- [Rules & Constraints](#-rules--constraints)
- [Modules in Detail](#-modules-in-detail)
  - [CPP 00](#cpp-00--namespaces-classes--io-streams) · [CPP 01](#cpp-01--memory-references--pointers-to-members) · [CPP 02](#cpp-02--polymorphism-operators--canonical-form) · [CPP 03](#cpp-03--inheritance) · [CPP 04](#cpp-04--subtype-polymorphism--abstract-classes)
  - [CPP 05](#cpp-05--exceptions) · [CPP 06](#cpp-06--c-casts) · [CPP 07](#cpp-07--templates) · [CPP 08](#cpp-08--templated-containers--iterators) · [CPP 09](#cpp-09--stl)
- [Key Takeaways](#-key-takeaways)
- [Testing](#-testing)
- [Resources](#-resources)
- [Author](#-author)
- [Disclaimer](#️-disclaimer)

---

## 📖 About

This repository contains my solutions to all **10 CPP modules** of the 1337 / 42 curriculum.
The modules start with the basics of classes and streams, and progressively introduce inheritance, polymorphism, exceptions, casts, templates and finally the Standard Template Library — all in **C++98**.

---

## ✅ Progress

| Module | Topic |
|:------:|-------|
| 00 | Namespaces, classes, member functions, streams.
| 01 | Memory allocation, pointers/references to members. 
| 02 | Ad-hoc polymorphism, operator overloading, OCF.
| 03 | Inheritance.
| 04 | Subtype polymorphism, abstract classes, interfaces.
| 05 | Repetition and exceptions.
| 06 | C++ casts.
| 07 | C++ templates.
| 08 | Templated containers, iterators, algorithms.
| 09 | STL.

---

## 📂 Repository Structure

```
.
├── cpp00/
│   ├── ex00/   ├── ex01/   └── ex02/
├── cpp01/      (ex00 → ex06)
├── cpp02/      (ex00 → ex03)
├── cpp03/      (ex00 → ex03)
├── cpp04/      (ex00 → ex03)
├── cpp05/      (ex00 → ex03)
├── cpp06/      (ex00 → ex02)
├── cpp07/      (ex00 → ex02)
├── cpp08/      (ex00 → ex02)
├── cpp09/      (ex00 → ex02)
└── README.md
```

Each exercise is self-contained, with its own `Makefile`, `.hpp` headers and `.cpp` sources.

---

## ⚙️ Compilation & Usage

All projects are compiled with:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

| Rule | Description |
|------|-------------|
| `make` | Build the executable |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and the executable |
| `make re` | Rebuild from scratch |

```bash
git clone <repo-url> cpp-modules
cd cpp-modules/cpp00/ex00
make
./megaphone "shhhhh... I think the students are asleep..."
```

---

## 📏 Rules & Constraints

- Compile with `c++` and `-Wall -Wextra -Werror -std=c++98`
- No `using namespace` and no `friend`
- No C functions such as `printf()`, `malloc()`, `free()` — use `std::cout`, `new`, `delete`
- **STL forbidden until Module 08** (no `<vector>`, `<list>`, `<map>`, `<algorithm>`…)
- No external libraries, no C++11 or later, no Boost
- No memory leaks
- From Module 02 on, classes follow the **Orthodox Canonical Form**
- Class names in `UpperCamelCase`; files named after the class
- Include guards in every header; no function implementations in headers (except templates)

---

## 📚 Modules in Detail

### CPP 00 — Namespaces, Classes & I/O Streams

**Concepts:** namespaces, classes, member functions, `std::cout` / `std::cin`, initialization lists, `static`, `const`.

| Ex | Name | Description |
|----|------|-------------|
| 00 | `megaphone` | Prints its arguments in uppercase; prints a loud feedback noise when no argument is given. |
| 01 | `PhoneBook` | A small contact manager with `ADD`, `SEARCH` and `EXIT`. Stores up to 8 contacts (oldest gets replaced), displayed in a 10-character-wide, right-aligned, truncated table. |
| 02 | `Account` | Recreate the lost `Account.cpp` so the output matches the provided log (timestamps aside). |

```bash
cd cpp00/ex01 && make && ./phonebook
```

---

### CPP 01 — Memory, References & Pointers to Members

**Concepts:** stack vs heap allocation, pointers vs references, pointers to member functions, file streams, `switch`.

| Ex | Name | Description |
|----|------|-------------|
| 00 | `Zombie` | `newZombie()` (heap) and `randomChump()` (stack): when to allocate where. |
| 01 | `Zombie Horde` | `zombieHorde(N, name)` allocates N zombies in a single allocation. |
| 02 | `HI THIS IS BRAIN` | A string, a pointer to it, and a reference to it — compare addresses and values. |
| 03 | `Weapon` | `HumanA` (reference to a Weapon) vs `HumanB` (pointer to a Weapon). |
| 04 | `Sed is for losers` | Replace every occurrence of `s1` with `s2` in a file using `ifstream`/`ofstream`, without `std::string::replace`. |
| 05 | `Harl 2.0` | A `complain()` function dispatching to `debug`, `info`, `warning`, `error` using pointers to member functions (no if/else forest). |
| 06 | `Harl filter` | Filter Harl's complaints by minimum level using a `switch`. |

---

### CPP 02 — Polymorphism, Operators & Canonical Form

**Concepts:** ad-hoc polymorphism, operator overloading, Orthodox Canonical Form, fixed-point numbers.

| Ex | Name | Description |
|----|------|-------------|
| 00 | `Fixed` | First class in OCF; stores a fixed-point value with 8 fractional bits. |
| 01 | `Fixed` v2 | Constructors from `int` / `float`, `toInt()`, `toFloat()`, and `operator<<`. |
| 02 | `Fixed` v3 | Comparison, arithmetic and increment/decrement operators, plus static `min` / `max`. |
| 03 | `BSP` | `bsp(a, b, c, point)` — checks whether a point lies strictly inside a triangle. |

---

### CPP 03 — Inheritance

**Concepts:** single & multiple inheritance, constructor/destructor chaining, the diamond problem, virtual inheritance.

| Ex | Name | Description |
|----|------|-------------|
| 00 | `ClapTrap` | Base robot: `attack()`, `takeDamage()`, `beRepaired()` with hit points and energy points. |
| 01 | `ScavTrap` | Derived from `ClapTrap`; adds `guardGate()`. |
| 02 | `FragTrap` | Derived from `ClapTrap`; adds `highFivesGuys()`. |
| 03 | `DiamondTrap` | Inherits from both `ScavTrap` and `FragTrap` via virtual inheritance; adds `whoAmI()`. |

---

### CPP 04 — Subtype Polymorphism & Abstract Classes

**Concepts:** `virtual` functions, virtual destructors, deep copy, abstract classes, interfaces.

| Ex | Name | Description |
|----|------|-------------|
| 00 | `Polymorphism` | `Animal`, `Dog`, `Cat` — and `WrongAnimal` / `WrongCat` to show what happens without `virtual`. |
| 01 | `I don't want to set the world on fire` | Add a `Brain` (100 ideas) to `Dog` and `Cat`; ensure deep copies. |
| 02 | `Abstract class` | Make `Animal` abstract (not instantiable). |
| 03 | `Interface & recap` | `AMateria` (`Ice`, `Cure`), `ICharacter` / `Character`, `IMateriaSource` / `MateriaSource`. |

---

### CPP 05 — Exceptions

**Concepts:** `try` / `catch` / `throw`, custom exception classes, class hierarchies, a simple factory.

| Ex | Name | Description |
|----|------|-------------|
| 00 | `Bureaucrat` | Grade from 1 (highest) to 150 (lowest); throws `GradeTooHighException` / `GradeTooLowException`. |
| 01 | `Form` | A form with sign and execute grades; `Bureaucrat::signForm()`. |
| 02 | `AForm` | Abstract form + `ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`. |
| 03 | `Intern` | `makeForm(name, target)` creates the right form without a giant if/else chain. |

---

### CPP 06 — C++ Casts

**Concepts:** `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`, scalar types and literals.

| Ex | Name | Description |
|----|------|-------------|
| 00 | `ScalarConverter` | Static class converting a string literal to `char`, `int`, `float` and `double`, handling edge cases (`nan`, `inf`, overflow, non-displayable chars). |
| 01 | `Serializer` | `serialize()` / `deserialize()` between a pointer and `uintptr_t`. |
| 02 | `Identify real type` | `Base`, `A`, `B`, `C`; `generate()` and `identify()` for both pointer and reference — without `<typeinfo>`. |

---

### CPP 07 — Templates

**Concepts:** function templates, class templates, template specialization basics.

| Ex | Name | Description |
|----|------|-------------|
| 00 | `swap`, `min`, `max` | Generic function templates. |
| 01 | `iter` | Applies a function to every element of an array of any type. |
| 02 | `Array<T>` | Class template with deep copy, `operator[]`, `size()` and out-of-bounds exceptions. |

---

### CPP 08 — Templated Containers & Iterators

**Concepts:** STL containers, iterators, algorithms (first time allowed).

| Ex | Name | Description |
|----|------|-------------|
| 00 | `easyfind` | Finds the first occurrence of an integer in any container of integers. |
| 01 | `Span` | Stores up to N integers; `addNumber()`, `shortestSpan()`, `longestSpan()`; supports adding ranges via iterators. |
| 02 | `MutantStack` | A `std::stack` that is iterable — exposes the underlying container's iterators. |

---

### CPP 09 — STL

**Concepts:** choosing the right container, parsing, algorithms, performance comparison.

| Ex | Name | Description |
|----|------|-------------|
| 00 | `btc` | Bitcoin Exchange: reads a CSV price database and an input file (`date \| value`), outputs the value using the closest earlier date. |
| 01 | `RPN` | Reverse Polish Notation calculator, using a stack. |
| 02 | `PmergeMe` | Merge-insert sort (Ford–Johnson) on two different containers, with timing for each. |

---

## 🧠 Key Takeaways

- Knowing **when to use the stack vs the heap**, and always cleaning up
- Mastering the **Orthodox Canonical Form** and deep copies
- Understanding **virtual tables**, virtual destructors and abstract classes
- Using **exceptions** for clean error handling
- Picking the correct **C++ cast** for each situation
- Writing **generic code** with templates
- Choosing the right **STL container** based on complexity and use case

---

## 🧪 Testing

- Always write your own `main()` and test edge cases.
- Check memory with Valgrind:
  ```bash
  valgrind --leak-check=full --show-leak-kinds=all ./executable
  ```
- Or use AddressSanitizer while developing:
  ```bash
  c++ -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g *.cpp -o test
  ```

---

## 📖 Resources

Helpful material that I used while going through the modules:

| Resource | Description |
|----------|-------------|
| [LearnCpp.com](https://www.learncpp.com/) | Free, beginner-friendly C++ tutorial covering everything from basics to OOP, templates and the STL. |
| [cplusplus.com](https://cplusplus.com/) | Reference for the standard library (containers, iterators, algorithms, streams) with examples. |
| [Bhanu Prakash Eagala's Blog](https://bhanuprakasheagala.hashnode.dev/) | Blog posts and notes on C++ and 42 CPP modules. |
| [BogoToBogo C++ Tutorial](https://www.bogotobogo.com/cplusplus/cpptut.php) | In-depth C++ tutorials on classes, inheritance, templates, STL and more. |

---

<p align="center">⭐ If this helped you, feel free to star the repo!</p>
