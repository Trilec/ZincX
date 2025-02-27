/**
 * @file ZCommon.h
 * @brief Defines foundational types, utility functions, time/error utilities, and enums for the ZincX framework.
 *
 * This file contains the essential data types used throughout ZincX. In addition to basic geometric types
 * like points, sizes, colors, rectangles, circles, and lines, it provides transformation types (vectors and matrices),
 * a suite of utility functions (clamp, lerp, distance), time measurement utilities, and a custom exception class.
 * It also defines a comprehensive set of enums that standardize configuration across various subsystems
 * (graphics, widgets, events, input, compute, layout, resource management, style, internationalization, networking,
 * debugging, and general configuration).
 */

#pragma once

#include <cmath>
#include <chrono>
#include <exception>
#include <string>

namespace ZincX {

/*==================== Fundamental Types ====================*/

/**
 * @brief Represents a 2D point in Cartesian coordinates.
 */
struct ZPoint {
    int x; /**< The X-coordinate. */
    int y; /**< The Y-coordinate. */
};

/**
 * @brief Represents the dimensions of an object.
 */
struct ZSize {
    int width;  /**< The width of the object. */
    int height; /**< The height of the object. */
};

/**
 * @brief Represents a color with red, green, blue, and alpha components.
 */
struct ZColor {
    int r; /**< Red component (0-255). */
    int g; /**< Green component (0-255). */
    int b; /**< Blue component (0-255). */
    int a; /**< Alpha component (0-255), defaults to 255 (opaque). */

    /**
     * @brief Constructs a ZColor.
     * @param red Red value.
     * @param green Green value.
     * @param blue Blue value.
     * @param alpha Alpha value, default is 255.
     */
    ZColor(int red, int green, int blue, int alpha = 255)
        : r(red), g(green), b(blue), a(alpha) {}
};

/**
 * @brief Represents padding values for layout calculations.
 *
 * Padding defines the space between an element's boundary and its content.
 */
struct ZPadding {
    int left;   /**< Padding on the left side. */
    int top;    /**< Padding on the top side. */
    int right;  /**< Padding on the right side. */
    int bottom; /**< Padding on the bottom side. */
};

/**
 * @brief Represents margin values for layout calculations.
 *
 * Margin defines the space between an element and adjacent elements.
 */
struct ZMargin {
    int left;   /**< Margin on the left side. */
    int top;    /**< Margin on the top side. */
    int right;  /**< Margin on the right side. */
    int bottom; /**< Margin on the bottom side. */
};

/**
 * @brief Represents a rectangle defined by its top-left corner and dimensions.
 */
struct ZRect {
    int x;      /**< X-coordinate of the top-left corner. */
    int y;      /**< Y-coordinate of the top-left corner. */
    int width;  /**< Width of the rectangle. */
    int height; /**< Height of the rectangle. */
    
    /**
     * @brief Returns a new rectangle reduced by the specified padding.
     *
     * This function subtracts the provided padding values from the rectangle's dimensions
     * and adjusts its position accordingly.
     *
     * @param padding The padding to apply.
     * @return A new ZRect after applying the padding.
     */
    ZRect deflate(const ZPadding& padding) const {
        return { x + padding.left, y + padding.top,
                 width - padding.left - padding.right,
                 height - padding.top - padding.bottom };
    }
};

/**
 * @brief Represents a circle defined by a center point and a radius.
 */
struct ZCircle {
    ZPoint center; /**< Center of the circle. */
    int radius;    /**< Radius of the circle. */

    /**
     * @brief Determines if a given point lies within the circle.
     * @param point The point to test.
     * @return True if the point is inside the circle; false otherwise.
     */
    bool contains(const ZPoint& point) const {
        int dx = point.x - center.x;
        int dy = point.y - center.y;
        return (dx * dx + dy * dy) <= (radius * radius);
    }
};

/**
 * @brief Represents a line segment defined by a starting and an ending point.
 */
struct ZLine {
    ZPoint start; /**< Starting point of the line. */
    ZPoint end;   /**< Ending point of the line. */
};

/*==================== Transformation Types ====================*/

/**
 * @brief Represents a 2D vector.
 */
struct ZVector2D {
    float x; /**< The X component. */
    float y; /**< The Y component. */

    ZVector2D() : x(0), y(0) {}
    ZVector2D(float x, float y) : x(x), y(y) {}
};

/**
 * @brief Represents a 3x3 matrix for 2D affine transformations.
 *
 * This matrix is used to perform transformations such as translation, rotation, and scaling in 2D space.
 */
struct ZMatrix {
    float m[3][3]; /**< Matrix elements in row-major order. */

