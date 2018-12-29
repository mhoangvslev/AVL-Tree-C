#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "TreeRB.h"


ARB root = NULL;


//fonction de dessin pour les cercles qui representeront les noeuds
void drawCircle(float segments, float radius, float sx, float sy)
{
    float theta = 2 * 3.1415926 / segments;
    float tan_factor = tanf(theta);
    float radial_factor = cosf(theta);
    float x = radius;
    float y = 0;

    int cache_pt = 0;
    double cache_x;
    double cache_y;

    glBegin(GL_LINES);
    for (int i = 0; i < segments; i++)
    {
        if(!cache_pt)
        {
            cache_x = x+sx;
            cache_y = y+sy;
            cache_pt = 1;
        }
        else
        {
            glVertex2f(x + sx, y + sy);
            cache_x = x+sx;
            cache_y = y+sy;
        }
        float tx = -y;
        float ty = x;
        x += tx * tan_factor;
        y += ty * tan_factor;
        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
    glFlush();
}


//fonction de dessin des branches
void draw_line(float x1,float y1,float x2, float y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
    glFlush();
}


//pour afficher la valeur du noeuf
void draw_text(char* text,float x, float y)
{
    GLvoid *font_style = GLUT_BITMAP_TIMES_ROMAN_24;
    glRasterPos3f(x, y, 0);
    for (int i = 0; text[i] != '\0'; i++)
    {
        glutBitmapCharacter(font_style, text[i]);
    }
}


//dessin de l'abre
void drawARB(ARB arbre,float x1,float y1,int level)
{
    if (arbre==NULL)
    {
        return;
    }
    float segments = 25;
    float radius = 0.05;
    float left_angle = 235; //angle du lien entre le noeud et son fils gauche
    float right_angle = 125; // de même, côté droit
    float branch_length =0.4; //taille de la branche
    float angle_change = 20;

    if(arbre->couleur == RED)
    {
        glColor3f(1.0,0.0,0.0);//on dessine le noeuf en fonction de sa couleur
    }
    else
    {
        glColor3f(0.0,0.0,0.0);
    }

    drawCircle(segments,radius,x1,y1);//on dessine le noeud courant

    char buff[5];
    snprintf(buff,10,"%d",arbre->value);//recup la valeur
    draw_text(buff,x1,y1); //pour la dessiner

    if(arbre->childLeft)   //côté gauche, recursive
    {
        float angle = left_angle - level*angle_change;
        double radian = angle*3.14/180;
        float m = (double)tan((double)radian);
        float x2 = x1 + branch_length * sin((double) radian);//on calcule l'emplacement
        float y2 = y1 + branch_length * cos((double) radian); // du nouveau noeud a dessiner
        drawARB(arbre->childLeft,x2,y2,level+1);
        glColor3f(0.0,0.0,0.0);
        draw_line(x1,y1,x2,y2);
    }
    if(arbre->childRight)   //côté droit, recursive
    {
        float angle = right_angle + level*angle_change;
        float radian = angle*3.14/180;
        float m = (double)tan((double)radian);
        float x2 = x1 + branch_length * sin((double) radian);//on calcule l'emplacement
        float y2 = y1 + branch_length * cos((double) radian);// du nouveau noeud a dessiner
        drawARB(arbre->childRight,x2,y2,level+1);
        glColor3f(0.0,0.0,0.0);
        draw_line(x1,y1,x2,y2);
    }

}


void reshape(int w,int l)
{
    glViewport(0,0,w,l);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if ( w > l )
        glOrtho((float) -w/l,(float) w/l,
                -1.0,1.0,
                -1.0,1.0);
    else
        glOrtho(-1.0,1.0,
                (float) -l/w,(float) l/w,
                -1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(2.0);
    drawARB(root,0,0.90,0);
    glFlush();
}


int main(int argc,char **argv)
{
    bool a = true;
    while(a)
    {
        int choix;
        int val;
        printf("\nBienvenue\n");
        printf("---- Selectionnez une action ----\n");
        printf("|1 - Insérer une valeur          |\n");
        printf("|2 - Supprimer une valeur        |\n");
        printf("|3 - Quitter et afficher l'arbre |\n");
        printf("----------------------------------\n");
        printf("\n Votre choix (numero menu) :  ");
        scanf("%i", &choix);

        switch(choix)
        {
        case 1 :
            printf("--> Entrez une valeur à insérer :  ");
            scanf("%i", &val);
            root = Ajouter(root,val);
            break;
        case 2 :
            if(root!=NULL)
            {
                printf("--> Entrez une valeur à supprimer :  ");
                scanf("%i", &val);
                Supprimer(root,val);
            }
            else
            {
                printf("Commencez par ajouter des noeuds !\n");
            }
            break;
        case 3 :
            a = false;
            break;
        default :
            printf("Opération inconnue\n");
        }
    }

    // Afficher arbre dans le console
    afficherARBTopo(root, 2);

    // Avec GNU plot
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Arbre Rouge-Noir");
    glutDisplayFunc(display);

    glutReshapeFunc(reshape);
    glutMainLoop();
    return(0);
}

/*
fprintf(gnuplotPipe, "plot '-' \n");
int i;

for (int i = 0; i < NUM_POINTS; i++)
{
    fprintf(gnuplotPipe, "%lf %lf\n", xvals[i], yvals[i]);
}

fprintf(gnuplotPipe, "e");
*/
