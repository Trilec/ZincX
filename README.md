# ZincX

**ZincX** is a modern, cross-platform, high-performance UI framework designed to modernize the classic Zinc library. It seamlessly bridges legacy systems (DOS/Win16) with contemporary platforms by leveraging the power of C++23 (via DJGPP GCC 14.2.0) and a modular, extensible architecture.

## Key Features
- **Fast & Lightweight:** Minimal overhead with direct STL use and optimized API design.
- **Elegant & Easy to Use:** Shallow class hierarchies and clear, modular interfaces.
- **Modular & Extensible:** Supports multiple rendering backends (DOS text mode, 16-bit, Vulkan, future APIs) and a unified compute module.
- **Rich Feature Set:** Integrated undo/redo, advanced image handling, dynamic layout management, robust event/input processing, and optional networking.
- **Legacy & Modern Support:** Conditional compilation for DOS/Win16 alongside full modern platform support.

/ZincX
   /src         // Contains all source code organized into subsystems:
      /common      // Core utilities, shared types (Point, Size, Color, Rect), logging, and configuration.
      /graphics    // Graphics subsystem: views, scenes, drawable items, and multiple rendering backends.
      /widgets     // UI components (e.g., buttons, text fields, combo boxes) built on top of graphics.
      /event       // Event system: definitions, propagation, and dispatching.
      /input       // Input handling: abstraction of devices and gesture recognition.
      /compute     // Unified API for asynchronous compute tasks (GPU/CPU processing).
      /layout      // Dynamic widget arrangement and responsive design (dock, grid, box layouts).
      /resource    // Resource management: loading, caching, and unloading of fonts, textures, shaders.
      /style       // Styling/theming and layered drawing system, including animations.
      /i18n        // Internationalization and accessibility support.
      /network     // (Optional) Networking module with a unified interface (legacy and modern).
      /debug       // Debugging and profiling tools.
   /include     // Public header files for external use, mirroring the module structure.
   /docs        // Detailed design documents, roadmap, contributing guidelines, etc.
   /test        // Unit tests and integration tests for ensuring robustness.
   /third_party // Only essential external libraries.
   CMakeLists.txt   // Build configuration file.
   README.md        // Project overview, instructions, and structure.
   LICENSE          // License file (e.g., Apache License 2.0).
   

## Getting Started
1. Clone the repository:
   ```bash
   git clone https://github.com/Trilec/ZincX/ZincX.git
