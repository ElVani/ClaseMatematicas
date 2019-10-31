/*
* GRAFICACION - UNIDAD 2
* CLASE MATEMATICAS TEMA FIGURAS GEOMETRICAS
* CARACTERISTICAS DE AREA Y PERIMETRO
* INTEGRANTES:
* IVAN FRANCO DELGADO
* JESUS EDUARDO SOSA DIAZ
* JOSUE TORRES AVALOS
*/

/*
* NOTA IMPORTANTE: ESTE PROGRAMA TRABAJA BAJO EL ESTANDAR DE C++ 14, POR LO QUE SI SE INTENTA CORRER ESTE MISMO PROGRAMA 
* EN UNA VERSION ANTERIOR ALGUNAS FUNCIONES PUEDEN NO DAR EL RESULTADO ESPERADO, SE RECOMIENDA DISCRECION
*/

#include <GL/glut.h> // IMPORTA LA LIBRERIA DE GLUT
#include <cmath>
#include "Vertex.h"
#include "Shapes.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include <string>

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
void defaultValues();

//bool tecleando = false;
//bool termino = true;
int finaliza = 0;
int noValores = 0;

int val1 = 9, val2 = 5;
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
		if (finaliza == 2) {
			//termino = true;
			//tecleando = false;

			defaultValues();
			glutPostRedisplay();
		}
		/*
		EL CHISTE DE ESTO ES QUE, CADA FIGURA TIENE UN NUMERO DE VALORES (CUADRADO USA SOLO UNO, EL LADO, EL TRIANGULO USA DOS, BASE Y ALTURA) Y CUANDO
		LA VARIABLE "FINALIZA" ES MENOR AL NUMERO DE VALORES VA AUMENTANDO, OSEA CAMBIANDO DE VARIABLE "VAL", Y CUANDO LLEGA A SER IGUAL AL NO DE VALORES
		COMO ERA DE ESPERARSE, ES PORQUE YA TERMINASTE TODOS LOS PINSHIS VALORES POSIBLES, ASI QUE LE DICES AL PROGRAMA QUE EL USUARIO YA NO DEBE DE ESTAR
		TECLEANDO NI VRGS (ALTERANDO LOS VALORES DE LAS VARIABLES) Y QUE YA TERMINO DE EDITAR TODAS LAS VARIABLES.
		*/
		break;
	case 99: // c
		//tecleando = true;//
		//termino = false;// pa limpiar use el enter por hueva :v
		break;
	case 49: // 1
		if (options != 0)
		{
			if (finaliza == 0) {
				val1 = 1;
				finaliza++;
				if (options == 2 || options == 4) { finaliza++;	val2 = 1; }
				glutPostRedisplay();
				return;
			}
			if (finaliza == 1) {
				val2 = 1;
				finaliza++;
				glutPostRedisplay();
				return;
			}
		}
		break;
	case 50: // 2
		if (options != 0)
		{
			if (finaliza == 0) {
				val1 = 2;
				finaliza++;
				if (options == 2 || options == 4) { finaliza++; val2 = 2; }
				glutPostRedisplay();
				return;
			}
			if (finaliza == 1) {
				val2 = 2;
				finaliza++;
				glutPostRedisplay();
				return;
			}
		}
		break;
	case 51: // 3
		if (options != 0)
		{
			if (finaliza == 0) {
				val1 = 3;
				finaliza++;
				if (options == 2 || options == 4) { finaliza++; val2 = 3; }
				glutPostRedisplay();
				return;
			}
			if (finaliza == 1) {
				val2 = 3;
				finaliza++;
				glutPostRedisplay();
				return;
			}
		}
		break;
	case 52: // 4
		if (options != 0)
		{
			if (finaliza == 0) {
				val1 = 4;
				finaliza++;
				if (options == 2 || options == 4) { finaliza++; val2 = 4; }
				glutPostRedisplay();
				return;
			}
			if (finaliza == 1) {
				val2 = 4;
				finaliza++;
				glutPostRedisplay();
				return;
			}
		}
		break;
	case 53: // 5
		if (options != 0)
		{
			if (finaliza == 0) {
				val1 = 5;
				finaliza++;
				if (options == 2 || options == 4) { finaliza++; val2 = 5; }
				glutPostRedisplay();
				return;
			}
			if (finaliza == 1) {
				val2 = 5;
				finaliza++;
				glutPostRedisplay();
				return;
			}
		}
		break;
	case 54: // 6
		if (options != 0)
		{
			if (finaliza == 0) {
				val1 = 6;
				finaliza++;
				if (options == 2 || options == 4) { finaliza++; val2 = 6; }
				glutPostRedisplay();
				return;
			}
			if (finaliza == 1) {
				val2 = 6;
				finaliza++;
				glutPostRedisplay();
				return;
			}
		}
		break;
	case 55: // 7
		if (options != 0)
		{
			if (finaliza == 0) {
				val1 = 7;
				finaliza++;
				if (options == 2 || options == 4) { finaliza++; val2 = 7; }
				glutPostRedisplay();
				return;
			}
			if (finaliza == 1) {
				val2 = 7;
				finaliza++;
				glutPostRedisplay();
				return;
			}
		}
		break;
	case 56: // 8
		if (options != 0)
		{
			if (finaliza == 0) {
				val1 = 8;
				finaliza++;
				if (options == 2 || options == 4) { finaliza++; val2 = 8; }
				glutPostRedisplay();
				return;
			}
			if (finaliza == 1) {
				val2 = 8;
				finaliza++;
				glutPostRedisplay();
				return;
			}
		}
		break;
	case 57: // 9
		if (options != 0)
		{
			if (finaliza == 0) {
				val1 = 9;
				finaliza++;
				if (options == 2 || options == 4) { finaliza++; val2 = 9; }
				glutPostRedisplay();
				return;
			}
			if (finaliza == 1) {
				val2 = 9;
				finaliza++;
				glutPostRedisplay();
				return;
			}
		}
		break;
	default:
		break;
	}
}

