OUT = ../out/liblua.a
C_FILES := $(wildcard src/*.c)
OBJS := $(addprefix obj/,$(notdir $(C_FILES:.c=.o)))
default: setup $(OUT)
setup:
	mkdir -p obj

obj/%.o: src/%.c
	@$(CC) -Iinclude -c $< -o $@

$(OUT):	$(OBJS)
	@$(AR) -cq $@ $^
	# $(RANLIB) $@

clean:
	rm -rf obj	
