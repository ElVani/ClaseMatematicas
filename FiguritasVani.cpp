/*
 * GRAFICACION - UNIDAD 2
 * CLASE MATEMATICAS TEMA FIGURAS GEOMETRICAS
 * CARACTERISTICAS DE AREA Y PERIMETRO
 * INTEGRANTES:
 * IVAN FRANCO DELGADO
 * JESUS EDUARDO SOSA DIAZ
 * JOSUE TORRES AVALOS
 */

#include <GL/glut.h> // IMPORTA LA LIBRERIA DE GLUT
#include <cmath>
#include "Vertex.h"
#include "Shapes.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"


 // VALORES UTILIZADOS PARA EL TAMANO DE LA
 // PANTALLA DEFINIENDO ALTO Y ANCHO
#define HEIGHT 720
#define WIDTH 1280

 // PROTOTIPOS DE FUNCIONES
void initializer(void);
void userInterface(void);
void keyInput(unsigned char, int, int);
void mouseControl(int, int, int, int);
bool collisionDetection(int);
bool isInside(int, int, int, int, int, int);
											
bool tecleando = false;
bool termino = true;
int finaliza = 1;
int noValores = 1;

int val1, val2 = 0;
Vertex mouseClic; // ALMACENA EL LUGAR DONDE HACE CLIC
int options = 0;
static long font = (long)GLUT_BITMAP_TIMES_ROMAN_24;
Rectangle rec(200, 650, 200, 100, 1.0, 0.0, 0.0);
Square sq(200, 480, 120, 0.0, 1.0, 0.0);
Triangle tr(200, 280, 150, 120, 0.0, 0.0, 1.0);
Circle cir(200, 100, 75, 1.0, 0.0, 1.0);



int main(int argc, char* argv[]) {
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT); // ESTABLECE EL TAMANO DE LA VENTANA
	glutCreateWindow("FIGURAS GEOMETRICAS");

	initializer(); // INICIALIZA LA VENTANA

	glutDisplayFunc(userInterface); // ACTUALIZA LA PANTALLA DE TRAZADO

	glutKeyboardFunc(keyInput); // CAPTURA LOS TECLAZOS
	glutMouseFunc(mouseControl); // CAPTURA LOS CLICS

	glutMainLoop(); // GENERA EL LOOP

	return 0;
}

/*
* FUNCION QUE TOMA EL VALOR DE LA FUENTE Y UNA CADENA COMO PARAMETRO
* RECORRE LA CADENA CARACTER POR CARACTER HASTA QUE LLEGA AL PUNTO FINAL
* IMPRIME EL CARACTER UTILIZANDO EL FONT
*/
void writeBitmapString(void* font, const char* string)
{
	const char* c;
	for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

void keyInput(unsigned char key, int x, int y)
{
	/*
	UTILIZO LAS BANDERAS TECLEANDO PARA SABER SI ESTA TECLEANDO (OBVIAMENTE) Y TERMINO PARA SABER SI YA TERMINO DE ESCRIBIR TODOS LOS VALORES
	FINALIZA ES COMO UN APUNTADOR QUE TE DICE QUE VALOR EDITA
	*/
	switch (key)
	{
	case 27: // esc key
		exit(0);
	case 13: // enter
		if (finaliza < noValores) {
			finaliza++;
		}
		if (finaliza == noValores) {
			termino = true;
			tecleando = false;
			finaliza = 1;
		}
		/*
		EL CHISTE DE ESTO ES QUE, CADA FIGURA TIENE UN NUMERO DE VALORES (CUADRADO USA SOLO UNO, EL LADO, EL TRIANGULO USA DOS, BASE Y ALTURA) Y CUANDO
		LA VARIABLE "FINALIZA" ES MENOR AL NUMERO DE VALORES VA AUMENTANDO, OSEA CAMBIANDO DE VARIABLE "VAL", Y CUANDO LLEGA A SER IGUAL AL NO DE VALORES
		COMO ERA DE ESPERARSE, ES PORQUE YA TERMINASTE TODOS LOS PINSHIS VALORES POSIBLES, ASI QUE LE DICES AL PROGRAMA QUE EL USUARIO YA NO DEBE DE ESTAR
		TECLEANDO NI VRGS (ALTERANDO LOS VALORES DE LAS VARIABLES) Y QUE YA TERMINO DE EDITAR TODAS LAS VARIABLES.
		
		*/
		break;
	case 99: // c
		tecleando = true;
		termino = false;
		break;
	case 48: // 0
		if (tecleando && termino == false) {
			if (finaliza == 0) {
				val1 = 0;
			}
			if (finaliza == 1) {
				val2 = 0;
			}
		}
		break;
	case 49: // 1
		if (tecleando && termino == false) {
			if (finaliza == 0) {
				val1 = 1;
			}
			if (finaliza == 1) {
				val2 = 1;
			}
		}
		break;
	case 50: // 2
		if (tecleando && termino == false) {
			if (finaliza == 0) {
				val1 = 2;
			}
			if (finaliza == 1) {
				val2 = 2;
			}
		}
		break;
	case 51: // 3
		if (tecleando && termino == false) {
			if (finaliza == 0) {
				val1 = 3;
			}
			if (finaliza == 1) {
				val2 = 3;
			}
		}
		break;
	case 52: // 4
		if (tecleando && termino == false) {
			if (finaliza == 0) {
				val1 = 4;
			}
			if (finaliza == 1) {
				val2 = 4;
			}
		}
		break;
	case 53: // 5
		if (tecleando && termino == false) {
			if (finaliza == 0) {
				val1 = 5;
			}
			if (finaliza == 1) {
				val2 = 5;
			}
		}
		break;
	case 54: // 6
		if (tecleando && termino == false) {
			if (finaliza == 0) {
				val1 = 6;
			}
			if (finaliza == 1) {
				val2 = 6;
			}
		}
		break;
	case 55: // 7
		if (tecleando && termino == false) {
			if (finaliza == 0) {
				val1 = 7;
			}
			if (finaliza == 1) {
				val2 = 7;
			}
		}
		break;
	case 56: // 8
		if (tecleando && termino == false) {
			if (finaliza == 0) {
				val1 = 8;
			}
			if (finaliza == 1) {
				val2 = 8;
			}
		}
		break;
	case 57: // 9
		if (tecleando && termino == false) {
			if (finaliza == 0) {
				val1 = 9;
			}
			if (finaliza == 1) {
				val2 = 9;
			}
		}
		break;
	default:
		break;
	}
}

/*
 * FUNCION QUE CAPTURA LOS CLIC DEL RATON
 */
void mouseControl(int button, int state, int x, int y)
{
	// BOTON IZQUIERDO PRESIONADO
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseClic.setX(x); // ALMACENA LAS COORDENADAS DEL CLIC
		mouseClic.setY(y);

		if (collisionDetection(1))
		{
			options = 1;
			glutPostRedisplay();
		}
		else if (collisionDetection(2))
		{
			options = 2;
			glutPostRedisplay();
		}
		else if (collisionDetection(3))
		{
			options = 3;
			glutPostRedisplay();
		}
		else if (collisionDetection(4))
		{
			options = 4;
			glutPostRedisplay();
		}
	}
}

