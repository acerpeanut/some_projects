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

#define MIRROR_DIR_0 0
#define MIRROR_DIR_V 1
#define MIRROR_DIR_H 2



void init_and_load(o_bmp*p,int w,int h,char* path);
void draw_pic(o_bmp* pic, GLfloat x, GLfloat y);
void draw_pic_origin(o_bmp* pic, 
	GLfloat x, GLfloat y,               // position
	GLfloat colorR, GLfloat colorG, GLfloat colorB, GLfloat colorA, // color
	GLfloat RotateR,                    // rotate
	GLfloat startX, GLfloat startY,     // cut start point
	GLfloat endX, GLfloat endY,         // cut end point
	GLfloat width, GLfloat height);

void o_bmp_bilt_c_ct_Base(GLfloat x_d, GLfloat y_d,
	GLfloat startX, GLfloat startY,
	GLfloat allignX, GLfloat allignY,
	GLfloat cutWidth, GLfloat cutHeight,
	GLint mirror_dir,
	GLfloat colorR, GLfloat colorG, GLfloat colorB, GLfloat colorA,
	o_bmp* pic);

#define o_bmp_bilt_c_ct_0(a,b,c,d,e,f,g,h,i)  o_bmp_bilt_c_ct_Base(  \
												a,b,c,d,e,f,g,h,     \
												MIRROR_DIR_0,        \
												1.0,1.0,1.0,1.0,i)

#define o_bmp_bilt_c_ct_V(a,b,c,d,e,f,g,h,i)  o_bmp_bilt_c_ct_Base(  \
												a,b,c,d,e,f,g,h,     \
												MIRROR_DIR_V,        \
												1.0,1.0,1.0,1.0,i)

#define o_bmp_bilt_c_ct_H(a,b,c,d,e,f,g,h,i)  o_bmp_bilt_c_ct_Base(  \
												a,b,c,d,e,f,g,h,     \
												MIRROR_DIR_H,        \
												1.0,1.0,1.0,1.0,i)



void o_bmp_silt_c_ct_Base(GLfloat x_d, GLfloat y_d,
	GLfloat scaleX, GLfloat scaleY,
	GLfloat startX, GLfloat startY,
	GLfloat allignX, GLfloat allignY,
	GLfloat cutWidth, GLfloat cutHeight,
	GLint mirror_dir,
	GLfloat colorR, GLfloat colorG, GLfloat colorB, GLfloat colorA,
	o_bmp* pic);

#define o_bmp_silt_c_ct_0(a,b,cc,dd,c,d,e,f,g,h,i)  o_bmp_silt_c_ct_Base(      \
													a,b,cc,dd,c,d,e,f,g,h,     \
													MIRROR_DIR_0,              \
													1.0,1.0,1.0,1.0,i)

#define o_bmp_silt_c_ct_V(a,b,cc,dd,c,d,e,f,g,h,i)  o_bmp_silt_c_ct_Base(      \
													a,b,cc,dd,c,d,e,f,g,h,     \
													MIRROR_DIR_V,              \
													1.0,1.0,1.0,1.0,i)

#define o_bmp_silt_c_ct_H(a,b,cc,dd,c,d,e,f,g,h,i)  o_bmp_silt_c_ct_Base(      \
													a,b,cc,dd,c,d,e,f,g,h,     \
													MIRROR_DIR_H,              \
													1.0,1.0,1.0,1.0,i)





#endif