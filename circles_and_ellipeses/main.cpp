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

void drawRectangle(){
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex2i(-3, -1.5);
        glVertex2i(3, -1.5);
        glVertex2i(3, -1.5);
        glVertex2i(3 , 5.5);
        glVertex2i(3 , 5.5);
        glVertex2i(-3, 5.5);
        glVertex2i(-3, 5.5);
        glVertex2i(-3, -1.5);
    glEnd();
}

void display_ellipse() {

    glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);

    GLfloat theta = 0, x_c = 0, y_c = 0, xi, yi, r_x = 1.2, r_y = .6;


	for (int i = 1; i <= 10000; ++i) {
        theta = theta + 0.001;

	    xi = x_c + r_x * cos(theta);
	    yi = y_c + r_y * sin(theta);
        glBegin(GL_POLYGON);
        glVertex2f(xi, yi);
        //glEnd();
            // if we don't use 2 * cos then it'd be a simple circle :D
		//glVertex2f(2.0f*cos(PI*i / 180), sin(PI*i / 180));
	}

	glEnd();

	//glFlush();

}

void drawCircle(float cx, float cy)
{
    float x, y;
    int i;
    GLfloat radius;
    int triangleAmount = 1000;
    GLfloat twicePi = 2.0 * PI;
        glBegin(GL_POINTS);
        //glBegin(GL_TRIANGLE_FAN);  // commenting out this line causes no fill rather lined curve

        glColor3f(0.0, 0.0, 0.0);
        x = cx; y = cy; radius = 1.1;
        twicePi = 2.0 * PI;

        //glVertex2f(x, y); // center of circle
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

	drawRectangle();

    drawCircle(-1.1, 3);
    drawCircle(1.1, 3);
    display_ellipse();

    //drawTriangle();

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
