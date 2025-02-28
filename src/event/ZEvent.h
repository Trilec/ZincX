/**
 * @file ZEvent.h
 * @brief Defines event structures for the ZincX event subsystem.
 *
 * This file contains the foundational event types used in the ZincX UI framework, including the base
 * ZEvent structure and derived types like ZMouseEvent, facilitating event handling and dispatching.
 */
 #pragma once
 #include "../common/ZCommon.h"
 #include "../common/ZCommonEnums.h"
 #include <cstdint>
 
 struct ZEvent {
     ZincX::EventType type;
     uint64_t timestamp;
     ZincX::InputDeviceType deviceType;
     virtual ~ZEvent() = default;
     explicit ZEvent(ZincX::EventType t, ZincX::InputDeviceType device = ZincX::InputDeviceType::Mouse)
         : type(t), timestamp(0), deviceType(device) {} // Add proper timestamp later
 };
 
 struct ZMouseEvent : ZEvent {
     ZPoint position;
     int button;
     ZincX::KeyModifier modifiers;
     ZMouseEvent(ZincX::EventType t, ZPoint pos, int btn, ZincX::KeyModifier mod = ZincX::KeyModifier::None)
         : ZEvent(t, ZincX::InputDeviceType::Mouse), position(pos), button(btn), modifiers(mod) {}
 };