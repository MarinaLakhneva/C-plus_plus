#ifndef DLLPLUGIN_H
#define DLLPLUGIN_H
#include "operations.h"

extern "C" {
    __declspec(dllexport)  Operation* getOperation();
}

#endif  DLLPLUGIN_H