bool collisionDetection(int figure) {
	switch (figure) // DEPENDIENDO LA FIGURA SELECCIONADA HACE LA COMPARACION
	{
	case 1: {
		float x1 = rec.getOrigin().getX() - (rec.getBase() / 2), x2 = x1 + rec.getBase();
		float y1 = HEIGHT - (rec.getOrigin().getY() - (rec.getHeight() / 2)), y2 = y1 - rec.getHeight();
		// COMPARA LAS COORDENADAS EN EJE X E Y
		bool collisionX = (x1 <= mouseClic.getX() && x2 >= mouseClic.getX());
		bool collisionY = (y1 >= mouseClic.getY() && y2 <= mouseClic.getY());
		return collisionX && collisionY;
	}
	case 2: {
		float x1 = sq.getOrigin().getX() - (sq.getSide() / 2), x2 = x1 + sq.getSide();
		float y1 = HEIGHT - (sq.getOrigin().getY() - (sq.getSide() / 2)), y2 = y1 - sq.getSide();
		bool collisionX = (x1 <= mouseClic.getX() && x2 >= mouseClic.getX());
		bool collisionY = (y1 >= mouseClic.getY() && y2 <= mouseClic.getY());
		return collisionX && collisionY;
	}
	case 3: {
		Vertex aux_pos = tr.getOrigin();
		int x1 = aux_pos.getX() - (tr.getBase() / 2), y1 = aux_pos.getY() - (tr.getHeight() / 3);
		int x2 = aux_pos.getX(), y2 = aux_pos.getY() + ((tr.getHeight() / 3) * 2);
		int x3 = aux_pos.getX() + (tr.getBase() / 2), y3 = aux_pos.getY() - (tr.getHeight() / 3);

		return isInside(x1, y1, x2, y2, x3, y3);
	}
	case 4: {
		Vertex aux_pos = cir.getOrigin();
		return sqrt((mouseClic.getX() - aux_pos.getX()) * (mouseClic.getX() - aux_pos.getX()) +
			(HEIGHT - mouseClic.getY() - aux_pos.getY()) * (HEIGHT - mouseClic.getY() - aux_pos.getY())) < cir.getRadius();
	}
	default:
		return false;
	}
}

/*
* CALCULA EL AREA PARA LOS VERTICES DADOS
*/
float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

/*
* DETERMINA SI EL PUNTO ESTA DENTRO DEL TRIANGULO EN CUALQUIERA DE LAS 3 AREAS
*/
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3)
{
	float A = area(x1, y1, x2, y2, x3, y3);
	float A1 = area(mouseClic.getX(), HEIGHT - mouseClic.getY(), x2, y2, x3, y3);
	float A2 = area(x1, y1, mouseClic.getX(), HEIGHT - mouseClic.getY(), x3, y3);
	float A3 = area(x1, y1, x2, y2, mouseClic.getX(), HEIGHT - mouseClic.getY());

	return (A == A1 + A2 + A3);
}

