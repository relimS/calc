build:
	gcc -o calc ccal.c `pkg-config --cflags --libs gtk4`
