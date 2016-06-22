#define dirF 7
#define esqF 6
#define dirT 5
#define esqT 8

Class Batmovel {
  struct comandoEl { char c; float temp; }
  typedef comandoEl* comando;
  public:
    Batmovel();
    ~Batmovel();
    void move(comandoEl);
    void criarComando(String);
    void rodar(String, bool ciclo);
    void parar();
  private:
    String abrirComando(comando);
    comando* comandos;
    bool modoProgramacao;
    bool flagParada;
}

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(dirF, OUTPUT);     
  pinMode(esqF, OUTPUT);     
  pinMode(dirT, OUTPUT);     
  pinMode(esqT, OUTPUT);
  digitalWrite(dirF, HIGH);
  digitalWrite(esqF, HIGH);
  digitalWrite(dirT, HIGH);
  digitalWrite(esqT, HIGH);
  Serial.begin(9600);
}

void lerComando() {
   
}

void move (char c, float temp) {
      temp *= 1000;
Serial.println(temp);
       switch(c){
          case 'e':
          {
            digitalWrite(dirF, LOW);
            delay(temp);
            digitalWrite(dirF, HIGH);
            break;
          }
          case 'd':
          {
            digitalWrite(esqF, LOW);
            delay(temp);
            digitalWrite(esqF, HIGH);
            break;
          }
          case 'E':
          {
            digitalWrite(dirF, LOW);
            digitalWrite(esqT, LOW);
            delay(temp);
            digitalWrite(dirF, HIGH);
            digitalWrite(esqT, HIGH);
            break;
          }
          case 'D':
          {
            digitalWrite(esqF, LOW);
            digitalWrite(dirT, LOW);
            delay(temp);
            digitalWrite(esqF, HIGH);
            digitalWrite(dirT, HIGH);
            break;
          }
          case 'f':
          case 'F':
          {
            digitalWrite(esqF, LOW);
            digitalWrite(dirF, LOW);
            delay(temp);
            digitalWrite(esqF, HIGH);
            digitalWrite(dirF, HIGH);
            break;
          }
          case 'p':
          case 'P':
          {
            digitalWrite(esqT, LOW);
            digitalWrite(dirT, LOW);
            delay(temp);
            digitalWrite(esqT, HIGH);
            digitalWrite(dirT, HIGH);
            break;
          }
          default:
          {
            Serial.println("Comando nao identificado.");
            break;
          }
       }
}

// the loop routine runs over and over again forever:
bool func;
String str;
void loop() {
  if(func){
    move( str[0], (str.substring(2, (str.length() - 1) )).toFloat() );
    func = false;
  }
}

void serialEvent() {
  if (Serial.available()) {
    str = Serial.readString();
    func = true;
  }
}
