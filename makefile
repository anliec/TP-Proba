EXE = B3129
COMP = g++
RM = rm
EDL = g++
ECHO = @echo
INTF = fileGenerator.h mersenne_twister.h von_neumann.h aes.h question2.h question3.h
REAL = $(INTF:.h=.c) main.c
OBJ =  $(REAL:.c=.o)
OUTPUT = -o
RMFLAGS = -f
EDLOPTION = 
CPPFLAGS = -c -std=c99
COMPFLAGS = -Wall #-FMAP
EDLFALGS = 
LIBS =
LIBPATH =
INPATH =
CLEAN = clean
SOSgutr = backup

EXEC_OPT =

$(EXE) : $(OBJ)
	$(ECHO) "Edition des liens"
	$(EDL) $(OUTPUT) $(EXE) $(EDLFLAGS) $(LIBPATH) $(OBJ) $(LIBS)

main.o : fileGenerator.h mersenne_twister.h von_neumann.h aes.h question2.h question3.h
mersenne_twister.o : mersenne_twister.h
von_neumann.o : von_neumann.h
aes.o :aes.h
fileGenerator.o : fileGenerator.h
question2.o : von_neumann.h aes.h mersenne_twister.h

%.o : %.cpp
	$(ECHO) "Compilation de <$<>"
	$(COMP) $(CPPFLAGS) $(INPATH) $(COMPFLAGS) $<

$(CLEAN) :
	$(ECHO) "Nettoyage des fichiers crees !"
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) $(EDLOPTION) #core

#$(SOS)
