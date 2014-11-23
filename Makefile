#########Makefile#########
# Raspberry Pi
# Compile network for rf24 using librf24
#
#

# The recommended compiler flags for the Raspberry Pi
#CCFLAGS=  -std=c++11 -Wall -Ofast -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s
#CC=arm-linux-gnueabihf-g++ 
CCFLAGS= -std=c99 -Wall 
CC=gcc
COPY=cp

#THIRDPARTYDIRS += /home/eddie/rpi_tools/rootfs/usr/include/ 
#THIRDPARTYDIRS += /home/eddie/rpi_tools/rootfs/usr/local/include/ 
#THIRDPARTYLIBDIRS += /home/eddie/rpi_tools/rootfs/lib 
#THIRDPARTYLIBDIRS += /home/eddie/rpi_tools/rootfs/usr/local/lib/ 
#THIRDPARTYLIBDIRS += /home/eddie/rpi_tools/rootfs/lib/arm-linux-gnueabihf/
#THIRDPARTYLIBDIRS += /home/eddie/rpi_tools/rootfs/usr/lib 
#LIBPATH += $(addprefix -L, $(THIRDPARTYLIBDIRS)) 
#INCLUDEPATH += $(addprefix -I, $(THIRDPARTYDIRS))
INCLUDEPATH = -I./inc/

#UPLOADSCRIPT = file_upload.sh

# define all programs
PROGRAM = messagetest
SOURCES = ./test/main.c

all: ${PROGRAM}

${PROGRAM}: ${SOURCES}
#	g++ ${CCFLAGS} -Wall -L../librf24/  -lrf24 -lwiringPi $@.cpp -o $@
	@echo $(LIBPATH)
	${CC} ${CCFLAGS} -g ${INCLUDEPATH} $< -o $@
	cp ${PROGRAM} ./build
#	@sh $(UPLOADSCRIPT)
clean:
	@echo 'Cleaning Directory'
	rm -rf $(PROGRAM)

#install: all
#	test -d $(prefix) || mkdir $(prefix)
#	test -d $(prefix)/bin || mkdir $(prefix)/bin
#	for prog in $(PROGRAM); do \
#	  install -m 0755 $$prog $(prefix)/bin; \
#	done

#.PHONY: install
