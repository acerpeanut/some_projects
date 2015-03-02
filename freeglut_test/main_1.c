#include "o_bmp.h"
#include "soliar.h"
#include <GL/glut.h>

o_bmp earth;
int Win_Width,Win_Height;

void Win_Reshape(int width,int height){
  Win_Width = width;
  Win_Height = height;
}
void Win_RenderScene(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  o_bmp_silt_c_ct_0(0, 0, 1, 1, 0, 0, 1, 0.5, 1, 1, &earth);

  glFlush();
}
int Win_Init(){
  init_and_load(&earth,128,128,"a.out");
  init_astrophere();
  new_astrophere(0, 0, 100, 0, 0);
  return 0;
}
void Win_Timer(int tflag){
  move_astrophere_all(1);
  double vx, vy;
  balance_astrophere(10, 0, 0, &vx, &vy);
}
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowSize(640,480);
  glutCreateWindow("3D Tech- GLUT Tutorial");
  glutDisplayFunc(Win_RenderScene);
  glutTimerFunc(1, Win_Timer, 33);
  glutReshapeFunc(Win_Reshape);
  glEnable(GL_TEXTURE_2D);
  
  Win_Init();
  glutMainLoop();
  return 0;
}