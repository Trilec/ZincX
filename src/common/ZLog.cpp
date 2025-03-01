/**
 * @file ZLog.cpp
 * @brief Implementation of logging utilities for the ZincX framework.
 *
 * This file implements the logging functions declared in ZLog.h, providing console output for
 * the ZincX UI framework.
 */
 #include "ZLog.h"
 #include <iostream>
 
 namespace ZincX {
     void log(const char* message) {
         std::cout << message << "\n";
     }
 }