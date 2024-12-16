# Decoratiuni Management System

A C++ application for managing a store's decorative items inventory. It allows you to insert, display, search, modify, and delete decorations like statuettes and shrubs.

---

## Features

1. **Insert Decorations**
   - Add new decorations (statuette or shrub) with attributes:
     - **Statuettes:** Unique series, price, height, material, author.
     - **Shrubs:** Unique series, price, name, type.

2. **Display Decorations**
   - View all stored decorations with their details.

3. **Search Decoration by Series**
   - Locate a decoration using its unique series number.

4. **Delete Shrub by Price**
   - Remove shrubs from the inventory based on their price.

5. **Update Statuette Price by Author**
   - Modify the price of a statuette by specifying its author.

---

## Class Structure

### `decoratiuni` (Base Class)
- **Attributes:** 
  - `serieUnica` (Unique series)
  - `pret` (Price)
- **Methods:** 
  - Virtual methods for displaying information and identifying decoration type.

### `statuete` (Derived Class)
- **Attributes:** 
  - `inaltime` (Height)
  - `material`
  - `autor` (Author)
- **Methods:** 
  - Additional methods for managing statuette-specific attributes.

### `arbusti` (Derived Class)
- **Attributes:** 
  - `denumire` (Name)
  - `tip` (Type)
- **Methods:** 
  - Additional methods for shrub-specific operations.

### `NodDecoratiune` (Linked List Node)
- **Purpose:** 
  - Links decorations dynamically in a linked list.

---

## How It Works

- Operates via a **menu-driven interface**.
- Users interact with the system through a series of options.
- Uses **dynamic memory allocation** and a **linked list** for efficient inventory management.

---

## Technologies Used

- **Language:** C++  
- **Paradigms:** Object-Oriented Programming (Inheritance, Polymorphism)  
- **Data Structures:** Linked List  

---

## Usage Instructions

1. Clone the repository:  
   ```bash
   git clone https://github.com/yourusername/Polymorphic-Lists.git

g++ -o PolymorphicLists PolymorphicLists.cpp

Follow the menu prompts to manage decorations.
