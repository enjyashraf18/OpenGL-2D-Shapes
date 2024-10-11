//cr. code: Sumanta Guha.
////////////////////////

//importing the header files
#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <math.h>

void drawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_POLYGON);
	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // Angle in radians
		float x = r * cosf(theta); // X coordinate
		float y = r * sinf(theta); // Y coordinate
		glVertex2f(x + cx, y + cy); // Vertex position
	}
	glEnd();
}

// Drawing routine.
void drawScene(void)
{
	// Clearing the buffer and setting the drawing color
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.827, 0.663, 0.616);
	
	// Color for the house base

	// Draw the base of the house (rectangle)
	glBegin(GL_POLYGON);
	glVertex3f(20.0, 20.0, 0.0); // btm lft
	glVertex3f(200.0, 20.0, 0.0);// btn rght
	glVertex3f(200.0, 80.0, 0.0);//top right
	glVertex3f(20.0, 80.0, 0.0);//top left
	
	
	glEnd();

	// Change color for the roof
	glColor3f(0.094, 0.196, 0.263);
	// Color for the roof

	// Draw the roof of the house 
	glBegin(GL_POLYGON);
	glVertex3f(10.0, 80.0, 0.0);//btm lft
	glVertex3f(210.0, 80.0, 0.0);//btn rght
	glVertex3f(195.0, 100.0, 0.0);//top right
	glVertex3f(25.0, 100.0, 0.0);//top left
	
	glEnd();

	glColor3f(0.973, 0.788, 0.663);//front part of the house

	glBegin(GL_POLYGON);
	glVertex3f(50.0, 20.0, 0.0);//btm lft
	glVertex3f(110.0, 20.0, 0.0);//btn rght
	glVertex3f(110.0, 80.0, 0.0);//top right
	glVertex3f(80.0, 110.0, 0.0);//top left
	glVertex3f(50.0, 80.0, 0.0);//top left

	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(110.0, 100.0, 0.0);//btm lft
	glVertex3f(120.0, 100.0, 0.0);//btn rght
	glVertex3f(120.0, 120.0, 0.0);//top right
	glVertex3f(110.0, 120.0, 0.0);//top left
	

	glEnd();


	glColor3f(0.0, 0.0, 0.0); // Green color

	drawCircle(80, 90, 5, 100);

	glBegin(GL_POLYGON);
	glVertex3f(70.0, 20.0, 0.0);//btm lft
	glVertex3f(90.0, 20.0, 0.0);//btn rght
	glVertex3f(90.0, 50.0, 0.0);//top right
	glVertex3f(70.0, 50.0, 0.0);//top left

	drawCircle(80, 50, 10, 100);


	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(130.0, 40.0, 0.0);//btm lft
	glVertex3f(150.0, 40.0, 0.0);//btn rght
	glVertex3f(150.0, 70.0, 0.0);//top right
	glVertex3f(130.0, 70.0, 0.0);//top left
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(170.0, 40.0, 0.0);//btm lft
	glVertex3f(190.0, 40.0, 0.0);//btn rght
	glVertex3f(190.0, 70.0, 0.0);//top right
	glVertex3f(170.0, 70.0, 0.0);//top left
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(25.0, 45.0, 0.0);//btm lft
	glVertex3f(40.0, 45.0, 0.0);//btn rght
	glVertex3f(40.0, 65.0, 0.0);//top right
	glVertex3f(25.0, 65.0, 0.0);//top left
	glEnd();

	//glBegin(GL_POLYGON);
	//glVertex3f(45.0, 72.0, 0.0);//btm lft
	//glVertex3f(40.0, 72.0, 0.0);//btn rght
	//glVertex3f(80.0, 112.0, 0.0);//top right
	//glVertex3f(120.0, 72.0, 0.0);//top left
	//glVertex3f(117.0, 72.0, 0.0);//btn rght
	//glVertex3f(80.0, 110.0, 0.0);//top right
	//glEnd();

	// Execute the drawing
	glFlush();
}


// Initialization routine.
void setup(void)
{
	//the clearing color of the opengl window (background)
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	// drawing the entire window
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//glOrtho(left, right, bottom, top, near, far)
	//Sets up a viewing box span along the x-axis is from left to right, along the y-axis from bottom to top, 
	// and along the z-axis from ?far to ?near.
	glOrtho(0.0, 300.0, 0.0, 300.0, -1.0, 1.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Keyboard input processing routine. x & y are location of the mouse
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	// ascii of escape key
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char **argv)
{
	
	glutInit(&argc, argv);	// initializes the FreeGLUT library.

	// create context, set its version and set backward compatibility. 
	// context is the interface between an instance of OpenGL and the rest of the system
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	// wanting an OpenGL context to support a single-buffered frame, each pixel having red, green, blue and alpha values.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	
	// set the initial size of the OpenGL window and the location of its top left corner on the computer screen
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(200, 200);
	
	// creates the OpenGL context and its associated window with the specified string parameter as title.
	glutCreateWindow("square.cpp");
	
	// callback routines – when the OpenGL window is to be drawn, when it is resized, 
	// and when keyboard input is received, respectively
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	// initializes GLEW (the OpenGL Extension Wrangler Library) which handles the loading of OpenGL extensions, 
	// with the switch set so that extensions implemented even in pre-release drivers are exposed.
	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	// begins the event-processing loop, calling registered callback routines as needed
	glutMainLoop();
	
}