    /**
     * @brief Constructs an identity matrix.
     */
    ZMatrix() {
        m[0][0] = 1; m[0][1] = 0; m[0][2] = 0;
        m[1][0] = 0; m[1][1] = 1; m[1][2] = 0;
        m[2][0] = 0; m[2][1] = 0; m[2][2] = 1;
    }
    // Additional transformation methods (translate, rotate, scale) can be added here.
};

/*==================== Utility Functions ====================*/

/**
 * @brief Clamps a value between a minimum and a maximum.
 * @tparam T A type that supports comparison.
 * @param value The value to clamp.
 * @param min The minimum allowed value.
 * @param max The maximum allowed value.
 * @return The clamped value.
 */
template<typename T>
inline T clamp(const T& value, const T& min, const T& max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

/**
 * @brief Performs linear interpolation between two values.
 * @tparam T A numeric type.
 * @param a The start value.
 * @param b The end value.
 * @param t The interpolation factor (0 <= t <= 1).
 * @return The interpolated value.
 */
template<typename T>
inline T lerp(const T& a, const T& b, float t) {
    return a + t * (b - a);
}

/**
 * @brief Calculates the Euclidean distance between two points.
 * @param a The first point.
 * @param b The second point.
 * @return The distance between the two points.
 */
inline float distance(const ZPoint& a, const ZPoint& b) {
    int dx = b.x - a.x;
    int dy = b.y - a.y;
    return std::sqrt(dx * dx + dy * dy);
}

/*==================== Time and Error Utilities ====================*/

/**
 * @brief Utility class for measuring time intervals.
 */
struct ZTime {
    using clock = std::chrono::steady_clock;
    clock::time_point start; /**< The starting time point. */

    /**
     * @brief Constructs a ZTime object and initializes the start time.
     */
    ZTime() : start(clock::now()) {}

    /**
     * @brief Returns the elapsed time in seconds since the object was created.
     * @return Elapsed time in seconds.
     */
    double elapsed() const {
        std::chrono::duration<double> diff = clock::now() - start;
        return diff.count();
    }
};

/**
 * @brief Exception class for ZincX-specific errors.
 */
class ZException : public std::exception {
private:
    std::string message; /**< Detailed error message. */
public:
    /**
     * @brief Constructs a ZException with a given error message.
     * @param msg The error message.
     */
    explicit ZException(const std::string& msg) : message(msg) {}

    /**
     * @brief Returns the error message.
     * @return C-string describing the error.
     */
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

/*==================== Enumerations =====================*/

/** @brief General alignment options. */
enum class Alignment { Left, Center, Right, Top, Bottom };

/** @brief Cardinal directions. */
enum class Direction { North, East, South, West };

/* Graphics */
enum class RenderMode { Text, Graphics16, Vulkan };
enum class CoordinateSystem { Screen, World };

/* Widgets */
enum class WidgetState { Normal, Hovered, Pressed, Disabled };
enum class WidgetType { Button, TextField, ComboBox };

/* Event */
enum class EventType { MouseClick, KeyPress, TouchStart };
enum class KeyModifier { None, Shift, Ctrl, Alt };

/* Input */
enum class InputDeviceType { Mouse, Keyboard, Touchpad };
enum class GestureType { Swipe, Pinch, Tap };

/* Compute */
enum class ComputeBackend { Vulkan, CPU };
enum class TaskPriority { Low, Medium, High };

/* Layout */
enum class LayoutOrientation { Horizontal, Vertical };
enum class LayoutAlignment { Start, Center, End, Stretch };

/* Resource Management */
enum class ResourceType { Texture, Font, Shader };
enum class LoadState { Loading, Loaded, Failed };

/* Style */
enum class BorderStyle { Solid, Dashed, Dotted };
enum class FontWeight { Normal, Bold, Light };
enum class TextAlignment { Left, Center, Right, Justified };

/* Internationalization & Accessibility */
enum class Language { English, Spanish, French };
enum class AccessibilityRole { Button, Checkbox, Slider };

/* Networking */
enum class Protocol { TCP, UDP };
enum class ConnectionState { Connecting, Connected, Disconnected, Failed };

/* Debugging & Profiling */
enum class LogLevel { Debug, Info, Warning, Error, Fatal };
enum class ProfilingCategory { Rendering, Compute, Input };

/* General */
enum class Platform { DOS, Win16, Windows, MacOS, Linux, Embedded };
enum class ErrorCode { Success, InvalidArgument, ResourceNotFound };

} // namespace ZincX
