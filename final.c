#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int Height = 0;
int Width = 0;

char *start = " CLICK HERE TO START";


char *title = "SIMULATION OF PARALLEL MIRRORS";
char *devBy = "Developed By : ";
char *Tharun = "Tharun [USN : 1PE13CS021]";
char *Anisha = "Anisha [USN : 1PE13CS023]";
char *co_ord = "Project Co-ordinator : ";
char *sudha = "Y.Sudha";

char *inst1 = "This project aims at simulation of parallel mirrors";
char *inst2 = "press '+' to increase the number of reflections on either sides";
char *inst3 = "press '-' to decrease the number of reflections on either sides";
char *inst4 = "press 't' or 'T' to change the view to top view or to front view";
char *inst5 = "press any other key to exit the simulation";
char *inst6 = "press 1 for cylinder , 2 for cone , 3 for cuboid";
char *inst7 = "press r to rotate sphere , s to stop rotation";
char *inst8 = "press x to remove/add sphere";
/* Function Description:
 *
 *
 */
void myInit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	gluOrtho2D(0.0, (float)(Width - 1), 0.0, (float)(Height -1));
}


void createMenu()
{
	float X_mid = Width / 2;
	X_mid = (X_mid + X_mid - 1) / 2;
	float Y_mid = Height / 2;
	Y_mid = (Y_mid + Y_mid - 1) / 2;
	int margin = 30;
	glColor3f(0.0, 1.0, 0.0);
	// BUTTON
	glBegin(GL_QUADS);
		glVertex2f(X_mid - 155, Y_mid - 180);
		glVertex2f(X_mid - 155, Y_mid - 130);
		glVertex2f(X_mid + 155, Y_mid - 130);
		glVertex2f(X_mid + 155, Y_mid - 180);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2i(X_mid - 140, Y_mid-160);
	for (int i = 0; i < strlen(start); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, start[i]);
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glColor3f(0,0,0);
	glRasterPos2i((Width-850 ), Height - 100);
	for (int i = 0; i < strlen(title); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);
	}

	float X_mid = Width / 2;
	X_mid = (X_mid + X_mid - 1) / 2;

	glRasterPos2i(Width - 950, Height - 180);
	for (int i = 0; i < strlen(inst1); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, inst1[i]);
	}
	glRasterPos2i(Width - 950, Height - 220);
	for (int i = 0; i < strlen(inst2); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, inst2[i]);
	}
	glRasterPos2i(Width - 950, Height - 260);
	for (int i = 0; i < strlen(inst3); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, inst3[i]);
	}
	glRasterPos2i(Width - 950, Height - 300);
	for (int i = 0; i < strlen(inst4); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, inst4[i]);
	}
	glRasterPos2i(Width - 950, Height - 340);
	for (int i = 0; i < strlen(inst5); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, inst5[i]);
	}
	glRasterPos2i(Width - 950, Height - 380);
	for (int i = 0; i < strlen(inst6); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, inst6[i]);
	}
	glRasterPos2i(Width - 950, Height - 420);
	for (int i = 0; i < strlen(inst7); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, inst7[i]);
	}
	glRasterPos2i(Width - 950, Height - 460);
	for (int i = 0; i < strlen(inst8); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, inst8[i]);
	}
	glRasterPos2i(Width-300, 120);
	for (int i = 0; i < strlen(devBy); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, devBy[i]);
	}

	glRasterPos2i(Width-300, 90);
	for (int i = 0; i < strlen(Tharun); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Tharun[i]);
	}

	glRasterPos2i(Width-300, 60);
	for (int i = 0; i < strlen(Anisha); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Anisha[i]);
	}

	glRasterPos2i(Width-1200, 120);
	for (int i = 0; i < strlen(co_ord); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, co_ord[i]);
	}

	glRasterPos2i(Width-1200, 80);
	for (int i = 0; i < strlen(sudha); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, sudha[i]);
	}
	createMenu();
	glFlush();
}

/* Function Description:
 *
 *
 */
void mouse(int btn, int state, int x, int y)
{
	float X_mid = Width / 2;
	X_mid = (X_mid + X_mid - 1) / 2;
	float Y_mid = Height / 2;
	Y_mid = (Y_mid + Y_mid - 1) / 2;
	int xMin = X_mid - 155;
	int xMax = X_mid + 155;
	int yMin = Y_mid - 180;
	int yMax = Y_mid - 130;
	pid_t gamePid;
	char cmd[100] = "g++ -lGL -lGLU -lglut main.c -o menu && ./menu";
	if ((gamePid = fork()) < 0) {
	}
	else if(gamePid == 0) {
		system(cmd);
	}
	else {
		exit(0);
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	Width = glutGet(GLUT_SCREEN_WIDTH);
	Height = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutCreateWindow("CG-Project");
	myInit();
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutFullScreen();
	glMatrixMode(GL_PROJECTION);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
