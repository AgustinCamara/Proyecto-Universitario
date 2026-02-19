#ifndef DTREFER_H
#define DTREFER_H
#include <iostream>
#include <string>
#include <vector>

class DTRefer {
private:
    const std::string DOI;
    const std::string titulo;
    const std::string fecha;
    const std::vector<std::string> autores;
public:
    DTRefer(const std::string& d, const std::string& t, const std::string& f, const std::vector<std::string>& a);
    std::string getDOI() const;
    std::string getTitulo() const;
    std::string getFecha() const;
    std::vector<std::string> getAutores() const;

    // Sobrecarga de operador <<
    friend std::ostream& operator<<(std::ostream& os, const DTRefer& dt);
};

#endif
