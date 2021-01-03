
OUT = ../bin/db_v$(VERSION)
INCLUDE_DIR += -I../lib -I/usr/include/mysql
LIBDIR = -L/usr/local/lib -L/usr/local/lib/mysql -L../lib/out
CFLAGS += -Wno-invalid-source-encoding # Removed -fno-rtti 
# CLINK_FLAGS = -Wl,-rpath,/usr/local/lib32/metin2 #-flto -fsanitize=address,undefined fsanitize-recover=all
LIBS = -pthread -lm -lmd -lthecore -lmysqlclient -lsql -lpoly -lgame -lz
CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

default: setup $(OUT)
setup:
	@mkdir -p obj

obj/%.o: src/%.cpp
	@$(CXX) $(CFLAGS) $(INCLUDE_DIR) -D__SERVER_VERSION__=\"$(VERSION)\" -c $< -o $@


$(OUT): $(OBJ_FILES)
		@$(CXX) $(CFLAGS) $(CLINK_FLAGS) $(LIBDIR) $^ $(LIBS) -o $@

clean:
	@rm -rf obj

# limit_time: @echo update limit time @python update_limit_time.py
# tag: ctags *.cpp *.h *.c
# dep: makedepend -f Depend $(INCDIR) -I/usr/local/include/c++/v1 -I/usr/include/c++/v1 -prelease/ $(CPPFILE) 2> /dev/null > Depend
# sinclude Depend
