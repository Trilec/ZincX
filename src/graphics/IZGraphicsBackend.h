/**
 * @file DOSGraphicsBackend.h
 * @brief Defines the DOS-specific graphics backend for the ZincX framework.
 *
 * This file contains the DOSGraphicsBackend class, implementing the IZGraphicsBackend interface
 * to provide rendering capabilities tailored for DOS environments in the ZincX UI framework.
 */
 #pragma once
 #include "IZGraphicsBackend.h"
 
 class DOSGraphicsBackend : public IZGraphicsBackend {
 public:
     void initialize(ZincX::RenderMode mode) override;
     void fillRect(const ZRect& rect, const ZColor& color) override;
     void drawRect(const ZRect& rect, const ZColor& color) override;
     void drawLine(const ZPoint& start, const ZPoint& end, const ZColor& color) override;
     void drawCircle(const ZPoint& center, int radius, const ZColor& color, bool filled = true) override;
     void drawEllipse(const ZPoint& center, int width, int height, const ZColor& color, bool filled = true) override;
     void drawPolygon(const std::vector<ZPoint>& points, const ZColor& color, bool filled = true) override;
     void drawText(const std::string& text, const ZRect& bounds, const ZColor& color, ZincX::TextAlignment alignment = ZincX::TextAlignment::Center) override;
 };