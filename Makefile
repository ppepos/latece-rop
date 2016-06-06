all: stack_exec stack_nx stack_nx_64

stack_exec:
	gcc -m32 -fno-stack-protector -z execstack -ldl -o bin/tvstation src/tvstation.c

stack_nx:
	gcc -m32 -fno-stack-protector -z noexecstack -ldl -o bin/tvstation src/tvstation.c

stack_nx_64:
	gcc -fno-stack-protector -z noexecstack -ldl -o bin/tvstation src/tvstation.c

