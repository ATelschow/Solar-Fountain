void relais() {
if (r == 0 && avgu > 13.5){
  digitalWrite(12, HIGH);
  r = 1;
}
if (r == 1 && avgu < 5.5){
  digitalWrite(12, LOW);
  r = 0;
  }
}
