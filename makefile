# the compiler
CC = g++

# compiler flags:
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -Wall -Wextra -pedantic -std=c++11

# the build target executable:
TARGET = envia

TARGET2 = recebe

all: $(TARGET) $(TARGET2)

$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

$(TARGET2): $(TARGET2).cpp
	$(CC) $(CFLAGS) -o $(TARGET2) $(TARGET2).cpp

clean:
	$(RM) $(TARGET) $(TARGE2)


# Modo de uso
# abra o arquivo recebe e um terminal e o envia em outro.
# primeiro execute o recebe, ele irá dizer o seu número PID e seus sinais receptores.
# Com o PID de recebe e seus sinais, use o envia para enviar os sinais
# Lembre que o terceiro sinal interrompe o processo.
