OUT     = ../out/libpoly.a
INCLUDE_DIR += -Iinclude -I../
CFLAGS += -fno-exceptions
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

default: setup $(OUT)
setup:
	@mkdir -p obj

$(OUT): $(OBJ_FILES)
	@$(AR) cru $@ $^
	# @ranlib $@ @chmod 700 $@

obj/%.o: src/%.cpp
	@$(CXX) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@

clean:
	@rm -rf obj

# dep: $(CXX) $(CFLAGS_DBG) $(INCLUDE_DIR) -MM src/*.cpp > src/Depend