#include <windows.h>
#include <vector>
#include <GL/glut.h>    /* OpenGL Utility Toolkit header */

#include<iostream>
#include "bresenham.h"
#include "toBST.h"
#include "tidy.h"

using namespace std;

//node * root = new node;

void display();
void reshape(int, int);
void init1();


int screen_w=glutGet(GLUT_SCREEN_WIDTH)-100;
int screen_h=glutGet(GLUT_SCREEN_HEIGHT)-100;

void init1()
{

    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(screen_w,screen_h);
    glutCreateWindow("Tidier Tree drawing");
    glutDisplayFunc(display);//Its a display callback
    glutReshapeFunc(reshape);//callback func to rehape window
}

int x0,y0,x1,y1,r;



int main(int argc, char ** argv)
{

    int n;
    vector <int> arr(10000000);
    cout<<"Enter n";
    cin>>n;

    cout << "Please enter the array: ";
        for (int i = 0; i < n; ++i) cin >> arr[i];

        root= ArrToBST(arr); // forms a BST

    //cin>>x0>>y0>>r;
    glutInit( &argc,argv);
    init1();


    //glClearColor(0.0,1.0,1.0,0.0);//changing colour by giving R G B values
    glutMainLoop();

    return 0;

}

void display()//one call to display function is considered one frame
{
    glClear(GL_COLOR_BUFFER_BIT);//to clear the frame everytime before drawing
    glLoadIdentity();//clears the transformation Matrix
    //draw
    glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);
    tidy();

    //glPointSize(10);//changing picel size
   // glBegin(GL_POINTS);//to start specifying vertices/lines/polygons

        //bres_line( x0, y0, x1,y1);
        //bres_circle(x0,y0,r);

    //



    glFlush();// to display the frame buffer
}

void reshape(int w, int h)
{
    //setting viewport and projection
    //viewport= area in the window where drawings will be displayed
    glViewport(0,0,(GLsizei)w,(GLsizei)h);

    glMatrixMode(GL_PROJECTION);//changing to projection mode to change projection
    glLoadIdentity();//clears the transformation Matrix
    gluOrtho2D(0,screen_w,0,screen_h);


    glMatrixMode(GL_MODELVIEW);//coming back to default mode to draw


}


