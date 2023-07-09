#include<glut.h>
#include<math.h>
#include<stdio.h>


int f=1;
int cc=600,nn=100,ni=800,da=10,ss=200;
int m=700,n=220;
int s=300,v=800;
int spotdisp=1;



float car1Position = 900;  // Initial position of car 1 (top to bottom)
float car2Position = 100; // Initial position of car 2 (bottom to top)
float car3Position = 100; // Initial position of car 3 (left to right)
float car4Position = 900;  // Initial position of car 4 (right to left)
float carSpeed = 0.03;    // Speed at which the cars move
bool deadlockOccurred = false; // Flag indicating whether a deadlock occurred

void update(int value) {
	
        float halfDistance = 500; // Half the distance of the road

    // Stop the cars at the halfway distance
    if (car1Position <= halfDistance+100 && car2Position >= halfDistance-100 && car3Position >= halfDistance-100 && car4Position <= halfDistance+100) {
        carSpeed = 0; // Set the car speed to 0 to stop them
    } else {
        carSpeed = 0.03; // Set the car speed back to the original value
    }

    car1Position -= carSpeed; // Move car 1 downwards
    car2Position += carSpeed; // Move car 2 upwards
    car3Position += carSpeed; // Move car 3 to the right
    car4Position -= carSpeed; // Move car 4 to the left

    // Check for a potential deadlock
    if (car1Position <= halfDistance+100 && car2Position >= halfDistance-100 && car3Position >= halfDistance-100 && car4Position <= halfDistance+100) {
        deadlockOccurred = true;
    } else {
        deadlockOccurred = false;
    }

    glutPostRedisplay(); // Call the display function
    glutTimerFunc(10, update, 0); // Call the update function after 10 milliseconds
	
}

float car1Position1 = 800;  // Initial position of car 1 (top to bottom)
float car2Position1 = 100; // Initial position of car 2 (bottom to top)
float car3Position1 = 100; // Initial position of car 3 (left to right)
float car4Position1 = 800;  // Initial position of car 4 (right to left)
float carSpeed1 = 0.05;
float carSpeed2 = 0.05;
float carSpeed3 = 0.01;
float carSpeed4 = 0.01;
void update1(int value){
	

	if(car1Position1<=50){
		carSpeed1=0.0;
	}
	if(car2Position1>=950){
		carSpeed2=0.0;
	}
	if(car3Position1>=950){
		carSpeed3=0.0;
	}
	if(car4Position1<=50){
		carSpeed4=0.0;
	}
	
	car1Position1 -= carSpeed1; // Move car 1 downwards
    car2Position1 += carSpeed2; // Move car 2 upwards
    car3Position1 += carSpeed3; // Move car 3 to the right
    car4Position1 -= carSpeed4; // Move car 4 to the left

	 glutPostRedisplay();
	 glutTimerFunc(10, update1, 0);
	
}
void renderBitmapString(float x,float y,const char *string)
{
	glRasterPos2f(x,y);   	
	for (int i=0;string[i]!='\0';i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]) ;

}
void BitmapString(float x,float y,const char *string)
{
	const char *c;
	glRasterPos2f(x,y);
	for (c=string;*c !='\0';c++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,*c) ;

}

void renderBitmapString18(float x,float y,const char *string)
{
	glRasterPos2f(x,y);   	
	glLineWidth(5.0);
	for (int i=0;string[i]!='\0';i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]) ;
		//GLUT_BITMAP_9_BY_15

}


// * * line function * * for line in flow chart
void line(int a,int b,int c,int d){
			glColor3f(1,1,1);
    	glBegin(GL_LINES);
    	glVertex2f(a,b);
    	glVertex2f(c,d);
    	glEnd();
			}	
			
			
