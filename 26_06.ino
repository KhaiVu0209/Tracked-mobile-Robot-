// ----- Cấu hình Encoder -----
#define ENC_A_R 2     // Pha A Motor phải 
#define ENC_A_L 3     // Pha A Motor trái

// ----- Motor phải -----
#define IN1 42
#define IN2 40
#define ENA 44

// ----- Motor trái -----
#define IN3 41
#define IN4 43
#define ENB 45

// ----- Biến toàn cục -----
volatile long xungPhai = 0;
volatile long xungTrai = 0;

int ppr = 400;              
int soVong = 5;             
long mucTieu = soVong * ppr;

// ----- Ngắt encoder -----
void tangXungPhai() {
  xungPhai++;
}

void tangXungTrai() {
  xungTrai++;
}

void setup() {
  Serial.begin(9600);

  // Motor phải
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  // Motor trái
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Encoder
  pinMode(ENC_A_R, INPUT_PULLUP);
  pinMode(ENC_A_L, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ENC_A_R), tangXungPhai, RISING);
  attachInterrupt(digitalPinToInterrupt(ENC_A_L), tangXungTrai, RISING);

  // Quay thuận cả 2 motor
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 160);
  analogWrite(ENB, 150);
  Serial.println("Bat dau quay...");
}

void loop() {
  Serial.print("Phai: ");
  Serial.print(xungPhai);
  Serial.print(" | Trai: ");
  Serial.println(xungTrai);

  if (xungPhai >= mucTieu && xungTrai >= mucTieu) {
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    Serial.println("Da quay xong muc tieu.");
    while (true);  // Dừng lại
  }

  delay(100);
}
