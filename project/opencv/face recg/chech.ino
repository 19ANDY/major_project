#include<SoftwareSerial.h>
int read_count=0,tag_count=0;
int j=0; 
char data_temp, RFID_data[12], data_store[12];
boolean disp_control;

void setup()
{
Serial.begin(9600);

}

void loop()
{
RecieveData();
StoreData();
PrintData();
checkdata1();


}

void RecieveData()
{
if(Serial.available()>0)
{
data_temp=Serial.read();
RFID_data[read_count]=data_temp;
read_count++;
}
}

void StoreData()
{

if(read_count==12)
{
disp_control=true;  
for(j=0;j<12;j++)
{
data_store[j]=RFID_data[j];
}
read_count=0;
}
}

void PrintData()
{
if(disp_control==true)
{
 
    for(j=0;j<12;j++)
  {
    if(data_store[0]==0)
    { break;}
    Serial.write(data_store[j]);
  }
  Serial.println();
disp_control=false;
}
}
void checkdata1()
{
if(disp_control==true)
{
  for(j=0;j<12;j++)
  {
    if(data_store[11]==9)
    {Serial.write(0);}
  }
 Serial.println();
disp_control=false;
}
}
