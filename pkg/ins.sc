func install
{
  g++ main.cpp -o ny6
  chmod +x ny6
  sudo mv ny6 /usr/bin/ny6
}

func remove
{
  sudo rm /usr/bin/ny6
}

func update
{
  &install
}
