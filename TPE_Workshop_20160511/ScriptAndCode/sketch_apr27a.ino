#include <SoftwareSerial.h>   // �ޥε{���w
 
// �w�q�s��LoRa�Ҳժ��ǦC��
SoftwareSerial LoRa(10, 11); // �����}, �ǰe�}
char val;  // �x�s������ƪ��ܼ�
 
void setup() {
  Serial.begin(9600);   // �P�q���ǦC��s�u
  Serial.println("LoRa is ready!");
  Serial.write('\r');
  // �]�wLoRa�Ҳժ��s�u�t�v
  LoRa.begin(9600);
  
  //��print ���覡�۰ʤU�FAT command
  
}
 
void loop() {
 //�e�X���ո�� lat: 25.045361, long:121.522544, batteryLevel:200, temp: 30, state: 10(00001010)
  // LoRa.print("AT+DTX=22,073E4970017E2971C81E0A\r");
  // delay(1500*60);
  //�ۦ��JAT command
 if (Serial.available()) {
    val = Serial.read();
    LoRa.print(val);
    
  }
  // �Y����LoRa�Ҳժ���ơA�h�e��u�ǦC��ʱ������v
  ;
  if (LoRa.available() ) {
    val = LoRa.read();
    Serial.print(val);
  }
}