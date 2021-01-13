#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<stdio.h>

static float	cld	=  140.0;
static float	cld2	= -127.0;
static float	cld3	= -140.0;

static float	bird1	= 140.0;
static float	bird2	= -127.0;
static float	bird3	= -140.0;


int n=0;
int l=0;

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glOrtho(0,500,0,600,-5,5);
}

void delay()
{
    for(int i=0;i<100000000;i++);
}
void cloud_move(){
    cld=cld+.03;
    if(cld>600)
        cld = -70;


    cld3=cld3+.02;
    if(cld3>600)
        cld3 = -70;


    cld2=cld2+.03;
    if(cld2>600)
        cld2 = -70;



        glutPostRedisplay();
}
void bird_move(){
    bird1=bird1+.06;
    if(bird1>600)
        bird1 = -70;


    bird2=bird2+.05;
    if(bird2>600)
       bird2= -100;


    bird3=bird3+.07;
    if(bird3>600)
        bird3 = -70;



        glutPostRedisplay();
}




void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)//radius_x,radius_y,certre_position_x,centre_position_y
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=500;i++)

    {
        float angle = 2.0f * 3.1416f * i/500;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();



}

void sky(){


  glColor3f(0.902, 0.902, 0.980);
  cloud_move();
  circle(25,35,5,492);
  circle(25,35,60,492);
  circle(20,30,50,515);
  circle(25,35,23,520);
  circle(25,35,25,485);

}