// * * triangle function * * 
void  arrow(int ta,int tb,int d)
{

		glBegin(GL_POLYGON);
		glColor3ub(254,228,64);
		if(d==0)
		{
			glVertex2f(ta,tb);
			glVertex2f(ta-5,tb+7);
			glVertex2f(ta+5,tb+7);
		}
		else if(d==1)
		{
			glVertex2f(ta,tb);
			glVertex2f(ta+5,tb+7);
			glVertex2f(ta+5,tb-7);
		}
		else if(d==2)
		{
			glVertex2f(ta,tb);
			glVertex2f(ta-5,tb+7);
			glVertex2f(ta-5,tb-7);
		}
		else if(d==3)
		{
			glVertex2f(ta,tb);
			glVertex2f(ta-7,tb+5);
			glVertex2f(ta-7,tb+5);
		}
		glEnd();
}
	void stippleLine() {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(4, 0xAAAA);
    glBegin(GL_LINES);
        glVertex2f(0,500);    
        glVertex2f(500,500);
        glVertex2f(500,500); 
        glVertex2f(1000,500);
    glEnd();                  
    glDisable(GL_LINE_STIPPLE);
}
		
			
void myinit()
{
    	glClearColor(0,0,0,0.0);
     	glMatrixMode(GL_PROJECTION);
    	gluOrtho2D(0,1000,0,1000); 
    	glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

}

void flowrect(int x,int y,int xs,int ys){
	
		glBegin(GL_QUADS);
    	glColor3ub(45,20,44);
   	 glVertex2f(x,y);
   	 glVertex2f(x+xs,y);
   	 glVertex2f(x+xs,y-ys);
   	 glVertex2f(x,y-ys);
   	 glEnd();
}

	

void create_menu(int choice){
        switch(choice){
            case 1:
                f=1;
                break;
            case 2:
                f=2;
                break;
            case 3:
                f=3;
                break;
            case 4:
                f=5;
                break;
			case 5:
				f=6;
				break;
			case 6:
				f=4;
				break;
			case 7:
				f=7;

	
        }
       

}


void keyboard( unsigned char key, int x, int y )
{
  	if(key=='b'||key=='B'){
     	f=1;
  	}
  	if(key=='d'||key=='D'){
  	f=2;
  	}
	if(key=='e'||key=='E'){
	f=6;
	}
	if(key=='i'||key=='I'){
	f=5;
	}
	if(key=='h'||key=='H'){
	f=3;
	}
	if(key=='f'||key=='F'){
	f=4;
	}
	if(key=='n'||key=='N'){
		f=7;
	}

}

void delay(){
int i=3900010;
while(i--);
}


//code addded

