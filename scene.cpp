

#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <math.h>

void drawCircle(float cx, float cy, float r, int num_segments) {
	glBegin(GL_POLYGON);
	for (int i = 0; i < num_segments; i++) {
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
		float x = r * cosf(theta);
		float y = r * sinf(theta);
		glVertex2f(x + cx, y + cy);
	}
	glEnd();
}

void drawGrass(float x, float y) {
	glColor3f(0.0, 1.0, 0.0); // Green color
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 150.0, 0.0);
	glVertex3f(x, 150.0, 0.0);
	glVertex3f(x, y, 0.0); // Height of the grass
	glVertex3f(0.0, y, 0.0);
	glEnd();
}

void drawLake(float x, float y) {
	glColor3f(0.113, 0.635, 0.847);
	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.0);
	glVertex2f(x, 0.0);
	glVertex2f(x, y); // Height of the lake
	glVertex2f(0.0, y);
	glEnd();
}

void drawBoat(void)
{
	// trapezoid 
	glColor3f(0.0, 0.0, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(0.0, 20.0, 0.0); // BL
	glVertex3f(100.0, 20.0, 0.0); // BR
	glVertex3f(120.0, 50.0, 0.0); // TR
	glVertex3f(-20.0, 50.0, 0.0); // TL
	glEnd();

	// triangle
	glColor3f(1.0, 0.0, 0.0); // red
	glBegin(GL_TRIANGLES);
	glVertex3f(50.0, 51.0, 0.0); // BL
	glVertex3f(-35.0, 51.0, 0.0); // BR
	glVertex3f(50.0, 100.0, 0.0); // Top 
	glEnd();

	// vertical lines 
	glColor3f(0.0, 0.5, 0.0);
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex3f(65.0, 51.0, 0.0);
	glVertex3f(65.0, 100.0, 0.0);

	glVertex3f(75.0, 51.0, 0.0); // Second bottom
	glVertex3f(75.0, 100.0, 0.0); // Second top
	glEnd();
}





void drawHouse(float x, float y) {
	glColor3f(0.827, 0.663, 0.616); // House base color
	glBegin(GL_POLYGON); // House base
	glVertex2f(x - 90, y - 30);
	glVertex2f(x + 90, y - 30);
	glVertex2f(x + 90, y + 30);
	glVertex2f(x - 90, y + 30);
	glEnd();

	glColor3f(0.094, 0.196, 0.263); // color
	glBegin(GL_POLYGON); // Roof
	glVertex2f(x - 100, y + 30);
	glVertex2f(x + 100, y + 30);
	glVertex2f(x + 85, y + 50);
	glVertex2f(x - 85, y + 50);
	glEnd();

	glColor3f(0.973, 0.788, 0.663); // Front part of house
	glBegin(GL_POLYGON);
	glVertex2f(x - 60, y - 30);
	glVertex2f(x, y - 30);
	glVertex2f(x, y + 30);
	glVertex2f(x - 30, y + 60);
	glVertex2f(x - 60, y + 30);
	glEnd();

	glBegin(GL_POLYGON); // Chimney
	glVertex2f(x, y + 50);
	glVertex2f(x + 10, y + 50);
	glVertex2f(x + 10, y + 70);
	glVertex2f(x, y + 70);
	glEnd();

	// windows
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 20, y - 10);//lft
	glVertex2f(x + 40, y - 10);//rght
	glVertex2f(x + 40, y + 20);//right
	glVertex2f(x + 20, y + 20);//left
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x + 60, y - 10);//lft
	glVertex2f(x + 80, y - 10);//rght
	glVertex2f(x + 80, y + 20);//right
	glVertex2f(x + 60, y + 20);//left
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x - 85, y - 5);//lft
	glVertex2f(x - 70, y - 5);//rght
	glVertex2f(x - 70, y + 15);//right
	glVertex2f(x - 85, y + 15);//left
	glEnd();

	drawCircle(x - 30, y + 40, 5, 100);

	glBegin(GL_POLYGON); // Door
	glVertex2f(x - 40, y - 30);
	glVertex2f(x - 20, y - 30);
	glVertex2f(x - 20, y);
	glVertex2f(x - 40, y);
	glEnd();
	drawCircle(x - 30, y, 10, 100);
}

void drawFruit(float x, float y) {
	glColor3f(1.0, 0.0, 0.0); // Red color for the fruit
	drawCircle(x, y, 3, 100); // Draw the fruit as a small circle
}

void drawGrassBlade(float x, float y) {
	glColor3f(0.0, 0.65, 0.0); // Green color for the grass
	glBegin(GL_TRIANGLES);
	glVertex2f(x, y + 10); // Base of the grass
	glVertex2f(x - 2, y); // Left tip
	glVertex2f(x + 2, y); // Right tip
	glEnd();
}


