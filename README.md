# ZincX

## ZincX – Comprehensive Design Document (V04)
(c) Curtis Edwards 2025

## Overview  
  Objective: Rebuild the classic Zinc library as ZincX—a modern, cross-platform, high-performance UI framework inspired by Zinc/OpenZinc, targeting legacy (DOS/Win16) and modern platforms (desktop, embedded) with a retro twist.  
  Reference Links: http://openzinc.com/Documentation/OpenZinc%201%20PROGRAMMERS%20REFERENCE%20VOLUME%201.pdf, http://openzinc.com/Documentation/OpenZinc%201%20PROGRAMMERS%20REFERENCE%20VOLUME%202.pdf, https://github.com/rafael2k/OpenZinc  
  Current GitHub: https://github.com/Trilec/ZincX  
  Key Attributes:  
    Fast & Lightweight: Minimal overhead with STL and optimized API for legacy and modern hardware.  
    Elegant & Easy to Use: Intuitive APIs with max three-level class hierarchy and modular interfaces.  
    Modular & Extensible: Multiple rendering backends (DOS text, 16-bit graphics, Vulkan) with unified compute module for layout, events, and drawing, using CPU/GPU where available, falling back to single-threaded for legacy.  
    Rich Feature Set:  
      * Undo/Redo & Serialization: Built-in state streaming.  
      * Image & Widget Library: Advanced image handling and pre-built widgets.  
      * Layout Management: Constraint-based layouts with compute acceleration.  
      * Event & Input Handling: Supports mouse, keyboard, multitouch, gestures.  
      * Custom Signal/Slot Framework: Type-safe, RAII-managed C++23 event system with multi-observation and optional thread safety.  
      * Styling, Theming & Layered Drawing: Compute-accelerated drawing (background, mid-ground, foreground) with global Theme and animation via ZAnimBase/ZAnimManager.  
      * Resource Management & Accessibility: Efficient caching, multilingual support, scalable fonts.  
    Reduced Third-Party Dependencies: Uses only essential libraries (e.g., single-header image loaders); networking leverages platform tools (DJGPP/Winsock).  
    Legacy Support & Compiler Standardization: Conditional compilation for DOS/Win16, standardized on DJGPP with GCC 14.2.0 for C++23, with C-style fallbacks for legacy.  
  Unified Subsystems: Includes Common Utilities, Graphics, Compute, MVC/MVP, Event/Input, Resource & Layout Management, Styling/Theming, plus Networking, Debugging, Testing.

## System Architecture  
  ZincX uses modular subsystems designed for minimal bloat, high performance, and easy integration, with common types and utilities centralized.

## Common & Utility Subsystem  
  Purpose: Provides shared types (Point, Size, Color, Rect) and utilities (logging, error handling, configuration) for all subsystems.  
  File Structure: /src/common ZCommon.h // Basic types: Point, Size, Color, Rect, etc. ZCommonEnums.h // Centralized enumerations ZLog.h / ZLog.cpp // Logging and error handling ZConfig.h // Global settings

## Graphics Subsystem  
  Core Classes: ZGraphicsView: Hosts ZGraphicsItem objects, applies transformations, dispatches events. ZGraphicsScene: Manages scene graph, layout, z-ordering. ZGraphicsItem: Base drawable widget with virtual draw and event callbacks.  
  Modular Rendering Backends: Abstracted via IZGraphicsBackend (DOS/Text, Vulkan, future APIs).  
  File Structure: /src/graphics ZGraphicsView.h, ZGraphicsView.cpp ZGraphicsScene.h, ZGraphicsScene.cpp ZGraphicsItem.h, ZGraphicsItem.cpp IZGraphicsBackend.h DOSGraphicsBackend.h, DOSGraphicsBackend.cpp VulkanGraphicsBackend.h, VulkanGraphicsBackend.cpp

## Compute Subsystem  
  Objective: Unified API for compute tasks (image filtering, layout recalculation) with asynchronous processing, leveraging CPU/GPU where available, falling back to single-threaded for legacy.  
  File Structure: /src/compute ZCompute.h, ZCompute.cpp IZComputeBackend.h VulkanComputeBackend.h, VulkanComputeBackend.cpp CPUComputeBackend.h, CPUComputeBackend.cpp

## MVC/MVP Subsystem  
  Components: ZModel: Holds data, supports observer registration. ZView_MVC: View derived from ZGraphicsItem. ZPresenter: Mediates model and view for event handling.  
  File Structure: /src/mvc ZModel.h, ZModel.cpp ZView_MVC.h, ZView_MVC.cpp ZPresenter.h, ZPresenter.cpp IZStateSerializable.h

## Event & Input Subsystems  
  Event Management  
    Purpose: Centralized event generation, propagation, handling (mouse, keyboard, multitouch).  
    Core Classes: ZEvent: Base event class with derived types (ZMouseEvent, ZKeyEvent). ZEventManager: Queues and dispatches events via bubble-up propagation.  
    File Structure: /src/event ZEvent.h ZEventManager.h, ZEventManager.cpp  
  Input Handling  
    Purpose: Abstracts raw input from devices (mouse, keyboard, touch) into actionable events.  
    Core Classes: ZInputDevice: Base interface for input devices. ZGestureRecognizer: Converts raw touch data into gesture events (pinch, swipe).  
    File Structure: /src/input ZInputDevice.h ZGestureRecognizer.h, ZGestureRecognizer.cpp

