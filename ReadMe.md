#Ny++6 - Das Ende?

Erstmal: Nein ich denke nicht das Ny++6 das Ende sein wird. Es wird vorraussichtlich die letzte große Version mit den letzten Änderungen sein, aber die Entwicklung wird hier nicht abruppt stoppen.

Falls Bugs in der Sprache gefunden werden, können diese mir mit einem Issue hier in der Repo gemeldet werden.
So... nun aber zum Prolog ;).

-----------------------

Ny++6, die vorerst letzte, große Version von Ny++. Es hat sich viel geändert und es ist viel dazugekommen.
Ny++6 ist viel typisierter, hat aber dadurch auch mehr Funktionen.

Das jedoch größte, was geändert wurde, ist die Programmiersprache in der Ny++ geschrieben wurde. Es wurde von Java auf C++ umgestiegen und somit wurde das ganze Konzept noch einmal neu überarbeitet.

**Dieses Tutorial baut sich auf Grundwissen über Assembler, C++, Java, C, Ny++, oder Ny++5 auf!**

##Inhaltsverzeichnis
* 0.1 Changelog
* 0.2 SourceCode kompilieren
* 1 Der Interpreter
    * Ein Programm starten
* 2 Der Compiler
    * Ein Programm von Ny++6 nach C++ konvertieren und kompilieren
* 3 Variablen
    * Integer
    * Strings
    * Besondere Variablen
    * Gültigkeitsbereiche von Variablen
    * Moi - Move Int
    * Mos - Move String
* 4 Rechnen
    * Addition
    * Division
    * Subtraktion
    * Multiplikation
* 5 Ausgabe
    * Say - Sätze ausgeben
    * Prv	- Variablen ausgeben
* 6 Eingabe
    * Inp - Input
* 7 Funktionen
    * Grundaufbau
    * Funktion im Verlauf verlassen
    * Argumente
    * Sprungmarken in Funktionen
* 8 Erweitert Rechnen (Potenzen und Rest)
    * Poi - Integer Potenzieren
    * Mod - Rest berechnen
* 9 Werte vergleichen
    * Strings
        * Eqs - Gleichheit
        * Nqs - Ungleichheit
        * Gqs - Größer
        * Lqs - Keiner
    * Integer
        * Eqi - Gleichheit
        * Nqi - Ungleichheit
        * Gqi - Größer
        * Lqi - Keiner
* 10 Dateien einbinden
    * Inc - Einbinden von Dateien
    * Indic - Einbinden nach Verlangen
* 11 Präprozessorbefehle
    * Def
    * Undef
* 12 Zusatzbefehle & Extras
    * Das Betriebssystem ermitteln
    * Stringmanipulation
        * GCA - Get Char At
        * STI - String to Int

##0.1 Changelog

###18.12.2016 –– 12:34 | 12:34 PM –– Survari

Notiz: Da die ersten Gotos zu eher richtigen Funktionen geworden sind, hab ich jetzt noch einmal andere Sprungmarken hinzugefügt, die NICHT mit Return zurückverfolgt werden können und auch nur inerhalb einer Funktion (bspw. {main}) genutzt werden können.

* Bugfix    Equals Integer
* Bugifx    Equals String
* Added     Sprungmarken 2.0
* Added     Sprungmarken zu EQI, NQI, GQI und LQI
* Added     Sprungmarken zu EQS, NQS, GQS und LQS
* Added     Readme-Eintrag Sprungmarken in Kapitel 7

###17.12.2016 –– 21:54 | 9:54 PM –– Survari

Notiz: Etwas größeres Update, man könnte Ny++6.1 meinen ;)!

* Bugfix    Scopes
* Bugfix    Werte
* Bugfix    Integer-Variablen
* Bugfix    Mod-Funktion
* Bugfix    Input
* Bugfix    Poi-Funktion
* Bugfix    Output (@, _NL);
* Bugfix    C++-Compiler

## 0.2 Source Code kompilieren

Um den C++ Source-Code von Ny++6 zu kompilieren, benötigen wir G++ Version 6.2. Dazu brauchen wir noch CMake, das aber nur auf Linux, wenn man es nicht per Hand machen möchte.

###Linux

####Installation von GCC auf Debian

	sudo apt-get install build-essential
	sudo apt-get install cmake

