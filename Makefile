Cross_compile=/home/garen/buildroot/buildroot/output/host/bin/aarch64-linux-gnu-
CC = $(Cross_compile)gcc

#### aarch64 libdrm ######
LindrmInstallDir=/home/garen/buildroot/buildroot/output/build/libdrm-2.4.107/install_dir
LibdrmInclude=$(LindrmInstallDir)/usr/include
LibdrmInclude+=-I$(LindrmInstallDir)/usr/include/libdrm
LibdrmSo=$(LindrmInstallDir)/usr/lib

#### aarch64 libv4l2 / libv4lconvert ######
Linv4lInstallDir=/home/garen/buildroot/buildroot/output/build/libv4l-1.12.3/installDir
Linv4lInclude=$(LindrmInstallDir)/usr/include
Linv4lSo=$(LindrmInstallDir)/usr/lib


EXAMPLE1_SRC = libv4l2/libv4l2.c example_capture.c
EXAMPLE1 = capture

EXAMPLE2_SRC = libv4l2/libv4l2.c libv4l2/color.c example_video2lcd.c
EXAMPLE2 = video2lcd

all:
	$(CC) -g -o $(EXAMPLE1) $(EXAMPLE1_SRC)
	$(CC) -g -o $(EXAMPLE2) $(EXAMPLE2_SRC)

modeset: libv4l2/libv4l2.c libv4l2/color.c modeset.c rgbyuv.c
	$(CC) -g -o DrmShowCamera libv4l2/libv4l2.c libv4l2/color.c modeset.c -I$(LibdrmInclude) -L$(LibdrmSo) -ldrm \
	-I$(Linv4lInclude) -L$(Linv4lSo) -lv4l2 -lv4lconvert

clean:
	rm modeset