void bird(){


  glColor3f(1, 1, 1);
  bird_move();
   glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex3f (7,292,0);
    glVertex3f (-4,310,0);
    glVertex3f (-1,292,0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f (10,292,0);
    glVertex3f (3,312,0);
    glVertex3f (-1,292,0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f (17,292,0);
    glVertex3f (3,297,0);
    glVertex3f (-1,286,0);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex3f (1,292,0);
    glVertex3f (-8,295,0);
    glVertex3f (-8,289,0);
    glEnd();
    circle(7,4,5,292);
    circle(4,4,11,295);
    glPopMatrix();


  bird_move();
   glPushMatrix();
    glBegin(GL_TRIANGLES);
    glVertex3f (96,392,0);
    glVertex3f (86,395,0);
    glVertex3f (86,389,0);
    glEnd();

     glBegin(GL_TRIANGLES);
    glVertex3f (102,392,0);
    glVertex3f (90,410,0);
    glVertex3f (93,392,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f (105,392,0);
    glVertex3f (97,412,0);
    glVertex3f (93,392,0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f (112,392,0);
    glVertex3f (97,397,0);
    glVertex3f (93,386,0);
    glEnd();
  circle(7,4,100,392);
  circle(4,4,106,395);
  glPopMatrix();





}



void sky2(){

        glPushMatrix();
        glTranslatef(cld,1,0);
        sky();
        glPopMatrix();


        glPushMatrix();
        glTranslatef(cld2,2,0);
        sky();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(cld3,0,0);
        sky();
        glPopMatrix();

}

void birds2(){

        glPushMatrix();
        glTranslatef(bird1,1,0);
        bird();
        glPopMatrix();


        glPushMatrix();
        glTranslatef(bird2,2,0);
        bird();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(bird3,0,0);
        bird();
        glPopMatrix();

}

void sun()
{
    glColor3f(1.000, 0.647, 0.000);//sun
    glPushMatrix();
    circle(35,50,100,440);
    glPopMatrix();
}



void skyblue(void)
{
    if(n==1)
    {
    glColor3f(0.098, 0.098, 0.439);//sky
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f (0,100,0);
    glVertex3f (500,100,0);
    glVertex3f (500,600,0);
    glVertex3f (0,600,0);
    glEnd();
    glPopMatrix();

    glColor3f(1.000, 0.749, 0.000);//moon
    glPushMatrix();
    circle(35,50,100,440);
    glPopMatrix();

    glColor3f(0.098, 0.098, 0.439);//moon
    glPushMatrix();
    circle(35,50,110,460);
    glPopMatrix();

    glColor3f (1.0, 1.0, 1.0);//star1
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.7, 360.0*0.7, 0.0);
    glVertex3f (133.0*0.7,362.0*0.7, 0.0);
    glVertex3f (131.0*0.7, 360.0*0.7, 0.0);
    glVertex3f (129.0*0.7,358.0*0.7, 0.0);
    glVertex3f (131.0*0.7,356.0*0.7, 0.0);
    glVertex3f (133.0*0.7,354.0*0.7, 0.0);
    glVertex3f (135.0*0.7,356.0*0.7, 0.0);
    glVertex3f (137.0*0.7,358.0*0.7, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);//star2
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.6+260, 360.0*0.6, 0.0);
    glVertex3f (133.0*0.6+260,362.0*0.6, 0.0);
    glVertex3f (131.0*0.6+260, 360.0*0.6, 0.0);
    glVertex3f (129.0*0.6+260,358.0*0.6, 0.0);
    glVertex3f (131.0*0.6+260,356.0*0.6, 0.0);
    glVertex3f (133.0*0.6+260,354.0*0.6, 0.0);
    glVertex3f (135.0*0.6+260,356.0*0.6, 0.0);
    glVertex3f (137.0*0.6+260,358.0*0.6, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);//star3
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.6+275, 360.0*0.6+100, 0.0);
    glVertex3f (133.0*0.6+275,362.0*0.6+100, 0.0);
    glVertex3f (131.0*0.6+275, 360.0*0.6+100, 0.0);
    glVertex3f (129.0*0.6+275,358.0*0.6+100, 0.0);
    glVertex3f (131.0*0.6+275,356.0*0.6+100, 0.0);
    glVertex3f (133.0*0.6+275,354.0*0.6+100, 0.0);
    glVertex3f (135.0*0.6+275,356.0*0.6+100, 0.0);
    glVertex3f (137.0*0.6+275,358.0*0.6+100, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);//star4
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.6-100, 360.0*0.6+150, 0.0);
    glVertex3f (133.0*0.6-100,362.0*0.6+150, 0.0);
    glVertex3f (131.0*0.6-100, 360.0*0.6+150, 0.0);
    glVertex3f (129.0*0.6-100,358.0*0.6+150, 0.0);
    glVertex3f (131.0*0.6-100,356.0*0.6+150, 0.0);
    glVertex3f (133.0*0.6-100,354.0*0.6+150, 0.0);
    glVertex3f (135.0*0.6-100,356.0*0.6+150, 0.0);
    glVertex3f (137.0*0.6-100,358.0*0.6+150, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);//star5
    glBegin(GL_POLYGON);

    glVertex3f (135.0-100, 360.0-100, 0.0);
    glVertex3f (133.0-100,362.0-100, 0.0);
    glVertex3f (131.0-100, 360.0-100, 0.0);
    glVertex3f (129.0-100,358.0-100, 0.0);
    glVertex3f (131.0-100,356.0-100, 0.0);
    glVertex3f (133.0-100,354.0-100, 0.0);
    glVertex3f (135.0-100,356.0-100, 0.0);
    glVertex3f (137.0-100,358.0-100, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);//star6
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.7+120, 360.0*0.7+200, 0.0);
    glVertex3f (133.0*0.7+120,362.0*0.7+200, 0.0);
    glVertex3f (131.0*0.7+120, 360.0*0.7+200, 0.0);
    glVertex3f (129.0*0.7+120,358.0*0.7+200, 0.0);
    glVertex3f (131.0*0.7+120,356.0*0.7+200, 0.0);
    glVertex3f (133.0*0.7+120,354.0*0.7+200, 0.0);
    glVertex3f (135.0*0.7+120,356.0*0.7+200, 0.0);
    glVertex3f (137.0*0.7+120,358.0*0.7+200, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);//star5
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.6+330, 360.0*0.6-100, 0.0);
    glVertex3f (133.0*0.6+330,362.0*0.6-100, 0.0);
    glVertex3f (131.0*0.6+330, 360.0*0.6-100, 0.0);
    glVertex3f (129.0*0.6+330,358.0*0.6-100, 0.0);
    glVertex3f (131.0*0.6+330,356.0*0.6-100, 0.0);
    glVertex3f (133.0*0.6+330,354.0*0.6-100, 0.0);
    glVertex3f (135.0*0.6+330,356.0*0.6-100, 0.0);
    glVertex3f (137.0*0.6+330,358.0*0.6-100, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);//star5
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.5+330, 360.0*0.5+100, 0.0);
    glVertex3f (133.0*0.5+330,362.0*0.5+100, 0.0);
    glVertex3f (131.0*0.5+330, 360.0*0.5+100, 0.0);
    glVertex3f (129.0*0.5+330,358.0*0.5+100, 0.0);
    glVertex3f (131.0*0.5+330,356.0*0.5+100, 0.0);
    glVertex3f (133.0*0.5+330,354.0*0.5+100, 0.0);
    glVertex3f (135.0*0.5+330,356.0*0.5+100, 0.0);
    glVertex3f (137.0*0.5+330,358.0*0.5+100, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);//star5
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.5+370, 360.0*0.5+180, 0.0);
    glVertex3f (133.0*0.5+370,362.0*0.5+180, 0.0);
    glVertex3f (131.0*0.5+370, 360.0*0.5+180, 0.0);
    glVertex3f (129.0*0.5+370,358.0*0.5+180, 0.0);
    glVertex3f (131.0*0.5+370,356.0*0.5+180, 0.0);
    glVertex3f (133.0*0.5+370,354.0*0.5+180, 0.0);
    glVertex3f (135.0*0.5+370,356.0*0.5+180, 0.0);
    glVertex3f (137.0*0.5+370,358.0*0.5+180, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);//star5
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.5+390, 360.0*0.5+380, 0.0);
    glVertex3f (133.0*0.5+390,362.0*0.5+380, 0.0);
    glVertex3f (131.0*0.5+390, 360.0*0.5+380, 0.0);
    glVertex3f (129.0*0.5+390,358.0*0.5+380, 0.0);
    glVertex3f (131.0*0.5+390,356.0*0.5+380, 0.0);
    glVertex3f (133.0*0.5+390,354.0*0.5+380, 0.0);
    glVertex3f (135.0*0.5+390,356.0*0.5+380, 0.0);
    glVertex3f (137.0*0.5+390,358.0*0.5+380, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);//star5
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.5+420, 360.0*0.5+280, 0.0);
    glVertex3f (133.0*0.5+420,362.0*0.5+280, 0.0);
    glVertex3f (131.0*0.5+420, 360.0*0.5+280, 0.0);
    glVertex3f (129.0*0.5+420,358.0*0.5+280, 0.0);
    glVertex3f (131.0*0.5+420,356.0*0.5+280, 0.0);
    glVertex3f (133.0*0.5+420,354.0*0.5+280, 0.0);
    glVertex3f (135.0*0.5+420,356.0*0.5+280, 0.0);
    glVertex3f (137.0*0.5+420,358.0*0.5+280, 0.0);
    glEnd();


    glColor3f (1.0, 1.0, 1.0);//star5
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.5+20, 360.0*0.5+380, 0.0);
    glVertex3f (133.0*0.5+20,362.0*0.5+380, 0.0);
    glVertex3f (131.0*0.5+20, 360.0*0.5+380, 0.0);
    glVertex3f (129.0*0.5+20,358.0*0.5+380, 0.0);
    glVertex3f (131.0*0.5+20,356.0*0.5+380, 0.0);
    glVertex3f (133.0*0.5+20,354.0*0.5+380, 0.0);
    glVertex3f (135.0*0.5+20,356.0*0.5+380, 0.0);
    glVertex3f (137.0*0.5+20,358.0*0.5+380, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);//star5
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.5+220, 360.0*0.5+380, 0.0);
    glVertex3f (133.0*0.5+220,362.0*0.5+380, 0.0);
    glVertex3f (131.0*0.5+220, 360.0*0.5+380, 0.0);
    glVertex3f (129.0*0.5+220,358.0*0.5+380, 0.0);
    glVertex3f (131.0*0.5+220,356.0*0.5+380, 0.0);
    glVertex3f (133.0*0.5+220,354.0*0.5+380, 0.0);
    glVertex3f (135.0*0.5+220,356.0*0.5+380, 0.0);
    glVertex3f (137.0*0.5+220,358.0*0.5+380, 0.0);
    glEnd();


    glColor3f (1.0, 1.0, 1.0);//star5
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.5+120, 360.0*0.5+330, 0.0);
    glVertex3f (133.0*0.5+120,362.0*0.5+330, 0.0);
    glVertex3f (131.0*0.5+120, 360.0*0.5+330, 0.0);
    glVertex3f (129.0*0.5+120,358.0*0.5+330, 0.0);
    glVertex3f (131.0*0.5+120,356.0*0.5+330, 0.0);
    glVertex3f (133.0*0.5+120,354.0*0.5+330, 0.0);
    glVertex3f (135.0*0.5+120,356.0*0.5+330, 0.0);
    glVertex3f (137.0*0.5+120,358.0*0.5+330, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);//star5
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.5-120, 360.0*0.5+330, 0.0);
    glVertex3f (133.0*0.5-120,362.0*0.5+330, 0.0);
    glVertex3f (131.0*0.5-120, 360.0*0.5+330, 0.0);
    glVertex3f (129.0*0.5-120,358.0*0.5+330, 0.0);
    glVertex3f (131.0*0.5-120,356.0*0.5+330, 0.0);
    glVertex3f (133.0*0.5-120,354.0*0.5+330, 0.0);
    glVertex3f (135.0*0.5-120,356.0*0.5+330, 0.0);
    glVertex3f (137.0*0.5-120,358.0*0.5+330, 0.0);
    glEnd();

     glColor3f (1.0, 1.0, 1.0);//star2
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.6+360, 360.0*0.6, 0.0);
    glVertex3f (133.0*0.6+360,362.0*0.6, 0.0);
    glVertex3f (131.0*0.6+360, 360.0*0.6, 0.0);
    glVertex3f (129.0*0.6+360,358.0*0.6, 0.0);
    glVertex3f (131.0*0.6+360,356.0*0.6, 0.0);
    glVertex3f (133.0*0.6+360,354.0*0.6, 0.0);
    glVertex3f (135.0*0.6+360,356.0*0.6, 0.0);
    glVertex3f (137.0*0.6+360,358.0*0.6, 0.0);
    glEnd();

     glColor3f (1.0, 1.0, 1.0);//star2
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.6+260, 360.0*0.6+320, 0.0);
    glVertex3f (133.0*0.6+260,362.0*0.6+320, 0.0);
    glVertex3f (131.0*0.6+260, 360.0*0.6+320, 0.0);
    glVertex3f (129.0*0.6+260,358.0*0.6+320, 0.0);
    glVertex3f (131.0*0.6+260,356.0*0.6+320, 0.0);
    glVertex3f (133.0*0.6+260,354.0*0.6+320, 0.0);
    glVertex3f (135.0*0.6+260,356.0*0.6+320, 0.0);
    glVertex3f (137.0*0.6+260,358.0*0.6+320, 0.0);
    glEnd();

     glColor3f (1.0, 1.0, 1.0);//star2
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.6+260, 360.0*0.6+220, 0.0);
    glVertex3f (133.0*0.6+260,362.0*0.6+220, 0.0);
    glVertex3f (131.0*0.6+260, 360.0*0.6+220, 0.0);
    glVertex3f (129.0*0.6+260,358.0*0.6+220, 0.0);
    glVertex3f (131.0*0.6+260,356.0*0.6+220, 0.0);
    glVertex3f (133.0*0.6+260,354.0*0.6+220, 0.0);
    glVertex3f (135.0*0.6+260,356.0*0.6+220, 0.0);
    glVertex3f (137.0*0.6+260,358.0*0.6+220, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);//star2
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.6+340, 360.0*0.6+240, 0.0);
    glVertex3f (133.0*0.6+340,362.0*0.6+240, 0.0);
    glVertex3f (131.0*0.6+340, 360.0*0.6+240, 0.0);
    glVertex3f (129.0*0.6+340,358.0*0.6+240, 0.0);
    glVertex3f (131.0*0.6+340,356.0*0.6+240, 0.0);
    glVertex3f (133.0*0.6+340,354.0*0.6+240, 0.0);
    glVertex3f (135.0*0.6+340,356.0*0.6+240, 0.0);
    glVertex3f (137.0*0.6+340,358.0*0.6+240, 0.0);
    glEnd();

     glColor3f (1.0, 1.0, 1.0);//star2
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.6+390, 360.0*0.6+80, 0.0);
    glVertex3f (133.0*0.6+390,362.0*0.6+80, 0.0);
    glVertex3f (131.0*0.6+390, 360.0*0.6+80, 0.0);
    glVertex3f (129.0*0.6+390,358.0*0.6+80, 0.0);
    glVertex3f (131.0*0.6+390,356.0*0.6+80, 0.0);
    glVertex3f (133.0*0.6+390,354.0*0.6+80, 0.0);
    glVertex3f (135.0*0.6+390,356.0*0.6+80, 0.0);
    glVertex3f (137.0*0.6+390,358.0*0.6+80, 0.0);
    glEnd();

      glColor3f (1.0, 1.0, 1.0);//star2
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.6+100, 360.0*0.6+80, 0.0);
    glVertex3f (133.0*0.6+100,362.0*0.6+80, 0.0);
    glVertex3f (131.0*0.6+100, 360.0*0.6+80, 0.0);
    glVertex3f (129.0*0.6+100,358.0*0.6+80, 0.0);
    glVertex3f (131.0*0.6+100,356.0*0.6+80, 0.0);
    glVertex3f (133.0*0.6+100,354.0*0.6+80, 0.0);
    glVertex3f (135.0*0.6+100,356.0*0.6+80, 0.0);
    glVertex3f (137.0*0.6+100,358.0*0.6+80, 0.0);
    glEnd();

      glColor3f (1.0, 1.0, 1.0);//star2
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.6+130, 360.0*0.6+150, 0.0);
    glVertex3f (133.0*0.6+130,362.0*0.6+150, 0.0);
    glVertex3f (131.0*0.6+130, 360.0*0.6+150, 0.0);
    glVertex3f (129.0*0.6+130,358.0*0.6+150, 0.0);
    glVertex3f (131.0*0.6+130,356.0*0.6+150, 0.0);
    glVertex3f (133.0*0.6+130,354.0*0.6+150, 0.0);
    glVertex3f (135.0*0.6+130,356.0*0.6+150, 0.0);
    glVertex3f (137.0*0.6+130,358.0*0.6+150, 0.0);
    glEnd();

    glColor3f (1.0, 1.0, 1.0);//star2
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.6+230, 360.0*0.6+150, 0.0);
    glVertex3f (133.0*0.6+230,362.0*0.6+150, 0.0);
    glVertex3f (131.0*0.6+230, 360.0*0.6+150, 0.0);
    glVertex3f (129.0*0.6+230,358.0*0.6+150, 0.0);
    glVertex3f (131.0*0.6+230,356.0*0.6+150, 0.0);
    glVertex3f (133.0*0.6+230,354.0*0.6+150, 0.0);
    glVertex3f (135.0*0.6+230,356.0*0.6+150, 0.0);
    glVertex3f (137.0*0.6+230,358.0*0.6+150, 0.0);
    glEnd();

      glColor3f (1.0, 1.0, 1.0);//star2
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.6+30, 360.0*0.6+150, 0.0);
    glVertex3f (133.0*0.6+30,362.0*0.6+150, 0.0);
    glVertex3f (131.0*0.6+30, 360.0*0.6+150, 0.0);
    glVertex3f (129.0*0.6+30,358.0*0.6+150, 0.0);
    glVertex3f (131.0*0.6+30,356.0*0.6+150, 0.0);
    glVertex3f (133.0*0.6+30,354.0*0.6+150, 0.0);
    glVertex3f (135.0*0.6+30,356.0*0.6+150, 0.0);
    glVertex3f (137.0*0.6+30,358.0*0.6+150, 0.0);
    glEnd();

      glColor3f (1.0, 1.0, 1.0);//star2
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.6-30, 360.0*0.6+150, 0.0);
    glVertex3f (133.0*0.6-30,362.0*0.6+150, 0.0);
    glVertex3f (131.0*0.6-30, 360.0*0.6+150, 0.0);
    glVertex3f (129.0*0.6-30,358.0*0.6+150, 0.0);
    glVertex3f (131.0*0.6-30,356.0*0.6+150, 0.0);
    glVertex3f (133.0*0.6-30,354.0*0.6+150, 0.0);
    glVertex3f (135.0*0.6-30,356.0*0.6+150, 0.0);
    glVertex3f (137.0*0.6-30,358.0*0.6+150, 0.0);
    glEnd();

      glColor3f (1.0, 1.0, 1.0);//star2
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.6-30, 360.0*0.6+250, 0.0);
    glVertex3f (133.0*0.6-30,362.0*0.6+250, 0.0);
    glVertex3f (131.0*0.6-30, 360.0*0.6+250, 0.0);
    glVertex3f (129.0*0.6-30,358.0*0.6+250, 0.0);
    glVertex3f (131.0*0.6-30,356.0*0.6+250, 0.0);
    glVertex3f (133.0*0.6-30,354.0*0.6+250, 0.0);
    glVertex3f (135.0*0.6-30,356.0*0.6+250, 0.0);
    glVertex3f (137.0*0.6-30,358.0*0.6+250, 0.0);
    glEnd();

      glColor3f (1.0, 1.0, 1.0);//star2
    glBegin(GL_POLYGON);

    glVertex3f (135.0*0.6-50, 360.0*0.6+350, 0.0);
    glVertex3f (133.0*0.6-50,362.0*0.6+350, 0.0);
    glVertex3f (131.0*0.6-50, 360.0*0.6+350, 0.0);
    glVertex3f (129.0*0.6-50,358.0*0.6+350, 0.0);
    glVertex3f (131.0*0.6-50,356.0*0.6+350, 0.0);
    glVertex3f (133.0*0.6-50,354.0*0.6+350, 0.0);
    glVertex3f (135.0*0.6-50,356.0*0.6+350, 0.0);
    glVertex3f (137.0*0.6-50,358.0*0.6+350, 0.0);
    glEnd();






    }


    else if(n==0)
    {
    glColor3f(0.529, 0.808, 0.922);//sky
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3f (0,100,0);
    glVertex3f (500,100,0);
    glVertex3f (500,600,0);
    glVertex3f (0,600,0);
    glEnd();
    glPopMatrix();
    sun();
    birds2();
    }

}

