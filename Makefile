CXX := g++

SRCDIR := src
BUILDDIR := build
INCDIR := ./raylib/raylib-5.5_win64_mingw-w64/include
LIBDIR := ./raylib/raylib-5.5_win64_mingw-w64/lib

CXXFLAGS := -I$(INCDIR) -I$(SRCDIR) -Wall -Wextra -std=c++17

LDFLAGS_SHARED := -L$(LIBDIR) -Wl,-Bdynamic -lraylibdll -lopengl32 -lgdi32 -lwinmm

LDFLAGS_STATIC := -L$(LIBDIR) -Wl,-Bstatic -lraylib -lopengl32 -lgdi32 -lwinmm

SRC := $(shell find $(SRCDIR) -name '*.cpp')
OBJ := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRC))
OUT_SHARED := megaline.exe
OUT_STATIC := megaline_static.exe

all: $(OUT_SHARED)

shared: $(OUT_SHARED)

static: $(OUT_STATIC)

$(OUT_SHARED): $(OBJ)
	@echo "[INFO] linking $@ (shared)"
	$(CXX) -o $@ $^ $(LDFLAGS_SHARED)

$(OUT_STATIC): $(OBJ)
	@echo "[INFO] linking $@ (static)"
	$(CXX) -o $@ $^ $(LDFLAGS_STATIC)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "[INFO] compiling $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "[INFO] cleaning..."
	@rm -rf $(BUILDDIR) *.exe *_static.exe