void initializer(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0); // COLOR CANVAS
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT); // TAMANO DE MANTA
}

/*
* INTERFAZ DE USUARIO O PANTALLA DONDE ES PINTADO TODO
* CADA VEZ QUE ES LLAMADA, SE LIMPIA LA PANTALLA
*/
void userInterface(void)
{
	Rectangle _rec(200, 650, 200, 100, 1.0, 0.0, 0.0);
	Square _sq(200, 480, 120, 0.0, 1.0, 0.0);
	Triangle _tr(200, 280, 150, 120, 0.0, 0.0, 1.0);
	Circle _cir(200, 100, 75, 1.0, 0.0, 1.0);

	Rectangle recAr(600, 400, 200, 100, 1.0, 0.0, 0.0);
	Rectangle recPer(1000, 400, 200, 100, 1.0, 0.0, 0.0);
	
	Square sqAr(600, 400, 120, 0.0, 1.0, 0.0);
	Square sqPer(1000, 400, 120, 0.0, 1.0, 0.0);

	Triangle trAr(600, 400, 150, 120, 0.0, 0.0, 1.0);
	Triangle trPer(1000, 400, 150, 120, 0.0, 0.0, 1.0);

	Circle cirAr(600, 400, 75, 1.0, 0.0, 1.0);
	Circle cirPer(1000, 400, 75, 1.0, 0.0, 1.0);

	recAr.setOrigin(700, 780);
	//recPer.setOrigin(600, 780);


	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(500, 680);
	writeBitmapString((void*)font, "Clase Matematicas Tema Figuras Geometricas");
	glRasterPos2f(570, 640);
	writeBitmapString((void*)font, "Caracteristicas de Area y Perimetro");

	// SIEMPRE PINTA LAS FIGURAS GEOMETRICAS
	rec.drawShapeFill();
	sq.drawShapeFill();
	tr.drawShapeFill();
	cir.drawShapeTrig();

	

	switch (options) {
	case 1: // ENTRA AL RECTANGULO
	{
		noValores = 2;
		val1 = _rec.getBase();
		val2 = _rec.getHeight();
		
		glColor3f(1.0, 0.0, 0.0);
		glRasterPos2f(570, 600);
		writeBitmapString((void*)font, "Figura Seleccionada: Rectangulo");
		recAr.drawShapeFill();
		recPer.drawShape();

		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2f(550, 500);
		writeBitmapString((void*)font, "Base:");
		glRasterPos2f(720, 500);
		writeBitmapString((void*)font, "Altura:");

		glRasterPos2f(550, 300);
		writeBitmapString((void*)font, "Area= algo X algo");
		glRasterPos2f(900, 300);
		writeBitmapString((void*)font, "Perimetro = 2algo + 2algo");
		break;
	}
	case 2: // ENTRA AL CUADRADO
	{
		noValores = 1;
		val1 = _sq.getSide();
		glColor3f(0.0, 1.0, 0.0);
		glRasterPos2f(570, 600);
		writeBitmapString((void*)font, "Figura Seleccionada: Cuadrado");
		sqAr.drawShapeFill();
		sqPer.drawShape();

		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2f(550, 500);
		writeBitmapString((void*)font, "Lado:");

		glRasterPos2f(550, 300);
		writeBitmapString((void*)font, "Area= lado X lado");
		glRasterPos2f(900, 300);
		writeBitmapString((void*)font, "Perimetro = 4lado");
		break;
	}
	case 3: // ENTRA AL TRIANGULO
	{
		noValores = 2;
		val1 = _tr.getBase();
		val2 = _tr.getHeight();
		glColor3f(0.0, 0.0, 1.0);
		glRasterPos2f(570, 600);
		writeBitmapString((void*)font, "Figura Seleccionada: Triangulo");
		trAr.drawShapeFill();
		trPer.drawShape();

		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2f(550, 500);
		writeBitmapString((void*)font, "Base:");
		glRasterPos2f(720, 500);
		writeBitmapString((void*)font, "Altura:");

		glRasterPos2f(550, 300);
		writeBitmapString((void*)font, "Area= (algo X algo)/2");
		glRasterPos2f(900, 300);
		writeBitmapString((void*)font, "Perimetro = 3algo");
		break;
	}
	case 4: // ENTRA AL CIRCULO
	{
		noValores = 1;
		val1 = _cir.getRadius();
		glColor3f(1.0, 0.0, 1.0);
		glRasterPos2f(570, 600);
		writeBitmapString((void*)font, "Figura Seleccionada: Circulo");
		cirAr.drawShapeTrig();
		cirPer.drawShape();

		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2f(550, 500);
		writeBitmapString((void*)font, "Radio:");

		glRasterPos2f(550, 300);
		writeBitmapString((void*)font, "Area= PI X radio X radio");
		glRasterPos2f(900, 300);
		writeBitmapString((void*)font, "Perimetro = PI X radio");
		break;
	}
	}

	glutSwapBuffers();
	glFlush();
}
