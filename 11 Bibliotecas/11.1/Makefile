CC = gcc
CFLAGS = -I././$(FOLDERINC)/ -Wall 
LIB = Info1sock
SOURCES = $(wildcard ./src/*.c) $(wildcard ./src/*/*.c)
HEADERS = $(wildcard ./$(FOLDERINC)/*.h) $(wildcard ./$(FOLDERINC)/*/*.h)
OBJS = $(subst /src/,/obj/,$(SOURCES:.c=.o))
FOLDERLIB = Info1libs
FOLDERSRC = src
FOLDERINC = src


# $@: output name
# $<: first dependence
# $^: all dependencies

.PHONY: CrearLibreriaDinamica
CrearLibreriaDinamica: $(OBJS)
		#crea librería en carpeta folderlib. Crea archivo .so.1.0.1
	$(CC) -shared -Wl,-soname,lib$(LIB).so.1 -o ./$(FOLDERLIB)/lib$(LIB).so.1.0.1 $(OBJS) -lc
	
		#objdump da información de la libreria
	objdump -p ./$(FOLDERLIB)/lib$(LIB).so.1.0.1 | grep -i soname
	ldconfig -n ./$(FOLDERLIB)
	ln -sf ./$(FOLDERLIB)/lib$(LIB).so.1 ./$(FOLDERLIB)/lib$(LIB).so
	sudo ldconfig

			#sudo -> pide permisos de admin. Esta línea copia la librería en la carpeta de librerías del sistema.
	#sudo cp ./$(FOLDERLIB)/lib$(LIB).so* /usr/local/lib/
			#cp de copy

			#agrega la librería creada dentro de las conocidas por el sistema. Creael archivo utilizando el -soname(.so.1)
#	sudo ldconfig -n /usr/local/lib/

		#crea el enlace llamado .so. Apunta a .so.1
#	sudo ln -sf /usr/local/lib/lib$(LIB).so.1 /usr/local/lib/lib$(LIB).so
		#echo imprime-> con el">" pueden asignarse destinos distintos a pantalla
#	sudo -- sh -c 'echo "/usr/local/lib" > /etc/ld.so.conf.d/$(LIB)Lib.conf'
#	sudo ldconfig


#Esta línea se utiliza en el makefile de los archivos que utlizarían a esta librería shared llamada por link.
#   export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(shell pwd)/$(FOLDERLIB)


./obj/%.o: ./src/%.c $(HEADERS)
	$(CC) -fPIC -c $< -c -o $@ $(CFLAGS)

.PHONY: CrearLibreriaEstatica
CrearLibreriaEstatica: $(OBJS)
	ar rcs ./$(FOLDERLIB)/lib$(LIB).a $(OBJS)

.PHONY: crearEstructura
crearEstructura:
	@echo	''
	@echo	'-----> Creando estructura de carpetas'

	mkdir -p obj $(FOLDERLIB) $(FOLDERINC) $(FOLDERSRC)

.PHONY: clean
clean:
	rm -f ./$(FOLDERLIB)/lib$(LIB).* $(OBJS)

# PHONY a las reglas que no generan archivos (por ejemplo, no se fija en fecha de modificación)
# 'fPIC' indica al compilador que genere código independiente de la
# posición que ocupe en memoria


# Comando 'ar' (archive):
#
# 'r' indica que reemplace al elemento previamente existente
# con el mismo nombre. En nuestro caso si existía dentro de
# la Biblioteca libestatica.a un elemento llamado func.o, ar lo
# pisa por este nuevo.
#
# 'c' indica que cree el archivo de Biblioteca especificado si no
# existiere (libestatica.a).
#
# 's' le indica actualizar el  ́ındice de la Biblioteca una vez
# inserto el archivo solicitado.