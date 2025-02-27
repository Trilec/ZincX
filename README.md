# ZincX

**ZincX** is a modern, cross-platform, high-performance UI framework designed to modernize the classic Zinc library. It seamlessly bridges legacy systems (DOS/Win16) with contemporary platforms by leveraging the power of C++23 (via DJGPP GCC 14.2.0) and a modular, extensible architecture.

## Key Features
- **Fast & Lightweight:** Minimal overhead with direct STL use and optimized API design.
- **Elegant & Easy to Use:** Shallow class hierarchies and clear, modular interfaces.
- **Modular & Extensible:** Supports multiple rendering backends (DOS text mode, 16-bit, Vulkan, future APIs) and a unified compute module.
- **Rich Feature Set:** Integrated undo/redo, advanced image handling, dynamic layout management, robust event/input processing, and optional networking.
- **Legacy & Modern Support:** Conditional compilation for DOS/Win16 alongside full modern platform support.

/ZincX
├── /src
│   ├── /common
│   │   ├── Contains core utilities, shared types (e.g., Point, Size, Color, Rect), logging, and configuration.
│   │   └── Examples: ZCommon.h, ZLog.cpp, ZConfig.h
│   │
│   ├── /graphics
│   │   ├── Implements the graphics subsystem including rendering views, scenes, and drawable items.
│   │   ├── Provides support for multiple rendering backends (e.g., DOS/text mode, Vulkan).
│   │   └── Examples: ZGraphicsView.cpp, ZGraphicsItem.cpp, IZGraphicsBackend.h
│   │
│   ├── /widgets
│   │   ├── Contains UI components built on top of the graphics and event systems.
│   │   └── Examples: ZButton.cpp, ZTextField.cpp, ZComboBox.cpp
│   │
│   ├── /event
│   │   ├── Manages event definitions, propagation, and dispatching.
│   │   └── Examples: ZEvent.h, ZEventManager.cpp
│   │
│   ├── /input
│   │   ├── Abstracts input devices and handles gesture recognition.
│   │   └── Examples: ZInputDevice.h, ZGestureRecognizer.cpp
│   │
│   ├── /compute
│   │   ├── Provides a unified API for asynchronous compute tasks (GPU/CPU).
│   │   └── Examples: ZCompute.cpp, IZComputeBackend.h
│   │
│   ├── /layout
│   │   ├── Manages dynamic widget arrangement and responsive design.
│   │   └── Examples: ZDock.cpp, ZGrid.cpp, ZLayoutConstraints.h
│   │
│   ├── /resource
│   │   ├── Handles loading, caching, and unloading of resources (fonts, textures, shaders).
│   │   └── Examples: ZResourceManager.cpp
│   │
│   ├── /style
│   │   ├── Manages the unified styling, theming, and layered drawing system.
│   │   └── Examples: ZStyle.cpp, ZAnimManager.cpp
│   │
│   ├── /i18n
│   │   ├── Provides internationalization and accessibility support.
│   │   └── Examples: ZLocale.cpp, ZAccessibility.cpp
│   │
│   ├── /network (Optional)
│   │   ├── Implements a unified networking interface, with legacy (DOS/Win16) and modern support.
│   │   └── Examples: ZNet.cpp
│   │
│   └── /debug
│       ├── Contains debugging and profiling tools to aid performance monitoring.
│       └── Examples: ZProfiler.cpp
│
├── /include
│   ├── Public header files for external use, mirroring the module structure in /src.
│   └── Examples: ZCommon.h, ZGraphicsView.h, etc.
│
├── /docs
│   ├── Contains detailed design documents, the comprehensive ZincX design plan, and the roadmap.
│   └── Consider adding files like DESIGN.md, ROADMAP.md, and CONTRIBUTING.md.
│
├── /test
│   ├── Unit tests and integration tests for ensuring robustness across modules.
│   └── Examples: test_compute.cpp, test_style.cpp, etc.
│
├── CMakeLists.txt       # Build configuration file.
├── README.md            # This file, with an overview and project structure.
└── LICENSE              # License file (e.g., Apache License 2.0).


## Getting Started
1. Clone the repository:
   ```bash
   git clone https://github.com/Trilec/ZincX/ZincX.git
