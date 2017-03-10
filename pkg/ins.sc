install
{
  g++ main.cpp -o ny6
  chmod +x ny6
  sudo mv ny6 /usr/bin/ny6
}

remove
{
  [
    if [-f /usr/bin/ny6 ]; then
      sudo rm /usr/bin/ny6
    else
      echo "Binary file not found, exiting without uninstalling."
    fi
  ]
}

update
{
  &install
}