//up to here
	

	

    	
void mydisplay(){
	
    	glClear(GL_COLOR_BUFFER_BIT);
    	glBegin(GL_QUADS);
    	glColor3f(0.8,0.5,0.5);
    	glVertex2f(0,0);
		glVertex2f(0,1000);
    	glColor3f(0.3,0.5,0.9);
		glVertex2f(1000,1000);
		glVertex2f(1000,0);
		
    	
    	glEnd();

    	glMatrixMode(GL_MODELVIEW);
    	glLoadIdentity();
    	//glEnd();
    	//glMatrixMode(GL_MODELVIEW);
    	//glLoadIdentity();
    	if(f==1){
			
		//glColor3f(1,1,1);
		//glLineWidth(6);
		//glPushMatrix(); 
		//char str[]="SDM Institute Of Technology, Ujire";
		//glColor3f(1.0,0.7,0.0);
		//glTranslatef(220,930.0,0.0);
		//glScaled(0.16,0.32,0.0);
		//for(int i=0;str[i]!='\0';i++)
		//glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str[i]);
		//glPopMatrix();
		
		
		//glLineWidth(2.5);
		//glPushMatrix(); 
		//char strc[]="Computer Science and Engineering ";
		//glColor3f(0.9,0.8,0.34);
		//glTranslatef(350,870.0,0.0);
		//glScaled(0.095,0.23,0.0);
		//for(int i=0;strc[i]!='\0';i++)
		//glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,strc[i]);
		//glPopMatrix();
		glColor3f(0.7,1,1);
		renderBitmapString(350,850,"SDM INSTITUTE OF TECHNOLOGY, UJIRE");
		glBegin(GL_LINES);
		{
		glVertex2i(350,840);
		glVertex2i(660,840);
		}
		glEnd();
		glFlush();
		glColor3f(0.7,0,0);
    	renderBitmapString(350,770,"COMPUTER SCIENCE AND ENGINEERING");
    	
    	
    	glColor3f(0.6,0,0.6);
    	renderBitmapString(350,700,"Computer Graphics Lab With Mini Project");
    	
    	glColor3f(1,1,0);
    	renderBitmapString(430,600,"* * DEADLOCK IN OS * *");
    	
    	glColor3f(0,0,0);
    	renderBitmapString(200,500,"TEAM MEMBERS :-");
		glColor3f(0,0,0);
		renderBitmapString(150,450,"NAME");
    	glColor3f(1,1,1);
    	renderBitmapString18(150,400,"1) ANISH KUMAR JAIN");
    	glColor3f(1,1,1);
    	renderBitmapString18(150,350,"2) DINESH G HEGDE");
    	glColor3f(1,1,1);
    	renderBitmapString18(150,300,"3) HARSHITHA");
    	glColor3f(1,1,1);
    	renderBitmapString18(150,250,"4) HEMANTH");
		glColor3f(0,0,0);
		glBegin(GL_LINE_LOOP);
		glVertex2i(130,220);
		glVertex2i(130,440);
		glVertex2i(440,440);
		glVertex2i(440,220);
		glEnd();
		glFlush();

		renderBitmapString(350,450,"USN");
    	glColor3f(1,1,1);
    	renderBitmapString18(350,400,"4SU20CS008");
		glColor3f(1,1,1);
    	renderBitmapString18(350,350,"4SU20CS029");
		glColor3f(1,1,1);
    	renderBitmapString18(350,300,"4SU20CS032");
		glColor3f(1,1,1);
    	renderBitmapString18(350,250,"4SU20CS034");

		glColor3f(0,0,0);
    	renderBitmapString(550,500,"GUIDE :-");
    	glColor3f(0,0,0);
    	renderBitmapString18(550,450,"DR. RAGHAVENDRA PATIL G E");
		renderBitmapString18(550,420,"Assistant professor");
		renderBitmapString18(550,390,"Computer Science Department");
    	glColor3f(0.1,0.1,0.1);
    	BitmapString(700,200,"RIGHT CLICK ANYWHERE TO CONTINUE");

		renderBitmapString18(800,650,"PRESS KEYS:");
		glColor3f(0,0.0,0.4);
		renderBitmapString18(800,600,"B return to home page");
		renderBitmapString18(800,560,"I for Introduction");
		renderBitmapString18(800,520,"N for scenario1(NORMAL)");
		renderBitmapString18(800,480,"D for Scenario2(DEADLOCK)");
		renderBitmapString18(800,440,"F for FLOW CHART ");
		renderBitmapString18(800,400,"H for HELP");
		renderBitmapString18(800,360,"E to EXIT");

    	glutPostRedisplay();
   	 }
   	 if(f==2)
	{
	
	
	 
	//code added 
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_QUADS);
    	glColor3f(0,0,0);
    	glVertex2f(0,0);
    	glVertex2f(1000,0);
    	//glColor3f(0.8,0.23,0.7);
    	glVertex2f(1000,1000);
    	glVertex2f(0,1000);
    	glEnd();
    //up to here
		glColor3f(1,1,1);
		renderBitmapString18(50,800,"SCENARIO 2 : DEADLOCK SITUATION");
		glBegin(GL_LINES);
		glColor3f(1,1,1);
		glVertex2f(0,400);
		glVertex2f(400,400);
		glVertex2f(400,400);
		glVertex2f(400,0);

		glVertex2f(600,0);
		glVertex2f(600,400);
		glVertex2f(600,400);
		glVertex2f(1000,400);

		glVertex2f(1000,600);
		glVertex2f(600,600);
		glVertex2f(600,600);
		glVertex2f(600,1000);

		glVertex2f(400,1000);
		glVertex2f(400,600);
		glVertex2f(400,600);
		glVertex2f(0,600);
		glEnd();
		glFlush();

		// Draw the cars
    glColor3f(1.0, 0.0, 0.0); // Set color to red

    // Car 1 (top to bottom)
    glBegin(GL_POLYGON);
    glVertex2f(450, car1Position - 50);
    glVertex2f(550, car1Position - 50);
    glVertex2f(550, car1Position + 50);
    glVertex2f(450, car1Position + 50);
    glEnd();

    // Car 2 (bottom to top)
	
    glBegin(GL_POLYGON);
    glVertex2f(450, car2Position - 50);
    glVertex2f(450, car2Position + 50);
    glVertex2f(550, car2Position + 50);
    glVertex2f(550, car2Position - 50);
    glEnd();

    // Car 3 (left to right)
    glBegin(GL_POLYGON);
    glVertex2f(car3Position - 50, 450);
    glVertex2f(car3Position + 50, 450);
    glVertex2f(car3Position + 50, 550);
    glVertex2f(car3Position - 50, 550);
    glEnd();

    // Car 4 (right to left)
    glBegin(GL_POLYGON);
    glVertex2f(car4Position + 50, 450);
    glVertex2f(car4Position - 50, 450);
    glVertex2f(car4Position - 50, 550);
    glVertex2f(car4Position + 50, 550);
    glEnd();
	glFlush();
	glutTimerFunc(10, update, 0);
    // Display the text popup for deadlock if occurred
    if (deadlockOccurred) {
        glColor3f(1.0, 1.0, 1.0); // Set color to white
        glRasterPos2f(440, 500); // Set the position for the text
        const char* text = "Deadlock occurred!";
        for (const char* c = text; *c != '\0'; ++c) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c); // Display each character of the text
        }
    }

    glFlush();
    
	}
   	 
   	 if(f==3)
	{
		glClear(GL_COLOR_BUFFER_BIT);
    	glBegin(GL_QUADS);
    	glColor3f(0.1,0.256,0.71);
    	glVertex2f(0,0);
    	glVertex2f(1000,0);
    	glColor3f(0.8,0.23,0.7);
    	glVertex2f(1000,1000);
    	glVertex2f(0,1000);
    	glEnd();
	glColor3f(0,1,0);
	renderBitmapString(200,900,"KEYS :-");
	glColor3f(1,1,1);
	
	renderBitmapString(300,800,"Press I for Introduction");
	renderBitmapString(300,750,"Press F for FLOW CHART ");
	renderBitmapString(300,700,"Press N for Scenario1 (Normal situation)");
	renderBitmapString(300,650,"Press D for Scenario2 (Dealock situation)");
	
	
	renderBitmapString(300,600,"Press H for HELP");
	renderBitmapString(300,550,"Press B return to home page");
	renderBitmapString(300,500,"Press E to EXIT");
	}
   	 
   	 if(f==4){
		
   	 	glBegin(GL_QUADS);
    	glColor3f(0,0.015,0.156);
    	glVertex2f(0,0);
    	glVertex2f(1000,0);
    	glColor3f(0,0.305,0.572);
    	glVertex2f(1000,1000);
    	glVertex2f(0,1000);
    	glEnd();
    	
    	
 
    	flowrect(450,900,90,50);//start
		
    	flowrect(450,800,90,50);//intro
		
    	flowrect(450,700,90,50);//about
		
    	flowrect(415,600,160,50);//simulationpage 
		
    	flowrect(250,600,90,50);//help
    	//flowrect(660,600,70,40);
		
    	flowrect(425,500,140,160);
		
    	flowrect(460,200,70,40);//exit 
    	glColor3f(1,0.4,0);
		
    	renderBitmapString(475,867,"START");
		
    	renderBitmapString(475,767,"INTRO");
	
    	renderBitmapString(475,667,"ABOUT");
		
    	renderBitmapString(437,567,"SIMULATION PAGE");
		
    	renderBitmapString(455,460,"SIMULATION");
		
    	renderBitmapString18(458,405,"Process=CAR");
	
    	renderBitmapString18(458,370,"Resource=ROAD");
   
    	renderBitmapString(480,170,"EXIT");
	
    	renderBitmapString(280,567,"HELP");

    	//lines for flowchart
    	glLineWidth(3.0);
    	line(495,850,495,800);
	
    	line(495,750,495,700);
    	line(495,650,495,600);
    	line(495,550,495,500);
    	line(340,575,415,575);
    	line(295,550,295,180);
    	line(295,180,460,180);
    	line(575,575,695,575);
    	line(695,575,695,180);
    	line(695,180,530,180);
    	//line(695,180,695,180);
    	
    	//triangle for arrows in flowchart
    	arrow(495,800,0);delay();
    	arrow(495,700,0);delay();
    	arrow(495,600,0);delay();
    	arrow(340,575,1 );delay();
    	arrow(495,500,0);delay();
    	arrow(460,180,2); //exit left side
    	arrow(530,180,1); //exit right side
    	
    	
  
    	
	}
   	 
   	 
   	 if(f==5)
	{
		glBegin(GL_QUADS);
    	glColor3f(0.2,0.1,0.04);
    	glVertex2f(0,0);
    	glVertex2f(1000,0);
    	glColor3f(0.1,0.3,0.7);
    	glVertex2f(1000,1000);
    	glVertex2f(0,1000);
    	glEnd();

	glColor3f(0,1,1);
	
	glColor3f(1,1,0);
	renderBitmapString(400,900,"DEADLOCK");
	glColor3f(0.4,0,0.2);
	glBegin(GL_LINE_STRIP);
	glVertex2i(380,880);
	glVertex2i(500,880);
	glEnd();
	glFlush();
	glColor3f(1,1,1);
	renderBitmapString18(50,800,"A deadlock is a situation in which two computer programs sharing the same resources.");
	
	renderBitmapString18(50,750,"MUTUAL EXCLUSION: Two or more resources are non-shareable (Only one process can use at a time)");
	glColor3f(0.9,0.4,0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(50,740);
	glVertex2i(200,740);
	glEnd();
	glFlush();
	glColor3f(1,1,1);
	renderBitmapString18(50,700,"HOLD AND WAIT: A process is holding at least one resource and waiting for resources. ");
	glColor3f(0.4,0,0.8);
	glBegin(GL_LINE_STRIP);
	glVertex2i(50,690);
	glVertex2i(200,690);
	glEnd();
	glFlush();
	glColor3f(1,1,1);
	renderBitmapString18(50,650,"NO PREEMPTION: A resource cannot be taken from a process unless the process releases the resource. ");
	glColor3f(0.9,0,0.5);
	glBegin(GL_LINE_STRIP);
	glVertex2i(50,640);
	glVertex2i(200,640);
	glEnd();
	glFlush();
	glColor3f(1,1,1);
	renderBitmapString18(100,585,"CIRCULAR DEPENDENCY");
	renderBitmapString18(50,550,"* Circular dependency in deadlock refers to a situation where multiple processes are waiting for resources held by each other, creating a cycle of dependencies that prevents ");
	
	renderBitmapString18(50,520," any of the processes from making progress, resulting in a deadlock state ");
	renderBitmapString18(50,470,"*A circular dependency occurs when two or more cars depend on each other for resources, creating a deadlock situation. Each car is waiting for a resource held by another car,");
	renderBitmapString18(50,440," forming a cycle of dependencies");
	renderBitmapString18(70,380,"Scene 1: Deadlock Avoidance ");
	renderBitmapString18(70,350,"Simulation: Roads represent resources, and cars are processes. A deadlock avoidance strategy is implemented to prevent deadlock. It manages resource allocation and");
	renderBitmapString18(70,320," requests by cars, ensuring smooth movement towards destinations and avoiding circular wait conditions. ");
	//renderBitmapString18(70,170,"");
	renderBitmapString18(70,260,"Scene 2: Deadlock Occurrence");
	renderBitmapString18(70,230,"Simulation: Conditions deliberately created lead to deadlock. Cars represent processes, and roads are treated as resources. Deliberately designed conditions lead to");
	renderBitmapString18(70,200," deadlock, where each car depends on a resource held by another car, creating a circular dependency. ");
	//renderBitmapString18(70,100," ");
	
	}
	
   	 if(f==6)
	{
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	
	glEnd();
	glColor3f(1,1,1);
	
	renderBitmapString(450,450,"THANK YOU");
	
	}
	 if(f==7){
		 glClear(GL_COLOR_BUFFER_BIT);
	
    
	
	glBegin(GL_QUADS);
    	glColor3f(0,0,0);
    	glVertex2f(0,0);
    	glVertex2f(1000,0);
    	//glColor3f(0.8,0.23,0.7);
    	glVertex2f(1000,1000);
    	glVertex2f(0,1000);
    	glEnd();
    //up to here
		glEnable(GL_LINE_STIPPLE);
	glLineStipple(2,0x00FF);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	{
	glVertex2i(0,500);
	glVertex2i(1000,500);
	glVertex2i(500,1000);
	glVertex2i(500,0);

	}
	glEnd();
	glDisable(GL_LINE_STIPPLE);
	renderBitmapString18(100,870,"SCENARIO 1");
		glBegin(GL_LINES);
		glColor3f(1,1,1);
		glVertex2f(0,350);
		glVertex2f(350,350);
		glVertex2f(350,350);
		glVertex2f(350,0);

		glVertex2f(650,0);
		glVertex2f(650,350);
		glVertex2f(650,350);
		glVertex2f(1000,350);

		glVertex2f(1000,650);
		glVertex2f(650,650);
		glVertex2f(650,650);
		glVertex2f(650,1000);

		glVertex2f(350,1000);
		glVertex2f(350,650);
		glVertex2f(350,650);
		glVertex2f(0,650);
		glEnd();
		glFlush();

		// Draw the cars
    glColor3f(1.0, 0.0, 0.0); // Set color to red

    // Car 1 (top to bottom)
    glBegin(GL_POLYGON);
    glVertex2f(370, car1Position1 - 50);
    glVertex2f(450, car1Position1 - 50);
    glVertex2f(450, car1Position1 + 50);
    glVertex2f(370, car1Position1 + 50);
    glEnd();

    // Car 2 (bottom to top)
	
    glBegin(GL_POLYGON);
    glVertex2f(550, car2Position1 - 50);
    glVertex2f(550, car2Position1 + 50);
    glVertex2f(630, car2Position1 + 50);
    glVertex2f(630, car2Position1 - 50);
    glEnd();

    // Car 3 (left to right)
    glBegin(GL_POLYGON);
    glVertex2f(car3Position1 - 40, 540);
    glVertex2f(car3Position1 + 40, 540);
    glVertex2f(car3Position1 + 40, 630);
    glVertex2f(car3Position1 - 40, 630);
    glEnd();

    // Car 4 (right to left)
    glBegin(GL_POLYGON);
    glVertex2f(car4Position1 + 40, 370);
    glVertex2f(car4Position1 - 40, 370);
    glVertex2f(car4Position1 - 40, 460);
    glVertex2f(car4Position1 + 40, 460);
    glEnd();
	
	glFlush();
	glutTimerFunc(10, update1, 0);
	 }


   	glutSwapBuffers();
	glutPostRedisplay();
	glFlush();
    	
}

    	
    	




int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1940,1000);
	glutInitWindowPosition(0,0);
	
	glutCreateWindow("DEADLOCK IN OS");
	myinit();

	glutCreateMenu(create_menu);
	glutAddMenuEntry("INTRODUCTION",1);
	glutAddMenuEntry("ABOUT",4);
	glutAddMenuEntry("FLOW CHART",6);
	glutAddMenuEntry("HELP KEY",3);
	glutAddMenuEntry("SCENARIO 1",7);
	glutAddMenuEntry("SCENARIO 2(DEADLOCK)",2);
	glutAddMenuEntry("EXIT",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	glutDisplayFunc(mydisplay);
	
	//glutSpecialFunc(SpecialKey);
	glutKeyboardFunc(keyboard);
	
	glClearColor(0.529f, 0.808f, 0.922f, 1.0f);             
   

	glutMainLoop();
	return 0;
}

