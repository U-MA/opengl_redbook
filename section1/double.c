#include <stdlib.h>

#include <GLUT/glut.h>

static GLfloat spin = 0.0f;

void init(void)
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glShadeModel(GL_FLAT);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  glRotatef(spin, 0.0f, 0.0f, 1.0f);
  glColor3f(1.0f, 1.0f, 1.0f);
  glRectf(-25.0f, -25.0f, 25.0, 25.0);
  glPopMatrix();
  glutSwapBuffers();
}

void spinDisplay(void)
{
  spin += 2.0f;
  if (spin > 360.0f) {
    spin -= 360.0f;
  }
  glutPostRedisplay();
}

void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-50.0f, 50.0f, -50.0f, 50.0f, -1.0f, 1.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
  switch (button) {
    case GLUT_LEFT_BUTTON:
      if (state == GLUT_DOWN) {
        glutIdleFunc(spinDisplay);
      }
      break;
    case GLUT_MIDDLE_BUTTON:
      if (state == GLUT_DOWN) {
        glutIdleFunc(NULL);
      }
      break;
    default:
      break;
  }
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(250, 250);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);
  glutMainLoop();
  return 0;
}
