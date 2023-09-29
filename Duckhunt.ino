int potValX;            // Variable para guardar el valor del potenciómetro X
int potValY;            // Variable para guardar el valor del potenciómetro Y
int mapxantes=0;          //Variable para guardar el estado anterior del Potenciometro mapeado en X
int mapyantes=0;          //Variable para guardar el estado anterior del Potenciometro mapeado en Y
int potValYantes;
int potValXantes;

int potPinX = A1;       // Pin analógico A1 para el potenciómetro X
int potPinY = A2;	// Pin analógico A2 para el potenciómetro Y
int mapx;		//Variable mapeada X para imprimir en Serial 
int mapy;		//Variable mapeada Y para imprimir en Serial 

void setup() {
  Serial.begin(9600);
}
void loop() {
  	
    potValX = analogRead(potPinX);			// Lee el valor del potenciómetro A1 (X)
  	mapx = map(potValX, 0, 1023, 0, 400);
  	potValY = analogRead(potPinY);			// Lee el valor del potenciómetro A2 (Y)
  	mapy=map(potValY,0,1023,0,300);
    	
      Serial.print(mapxantes);
      Serial.print(" ");
      Serial.println(mapyantes);
  
      if(mapx != mapxantes | mapy != mapyantes) {
      	 Serial.println(mapx);
         Serial.print(" ");
         Serial.println(mapy);
    	}
      mapxantes=mapx;
      mapyantes=mapy;
}