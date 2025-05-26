CXX := g++

SRCDIR := src
BUILDDIR := build
INCDIR := ./raylib/raylib-5.5_win64_mingw-w64/include

CXXFLAGS := -I$(INCDIR) -I$(SRCDIR) -Wall -std=c++17
LDFLAGS := -L./raylib/raylib-5.5_win64_mingw-w64/lib -lraylib -lopengl32 -lgdi32 -lwinmm

SRC := $(shell find $(SRCDIR) -name '*.cpp')
OBJ := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRC))
OUT := megaline.exe

all: $(OUT)

$(OUT): $(OBJ)
	@echo "[INFO] linking $@"
	$(CXX) -o $@ $^ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "[INFO] compiling $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "[INFO] cleaning..."
	@rm -rf $(BUILDDIR) *.exe