void defaultValues() {
	val1 = 9;
	val2 = 5;
	finaliza = 0;
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
			defaultValues();
			glutPostRedisplay();
		}
		else if (collisionDetection(2))
		{
			options = 2;
			defaultValues();
			glutPostRedisplay();
		}
		else if (collisionDetection(3))
		{
			options = 3;
			defaultValues();
			glutPostRedisplay();
		}
		else if (collisionDetection(4))
		{
			options = 4;
			defaultValues();
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

	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2f(350, 90);
	writeBitmapString((void*)font, "Instrucciones: De click izquierdo sobre la figura que quiera trabajar y cambie los valores");
	glRasterPos2f(350, 65);
	writeBitmapString((void*)font, "de la figura con los numeros del teclado.");
	switch (options) {
	case 1: // ENTRA AL RECTANGULO
	{
		Rectangle recAr(600, 430, val1 * 20, val2 * 20, 1.0, 0.0, 0.0);
		Rectangle recPer(1000, 430, val1 * 20, val2 * 20, 1.0, 0.0, 0.0);

		glColor3f(1.0, 0.0, 0.0);
		glRasterPos2f(570, 600);
		writeBitmapString((void*)font, "Figura Seleccionada: Rectangulo");
		recAr.drawShapeFill();
		recPer.drawShape();

		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2f(550, 550);
		writeBitmapString((void*)font, "Base:");
		glRasterPos2f(630, 550);
		writeBitmapString((void*)font, std::to_string(val1).c_str());
		glRasterPos2f(720, 550);
		writeBitmapString((void*)font, "Altura:");
		glRasterPos2f(800, 550);
		writeBitmapString((void*)font, std::to_string(val2).c_str());

		glRasterPos2f(500, 300);
		writeBitmapString((void*)font, "Area =");
		glRasterPos2f(580, 300);
		writeBitmapString((void*)font, std::to_string(val1).c_str());
		glRasterPos2f(600, 300);
		writeBitmapString((void*)font, "X");
		glRasterPos2f(630, 300);
		writeBitmapString((void*)font, std::to_string(val2).c_str());
		glRasterPos2f(650, 300);
		writeBitmapString((void*)font, "=");
		glRasterPos2f(670, 300);
		writeBitmapString((void*)font, std::to_string(val1*val2).c_str());


		glRasterPos2f(830, 300);
		writeBitmapString((void*)font, "Perimetro = 2(");
		glRasterPos2f(975, 300);
		writeBitmapString((void*)font, std::to_string(val1).c_str());
		glRasterPos2f(990, 300);
		writeBitmapString((void*)font, ") + 2(");
		glRasterPos2f(1050, 300);
		writeBitmapString((void*)font, std::to_string(val2).c_str());
		glRasterPos2f(1065, 300);
		writeBitmapString((void*)font, ") =");
		glRasterPos2f(1100, 300);
		writeBitmapString((void*)font, std::to_string((2*val1)+(2*val2)).c_str());
		break;
	}
	case 2: // ENTRA AL CUADRADO
	{
		Square sqAr(600, 430, val1 * 20, 0.0, 1.0, 0.0);
		Square sqPer(1000, 430, val1 * 20, 0.0, 1.0, 0.0);

		glColor3f(0.0, 1.0, 0.0);
		glRasterPos2f(570, 600);
		writeBitmapString((void*)font, "Figura Seleccionada: Cuadrado");
		sqAr.drawShapeFill();
		sqPer.drawShape();

		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2f(550, 550);
		writeBitmapString((void*)font, "Lado:");
		glRasterPos2f(630, 550);
		writeBitmapString((void*)font, std::to_string(val1).c_str());

		glRasterPos2f(500, 300);
		writeBitmapString((void*)font, "Area =");
		glRasterPos2f(580, 300);
		writeBitmapString((void*)font, std::to_string(val1).c_str());
		glRasterPos2f(600, 300);
		writeBitmapString((void*)font, "X");
		glRasterPos2f(630, 300);
		writeBitmapString((void*)font, std::to_string(val1).c_str());
		glRasterPos2f(650, 300);
		writeBitmapString((void*)font, "=");
		glRasterPos2f(670, 300);
		writeBitmapString((void*)font, std::to_string(val1 * val1).c_str());

		glRasterPos2f(900, 300);
		writeBitmapString((void*)font, "Perimetro = 4 X");
		glRasterPos2f(1070, 300);
		writeBitmapString((void*)font, std::to_string(val1).c_str());
		glRasterPos2f(1090, 300);
		writeBitmapString((void*)font, "=");
		glRasterPos2f(1120, 300);
		writeBitmapString((void*)font, std::to_string(4*val1).c_str());
		break;
	}
	case 3: // ENTRA AL TRIANGULO
	{
		Triangle trAr(600, 370, val1 * 20, val2 * 20, 0.0, 0.0, 1.0);
		Triangle trPer(1000, 370, val1 * 20, val2 * 20, 0.0, 0.0, 1.0);
		float side = sqrt((.5 * val1) * (.5 * val1) + (val2 * val2));

		glColor3f(0.0, 0.0, 1.0);
		glRasterPos2f(570, 600);
		writeBitmapString((void*)font, "Figura Seleccionada: Triangulo");
		trAr.drawShapeFill();
		trPer.drawShape();

		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2f(550, 550);
		writeBitmapString((void*)font, "Base:");
		glRasterPos2f(630, 550);
		writeBitmapString((void*)font, std::to_string(val1).c_str());
		glRasterPos2f(720, 550);
		writeBitmapString((void*)font, "Altura:");
		glRasterPos2f(800, 550);
		writeBitmapString((void*)font, std::to_string(val2).c_str());
		glRasterPos2f(900, 550);
		writeBitmapString((void*)font, "Lado:");
		glRasterPos2f(980, 550);
		writeBitmapString((void*)font, std::to_string(side).c_str());

		glRasterPos2f(500, 270);
		writeBitmapString((void*)font, "Area = (");
		glRasterPos2f(585, 270);
		writeBitmapString((void*)font, std::to_string(val1).c_str());
		glRasterPos2f(600, 270);
		writeBitmapString((void*)font, "X");
		glRasterPos2f(625, 270);
		writeBitmapString((void*)font, std::to_string(val2).c_str());
		glRasterPos2f(640, 270);
		writeBitmapString((void*)font, ")/2 =");
		glRasterPos2f(700, 270);
		writeBitmapString((void*)font, std::to_string((val1*val2) * .5).c_str());

		glRasterPos2f(850, 270);
		writeBitmapString((void*)font, "Perimetro = 2(Lado) +");
		glRasterPos2f(1080, 270);
		writeBitmapString((void*)font, std::to_string(val1).c_str());
		glRasterPos2f(1100, 270);
		writeBitmapString((void*)font, ")/2 =");
		glRasterPos2f(1150, 270);
		writeBitmapString((void*)font, std::to_string(2*side + val1).c_str());
		break;
	}
	case 4: // ENTRA AL CIRCULO
	{
		Circle cirAr(600, 350, val1 * 20, 1.0, 0.0, 1.0);
		Circle cirPer(1000, 350, val1 * 20, 1.0, 0.0, 1.0);

		glColor3f(1.0, 0.0, 1.0);
		glRasterPos2f(570, 600);
		writeBitmapString((void*)font, "Figura Seleccionada: Circulo");
		cirAr.drawShapeTrig();
		cirPer.drawShape();

		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2f(550, 550);
		writeBitmapString((void*)font, "Radio:");
		glRasterPos2f(630, 550);
		writeBitmapString((void*)font, std::to_string(val1).c_str());
		glRasterPos2f(700, 550);
		writeBitmapString((void*)font, "PI: 3.1416");

		glRasterPos2f(480, 130);
		writeBitmapString((void*)font, "Area= PI X");
		glRasterPos2f(600, 130);
		writeBitmapString((void*)font, std::to_string(val1).c_str());
		glRasterPos2f(615, 130);
		writeBitmapString((void*)font, "X");
		glRasterPos2f(640, 130);
		writeBitmapString((void*)font, std::to_string(val1).c_str());
		glRasterPos2f(660, 130);
		writeBitmapString((void*)font, "=");
		glRasterPos2f(680, 130);
		writeBitmapString((void*)font, std::to_string(3.1416*val1*val1).c_str());

		glRasterPos2f(880, 130);
		writeBitmapString((void*)font, "Perimetro = PI X");
		glRasterPos2f(1060, 130);
		writeBitmapString((void*)font, std::to_string(val1).c_str());
		glRasterPos2f(1080, 130);
		writeBitmapString((void*)font, "=");
		glRasterPos2f(1100, 130);
		writeBitmapString((void*)font, std::to_string(3.1416*val1).c_str());
		break;
	}
	}
	if (finaliza == 2) { finaliza = 0; }
	glutSwapBuffers();
	glFlush();
}
