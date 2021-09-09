#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

#include <linux/fb.h>
// dd
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

int main()
{
   struct fb_var_screeninfo screen_info;
   struct fb_fix_screeninfo fixed_info;
   char *buffer = NULL;
   size_t buflen;
   int fd = -1;
   int r = 1;

   fd = open("/dev/fb0", O_RDWR);
   if (fd >= 0)
   {
      if (!ioctl(fd, FBIOGET_VSCREENINFO, &screen_info) &&
          !ioctl(fd, FBIOGET_FSCREENINFO, &fixed_info))
      {
         buflen = screen_info.yres_virtual * fixed_info.line_length;
         buffer = mmap(NULL,
                       buflen,
                       PROT_READ|PROT_WRITE,
                       MAP_SHARED,
                       fd,
                       0);
         if (buffer != MAP_FAILED)
         {
            /*
             * TODO: something interesting here.
             * "buffer" now points to screen pixels.
             * Each individual pixel might be at:
             *    buffer + x * screen_info.bits_per_pixel/8
             *           + y * fixed_info.line_length
             * Then you can write pixels at locations such as that.
             */

             r = 0;   /* Indicate success */
         }
         else
         {
            perror("mmap");
         }
      }
      else
      {
         perror("ioctl");
      }
   }
   else
   {
      perror("open");
   }

   /*
    * Clean up
    */
   if (buffer && buffer != MAP_FAILED)
      munmap(buffer, buflen);
   if (fd >= 0)
      close(fd);

   return r;
}