## Resource & Layout Management Subsystems  
  Resource Management  
    Purpose: Centralizes loading, caching, unloading of assets (fonts, textures, shaders) with a fast, lightweight LRU cache (16MB modern, 64KB DOS).  
    File Structure: /src/resource ZResourceManager.h, ZResourceManager.cpp  
  Layout Management  
    Purpose: Dynamically arranges UI widgets with responsive design and constraints, leveraging compute acceleration.  
    Components: Layout types: ZDock, ZSplitter, ZGrid, ZBox (ZHBox, ZVBox). Constraints: Defined via ZLayoutConstraints.  
    File Structure: /src/layout ZDock.h, ZDock.cpp ZSplitter.h, ZSplitter.cpp ZGrid.h, ZGrid.cpp ZBox.h, ZBox.cpp ZLayoutConstraints.h

## Memory Management in the Custom Signal/Slot Framework  
  Built in C++23, this type-safe, efficient event system uses RAII for memory management, supports multi-observation, and offers optional thread safety with compute acceleration where available.  
  Key Principles:  
    * RAII: Resources auto-cleaned via destructors.  
    * Type Safety: Templated signals ensure correct signatures.  
    * Multi-Observation: Slots stored in std::vector for multiple observers.  
    * Connection Management: RAII connection objects auto-disconnect.  
    * No Meta-Programming: Uses lambdas, templates, no macros.  
    * Thread Safety: Optional via ZINCX_THREAD_SAFE switch, with std::shared_mutex or single-threaded dummy.

## Styling, Theming & Layered Drawing Subsystem  
  Objective: Centralized styling with widgets rendering across background, mid-ground, and foreground layers, using a global Theme for defaults, state variations, and animations, with compute acceleration.  
  Core Structures & Classes: Style Elements & WidgetStyle: Define visual properties (background, border, text, shadow) with state-specific variations. Centralized Drawing Functions: Compute-accelerated routines (drawStyleElement, drawText, drawRect, drawCircle).  
  File Structure: /src/style ZStyle.h, ZStyle.cpp ZAnimBase.h, ZAnimBase.cpp ZAnimManager.h, ZAnimManager.cpp

## Widgets Subsystem  
  Overview: Pre-built UI components derive from ZWidget (extends ZView_MVC), integrating styling, layout, undo/redo.  
  Widget Interoperability: Supports composite widgets (ZTabPanel, ZComboBox) and data binding with models.  
  File Structure: /src/widgets ZWidget.h, ZWidget.cpp ZCompositeWidget.h, ZCompositeWidget.cpp ZButton.h, ZButton.cpp ZTextField.h, ZTextField.cpp ZComboBox.h, ZComboBox.cpp

## Additional Subsystems  
  Undo/Redo & Serialization: Manages state saving/restoring and scene serialization.  
    File Structure: /src/undo IZStateSerializable.h ZUndoRedoManager.h, ZUndoRedoManager.cpp ZSceneSerializer.h, ZSceneSerializer.cpp  
  Internationalization & Accessibility: Multilingual support and widget properties for assistive tech.  
    File Structure: /src/i18n ZLocale.h, ZLocale.cpp ZAccessibility.h, ZAccessibility.cpp  
  Printing: Platform-independent printing API.  
    File Structure: /src/printing ZPrinter.h, ZPrinter.cpp  
  Image Handling: Supports various image formats with extensible loader system.  
    File Structure: /src/image ZImage.h, ZImage.cpp ZImageData.h IZImageLoader.h ZImageLoaderRegistry.h, ZImageLoaderRegistry.cpp  
  Networking Module (Optional): Unified networking interface, using C-style sockets on DOS/Win16, C++23 networking on modern platforms.  
    File Structure: /src/network ZNet.h, ZNet.cpp  
  Debugging & Profiling: Built-in logging and performance counters.  
    File Structure: /src/debug ZProfiler.h, ZProfiler.cpp  
  Testing & Validation: Unit tests (Catch2), integration tests, benchmarks.  
    File Structure: /test test_compute.cpp test_graphics.cpp test_style.cpp

## Build System & Project Organization  
  Project Structure: /ZincX /src // Subsystem source files by module /include // Public headers /third_party // Essential external libraries CMakeLists.txt  
  Build Strategy: CMake with static/dynamic linking options, targeting C++17 base with DJGPP/GCC 14.2.0 for C++23 features and legacy fallbacks.


Summary  
  ZincX modernizes Zinc/OpenZinc with robust legacy support and C++23 capabilities via DJGPP GCC 14.2.0. Its modular architecture ensures a consistent, extensible experience, emphasizing clarity, efficient component grouping, and an elegant API for both retro and modern applications.

   

## Getting Started
1. Clone the repository:
   ```bash
   git clone https://github.com/Trilec/ZincX/ZincX.git