void tree1()
{
    glColor3f(0.502, 0.000, 0.000);//tree1
    glBegin(GL_TRIANGLES);
    glVertex3f (68,120,0);
    glVertex3f (82,120,0);
    glVertex3f (75,220,0);
    glEnd();

    glColor3f(0.133, 0.545, 0.13);//tree leaf
    glPushMatrix();
    circle(15,20,60,200);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//tree leaf
    glPushMatrix();
    circle(15,20,90,200);
    glPopMatrix();

     glColor3f(0.133, 0.545, 0.13);//tree leaf
    glPushMatrix();
    circle(15,20,75,220);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//tree leaf
    glPushMatrix();
    circle(15,20,75,195);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//tree leaf
    glPushMatrix();
    circle(10,15,63,217);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//tree leaf
    glPushMatrix();
    circle(10,15,87,217);
    glPopMatrix();


    glColor3f(0.502, 0.000, 0.000);//tree2
    glBegin(GL_TRIANGLES);
    glVertex3f (68*0.7+420,120,0);
    glVertex3f (82*0.7+420,120,0);
    glVertex3f (75*0.7+420,200,0);
    glEnd();

    glColor3f(0.133, 0.545, 0.13);//tree leaf
    glPushMatrix();
    circle(10,15,60*0.7+420,200-30);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//tree leaf
    glPushMatrix();
    circle(10,15,90*0.7+420,200-30);
    glPopMatrix();

     glColor3f(0.133, 0.545, 0.13);//tree leaf
    glPushMatrix();
    circle(10,15,75*0.7+420,220-30);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//tree leaf
    glPushMatrix();
    circle(10,15,75*0.7+420,195-30);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//tree leaf
    glPushMatrix();
    circle(7,12,63*0.7+420,217-30);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//tree leaf
    glPushMatrix();
    circle(7,12,87*0.7+420,217-30);
    glPopMatrix();


    glColor3f(0.502, 0.000, 0.000);//tree2
    glBegin(GL_TRIANGLES);
    glVertex3f (420,120,0);
    glVertex3f (430,120,0);
    glVertex3f (425,190,0);
    glEnd();

    glColor3f(0.133, 0.545, 0.13);//tree leaf

    glPushMatrix();
    circle(7,10,60*0.3+400,200-30);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//tree leaf

    glPushMatrix();
    circle(7,10,90*0.3+405,200-30);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//tree leaf
    glPushMatrix();
    circle(7,10,90*0.3+402,200-18);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//tree leaf
    glPushMatrix();
    circle(7,12,90*0.3+394,200-18);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//tree leaf
    glPushMatrix();
    circle(5,8,90*0.3+398,200-35);
    glPopMatrix();


    glColor3f(0.502, 0.000, 0.000);//tree2
    glBegin(GL_TRIANGLES);
    glVertex3f (420-400,120,0);
    glVertex3f (430-400,120,0);
    glVertex3f (425-400,190,0);
    glEnd();

    glColor3f(0.133, 0.545, 0.13);//tree leaf

    glPushMatrix();
    circle(9,13,60*0.3+400-402,200-30);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//tree leaf

    glPushMatrix();
    circle(9,13,90*0.3+407-400,200-30);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//tree leaf

    glPushMatrix();
    circle(9,13,90*0.3+402-400,200-18);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//tree leaf

    glPushMatrix();
    circle(9,13,90*0.3+394-400,200-18);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//tree leaf
    glPushMatrix();
    circle(5,8,90*0.3+398-400,200-35);
    glPopMatrix();





}
void back_grass()
{
    glColor3f(0.133, 0.545, 0.13);//grass
    glPushMatrix();
    circle(35,38,0,80);
    glPopMatrix();

    glColor3f(0.000, 0.502, 0.000);//grass
    glPushMatrix();
    circle(35,38,40,90);
    glPopMatrix();

    glColor3f(0.000, 0.502, 0.000);//grass
    glPushMatrix();
    circle(35,38,80,100);
    glPopMatrix();


    glColor3f(0.133, 0.545, 0.13);//grass
    glPushMatrix();
    circle(35,38,500,80);
    glPopMatrix();

    glColor3f(0.000, 0.502, 0.000);//grass
    glPushMatrix();
    circle(35,38,460,90);
    glPopMatrix();

    glColor3f(0.000, 0.502, 0.000);//grass
    glPushMatrix();
    circle(35,38,420,100);
    glPopMatrix();


}


