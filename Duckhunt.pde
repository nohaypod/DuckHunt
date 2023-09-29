import processing.serial.*;
Serial comunicacionarduino;
float patoX,patoY;
String Mensaje;
String[] Dato;
int x,y;

void setup(){
  
  size( 500,500 );
  patoX = random(width);
  patoY = random(height);
  patoX=int(patoX); //Casteo X
  patoY=int(patoY); //Casteo Y
  comunicacionarduino = new Serial(this,"COM4",9600);
  comunicacionarduino.bufferUntil('\n');
}

void draw(){
  while(comunicacionarduino.available()>0) {
    String inByte = comunicacionarduino.readString();
    delay(100);
    Dato = splitTokens(inByte);
    printArray(Dato);
    println(Dato[0]);
    println(Dato[1]);
    x = int(Dato[0]);
    y = int(Dato[1]);
  }
  background( 255 ); //restablece cada vez el background
  strokeWeight(5); //ancho de línea
  line( x-10, y, x+10, y ); //Dibuja un eje de la mira
  line( x, y-10, x, y+10 ); //Dibuja el otro eje de la mirillia
  if(patoX==x&patoY==y)
    {fill(255,255,255);}
  else {fill( 120,200, 40 );}
  ellipse(  patoX, patoY, 30,30 );
  }
