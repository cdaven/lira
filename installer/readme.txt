---------------------------------------------------------------------------
  Lira! 1.0.0
  Copyright 2003 Christian Davén
---------------------------------------------------------------------------

  Lira! är gratis och får användas fritt så länge som ingen del av programmet är
  modifierat.

  Utvecklaren ansvarar inte för eventuella dataförluster eller annan skada som
  kan uppstå vid användning av programmet. Användning sker på egen risk.



  FUNKTIONALITET
---------------------------------------------------------------------------

  Lira! ...

  * söker igenom din musiksamling och lagrar information om alla låtar
    i en central databas för snabbare operationer

  * märker automatiskt när du har lagt in nya musikfiler i din samling,
    när du har raderat eller flyttat någon fil

  * låter dig sortera dina musikfiler baserat på deras egenskaper,
    exempelvis genre, årtal, artist, betyg

  * spelar upp dina musikfiler i Winamp eller Windows Media Player

  * låter dig ändra egenskaperna hos dina musikfiler, och förutom
    de "vanliga" egenskaperna kan du sätta betyg, humör och tillfälle

  * hanterar musikinformation lagrad i ID3v1 och ID3v2.x, som är de
    standardiserade formaten för information i mp3-filer

  * startar snabbt och är minnessnålt för att du alltid ska kunna
    ha programmet till hands



  FRÅGOR OCH SVAR
---------------------------------------------------------------------------

  Varför visar Winamp en annan genre än den som angetts i Lira!?

  Winamp stöder inte ID3v2-standarden fullt ut, detta märks bland annat i dess
  hantering av genrer. Winamp visar "bas-genren", exempelvis Alt. Rock, när du
  anger en genre som inte ingår i ID3v1 (ex. College Rock) tillsammans med genren
  som den nya härletts ifrån. Hela den angivna genren är dock sparad till filen i
  standardiserat format.


  Varför går det långsamt att skriva information till vissa mp3-filer?

  Lira! använder sig av ID3v2-taggar för att lagra information i varje mp3-fil,
  och dessa ligger nästan alltid först i filen. Om filen sedan tidigare saknar
  ID3v2-tagg (den kan ha ID3v1-tagg, det är en annan sak) måste programmet först
  flytta hela musikdatat framåt i filen och därefter lägga in taggen. Denna
  tidsåtgång är proportionell mot musikfilens storlek. En fil som redan har en
  ID3v2-tagg behöver oftast inte skrivas mer till disk än själva informationen.
  Därför går det mycket snabbare.


  Hur lagras tillfälle, humör och betyg i mp3-filerna?

  Dessa informationsfält kommer ursprungligen från Music Match, som lagrade det i
  kommentar-fältet. Tyvärr kan Winamp då skriva över informationen när du ändrar
  kommentaren där, därför sparar Lira! informationen i ett annat fält, det som
  kan användas till vad som helst enlig ID3v2-standarden.

