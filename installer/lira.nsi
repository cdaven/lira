!define VERSION "1.0.0"

LoadLanguageFile "${NSISDIR}\Contrib\Language files\Swedish.nlf"

Name "Lira!"

OutFile "lira-${VERSION}.exe"
InstallDir $PROGRAMFILES\Lira

InstallDirRegKey HKLM SOFTWARE\Lira! "Install Dir"

ComponentText "Lira! ${VERSION} kommer installeras på din dator."
DirText "Lira! ${VERSION} kommer installeras på din dator."

Section "Programfiler (krävs)"

  SectionIn RO
  SetOutPath $INSTDIR
  File "lira.exe"
  File "id3lib.dll"
  File "readme.txt"
  WriteRegStr HKLM SOFTWARE\Lira! "Install Dir" "$INSTDIR"

  ; Skriver värden för avinstallation till registret
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Lira!" "DisplayName" "Lira!"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Lira!" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteUninstaller "uninstall.exe"

SectionEnd

Section "Genvägar på startmenyn"

  CreateDirectory "$SMPROGRAMS\Lira!"
  CreateShortCut "$SMPROGRAMS\Lira!\Avinstallera.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  CreateShortCut "$SMPROGRAMS\Lira!\Lira!.lnk" "$INSTDIR\lira.exe" "" "$INSTDIR\lira.exe" 0

SectionEnd

Section "Läs readme.txt efter installation"

  ExecShell open "$INSTDIR\readme.txt"

SectionEnd

; --------------------------------
; Uninstall
; --------------------------------

UninstallText "Detta avinstallerar Lira! Tryck på nästa för att fortsätta."

Section "Uninstall"
  
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Lira!"
  DeleteRegKey HKLM SOFTWARE\Lira!

  Delete $INSTDIR\lira.exe
  Delete $INSTDIR\id3lib.exe
  Delete $INSTDIR\readme.txt
  Delete $INSTDIR\uninstall.exe

  Delete "$SMPROGRAMS\Lira!\*.*"

  RMDir "$SMPROGRAMS\Lira!"
  RMDir "$INSTDIR"

SectionEnd

