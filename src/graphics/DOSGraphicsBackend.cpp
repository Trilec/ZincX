/**
 * @file DOSGraphicsBackend.cpp
 * @brief Implementation of the DOS-specific graphics backend for the ZincX framework.
 *
 * This file provides the implementation for the DOSGraphicsBackend class, offering rendering
 * functionality for DOS environments using placeholder console output in the ZincX UI framework.
 */
 #include "DOSGraphicsBackend.h"
 #include <iostream>
 
 void DOSGraphicsBackend::initialize(ZincX::RenderMode mode) {
     std::cout << "DOS Graphics Backend Initialized with mode: ";
     switch (mode) {
         case ZincX::RenderMode::Text: std::cout << "Text\n"; break;
         case ZincX::RenderMode::Graphics16: std::cout << "Graphics16\n"; break;
         case ZincX::RenderMode::Vulkan: std::cout << "Vulkan (not supported on DOS)\n"; break;
     }
 }
 
 void DOSGraphicsBackend::fillRect(const ZRect& rect, const ZColor& color) {
     std::cout << "Filling rect at " << rect.x << "," << rect.y << " with size "
               << rect.width << "x" << rect.height << " and color ("
               << color.r << "," << color.g << "," << color.b << ")\n";
 }
 
 void DOSGraphicsBackend::drawRect(const ZRect& rect, const ZColor& color) {
     std::cout << "Drawing rect outline at " << rect.x << "," << rect.y << " with size "
               << rect.width << "x" << rect.height << " and color ("
               << color.r << "," << color.g << "," << color.b << ")\n";
 }
 
 void DOSGraphicsBackend::drawLine(const ZPoint& start, const ZPoint& end, const ZColor& color) {
     std::cout << "Drawing line from (" << start.x << "," << start.y << ") to ("
               << end.x << "," << end.y << ") with color ("
               << color.r << "," << color.g << "," << color.b << ")\n";
 }
 
 void DOSGraphicsBackend::drawCircle(const ZPoint& center, int radius, const ZColor& color, bool filled) {
     std::cout << "Drawing " << (filled ? "filled " : "") << "circle at ("
               << center.x << "," << center.y << ") with radius " << radius
               << " and color (" << color.r << "," << color.g << "," << color.b << ")\n";
 }
 
 void DOSGraphicsBackend::drawEllipse(const ZPoint& center, int width, int height, const ZColor& color, bool filled) {
     std::cout << "Drawing " << (filled ? "filled " : "") << "ellipse at ("
               << center.x << "," << center.y << ") with size " << width << "x" << height
               << " and color (" << color.r << "," << color.g << "," << color.b << ")\n";
 }
 
 void DOSGraphicsBackend::drawPolygon(const std::vector<ZPoint>& points, const ZColor& color, bool filled) {
     std::cout << "Drawing " << (filled ? "filled " : "") << "polygon with " << points.size() << " points and color ("
               << color.r << "," << color.g << "," << color.b << ")\n";
     for (const auto& point : points) {
         std::cout << "Point: (" << point.x << "," << point.y << ") ";
     }
     std::cout << "\n";
 }
 
 void DOSGraphicsBackend::drawText(const std::string& text, const ZRect& bounds, const ZColor& color, ZincX::TextAlignment alignment) {
     std::cout << "Drawing text '" << text << "' at bounds " << bounds.x << "," << bounds.y << " with size "
               << bounds.width << "x" << bounds.height << " and color ("
               << color.r << "," << color.g << "," << color.b << ") aligned ";
     switch (alignment) {
         case ZincX::TextAlignment::Left: std::cout << "Left\n"; break;
         case ZincX::TextAlignment::Center: std::cout << "Center\n"; break;
         case ZincX::TextAlignment::Right: std::cout << "Right\n"; break;
         case ZincX::TextAlignment::Justified: std::cout << "Justified\n"; break;
     }
 }