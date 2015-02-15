#ifndef __O_BMP_H__
#define __O_BMP_H__

#include <GL/glut.h>

#include <stdio.h>
#include <assert.h>
//#include "GL/freeglut.h"
typedef struct o_bmp{
  GLuint  	 width;
  GLuint  	 height;
  GLuint     i_w;
  GLuint     i_h;
  GLuint     texture_ID;
  GLuint  	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  GLuint     finish_texture;  /* false, true */
  GLubyte 	 *pixel_data;
}o_bmp;


void init_and_load(o_bmp*p,int w,int h,char* path);
void draw_pic(o_bmp* pic, GLfloat x, GLfloat y);


#endif