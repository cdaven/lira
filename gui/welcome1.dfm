object Welcome1Form: TWelcome1Form
  Left = 321
  Top = 181
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsDialog
  Caption = 'V'#228'lkommen till Lira!'
  ClientHeight = 343
  ClientWidth = 452
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 16
    Top = 16
    Width = 111
    Height = 13
    Caption = 'V'#228'lkommen till Lira!'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 16
    Top = 39
    Width = 413
    Height = 143
    Caption = 
      'Med Lira! kan du p'#229' ett enkelt s'#228'tt organisera och spela upp din' +
      'a musikfiler.'#13#10#13#10'Du m'#229'ste f'#246'rst och fr'#228'mst tala om f'#246'r programme' +
      't var p'#229' h'#229'rddisken du har dina musikfiler.'#13#10#13#10'Lira! fungerar s'#229 +
      ' att du anger en mapp som huvudmapp f'#246'r din musiksamling. Progra' +
      'mmet s'#246'ker sedan rekursivt igenom alla undermappar till denna oc' +
      'h registrerar alla musikfiler. N'#228'r du l'#228'gger till nya filer, fly' +
      'ttar eller tar bort gamla s'#229' k'#228'nner Lira! av detta vid uppstart.' +
      #13#10#13#10'Klicka p'#229' Ange huvudmapp-knappen f'#246'r att v'#228'lja huvudmapp f'#246'r' +
      ' musiksamlingen.'
    WordWrap = True
  end
  object PreMainFolderLabel: TLabel
    Left = 16
    Top = 232
    Width = 115
    Height = 13
    Caption = 'Angiven huvudmapp '#228'r:'
    Visible = False
  end
  object MainFolderLabel: TLabel
    Left = 160
    Top = 232
    Width = 233
    Height = 13
    AutoSize = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object MainFolderButton: TButton
    Left = 16
    Top = 194
    Width = 129
    Height = 25
    Caption = 'Ange &huvudmapp'
    TabOrder = 0
    OnClick = MainFolderButtonClick
  end
  object NextButton: TButton
    Left = 288
    Top = 304
    Width = 75
    Height = 25
    Caption = '&N'#228'sta >>'
    Default = True
    Enabled = False
    TabOrder = 1
    OnClick = NextButtonClick
  end
  object CancelButton: TButton
    Left = 368
    Top = 304
    Width = 75
    Height = 25
    Cancel = True
    Caption = '&Avbryt'
    TabOrder = 2
    OnClick = CancelButtonClick
  end
end
