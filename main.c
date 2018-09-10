#include <GL/glut.h>
#include <stdio.h>
//Exercício Pedro Lopes Perozin RA: 1648730
int rotation = 0;
int translation = 1;

float tx = 0;
float ty = 0;

int rx = 5;
int ry = 5;

int angulo = 0;


void drawSquare()
{                             //desenha o quadrado
    glColor3f(1.0, 0.0, 0.0); //altera o atributo de cor
    glBegin(GL_POLYGON);      //desenha uma linha
    glVertex2i(0, 0);         //P1 origem
    glVertex2i(10, 0);        //P2 x = 10 y = 0
    glVertex2i(10, 10);       //P3 x = 10 y = 10
    glVertex2i(0, 10);        //P4 x = 0 y = 10
    glEnd();
}

void selectedKey(unsigned char key, int x, int y)
{ //função de reconhecimento de tecla selecionada Ex: T ou R

    switch (key)
    {
    case 't':
        translation = 1;
        rotation = 0;
        
        break;

    case 'r':
        rotation = 1;
        translation = 0;
        
        break;
    }
     glutPostRedisplay();
}
//selectedDirection
void selectedDirection(int key, int x, int y)
{

    switch (key)
    {
    case GLUT_KEY_LEFT:
        if (translation == 1)
        {
            tx--;
            break;
        }
        if (rotation == 1)
        {
            angulo ++ ;
            break;
        }
        break;

    case GLUT_KEY_RIGHT:
        if (translation == 1)
        {
            tx++;
            break;
        }
        if (rotation == 1)
        {
            angulo --;
            
            break;
        }
        break;

    case GLUT_KEY_UP:
        if (translation == 1)
        {
            ty++;
            break;
        }
        if (rotation == 1)
        {
            break;
        }

    case GLUT_KEY_DOWN:
        if (translation == 1)
        {
            ty--;
            break;
        }
        if (rotation == 1)
        {
            break;
        }
    }
    glutPostRedisplay();
}

//void glutKeyboardFunc(void (*func)(unsigned char key, int x, int y));

//void glutSpecialFunc(void (*func)(int key, int x, int y));

int init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);   //define a cor de fundo
    glMatrixMode(GL_PROJECTION);        //carrega a matriz de projeção
    gluOrtho2D(0.0, 100.0, 0.0, 100.0); //define projeção ortogonal 2D
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); //desenha o fundo (limpa a janela)

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(tx, ty, 0);

    glTranslatef(rx,ry,0);
    glRotatef(angulo,0,0,1);
    glTranslatef(-(rx),-(ry),0);
    drawSquare();


    glFlush(); //desenha os comandos não executados
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);                       //inicializa o GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //configura o modo de display
    glutInitWindowPosition(200, 0);
    glutInitWindowSize(500, 500);                //configura a largura e altura da janela de exibição
    glutCreateWindow("Exercicio bonus 1"); //cria a janela de exibição

    init(); //executa função de inicialização

    glutDisplayFunc(display); //estabelece a função "display" como a função callback de exibição.
    
    glutKeyboardFunc(selectedKey);
    glutSpecialFunc(selectedDirection);

    
    glutMainLoop(); //mostre tudo e espere
    rx = tx + 5;
    ry = ty + 5;

    return 0;
}
