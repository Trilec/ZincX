/**
 * @file ZEventManager.h
 * @brief Defines the event manager class for the ZincX event subsystem.
 *
 * This file contains the ZEventManager class, responsible for queuing and dispatching events to
 * registered listeners within the ZincX UI framework, enabling responsive user interaction.
 */
 #pragma once
 #include "ZEvent.h"
 #include <queue>
 #include <functional>
 
 class ZGraphicsItem;
 
 class ZEventManager {
 public:
     void queueEvent(std::unique_ptr<ZEvent> event);
     void dispatchEvents();
     void registerListener(ZGraphicsItem* item, std::function<void(const ZEvent&)> callback);
 
 private:
     std::queue<std::unique_ptr<ZEvent>> eventQueue_;
     std::vector<std::pair<ZGraphicsItem*, std::function<void(const ZEvent&)>>> listeners_;
 };