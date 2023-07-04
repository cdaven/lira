---------------------------------------------------------------------------
  Lira! 1.0.0
  Copyright 2003 Christian Dav�n
---------------------------------------------------------------------------

  Lira! �r gratis och f�r anv�ndas fritt s� l�nge som ingen del av programmet �r
  modifierat.

  Utvecklaren ansvarar inte f�r eventuella dataf�rluster eller annan skada som
  kan uppst� vid anv�ndning av programmet. Anv�ndning sker p� egen risk.



  FUNKTIONALITET
---------------------------------------------------------------------------

  Lira! ...

  * s�ker igenom din musiksamling och lagrar information om alla l�tar
    i en central databas f�r snabbare operationer

  * m�rker automatiskt n�r du har lagt in nya musikfiler i din samling,
    n�r du har raderat eller flyttat n�gon fil

  * l�ter dig sortera dina musikfiler baserat p� deras egenskaper,
    exempelvis genre, �rtal, artist, betyg

  * spelar upp dina musikfiler i Winamp eller Windows Media Player

  * l�ter dig �ndra egenskaperna hos dina musikfiler, och f�rutom
    de "vanliga" egenskaperna kan du s�tta betyg, hum�r och tillf�lle

  * hanterar musikinformation lagrad i ID3v1 och ID3v2.x, som �r de
    standardiserade formaten f�r information i mp3-filer

  * startar snabbt och �r minnessn�lt f�r att du alltid ska kunna
    ha programmet till hands



  FR�GOR OCH SVAR
---------------------------------------------------------------------------

  Varf�r visar Winamp en annan genre �n den som angetts i Lira!?

  Winamp st�der inte ID3v2-standarden fullt ut, detta m�rks bland annat i dess
  hantering av genrer. Winamp visar "bas-genren", exempelvis Alt. Rock, n�r du
  anger en genre som inte ing�r i ID3v1 (ex. College Rock) tillsammans med genren
  som den nya h�rletts ifr�n. Hela den angivna genren �r dock sparad till filen i
  standardiserat format.


  Varf�r g�r det l�ngsamt att skriva information till vissa mp3-filer?

  Lira! anv�nder sig av ID3v2-taggar f�r att lagra information i varje mp3-fil,
  och dessa ligger n�stan alltid f�rst i filen. Om filen sedan tidigare saknar
  ID3v2-tagg (den kan ha ID3v1-tagg, det �r en annan sak) m�ste programmet f�rst
  flytta hela musikdatat fram�t i filen och d�refter l�gga in taggen. Denna
  tids�tg�ng �r proportionell mot musikfilens storlek. En fil som redan har en
  ID3v2-tagg beh�ver oftast inte skrivas mer till disk �n sj�lva informationen.
  D�rf�r g�r det mycket snabbare.


  Hur lagras tillf�lle, hum�r och betyg i mp3-filerna?

  Dessa informationsf�lt kommer ursprungligen fr�n Music Match, som lagrade det i
  kommentar-f�ltet. Tyv�rr kan Winamp d� skriva �ver informationen n�r du �ndrar
  kommentaren d�r, d�rf�r sparar Lira! informationen i ett annat f�lt, det som
  kan anv�ndas till vad som helst enlig ID3v2-standarden.

