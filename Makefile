export CC = clang
export CXX = clang++
export VERSION = 71480
export INCLUDE_DIR = -I/usr/include/x86_64-linux-gnu -I/usr/include -I/usr/src/gtest/include # -I/usr/local/include -I/usr/include/c++/7 -I/usr/include/c++/7/tr1 -I/usr/include/x86_64-linux-gnu/c++/7
export LIBS_DIR = -L/usr/lib/x86_64-linux-gnu
CFLAGS = -Wall -D_THREAD_SAFE -pipe -msse2 -mssse3 -m32 -std=c++1z -stdlib=libc++ # -std=c++14
REL_FLAGS = -Ofast  #-g0 -fexceptions
DBG_FLAGS = -g3 -O0 -ggdb -DNDEBUG #-fexceptions ........ -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls

default: #lib/lua
	@mkdir -p bin
	@mkdir -p lib/out
	@$(MAKE) -C lib/core
	@$(MAKE) -C lib/poly
	@$(MAKE) -C lib/game
	@$(MAKE) -C lib/sql
	# @$(MAKE) -C lib/serverkey
	@$(MAKE) -C lib/lua
	
	@$(MAKE) -C game
	@$(MAKE) -C db
	@echo "--------------------------------------"
	@printf "\033[0;32mBuild Done\033[0m\n"
	@echo "--------------------------------------"


# lib/lua:
# 	@cd lib && git clone https://github.com/lua/lua.git 
# 	@cd lib/lua && git reset --hard 6c0e44464b9eef4be42e2c8181aabfb3301617ad
# 	@$(MAKE) -C lib/lua

clean:
	@rm -rf lib/out
	@$(MAKE) -C lib/core clean
	@$(MAKE) -C lib/poly clean
	@$(MAKE) -C lib/game clean
	# @rm -rf lib/lua
	@$(MAKE) -C lib/sql clean
	# @$(MAKE) -C lib/serverkey clean
	@$(MAKE) -C lib/lua clean
	@$(MAKE) -C game clean
	@$(MAKE) -C db clean
	@echo "--------------------------------------"
	@printf "\033[0;32mAll Clean now!\033[0m\n"
	@echo "--------------------------------------"

