/**
 * @file ZGraphicsView.cpp
 * @brief Implementation of the ZGraphicsView class for the ZincX graphics subsystem.
 *
 * This file provides the implementation for the ZGraphicsView class, handling the management and
 * rendering of ZGraphicsItem objects using a specified graphics backend in the ZincX UI framework.
 */
 #include "ZGraphicsView.h"

 ZGraphicsView::ZGraphicsView(std::unique_ptr<IZGraphicsBackend> backend, ZincX::RenderMode mode)
     : backend_(std::move(backend)), renderMode_(mode) {
     backend_->initialize(renderMode_);
 }
 
 void ZGraphicsView::addItem(ZGraphicsItem* item) {
     items_.push_back(item);
 }
 
 void ZGraphicsView::removeItem(ZGraphicsItem* item) {
     items_.erase(std::remove(items_.begin(), items_.end(), item), items_.end());
 }
 
 void ZGraphicsView::render() {
     for (auto* item : items_) {
         item->draw(backend_.get());
     }
 }