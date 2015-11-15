// SphereWorld.cpp
// OpenGL SuperBible
// Demonstrates an immersive 3D environment using actors
// and a camera.
// Program by Richard S. Wright Jr.

#include "gltools.h"	// OpenGL toolkit
#include "glframe.h"   // Frame Class
#include <math.h>


#define NUM_SPHERES      50
GLFrame    spheres[NUM_SPHERES];
GLFrame    frameCamera;
GLFrame    frametorus;
float delta=0;

int leftknee = 0 , rightknee = 0 , leftthigh= 0 , rightthigh = 0;
int leftarm = 0 , leftshoulder = 0 , rightarm = 0 , rightshoulder = 0;
int head = 0;
int x = 0 , y = 0 ;


//////////////////////////////////////////////////////////////////
// This function does any needed initialization on the rendering
// context.
void SetupRC()
{
    int iSphere;

    // Bluish background
    glClearColor(0.0f, 0.0f, .50f, 1.0f );

    // Draw everything as wire frame
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Randomly place the sphere inhabitants
//    for(iSphere = 0; iSphere < NUM_SPHERES; iSphere++)
//    {
//        // Pick a random location between -20 and 20 at .1 increments
//        float x = ((float)((rand() % 400) - 200) * 0.1f);
//        float z = (float)((rand() % 400) - 200) * 0.1f;
//        spheres[iSphere].SetOrigin(x, 0.0f, z);
//    }

    frametorus.SetOrigin(0.0f, 1.5f, -7.0);

}



///////////////////////////////////////////////////////////
// Draw a gridded ground
void DrawGround(void)
{
    GLfloat fExtent = 20.0f;
    GLfloat fStep = 1.0f;
    GLfloat y = -0.4f;
    GLint iLine;

    glBegin(GL_LINES);
    for(iLine = -fExtent; iLine <= fExtent; iLine += fStep)
    {
        glVertex3f(iLine, y, fExtent);    // Draw Z lines
        glVertex3f(iLine, y, -fExtent);

        glVertex3f(fExtent, y, iLine);
        glVertex3f(-fExtent, y, iLine);
    }

    glEnd();
}


