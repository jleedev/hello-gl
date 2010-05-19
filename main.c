#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

void drawGeometry(void);

GLuint torus;

double theta = 0;

void render(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(4);
	glCullFace(GL_FRONT);
	glPolygonMode(GL_BACK, GL_LINE);
	drawGeometry();

	glColor3f(1.0f, 0.0f, 0.0f);
	glCullFace(GL_BACK);
	glPolygonMode(GL_FRONT, GL_FILL);
	drawGeometry();

	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(1);
	glCullFace(GL_BACK);
	glPolygonMode(GL_FRONT, GL_LINE);
	drawGeometry();

	glutSwapBuffers();
}

void drawGeometry(void) {
	glPushMatrix();
	glRotated(theta, 1, 0.5, 0);

	glCallList(torus);

	glPopMatrix();
}

void update(void) {
	theta = theta + M_PI / 120;
	glutPostRedisplay();
}

void init(void) {
	torus = glGenLists(1);
	glNewList(torus, GL_COMPILE);
	glutSolidTorus(20, 100, 10, 30);
	glEndList();

	glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
	//glOrtho(-200, 200, -150, 150, -200, 200);
	glFrustum(-200, 200, -150, 150, 600, 1000);
	glTranslatef(0, 0, -800);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(400, 300);
	glutCreateWindow("Hello World");
	glutDisplayFunc(&render);
	glutIdleFunc(&update);
	init();
	glutMainLoop();
	return 0;
}