void memorial()
{
   glColor3f(0.827, 0.827, 0.827);//7th
    glBegin(GL_TRIANGLES);
    glVertex3f (40,100,0);
    glVertex3f (460,100,0);
    glVertex3f (250,240,0);
    glEnd();

    glColor3f(0.663, 0.663, 0.663);//6th shadow
    glBegin(GL_TRIANGLES);
    glVertex3f (64,100,0);
    glVertex3f (436,100,0);
    glVertex3f (250,265,0);
    glEnd();

    glColor3f(0.827, 0.827, 0.827);//6th
    glBegin(GL_TRIANGLES);
    glVertex3f (70,100,0);
    glVertex3f (430,100,0);
    glVertex3f (250,270,0);
    glEnd();

    glColor3f(0.663, 0.663, 0.663);//5th shadow
    glBegin(GL_TRIANGLES);
    glVertex3f (94,100,0);
    glVertex3f (406,100,0);
    glVertex3f (250,295,0);
    glEnd();

    glColor3f(0.827, 0.827, 0.827);//5th
    glBegin(GL_TRIANGLES);
    glVertex3f (100,100,0);
    glVertex3f (400,100,0);
    glVertex3f (250,300,0);
    glEnd();

    glColor3f(0.663, 0.663, 0.663);//4th shadow
    glBegin(GL_TRIANGLES);
    glVertex3f (124,100,0);
    glVertex3f (376,100,0);
    glVertex3f (250,325,0);
    glEnd();

    glColor3f(0.827, 0.827, 0.827);//4th
    glBegin(GL_TRIANGLES);
    glVertex3f (130,100,0);
    glVertex3f (370,100,0);
    glVertex3f (250,330,0);
    glEnd();

    glColor3f(0.663, 0.663, 0.663);//3rd shadow
    glBegin(GL_TRIANGLES);
    glVertex3f (154,100,0);
    glVertex3f (346,100,0);
    glVertex3f (250,355,0);
    glEnd();

    glColor3f(0.827, 0.827, 0.827);//3rd
    glBegin(GL_TRIANGLES);
    glVertex3f (160,100,0);
    glVertex3f (340,100,0);
    glVertex3f (250,360,0);
    glEnd();

    glColor3f(0.663, 0.663, 0.663);//2nd shadow
    glBegin(GL_TRIANGLES);
    glVertex3f (184,100,0);
    glVertex3f (316,100,0);
    glVertex3f (250,385,0);
    glEnd();

    glColor3f(0.827, 0.827, 0.827);//2nd
    glBegin(GL_TRIANGLES);
    glVertex3f (190,100,0);
    glVertex3f (310,100,0);
    glVertex3f (250,390,0);
    glEnd();

    glColor3f(0.663, 0.663, 0.663);//1st shadow
    glBegin(GL_TRIANGLES);
    glVertex3f (214,100,0);
    glVertex3f (286,100,0);
    glVertex3f (250,425,0);
    glEnd();

    glColor3f(0.827, 0.827, 0.827);//1st
    glBegin(GL_TRIANGLES);
    glVertex3f (220,100,0);
    glVertex3f (280,100,0);
    glVertex3f (250,440,0);
    glEnd();



    glColor3f(0.663, 0.663, 0.663);//triangle1
    glBegin(GL_TRIANGLES);
    glVertex3f (236,216,0);
    glVertex3f (264,216,0);
    glVertex3f (250,260,0);
    glEnd();

    glColor3f(0.827, 0.827, 0.827);//triangle1
    glBegin(GL_TRIANGLES);
    glVertex3f (240,220,0);
    glVertex3f (260,220,0);
    glVertex3f (250,250,0);
    glEnd();

    glColor3f(0.663, 0.663, 0.663);//triangle2
    glBegin(GL_TRIANGLES);
    glVertex3f (236,204,0);
    glVertex3f (264,204,0);
    glVertex3f (250,160,0);
    glEnd();

    glColor3f(0.827, 0.827, 0.827);//triangle2
    glBegin(GL_TRIANGLES);
    glVertex3f (240,200,0);
    glVertex3f (260,200,0);
    glVertex3f (250,170,0);
    glEnd();
}
void flag(){



    glColor3f(0.502, 0.000, 0.000);//flag stick
    glBegin(GL_QUADS);
    glVertex3f (380,100,0);
    glVertex3f (382,100,0);
    glVertex3f (382,350,0);
    glVertex3f (380,350,0);
    glEnd();

    glColor3f(0.133, 0.545, 0.13);//flag quads
    glBegin(GL_QUADS);
    glVertex3f (380,350,0);
    glVertex3f (330,350,0);
    glVertex3f (315,280,0);
    glVertex3f (380,280,0);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);//flag circle
    glPushMatrix();
    circle(15,18,355,315);
    glPopMatrix();


}