// Called to draw scene
void RenderScene(void)
{
    int i;
    static GLfloat yRot = 0.0f;         // Rotation angle for animation
    yRot += 0.5f;
    
    GLUquadricObj *quadricObj = gluNewQuadric();
    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    frameCamera.ApplyCameraTransform();

    // Draw the ground
    DrawGround();

    glPushMatrix();
    frametorus.ApplyActorTransform();
    
    /* Your Implementation */

    
    glPushMatrix();
    //gltDrawUnitAxes();
        glScalef(4.0,6.472,3.0);
        glutSolidCube(0.2f);
    glPopMatrix();
    
    
    glTranslated(-0.25f, -0.65f, 0.0f);
    
    //right feet
    glPushMatrix();
        glutSolidSphere(0.03f, 15, 15);
    
        glTranslated(0.0f, -0.2f, 0.0f);
        glRotatef(rightthigh , 1, 0, 0);
    
        glPushMatrix();
    
            glScalef(1.5,2.5,1.0);
            glutSolidCube(0.2f);
    
            glTranslated(0.0f, -0.1, 0.0f);
            glPushMatrix();
                glRotatef(rightknee, 1.0, 0.0, 0.0);
                glutSolidSphere(0.02f, 15, 15);
                glTranslated(0.0f, -0.1f, 0.0f);
    
                glPushMatrix();
                    //gltDrawUnitAxes();
                    glScalef(1.5,2.0,1.0);
                    glutSolidCube(0.1f);
                glPopMatrix();
            glPopMatrix();
    
        glPopMatrix();
    
    
    glPopMatrix();
    //end right feet
    
    glTranslated(0.5f, 0.0f, 0.0f);
    
    //left feet
    glPushMatrix();
        glutSolidSphere(0.03f, 15, 15);
    glTranslated(0.0f, -0.2f, 0.0f);
    glRotatef(leftthigh , 1, 0, 0);
    
    glPushMatrix();
    
    glScalef(1.5,2.5,1.0);
    glutSolidCube(0.2f);
    
    glTranslated(0.0f, -0.1, 0.0f);
    glPushMatrix();
    glRotatef(leftknee, 1.0, 0.0, 0.0);
    glutSolidSphere(0.02f, 15, 15);
    glTranslated(0.0f, -0.1f, 0.0f);
    
    glPushMatrix();
    //gltDrawUnitAxes();
    glScalef(1.5,2.0,1.0);
    glutSolidCube(0.1f);
    glPopMatrix();
    glPopMatrix();
    
    glPopMatrix();
    
    glPopMatrix();
    //end left feet
    
    glTranslated(0.2, 0.9, 0.0);
    
    //left hand
    glPushMatrix();
        glutSolidSphere(0.03f, 15,15);
        glTranslated(0.1, 0.0, 0.0);
    glRotatef(leftshoulder, x, 0, y);
    
        glPushMatrix();
            glScalef(1.2,2.5,1.0);
            glutSolidCube(0.2f);
    
    
            glTranslated(0.0f, -0.2f, 0.0f);
    glRotatef(leftarm, x, 0, y);
    
            glPushMatrix();
                glScalef(1.2,2.5,1.0);
                glutSolidCube(0.1f);
            glPopMatrix();
    
        glPopMatrix();
    
    
    glPopMatrix();
    //end left hand
    
    glTranslated(-0.9, 0.0, 0.0);
    
    //right hand
    glPushMatrix();
    glutSolidSphere(0.03f, 15,15);
    glTranslated(-0.1, 0.0, 0.0);
    glRotatef(rightshoulder, x, 0, y);
    
    glPushMatrix();
    glScalef(1.2,2.5,1.0);
    glutSolidCube(0.2f);
    
    
    glTranslated(0.0f, -0.2f, 0.0f);
    glRotatef(rightarm, x, 0, y);
    
    glPushMatrix();
    glScalef(1.2,2.5,1.0);
    glutSolidCube(0.1f);
    glPopMatrix();
    
    glPopMatrix();
    
    glPopMatrix();
    //end right hand
    
    
    glTranslated(0.45, 0.4, 0.0);
    
    //head
    glPushMatrix();
    gltDrawUnitAxes();
    glutSolidSphere(0.03f, 15,15);
    glTranslated(0.0f, 0.4f, 0.0f);
    glutSolidSphere(0.5f, 15, 15);
    glRotatef(head, 0.0, 1.0, 0.0);
    //printf("%d\n" , head);
    
    glTranslated(0.0f, 0.0f,0.5f);
    glRotated(90, 1, 0, 0);
    
    glPushMatrix();
    //triangle
    glBegin(GL_TRIANGLES);
    
    //front triangle
    //glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.15f, 0.0f);
    glVertex3f( -0.15f, -0.15f, 0.0f);
    glVertex3f( 0.1f,  -0.15f, 0.0f);
    
    //right side triangle
    //glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    glVertex3f( 0.15f,  -0.15f, 0.0f);
    glVertex3f(0.0f, 0.15f, 0.0f);
    glVertex3f( 0.0f,  -0.15f, -0.15f);
    
    //left side triangle
    //glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glVertex3f( -0.15f, -0.15f, 0.0f);
    glVertex3f(0.0f, 0.15f, 0.0f);
    glVertex3f( 0.0f,  -0.15f, -0.15f);
    
    //bottom triangle
    //glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
    glVertex3f( -0.15f, -0.15f, 0.0f);
    glVertex3f( 0.15f,  -0.15f, 0.0f);
    glVertex3f( 0.0f,  -0.15f, -0.15f);
    
    glEnd();
    //end triangle
    glPopMatrix();
    
    glPopMatrix();
    //end head
    
    
    
    
    
    glPopMatrix();
        //push framecamera
    glPopMatrix();
        //push frametorus

    // Do the buffer Swap
    glutSwapBuffers();
}

void jump (int i)
{
    x = 1;
    if(i < 25)
    {
        if(i<5)
        {
            frametorus.TranslateLocal(0.0f, -0.1f, 0.0f);
            leftthigh = leftthigh - 9;
            rightthigh = rightthigh - 9;
            leftknee+=12;
            rightknee+=12;
            rightshoulder-=6;
            leftshoulder-=6;
            rightarm-=18;
            leftarm-=18;
        }
        else if(i< 10)
        {
            int j = i%5;
            frametorus.TranslateLocal(0.0f, 0.2f , 0.0f);
            leftthigh = leftthigh + 9;
            rightthigh = rightthigh + 9;
            leftknee-=12;
            rightknee-=12;
            rightshoulder+=6;
            leftshoulder+=6;
            rightarm+=18;
            leftarm+=18;
        }
        else if(i<15)
        {
            frametorus.TranslateLocal(0.0f, -0.1f, 0.0f);
        }
        else if(i < 20)
        {
            frametorus.TranslateLocal(0.0f, -0.1f, 0.0f);
            leftthigh-=9;
            rightthigh-=9;
            leftknee+=12;
            rightknee+=12;
            rightshoulder-=6;
            leftshoulder-=6;
            rightarm-=18;
            leftarm-=18;
        }
        else
        {
            frametorus.TranslateLocal(0.0f, 0.1f, 0.0f);
            leftthigh+=9;
            rightthigh+=9;
            leftknee-=12;
            rightknee-=12;
            rightshoulder+=6;
            leftshoulder+=6;
            rightarm+=18;
            leftarm+=18;

        }
        i++;
        glutTimerFunc(100, jump , i );
    }
    glutPostRedisplay();
}

