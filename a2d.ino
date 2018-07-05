int a2d(int n)
{
  int analogValue;
  analogValue = analogRead(n);
  if(analogValue<100)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
