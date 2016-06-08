#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void debug_func() {
	void *a = 0;
	void *b = 0;
	void *c = 0;
	char buff[8];

	read(0, buff, 0xc8);
}

void debug() {
	char *func = "system";
	void *func_addr;

	puts("=== TV Station - Debug Menu ===");
	// void* handle = dlopen(0, RTLD_NOW|RTLD_GLOBAL);
	func_addr = dlsym((void *)-1, func);
	printf("[Debug menu] system is @%p\n[Debug menu] enter cmd: ", func_addr);
	debug_func();
}

char get_one() {
	char val;
	char line_break;

	val = getchar();
	line_break = getchar();

	return val;
}

void uptime() {
	system("uptime");
}

void user() {
	system("id");
}

void print_menu() {
	puts("=== TV Station - Control Panel ===");
	puts("1) Show uptime");
	puts("2) Show current user");
	puts("3) Exit");
	printf("Choice: ");
}

void menu()
{
	char input;

	while (1) {
		print_menu();
		input = 0;
		input = get_one();

		if (input <= '2') {
			if (input == '1') {
				uptime();
			} else if (input == '2') {
				user();
			}
		} else if (input == '3') {
			puts("Disconnected!");
			exit(0);
		} else if (input == '4') {
			debug();
		} else {
			puts("Invalid option!");
		}


		/* if (input == '1') {
			uptime();
		} else if (input == '2') {
			user();
		} else if (input == '3') {
			puts("Disconnected!");
			exit(0);
		} else if (input == '4') {
			debug();
		} else {
			puts("Invalid option!");
		} */ 
	}
}

int main(int argc, char *argv[])
{
	FILE *f;
	f = stdin;
	setvbuf(f, 0, 2, 0);
	f = stdout;
	setvbuf(f, 0, 2, 0);
	menu();
	return 0;
}
