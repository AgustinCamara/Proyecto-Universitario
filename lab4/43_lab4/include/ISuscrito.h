#ifndef ISUSCRITO_H
#define ISUSCRITO_H

#include <set>
#include "DTNotificacion.h"

class ISuscrito {
public:
    virtual void notificar(DTNotificacion* notificacion) = 0;
    virtual ~ISuscrito() {}
    virtual std::string getNickname() const = 0;
};

#endif
