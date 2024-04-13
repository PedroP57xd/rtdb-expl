#include <Arduino.h>

#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

const char* WIFI_SSID = "PP";
const char* WIFI_PASSWORD= "1234PP123";


const char* API_KEY= "AIzaSyDqQd7DgXjISmqdwXQ7SThZ1kB520W0-Es";

const char* DATABASE_URL= "https://rtdb-expl-8cffc-default-rtdb.firebaseio.com"; //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app;

const char* USER_EMAIL= "test@esp.com";
const char* USER_PASSWORD= "esp123";


FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;G*

unsigned long sendDataPrevMillis = 0;

unsigned long count = 0;



const int BUTTON_BANO = 23;    // Baño en el pin 23
const int BUTTON_COMEDOR = 22; // Comedor en el pin 22
const int BUTTON_COCINA = 21;  // Cocina en el pin 21
const int BUTTON_CUARTO = 19;  // Cuarto en el pin 19
const int BUTTON_CUARTO2 = 18; // Cuarto2 en el pin 18
const int BUTTON_CUARTO3 = 5;  // Cuarto3 en el pin 5
const int BUTTON_CUARTO4 = 17; // Cuarto4 en el pin 17
const int BUTTON_CUARTO5 = 16; // Cuarto5 en el pin 16
const int BUTTON_OFICINA = 4;  // Oficina en el pin 4
const int BUTTON_PATIO = 0;    // Patio en el pin 0
const int BUTTON_SALA = 2; 

bool bano  = false;
bool comedor  = false;
bool cocina  = false;
bool cuarto  = false;
bool cuarto2  = false;
bool cuarto3  = false;
bool cuarto4  = false;
bool cuarto5  = false;
bool oficina  = false;
bool patio  = false;
bool sala  = false;


void setup_WIFI(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  unsigned long ms = millis();
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void setupFirebase() {
  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.database_url = DATABASE_URL;
  config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h
  config.signer.tokens.legacy_token = "<database secret>";
  Firebase.reconnectNetwork(true);
  fbdo.setBSSLBufferSize(4096, 1024);
  fbdo.setResponseSize(2048);
  Firebase.begin(&config, &auth);
  Firebase.setDoubleDigits(5);
  config.timeout.serverResponse = 10 * 1000;
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

}

void setup() {
    Serial.begin(115200);
    setup_WIFI();
    setupFirebase();
    
    pinMode(BUTTON_BANO, INPUT);
    pinMode(BUTTON_COMEDOR, INPUT);
    pinMode(BUTTON_COCINA, INPUT);
    pinMode(BUTTON_CUARTO, INPUT);
    pinMode(BUTTON_CUARTO2, INPUT);
    pinMode(BUTTON_CUARTO3, INPUT);
    pinMode(BUTTON_CUARTO4, INPUT);
    pinMode(BUTTON_CUARTO5, INPUT);
    pinMode(BUTTON_OFICINA, INPUT);
    pinMode(BUTTON_PATIO, INPUT);
    pinMode(BUTTON_SALA, INPUT);

}

void loop() {

   if (Firebase.ready() && (millis() - sendDataPrevMillis >= INTREAD || sendDataPrevMillis == 0)) {
        bano = digitalRead(BUTTON_BANO);
        comedor = digitalRead(BUTTON_COMEDOR);
        cocina = digitalRead(BUTTON_COCINA);
        cuarto = digitalRead(BUTTON_CUARTO);
        cuarto2 = digitalRead(BUTTON_CUARTO2);
        cuarto3 = digitalRead(BUTTON_CUARTO3);
        cuarto4 = digitalRead(BUTTON_CUARTO4);
        cuarto5 = digitalRead(BUTTON_CUARTO5);
        oficina = digitalRead(BUTTON_OFICINA);
        patio = digitalRead(BUTTON_PATIO);
        sala = digitalRead(BUTTON_SALA);

         if (Firebase.RTDB.setBool(&fbdo, "/casa/bano", bano)) {
            Serial.println("Estado del baño actualizado en Firebase");
        } else {
            Serial.println("Error al actualizar el estado del baño: " + fbdo.errorReason());
        }

        if (Firebase.RTDB.setBool(&fbdo, "/casa/comedor", comedor)) {
            Serial.println("Estado del comedor actualizado en Firebase");
        } else {
            Serial.println("Error al actualizar el estado del comedor: " + fbdo.errorReason());
        }

        if (Firebase.RTDB.setBool(&fbdo, "/casa/cocina", cocina)) {
            Serial.println("Estado de la cocina actualizado en Firebase");
        } else {
            Serial.println("Error al actualizar el estado de la cocina: " + fbdo.errorReason());
        }

        if (Firebase.RTDB.setBool(&fbdo, "/casa/cuarto", cuarto)) {
            Serial.println("Estado del cuarto actualizado en Firebase");
        } else {
            Serial.println("Error al actualizar el estado del cuarto: " + fbdo.errorReason());
        }

        if (Firebase.RTDB.setBool(&fbdo, "/casa/cuarto2", cuarto2)) {
            Serial.println("Estado del cuarto2 actualizado en Firebase");
        } else {
            Serial.println("Error al actualizar el estado del cuarto2: " + fbdo.errorReason());
        }

        if (Firebase.RTDB.setBool(&fbdo, "/casa/cuarto3", cuarto3)) {
            Serial.println("Estado del cuarto3 actualizado en Firebase");
        } else {
            Serial.println("Error al actualizar el estado del cuarto3: " + fbdo.errorReason());
        }

        if (Firebase.RTDB.setBool(&fbdo, "/casa/cuarto4", cuarto4)) {
            Serial.println("Estado del cuarto4 actualizado en Firebase");
        } else {
            Serial.println("Error al actualizar el estado del cuarto4: " + fbdo.errorReason());
        }

        if (Firebase.RTDB.setBool(&fbdo, "/casa/cuarto5", cuarto5)) {
            Serial.println("Estado del cuarto5 actualizado en Firebase");
        } else {
            Serial.println("Error al actualizar el estado del cuarto5: " + fbdo.errorReason());
        }

        if (Firebase.RTDB.setBool(&fbdo, "/casa/oficina", oficina)) {
            Serial.println("Estado de la oficina actualizado en Firebase");
        } else {
            Serial.println("Error al actualizar el estado de la oficina: " + fbdo.errorReason());
        }

        if (Firebase.RTDB.setBool(&fbdo, "/casa/patio", patio)) {
            Serial.println("Estado del patio actualizado en Firebase");
        } else {
            Serial.println("Error al actualizar el estado del patio: " + fbdo.errorReason());
        }

        if (Firebase.RTDB.setBool(&fbdo, "/casa/sala", sala)) {
            Serial.println("Estado de la sala actualizado en Firebase");
        } else {
            Serial.println("Error al actualizar el estado de la sala: " + fbdo.errorReason());
        }

        // Actualiza la última vez que se enviaron datos
        sendDataPrevMillis = millis();
    }
}