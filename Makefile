##########################################################################
# POR FAVOR, INDIQUE A CONTINUACIÓN SU CONFIGURACIÓN PARA LA COMPILACIÓN

# Versión de SYSTEMC
	VERSION = systemc-2.3.3
# Especifique los archivos .cpp
	SRCS = 1_Adder.cpp 1_mux.cpp 1_PC.cpp 1_Instruction_Memory.cpp 2_Adder.cpp 2_Branch_Condition.cpp 2_Hazard_Detection_Unit.cpp 2_IF_ID.cpp 2_RegisterFile.cpp 2_ImmGen.cpp 3_ALU.cpp 3_FORWARDING_UNIT.cpp 3_MUX_3.cpp 3_ID_EX.cpp 5_Mux.cpp 5_MEM_WB.cpp 4_EX_MEM.cpp 4_Data_Memory.cpp main.cpp 2_Control_Unit.cpp OrGate.cpp AndGate.cpp AndGate5.cpp


# Nombre del ejecutable
	TARGET = test
#
# Instrucciones de uso:
# 
# El makefile le provee de varios comandos para su comodidad en la
# compilación, a continuación están más importantes:
#
# $ make
# -> Compila el proyecto según la configuración previa
#
# $ make clean
# -> Elimina todos los archivos resultantes de la compilación
#
# $ make ejemplo.o
# -> En general, puedes compilar los archivos que necesites según
#  hayas hecho cambios. Supongamos que únicaMemte cambiaste el main.cpp
#  puedes ejecutar "rm main.o" y luego "make main.o" en vez de
#  recompilar todos los archivos
#
# $ make run
# -> Si olvidan el nombre del ejecutable del proyecto, pueden tan solo
#  usar éste comando para ejecutarlo rápidaMemte, lo cual les permite
#  agilizar el tiempo del desarrollo
#######################################################################


CC  = g++
X64 = 
SYSTEMC_HOME_BY_VERSION = /usr/local/$(VERSION)

ifeq ($(shell uname -m), x86_64)
	X64 = 64
endif

ifeq ($(VERSION),systemc-2.3.1)
	CC = g++ -std=c++98
endif

INCDIR  = -I. -I.. -I../gates -I$(SYSTEMC_HOME_BY_VERSION)/include
LIBDIR  = -L. -L.. -L$(SYSTEMC_HOME_BY_VERSION)/lib-linux$(X64)
LIBS    = -lm -lsystemc

CFLAGS  = -g -Wno-deprecated -Wall
OBJS   = $(SRCS:.cpp=.o)
NOTDIR_OBJS = $(notdir $(OBJS))

.SUFFIXES: .cpp .o

$(TARGET): $(OBJS) $(SRCH)
	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) -o $@ $(NOTDIR_OBJS) $(LIBS) 2>&1 | c++filt

all: $(TARGET)

.cpp.o:
	$(CC) $(CFLAGS) $(INCDIR) -c $<

clean:
	rm -f $(NOTDIR_OBJS) *~ $(TARGET) *.bak $(TARGET).stackdump *.vcd

run:
	./$(TARGET)
