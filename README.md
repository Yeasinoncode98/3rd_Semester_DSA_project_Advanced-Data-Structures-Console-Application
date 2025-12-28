# 🚀 Advanced Data Structures Console Application

<div align="center">

![Version](https://img.shields.io/badge/version-1.0.0-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)
![Language](https://img.shields.io/badge/language-C-orange.svg)

**A visually stunning, interactive console application for learning and visualizing fundamental data structures**

[Features](#-features) • [Installation](#-installation) • [Usage](#-usage) • [Screenshots](#-screenshots) • [Contributing](#-contributing)

</div>

---

## 📖 Overview

The **Advanced Data Structures Console Application** is an educational and interactive tool designed to help students, developers, and computer science enthusiasts understand and visualize fundamental data structures through a beautiful retro-styled console interface with animations and color-coded outputs.

### 👨‍💻 Developer

**Yeasin Arafat**  
Department of Computer Science and Engineering  
Daffodil International University  
4th Semester

### 🎯 Educational Value

- **Visual Learning**: See data structures come to life with animated visualizations
- **Interactive Exploration**: Hands-on experience with real-time operations
- **Cross-Platform**: Works seamlessly on Windows, Linux, and macOS
- **Performance Optimized**: Efficient implementations with proper memory management

---

## ✨ Features

### 🔗 Linked List Implementation
- Dynamic node insertion and deletion
- Visual representation of linked structure
- Animated traversal with step-by-step visualization
- Real-time pointer tracking

### 📚 Stack Operations
- Push and pop operations with visual feedback
- Stack overflow and underflow detection
- Top-to-bottom vertical visualization
- Color-coded status indicators

### 🎫 Queue Management
- Enqueue and dequeue operations
- Circular queue implementation
- Front and rear pointer visualization
- Animated operation sequences

### 🌳 Binary Search Tree
- Dynamic node insertion with automatic balancing
- Three traversal methods (Inorder, Preorder, Postorder)
- Hierarchical tree visualization
- Animated traversal demonstrations

### 🎨 User Interface
- Retro ASCII art design with box-drawing characters
- Typewriter effect for text animation
- Loading animations with progress bars
- Color-coded outputs for better readability
- Flashing text effects for important messages

---

## 🛠️ Installation

### Prerequisites

**Windows:**
- MinGW-w64 or Visual Studio with C compiler
- Windows Command Prompt or PowerShell

**Linux/macOS:**
- GCC compiler
- Terminal with ANSI color support

### Compilation Instructions

#### Windows (MinGW)
```bash
gcc -o data_structures.exe data_structures.c -std=c99
```

#### Windows (Visual Studio)
```bash
cl /Fe:data_structures.exe data_structures.c
```

#### Linux/macOS
```bash
gcc -o data_structures data_structures.c -std=c99
chmod +x data_structures
```

### Quick Start
```bash
# Clone or download the source file
# Navigate to the directory
# Compile using the appropriate command above
# Run the application
./data_structures        # Linux/macOS
data_structures.exe      # Windows
```

---

## 💻 Usage

### Main Menu Navigation

Upon launching the application, you'll be greeted with a colorful retro-styled main menu:

```
╔══════════════════════════════════════════════════════════╗
║                                                          ║
║     ADVANCED DATA STRUCTURES CONSOLE APPLICATION         ║
║                                                          ║
╚══════════════════════════════════════════════════════════╝

           Eat Code Coode Coooode Sleep!

┌──────────────────────────────────────────────────────────┐
│ Main Menu                                                │
├──────────────────────────────────────────────────────────┤
│ 1. Linked List Demonstration                            │
│ 2. Stack Implementation                                 │
│ 3. Queue Implementation                                 │
│ 4. Binary Tree Visualization                            │
│ 0. Exit Program                                         │
└──────────────────────────────────────────────────────────┘
```

### Data Structure Operations

#### 1️⃣ Linked List Operations
- **Insert Node**: Add elements to the end of the list
- **Delete Node**: Remove specific elements
- **Animate Traversal**: Watch the pointer move through the list

Example visualization:
```
[10] -> [20] -> [30] -> [40] -> NULL
```

#### 2️⃣ Stack Operations
- **Push**: Add elements to the top
- **Pop**: Remove elements from the top

Example visualization:
```
┌───────┐
│    40 │  ← TOP
├───────┤
│    30 │
├───────┤
│    20 │
├───────┤
│    10 │
├───────┤
└───────┘
```

#### 3️⃣ Queue Operations
- **Enqueue**: Add elements to the rear
- **Dequeue**: Remove elements from the front
- **Animate Operations**: Watch automatic enqueue/dequeue sequences

Example visualization:
```
FRONT → [10] → [20] → [30] → [40] ← REAR
```

#### 4️⃣ Binary Tree Operations
- **Insert Node**: Add nodes following BST rules
- **Traversals**: View Inorder, Preorder, and Postorder
- **Animate**: See all traversals in sequence

Example visualization:
```
                    [50]
               [30]
          [20]
               [40]
                    [70]
               [60]
                    [80]
```

---

## 🎨 Screenshots

### Main Interface
The application features a vibrant, color-coded interface with:
- **Magenta** headers and borders
- **Cyan** prompts and highlights
- **Green** success messages
- **Red** error warnings
- **Yellow** informational boxes

### Animation Effects
- **Typewriter Effect**: Smooth character-by-character text display
- **Loading Bars**: Progress indicators for initializations
- **Flashing Text**: Attention-grabbing important messages
- **Traversal Animations**: Step-by-step visualization of operations

---

## 🏗️ Architecture

### Code Structure

```
data_structures.c
├── Platform-Specific Includes
│   ├── Windows (windows.h, conio.h)
│   └── Unix/Linux (termios.h, unistd.h)
├── Cross-Platform Utilities
│   ├── clear()
│   ├── setColor()
│   ├── getch_wrapper()
│   └── SLEEP()
├── Animation Functions
│   ├── typewriter()
│   ├── loadingAnimation()
│   └── flashText()
├── Data Structures
│   ├── Linked List (Node)
│   ├── Stack
│   ├── Queue
│   └── Binary Tree (TreeNode)
└── Demonstration Functions
    ├── linkedListDemo()
    ├── stackDemo()
    ├── queueDemo()
    └── binaryTreeDemo()
```

### Design Patterns

- **Modular Design**: Each data structure is self-contained
- **Memory Safety**: Proper allocation and deallocation
- **Error Handling**: Input validation and boundary checks
- **Cross-Platform Compatibility**: Conditional compilation for different OS

---

## 🔧 Technical Details

### Supported Platforms
- ✅ Windows 10/11 (Command Prompt, PowerShell, Windows Terminal)
- ✅ Linux (most distributions with GCC)
- ✅ macOS (with Xcode Command Line Tools)

### Compiler Support
- GCC 4.8+
- Clang 3.4+
- MSVC 2015+

### Language Standard
- C99 or later

### Dependencies
- Standard C Library
- Platform-specific APIs (windows.h for Windows, termios.h for Unix)

---

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/AmazingFeature`)
3. **Commit** your changes (`git commit -m 'Add some AmazingFeature'`)
4. **Push** to the branch (`git push origin feature/AmazingFeature`)
5. **Open** a Pull Request

### Areas for Contribution
- Additional data structures (AVL trees, graphs, hash tables)
- Enhanced visualizations
- Performance optimizations
- Extended platform support
- Bug fixes and improvements
- Documentation enhancements

---

## 📝 License

This project is licensed under the MIT License - see below for details:

```
MIT License

Copyright (c) 2025 Yeasin Arafat

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

---

## 🎓 Educational Resources

### Learn More About Data Structures
- [GeeksforGeeks - Data Structures](https://www.geeksforgeeks.org/data-structures/)
- [Visualgo - Visualizing Data Structures](https://visualgo.net/)
- [CS50 - Harvard's Introduction to Computer Science](https://cs50.harvard.edu/)

### Related Topics
- Algorithm complexity (Big O notation)
- Memory management in C
- Cross-platform C programming
- Console application development

---

## 📞 Support

Encountered an issue or have a question?

- 🐛 **Bug Reports**: Open an issue with detailed description
- 💡 **Feature Requests**: Share your ideas for improvements
- 📖 **Documentation**: Check this README and code comments
- 💬 **Discussions**: Join conversations about the project

---

## 🌟 Acknowledgments

- Developed by **Yeasin Arafat** as part of CSE curriculum at Daffodil International University
- Inspired by classic computer science education tools
- ASCII art design influenced by retro computing aesthetics
- Built with passion for teaching and learning

---

## 📊 Project Status

**Current Version**: 1.0.0  
**Developer**: Yeasin Arafat  
**Institution**: Daffodil International University  
**Department**: Computer Science and Engineering  
**Status**: Active Development  
**Last Updated**: December 2025

### Roadmap
- [ ] Add graph data structure
- [ ] Implement AVL tree
- [ ] Add hash table visualization
- [ ] Create GUI version
- [ ] Add save/load functionality
- [ ] Performance benchmarking tools

---

<div align="center">

**Made with ❤️ for Computer Science Education**

**Developed by Yeasin Arafat**  
*Department of CSE, Daffodil International University*

⭐ Star this project if you found it helpful!

[Back to Top](#-advanced-data-structures-console-application)

</div>