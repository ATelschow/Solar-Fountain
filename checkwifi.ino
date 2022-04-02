void checkwifi() {
  if (WiFi.status() != WL_CONNECTED) {
  Serial.println("You're not connected to the network");
  }
}
