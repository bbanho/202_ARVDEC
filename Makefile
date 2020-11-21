prog=arvore
#
# define arquivos
c_source=$(wildcard ./src/*.c)
h_source=$(wildcard ./src/*.h)

# renomeia .c em .o, numa pasta renomeada de source p/ object, com nomes de arquivos de c_source
obj=$(subst .c,.o,$(subst src,object,$(c_source)))


cc_flags=-Wall \
				 -c \
				 -g	\
				 -W \
				 -pedantic


all: clean objdir $(prog)

objdir:
	@ mkdir object

$(prog): $(obj)
	gcc $^ -o $@

./object/%.o: ./src/%.c ./src/%.h
	gcc $< $(cc_flags) -o $@

./object/%.o: ./src/%.c
	gcc $< $(cc_flags) -o $@

./object/main.o: ./src/main.c $(h_source)
	gcc $< $(cc_flags) -o $@

clean:
	@ rm -rf ./object ./$(prog)

run: 
	@ ./$(prog)

debug: all
	@ gdb ./$(prog)

