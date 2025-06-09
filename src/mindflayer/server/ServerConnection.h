//
// Created by jan on 29.09.21.
//

#ifndef MINDFLAYER_USB_SERVERCONNECTION_H
#define MINDFLAYER_USB_SERVERCONNECTION_H


#include <memory>
#include "../controller/Controller.h"

class ServerConnection {
public:
    virtual void attach(std::weak_ptr<Controller> controller) = 0;
    virtual ~ServerConnection() noexcept = default;
};


#endif //MINDFLAYER_USB_SERVERCONNECTION_H
