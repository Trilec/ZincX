/**
 * @file ZCommonEnums.h
 * @brief Centralized enumeration definitions for the ZincX framework.
 *
 * This header file contains a comprehensive set of enumeration types used across the ZincX UI framework.
 * These enums are designed to provide consistent, framework-wide definitions for various states, types,
 * and configurations, ensuring uniformity and reducing redundancy across subsystems.
 *
 * Enums are organized by subsystem for easy reference and include:
 * - Graphics-related enums (e.g., RenderMode, CoordinateSystem)
 * - Widget states and types (e.g., WidgetState, WidgetType)
 * - Event and input classifications (e.g., EventType, InputDeviceType)
 * - Compute and layout configurations (e.g., ComputeBackend, LayoutOrientation)
 * - Resource management states (e.g., LoadState)
 * - Styling options (e.g., BorderStyle, FontWeight)
 * - Internationalization and accessibility roles (e.g., Language, AccessibilityRole)
 * - Networking protocols and states (e.g., Protocol, ConnectionState)
 * - Debugging and profiling categories (e.g., LogLevel, ProfilingCategory)
 * - General platform and error codes (e.g., Platform, ErrorCode)
 *
 * These enums are intended to be used throughout the framework to ensure consistent behavior and
 * to facilitate platform-specific or subsystem-specific logic where necessary.
 *
 * @note This file is part of the ZincX framework's common utilities and should be included wherever
 *       these enums are needed.
 */

#ifndef ZINCX_COMMON_ENUMS_H
#define ZINCX_COMMON_ENUMS_H

