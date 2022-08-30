#include<windows.h>
#include <GL/glut.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);	// Set display window color to white

	glMatrixMode(GL_PROJECTION);		// Set projection parameters
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void drawShapes(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	// Clear display window

	//Set color to black
	glColor3f(0.0, 0.0, 0.0);
	//Adjust the point size
	glPointSize(5.0);

	//Set color to red
	glColor3f(1.0, 0.0, 0.0);

	// Draw an outlined rectangle (body of house)
	glBegin(GL_QUADS);

		glVertex2i(100, 0);
		glVertex2i(300,0);
		glVertex2i(300,200);
		glVertex2i(100,200);
    glEnd();

    /// roof
    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 1.0);
		glVertex2i(100,200);
		glVertex2i(300,200);
		glVertex2i(200,300);
    glEnd();

    /// door
    glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2i(180,0);
		glVertex2i(220, 0);
		glVertex2i(220, 120);
		glVertex2i(180,120);
    glEnd();

    /// window 1
    glBegin(GL_QUADS);
		glColor3f(0.0, 1.0, 0.0);
		glVertex2i(110,80);
		glVertex2i(170, 80);
		glVertex2i(170, 130);
		glVertex2i(110, 130);
    glEnd();

    /// window 2
    glBegin(GL_QUADS);
		glColor3f(0.0, 1.0, 0.0);
		glVertex2i(230,80);
		glVertex2i(290, 80);
		glVertex2i(290, 130);
		glVertex2i(230, 130);
	glEnd();

	glFlush();	// Process all OpenGL routines
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("An Example OpenGL Program");

	init();
	glutDisplayFunc(drawShapes);
	glutMainLoop();					// Display everything and wait

	return 0;
}
