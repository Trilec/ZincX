# ZincX

**ZincX** is a modern, cross-platform, high-performance UI framework designed to modernize the classic Zinc library. It seamlessly bridges legacy systems (DOS/Win16) with contemporary platforms by leveraging the power of C++23 (via DJGPP GCC 14.2.0) and a modular, extensible architecture.

## Key Features
- **Fast & Lightweight:** Minimal overhead with direct STL use and optimized API design.
- **Elegant & Easy to Use:** Shallow class hierarchies and clear, modular interfaces.
- **Modular & Extensible:** Supports multiple rendering backends (DOS text mode, 16-bit, Vulkan, future APIs) and a unified compute module.
- **Rich Feature Set:** Integrated undo/redo, advanced image handling, dynamic layout management, robust event/input processing, and optional networking.
- **Legacy & Modern Support:** Conditional compilation for DOS/Win16 alongside full modern platform support.

## Project Structure
- **/src:** Contains the source code organized into subsystems (common, graphics, widgets, etc.).
- **/include:** Public headers for external use.
- **/docs:** Detailed design documents, including the comprehensive design plan for ZincX.
- **/test:** Unit tests and integration tests to ensure robustness.

## Getting Started
1. Clone the repository:
   ```bash
   git clone https://github.com/Trilec/ZincX/ZincX.git
