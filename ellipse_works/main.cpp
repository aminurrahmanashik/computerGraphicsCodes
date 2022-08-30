#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>
#define PI 3.14


void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);	// Set display window color to white

	glMatrixMode(GL_PROJECTION);		// Set projection parameters
	gluOrtho2D(-5.5, 5.5, -5.5, 5.5);
}


void display_ellipse() {

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(0.0, 0.0);



	for (int i = 0; i < 370; ++i) {
		glVertex2f(2.0f*cos(PI*i / 180), sin(PI*i / 180));
	}

    // ellipse (major axis : Y-axis)
	for (int i = 0; i < 370; ++i) {
		glVertex2f(cos(PI*i / 180), 2.0f*sin(PI*i / 180));
	}
    // ellipse (major axis : X-axis)

	glEnd();

	glFlush();

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);          // Initialize GLUT

	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	glutInitWindowSize(500, 600);   // Set the window's initial width & height
	glutInitWindowPosition(100, 100); // Position the window's initial top-left corner
	glutCreateWindow("Ellipse operations");
    init();
	glutDisplayFunc(display_ellipse);
	glutMainLoop();                 // Enter the event-processing loop
	return 0;
}
