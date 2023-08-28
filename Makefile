# assuming compilation on windows w/ mingw-w64

# files to compile
FILEIN = src/main.cpp src/shaders.cpp

# exe name
FILEOUT = PolCorrTool.exe

# compiler options
# -Wall keeps all warnings on
# -Wl,-subsystem,windows removes console popup & suppresses any console output (use only for release build)
COMPILER_FLAGS = -Wall #-Wl,-subsystem,windows

# specify include dirs
INCLUDE_FLAGS = -Iinclude

# specify libs
LINKER_FLAGS = -Llib -lglew32 -lglfw3dll

# compile command
all : $(FILEIN)
	g++ $(FILEIN) $(COMPILER_FLAGS) $(INCLUDE_FLAGS) $(LINKER_FLAGS) -o $(FILEOUT)

# run command
run : $(FILEOUT)
	./$(FILEOUT)

# remove exe command
clean: $(FILEOUT)
	rm ./$(FILEOUT)