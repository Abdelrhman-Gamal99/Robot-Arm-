#include <stdlib.h>
#include <GL/glut.h>


static int shoulder = 0, elbow = 0, finger_1_Base = 0, finger_1_Up = 0, finger_2_Base = 0, finger_2_Up = 0, finger_3_Base = 0, finger_3_Up = 0
, finger_4_Base = 0, finger_4_Up = 0, finger_5_Base = 0, finger_5_Up = 0;
int moving, startx, starty;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.6, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.6, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    //Draw finger finger_1_Base 
    glTranslatef(1.0, -0.25, 0.0);
    glPushMatrix();
    glRotatef((GLfloat)finger_1_Base, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();


   //Draw finger finger_1_Up
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)finger_1_Up, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();

  
    //Draw finger finger_2_Base 
    glTranslatef(0.0, 0.5, 0.0);
    glPushMatrix();
    glRotatef((GLfloat)finger_2_Base, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.45);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();

    //Draw finger finger_2_Up 
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)finger_2_Up, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();
   
    //Draw finger finger_3_Base 
    glPushMatrix();
    glRotatef((GLfloat)finger_3_Base, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.15);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    //Draw finger_3_Up
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)finger_3_Up, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();

    //Draw finger_4_Base
    glPushMatrix();
    glRotatef((GLfloat)finger_4_Base, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, -0.15);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    
    //Draw finger_4_Up
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)finger_4_Up, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    glPopMatrix();

    //Draw finger_5_Base
    glRotatef((GLfloat)finger_5_Base, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, -0.45);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();




    //Draw finger_5_Up
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)finger_5_Up, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.1);
    glutWireCube(1);
    glPopMatrix();
    
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        shoulder = (shoulder + 5) % 360;
        glutPostRedisplay();
        break;
    case 'S':
        shoulder = (shoulder - 5) % 360;
        glutPostRedisplay();
        break;
    case 'e':
        if (elbow < 170)
        {
            elbow = (elbow + 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'E':
        if (elbow > 0)
        {
            elbow = (elbow - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'f':
      
        if (finger_1_Base < 90)
        {
            finger_1_Base = (finger_1_Base + 5) % 360;
        }
        
        glutPostRedisplay();
        break;
        
    case 'F':
        if (finger_1_Base > 0)
        {
            finger_1_Base = (finger_1_Base - 5) % 360;
        }
        
        glutPostRedisplay();
        break;
    case 'g':
        if (finger_1_Up < 90)
        {
            finger_1_Up = (finger_1_Up + 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'G':
        if (finger_1_Up > 0)
        {
            finger_1_Up = (finger_1_Up - 5) % 360;
        }
        glutPostRedisplay();
        break;


    case 'h':
        if (finger_2_Base < 90)
        {
            finger_2_Base = (finger_2_Base + 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'H':
        if (finger_2_Base > 0)
        {
            finger_2_Base = (finger_2_Base - 5) % 360;
        }

        glutPostRedisplay();
        break;
    case 'j':
        if (finger_2_Up > -90)
        {
            finger_2_Up = (finger_2_Up - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'J':
        if (finger_2_Up < 0)
        {
            finger_2_Up = (finger_2_Up + 5) % 360;
        }
        glutPostRedisplay();
        break;


    case 'k':
        if (finger_3_Base < 90)
        {
            finger_3_Base = (finger_3_Base + 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'K':
        if (finger_3_Base > 0)
        {
            finger_3_Base = (finger_3_Base - 5) % 360;
        }

        glutPostRedisplay();
        break;
    case 'l':
        if (finger_3_Up > -90)
        {
            finger_3_Up = (finger_3_Up - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'L':
        if (finger_3_Up < 0)
        {
            finger_3_Up = (finger_3_Up + 5) % 360;
        }
        glutPostRedisplay();
        break;

    case 'u':
        if (finger_4_Base < 90)
        {
            finger_4_Base = (finger_4_Base + 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'U':
        if (finger_4_Base > 0)
        {
            finger_4_Base = (finger_4_Base - 5) % 360;
        }

        glutPostRedisplay();
        break;
    case 'i':
        if (finger_4_Up >- 90)
        {
            finger_4_Up = (finger_4_Up - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'I':
        if (finger_4_Up < 0)
        {
            finger_4_Up = (finger_4_Up + 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'o':
        if (finger_5_Base < 90)
        {
            finger_5_Base = (finger_5_Base + 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'O':
        if (finger_5_Base > 0)
        {
            finger_5_Base = (finger_5_Base - 5) % 360;
        }

        glutPostRedisplay();
        break;
    case 'p':
        if (finger_5_Up >- 90)
        {
            finger_5_Up = (finger_5_Up - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'P':
        if (finger_5_Up < 0)
        {
            finger_5_Up = (finger_5_Up + 5) % 360;
        }
        glutPostRedisplay();
        break;


    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

static void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving = 0;
        }
    }
}


static void motion(int x, int y)
{
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}