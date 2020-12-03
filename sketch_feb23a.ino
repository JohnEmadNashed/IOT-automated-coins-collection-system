#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "iotprojec.firebaseio.com"  //iotproject-1fba8.firebaseio.com
#define FIREBASE_AUTH "ZDBMS76YVUTyQqMJc4QivcmWXyWLmSiISxFtGExQ"  //HCdki3npjisRDHoAzPr5nwSNlQQaZhquKBBzTYGh
#define WIFI_SSID "Bolla's phone" //Marco 2
#define WIFI_PASSWORD "Jj123456" //01225468098

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
/*
  Firebase.pushInt("PosMov", 1);
  Firebase.pushInt("PosMov", 2);
  Firebase.pushInt("PosMov", 3);
  Firebase.pushInt("PosMov", 4);
*/ 
}

void loop() 
{
  
  // set values
  Firebase.setInt("StartX", 1);
  Firebase.setInt("StartY", 0);



  //get values
  /*
  Serial.print("PosMovDown: ");
  Serial.println(Firebase.getInt("PosMovDown")); 
  Serial.print("PosMovLeft: ");
  Serial.println(Firebase.getInt("PosMovLeft")); 
  Serial.print("PosMovRight: ");
  Serial.println(Firebase.getInt("PosMovRight")); 
  Serial.print("PosMovUp: ");
  Serial.println(Firebase.getInt("PosMovUp")); 
   */
  delay(1000);

    for (int i=1;i<5;i++)
    {
        String what = "/PosMovTest/" + String(i);
        Serial.println(what);
        Serial.println(Firebase.getInt(what));
    }
  //Serial.println(StopReachIt());
  //getNextMove();
  
  }
 int StopReachIt()
  {

  }
  /*
  void getNextMove()
  {
    if(StopReachIt()==1)
    {
      MoveForward();
    }
    else if(StopReachIt()==2)
    {
      MoveBackward();
    }
    else if(StopReachIt()==3)
    {
     MoveRight();
    }
    else if(StopReachIt()==4)
    {
     MoveLeft();    
    }
  }
  void MoveForward()
  {
    Serial.println("Moving Forward...");
  }
  void MoveBackward()
  {
    Serial.println("Moving Backward...");
  }
  void MoveRight()
  {
    Serial.println("Moving Right...");
  }
  void MoveLeft()
  {
    Serial.println("Moving Left...");
  }
*/
  
