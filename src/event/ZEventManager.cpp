/**
 * @file ZEventManager.cpp
 * @brief Implementation of the ZEventManager class for the ZincX event subsystem.
 *
 * This file provides the implementation for the ZEventManager class, handling event queuing and
 * dispatching to registered listeners, including state updates for graphics items in the ZincX UI framework.
 */
 #include "ZEventManager.h"
 #include "../graphics/ZGraphicsItem.h"
 
 void ZEventManager::queueEvent(std::unique_ptr<ZEvent> event) {
     eventQueue_.push(std::move(event));
 }
 
 void ZEventManager::dispatchEvents() {
     while (!eventQueue_.empty()) {
         auto event = std::move(eventQueue_.front());
         eventQueue_.pop();
         for (auto& [item, callback] : listeners_) {
             callback(*event);
             // Example: Update item state based on event
             if (auto* mouseEvent = dynamic_cast<ZMouseEvent*>(event.get())) {
                 if (mouseEvent->type == ZincX::EventType::MouseClick) {
                     item->setState(ZincX::WidgetState::Pressed);
                 } else if (mouseEvent->type == ZincX::EventType::MouseRelease) {
                     item->setState(ZincX::WidgetState::Normal);
                 }
             }
         }
     }
 }
 
 void ZEventManager::registerListener(ZGraphicsItem* item, std::function<void(const ZEvent&)> callback) {
     listeners_.emplace_back(item, std::move(callback));
 }