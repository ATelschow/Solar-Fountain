void batterie()
{

if (batterie_an == 0)
    {
    if (avgu > 11.5) 
        {
        batterie_an = 1;
        digitalWrite(12, HIGH);  
        client.publish(MQTTstatus, "Batterie an");  
        }   
    }
else if (batterie_an == 1)
    {
    if (avgu < 11)
        {
        batterie_an = 0;
        digitalWrite(12, LOW);  
        client.publish(MQTTstatus, "Batterie aus");       
        }    
    }

}