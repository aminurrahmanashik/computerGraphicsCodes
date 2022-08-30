#include<windows.h>
#include <GL/glut.h>
#include<math.h>
#include <stdio.h>

float PI=3.1416;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);	// Set display window color to white

	glMatrixMode(GL_PROJECTION);		// Set projection parameters
	//gluOrtho2D(0.0, 400.0, 0.0, 400.0);
	gluOrtho2D(-10, 10, -10, 10);
}
void drawTriangle(){
    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex2f(-3.7, 0);
        glVertex2f(-1.5, -1.0);
        glVertex2f(-1.5, 1.0);
    glEnd();
}

void display_ellipse(float rx, float ry, float xc) {

    glColor3f(0.0, 0.0, 0.0);

    /// r_x, r_y are the half length of major and minor axis
    GLfloat theta = 0, x_c = xc, y_c = 0, xi, yi, r_x = rx, r_y = ry;


	for (int i = 1; i <= 10000; ++i) {
        theta = theta + 0.001;

	    xi = x_c + r_x * cos(theta);
	    yi = y_c + r_y * sin(theta);

        glBegin(GL_POINTS);
        glVertex2f(xi, yi);
        glEnd();
            // if we don't use 2 * cos then it'd be a simple circle :D
		//glVertex2f(2.0f*cos(PI*i / 180), sin(PI*i / 180));
	}

	//glEnd();

	//glFlush();

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



    display_ellipse(3.8, 2.2, 0);
    display_ellipse(2.2, 1.0, -1.5);

    drawTriangle();

	glFlush();	// Process all OpenGL routines
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowPosition(200, 300);
	glutInitWindowSize(400, 400);
	glutCreateWindow("An Example OpenGL Program");

	init();
	glutDisplayFunc(drawShapes);
	glutMainLoop();					// Display everything and wait

	return 0;
}
