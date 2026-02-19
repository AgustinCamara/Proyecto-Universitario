#ifndef AGENDA_H
#define AGENDA_H
#include "DTFecha.h"


class Agenda {
    private:
        DTFecha* fecha;
        std::string formaContacto;
    
    public: 
        Agenda(DTFecha* fecha, std::string& formaContacto);
        ~Agenda();
        DTFecha* getFecha();
        std::string getFormaContacto();
        void setFecha(DTFecha* fecha);
        void setFormaContacto(std::string& formaContacto);
};

#endif