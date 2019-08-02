#include <windows.h>
#include <GL\glut.h>
#include <math.h>

void render(void);
void lineDDA(int,int,int,int);
void Bresenham(int,int,int,int);
void midPoint(int,int,int);
void drawPixel(int, int);
void plot(int,int);

int main(int argc, char **argv){

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(1080, 612);
  glutInitWindowPosition(140, 110);
  glutCreateWindow("Shaheed Minar");

  glutDisplayFunc(render);

  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0.109, 0.133, 0.156, 1.0);
  glPointSize(4.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 1080.0, 0.0, 612.0);

  glutMainLoop();
  return 0;
}
void render(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /** CIRCLE */
    int radius = 112;
    while(radius > 0 ){
        midPoint(572,350,radius);
        radius -=4;
    }

    /** FLOOR */
    lineDDA(216,180,934,180);
    lineDDA(168,64,982,64);
    Bresenham(168,216,64,180);
    Bresenham(982,934,64,180);

    /** MIDDLE PILLER-ONE */
    Bresenham(480,520,148,148);
    Bresenham(480,480,148,430);
    Bresenham(480,520,430,430);
    Bresenham(520,520,148,430);
    /* UPPER PART */
    Bresenham(480,472,430,510);
    Bresenham(520,512,430,510);
    Bresenham(472,512,510,510);
    /** END */

    /** MIDDLE PILLER-TWO */
    Bresenham(552,592,148,148);
    Bresenham(552,552,148,430);
    Bresenham(552,592,430,430);
    Bresenham(592,592,148,430);
    /* UPPER PART */
    Bresenham(552,544,430,510);
    Bresenham(592,600,430,510);
    Bresenham(544,600,510,510);
    /** END MIDDLE PILLER-TWO */


    /** MIDDLE PILLER-THREE */
    Bresenham(624,664,148,148);
    Bresenham(624,624,148,430);
    Bresenham(624,664,430,430);
    Bresenham(664,664,148,430);
    /* UPPER PART */
    Bresenham(624,632,430,510);
    Bresenham(664,672,430,510);
    Bresenham(632,672,510,510);
    /** END */

    /** LEFT PILLER */
    Bresenham(394,432,148,148);
    Bresenham(394,394,148,436);
    Bresenham(432,432,148,446);
    Bresenham(394,432,436,446);

    /** LEFT-MOST PILLER */
    Bresenham(316,352,148,148);
    Bresenham(316,316,148,340);
    Bresenham(352,352,148,350);
    Bresenham(316,352,340,350);

    /** RIGHT PILLER */
    Bresenham(712,750,148,148);
    Bresenham(712,712,148,446);
    Bresenham(750,750,148,436);
    Bresenham(750,712,436,446);

    /** RIGHT-MOST PILLER */
    Bresenham(798,834,148,148);
    Bresenham(798,798,148,350);
    Bresenham(834,834,148,340);
    Bresenham(834,798,340,350);

    lineDDA(316,148,834,148);

  glFlush();
  glutSwapBuffers();
}
void drawPixel(int x, int y) {
	glBegin(GL_POINTS);
	glColor3f(0.8, 0.8, 0.8);
	glVertex2i(x, y);
	glEnd();
}
void plot(int x, int y){
	glBegin(GL_POINTS);
	glColor3f(0.988, 0.427, 0.427);
	glVertex2i(x, y);
	glEnd();
}
void lineDDA(int X1,int Y1,int X2,int Y2){
  int dx=(X2-X1);
  int dy=(Y2-Y1);

  double steps;
  float xInc,yInc,x=X1,y=Y1;

  steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));

  xInc=dx/(float)steps;
  yInc=dy/(float)steps;

  glVertex2i(x,y);

  int k;
  for(k=0;k<steps;k++){
    x+=xInc;
    y+=yInc;
    drawPixel(x, y);
  }
  glFlush();
}
void Bresenham(int x1, int x2, int y1, int y2) {
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		drawPixel(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			drawPixel(x, y);
		}
	} else {
		drawPixel(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			drawPixel(x, y);
		}
	}
}
void midPoint(int xCor,int yCor,int r){
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	plot(x+xCor, y+yCor);
	while (y > x){
		if (decision < 0){
			x++;decision += 2*x+1;
		}
		else{
			y--;x++;decision += 2*(x-y)+1;
		}
		plot(x+xCor, y+yCor);
		plot(x+xCor, -y+yCor);
		plot(-x+xCor, y+yCor);
		plot(-x+xCor, -y+yCor);
		plot(y+xCor,x+yCor);
		plot(-y+xCor, x+yCor);
		plot(y+xCor, -x+yCor);
		plot(-y+xCor, -x+yCor);
	}

}
