object AboutForm: TAboutForm
  Left = 213
  Top = 184
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Om Lira!'
  ClientHeight = 258
  ClientWidth = 235
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
  object VersionLabel: TLabel
    Left = 20
    Top = 48
    Width = 197
    Height = 13
    AutoSize = False
    Caption = 'Version 1.0.0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGrayText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label1: TLabel
    Left = 20
    Top = 20
    Width = 36
    Height = 19
    Caption = 'Lira!'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 20
    Top = 72
    Width = 209
    Height = 133
    AutoSize = False
    Caption = 
      'Copyright 2003 Christian Dav'#233'n'#13#10#13#10'Lira! '#228'r gratis och f'#229'r anv'#228'nd' +
      'as fritt s'#229' l'#228'nge som ingen del av programmet '#228'r modifierat.'#13#10#13#10 +
      'Utvecklaren ansvarar inte f'#246'r eventuella dataf'#246'rluster eller ann' +
      'an skada som kan uppst'#229' vid anv'#228'ndning av programmet. Anv'#228'ndning' +
      ' sker p'#229' egen risk.'
    WordWrap = True
  end
  object OkButton: TButton
    Left = 144
    Top = 224
    Width = 75
    Height = 25
    Cancel = True
    Caption = '&OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
end
