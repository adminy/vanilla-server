OUT = ../bin/game_v$(VERSION)
INCLUDE_DIR += -Iinclude -I../lib -I../lib/lua/include
LIBS_DIR += -L../lib/out
# CFLAGS += -fexceptions
# CLINKFLAGS_DBG = $(CFLAGS) -Wl,-rpath,/usr/local/lib32/metin2 -fstandalone-debug -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls #CLINKFLAGS_REL += -flto
LIBS = -pthread -lm -lIL -ljpeg -lmysqlclient -lz -lcryptopp -lssl -llzo2  -lgtest -llua -lcore -lpoly -lsql -lgame -nostartfiles  # -lmd /usr/local/lib/libexecinfo.a == use_stacktrace
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
default: setup $(OUT)
setup:
	@mkdir -p obj


# CF = -Wall -D_THREAD_SAFE -pipe -msse2 -mssse3 -m32 -stdlib=libc++ -std=c++14

obj/%.o: src/%.cpp
	@$(CXX) $(CFLAGS) $(INCLUDE_DIR) -D__SERVER_VERSION__=\"$(VERSION)\" -c $< -o $@

$(OUT): $(OBJ_FILES)
	@printf "\033[0;31mYet to successfully build game ....\033[0m\n"
	# @$(CXX) $(CFLAGS) $(LIBS_DIR) $(LIBS) $^ -o $@ 
	
clean:
	@rm -rf obj

# limit_time: @echo update limit time @python update_limit_time.py
# tag: ctags *.cpp *.h *.c
# dep: makedepend -f Depend $(INCDIR) -I/usr/local/include/c++/v1 -I/usr/include/c++/v1 -prelease/ $(CPPFILE) 2> /dev/null > Depend
# sinclude Depend
