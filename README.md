# Robot s všesměrovým podvozkem
Projekt se zabývá stavbou robota s všesměrovým podvozkem. Zatím je zprovozněna komunikace pomocí Bluetooth mezi Arduinem Nano s ATmegou168 a ATtiny 3224.

## Ovladač
Jako ovladač je použit čip ATtiny3224, ke kterému je připojen joystick a 4. tlačítka. Konstrukčně je schován do starého ovladače Trustmaster k počítači.

## Robot
Momentálně je jezdící robot nahrazen LED indikací. Tento kó zatím slouží pouze pro ověření funkčnosti komunikace pomocí Bluetooth.

> [!WARNING]
> U komunikace Bluethoot je nastavena u ovladače a robota jiná rychlost baud! To protože jsou fyzicky moduly jinak nastaveny.