####Installation von GCC auf Arch

	sudo pacman -S gcc
	sudo pacman -S cmake

####Installation von GCC auf SuSe

####Installation von GCC auf RedHat

###Windows

####Installation von GCC auf Windows
MinGW ist eine portierte GCC-Version für Windows, sie ist hier zu finden: [MinGW-Website](http://www.mingw.org/)

###Kompilieren auf Windows und Linux

Zuerst wird in das Projektverzeichnis gewechselt und mit...

	g++ -o bin/ny6 main.cpp

oder (CMake von nöten)

	cmake CMakeLists.txt
	make

... wird die Anwendung in dem Unterordner bin/ des Projektes neu kompiliert.

##1 Der Interpreter

Um eine Datei zu starten, müssen wir folgenden Befehl eingeben:

	ny6 [Datei]

oder auf Linux

	./ny6 [Datei]

damit wird die Datei `[Datei]` gestartet, einfach `[Datei]` durch die gewünschte Datei ersetzen.

## 2 Der Compiler

Damit wir eine Datei in die Sprache C++ konvertieren wird folgender Befehl benötigt:

	ny6 -cc [Datei]

Damit wird der Ny++6 Code in eine C++-Datei umgewandelt und kann kompiliert werden.

##3 Variablen

Auch in Ny++6 sind die Variablen vertreten. Es gibt zwei Typen. Einmal die Strings und einmal die Integer.

###Integer

Um einen Integer zu kreieren, benutzen wir den Befehl `defi` (mehr zu dem Aufbau in dem Befehlsstammbaum, am Ende der Datei):

	{main}  
		defi i, [7];
		endf;

**Notiz:** Wenn irgendwo in Ny++6 Zahlen angegeben werden, müssen eckige Klammern (`[x]`) um diese Zahl stehen!

###Strings

Bei den Strings ist es genausom bloß mit `defs`, statt `defi`. Auch hier kann wieder zum Stammbaum der Befehle am Ende der Datei. Anders bei Den Strings sind die Anführungszeichen statt den eckigen Klammern.

	{main}
		defs s, "Hallo Welt";
		endf;

###Besondere Variablen

Wenn wir von den "besonderen" Variablen in Ny++6 sprechen, meinen wir vordeklarierte Variablen. Diese Variablen sind in jeder Funktion erreichbar und haben somit keinen Gültigkeitsbereich. Diese Variablen beginnen mit einem `_`, dies sind sie:

	_axs
	_cxs
	_dxs
	_exs

Dies sind beschreibbare Stringvariablen, angelehnt an die Register in Assembler.

	_axi
	_cxi
	_dxi
	_exi

Und hier die Integer-Form. Diese sind auch beschreibbar. Dann haben wir nur noch vier weitere:

	_SN
	_IN
	_fos
  _NL

`_SN` beinhaltet nichts und ist auch nicht beschreibbar. `_IN` beinhaltet auch `0` und ist, wie `_SN`, nicht beschreibbar.
`_NL` steht für "New Line" und erzeugt eine neue Zeile wenn es ausgegeben wird.

`_fos` ist hier etwas ganz besonderes. FOS beinhaltet die Nummer des aktuellen Betriebssystems, diese Zahlen stehen für dieses Betriebssystem:

	0 = Windows 32bit
	1 = Windows 64bit
	2 = MacOS
	3 = Unix
	4 = Linux
	5 = FreeBSD
	6 = Andere

###Gültigkeitsbereiche von Variablen

Jede Variable die Deklariert wird hat ihren Gültigkeitsbereich in ihrer eigenen Funktion. Da bedeutet wenn in dem Funktionsraum Main...

	{main}  
		defs s, "Hallo Welt";
		endf;

eine Variable `s` mit dem Wer `Hallo Welt` deklariert wurde, ist sie auch nur in diesem Bereich verfügbar.

###Moi - Move Int

Um eine Integer Variable direkt zu setzen, benutzen wir den Befehl `moi`:

	moi [5], a;
Damit wird der Wert `5` in die Variable `a` geschrieben.

###Mos - Move String
Um eine String Variable direkt zu setzen, benutzen wir den Befehl `mos`:

	mos "Hallo Welt", s;
Damit wird der Wert `Hallo Welt` in die Variable `s` geschrieben.
##4 Rechnen
###Addition
Damit wir in Ny++6 Variablen (Integer) addieren können, nutzen wir den Befehl `add`:

	add [5], a;

Auch mit Strings ist dies Möglich, dort wird der String einfach ans Ende rangehangen:

	add "Hallo", s;

"Was? -> Wohin?" ist die Frage.

###Division
Damit wir in Ny++6 Variablen (Integer) dividieren können, nutzen wir den Befehl `add`:

	div [5], a;

###Subtraktion
Damit wir in Ny++6 Variablen (Integer) subtrahieren können, nutzen wir den Befehl `add`:

	sub [5], a;

###Multiplikation
Damit wir in Ny++6 Variablen (Integer) multiplitieren können, nutzen wir den Befehl `add`:

	mul [5], a;

##5 Ausgabe

###Say - Sätze ausgeben

Der Output ist sehr einfach gehalten, der Befehl lautet `say`:

	say "Hallo Welt!";
Und schon gibt es eine Ausgabe `Hallo Welt!`!

###Prv	- Variablen ausgeben

Mit Say ist es nur möglich Strings und Integer auszugeben, mit dem Befehl `prv` geben wir Werte von Variablen aus:

	prv a;

###Zeilenumbruch
Einen Zeilenumbruch rufen wir mit einem (oder mehreren) @ am Befehlsende hervor:

	prv a;@

##6 Eingabe
###Inp - Input

Um einen Input einer Variable entgegenzunehmen nutzen wir den Befehl `inp`. Dieser kann Strings als auch Variablen entgegennehmen:

	inp a;

##7 Funktionen
###Grundaufbau

Der Grundaufbau einer Funktion sieht immer so aus:

	{main}
		endf;

Das `main` in den Klammern gibt den Namen an und auch den Start der Funktion. Der Befehl `endf` beendet und schließt die Funktion.

Jede Funktion hat ihren eigenen Fültigkeitsbereich. Wenn man in Funktionen (sonnst wo anders sollte man es auch nicht machen) Variablen deklariert, werden diese Variablen auch nur in diesem Funktionsbereich aufrufbar sein.

Um nun eine Funktion aufzurufen, nutzen wir `cl`, dies steht für "call":

	{main}
		mos "Hallo", _axs;
		cl args;

		end;
		endf;

	{args}
		prv _axs;@
		return;
		endf;

###Funktionen verlassen

`endf`  beendet wie gesagt die Funktion und steht immer als letzter Befehl einer Funktion. Um aus der Funktion zu springen, benutzt man den Befehl `return` (Siehe nutzung Befehlsstambaum am Ende der Datei):

	{main}
		defs s, "H";
		prv s;@
		return;
		mos _SN, s;
		endf;
Damit erstellen wir eine Variable `s` mit dem Wert `H` und verlassen die Funktion dann.

###Argumente

Direkte Argumente gibt es nicht, aber es ist möglich die System-/"besonderen" Variablen zu benutzen.

##8 Erweitert Rechnen(Potenzen und Rest)

###Mod - Rest berechnen

Den Rest kann man so berechnen, zu dem Aufbau ist wieder der Stammbaum am Ende der Datei da:

	{main}
		moi     [2], _axi;
		moi     [8], _cxi;

		mod     _axi, _cxi;
		prv     _cxi;@

		return;
		endf;

###Sprungmarken in Funktionen

Um in Funktionen hin und her springen zu können, gibt es die Sprungmarken. Eigentlich sollten Funktionen allein Sprungmarken sein, haben dann aber einen größeren Umfang als erst gedacht erhalten und so wurden jetzt Sprungmarken nachgereicht.

Sprungmarken deklarieren wir indem wir es wie mit Funktionen machen, bloß dass wir statt geschweiften Klammern `{marke}` nun runde verwenden `(marke)`:

  {main}
    (punk1)
    moi     [2], _axi;
    moi     [8], _cxi;

    mod     _axi, _cxi;
    prv     _cxi;@
    (punkt2)

    return;
    endf;

Um zu diesen Sprungmarken zu springen, können wir den Befehl `gt` nutzen:

  {main}
    (punk1)
    moi     [2], _axi;
    moi     [8], _cxi;

    mod     _axi, _cxi;
    prv     _cxi;@

    gt      punk1t;

    (punkt2)
    return;
    endf;

Sprungmarken haben ihren Gültigkeitspbereich in der dementsprechenden Funktion, also können wir zwei Sprungmarken mit dem gleichen Namen in unterschiedlichen Funktionen erzeugen:

  {main}
    (punkt1)
    say   "Ich bin in Main!";@
    gt    punkt1;

  {ok}
    (punkt1)
    say   "Diese Funktion wird niemals aufgerufen!";@
    gt    punkt1;

Dort wird die Main aufgerufen und dann wird immer wieder zu Punkt 1 in der Main gesprungen, da der Interpreter sich derzeit in dem Gültigkeitsbereich der Main-Funktion befindet und desswegen auch nur in der Main-Funktion anch Sprungmarken sucht.

Bei Sprungmakren ist es nciht möglich mit dem Befehl Return zurückzukehren!

##9 Werte vergleichen

Werte vergleichen ist wie wir wissen das so ziemlich wichtigste in Programmiersprachen. Zwischen den vergleichen bei Strings und Integern besteht absolut kein Unterschied, außer der Befehlsname.

###Strings
####Eqs - Gleichheit

Um die Gleichheit bei Strings zu prüfen nutzen wir den Befehl `eqs`:

	eqs s, "Hallo Welt", funktion;
Wenn s den Wert `Hallo Welt` hat, dann wird die Funktion `funktion` ausgeführt.
Es ist dabei nur möglich einen String (`""`) als zweites Argument anzugeben!

####Nqs - Ungleichheit

Um die Ungleichheit bei Strings zu prüfen nutzen wir den Befehl `nqs`:

	nqs s, "Hallo Welt", funktion;
Wenn s nicht den Wert `Hallo Welt` hat, dann wird die Funktion `funktion` ausgeführt.
Es ist dabei nur möglich einen String (`""`) als zweites Argument anzugeben!
####Gqs - Größer

Um die Länge bei Strings zu prüfen (größer) nutzen wir den Befehl `gqs`:

	gqs s, "Hallo Welt", funktion;
Wenn die Länge von s großer als die Länge von `Hallo Welt` ist, wird die Funktion `funktion`  ausgeführt.
####Lqs - Keiner

Um die Länge bei Strings zu prüfen (kleiner) nutzen wir den Befehl `lqs`:

	lqs s, "Hallo Welt", funktion;
Wenn die Länge von s kleiner als die Länge von `Hallo Welt` ist, wird die Funktion `funktion` ausgeführt.
Es ist dabei nur möglich einen String (`""`) als zweites Argument anzugeben!

###Integer
####Eqi - Gleichheit

Auch hier nur wenig unterschied zum String. `eqi` prüft auf Gleichheit:

	eqi a, [5], funktion;

Wenn a gleich `5` ist, dann wird die Funktion `funktion` ausgeführt.

####Nqi - Ungleichheit

`nqi` prüft auf Ungleichheit:

	nqi a, [5], funktion;

Wenn a nicht den Wert `5` hat, dann wird die Funktion `funktion` ausgeführt.

####Gqi - Größer
`gqi` prüft auf einen größeren Wert:

	gqi a, [5], funktion;

Wenn a größer `5` ist, dann wird die Funktion `funktion` ausgeführt.
####Lqi - Kleiner
`lqi` prüft auf einen kleineren Wert:

	lqi a, [5], funktion;

Wenn a kleiner `5` ist, dann wird die Funktion `funktion` ausgeführt.

###Anmerkung

Um Sprungmarken anzusteuern, muss derjenige Sprungmarkenname in <> stehen:

  {main}
    (anfang)
    add   [1], _cxi;
    gqi   _cxi, 1, <anfang>;

Damit wird zu der Funktion anfang gesprungen, es ist nicht möglich mit einem Return zurückzukehren.

## 10 Dateien einbinden
###Inc - Einbinden von Dateien

Hier könnnen wir, wie in C++ mit `#include`, mit `%inc datei.n6` eine Datei einbinden und deren Code an dieser Zeile einfügen.

###Indic - Einbinden nach Verlangen

Damit dies dann nicht zu Errors kommt, gibt es den Befehl `%indic`, er überprüft ob eine Praeprozessorvariable existiert und wenn dies nicht der Fall ist, wird die Datei eingebunden, sonnst wird der Befehl ignoriert:

test.n6:

	%indic a2 a2.n6
	...

a2.n6:

	%def a2


##11 Präprozessorbefehle

###Def

Mit `%def` definieren wir eine Praeprozessorvariable erstellt. Diese Variablen haben, außer bei den Includes, keine weitere Beeinflusung auf den Programmverlauf.

###Undef

Mit `%undef` löschen wir eine Praeprozessorvariable, damit man sie, falls notwendig, später wieder verwenden kann.

##12 Zusatzbefehle & Extras
###Stringmanipulation
####GCA - Get Char At
####STI - String to Int

#Befehlsstammbaum

###moi - Ziel = Quelle
	moi [Quelle:INT], [Ziel:INT];
	moi [5], a;
###mos - Ziel = Quelle
	mos [Quelle:STR], [Ziel:STR];
	mos "Hallo", s;
###defi - Define Integer Name = Wert
	defi [Name], [Wert:INT];
	defi a, [5];
###defs - Define String [Name] = [Wert]
	defs [Name], [Wert:STR];
	defs s, "Hallo";
###%def - Define PraeprozessorVariable
	%def [Name]
	%def a2.n6
###%inc - Include
	%inc [Datei]
	%inc a2.n6
###%indic - If Not(/Nicht) Defined PraeprozessorVariable dann #include Datei
	%indic [PraeprozessorVariable] [Datei]
	%indic a2.n6 a2.n6
###nqi - If Quelle != Ziel dann Funktion()
	nqi [Quelle:INT], [Ziel:INT], [Funktion]
	nqi a, 5, ok;
###gqi - If Quelle > Ziel dann Funktion()
	gqi [Quelle:INT], [Ziel:INT], [Funktion]
	gqi a, 5, ok;
###lqi - If Quelle < Ziel dann Funktion()
	lqi [Quelle:INT], [Ziel:INT], [Funktion]
	lqi a, 5, ok;
###eqi - If Quelle == Ziel dann Funktion()
	eqi [Quelle:INT], [Ziel:INT], [Funktion]
	eqi a, 5, ok;
###eqs - If Quelle == Ziel dann Funktion()
	eqs [Quelle:STR], [Ziel:STR], [Funktion]
	eqs a, 5, ok;
###lqs - If Quelle < Ziel dann Funktion()
	lqs [Quelle:STR], [Ziel:STR], [Funktion]
	lqs a, 5, ok;
###gqs - If Quelle > Ziel dann Funktion()
	gqs [Quelle:STR], [Ziel:STR], [Funktion]
	gqs a, 5, ok;
###nqs - If Quelle != Ziel dann Funktion()
	nqs [Quelle:STR], [Ziel:STR], [Funktion]
	nqs a, 5, ok;
###gca - Ziel = Quelle[Index] (Quelle at Index)
	gca [Quelle:STR], [Index:INT], [Ziel:STR];
	gca s, a, s;
	gca s, [5], s;
###sti - Ziel = (char) Quelle
	sti [Quelle:INT], [Ziel:STR];
	sti
###return - Return 0
	return;
###cl - Funktion()
	cl [Funktion];
	cl ok;
###gt - goto Sprungmarke
	gt [Sprungmarke];
	gt punkt1;
###sub - Ziel = Ziel - Quelle
	sub [Quelle:INT], [Ziel:INT];
	sub 5, a;
###div - Ziel = Ziel / Quelle
	div [Quelle:INT], [Ziel:INT];
	div 1, a;
###mul - Ziel = Ziel * Quelle
	mul [Quelle:INT], [Ziel:INT];
	mul 5, a;
###add - Ziel = Ziel + Quelle
	add [Quelle:INT/:STR], [Ziel:INT/:STR];
	add 5, a;
	add " Welt!", s;
###inp - Input
	inp [Ziel:INT/:STR];
	inp a;
	inp s;
###poi - Ziel = Quelle(hoch)Ziel
	poi [Quelle:INT], [Ziel:INT];
	poi 1, a;  
###mod - Ziel = Quelle/Ziel R
	mod [Quelle:INT], [Ziel:INT];
	mod 2, a;
###%err - Error: "Error"
	%err "Error"
