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

func install_win
{
  [
    @echo off
    
    if NOT EXISTS %appdata%\info.inf (
    mkdir %appdata%\bin
    echo Triploit-Binary-Directory > info.inf
    setx PATH "%PATH%;%appdata%\\bin\\"
    ) ELSE (
      echo Triploit Directory Exists, Continue...
    )
    
    g++ main.cpp -o ny6.exe -static
    copy ny6.exe %appdata%\\bin\\ny6.exe
  ]
}

func remove_win
{
  del %appdata%\bin\ny6.exe
}

func update_win
{
  &install_win
}
