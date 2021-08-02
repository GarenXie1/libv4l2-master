---
typora-root-url: ./
---

# libv4l2
对Linux v4l2接口进行封装，降低操作难度，主要内容在libv4l2目录下

编译/运行 "在 Arm aarch64 验证.":

~~~shell
# 编译命令
$gcc -g -o DrmShowCamera libv4l2/libv4l2.c libv4l2/color.c modeset.c $(pkg-config --cflags --libs libdrm)

#运行命令
./DrmShowCamera /dev/video0 &
root@debian:~/libv4l2-master# using card '/dev/dri/card0'
mode for connector 4 is 1200x1920
width -> 1200
height -> 1920
size -> 9216000
offset -> 0
ignoring unused connector 6
[  110.240780] sensor_power_on  ov5640 rear:1,hardware:0
[  110.290155] no hardware sensor_power_on
dev support capture
dev support streaming
input:Camera
input device name:Camera
fmt:YUV 4:2:0 planar 12 bit
fmt:YVU 4:2:0 planar 12 bit
fmt:YUV 4:2:2 planar 16 bit
fmt:YUYV[  110.347718] the width is 640,height is 480
 4:2:2 interleaved 16bit
image width:640
image height:480
. .  在 Arm aarch64 平台可以看到 camera 的显示. . . . 
~~~

![image-20210802223801568](pic\image-20210802223801568.png)


​	
​	