# MockOS

MockOS is a C++ implementation of a mock operating system that provides file management and command execution capabilities. This project is designed to simulate basic operating system functionalities and serves as an educational tool for understanding OS concepts.

## Features

- File system management (creation, deletion, reading, writing)
- Support for text and image files
- Password-protected files
- Command-line interface with various commands
- Extensible command system
- Visitor pattern for file operations
- Macro commands for complex operations

## Getting Started

### Prerequisites

- CMake (version 3.20 or higher)
- C++14 compatible compiler

### Building the Project

1. Clone the repository:
   ```
   git clone https://github.com/yourusername/mockos.git
   cd mockos
   ```

2. Create a build directory and navigate to it:
   ```
   mkdir build
   cd build
   ```

3. Generate the build files with CMake:
   ```
   cmake ..
   ```

4. Build the project:
   ```
   cmake --build .
   ```

### Running the Tests

To run the unit tests, execute the following command from the build directory:

```
ctest
```

### Running the MockOS

After building the project, you can run the MockOS executable:

```
./src/lab5
```

## Usage

MockOS provides a command-line interface with various commands for file and system management. Here are some example commands:

- `touch <filename>`: Create a new file
- `ls`: List all files in the system
- `cat <filename>`: Display and edit file contents
- `rm <filename>`: Remove a file
- `cp <source> <destination>`: Copy a file
- `ds <filename>`: Display file contents
- `rn <oldname> <newname>`: Rename a file

For more detailed information on each command, use the `help` command followed by the command name, e.g., `help touch`.

## Project Structure

- `include/`: Header files
- `lib/`: Source files for the MockOS library
- `src/`: Source files for executable programs
- `tests/`: Unit tests
- `docs/`: Documentation files