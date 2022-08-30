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

void drawTriangle(){
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2i(150, 140);
        glVertex2i(250, 140);
        glVertex2i(200, 280);
    glEnd();
}
void drawCircle(float cx, float cy)
{
    float x, y;
    int i;
    GLfloat radius;
    int triangleAmount = 40;
    GLfloat twicePi = 2.0 * PI;
        glBegin(GL_POINTS);
        glBegin(GL_TRIANGLE_FAN);  // commenting out this line causes no fill rather lined curve

        glColor3f(1.0, 1.0, 0.0);
        x = cx; y = cy; radius = 80;
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
	//glPointSize(5.0);

	//Set color to red
	glColor3f(1.0, 0.0, 0.0);


    drawCircle(200, 200);

    drawTriangle();

	glFlush();	// Process all OpenGL routines
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowPosition(400, 200);
	glutInitWindowSize(400, 400);
	glutCreateWindow("An Example OpenGL Program");

	init();
	glutDisplayFunc(drawShapes);
	glutMainLoop();					// Display everything and wait

	return 0;
}