void walk(int i)
{
    x = 1;
    if(i < 9)
    {
        if(i < 3)
        {
            frametorus.TranslateLocal(0.0f, 0.0f, 0.1f);
            rightthigh-=10;
            rightknee+=10;
            leftthigh+=10;
            leftshoulder-=5;
            leftarm-=5;
            rightshoulder+=5;
            rightarm+=5;
        }
        else if (i < 6)
        {
            frametorus.TranslateLocal(0.0f, 0.0f, 0.1f);
            leftthigh-=20;
            leftknee+=10;
            rightthigh+=20;
            leftshoulder+=10;
            leftarm+=10;
            rightshoulder-=10;
            rightarm-=10;
        }
        else
        {
            frametorus.TranslateLocal(0.0f, 0.0f, 0.1f);
            rightthigh-=10;
            leftthigh+=10;
            rightknee-=10;
            leftknee-=10;
            leftshoulder-=5;
            leftarm-=5;
            rightshoulder+=5;
            rightarm+=5;
        }
        i++;
        glutTimerFunc(100, walk, i);
    }
    glutPostRedisplay();
}
void wave(int i)
{
    if(i < 12)
    {
        if(i < 3)
        {
            x=1;
            y=0;
            rightshoulder-=15;
            rightarm-=30;
        }
        else if(i < 9)
        {
            x = 0;
            y = 1;
            if(i%2 == 1)
                rightarm -= 30;
            else
                rightarm += 30;
            
        }
        else
        {
            x = 1;
            y= 0 ;
            rightshoulder+=15;
            rightarm+=30;
        }
        
        i++;
        glutTimerFunc(100, wave, i);
    }
    glutPostRedisplay();
}

void clap(int i)
{
    if (i < 9)
    {
        if(i < 3)
            head +=30;
        else if (i < 6)
            head -= 60;
        else
            head+=30;
    
        i++;
        glutTimerFunc(100, clap, i);
    }
    glutPostRedisplay();
}


void bf(int i)
{
    /*
        Your Implementation
    */

    glutPostRedisplay();
}

void myKeys(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'j':
            jump(0);
            break;
//    case 'k':
//            walk(0);
//            break;
    case 'p':
            wave(0);
            break;
    case 'o':
            clap(0);
            break;
    
    case 'w':
        /* Your Implementation */
            frametorus.MoveForward(0.1f);
            walk(0);
        break;
    case 's':
        /* Your Implementation */
            frametorus.RotateLocalY(3.15f);
        break;
    case 'a':
        /* Your Implementation */
            frametorus.RotateLocalY(0.1f);
        break;
    case 'd':
        /* Your Implementation */
            frametorus.RotateLocalY(-0.1f);
        break;
    case 'u':
            frameCamera.MoveUp(0.1f);
        break;
    case 'l':
            frameCamera.MoveUp(-0.1f);
            break;
            

    case 'b':
        bf(0);
        break;
    }
    glutPostRedisplay();
}


// Respond to arrow keys by moving the camera frame of reference
void SpecialKeys(int key, int x, int y)
{
    if(key == GLUT_KEY_UP)
        frameCamera.MoveForward(0.1f);

    if(key == GLUT_KEY_DOWN)
        frameCamera.MoveForward(-0.1f);

    if(key == GLUT_KEY_LEFT)
        frameCamera.RotateLocalY(0.1f);

    if(key == GLUT_KEY_RIGHT)
        frameCamera.RotateLocalY(-0.1f);

    // Refresh the Window
    glutPostRedisplay();
}



///////////////////////////////////////////////////////////
// Called by GLUT library when idle (window not being
// resized or moved)
void TimerFunction(int value)
{
    // Redraw the scene with new coordinates
    glutPostRedisplay();
    glutTimerFunc(3,TimerFunction, 1);
}

void ChangeSize(int w, int h)
{
    GLfloat fAspect;

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if(h == 0)
        h = 1;

    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w / (GLfloat)h;

    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set the clipping volume
    gluPerspective(35.0f, fAspect, 1.0f, 50.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutCreateWindow("OpenGL SphereWorld Demo");
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(RenderScene);
    glutKeyboardFunc(myKeys);
    glutSpecialFunc(SpecialKeys);

    SetupRC();
    glutTimerFunc(33, TimerFunction, 1);

    glutMainLoop();

    return 0;
}
