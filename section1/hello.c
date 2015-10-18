#include <GLUT/glut.h>

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1.0f, 1.0f, 1.0f);
  glBegin(GL_POLYGON);
    glVertex3f(0.25f, 0.25f, 0.0f);
    glVertex3f(0.75f, 0.25f, 0.0f);
    glVertex3f(0.75f, 0.75f, 0.0f);
    glVertex3f(0.25f, 0.75f, 0.0f);
  glEnd();

  glFlush();
}

void init(void)
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 1.0f);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(250, 250);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("hello");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
