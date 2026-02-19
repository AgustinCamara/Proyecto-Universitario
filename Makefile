CXX = g++
CXXFLAGS = -std=c++98 -Wall -Iinclude
SRC_DIR = src
BUILD_DIR = build
GRUPO = 43

SRCS = $(SRC_DIR)/Publicacion.cpp \
       $(SRC_DIR)/ArticuloRevista.cpp \
       $(SRC_DIR)/Libro.cpp \
       $(SRC_DIR)/PaginaWeb.cpp \
       $(SRC_DIR)/Investigador.cpp \
       $(SRC_DIR)/DTFecha.cpp \
	   $(SRC_DIR)/DTRefer.cpp \
       main.cpp

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/$(SRC_DIR)/%.o)
TARGET = lab0

all: $(BUILD_DIR) $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

entrega:
	tar -czvf $(GRUPO)_lab0.tar.gz include/*.h src/*.cpp main.cpp Makefile

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean entrega