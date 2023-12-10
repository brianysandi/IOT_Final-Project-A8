#define BLYNK_TEMPLATE_ID "TMPL6cvzBllv7"
#define BLYNK_TEMPLATE_NAME "Proyek Akhir IoT"
#define BLYNK_AUTH_TOKEN "j8E1AQr_5N_BD1Xd8H2T8KuZYgZn0Nh1"
#define BLYNK_PRINT Serial
// NOTE: DI BOARD MANAGER DOWNGRADE ESP32 KE VERSI 1.6 BIAR I2S MASIH BISA FUNGSIONAL
#include "Audio.h"
#include "CloudSpeechClient.h"
#include <BlynkSimpleEsp32.h>

const char *ssid = "trojan virus_plus";
const char *password = "armondharer098";
const char*  server = "speech.googleapis.com";

const char* root_ca= 
"-----BEGIN CERTIFICATE-----\n"
"MIIFljCCA36gAwIBAgINAgO8U1lrNMcY9QFQZjANBgkqhkiG9w0BAQsFADBHMQsw\n"
"CQYDVQQGEwJVUzEiMCAGA1UEChMZR29vZ2xlIFRydXN0IFNlcnZpY2VzIExMQzEU\n"
"MBIGA1UEAxMLR1RTIFJvb3QgUjEwHhcNMjAwODEzMDAwMDQyWhcNMjcwOTMwMDAw\n"
"MDQyWjBGMQswCQYDVQQGEwJVUzEiMCAGA1UEChMZR29vZ2xlIFRydXN0IFNlcnZp\n"
"Y2VzIExMQzETMBEGA1UEAxMKR1RTIENBIDFDMzCCASIwDQYJKoZIhvcNAQEBBQAD\n"
"ggEPADCCAQoCggEBAPWI3+dijB43+DdCkH9sh9D7ZYIl/ejLa6T/belaI+KZ9hzp\n"
"kgOZE3wJCor6QtZeViSqejOEH9Hpabu5dOxXTGZok3c3VVP+ORBNtzS7XyV3NzsX\n"
"lOo85Z3VvMO0Q+sup0fvsEQRY9i0QYXdQTBIkxu/t/bgRQIh4JZCF8/ZK2VWNAcm\n"
"BA2o/X3KLu/qSHw3TT8An4Pf73WELnlXXPxXbhqW//yMmqaZviXZf5YsBvcRKgKA\n"
"gOtjGDxQSYflispfGStZloEAoPtR28p3CwvJlk/vcEnHXG0g/Zm0tOLKLnf9LdwL\n"
"tmsTDIwZKxeWmLnwi/agJ7u2441Rj72ux5uxiZ0CAwEAAaOCAYAwggF8MA4GA1Ud\n"
"DwEB/wQEAwIBhjAdBgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwEgYDVR0T\n"
"AQH/BAgwBgEB/wIBADAdBgNVHQ4EFgQUinR/r4XN7pXNPZzQ4kYU83E1HScwHwYD\n"
"VR0jBBgwFoAU5K8rJnEaK0gnhS9SZizv8IkTcT4waAYIKwYBBQUHAQEEXDBaMCYG\n"
"CCsGAQUFBzABhhpodHRwOi8vb2NzcC5wa2kuZ29vZy9ndHNyMTAwBggrBgEFBQcw\n"
"AoYkaHR0cDovL3BraS5nb29nL3JlcG8vY2VydHMvZ3RzcjEuZGVyMDQGA1UdHwQt\n"
"MCswKaAnoCWGI2h0dHA6Ly9jcmwucGtpLmdvb2cvZ3RzcjEvZ3RzcjEuY3JsMFcG\n"
"A1UdIARQME4wOAYKKwYBBAHWeQIFAzAqMCgGCCsGAQUFBwIBFhxodHRwczovL3Br\n"
"aS5nb29nL3JlcG9zaXRvcnkvMAgGBmeBDAECATAIBgZngQwBAgIwDQYJKoZIhvcN\n"
"AQELBQADggIBAIl9rCBcDDy+mqhXlRu0rvqrpXJxtDaV/d9AEQNMwkYUuxQkq/BQ\n"
"cSLbrcRuf8/xam/IgxvYzolfh2yHuKkMo5uhYpSTld9brmYZCwKWnvy15xBpPnrL\n"
"RklfRuFBsdeYTWU0AIAaP0+fbH9JAIFTQaSSIYKCGvGjRFsqUBITTcFTNvNCCK9U\n"
"+o53UxtkOCcXCb1YyRt8OS1b887U7ZfbFAO/CVMkH8IMBHmYJvJh8VNS/UKMG2Yr\n"
"PxWhu//2m+OBmgEGcYk1KCTd4b3rGS3hSMs9WYNRtHTGnXzGsYZbr8w0xNPM1IER\n"
"lQCh9BIiAfq0g3GvjLeMcySsN1PCAJA/Ef5c7TaUEDu9Ka7ixzpiO2xj2YC/WXGs\n"
"Yye5TBeg2vZzFb8q3o/zpWwygTMD0IZRcZk0upONXbVRWPeyk+gB9lm+cZv9TSjO\n"
"z23HFtz30dZGm6fKa+l3D/2gthsjgx0QGtkJAITgRNOidSOzNIb2ILCkXhAd4FJG\n"
"AJ2xDx8hcFH1mt0G/FX0Kw4zd8NLQsLxdxP8c4CU6x+7Nz/OAipmsHMdMqUybDKw\n"
"juDEI/9bfU1lcKwrmz3O2+BtjjKAvpafkmO8l7tdufThcV4q5O8DIrGKZTqPwJNl\n"
"1IXNDw9bg1kWRxYtnCQ6yICmJhSFm/Y3m6xv+cXDBlHz4n/FsRC6UfTd\n"
"-----END CERTIFICATE-----\n";

