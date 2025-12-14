# C++ Module 05: Exceptions, Inheritance, and Polymorphism

This module provides a comprehensive exploration of advanced C++ concepts, including exception handling, inheritance, polymorphism, abstract classes, and design patterns. Each exercise builds upon the last, creating a deeper understanding of how these features work together to build robust and maintainable software.
## Exercise 00: The Bureaucrat

### Concepts
- **Class Implementation:** Creation of the `Bureaucrat` class with private attributes and public member functions.
- **Exception Handling:** Custom exception classes (`GradeTooHighException` and `GradeTooLowException`) are defined to handle invalid grade values. This demonstrates the importance of robust error handling.
- **Operator Overloading:** The insertion operator (`<<`) is overloaded to allow for easy printing of `Bureaucrat` objects to output streams.
## Exercise 01: The Form

### Concepts
- **Class Interaction:** This exercise introduces the `Form` class, which interacts with the `Bureaucrat` class. It demonstrates how objects of different classes can collaborate.
- **Encapsulation:** The `Form` class encapsulates its own attributes and behaviors, such as signing status and grade requirements.
- **Exception Handling:** More complex exception handling is implemented to manage the signing process, ensuring that a `Bureaucrat` has the required grade to sign a `Form`.
## Exercise 02: The Forms

### Concepts
- **Abstract Classes:** The `AForm` class is introduced as an abstract base class, defining a common interface for all form types. It contains at least one pure virtual function, making it non-instantiable.
- **Inheritance:** Concrete form classes (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`) inherit from `AForm`, providing specific implementations for the pure virtual functions.
- **Polymorphism:** The use of a base class pointer (`AForm*`) to manage objects of derived classes demonstrates polymorphism, allowing for flexible and extensible code.
## Exercise 03: The Intern

### Concepts
- **Factory Pattern:** The `Intern` class implements a simple factory pattern. Its `makeForm` method takes a form name and a target, and returns a pointer to a newly created form object of the appropriate type. This decouples the client code from the concrete form classes.
- **Dynamic Allocation:** The `Intern` class uses dynamic allocation (`new`) to create form objects, which must be managed properly to avoid memory leaks.
