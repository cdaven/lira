object SettingsForm: TSettingsForm
  Left = 393
  Top = 352
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsDialog
  Caption = 'Inst'#228'llningar'
  ClientHeight = 246
  ClientWidth = 340
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 20
    Top = 24
    Width = 83
    Height = 13
    Caption = 'Vald huvudmapp:'
  end
  object MainFolderLabel: TLabel
    Left = 120
    Top = 24
    Width = 201
    Height = 17
    AutoSize = False
  end
  object Label2: TLabel
    Left = 20
    Top = 112
    Width = 90
    Height = 13
    Caption = 'S'#246'kv'#228'g till spelare:'
  end
  object PlayerPathLabel: TLabel
    Left = 120
    Top = 112
    Width = 201
    Height = 17
    AutoSize = False
  end
  object MainFolderButton: TButton
    Left = 20
    Top = 50
    Width = 129
    Height = 25
    Caption = #196'ndra &huvudmapp'
    TabOrder = 0
    OnClick = MainFolderButtonClick
  end
  object WinampRadioButton: TRadioButton
    Left = 20
    Top = 136
    Width = 77
    Height = 17
    Caption = 'Winamp 2.x'
    TabOrder = 1
    OnClick = WinampRadioButtonClick
  end
  object WMPRadioButton: TRadioButton
    Left = 20
    Top = 160
    Width = 189
    Height = 17
    Caption = 'Windows Media Player 8, 9 eller XP'
    TabOrder = 2
    OnClick = WMPRadioButtonClick
  end
  object CancelButton: TButton
    Left = 252
    Top = 208
    Width = 75
    Height = 25
    Cancel = True
    Caption = '&Avbryt'
    ModalResult = 2
    TabOrder = 4
  end
  object OkButton: TButton
    Left = 168
    Top = 208
    Width = 75
    Height = 25
    Caption = '&OK'
    Default = True
    ModalResult = 1
    TabOrder = 3
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'exe'
    Filter = 'Exekverbara filer (*.exe)|*.exe'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing, ofDontAddToRecent]
    Left = 20
    Top = 204
  end
end