char auth[] = BLYNK_AUTH_TOKEN;

enum State {
  STOP,
  PLAY,
  IDLE,
};

const int timerPeriod = 1000;
const int recordDuration = 300;

State currentState = IDLE;
int currentTime = 0;

TimerHandle_t timer;

void TaskSerial(void *pvParameters);
void TaskRECORD(void *pvParameters);
void TaskTimer(void *pvParameters);
void TaskBlynkRun(void *pvParameters);
String formatTimeStamp(int currentTime, int recordDuration);
void TaskSendDataToBlynk(void *pvParameters);

int buttonPlay;
Audio* audio = nullptr;
CloudSpeechClient* cloudSpeechClient = nullptr;

BLYNK_WRITE(V0) {
  buttonPlay = param.asInt();
}

void TaskBlynkRun(void *pvParameters) {
  (void)pvParameters;
  for (;;) {
    Blynk.run();
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}

void TaskSerial(void *pvParameters) {
  (void)pvParameters;

  while (1) {
    if (buttonPlay == 1) {
      if(currentState == STOP || IDLE){
        Serial.print("PLAYING");
        Serial.println(" : Play.");
        currentState = PLAY;
        currentTime = 0;
        audio->Record();
      }else{
        Serial.println("ERROR : Tidak dapat Play saat ini.");

      }
    } else {
      if(currentState == PLAY){
        Serial.print("STOPPED");
        Serial.println(" : Perekam diberhentikan.");
        currentState = STOP;
      }
      if(currentState == STOP){
        currentTime = 0;
        cloudSpeechClient->Transcribe(audio);
        delete audio;
        delete cloudSpeechClient;
        audio = new Audio(ICS43434);
        cloudSpeechClient = new CloudSpeechClient(USE_ACCESSTOKEN);
        currentState = IDLE;
        }
      }
    vTaskDelay(pdMS_TO_TICKS(100));
  }
}

void TaskSendDataToBlynk(void *pvParameters) {
  (void)pvParameters;
  String dataToSend;
  String timeStamp;

  while (1) {
    if(currentState == PLAY){
        timeStamp = formatTimeStamp(currentTime, recordDuration);
    }
    dataToSend = timeStamp + "; ";

    switch (currentState) {
      case PLAY: dataToSend += "PLAY"; break;
      case STOP: dataToSend += "STOP"; break;
      case IDLE: dataToSend += "IDLE"; break;\
    }

    Blynk.virtualWrite(V2, dataToSend);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

String formatTimeStamp(int currentTime, int recordDuration) {
    String timeStamp = "";
    timeStamp += currentTime / 60;
    timeStamp += ":";
    if (currentTime % 60 < 10) {
        timeStamp += "0";
    }
    timeStamp += currentTime % 60;
    timeStamp += " / ";
    timeStamp += recordDuration / 60;
    timeStamp += ":";
    if (recordDuration % 60 < 10) {
        timeStamp += "0";
    }
    timeStamp += recordDuration % 60;

    return timeStamp;
}

void TaskTimer(void *pvParameters) {
  (void)pvParameters;
  String timeStamp;

  while (1) {
    if (currentState == PLAY) {
      currentTime++;
      if (currentTime >= (recordDuration + 1)) {
        currentState = STOP;
        currentTime = 0;
        Serial.println("Recording ended.");
      }
      String timeStamp = formatTimeStamp(currentTime, recordDuration);
      Serial.println(timeStamp);
    }
    vTaskDelay(pdMS_TO_TICKS(timerPeriod));
  }
}

void TimerCallback(TimerHandle_t xTimer) {}

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("\r\nESP32-LNW\r\n");
  Serial.println("Connecting to Blynk...\n");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
  xTaskCreatePinnedToCore(TaskSerial, "SerialTask", 4096, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(TaskTimer, "TimerTask", 4096, NULL, 3, NULL, 0);
  xTaskCreatePinnedToCore(TaskBlynkRun, "BlynkRunTask", 4096, NULL, 1, NULL, 1);
  xTaskCreatePinnedToCore(TaskSendDataToBlynk, "TaskSendData", 4096, NULL, 1, NULL, 1);
  audio = new Audio(ICS43434);
  cloudSpeechClient = new CloudSpeechClient(USE_APIKEY);
  timer = xTimerCreate("RecordTimer", pdMS_TO_TICKS(timerPeriod), pdTRUE, (void *)0, TimerCallback);
  if (timer != NULL) {
    xTimerStart(timer, 0);
  }
}

void loop() {
}