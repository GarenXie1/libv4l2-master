# libv4l2
对Linux v4l2接口进行封装，降低操作难度，主要内容在libv4l2目录下

编译/运行 "在 Arm aarch64 验证.":
	gcc -g -o DrmShowCamera libv4l2/libv4l2.c libv4l2/color.c modeset.c $(pkg-config --cflags --libs libdrm)
	./DrmShowCamera /dev/video0 &
