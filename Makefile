export CC = clang
export CXX = clang++
export VERSION = 71480
export INCLUDE_DIR = -I/usr/include/x86_64-linux-gnu -I/usr/include
export LIBS_DIR = -L/usr/lib/x86_64-linux-gnu
export CFLAGS = -Wall -D_THREAD_SAFE -msse2 -mssse3 -pipe -std=c++2a
REL_FLAGS = -Ofast  #-g0 -fexceptions
DBG_FLAGS = -g3 -O0 -ggdb -DNDEBUG #-fexceptions ........ -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls

default:
	@mkdir -p bin
	@mkdir -p lib/out
	@$(MAKE) -C lib/core
	@$(MAKE) -C lib/poly
	@$(MAKE) -C lib/game
	@$(MAKE) -C lib/sql
	@$(MAKE) -C lib/lua
	
	@$(MAKE) -C game
	@$(MAKE) -C db
	@echo "--------------------------------------"
	@printf "\033[0;32mBuild Done\033[0m\n"
	@echo "--------------------------------------"

#TODO: build from repo
# lib/lua:
# 	@cd lib && git clone https://github.com/lua/lua.git 
# 	@cd lib/lua && git reset --hard 6c0e44464b9eef4be42e2c8181aabfb3301617ad
# 	@$(MAKE) -C lib/lua

clean:
	@rm -rf lib/out
	@$(MAKE) -C lib/core clean
	@$(MAKE) -C lib/poly clean
	@$(MAKE) -C lib/game clean
	@$(MAKE) -C lib/sql clean
	@$(MAKE) -C lib/lua clean
	@$(MAKE) -C game clean
	@$(MAKE) -C db clean
	@echo "--------------------------------------"
	@printf "\033[0;32mAll Clean now!\033[0m\n"
	@echo "--------------------------------------"

