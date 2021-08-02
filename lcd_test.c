#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>


#define _COLOR_RED      0x00ffffff
#define _COLOR_GREEN    0x00AAffff
#define _COLOR_BLUE     0x00ffffAA

static struct fb_fix_screeninfo fb_fix ={0};
static struct fb_var_screeninfo fb_var ={0};

long screen_size=0;


unsigned char *fb32=NULL;
//int *fb32 =NULL;
int main()
{
    int fd = -1;
    int x,y;
	unsigned int off = 0;
    fd =open("/dev/fb0",O_RDWR);
    if(fd < 0)
    {
        printf("open dev fb0 fail.\n");
        return -1;
    }
    //get  lcd param
    ioctl(fd,FBIOGET_FSCREENINFO,&fb_fix);

    ioctl(fd,FBIOGET_VSCREENINFO,&fb_var);

    screen_size = fb_var.xres*fb_var.yres*(fb_var.bits_per_pixel/8);
	printf("lcd solution-->%dx%d\n",fb_var.xres,fb_var.yres);
	printf("screen_size-->%d\n",screen_size);
    fb32 =mmap(0,screen_size,PROT_READ |PROT_WRITE,MAP_SHARED,fd,0);

    if(fb32 == NULL)
    {
        printf("mmap framebuffer fail.\n");
        return -1;
    }

    if(fb_var.bits_per_pixel == 8)
    {
        printf("8bpp framebuffer test.\n");
    }
    else if(fb_var.bits_per_pixel == 16)
    {
        printf("16bpp framebuffer test.\n");
    }
    else if(fb_var.bits_per_pixel == 24)
    {
        printf("24bpp framebuffer test.\n");
    }
    else if(fb_var.bits_per_pixel == 32)
    {
        printf("32bpp framebuffer test.\n");
    }

#if 0
    for(y=0;y< fb_var.yres;++y)
    {
        for(x=0;x< fb_var.xres;++x)
        {
            *(unsigned int*)(fb32 +y*fb_var.xres*4 + x*4) = 0x000000FF ; // 0x0000FF00;
        }
    }

#else
	printf("test 480*640.\n");

	/* clear the framebuffer to 0 */
	memset(fb32, 0, screen_size);

    for(y=0;y<= 480;++y)	// 480
    {
        for(x=0;x<= 1200;++x)
        {
        	if(x <= 600){
				//*(unsigned int*)(fb32 +y*1200*4 + x*4) = 0x00FF0000;	//red -> 0x00FF0000
				//off = 0*1200*4 + x*4;	// 第一条线是正确的
				off = 2*1200*4 + x*4;
				*(unsigned int*)&fb32[off] = 0x00FF0000; //0x00FF0000;
        	}
			else{
				off = y*1200*4 + x*4;
				//*(unsigned int*)&fb32[off] = (0xAC << 16) | (0x12 << 8) | 0x34; //0x0000FF00;
            	//*(unsigned int*)(fb32 +y*1200*4 + x*4) = 0x0000FF00;//	blue -> 0x0000FF00
			}
        }
    }	
#endif
    munmap(fb32,screen_size);
    close(fd);
    return 0;
}