void front_yeard(void)
{
    if(l==1)
    {
    glColor3f(0.647f, 0.165f, 0.165f);//brick
    glBegin(GL_QUADS);
    glVertex3f (0,100,0);
    glVertex3f (500,100,0);
    glVertex3f (500,80,0);
    glVertex3f (0,80,0);
    glEnd();

    glColor3f(1.000, 0.843, 0.000);//light1
    glBegin(GL_QUADS);
    glVertex3f (30,95,0);
    glVertex3f (50,95,0);
    glVertex3f (50,85,0);
    glVertex3f (30,85,0);
    glEnd();

     glColor3f(1.000, 0.843, 0.000);//light2
    glBegin(GL_QUADS);
    glVertex3f (30+100,95,0);
    glVertex3f (50+100,95,0);
    glVertex3f (50+100,85,0);
    glVertex3f (30+100,85,0);
    glEnd();


     glColor3f(1.000, 0.843, 0.000);//light3
    glBegin(GL_QUADS);
    glVertex3f (30+200,95,0);
    glVertex3f (50+200,95,0);
    glVertex3f (50+200,85,0);
    glVertex3f (30+200,85,0);
    glEnd();


     glColor3f(1.000, 0.843, 0.000);//light4
    glBegin(GL_QUADS);
    glVertex3f (30+300,95,0);
    glVertex3f (50+300,95,0);
    glVertex3f (50+300,85,0);
    glVertex3f (30+300,85,0);
    glEnd();

    glColor3f(1.000, 0.843, 0.000);//light5
    glBegin(GL_QUADS);
    glVertex3f (30+400,95,0);
    glVertex3f (50+400,95,0);
    glVertex3f (50+400,85,0);
    glVertex3f (30+400,85,0);
    glEnd();






    glColor3f(0.804f, 0.522f, 0.247f);//field
    glBegin(GL_QUADS);
    glVertex3f (0,80,0);
    glVertex3f (500,80,0);
    glVertex3f (500,0,0);
    glVertex3f (0,0,0);
    glEnd();

    glColor3f(0.647f, 0.165f, 0.165f);//pond brick
    glBegin(GL_QUADS);
    glVertex3f (220,80,0);
    glVertex3f (215,80,0);
    glVertex3f (190,0,0);
    glVertex3f (200,0,0);
    glEnd();

    glColor3f(1.000, 0.843, 0.000);//light5
    circle(2,3,215,70);
    circle(3,4,210,50);
    circle(4,5,205,30);
    circle(5,5,200,10);





    glColor3f(0.647f, 0.165f, 0.165f);//pond brick
    glBegin(GL_QUADS);
    glVertex3f (280,80,0);
    glVertex3f (285,80,0);
    glVertex3f (310,0,0);
    glVertex3f (300,0,0);
    glEnd();

    glColor3f(1.000, 0.843, 0.000);//light5
    circle(2,3,285,70);
    circle(3,4,290,50);
    circle(4,5,295,30);
    circle(5,5,300,10);


    glColor3f(0.118, 0.565, 1.000);//water
    glBegin(GL_QUADS);
    glVertex3f (220,80,0);
    glVertex3f (280,80,0);
    glVertex3f (300,0,0);
    glVertex3f (200,0,0);
    glEnd();

    ///new

    glColor3f(0.4f, 0.165f, 0.165f);//light5
    glBegin(GL_QUADS);
    glVertex3f (140,65,0);
    glVertex3f (145,65,0);
    glVertex3f (145,15,0);
    glVertex3f (140,15,0);
    glEnd();
    glColor3f(0.4f, 0.165f, 0.165f);//light5
    glBegin(GL_QUADS);
    glVertex3f (80,65,0);
    glVertex3f (85,65,0);
    glVertex3f (85,15,0);
    glVertex3f (80,15,0);
    glEnd();
    glColor3f(0.4f, 0.165f, 0.165f);//light5
    glBegin(GL_QUADS);
    glVertex3f (20,65,0);
    glVertex3f (25,65,0);
    glVertex3f (25,15,0);
    glVertex3f (20,15,0);
    glEnd();
    glColor3f(1.000, 0.843, 0.000);//light5
    circle(12,15,143,63);
    circle(12,15,83,63);
    circle(12,15,23,63);




     glColor3f(0.4f, 0.165f, 0.165f);//light5
    glBegin(GL_QUADS);
    glVertex3f (340,65,0);
    glVertex3f (345,65,0);
    glVertex3f (345,15,0);
    glVertex3f (340,15,0);
    glEnd();
    glColor3f(0.4f, 0.165f, 0.165f);//light5
    glBegin(GL_QUADS);
    glVertex3f (400,65,0);
    glVertex3f (405,65,0);
    glVertex3f (405,15,0);
    glVertex3f (400,15,0);
    glEnd();
    glColor3f(0.4f, 0.165f, 0.165f);//light5
    glBegin(GL_QUADS);
    glVertex3f (460,65,0);
    glVertex3f (465,65,0);
    glVertex3f (465,15,0);
    glVertex3f (460,15,0);
    glEnd();
    glColor3f(1.000, 0.843, 0.000);//light5
    circle(12,15,343,63);
    circle(12,15,403,63);
    circle(12,15,463,63);
    ///new





    }
    else if(l==0)
    {
    glColor3f(0.647f, 0.165f, 0.165f);//brick
    glBegin(GL_QUADS);
    glVertex3f (0,100,0);
    glVertex3f (500,100,0);
    glVertex3f (500,80,0);
    glVertex3f (0,80,0);
    glEnd();

    glColor3f(0.412, 0.412, 0.412);//light1
    glBegin(GL_QUADS);
    glVertex3f (30,95,0);
    glVertex3f (50,95,0);
    glVertex3f (50,85,0);
    glVertex3f (30,85,0);
    glEnd();

     glColor3f(0.412, 0.412, 0.412);//light2
    glBegin(GL_QUADS);
    glVertex3f (30+100,95,0);
    glVertex3f (50+100,95,0);
    glVertex3f (50+100,85,0);
    glVertex3f (30+100,85,0);
    glEnd();


     glColor3f(0.412, 0.412, 0.412);//light3
    glBegin(GL_QUADS);
    glVertex3f (30+200,95,0);
    glVertex3f (50+200,95,0);
    glVertex3f (50+200,85,0);
    glVertex3f (30+200,85,0);
    glEnd();


     glColor3f(0.412, 0.412, 0.412);//light4
    glBegin(GL_QUADS);
    glVertex3f (30+300,95,0);
    glVertex3f (50+300,95,0);
    glVertex3f (50+300,85,0);
    glVertex3f (30+300,85,0);
    glEnd();

    glColor3f(0.412, 0.412, 0.412);//light5
    glBegin(GL_QUADS);
    glVertex3f (30+400,95,0);
    glVertex3f (50+400,95,0);
    glVertex3f (50+400,85,0);
    glVertex3f (30+400,85,0);
    glEnd();






    glColor3f(0.804f, 0.522f, 0.247f);//field
    glBegin(GL_QUADS);
    glVertex3f (0,80,0);
    glVertex3f (500,80,0);
    glVertex3f (500,0,0);
    glVertex3f (0,0,0);
    glEnd();

    glColor3f(0.647f, 0.165f, 0.165f);//pond brick
    glBegin(GL_QUADS);
    glVertex3f (220,80,0);
    glVertex3f (215,80,0);
    glVertex3f (190,0,0);
    glVertex3f (200,0,0);
    glEnd();

    glColor3f(0.412, 0.412, 0.412);//light5
    circle(2,3,215,70);
    circle(3,4,210,50);
    circle(4,5,205,30);
    circle(5,5,200,10);


    glColor3f(0.647f, 0.165f, 0.165f);//pond brick
    glBegin(GL_QUADS);
    glVertex3f (280,80,0);
    glVertex3f (285,80,0);
    glVertex3f (310,0,0);
    glVertex3f (300,0,0);
    glEnd();

    glColor3f(0.412, 0.412, 0.412);//light5
    circle(2,3,285,70);
    circle(3,4,290,50);
    circle(4,5,295,30);
    circle(5,5,300,10);
///new

    glColor3f(0.4f, 0.165f, 0.165f);//light5
    glBegin(GL_QUADS);
    glVertex3f (140,65,0);
    glVertex3f (145,65,0);
    glVertex3f (145,15,0);
    glVertex3f (140,15,0);
    glEnd();
    glColor3f(0.4f, 0.165f, 0.165f);//light5
    glBegin(GL_QUADS);
    glVertex3f (80,65,0);
    glVertex3f (85,65,0);
    glVertex3f (85,15,0);
    glVertex3f (80,15,0);
    glEnd();
    glColor3f(0.4f, 0.165f, 0.165f);//light5
    glBegin(GL_QUADS);
    glVertex3f (20,65,0);
    glVertex3f (25,65,0);
    glVertex3f (25,15,0);
    glVertex3f (20,15,0);
    glEnd();
    glColor3f(0.412, 0.412, 0.412);//light5
    circle(12,15,143,63);
    circle(12,15,83,63);
    circle(12,15,23,63);




     glColor3f(0.4f, 0.165f, 0.165f);//light5
    glBegin(GL_QUADS);
    glVertex3f (340,65,0);
    glVertex3f (345,65,0);
    glVertex3f (345,15,0);
    glVertex3f (340,15,0);
    glEnd();
    glColor3f(0.4f, 0.165f, 0.165f);//light5
    glBegin(GL_QUADS);
    glVertex3f (400,65,0);
    glVertex3f (405,65,0);
    glVertex3f (405,15,0);
    glVertex3f (400,15,0);
    glEnd();
    glColor3f(0.4f, 0.165f, 0.165f);//light5
    glBegin(GL_QUADS);
    glVertex3f (460,65,0);
    glVertex3f (465,65,0);
    glVertex3f (465,15,0);
    glVertex3f (460,15,0);
    glEnd();
    glColor3f(0.412, 0.412, 0.412);//light5
    circle(12,15,343,63);
    circle(12,15,403,63);
    circle(12,15,463,63);
    ///new





    glColor3f(0.118, 0.565, 1.000);//water
    glBegin(GL_QUADS);
    glVertex3f (220,80,0);
    glVertex3f (280,80,0);
    glVertex3f (300,0,0);
    glVertex3f (200,0,0);
    glEnd();
    }


}
void front_grass()
{

    glColor3f(0.133, 0.545, 0.13);//grass
    glPushMatrix();
    circle(35,38,40,0);
    glPopMatrix();

    glColor3f(0.000, 0.502, 0.000);//grass
    glPushMatrix();
    circle(35,38,10,0);
    glPopMatrix();


    glColor3f(0.000, 0.502, 0.000);//grass
    glPushMatrix();
    circle(35,38,80,0);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//grass
    glPushMatrix();
    circle(35,38,120,0);
    glPopMatrix();

    glColor3f(0.000, 0.502, 0.000);//grass
    glPushMatrix();
    circle(35,38,80,0);
    glPopMatrix();

    glColor3f(0.000, 0.502, 0.000);//grass
    glPushMatrix();
    circle(35,38,150,0);
    glPopMatrix();



    glColor3f(0.133, 0.545, 0.13);//grass
    glPushMatrix();
    circle(35,38,380,0);
    glPopMatrix();

     glColor3f(0.000, 0.502, 0.000);//grass
    glPushMatrix();
    circle(35,38,350,0);
    glPopMatrix();

    glColor3f(0.133, 0.545, 0.13);//grass
    glPushMatrix();
    circle(35,38,460,0);
    glPopMatrix();

    glColor3f(0.000, 0.502, 0.000);//grass
    glPushMatrix();
    circle(35,38,420,0);
    glPopMatrix();

    glColor3f(0.000, 0.502, 0.000);//grass
    glPushMatrix();
    circle(35,38,490,0);
    glPopMatrix();


}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    skyblue();
    tree1();
    back_grass();

    sky2();
    memorial();
    flag();
    front_yeard();
    front_grass();

    sky2();

    glFlush();


}




void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 'n':
	    case 'N':
				if(n==0)
				  n=1;

	break;
	    case 'd':
	    case 'D':
				if(n==1)
				  n=0;

	break;
	    case 'l':
	    case 'L':
				if(l==0)
				  l=1;

	break;
	    case 'o':
	    case 'O':
				if(l==1)
				  l=0;

	break;
	}
}

int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(850, 700);
    glutInitWindowPosition(500, 15);
    glutCreateWindow("National Martyr's Memorial");

    init();
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(my_keyboard);
    ///PlaySound("Ami Banglar Gaan Gai.wav", NULL, SND_ASYNC|SND_FILENAME);

	printf("Enter N or n for Night's View..\n");
	printf("Enter D or d for Day's View..\n");
	printf("Enter L or l for ON Light..\n");
	printf("Enter O or o for OFF Light..\n");




    glutMainLoop();
    return 0;
}

