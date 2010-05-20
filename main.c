#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define TIMERMSECS 17.0f

static void drawGeometry(void);

static double theta = 0;

static void render(void) {
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

static void drawGeometry(void) {
	glPushMatrix();
	glRotated(theta, 1, 0.5, 0);

	glutSolidTorus(20, 100, 10, 30);

	glPopMatrix();
}

static void update(int value) {
	(void) value;
	glutTimerFunc(TIMERMSECS, update, 0);
	theta = theta + 1;
	glutPostRedisplay();
}

static void init(void) {
	glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
	//glOrtho(-200, 200, -150, 150, -200, 200);
	glFrustum(-200, 200, -150, 150, 600, 1000);
	glTranslatef(0, 0, -800);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

extern int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(400, 300);
	glutCreateWindow("Hello World");
	glutDisplayFunc(render);
	glutTimerFunc(TIMERMSECS, update, 0);
	init();
	glutMainLoop();
	return 0;
}
