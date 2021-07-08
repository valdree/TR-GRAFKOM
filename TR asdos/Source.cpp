#include <windows.h>
#include <GL/glut.h>







// Valdy Reado Silaen - 672019010 
// Zefanya Loudewieq Gabriel Lala - 672019100
// Rezky Agung Kurniawan Ta'ewa - 672019295

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void Init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
}

void Display(void) {


    int i, j;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    //Alas Besar
    glBegin(GL_QUADS);
    glColor3ub(50, 205, 50);
    glVertex3i(-120, 0, 120);
    glVertex3i(120, 0, 120);
    glVertex3i(120, 0, -120);
    glVertex3i(-120, 0, -120);
    glEnd();

    //Alas
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3f(-12, 0.1, 12);
    glVertex3f(12, 0.1, 12);
    glVertex3f(12, 0.1, -12);
    glVertex3f(-12, 0.1, -12);
    glEnd();

    //Atap 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-12, 40, 12);
    glVertex3i(12, 40, 12);
    glVertex3i(12, 40, -12);
    glVertex3i(-12, 40, -12);
    glEnd();

    //Tembok 1
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(12, 40, -12);
    glVertex3i(12, 40, 12);
    glVertex3i(12, 0, 12);
    glVertex3i(12, 0, -12);
    glEnd();
    //Jendela 1
    glColor3f(0.25, 0.26, 0.33);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(0, 0, -1.5 * j); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(0, -4 * i, -1);//Vertical
            glBegin(GL_POLYGON);
            glVertex3f(12.1, 37, 10);
            glVertex3f(12.1, 37, 9);
            glVertex3f(12.1, 34, 9);
            glVertex3f(12.1, 34, 10);
            glEnd();

            glPopMatrix();
        }

        glPopMatrix();

    }
    //Bingkai Jendela
    glColor3f(0, 0, 0);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(0, 0, -1.5 * j); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(0, -4 * i, -1); //Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(12.1, 37, 10);
            glVertex3f(12.1, 37, 9);
            glVertex3f(12.1, 34, 9);
            glVertex3f(12.1, 34, 10);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(12.1, 37, 9.5);
            glVertex3f(12.1, 34, 9.5);
            glVertex3f(12.1, 36, 9);
            glVertex3f(12.1, 36, 10);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Tembok 2
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-12, 40, -12);
    glVertex3i(12, 40, -12);
    glVertex3i(12, 0, -12);
    glVertex3i(-12, 0, -12);
    glEnd();
    //Jendela 2
    glColor3f(0.25, 0.26, 0.33);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(-1, -4 * i, 0); //Vertical
            glBegin(GL_POLYGON);
            glVertex3f(10, 37, -12.1);
            glVertex3f(9, 37, -12.1);
            glVertex3f(9, 34, -12.1);
            glVertex3f(10, 34, -12.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela
    glColor3f(0, 0, 0);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(-1, -4 * i, 0); //Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(10, 37, -12.1);
            glVertex3f(9, 37, -12.1);
            glVertex3f(9, 34, -12.1);
            glVertex3f(10, 34, -12.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(9.5, 37, -12.1);
            glVertex3f(9.5, 34, -12.1);
            glVertex3f(10, 36, -12.1);
            glVertex3f(9, 36, -12.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Tembok 3
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(12, 40, 12);
    glVertex3i(-12, 40, 12);
    glVertex3i(-12, 0, 12);
    glVertex3i(12, 0, 12);
    glEnd();
    //Jendela 3
    glColor3f(0.25, 0.26, 0.33);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(18, -4 * i, 0); //Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-10, 37, 12.1);
            glVertex3f(-9, 37, 12.1);
            glVertex3f(-9, 34, 12.1);
            glVertex3f(-10, 34, 12.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela
    glColor3f(0, 0, 0);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-1.5 * j, 0, 0); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(18, -4 * i, 0); //Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-10, 37, 12.1);
            glVertex3f(-9, 37, 12.1);
            glVertex3f(-9, 34, 12.1);
            glVertex3f(-10, 34, 12.1);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-9.5, 37, 12.1);
            glVertex3f(-9.5, 34, 12.1);
            glVertex3f(-10, 36, 12.1);
            glVertex3f(-9, 36, 12.1);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }

    //Tembok 4
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-12, 40, 12);
    glVertex3i(-12, 40, -12);
    glVertex3i(-12, 0, -12);
    glVertex3i(-12, 0, 12);
    glEnd();
    //Jendela 4
    glColor3f(0.25, 0.26, 0.33);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-18, 0, -1.5 * j); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glTranslatef(18, -4 * i, 18); //Vertical
            glBegin(GL_POLYGON);
            glVertex3f(-12.1, 37, -10);
            glVertex3f(-12.1, 37, -9);
            glVertex3f(-12.1, 34, -9);
            glVertex3f(-12.1, 34, -10);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Bingkai Jendela
    glColor3f(0, 0, 0);
    for (j = 0; j < 12; j++) {
        glPushMatrix();
        glTranslatef(-18, 0, -1.5 * j); //Horizontal
        for (i = 0; i < 6; i++) {
            glPushMatrix();
            glLineWidth(2);
            glTranslatef(18, -4 * i, 18); //Vertical
            glBegin(GL_LINE_LOOP);
            glVertex3f(-12.1, 37, -10);
            glVertex3f(-12.1, 37, -9);
            glVertex3f(-12.1, 34, -9);
            glVertex3f(-12.1, 34, -10);
            glEnd();
            glBegin(GL_LINES);
            glVertex3f(-12.1, 37, -9.5);
            glVertex3f(-12.1, 34, -9.5);
            glVertex3f(-12.1, 36, -10);
            glVertex3f(-12.1, 36, -9);
            glEnd();
            glPopMatrix();
        }
        glPopMatrix();
    }
    //Pojokan
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 35, -10);
    glVertex3i(-10, 35, -10);
    glVertex3i(-10, 35, -14);
    glVertex3i(-14, 35, -14);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-14, 35, -10);
    glVertex3i(-10, 35, -10);
    glVertex3i(-10, 0, -10);
    glVertex3i(-14, 0, -10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-10, 35, -10);
    glVertex3i(-10, 35, -14);
    glVertex3i(-10, 0, -14);
    glVertex3i(-10, 0, -10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-10, 35, -14);
    glVertex3i(-14, 35, -14);
    glVertex3i(-14, 0, -14);
    glVertex3i(-10, 0, -14);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-14, 35, -14);
    glVertex3i(-14, 35, -10);
    glVertex3i(-14, 0, -10);
    glVertex3i(-14, 0, -14);
    glEnd();
    //Garis Tembok
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 0, -12);
    glVertex3i(-10, 35, -12);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 0, -14);
    glVertex3i(-10, 35, -14);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-14, 0, -14);
    glVertex3i(-14, 35, -14);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-14, 0, -10);
    glVertex3i(-14, 35, -10);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-12, 0, -10);
    glVertex3i(-12, 35, -10);
    glEnd();

    //Pojokan
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 35, -10);
    glVertex3i(14, 35, -10);
    glVertex3i(14, 35, -14);
    glVertex3i(10, 35, -14);
    glEnd();
    // glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(10, 35, -10);
    glVertex3i(14, 35, -10);
    glVertex3i(14, 0, -10);
    glVertex3i(10, 0, -10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(14, 35, -10);
    glVertex3i(14, 35, -14);
    glVertex3i(14, 0, -14);
    glVertex3i(14, 0, -10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(14, 35, -14);
    glVertex3i(10, 35, -14);
    glVertex3i(10, 0, -14);
    glVertex3i(14, 0, -14);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(10, 35, -14);
    glVertex3i(10, 35, -10);
    glVertex3i(10, 0, -10);
    glVertex3i(10, 0, -14);
    glEnd();
    //Garis Tembok
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(10, 0, -12);
    glVertex3i(10, 35, -12);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(10, 0, -14);
    glVertex3i(10, 35, -14);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(14, 0, -14);
    glVertex3i(14, 35, -14);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(14, 0, -10);
    glVertex3i(14, 35, -10);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(12, 0, -10);
    glVertex3i(12, 35, -10);
    glEnd();

    //Pojokan
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 35, 14);
    glVertex3i(14, 35, 14);
    glVertex3i(14, 35, 10);
    glVertex3i(10, 35, 10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(10, 35, 14);
    glVertex3i(14, 35, 14);
    glVertex3i(14, 0, 14);
    glVertex3i(10, 0, 14);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(14, 35, 14);
    glVertex3i(14, 35, 10);
    glVertex3i(14, 0, 10);
    glVertex3i(14, 0, 14);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(14, 35, 10);
    glVertex3i(10, 35, 10);
    glVertex3i(10, 0, 10);
    glVertex3i(14, 0, 10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(10, 35, 10);
    glVertex3i(10, 35, 14);
    glVertex3i(10, 0, 14);
    glVertex3i(10, 0, 10);
    glEnd();
    //Garis Tembok
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(10, 0, 12);
    glVertex3i(10, 35, 12);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(10, 0, 14);
    glVertex3i(10, 35, 14);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(14, 0, 14);
    glVertex3i(14, 35, 14);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(14, 0, 10);
    glVertex3i(14, 35, 10);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(12, 0, 10);
    glVertex3i(12, 35, 10);
    glEnd();

    //Pojokan
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 35, 14);
    glVertex3i(-10, 35, 14);
    glVertex3i(-10, 35, 10);
    glVertex3i(-14, 35, 10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-14, 35, 14);
    glVertex3i(-10, 35, 14);
    glVertex3i(-10, 0, 14);
    glVertex3i(-14, 0, 14);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-10, 35, 14);
    glVertex3i(-10, 35, 10);
    glVertex3i(-10, 0, 10);
    glVertex3i(-10, 0, 14);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-10, 35, 10);
    glVertex3i(-14, 35, 10);
    glVertex3i(-14, 0, 10);
    glVertex3i(-10, 0, 10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 224);
    glVertex3i(-14, 35, 10);
    glVertex3i(-14, 35, 14);
    glVertex3i(-14, 0, 14);
    glVertex3i(-14, 0, 10);
    glEnd();
    //Garis Tembok
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 0, 12);
    glVertex3i(-10, 35, 12);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 0, 14);
    glVertex3i(-10, 35, 14);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-14, 0, 14);
    glVertex3i(-14, 35, 14);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-14, 0, 10);
    glVertex3i(-14, 35, 10);
    glEnd();
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-12, 0, 10);
    glVertex3i(-12, 35, 10);
    glEnd();

    //Garis Atap
    glBegin(GL_LINES);
    glLineWidth(100.0);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 40, 12); glVertex3i(10, 40, 12);
    glVertex3i(10, 40, 12); glVertex3i(10, 40, 14);
    glVertex3i(10, 40, 14); glVertex3i(14, 40, 14);
    glVertex3i(14, 40, 14); glVertex3i(14, 40, 10);
    glVertex3i(14, 40, 10); glVertex3i(12, 40, 10);
    glVertex3i(12, 40, 10); glVertex3i(12, 40, -10);
    glVertex3i(12, 40, -10); glVertex3i(14, 40, -10);
    glVertex3i(14, 40, -10); glVertex3i(14, 40, -14);
    glVertex3i(14, 40, -14); glVertex3i(10, 40, -14);
    glVertex3i(10, 40, -14); glVertex3i(10, 40, -12);
    glVertex3i(10, 40, -12); glVertex3i(-10, 40, -12);
    glVertex3i(-10, 40, -12); glVertex3i(-10, 40, -14);
    glVertex3i(-10, 40, -14); glVertex3i(-14, 40, -14);
    glVertex3i(-14, 40, -14); glVertex3i(-14, 40, -10);
    glVertex3i(-14, 40, -10); glVertex3i(-12, 40, -10);
    glVertex3i(-12, 40, -10); glVertex3i(-12, 40, 10);
    glVertex3i(-12, 40, 10); glVertex3i(-14, 40, 10);
    glVertex3i(-14, 40, 10); glVertex3i(-14, 40, 14);
    glVertex3i(-14, 40, 14); glVertex3i(-10, 40, 14);
    glVertex3i(-10, 40, 14); glVertex3i(-10, 40, 12);
    glEnd();





    //Atap 2

    //Tembok 1
    glBegin(GL_TRIANGLES);
    glColor3ub(102, 17, 0);

    glVertex3i(0, 60, 0);
    glVertex3i(14, 40, -14);
    glVertex3i(-14, 40, -14);
    glEnd();
    //Tembok 2
    glBegin(GL_TRIANGLES);
    glColor3ub(102, 17, 0);

    glVertex3i(0, 60, 0);
    glVertex3i(14, 40, 14);
    glVertex3i(14, 40, -14);
    glEnd();
    //Tembok 3
    glBegin(GL_TRIANGLES);
    glColor3ub(102, 17, 0);

    glVertex3i(0, 60, 0);
    glVertex3i(-14, 40, 14);
    glVertex3i(14, 40, 14);
    glEnd();
    //Tembok 4
    glBegin(GL_TRIANGLES);
    glColor3ub(102, 17, 0);

    glVertex3i(0, 60, 0);
    glVertex3i(-14, 40, -14);
    glVertex3i(-14, 40, 14);
    glEnd();

    //Pojokan atas 1


    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 35, -14);
    glVertex3i(14, 35, -14);
    glVertex3i(16, 33, -16);
    glVertex3i(8, 33, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 35, -14);
    glVertex3i(14, 35, -10);
    glVertex3i(16, 33, -8);
    glVertex3i(8, 33, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 35, -14);
    glVertex3i(14, 35, -14);
    glVertex3i(16, 33, -16);
    glVertex3i(8, 33, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 35, -14);
    glVertex3i(14, 35, -10);
    glVertex3i(16, 33, -8);
    glVertex3i(16, 33, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 35, -12);
    glVertex3i(10, 35, -14);
    glVertex3i(8, 33, -16);
    glVertex3i(8, 33, -12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(12, 35, -10);
    glVertex3i(14, 35, -10);
    glVertex3i(16, 33, -8);
    glVertex3i(12, 33, -8);
    glEnd();

    //jendela pojok 1

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(10.01, 33, 14.01);
    glVertex3f(14.01, 33, 14.01);
    glVertex3f(14.01, 31, 14.01);
    glVertex3f(10.01, 31, 14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(14.01, 33, 10.01);
    glVertex3f(14.01, 33, 14.01);
    glVertex3f(14.01, 31, 14.01);
    glVertex3f(14.01, 31, 10.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(10.01, 29, 14.01);
    glVertex3f(14.01, 29, 14.01);
    glVertex3f(14.01, 27, 14.01);
    glVertex3f(10.01, 27, 14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(14.01, 29, 10.01);
    glVertex3f(14.01, 29, 14.01);
    glVertex3f(14.01, 27, 14.01);
    glVertex3f(14.01, 27, 10.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(10.01, 25, 14.01);
    glVertex3f(14.01, 25, 14.01);
    glVertex3f(14.01, 23, 14.01);
    glVertex3f(10.01, 23, 14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(14.01, 25, 10.01);
    glVertex3f(14.01, 25, 14.01);
    glVertex3f(14.01, 23, 14.01);
    glVertex3f(14.01, 23, 10.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(10.01, 21, 14.01);
    glVertex3f(14.01, 21, 14.01);
    glVertex3f(14.01, 19, 14.01);
    glVertex3f(10.01, 19, 14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(14.01, 21, 10.01);
    glVertex3f(14.01, 21, 14.01);
    glVertex3f(14.01, 19, 14.01);
    glVertex3f(14.01, 19, 10.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(10.01, 17, 14.01);
    glVertex3f(14.01, 17, 14.01);
    glVertex3f(14.01, 15, 14.01);
    glVertex3f(10.01, 15, 14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(14.01, 17, 10.01);
    glVertex3f(14.01, 17, 14.01);
    glVertex3f(14.01, 15, 14.01);
    glVertex3f(14.01, 15, 10.01);
    glEnd();

    // jendela pojok 2

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(10.01, 33, -14.01);
    glVertex3f(14.01, 33, -14.01);
    glVertex3f(14.01, 31, -14.01);
    glVertex3f(10.01, 31, -14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(14.01, 33, -10.01);
    glVertex3f(14.01, 33, -14.01);
    glVertex3f(14.01, 31, -14.01);
    glVertex3f(14.01, 31, -10.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(10.01, 29, -14.01);
    glVertex3f(14.01, 29, -14.01);
    glVertex3f(14.01, 27, -14.01);
    glVertex3f(10.01, 27, -14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(14.01, 29, -10.01);
    glVertex3f(14.01, 29, -14.01);
    glVertex3f(14.01, 27, -14.01);
    glVertex3f(14.01, 27, -10.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(10.01, 25, -14.01);
    glVertex3f(14.01, 25, -14.01);
    glVertex3f(14.01, 23, -14.01);
    glVertex3f(10.01, 23, -14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(14.01, 25, -10.01);
    glVertex3f(14.01, 25, -14.01);
    glVertex3f(14.01, 23, -14.01);
    glVertex3f(14.01, 23, -10.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(10.01, 21, -14.01);
    glVertex3f(14.01, 21, -14.01);
    glVertex3f(14.01, 19, -14.01);
    glVertex3f(10.01, 19, -14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(14.01, 21, -10.01);
    glVertex3f(14.01, 21, -14.01);
    glVertex3f(14.01, 19, -14.01);
    glVertex3f(14.01, 19, -10.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(10.01, 17, -14.01);
    glVertex3f(14.01, 17, -14.01);
    glVertex3f(14.01, 15, -14.01);
    glVertex3f(10.01, 15, -14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(14.01, 17, -10.01);
    glVertex3f(14.01, 17, -14.01);
    glVertex3f(14.01, 15, -14.01);
    glVertex3f(14.01, 15, -10.01);
    glEnd();

    // jendela pojok 3

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-10.01, 33, -14.01);
    glVertex3f(-14.01, 33, -14.01);
    glVertex3f(-14.01, 31, -14.01);
    glVertex3f(-10.01, 31, -14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-14.01, 33, -10.01);
    glVertex3f(-14.01, 33, -14.01);
    glVertex3f(-14.01, 31, -14.01);
    glVertex3f(-14.01, 31, -10.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-10.01, 29, -14.01);
    glVertex3f(-14.01, 29, -14.01);
    glVertex3f(-14.01, 27, -14.01);
    glVertex3f(-10.01, 27, -14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-14.01, 29, -10.01);
    glVertex3f(-14.01, 29, -14.01);
    glVertex3f(-14.01, 27, -14.01);
    glVertex3f(-14.01, 27, -10.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-10.01, 25, -14.01);
    glVertex3f(-14.01, 25, -14.01);
    glVertex3f(-14.01, 23, -14.01);
    glVertex3f(-10.01, 23, -14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-14.01, 25, -10.01);
    glVertex3f(-14.01, 25, -14.01);
    glVertex3f(-14.01, 23, -14.01);
    glVertex3f(-14.01, 23, -10.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-10.01, 21, -14.01);
    glVertex3f(-14.01, 21, -14.01);
    glVertex3f(-14.01, 19, -14.01);
    glVertex3f(-10.01, 19, -14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-14.01, 21, -10.01);
    glVertex3f(-14.01, 21, -14.01);
    glVertex3f(-14.01, 19, -14.01);
    glVertex3f(-14.01, 19, -10.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-10.01, 17, -14.01);
    glVertex3f(-14.01, 17, -14.01);
    glVertex3f(-14.01, 15, -14.01);
    glVertex3f(-10.01, 15, -14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-14.01, 17, -10.01);
    glVertex3f(-14.01, 17, -14.01);
    glVertex3f(-14.01, 15, -14.01);
    glVertex3f(-14.01, 15, -10.01);
    glEnd();

    // jendela pojok 4

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-10.01, 33, 14.01);
    glVertex3f(-14.01, 33, 14.01);
    glVertex3f(-14.01, 31, 14.01);
    glVertex3f(-10.01, 31, 14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-14.01, 33, 10.01);
    glVertex3f(-14.01, 33, 14.01);
    glVertex3f(-14.01, 31, 14.01);
    glVertex3f(-14.01, 31, 10.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-10.01, 29, 14.01);
    glVertex3f(-14.01, 29, 14.01);
    glVertex3f(-14.01, 27, 14.01);
    glVertex3f(-10.01, 27, 14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-14.01, 29, 10.01);
    glVertex3f(-14.01, 29, 14.01);
    glVertex3f(-14.01, 27, 14.01);
    glVertex3f(-14.01, 27, 10.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-10.01, 25, 14.01);
    glVertex3f(-14.01, 25, 14.01);
    glVertex3f(-14.01, 23, 14.01);
    glVertex3f(-10.01, 23, 14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-14.01, 25, 10.01);
    glVertex3f(-14.01, 25, 14.01);
    glVertex3f(-14.01, 23, 14.01);
    glVertex3f(-14.01, 23, 10.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-10.01, 21, 14.01);
    glVertex3f(-14.01, 21, 14.01);
    glVertex3f(-14.01, 19, 14.01);
    glVertex3f(-10.01, 19, 14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-14.01, 21, 10.01);
    glVertex3f(-14.01, 21, 14.01);
    glVertex3f(-14.01, 19, 14.01);
    glVertex3f(-14.01, 19, 10.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-10.01, 17, 14.01);
    glVertex3f(-14.01, 17, 14.01);
    glVertex3f(-14.01, 15, 14.01);
    glVertex3f(-10.01, 15, 14.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(80, 80, 80);
    glVertex3f(-14.01, 17, 10.01);
    glVertex3f(-14.01, 17, 14.01);
    glVertex3f(-14.01, 15, 14.01);
    glVertex3f(-14.01, 15, 10.01);
    glEnd();



    //Pojokan atas 2
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 31, -14);
    glVertex3i(14, 31, -14);
    glVertex3i(16, 29, -16);
    glVertex3i(8, 29, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 31, -14);
    glVertex3i(14, 31, -10);
    glVertex3i(16, 29, -8);
    glVertex3i(8, 29, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 31, -14);
    glVertex3i(14, 31, -14);
    glVertex3i(16, 29, -16);
    glVertex3i(8, 29, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 31, -14);
    glVertex3i(14, 31, -10);
    glVertex3i(16, 29, -8);
    glVertex3i(16, 29, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(12, 31, -10);
    glVertex3i(14, 31, -10);
    glVertex3i(16, 29, -8);
    glVertex3i(12, 29, -8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 31, -12);
    glVertex3i(10, 31, -14);
    glVertex3i(8, 29, -16);
    glVertex3i(8, 29, -12);
    glEnd();

    //Pojokan atas 3
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 27, -14);
    glVertex3i(14, 27, -14);
    glVertex3i(16, 25, -16);
    glVertex3i(8, 25, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 27, -14);
    glVertex3i(14, 27, -10);
    glVertex3i(16, 25, -8);
    glVertex3i(8, 25, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 27, -14);
    glVertex3i(14, 27, -14);
    glVertex3i(16, 25, -16);
    glVertex3i(8, 25, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 27, -14);
    glVertex3i(14, 27, -10);
    glVertex3i(16, 25, -8);
    glVertex3i(16, 25, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(12, 27, -10);
    glVertex3i(14, 27, -10);
    glVertex3i(16, 25, -8);
    glVertex3i(12, 25, -8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 27, -12);
    glVertex3i(10, 27, -14);
    glVertex3i(8, 25, -16);
    glVertex3i(8, 25, -12);
    glEnd();

    //Pojokan atas 4
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 23, -14);
    glVertex3i(14, 23, -14);
    glVertex3i(16, 21, -16);
    glVertex3i(8, 21, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 23, -14);
    glVertex3i(14, 23, -10);
    glVertex3i(16, 21, -8);
    glVertex3i(8, 21, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 23, -14);
    glVertex3i(14, 23, -14);
    glVertex3i(16, 21, -16);
    glVertex3i(8, 21, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 23, -14);
    glVertex3i(14, 23, -10);
    glVertex3i(16, 21, -8);
    glVertex3i(16, 21, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(12, 23, -10);
    glVertex3i(14, 23, -10);
    glVertex3i(16, 21, -8);
    glVertex3i(12, 21, -8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 23, -12);
    glVertex3i(10, 23, -14);
    glVertex3i(8, 21, -16);
    glVertex3i(8, 21, -12);
    glEnd();

    //Pojokan atas 5
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 19, -14);
    glVertex3i(14, 19, -14);
    glVertex3i(16, 17, -16);
    glVertex3i(8, 17, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 19, -14);
    glVertex3i(14, 19, -10);
    glVertex3i(16, 17, -8);
    glVertex3i(8, 17, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 19, -14);
    glVertex3i(14, 19, -14);
    glVertex3i(16, 17, -16);
    glVertex3i(8, 17, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 19, -14);
    glVertex3i(14, 19, -10);
    glVertex3i(16, 17, -8);
    glVertex3i(16, 17, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(12, 19, -10);
    glVertex3i(14, 19, -10);
    glVertex3i(16, 17, -8);
    glVertex3i(12, 17, -8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 19, -12);
    glVertex3i(10, 19, -14);
    glVertex3i(8, 17, -16);
    glVertex3i(8, 17, -12);
    glEnd();

    //Pojokan atas 6
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 15, -14);
    glVertex3i(14, 15, -14);
    glVertex3i(16, 13, -16);
    glVertex3i(8, 13, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 15, -14);
    glVertex3i(14, 15, -10);
    glVertex3i(16, 13, -8);
    glVertex3i(8, 13, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 15, -14);
    glVertex3i(14, 15, -14);
    glVertex3i(16, 13, -16);
    glVertex3i(8, 13, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 15, -14);
    glVertex3i(14, 15, -10);
    glVertex3i(16, 13, -8);
    glVertex3i(16, 13, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(12, 15, -10);
    glVertex3i(14, 15, -10);
    glVertex3i(16, 13, -8);
    glVertex3i(12, 13, -8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 15, -12);
    glVertex3i(10, 15, -14);
    glVertex3i(8, 13, -16);
    glVertex3i(8, 13, -12);
    glEnd();




    //pojokan atas 1 part2
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 35, -14);
    glVertex3i(-14, 35, -14);
    glVertex3i(-16, 33, -16);
    glVertex3i(-8, 33, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 35, -14);
    glVertex3i(-14, 35, -10);
    glVertex3i(-16, 33, -8);
    glVertex3i(-8, 33, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 35, -14);
    glVertex3i(-14, 35, -14);
    glVertex3i(-16, 33, -16);
    glVertex3i(-8, 33, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 35, -14);
    glVertex3i(-14, 35, -10);
    glVertex3i(-16, 33, -8);
    glVertex3i(-16, 33, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 35, -12);
    glVertex3i(-10, 35, -14);
    glVertex3i(-8, 33, -16);
    glVertex3i(-8, 33, -12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-12, 35, -10);
    glVertex3i(-14, 35, -10);
    glVertex3i(-16, 33, -8);
    glVertex3i(-12, 33, -8);
    glEnd();

    //Pojokan atas 2
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 31, -14);
    glVertex3i(-14, 31, -14);
    glVertex3i(-16, 29, -16);
    glVertex3i(-8, 29, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 31, -14);
    glVertex3i(-14, 31, -10);
    glVertex3i(-16, 29, -8);
    glVertex3i(-8, 29, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 31, -14);
    glVertex3i(-14, 31, -14);
    glVertex3i(-16, 29, -16);
    glVertex3i(-8, 29, -16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 31, -14);
    glVertex3i(-14, 31, -10);
    glVertex3i(-16, 29, -8);
    glVertex3i(-16, 29, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 31, -12);
    glVertex3i(-10, 31, -14);
    glVertex3i(-8, 29, -16);
    glVertex3i(-8, 29, -12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-12, 31, -10);
    glVertex3i(-14, 31, -10);
    glVertex3i(-16, 29, -8);
    glVertex3i(-12, 29, -8);
    glEnd();

    //Pojokan atas 3
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 27, -14);
    glVertex3i(-14, 27, -14);
    glVertex3i(-16, 25, -16);
    glVertex3i(-8, 25, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 27, -14);
    glVertex3i(-14, 27, -10);
    glVertex3i(-16, 25, -8);
    glVertex3i(-8, 25, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 27, -14);
    glVertex3i(-14, 27, -14);
    glVertex3i(-16, 25, -16);
    glVertex3i(-8, 25, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 27, -14);
    glVertex3i(-14, 27, -10);
    glVertex3i(-16, 25, -8);
    glVertex3i(-16, 25, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 27, -12);
    glVertex3i(-10, 27, -14);
    glVertex3i(-8, 25, -16);
    glVertex3i(-8, 25, -12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-12, 27, -10);
    glVertex3i(-14, 27, -10);
    glVertex3i(-16, 25, -8);
    glVertex3i(-12, 25, -8);
    glEnd();

    //Pojokan atas 4
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 23, -14);
    glVertex3i(-14, 23, -14);
    glVertex3i(-16, 21, -16);
    glVertex3i(-8, 21, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 23, -14);
    glVertex3i(-14, 23, -10);
    glVertex3i(-16, 21, -8);
    glVertex3i(-8, 21, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 23, -14);
    glVertex3i(-14, 23, -14);
    glVertex3i(-16, 21, -16);
    glVertex3i(-8, 21, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 23, -14);
    glVertex3i(-14, 23, -10);
    glVertex3i(-16, 21, -8);
    glVertex3i(-16, 21, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 23, -12);
    glVertex3i(-10, 23, -14);
    glVertex3i(-8, 21, -16);
    glVertex3i(-8, 21, -12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-12, 23, -10);
    glVertex3i(-14, 23, -10);
    glVertex3i(-16, 21, -8);
    glVertex3i(-12, 21, -8);
    glEnd();

    //Pojokan atas 5
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 19, -14);
    glVertex3i(-14, 19, -14);
    glVertex3i(-16, 17, -16);
    glVertex3i(-8, 17, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 19, -14);
    glVertex3i(-14, 19, -10);
    glVertex3i(-16, 17, -8);
    glVertex3i(-8, 17, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 19, -14);
    glVertex3i(-14, 19, -14);
    glVertex3i(-16, 17, -16);
    glVertex3i(-8, 17, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 19, -14);
    glVertex3i(-14, 19, -10);
    glVertex3i(-16, 17, -8);
    glVertex3i(-16, 17, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 19, -12);
    glVertex3i(-10, 19, -14);
    glVertex3i(-8, 17, -16);
    glVertex3i(-8, 17, -12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-12, 19, -10);
    glVertex3i(-14, 19, -10);
    glVertex3i(-16, 17, -8);
    glVertex3i(-12, 17, -8);
    glEnd();

    //Pojokan atas 6
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 15, -14);
    glVertex3i(-14, 15, -14);
    glVertex3i(-16, 13, -16);
    glVertex3i(-8, 13, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 15, -14);
    glVertex3i(-14, 15, -10);
    glVertex3i(-16, 13, -8);
    glVertex3i(-8, 13, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 15, -14);
    glVertex3i(-14, 15, -14);
    glVertex3i(-16, 13, -16);
    glVertex3i(-8, 13, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 15, -14);
    glVertex3i(-14, 15, -10);
    glVertex3i(-16, 13, -8);
    glVertex3i(-16, 13, -16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 15, -12);
    glVertex3i(-10, 15, -14);
    glVertex3i(-8, 13, -16);
    glVertex3i(-8, 13, -12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-12, 15, -10);
    glVertex3i(-14, 15, -10);
    glVertex3i(-16, 13, -8);
    glVertex3i(-12, 13, -8);
    glEnd();



    //sambungan

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3f(-10.01, 15, -12.01);
    glVertex3f(10.01, 15, -12.01);
    glVertex3f(8.01, 13, -16.01);
    glVertex3f(-8.01, 13, -16.01);
   
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3f(10.01, 15, 12.01);
    glVertex3f(-10.01, 15, 12.01);
    glVertex3f(-8.01, 13, 16.01);
    glVertex3f(8.01, 13, 16.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3f(-12.01, 15, 10.01);
    glVertex3f(-12.01, 15, -10.01);
    glVertex3f(-16.01, 13, 8.01);
    glVertex3f(-16.01, 13, -8.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3f(-12.01, 15, -10.01);
    glVertex3f(-12.01, 15, 10.01);
    glVertex3f(-16.01, 13, -8.01);
    glVertex3f(-16.01, 13, 8.01);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3f(12.01, 15, 10.01);
    glVertex3f(12.01, 15, -10.01);
    glVertex3f(16.01, 13, 8.01);
    glVertex3f(16.01, 13, -8.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3f(12.01, 15, -10.01);
    glVertex3f(12.01, 15, 10.01);
    glVertex3f(-16.01, 13, -8.01);
    glVertex3f(-16.01, 13, 8.01);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3f(12.01, 15, -10.01);
    glVertex3f(12.01, 15, 10.01);
    glVertex3f(-16.01, 13, -8.01);
    glVertex3f(16.01, 13, 8.01);
    glEnd();




  /*  glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3f(8.01, 13, -12.01);
    glVertex3f(-8.01, 13, -16.01);
    glVertex3f(-16.01, 13, -12.01);
    glVertex3f(-12.01, 13, -12.01);
    glEnd();
    */
    //pojokan atas 1 part3
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 35, 14);
    glVertex3i(14, 35, 14);
    glVertex3i(16, 33, 16);
    glVertex3i(8, 33, 16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 35, 14);
    glVertex3i(14, 35, 10);
    glVertex3i(16, 33, 8);
    glVertex3i(8, 33, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 35, 14);
    glVertex3i(14, 35, 14);
    glVertex3i(16, 33, 16);
    glVertex3i(8, 33, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 35, 14);
    glVertex3i(14, 35, 10);
    glVertex3i(16, 33, 8);
    glVertex3i(16, 33, 16);
    glEnd();

    //Pojokan atas 2
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 31, 14);
    glVertex3i(14, 31, 14);
    glVertex3i(16, 29, 16);
    glVertex3i(8, 29, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 31, 14);
    glVertex3i(14, 31, 10);
    glVertex3i(16, 29, 8);
    glVertex3i(8, 29, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 31, 14);
    glVertex3i(14, 31, 14);
    glVertex3i(16, 29, 16);
    glVertex3i(8, 29, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 31, 14);
    glVertex3i(14, 31, 10);
    glVertex3i(16, 29, 8);
    glVertex3i(16, 29, 16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(12, 31, 10);
    glVertex3i(14, 31, 10);
    glVertex3i(16, 29, 8);
    glVertex3i(12, 29, 8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 31, 12);
    glVertex3i(10, 31, 14);
    glVertex3i(8, 29, 16);
    glVertex3i(8, 29, 12);
    glEnd();

    //Pojokan atas 3
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 27, 14);
    glVertex3i(14, 27, 14);
    glVertex3i(16, 25, 16);
    glVertex3i(8, 25, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 27, 14);
    glVertex3i(14, 27, 10);
    glVertex3i(16, 25, 8);
    glVertex3i(8, 25, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 27, 14);
    glVertex3i(14, 27, 14);
    glVertex3i(16, 25, 16);
    glVertex3i(8, 25, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 27, 14);
    glVertex3i(14, 27, 10);
    glVertex3i(16, 25, 8);
    glVertex3i(16, 25, 16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(12, 27, 10);
    glVertex3i(14, 27, 10);
    glVertex3i(16, 25, 8);
    glVertex3i(12, 25, 8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 27, 12);
    glVertex3i(10, 27, 14);
    glVertex3i(8, 25, 16);
    glVertex3i(8, 25, 12);
    glEnd();

    //Pojokan atas 4
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 23, 14);
    glVertex3i(14, 23, 14);
    glVertex3i(16, 21, 16);
    glVertex3i(8, 21, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 23, 14);
    glVertex3i(14, 23, 10);
    glVertex3i(16, 21, 8);
    glVertex3i(8, 21, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 23, 14);
    glVertex3i(14, 23, 14);
    glVertex3i(16, 21, 16);
    glVertex3i(8, 21, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 23, 14);
    glVertex3i(14, 23, 10);
    glVertex3i(16, 21, 8);
    glVertex3i(16, 21, 16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(12, 23, 10);
    glVertex3i(14, 23, 10);
    glVertex3i(16, 21, 8);
    glVertex3i(12, 21, 8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 23, 12);
    glVertex3i(10, 23, 14);
    glVertex3i(8, 21, 16);
    glVertex3i(8, 21, 12);
    glEnd();

    //Pojokan atas 5
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 19, 14);
    glVertex3i(14, 19, 14);
    glVertex3i(16, 17, 16);
    glVertex3i(8, 17, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 19, 14);
    glVertex3i(14, 19, 10);
    glVertex3i(16, 17, 8);
    glVertex3i(8, 17, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 19, 14);
    glVertex3i(14, 19, 14);
    glVertex3i(16, 17, 16);
    glVertex3i(8, 17, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 19, 14);
    glVertex3i(14, 19, 10);
    glVertex3i(16, 17, 8);
    glVertex3i(16, 17, 16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(12, 19, 10);
    glVertex3i(14, 19, 10);
    glVertex3i(16, 17, 8);
    glVertex3i(12, 17, 8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 19, 12);
    glVertex3i(10, 19, 14);
    glVertex3i(8, 17, 16);
    glVertex3i(8, 17, 12);
    glEnd();

    //Pojokan atas 6
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 15, 14);
    glVertex3i(14, 15, 14);
    glVertex3i(16, 13, 16);
    glVertex3i(8, 13, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 15, 14);
    glVertex3i(14, 15, 10);
    glVertex3i(16, 13, 8);
    glVertex3i(8, 13, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 15, 14);
    glVertex3i(14, 15, 14);
    glVertex3i(16, 13, 16);
    glVertex3i(8, 13, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(14, 15, 14);
    glVertex3i(14, 15, 10);
    glVertex3i(16, 13, 8);
    glVertex3i(16, 13, 16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(12, 15, 10);
    glVertex3i(14, 15, 10);
    glVertex3i(16, 13, 8);
    glVertex3i(12, 13, 8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 15, 12);
    glVertex3i(10, 15, 14);
    glVertex3i(8, 13, 16);
    glVertex3i(8, 13, 12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(10, 35, 12);
    glVertex3i(10, 35, 14);
    glVertex3i(8, 33, 16);
    glVertex3i(8, 33, 12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(12, 35, 10);
    glVertex3i(14, 35, 10);
    glVertex3i(16, 33, 8);
    glVertex3i(12, 33, 8);
    glEnd();


    //pojokan atas 1 part4
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 35, 14);
    glVertex3i(-14, 35, 14);
    glVertex3i(-16, 33, 16);
    glVertex3i(-8, 33, 16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 35, 14);
    glVertex3i(-14, 35, 10);
    glVertex3i(-16, 33, 8);
    glVertex3i(-8, 33, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 35, 14);
    glVertex3i(-14, 35, 14);
    glVertex3i(-16, 33, 16);
    glVertex3i(-8, 33, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 35, 14);
    glVertex3i(-14, 35, 10);
    glVertex3i(-16, 33, 8);
    glVertex3i(-16, 33, 16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 35, 12);
    glVertex3i(-10, 35, 14);
    glVertex3i(-8, 33, 16);
    glVertex3i(-8, 33, 12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-12, 35, 10);
    glVertex3i(-14, 35, 10);
    glVertex3i(-16, 33, 8);
    glVertex3i(-12, 33, 8);
    glEnd();

    //Pojokan atas 2
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 31, 14);
    glVertex3i(-14, 31, 14);
    glVertex3i(-16, 29, 16);
    glVertex3i(-8, 29, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 31, 14);
    glVertex3i(-14, 31, 10);
    glVertex3i(-16, 29, 8);
    glVertex3i(-8, 29, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 31, 14);
    glVertex3i(-14, 31, 14);
    glVertex3i(-16, 29, 16);
    glVertex3i(-8, 29, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 31, 14);
    glVertex3i(-14, 31, 10);
    glVertex3i(-16, 29, 8);
    glVertex3i(-16, 29, 16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-12, 31, 10);
    glVertex3i(-14, 31, 10);
    glVertex3i(-16, 29, 8);
    glVertex3i(-12, 29, 8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 31, 12);
    glVertex3i(-10, 31, 14);
    glVertex3i(-8, 29, 16);
    glVertex3i(-8, 29, 12);
    glEnd();

    //Pojokan atas 3
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 27, 14);
    glVertex3i(-14, 27, 14);
    glVertex3i(-16, 25, 16);
    glVertex3i(-8, 25, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 27, 14);
    glVertex3i(-14, 27, 10);
    glVertex3i(-16, 25, 8);
    glVertex3i(-8, 25, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 27, 14);
    glVertex3i(-14, 27, 14);
    glVertex3i(-16, 25, 16);
    glVertex3i(-8, 25, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 27, 14);
    glVertex3i(-14, 27, 10);
    glVertex3i(-16, 25, 8);
    glVertex3i(-16, 25, 16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-12, 27, 10);
    glVertex3i(-14, 27, 10);
    glVertex3i(-16, 25, 8);
    glVertex3i(-12, 25, 8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 27, 12);
    glVertex3i(-10, 27, 14);
    glVertex3i(-8, 25, 16);
    glVertex3i(-8, 25, 12);
    glEnd();

    //Pojokan atas 4
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 23, 14);
    glVertex3i(-14, 23, 14);
    glVertex3i(-16, 21, 16);
    glVertex3i(-8, 21, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 23, 14);
    glVertex3i(-14, 23, 10);
    glVertex3i(-16, 21, 8);
    glVertex3i(-8, 21, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 23, 14);
    glVertex3i(-14, 23, 14);
    glVertex3i(-16, 21, 16);
    glVertex3i(-8, 21, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 23, 14);
    glVertex3i(-14, 23, 10);
    glVertex3i(-16, 21, 8);
    glVertex3i(-16, 21, 16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-12, 23, 10);
    glVertex3i(-14, 23, 10);
    glVertex3i(-16, 21, 8);
    glVertex3i(-12, 21, 8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 23, 12);
    glVertex3i(-10, 23, 14);
    glVertex3i(-8, 21, 16);
    glVertex3i(-8, 21, 12);
    glEnd();

    //Pojokan atas 5
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 19, 14);
    glVertex3i(-14, 19, 14);
    glVertex3i(-16, 17, 16);
    glVertex3i(-8, 17, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 19, 14);
    glVertex3i(-14, 19, 10);
    glVertex3i(-16, 17, 8);
    glVertex3i(-8, 17, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 19, 14);
    glVertex3i(-14, 19, 14);
    glVertex3i(-16, 17, 16);
    glVertex3i(-8, 17, 16);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 19, 14);
    glVertex3i(-14, 19, 10);
    glVertex3i(-16, 17, 8);
    glVertex3i(-16, 17, 16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-12, 19, 10);
    glVertex3i(-14, 19, 10);
    glVertex3i(-16, 17, 8);
    glVertex3i(-12, 17, 8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 19, 12);
    glVertex3i(-10, 19, 14);
    glVertex3i(-8, 17, 16);
    glVertex3i(-8, 17, 12);
    glEnd();



    //Pojokan atas 6

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 15, 14);
    glVertex3i(-14, 15, 14);
    glVertex3i(-16, 13, 16);
    glVertex3i(-8, 13, 16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 15, 14);
    glVertex3i(-14, 15, 10);
    glVertex3i(-16, 13, 8);
    glVertex3i(-8, 13, 16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 15, 14);
    glVertex3i(-14, 15, 14);
    glVertex3i(-16, 13, 16);
    glVertex3i(-8, 13, 16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-14, 15, 14);
    glVertex3i(-14, 15, 10);
    glVertex3i(-16, 13, 8);
    glVertex3i(-16, 13, 16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-12, 15, 10);
    glVertex3i(-14, 15, 10);
    glVertex3i(-16, 13, 8);
    glVertex3i(-12, 13, 8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 15, 12);
    glVertex3i(-10, 15, 14);
    glVertex3i(-8, 13, 16);
    glVertex3i(-8, 13, 12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-10, 35, 12);
    glVertex3i(-10, 35, 14);
    glVertex3i(-8, 33, 16);
    glVertex3i(-8, 33, 12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 17, 0);
    glVertex3i(-12, 35, 10);
    glVertex3i(-14, 35, 10);
    glVertex3i(-16, 33, 8);
    glVertex3i(-12, 33, 8);
    glEnd();

    //pillar belakang


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(10.7, 0, -14.7);
    glVertex3f(10.7, 0, -14.3);
    glVertex3f(10.3, 0, -14.3);
    glVertex3f(10.3, 0, -14.7);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(10.7, 34, -14.7);
    glVertex3f(10.7, 34, -14.3);
    glVertex3f(10.3, 34, -14.3);
    glVertex3f(10.3, 34, -14.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(10.7, 0, -14.7);
    glVertex3f(10.7, 0, -14.3);
    glVertex3f(10.7, 0, -14.7);
    glVertex3f(10.7, 34, -14.7);
    glVertex3f(10.7, 34, -14.3);
    glVertex3f(10.7, 0, -14.3);
    glVertex3f(10.7, 34, -14.7);
    glVertex3f(10.7, 34, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(10.3, 34 , -14.7);
    glVertex3f(10.7, 34 , -14.7);
    glVertex3f(10.7, 0, -14.7);
    glVertex3f(10.7, 34 , -14.7);
    glVertex3f(10.3, 34, -14.7);
    glVertex3f(10.3, 34 , -14.7);
    glVertex3f(10.7, 34 , -14.7);
    glVertex3f(10.3, 34 ,-14.7);
    glEnd();

    glColor3ub(0.77, 0.69, 0.62);
    glColor3ub(0, 0, 255);
    glVertex3f(10.3, 34, -14.7);
    glVertex3f(10.3, 34, -14.3);
    glVertex3f(10.3, 34, -14.7);
    glVertex3f(10.3, 0, -14.7);
    glVertex3f(10.3, 34, -14.3);
    glVertex3f(10.3, 0, -14.3);
    glVertex3f(10.3, 0, -14.3);
    glVertex3f(10.3, 0, -14.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(10.7, 34, -14.3);
    glVertex3f(10.3, 34, -14.3);
    glVertex3f(10.3, 34, -14.3);
    glVertex3f(10.3, 0, -14.3);
    glVertex3f(10.7, 34, -14.3);
    glVertex3f(10.7, 0, -14.3);
    glVertex3f(10.7, 0, -14.3);
    glVertex3f(10.3, 0, -14.3);
    glEnd();





    //pillar belakang 2


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.7, 0, -14.7);
    glVertex3f(14.7, 0, -14.3);
    glVertex3f(14.3, 0, -14.3);
    glVertex3f(14.3, 0, -14.7);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.7, 34, -14.7);
    glVertex3f(14.7, 34, -14.3);
    glVertex3f(14.3, 34, -14.3);
    glVertex3f(14.3, 34, -14.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.7, 0, -14.7);
    glVertex3f(14.7, 0, -14.3);
    glVertex3f(14.7, 0, -14.7);
    glVertex3f(14.7, 34, -14.7);
    glVertex3f(14.7, 34, -14.3);
    glVertex3f(14.7, 0, -14.3);
    glVertex3f(14.7, 34, -14.7);
    glVertex3f(14.7, 34, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.3, 34, -14.7);
    glVertex3f(14.7, 34, -14.7);
    glVertex3f(14.7, 0, -14.7);
    glVertex3f(14.7, 34, -14.7);
    glVertex3f(14.3, 34, -14.7);
    glVertex3f(14.3, 34, -14.7);
    glVertex3f(14.7, 34, -14.7);
    glVertex3f(14.3, 34, -14.7);
    glEnd();

    glColor3ub(0.77, 0.69, 0.62);
    glColor3ub(0, 0, 255);
    glVertex3f(14.3, 34, -14.7);
    glVertex3f(14.3, 34, -14.3);
    glVertex3f(14.3, 34, -14.7);
    glVertex3f(14.3, 0, -14.7);
    glVertex3f(14.3, 34, -14.3);
    glVertex3f(14.3, 0, -14.3);
    glVertex3f(14.3, 0, -14.3);
    glVertex3f(14.3, 0, -14.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.7, 34, -14.3);
    glVertex3f(14.3, 34, -14.3);
    glVertex3f(14.3, 34, -14.3);
    glVertex3f(14.3, 0, -14.3);
    glVertex3f(14.7, 34, -14.3);
    glVertex3f(14.7, 0, -14.3);
    glVertex3f(14.7, 0, -14.3);
    glVertex3f(14.3, 0, -14.3);
    glEnd();



    //pillar belakang 3


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.7, 0, -10.7);
    glVertex3f(14.7, 0, -10.3);
    glVertex3f(14.3, 0, -10.3);
    glVertex3f(14.3, 0, -10.7);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.7, 34, -10.7);
    glVertex3f(14.7, 34, -10.3);
    glVertex3f(14.3, 34, -10.3);
    glVertex3f(14.3, 34, -10.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.7, 0, -10.7);
    glVertex3f(14.7, 0, -10.3);
    glVertex3f(14.7, 0, -10.7);
    glVertex3f(14.7, 34, -10.7);
    glVertex3f(14.7, 34, -10.3);
    glVertex3f(14.7, 0, -10.3);
    glVertex3f(14.7, 34, -10.7);
    glVertex3f(14.7, 34, -10.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.3, 34, -10.7);
    glVertex3f(14.7, 34, -10.7);
    glVertex3f(14.7, 0, -10.7);
    glVertex3f(14.7, 34, -10.7);
    glVertex3f(14.3, 34, -10.7);
    glVertex3f(14.3, 34, -10.7);
    glVertex3f(14.7, 34, -10.7);
    glVertex3f(14.3, 34, -10.7);
    glEnd();

    glColor3ub(0.77, 0.69, 0.62);
    glColor3ub(0, 0, 255);
    glVertex3f(14.3, 34, -10.7);
    glVertex3f(14.3, 34, -10.3);
    glVertex3f(14.3, 34, -10.7);
    glVertex3f(14.3, 0, -10.7);
    glVertex3f(14.3, 34, -10.3);
    glVertex3f(14.3, 0, -10.3);
    glVertex3f(14.3, 0, -10.3);
    glVertex3f(14.3, 0, -10.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.7, 34, -10.3);
    glVertex3f(14.3, 34, -10.3);
    glVertex3f(14.3, 34, -10.3);
    glVertex3f(14.3, 0, -10.3);
    glVertex3f(14.7, 34, -10.3);
    glVertex3f(14.7, 0, -10.3);
    glVertex3f(14.7, 0, -10.3);
    glVertex3f(14.3, 0, -10.3);
    glEnd();

    //pillar depan 1


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.7, 0, 10.7);
    glVertex3f(14.7, 0, 10.3);
    glVertex3f(14.3, 0, 10.3);
    glVertex3f(14.3, 0, 10.7);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.7, 34, 10.7);
    glVertex3f(14.7, 34, 10.3);
    glVertex3f(14.3, 34, 10.3);
    glVertex3f(14.3, 34, 10.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.7, 0, 10.7);
    glVertex3f(14.7, 0, 10.3);
    glVertex3f(14.7, 0, 10.7);
    glVertex3f(14.7, 34, 10.7);
    glVertex3f(14.7, 34, 10.3);
    glVertex3f(14.7, 0, 10.3);
    glVertex3f(14.7, 34, 10.7);
    glVertex3f(14.7, 34, 10.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.3, 34, 10.7);
    glVertex3f(14.7, 34, 10.7);
    glVertex3f(14.7, 0, 10.7);
    glVertex3f(14.7, 34, 10.7);
    glVertex3f(14.3, 34, 10.7);
    glVertex3f(14.3, 34, 10.7);
    glVertex3f(14.7, 34, 10.7);
    glVertex3f(14.3, 34, 10.7);
    glEnd();

    glColor3ub(0.77, 0.69, 0.62);
    glColor3ub(0, 0, 255);
    glVertex3f(14.3, 34, 10.7);
    glVertex3f(14.3, 34, 10.3);
    glVertex3f(14.3, 34, 10.7);
    glVertex3f(14.3, 0, 10.7);
    glVertex3f(14.3, 34, 10.3);
    glVertex3f(14.3, 0, 10.3);
    glVertex3f(14.3, 0, 10.3);
    glVertex3f(14.3, 0, 10.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.7, 34, 10.3);
    glVertex3f(14.3, 34, 10.3);
    glVertex3f(14.3, 34, 10.3);
    glVertex3f(14.3, 0, 10.3);
    glVertex3f(14.7, 34, 10.3);
    glVertex3f(14.7, 0, 10.3);
    glVertex3f(14.7, 0, 10.3);
    glVertex3f(14.3, 0, 10.3);
    glEnd();


    //pillar depan 2


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.7, 0, 14.7);
    glVertex3f(14.7, 0, 14.3);
    glVertex3f(14.3, 0, 14.3);
    glVertex3f(14.3, 0, 14.7);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.7, 34, 14.7);
    glVertex3f(14.7, 34, 14.3);
    glVertex3f(14.3, 34, 14.3);
    glVertex3f(14.3, 34, 14.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.7, 0, 14.7);
    glVertex3f(14.7, 0, 14.3);
    glVertex3f(14.7, 0, 14.7);
    glVertex3f(14.7, 34, 14.7);
    glVertex3f(14.7, 34, 14.3);
    glVertex3f(14.7, 0, 14.3);
    glVertex3f(14.7, 34, 14.7);
    glVertex3f(14.7, 34, 14.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.3, 34, 14.7);
    glVertex3f(14.7, 34, 14.7);
    glVertex3f(14.7, 0, 14.7);
    glVertex3f(14.7, 34, 14.7);
    glVertex3f(14.3, 34, 14.7);
    glVertex3f(14.3, 34, 14.7);
    glVertex3f(14.7, 34, 14.7);
    glVertex3f(14.3, 34, 14.7);
    glEnd();

    glColor3ub(0.77, 0.69, 0.62);
    glColor3ub(0, 0, 255);
    glVertex3f(14.3, 34, 14.7);
    glVertex3f(14.3, 34, 14.3);
    glVertex3f(14.3, 34, 14.7);
    glVertex3f(14.3, 0, 14.7);
    glVertex3f(14.3, 34, 14.3);
    glVertex3f(14.3, 0, 14.3);
    glVertex3f(14.3, 0, 14.3);
    glVertex3f(14.3, 0, 14.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(14.7, 34, 14.3);
    glVertex3f(14.3, 34, 14.3);
    glVertex3f(14.3, 34, 14.3);
    glVertex3f(14.3, 0, 14.3);
    glVertex3f(14.7, 34, 14.3);
    glVertex3f(14.7, 0, 14.3);
    glVertex3f(14.7, 0, 14.3);
    glVertex3f(14.3, 0, 14.3);
    glEnd();

    //pillar depan 3


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(10.7, 0, 14.7);
    glVertex3f(10.7, 0, 14.3);
    glVertex3f(10.3, 0, 14.3);
    glVertex3f(10.3, 0, 14.7);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(10.7, 34, 14.7);
    glVertex3f(10.7, 34, 14.3);
    glVertex3f(10.3, 34, 14.3);
    glVertex3f(10.3, 34, 14.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(10.7, 0, 14.7);
    glVertex3f(10.7, 0, 14.3);
    glVertex3f(10.7, 0, 14.7);
    glVertex3f(10.7, 34, 14.7);
    glVertex3f(10.7, 34, 14.3);
    glVertex3f(10.7, 0, 14.3);
    glVertex3f(10.7, 34, 14.7);
    glVertex3f(10.7, 34, 14.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(10.3, 34, 14.7);
    glVertex3f(10.7, 34, 14.7);
    glVertex3f(10.7, 0, 14.7);
    glVertex3f(10.7, 34, 14.7);
    glVertex3f(10.3, 34, 14.7);
    glVertex3f(10.3, 34, 14.7);
    glVertex3f(10.7, 34, 14.7);
    glVertex3f(10.3, 34, 14.7);
    glEnd();

    glColor3ub(0.77, 0.69, 0.62);
    glColor3ub(0, 0, 255);
    glVertex3f(10.3, 34, 14.7);
    glVertex3f(10.3, 34, 14.3);
    glVertex3f(10.3, 34, 14.7);
    glVertex3f(10.3, 0, 14.7);
    glVertex3f(10.3, 34, 14.3);
    glVertex3f(10.3, 0, 14.3);
    glVertex3f(10.3, 0, 14.3);
    glVertex3f(10.3, 0, 14.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(10.7, 34, 14.3);
    glVertex3f(10.3, 34, 14.3);
    glVertex3f(10.3, 34, 14.3);
    glVertex3f(10.3, 0, 14.3);
    glVertex3f(10.7, 34, 14.3);
    glVertex3f(10.7, 0, 14.3);
    glVertex3f(10.7, 0, 14.3);
    glVertex3f(10.3, 0, 14.3);
    glEnd();


    //pillar depan II 1


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.7, 0, 14.7);
    glVertex3f(-14.7, 0, 14.3);
    glVertex3f(-14.3, 0, 14.3);
    glVertex3f(-14.3, 0, 14.7);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.7, 34, 14.7);
    glVertex3f(-14.7, 34, 14.3);
    glVertex3f(-14.3, 34, 14.3);
    glVertex3f(-14.3, 34, 14.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.7, 0, 14.7);
    glVertex3f(-14.7, 0, 14.3);
    glVertex3f(-14.7, 0, 14.7);
    glVertex3f(-14.7, 34, 14.7);
    glVertex3f(-14.7, 34, 14.3);
    glVertex3f(-14.7, 0, 14.3);
    glVertex3f(-14.7, 34, 14.7);
    glVertex3f(-14.7, 34, 14.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.3, 34, 14.7);
    glVertex3f(-14.7, 34, 14.7);
    glVertex3f(-14.7, 0, 14.7);
    glVertex3f(-14.7, 34, 14.7);
    glVertex3f(-14.3, 34, 14.7);
    glVertex3f(-14.3, 34, 14.7);
    glVertex3f(-14.7, 34, 14.7);
    glVertex3f(-14.3, 34, 14.7);
    glEnd();

    glColor3ub(0.77, 0.69, 0.62);
    glColor3ub(0, 0, 255);
    glVertex3f(-14.3, 34, 14.7);
    glVertex3f(-14.3, 34, 14.3);
    glVertex3f(-14.3, 34, 14.7);
    glVertex3f(-14.3, 0, 14.7);
    glVertex3f(-14.3, 34, 14.3);
    glVertex3f(-14.3, 0, 14.3);
    glVertex3f(-14.3, 0, 14.3);
    glVertex3f(-14.3, 0, 14.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.7, 34, 14.3);
    glVertex3f(-14.3, 34, 14.3);
    glVertex3f(-14.3, 34, 14.3);
    glVertex3f(-14.3, 0, 14.3);
    glVertex3f(-14.7, 34, 14.3);
    glVertex3f(-14.7, 0, 14.3);
    glVertex3f(-14.7, 0, 14.3);
    glVertex3f(-14.3, 0, 14.3);
    glEnd();

    //pillar depan II 2


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-10.7, 0, 14.7);
    glVertex3f(-10.7, 0, 14.3);
    glVertex3f(-10.3, 0, 14.3);
    glVertex3f(-10.3, 0, 14.7);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-10.7, 34, 14.7);
    glVertex3f(-10.7, 34, 14.3);
    glVertex3f(-10.3, 34, 14.3);
    glVertex3f(-10.3, 34, 14.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-10.7, 0, 14.7);
    glVertex3f(-10.7, 0, 14.3);
    glVertex3f(-10.7, 0, 14.7);
    glVertex3f(-10.7, 34, 14.7);
    glVertex3f(-10.7, 34, 14.3);
    glVertex3f(-10.7, 0, 14.3);
    glVertex3f(-10.7, 34, 14.7);
    glVertex3f(-10.7, 34, 14.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-10.3, 34, 14.7);
    glVertex3f(-10.7, 34, 14.7);
    glVertex3f(-10.7, 0, 14.7);
    glVertex3f(-10.7, 34, 14.7);
    glVertex3f(-10.3, 34, 14.7);
    glVertex3f(-10.3, 34, 14.7);
    glVertex3f(-10.7, 34, 14.7);
    glVertex3f(-10.3, 34, 14.7);
    glEnd();

    glColor3ub(0.77, 0.69, 0.62);
    glColor3ub(0, 0, 255);
    glVertex3f(-10.3, 34, 14.7);
    glVertex3f(-10.3, 34, 14.3);
    glVertex3f(-10.3, 34, 14.7);
    glVertex3f(-10.3, 0, 14.7);
    glVertex3f(-10.3, 34, 14.3);
    glVertex3f(-10.3, 0, 14.3);
    glVertex3f(-10.3, 0, 14.3);
    glVertex3f(-10.3, 0, 14.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-10.7, 34, 14.3);
    glVertex3f(-10.3, 34, 14.3);
    glVertex3f(-10.3, 34, 14.3);
    glVertex3f(-10.3, 0, 14.3);
    glVertex3f(-10.7, 34, 14.3);
    glVertex3f(-10.7, 0, 14.3);
    glVertex3f(-10.7, 0, 14.3);
    glVertex3f(-10.3, 0, 14.3);
    glEnd();

    //pillar depan II 3


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.7, 0, 10.7);
    glVertex3f(-14.7, 0, 10.3);
    glVertex3f(-14.3, 0, 10.3);
    glVertex3f(-14.3, 0, 10.7);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.7, 34, 10.7);
    glVertex3f(-14.7, 34, 10.3);
    glVertex3f(-14.3, 34, 10.3);
    glVertex3f(-14.3, 34, 10.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.7, 0, 10.7);
    glVertex3f(-14.7, 0, 10.3);
    glVertex3f(-14.7, 0, 10.7);
    glVertex3f(-14.7, 34, 10.7);
    glVertex3f(-14.7, 34, 10.3);
    glVertex3f(-14.7, 0, 10.3);
    glVertex3f(-14.7, 34, 10.7);
    glVertex3f(-14.7, 34, 10.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.3, 34, 10.7);
    glVertex3f(-14.7, 34, 10.7);
    glVertex3f(-14.7, 0, 10.7);
    glVertex3f(-14.7, 34, 10.7);
    glVertex3f(-14.3, 34, 10.7);
    glVertex3f(-14.3, 34, 10.7);
    glVertex3f(-14.7, 34, 10.7);
    glVertex3f(-14.3, 34, 10.7);
    glEnd();

    glColor3ub(0.77, 0.69, 0.62);
    glColor3ub(0, 0, 255);
    glVertex3f(-14.3, 34, 10.7);
    glVertex3f(-14.3, 34, 10.3);
    glVertex3f(-14.3, 34, 10.7);
    glVertex3f(-14.3, 0, 10.7);
    glVertex3f(-14.3, 34, 10.3);
    glVertex3f(-14.3, 0, 10.3);
    glVertex3f(-14.3, 0, 10.3);
    glVertex3f(-14.3, 0, 10.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.7, 34, 10.3);
    glVertex3f(-14.3, 34, 10.3);
    glVertex3f(-14.3, 34, 10.3);
    glVertex3f(-14.3, 0, 10.3);
    glVertex3f(-14.7, 34, 10.3);
    glVertex3f(-14.7, 0, 10.3);
    glVertex3f(-14.7, 0, 10.3);
    glVertex3f(-14.3, 0, 10.3);
    glEnd();


    //pillar belakang II 1


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.7, 0, -10.7);
    glVertex3f(-14.7, 0, -10.3);
    glVertex3f(-14.3, 0, -10.3);
    glVertex3f(-14.3, 0, -10.7);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.7, 34, -10.7);
    glVertex3f(-14.7, 34, -10.3);
    glVertex3f(-14.3, 34, -10.3);
    glVertex3f(-14.3, 34, -10.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.7, 0, -10.7);
    glVertex3f(-14.7, 0, -10.3);
    glVertex3f(-14.7, 0, -10.7);
    glVertex3f(-14.7, 34, -10.7);
    glVertex3f(-14.7, 34, -10.3);
    glVertex3f(-14.7, 0, -10.3);
    glVertex3f(-14.7, 34, -10.7);
    glVertex3f(-14.7, 34, -10.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.3, 34, -10.7);
    glVertex3f(-14.7, 34, -10.7);
    glVertex3f(-14.7, 0, -10.7);
    glVertex3f(-14.7, 34, -10.7);
    glVertex3f(-14.3, 34, -10.7);
    glVertex3f(-14.3, 34, -10.7);
    glVertex3f(-14.7, 34, -10.7);
    glVertex3f(-14.3, 34, -10.7);
    glEnd();

    glColor3ub(0.77, 0.69, 0.62);
    glColor3ub(0, 0, 255);
    glVertex3f(-14.3, 34, -10.7);
    glVertex3f(-14.3, 34, -10.3);
    glVertex3f(-14.3, 34, -10.7);
    glVertex3f(-14.3, 0, -10.7);
    glVertex3f(-14.3, 34, -10.3);
    glVertex3f(-14.3, 0, -10.3);
    glVertex3f(-14.3, 0, -10.3);
    glVertex3f(-14.3, 0, -10.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.7, 34, -10.3);
    glVertex3f(-14.3, 34, -10.3);
    glVertex3f(-14.3, 34, -10.3);
    glVertex3f(-14.3, 0, -10.3);
    glVertex3f(-14.7, 34, -10.3);
    glVertex3f(-14.7, 0, -10.3);
    glVertex3f(-14.7, 0, -10.3);
    glVertex3f(-14.3, 0, -10.3);
    glEnd();

    //pillar belakang II 2


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.7, 0, -14.7);
    glVertex3f(-14.7, 0, -14.3);
    glVertex3f(-14.3, 0, -14.3);
    glVertex3f(-14.3, 0, -14.7);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.7, 34, -14.7);
    glVertex3f(-14.7, 34, -14.3);
    glVertex3f(-14.3, 34, -14.3);
    glVertex3f(-14.3, 34, -14.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.7, 0, -14.7);
    glVertex3f(-14.7, 0, -14.3);
    glVertex3f(-14.7, 0, -14.7);
    glVertex3f(-14.7, 34, -14.7);
    glVertex3f(-14.7, 34, -14.3);
    glVertex3f(-14.7, 0, -14.3);
    glVertex3f(-14.7, 34, -14.7);
    glVertex3f(-14.7, 34, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.3, 34, -14.7);
    glVertex3f(-14.7, 34, -14.7);
    glVertex3f(-14.7, 0, -14.7);
    glVertex3f(-14.7, 34, -14.7);
    glVertex3f(-14.3, 34, -14.7);
    glVertex3f(-14.3, 34, -14.7);
    glVertex3f(-14.7, 34, -14.7);
    glVertex3f(-14.3, 34, -14.7);
    glEnd();

    glColor3ub(0.77, 0.69, 0.62);
    glColor3ub(0, 0, 255);
    glVertex3f(-14.3, 34, -14.7);
    glVertex3f(-14.3, 34, -14.3);
    glVertex3f(-14.3, 34, -14.7);
    glVertex3f(-14.3, 0, -14.7);
    glVertex3f(-14.3, 34, -14.3);
    glVertex3f(-14.3, 0, -14.3);
    glVertex3f(-14.3, 0, -14.3);
    glVertex3f(-14.3, 0, -14.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-14.7, 34, -14.3);
    glVertex3f(-14.3, 34, -14.3);
    glVertex3f(-14.3, 34, -14.3);
    glVertex3f(-14.3, 0, -14.3);
    glVertex3f(-14.7, 34, -14.3);
    glVertex3f(-14.7, 0, -14.3);
    glVertex3f(-14.7, 0, -14.3);
    glVertex3f(-14.3, 0, -14.3);
    glEnd();



    //pillar belakang II 3


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-10.7, 0, -14.7);
    glVertex3f(-10.7, 0, -14.3);
    glVertex3f(-10.3, 0, -14.3);
    glVertex3f(-10.3, 0, -14.7);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-10.7, 34, -14.7);
    glVertex3f(-10.7, 34, -14.3);
    glVertex3f(-10.3, 34, -14.3);
    glVertex3f(-10.3, 34, -14.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-10.7, 0, -14.7);
    glVertex3f(-10.7, 0, -14.3);
    glVertex3f(-10.7, 0, -14.7);
    glVertex3f(-10.7, 34, -14.7);
    glVertex3f(-10.7, 34, -14.3);
    glVertex3f(-10.7, 0, -14.3);
    glVertex3f(-10.7, 34, -14.7);
    glVertex3f(-10.7, 34, -14.3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-10.3, 34, -14.7);
    glVertex3f(-10.7, 34, -14.7);
    glVertex3f(-10.7, 0, -14.7);
    glVertex3f(-10.7, 34, -14.7);
    glVertex3f(-10.3, 34, -14.7);
    glVertex3f(-10.3, 34, -14.7);
    glVertex3f(-10.7, 34, -14.7);
    glVertex3f(-10.3, 34, -14.7);
    glEnd();

    glColor3ub(0.77, 0.69, 0.62);
    glColor3ub(0, 0, 255);
    glVertex3f(-10.3, 34, -14.7);
    glVertex3f(-10.3, 34, -14.3);
    glVertex3f(-10.3, 34, -14.7);
    glVertex3f(-10.3, 0, -14.7);
    glVertex3f(-10.3, 34, -14.3);
    glVertex3f(-10.3, 0, -14.3);
    glVertex3f(-10.3, 0, -14.3);
    glVertex3f(-10.3, 0, -14.7);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.77, 0.69, 0.62);
    glVertex3f(-10.7, 34, -14.3);
    glVertex3f(-10.3, 34, -14.3);
    glVertex3f(-10.3, 34, -14.3);
    glVertex3f(-10.3, 0, -14.3);
    glVertex3f(-10.7, 34, -14.3);
    glVertex3f(-10.7, 0, -14.3);
    glVertex3f(-10.7, 0, -14.3);
    glVertex3f(-10.3, 0, -14.3);
    glEnd();





    
    //pintu
    glBegin(GL_QUADS);
    glColor3ub(0.09, 0.09, 0.09);
    glVertex3i(1, 0, 13);
    glVertex3i(-5, 0, 13);
    glVertex3i(-5, 8, 13);
    glVertex3i(1, 8, 13);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0.09, 0.09, 0.09);
    glVertex3i(5, 0, 13);
    glVertex3i(1, 0, 13);
    glVertex3i(1, 8, 13);
    glVertex3i(5, 8, 13);
    glEnd();

   //inventory


    //Papan Tulis
    glBegin(GL_QUADS);
    glColor3ub(250, 235, 215);
    glVertex3f(-4, 8, -11.5);
    glVertex3f(4, 8, -11.5);
    glVertex3f(4, 3, -11.5);
    glVertex3f(-4, 3, -11.5);
    glEnd();
    //Bingkai Papan Tulis
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(139, 69, 19);
    glVertex3f(-4, 8, -11.5);
    glVertex3f(4, 8, -11.5);
    glVertex3f(4, 3, -11.5);
    glVertex3f(-4, 3, -11.5);
    glEnd();

    //Lemari
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(8, 3, -4);
    glVertex3i(8, 3, 4);
    glVertex3i(10, 3, 4);
    glVertex3i(10, 3, -4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(8, 3, -4);
    glVertex3i(8, 3, 4);
    glVertex3i(8, 0, 4);
    glVertex3i(8, 0, -4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(8, 3, 4);
    glVertex3i(10, 3, 4);
    glVertex3i(10, 0, 4);
    glVertex3i(8, 0, 4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(10, 3, 4);
    glVertex3i(10, 3, -4);
    glVertex3i(10, 0, -4);
    glVertex3i(10, 0, 4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(10, 3, -4);
    glVertex3i(8, 3, -4);
    glVertex3i(8, 0, -4);
    glVertex3i(10, 0, -4);
    glEnd();
    //Garis Lemari
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(8, 3, -4);
    glVertex3i(8, 3, 4);
    glVertex3i(10, 3, 4);
    glVertex3i(10, 3, -4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(8, 3, -4);
    glVertex3i(8, 3, 4);
    glVertex3i(8, 0, 4);
    glVertex3i(8, 0, -4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(8, 3, 4);
    glVertex3i(10, 3, 4);
    glVertex3i(10, 0, 4);
    glVertex3i(8, 0, 4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(10, 3, 4);
    glVertex3i(10, 3, -4);
    glVertex3i(10, 0, -4);
    glVertex3i(10, 0, 4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(10, 3, -4);
    glVertex3i(8, 3, -4);
    glVertex3i(8, 0, -4);
    glVertex3i(10, 0, -4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(8, 0, -2);
    glVertex3i(8, 3, -2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(8, 0, 0);
    glVertex3i(8, 3, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(8, 0, 2);
    glVertex3i(8, 3, 2);
    glEnd();

    //Lemari 2
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(-8, 6, -4);
    glVertex3i(-8, 6, 4);
    glVertex3i(-10, 6, 4);
    glVertex3i(-10, 6, -4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(-8, 6, -4);
    glVertex3i(-8, 6, 4);
    glVertex3i(-8, 0, 4);
    glVertex3i(-8, 0, -4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(-8, 6, 4);
    glVertex3i(-10, 6, 4);
    glVertex3i(-10, 0, 4);
    glVertex3i(-8, 0, 4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(-10, 6, 4);
    glVertex3i(-10, 6, -4);
    glVertex3i(-10, 0, -4);
    glVertex3i(-10, 0, 4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(-10, 6, -4);
    glVertex3i(-8, 6, -4);
    glVertex3i(-8, 0, -4);
    glVertex3i(-10, 0, -4);
    glEnd();
    //Garis Lemari
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(-8, 6, -4);
    glVertex3i(-8, 6, 4);
    glVertex3i(-10, 6, 4);
    glVertex3i(-10, 6, -4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(-8, 6, -4);
    glVertex3i(-8, 6, 4);
    glVertex3i(-8, 0, 4);
    glVertex3i(-8, 0, -4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(-8, 6, 4);
    glVertex3i(-10, 6, 4);
    glVertex3i(-10, 0, 4);
    glVertex3i(-8, 0, 4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 6, 4);
    glVertex3i(-10, 6, -4);
    glVertex3i(-10, 0, -4);
    glVertex3i(-10, 0, 4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(-10, 6, -4);
    glVertex3i(-8, 6, -4);
    glVertex3i(-8, 0, -4);
    glVertex3i(-10, 0, -4);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(-8, 0, -2);
    glVertex3i(-8, 6, -2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(-8, 0, 0);
    glVertex3i(-8, 6, 0);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3i(-8, 0, 2);
    glVertex3i(-8, 6, 2);
    glEnd();

    //Meja
    //Kaki Meja 1
    glPushMatrix();
    glRotatef(-90.0, 0, -180.0, 0);
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(7, 2, -2);
    glVertex3i(5, 2, -2);
    glVertex3i(5, 0, -2);
    glVertex3i(7, 0, -2);
    glEnd();
    glPopMatrix();
    //Kaki Meja 2
    glPushMatrix();
    glRotatef(90.0, 0, -180.0, 0);
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(-7, 2, -2);
    glVertex3i(-5, 2, -2);
    glVertex3i(-5, 0, -2);
    glVertex3i(-7, 0, -2);
    glEnd();
    glPopMatrix();
    //Alas Meja
    glBegin(GL_QUADS);
    glTranslatef(0, 0, 50.0);
    glColor3ub(47, 79, 79);
    glVertex3i(-2, 2, -7);
    glVertex3i(2, 2, -7);
    glVertex3i(2, 2, -5);
    glVertex3i(-2, 2, -5);
    glEnd();

    //Kursi
    //Kaki Belakang
    glBegin(GL_QUADS);;
    glColor3ub(160, 82, 45);
    glVertex3i(-0.5, 3, -3);
    glVertex3i(1, 3, -3);
    glVertex3i(1, 0, -3);
    glVertex3i(-0.5, 0, -3);
    glEnd();
    //Kaki Depan
    glBegin(GL_QUADS);;
    glColor3ub(160, 82, 45);
    glVertex3i(-0.5, 1.5, -4);
    glVertex3i(1, 1.5, -4);
    glVertex3i(1, 0, -4);
    glVertex3i(-0.5, 0, -4);
    glEnd();
    //Alas Kursi
    glBegin(GL_QUADS);
    glColor3ub(47, 79, 79);
    glVertex3i(0, 1.6, -4.5);
    glVertex3i(1, 1.6, -4.5);
    glVertex3i(1, 1.6, -3);
    glVertex3i(0, 1.6, -3);
    glEnd();

    //Kursi 2
    //Kaki Belakang
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(3.5, 3, -3);
    glVertex3i(4, 3, -3);
    glVertex3i(4, 0, -3);
    glVertex3i(3.5, 0, -3);
    glEnd();
    //Kaki Depan
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(3.5, 1.5, -4);
    glVertex3i(4, 1.5, -4);
    glVertex3i(4, 0, -4);
    glVertex3i(3.5, 0, -4);
    glEnd();
    //Alas Kursi
    glBegin(GL_QUADS);
    glColor3ub(47, 79, 79);
    glVertex3i(3, 1.6, -4.5);
    glVertex3i(4, 1.6, -4.5);
    glVertex3i(4, 1.6, -3);
    glVertex3i(3, 1.6, -3);
    glEnd();

    //Kursi 3
    //Kaki Belakang
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(-3.5, 3, -3);
    glVertex3i(-2, 3, -3);
    glVertex3i(-2, 0, -3);
    glVertex3i(-3.5, 0, -3);
    glEnd();
    //Kaki Depan
    glBegin(GL_QUADS);
    glColor3ub(160, 82, 45);
    glVertex3i(-3.5, 1.5, -4);
    glVertex3i(-2, 1.5, -4);
    glVertex3i(-2, 0, -4);
    glVertex3i(-3.5, 0, -4);
    glEnd();
    //Alas Kursi
    glBegin(GL_QUADS);
    glColor3ub(47, 79, 79);
    glVertex3i(-3, 1.6, -4.5);
    glVertex3i(-2, 1.6, -4.5);
    glVertex3i(-2, 1.6, -3);
    glVertex3i(-3, 1.6, -3);
    glEnd();

    //Laptop
    glBegin(GL_QUADS);
    glTranslatef(0, 0, 50.0);
    glColor3ub(0, 250, 154);
    glVertex3f(-0.5, 2.2, -6.6);
    glVertex3f(1.0, 2.2, -6.6);
    glVertex3f(1.0, 2, -5.5);
    glVertex3f(-0.5, 2, -5.5);
    glEnd();
    glBegin(GL_QUADS);
    glTranslatef(0, 0, 50.0);
    glColor3ub(0, 128, 128);
    glVertex3f(-0.5, 3, -7.3);
    glVertex3f(1.0, 3, -7.3);
    glVertex3f(1.0, 2, -6.4);
    glVertex3f(-0.5, 2, -6.4);
    glEnd();



    glPopMatrix();
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else {
        mouseDown = false;
    }
}

void mouseMotion(int x, int y) {
    if (mouseDown) {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
    case 'A':
        glTranslatef(5.0, 0.0, 0.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(-5.0, 0.0, 0.0);
        break;
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 5.0);
        break;
    case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -5.0);
        break;
    case 'z':
    case 'Z':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case 'c':
    case 'C':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case 'q':
    case 'Q':
        glRotatef(5, 0.0, 3.0, 0.0);
        break;
    case 'e':
    case 'E':
        glRotatef(5, 0.0, -3.0, 0.0);
        break;
    case '5':
        if (is_depth) {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    Display();
}

void resize(int width, int height) {
    if (height == 0) height = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, width / height, 1.0, 600.0);
    glTranslatef(0.0, -10.0, -50.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("Universitas Indonesia");
    Init();
    glutDisplayFunc(Display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(resize);
    glutMainLoop();
    return 0;
}
