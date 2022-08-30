#include<windows.h>
#include <GL/glut.h>
#include<math.h>
#include <stdio.h>

float PI=3.1416;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);	// Set display window color to white

	glMatrixMode(GL_PROJECTION);		// Set projection parameters
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void drawCircle(float cx, float cy)
{
    float x, y;
    int i;
    GLfloat radius;
    int triangleAmount = 40;
    GLfloat twicePi = 2.0 * PI;

        glBegin(GL_TRIANGLE_FAN);

        glColor3f(1.0, 1.0, 0.0);
        x = cx; y = cy; radius = 70;
        twicePi = 2.0 * PI;

        glVertex2f(x, y); // center of circle
        for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(
                    x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                  );
        }

    glEnd();

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

    /// triangle 1
	glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2i(140, 150);
        glVertex2i(60, 150);
        glVertex2i(120, 100);
    glEnd();


    /// triangle 2
	glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2i(120, 100);
        glVertex2i(100, 0);
        glVertex2i(200, 50);

    glEnd();

    /// triangle 3
	glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2i(200, 50);
        glVertex2i(300, 0);
        glVertex2i(280, 100);

    glEnd();


    /// triangle 4
	glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2i(280, 100);
        glVertex2i(340, 150);
        glVertex2i(260, 150);

    glEnd();
    /// triangle 5
    glBegin(GL_TRIANGLES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2i(260, 150);
        glVertex2i(200, 200);
        glVertex2i(140, 150);

    glEnd();
    /// polygon 1
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2i(140, 150);
        glVertex2i(260, 150);
        glVertex2i(280, 100);
        glVertex2i(200, 50);
        glVertex2i(120, 100);
    glEnd();

    drawCircle(200, 110);

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
