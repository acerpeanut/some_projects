#include "o_bmp.h"
#include "HS_ADAPT.h"

void init_and_load(o_bmp*p,int w,int h,char* path){
	FILE* fp = fopen(path,"rb");
	if(fp){
		p->width=w;
		p->height=h;
		for(int i=64;i<=2048;i*=2){
			if(i>=w){
				p->i_w = i;
				break;
			}
		}
		for(int i=64;i<=2048;i*=2){
			if(i>=h){
				p->i_h = i;
				break;
			}
		}
		p->bytes_per_pixel = 3;
		p->pixel_data = (GLubyte*)malloc(p->i_w*p->i_h*p->bytes_per_pixel);
		int count = 0;
		for(int i=0;i<p->i_w;i++){
			for(int j=0;j<p->i_h;j++){
				unsigned char c;
				if(i<w&&j<h){
					for(int k=0;k<p->bytes_per_pixel;k++){
						fread(&c, 1, 1, fp);
						p->pixel_data[(j*p->i_w+i)*p->bytes_per_pixel+k] = c;
						count++;
					}
				}
				else{
					for(int k=0;k<p->bytes_per_pixel;k++){
						p->pixel_data[(j*p->i_w+i)*p->bytes_per_pixel+k] = 0;
					}
				}
			}
		}
		printf("count:%d\n", count);
		p->finish_texture = TRUE;
		glGenTextures(1, &p->texture_ID);
		fclose(fp);

		
		
		//glGetIntegerv(GL_TEXTURE_BINDING_2D, &last_texture_ID); 
		glBindTexture(GL_TEXTURE_2D, p->texture_ID );
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);  
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);//此为纹理过滤参数设置
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 
					GL_RGB, 
					128, 128, 
					0, GL_RGB, GL_UNSIGNED_BYTE, 
					p->pixel_data );
		//free(p->pixel_data);
	}
	else{
		assert(fp);
	}
}

void draw_pic(o_bmp* pic, GLfloat x, GLfloat y){
	glBindTexture(GL_TEXTURE_2D, pic->texture_ID);   
    glBegin(GL_QUADS);   
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, -0.5f, 0.0f);   
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, 0.0f);   
        glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, 0.0f);   
        glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -0.5f, 0.0f);   
    glEnd();
}
void draw_pic_origin(o_bmp* pic, 
	GLfloat x, GLfloat y,               // position
	GLfloat colorR, GLfloat colorG, GLfloat colorB, GLfloat colorA, // color
	GLfloat RotateR,                    // rotate
	GLfloat startX, GLfloat startY,     // cut start point
	GLfloat endX, GLfloat endY,         // cut end point
	GLfloat width, GLfloat height)      // show width and height
{
	glPushMatrix();
	glRotatef(RotateR, 0, 0, 1.0);
	glColor4f(colorR, colorG, colorB, colorA);
	glBindTexture(GL_TEXTURE_2D, pic->texture_ID);
	glBegin(GL_QUADS);   
        glTexCoord2f(startX, startY); glVertex2f(x, y);   
        glTexCoord2f(startX, endY); glVertex2f(x, y+height);   
        glTexCoord2f(endX, endY); glVertex2f(x+width, y+height);   
        glTexCoord2f(endX, startY); glVertex2f(x+width, y);   
    glEnd();
    glPopMatrix();
}
void o_bmp_bilt_c_ct_Base(GLfloat x_d, GLfloat y_d,
	GLfloat startX, GLfloat startY,
	GLfloat allignX, GLfloat allignY,
	GLfloat cutWidth, GLfloat cutHeight,
	GLint mirror_dir,
	GLfloat colorR, GLfloat colorG, GLfloat colorB, GLfloat colorA,
	o_bmp* pic)
{
	GLfloat w = HS_INT_FLT_W(pic->width) * cutWidth;
	GLfloat h = HS_INT_FLT_H(pic->height) * cutHeight;

	GLfloat s_x = startX;
	GLfloat s_y = startY;
	GLfloat e_x = startX + cutWidth;
	GLfloat e_y = startY + cutHeight;

	switch(mirror_dir){
		case MIRROR_DIR_0:
			break;
		case MIRROR_DIR_V:
			s_y = startY + cutHeight;
			e_y = startY;
			break;
		case MIRROR_DIR_H:
			s_x = startX + cutWidth;
			e_x = startX;
			break;
	}
	draw_pic_origin(pic,
		x_d - w*allignX, y_d - h*allignY,
		colorR, colorG, colorB, colorA,
		0,
		s_x, s_y,
		e_x, e_y,
		w, h);
	// printf("x:%f,y:%f,startX:%f,startY:%f,endX:%f,endY:%f,w:%f,h:%f\n",
	// 	x_d + w*allignX, y_d + h*allignY,
	// 	startX, startY,
	// 	startX + cutWidth, 
	// 	startY + cutHeight,
	// 	w, h);
}

void o_bmp_silt_c_ct_Base(GLfloat x_d, GLfloat y_d,
	GLfloat scaleX, GLfloat scaleY,
	GLfloat startX, GLfloat startY,
	GLfloat allignX, GLfloat allignY,
	GLfloat cutWidth, GLfloat cutHeight,
	GLint mirror_dir,
	GLfloat colorR, GLfloat colorG, GLfloat colorB, GLfloat colorA,
	o_bmp* pic)
{
	GLfloat w = HS_INT_FLT_W(pic->width) * cutWidth * scaleX;
	GLfloat h = HS_INT_FLT_H(pic->height) * cutHeight * scaleY;

	GLfloat s_x = startX;
	GLfloat s_y = startY;
	GLfloat e_x = startX + cutWidth;
	GLfloat e_y = startY + cutHeight;

	switch(mirror_dir){
		case MIRROR_DIR_0:
			break;
		case MIRROR_DIR_V:
			s_y = startY + cutHeight;
			e_y = startY;
			break;
		case MIRROR_DIR_H:
			s_x = startX + cutWidth;
			e_x = startX;
			break;
	}

	draw_pic_origin(pic,
		x_d - w*allignX, y_d - h*allignY,
		colorR, colorG, colorB, colorA,
		0,
		s_x, s_y,
		e_x, e_y,
		w, h);
}
