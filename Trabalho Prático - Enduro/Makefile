ALLEGRO_VERSION=5.0.10
MINGW_VERSION=4.7.0
FOLDER=C:

FOLDER_NAME=\allegro-$(ALLEGRO_VERSION)-mingw-$(MINGW_VERSION)
PATH_ALLEGRO=$(FOLDER)$(FOLDER_NAME)
LIB_ALLEGRO=\lib\liballegro-$(ALLEGRO_VERSION)-monolith-mt.a
INCLUDE_ALLEGRO=\include

all: Enduro.exe
	
Enduro.exe: enduro.o color.o
	gcc -o Enduro.exe enduro.o color.o $(PATH_ALLEGRO)$(LIB_ALLEGRO)

enduro.o: enduro.c color.c
	gcc -I $(PATH_ALLEGRO)$(INCLUDE_ALLEGRO) -c enduro.c -c color.c
	
clean:
	del enduro.o
	del color.o
	del Enduro.exe