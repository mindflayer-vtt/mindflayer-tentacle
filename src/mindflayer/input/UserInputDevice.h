//
// Created by jan on 29.09.21.
//

#ifndef MINDFLAYER_USB_USERINPUTDEVICE_H
#define MINDFLAYER_USB_USERINPUTDEVICE_H


#include <memory>
#include "../controller/Controller.h"

class UserInputDevice {
public:
    virtual void notify(std::weak_ptr<Controller> controller) = 0;
    virtual ~UserInputDevice() noexcept = default;
};


#endif //MINDFLAYER_USB_USERINPUTDEVICE_H
