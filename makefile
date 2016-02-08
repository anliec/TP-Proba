#makefile de test_bechfulladder
#la variable EXE correspond au nom du test a effectuer 

EXE = B3129
COMP = gcc
RM = rm
EDL = gcc
ECHO = @echo
INTF = fileGenerator.h mersenne_twister.h von_neumann.h aes.h
REAL = $(INTF:.h=.c) main.c
OBJ =  $(REAL:.c=.o)
OUTPUT = -o
RMFLAGS = -f
EDLOPTION = 
CPPFLAGS = -c
COMPFLAGS = -Wall #-FMAP
EDLFALGS = 
LIBS =
LIBPATH =
INPATH =
CLEAN = clean
SOS = backup

EXEC_OPT =

$(EXE) : $(OBJ)
	$(ECHO) "Edition des liens"
	$(EDL) $(OUTPUT) $(EXE) $(EDLFLAGS) $(LIBPATH) $(OBJ) $(LIBS)

main.o : fileGenerator.h mersenne_twister.h von_neumann.h aes.h
mersenne_twister.o : mersenne_twister.h
von_neumann.o : von_neumann.h
aes.o :aes.h
fileGenerator.o : fileGenerator.h

%.o : %.cpp
	$(ECHO) "Compilation de <$<>"
	$(COMP) $(CPPFLAGS) $(INPATH) $(COMPFLAGS) $<

$(CLEAN) :
	$(ECHO) "Nettoyage des fichiers crees !"
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) $(EDLOPTION) #core

#$(SOS)