void drawTree(float x, float y) {
	// Draw trunk
	glColor3f(0.545, 0.271, 0.075); // Brown color for the trunk
	glBegin(GL_POLYGON);
	glVertex2f(x - 10, y);    // Bottom left
	glVertex2f(x + 10, y);    // Bottom right
	glVertex2f(x + 5, y + 50); // Top right
	glVertex2f(x - 5, y + 50); // Top left
	glEnd();

	// Draw foliage
	glColor3f(0.0, 0.65, 0.0); // Green color for the leaves
	drawCircle(x, y + 75, 30, 100); // Foliage circle
	drawCircle(x + 25, y + 75, 15, 100);
	drawCircle(x - 25, y + 75, 15, 100);
	drawCircle(x, y + 100, 15, 100);
	drawCircle(x, y + 55, 15, 100);
	drawCircle(x + 20, y + 90, 15, 100);
	drawCircle(x + 20, y + 60, 15, 100);
	drawCircle(x - 20, y + 90, 15, 100);
	drawCircle(x - 20, y + 60, 15, 100);
	// Draw fruits
	drawFruit(x - 22.5, y + 55);
	drawFruit(x + 22.5, y + 55);
	drawFruit(x, y + 50);
	drawFruit(x - 30, y + 75);
	drawFruit(x + 30, y + 75);
	drawFruit(x, y + 105);
	drawFruit(x - 22.5, y + 92.5);
	drawFruit(x + 22.5, y + 92.5);

	drawFruit(x - 10, y + 70);
	drawFruit(x + 10, y + 70);
	drawFruit(x, y + 85);

	drawGrassBlade(x - 9, y);
	drawGrassBlade(x + 9, y);
	drawGrassBlade(x - 6, y - 0.5);
	drawGrassBlade(x + 6, y - 0.5);
	drawGrassBlade(x - 3, y - 1);
	drawGrassBlade(x + 3, y - 1);
	drawGrassBlade(x, y - 1.5);
}

void drawCloud(float x, float y) {
	// Draw clouds
	glColor3f(1.0, 1.0, 1.0); // White color
	drawCircle(x - 25, y, 20, 100); // left
	drawCircle(x + 25, y, 20, 100); // right
	drawCircle(x, y, 30, 100); // center
	//drawCircle(x, y + 10, 30, 100); // top
}


// windmill stand
void windmill(float x, float y)
{
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.075);
	glVertex2i(x - 20, y - 30);
	glVertex2i(x + 20, y - 30);
	glVertex2i(x + 15, y + 30);
	glVertex2i(x - 15, y + 30);
	glEnd();

	glColor3f(0.8, 0.0, 0.0); // 
	glBegin(GL_TRIANGLES);
	glVertex2f(x, y + 60); // 
	glVertex2f(x - 30, y + 30); // 
	glVertex2f(x + 30, y + 30);

	// wings
	glColor3f(0.4, 0.176, 0.070);
	glVertex2f(x, y + 45);
	glVertex2f(x + 32, y + 22.5);
	glVertex2f(x + 20, y + 12.5);

	glVertex2f(x, y + 45);
	glVertex2f(x - 32, y + 22.5);
	glVertex2f(x - 20, y + 12.5);

	glVertex2f(x, y + 45);
	glVertex2f(x + 32, y + 67.5);
	glVertex2f(x + 20, y + 77.5);

	glVertex2f(x, y + 45);
	glVertex2f(x - 32, y + 67.5);
	glVertex2f(x - 20, y + 77.5);
	glEnd();

	drawCircle(x, y + 45, 4, 100);

	glBegin(GL_POLYGON); // Door
	glVertex2f(x - 7.5, y - 30);
	glVertex2f(x + 7.5, y - 30);
	glVertex2f(x + 7.5, y - 10);
	glVertex2f(x - 7.5, y - 10);
	glEnd();
	drawCircle(x, y + 15, 7.5, 100);

}

void drawScene(void) {
	// Clear the buffer and set the drawing color
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw the lake
	drawLake(600, 160); // Draw the lake first

	// Draw the grass
	drawGrass(600, 200); // Move the grass up a bit

	// Draw the house
	drawHouse(225, 220); // Adjust position

	// Draw the tree
	drawTree(75, 190); // Adjust position
	drawTree(375, 190); // Adjust position

	drawCloud(100, 400); // Clouds stay the same
	drawCloud(300, 430);
	drawCloud(500, 415);

	// Draw windmill
	windmill(525, 230); // Adjust position

	// Draw boat
	//glPushMatrix(); // Save current state
	glTranslatef(280.0, 15.0, 0.0); // Adjust position of the boat on the lake
	drawBoat(); // Draw the boat on the lake
	//glPopMatrix(); // Restore saved state

	// Execute the drawing
	glFlush();
}


// Initialization routine.
void setup(void) {
	// the clearing color of the opengl window (background)
	glClearColor(0.53, 0.81, 0.92, 0.0); // Background color
}

// OpenGL window reshape routine.
void resize(int w, int h) {
	// drawing the entire window
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 600.0, 0.0, 500.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Keyboard input processing routine. x & y are location of the mouse
void keyInput(unsigned char key, int x, int y) {
	switch (key) {
	case 27: // ascii of escape key
		exit(0);
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char** argv) {
	glutInit(&argc, argv); // initializes the FreeGLUT library.
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(600, 400);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("nature.cpp");

	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();
	glutMainLoop();
}

