object Welcome2Form: TWelcome2Form
  Left = 411
  Top = 214
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
  object Label3: TLabel
    Left = 16
    Top = 16
    Width = 417
    Height = 182
    Caption = 
      'Om du vill spela upp dina musikfiler genom Lira! m'#229'ste du f'#246'rst ' +
      'tala om f'#246'r programmet vilken musikspelare du vill anv'#228'nda. Du k' +
      'an v'#228'lja mellan Winamp 2 och Windows Media Player.'#13#10#13#10'Har du Win' +
      'amp med versionsnummer 2.x (tv'#229'-punkt-vadsomhelst), och du vill ' +
      'anv'#228'nda det, klickar du p'#229' Winamp-knappen. Observera att Winamp ' +
      '3 ocks'#229' fungerar om du har installerat insticksprogrammet Winamp' +
      ' 2x Plugin Manager.'#13#10#13#10'Har du ist'#228'llet Windows Media Player vers' +
      'ion 8, 9 eller XP (den senare installeras automatiskt med Window' +
      's XP), och du vill anv'#228'nda det, klickar du p'#229' Windows Media Play' +
      'er-knappen.'#13#10#13#10'Lira! fungerar b'#228'st med Winamp. Du kan n'#228'r som he' +
      'lst byta f'#246'rvald musikspelare i inst'#228'llningarna.'
    WordWrap = True
  end
  object PrePlayerTypeLabel: TLabel
    Left = 16
    Top = 250
    Width = 120
    Height = 13
    Caption = 'Angiven musikspelare '#228'r:'
    Visible = False
  end
  object PlayerTypeLabel: TLabel
    Left = 192
    Top = 250
    Width = 201
    Height = 13
    AutoSize = False
  end
  object PrePlayerPathLabel: TLabel
    Left = 16
    Top = 272
    Width = 157
    Height = 13
    Caption = 'S'#246'kv'#228'g till angiven musikspelare:'
    Visible = False
  end
  object PlayerPathLabel: TLabel
    Left = 192
    Top = 272
    Width = 250
    Height = 13
    AutoSize = False
  end
  object WinampButton: TButton
    Left = 16
    Top = 212
    Width = 129
    Height = 25
    Caption = 'Win&amp'
    TabOrder = 0
    OnClick = WinampButtonClick
  end
  object WMPButton: TButton
    Left = 152
    Top = 212
    Width = 129
    Height = 25
    Caption = 'Windows &Media Player'
    TabOrder = 1
    OnClick = WMPButtonClick
  end
  object StartButton: TButton
    Left = 288
    Top = 304
    Width = 75
    Height = 25
    Caption = '&Starta'
    Default = True
    Enabled = False
    TabOrder = 2
    OnClick = StartButtonClick
  end
  object CancelButton: TButton
    Left = 368
    Top = 304
    Width = 75
    Height = 25
    Cancel = True
    Caption = '&Avbryt'
    TabOrder = 3
    OnClick = CancelButtonClick
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'exe'
    Filter = 'Exekverbara filer (*.exe)|*.exe'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing, ofDontAddToRecent]
    Left = 16
    Top = 296
  end
end