namespace ZincX {

// Graphics
/**
 * @brief Specifies the active rendering backend.
 *
 * This enum is used to select the rendering backend appropriate for the platform or desired capabilities.
 */
enum class RenderMode {
    Text,      ///< Text-based rendering, suitable for DOS or console environments.
    Graphics16, ///< 16-bit graphics rendering, suitable for Win16 or similar environments.
    Vulkan     ///< Vulkan-based rendering, suitable for modern platforms with GPU support.
};

/**
 * @brief Differentiates between coordinate systems used in rendering.
 *
 * This enum helps in managing coordinate transformations between screen and world spaces.
 */
enum class CoordinateSystem {
    Screen, ///< Screen coordinate system, typically pixel-based.
    World   ///< World coordinate system, typically used for game or simulation logic.
};

// Widgets
/**
 * @brief Represents the various states a widget can be in.
 *
 * Widgets can change their appearance and behavior based on their state.
 */
enum class WidgetState {
    Normal,   ///< The default state of the widget.
    Hovered,  ///< The widget is being hovered over by the cursor.
    Pressed,  ///< The widget is being pressed.
    Disabled  ///< The widget is disabled and cannot be interacted with.
};

/**
 * @brief Categorizes different types of widgets.
 *
 * This enum can be used for type checking or dynamic behavior based on widget type.
 */
enum class WidgetType {
    Button,    ///< A button widget.
    TextField, ///< A text input field widget.
    ComboBox   ///< A combo box widget.
};

// Events
/**
 * @brief Classifies different types of events handled by the framework.
 *
 * This enum is crucial for event handling and dispatching.
 */
enum class EventType {
    MouseClick, ///< A mouse click event.
    KeyPress,   ///< A key press event.
    TouchStart  ///< A touch start event.
};

/**
 * @brief Indicates keyboard modifiers for input events.
 *
 * This enum helps in determining if modifier keys were pressed during an event.
 */
enum class KeyModifier {
    None,  ///< No modifier key was pressed.
    Shift, ///< The shift key was pressed.
    Ctrl,  ///< The control key was pressed.
    Alt    ///< The alt key was pressed.
};

// Input
/**
 * @brief Identifies the type of input device generating an event.
 *
 * This enum is used to differentiate between various input sources.
 */
enum class InputDeviceType {
    Mouse,     ///< Mouse device.
    Keyboard,  ///< Keyboard device.
    Touchpad   ///< Touchpad device.
};

/**
 * @brief Defines supported gestures for touch or advanced input systems.
 *
 * This enum is used in gesture recognition.
 */
enum class GestureType {
    Swipe, ///< A swipe gesture.
    Pinch, ///< A pinch gesture.
    Tap    ///< A tap gesture.
};

// Compute
/**
 * @brief Specifies the compute backend in use.
 *
 * This enum allows the framework to switch between different compute backends.
 */
enum class ComputeBackend {
    Vulkan, ///< Vulkan-based compute backend.
    CPU     ///< CPU-based compute backend.
};

/**
 * @brief Assigns priority levels to compute tasks.
 *
 * This enum helps in managing the execution order of compute tasks.
 */
enum class TaskPriority {
    Low,    ///< Low priority task.
    Medium, ///< Medium priority task.
    High    ///< High priority task.
};

// Layout
/**
 * @brief Determines the orientation of layouts.
 *
 * This enum is used in layouts like box layouts to specify direction.
 */
enum class LayoutOrientation {
    Horizontal, ///< Horizontal orientation.
    Vertical    ///< Vertical orientation.
};

/**
 * @brief Specifies alignment options within a layout.
 *
 * This enum is used to align widgets within their layout containers.
 */
enum class LayoutAlignment {
    Start,   ///< Align to the start of the layout.
    Center,  ///< Center alignment.
    End,     ///< Align to the end of the layout.
    Stretch  ///< Stretch to fill the layout.
};

// Resource Management
/**
 * @brief Categorizes different types of resources managed by the framework.
 *
 * This enum helps in identifying and handling different resource types.
 */
enum class ResourceType {
    Texture, ///< Texture resource.
    Font,    ///< Font resource.
    Shader   ///< Shader resource.
};

/**
 * @brief Tracks the loading status of resources.
 *
 * This enum is used to monitor the state of resource loading operations.
 */
enum class LoadState {
    Loading, ///< Resource is currently loading.
    Loaded,  ///< Resource has been successfully loaded.
    Failed   ///< Resource loading failed.
};

// Style
/**
 * @brief Defines styles for widget borders.
 *
 * This enum specifies how borders are drawn.
 */
enum class BorderStyle {
    Solid,  ///< Solid border.
    Dashed, ///< Dashed border.
    Dotted  ///< Dotted border.
};

/**
 * @brief Specifies font weight options for text styling.
 *
 * This enum is used to set the weight of text in widgets.
 */
enum class FontWeight {
    Normal, ///< Normal font weight.
    Bold,   ///< Bold font weight.
    Light   ///< Light font weight.
};

/**
 * @brief Sets text alignment within widgets or layouts.
 *
 * This enum determines how text is aligned.
 */
enum class TextAlignment {
    Left,      ///< Left-aligned text.
    Center,    ///< Center-aligned text.
    Right,     ///< Right-aligned text.
    Justified  ///< Justified text.
};

// Internationalization & Accessibility
/**
 * @brief Represents supported languages for internationalization.
 *
 * This enum is used to set the language for UI elements.
 */
enum class Language {
    English, ///< English language.
    Spanish, ///< Spanish language.
    French   ///< French language.
};

/**
 * @brief Defines roles for accessibility features.
 *
 * This enum helps in making the UI accessible by defining widget roles.
 */
enum class AccessibilityRole {
    Button,   ///< Button role.
    Checkbox, ///< Checkbox role.
    Slider    ///< Slider role.
};

// Networking
/**
 * @brief Specifies the networking protocol in use.
 *
 * This enum is used to select the protocol for network communications.
 */
enum class Protocol {
    TCP, ///< TCP protocol.
    UDP  ///< UDP protocol.
};

/**
 * @brief Tracks the state of network connections.
 *
 * This enum is used to monitor the status of network connections.
 */
enum class ConnectionState {
    Connecting,   ///< Connection is being established.
    Connected,    ///< Connection is established.
    Disconnected, ///< Connection is disconnected.
    Failed        ///< Connection failed.
};

// Debugging & Profiling
/**
 * @brief Controls the verbosity of logging output.
 *
 * This enum is used to filter log messages based on their severity.
 */
enum class LogLevel {
    Debug,   ///< Debug level logging.
    Info,    ///< Info level logging.
    Warning, ///< Warning level logging.
    Error,   ///< Error level logging.
    Fatal    ///< Fatal level logging.
};

/**
 * @brief Categorizes profiling data for performance analysis.
 *
 * This enum helps in organizing profiling information.
 */
enum class ProfilingCategory {
    Rendering, ///< Rendering related profiling.
    Compute,   ///< Compute related profiling.
    Input      ///< Input related profiling.
};

// General
/**
 * @brief Identifies the target platform for platform-specific code.
 *
 * This enum is used in conditional compilation or runtime checks.
 */
enum class Platform {
    DOS,      ///< DOS platform.
    Win16,    ///< Windows 16-bit platform.
    Windows,  ///< Modern Windows platform.
    MacOS,    ///< macOS platform.
    Linux,    ///< Linux platform.
    Embedded  ///< Embedded systems platform.
};

/**
 * @brief Provides a unified set of error codes for consistent error handling.
 *
 * This enum is used across the framework for standardized error reporting.
 */
enum class ErrorCode {
    Success,           ///< Operation was successful.
    InvalidArgument,   ///< Invalid argument provided.
    ResourceNotFound   ///< Resource was not found.
};

} // namespace ZincX

#endif // ZINCX_COMMON_ENUMS_H