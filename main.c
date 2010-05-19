#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

void render(void) {
}

void update(void) {
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(400,300);
	glutCreateWindow("Hello World");
	glutDisplayFunc(&render);
	glutIdleFunc(&update);

	glutMainLoop();
	return 0;
}
