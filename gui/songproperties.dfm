object SongPropertiesForm: TSongPropertiesForm
  Left = 249
  Top = 184
  BorderStyle = bsDialog
  Caption = 'Egenskaper'
  ClientHeight = 253
  ClientWidth = 607
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  ShowHint = True
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 16
    Top = 76
    Width = 62
    Height = 13
    Caption = 'Artist/grupp:'
  end
  object Label3: TLabel
    Left = 16
    Top = 108
    Width = 33
    Height = 13
    Caption = 'Album:'
  end
  object Label1: TLabel
    Left = 16
    Top = 49
    Width = 37
    Height = 13
    Caption = 'L'#229'ttitel:'
  end
  object Label4: TLabel
    Left = 16
    Top = 136
    Width = 39
    Height = 13
    Caption = 'Sp'#229'r nr:'
  end
  object Label5: TLabel
    Left = 140
    Top = 136
    Width = 84
    Height = 13
    Caption = 'Utgivningsdatum:'
  end
  object Label6: TLabel
    Left = 16
    Top = 164
    Width = 33
    Height = 13
    Caption = 'Genre:'
  end
  object Label7: TLabel
    Left = 16
    Top = 192
    Width = 58
    Height = 13
    Caption = 'Kommentar:'
  end
  object Label11: TLabel
    Left = 16
    Top = 16
    Width = 40
    Height = 13
    Caption = 'Filnamn:'
  end
  object FileNameLabel: TLabel
    Left = 88
    Top = 16
    Width = 505
    Height = 17
    AutoSize = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object ArtistEdit: TEdit
    Left = 88
    Top = 74
    Width = 201
    Height = 21
    TabOrder = 1
  end
  object TitleEdit: TEdit
    Left = 88
    Top = 44
    Width = 201
    Height = 21
    TabOrder = 0
  end
  object TrackEdit: TEdit
    Left = 88
    Top = 132
    Width = 41
    Height = 21
    Hint = 'Formatet '#228'r xx/yy d'#228'r yy '#228'r totala antalet sp'#229'r'
    MaxLength = 5
    TabOrder = 3
  end
  object CancelButton: TButton
    Left = 516
    Top = 212
    Width = 75
    Height = 25
    Cancel = True
    Caption = '&Avbryt'
    ModalResult = 2
    TabOrder = 9
  end
  object OKButton: TButton
    Left = 428
    Top = 212
    Width = 75
    Height = 25
    Caption = '&OK'
    Default = True
    TabOrder = 8
    OnClick = OKButtonClick
  end
  object YearEdit: TEdit
    Left = 232
    Top = 132
    Width = 57
    Height = 21
    Hint = 'Formatet '#228'r '#197#197#197#197'MMDD, eller bara '#197#197#197#197' eller '#197#197#197#197'MM'
    MaxLength = 8
    TabOrder = 4
  end
  object GenreComboBox: TComboBox
    Left = 88
    Top = 160
    Width = 201
    Height = 21
    Hint = 'V'#228'lj en genre i listan eller definiera en egen'
    DropDownCount = 9
    ItemHeight = 13
    TabOrder = 5
    Items.Strings = (
      'Rock'
      'Alternative Rock'
      'Indierock'
      'Dream-Pop'
      'Brit-Pop'
      'Gothic Rock'
      'Grunge'
      'College Rock'
      'Lo-Fi'
      'New Wave'
      'Synt-pop'
      'Punk'
      'Acid Punk'
      'N-punk'
      'Polsk Punk'
      'H'#229'rdrock'
      'Southern Rock'
      'Metal'
      'Heavy Metal'
      'Black Metal'
      'Thrash Metal'
      'Death Metal'
      'Primus'
      'Rock & Roll'
      'Instrumental rock'
      'Rockabilly'
      'Psykedelisk rock'
      'Garage Rock'
      'Progressiv rock'
      'Symfonisk rock'
      'Pop'
      'Europop'
      'Topp 40'
      'Japansk pop'
      'Country-Rock'
      'Slow Rock'
      'Soft Rock'
      'Merseybeat'
      '--------'
      'Dance'
      'Freestyle'
      'Eurodance'
      'Club'
      'Club-House'
      'Disco'
      '--------'
      'R&B'
      'Soul'
      'Rhythmic Soul'
      'Motown'
      'Funk'
      'Pop/Funk'
      'Doo Wop'
      'Urban'
      'Quiet Storm'
      '--------'
      'Hip-hop'
      'Rap'
      'Gangsta Rap'
      'Bass Music'
      'Miami Bass'
      '--------'
      'Blues'
      'Chicago Blues'
      'Texas Blues'
      'Country Blues'
      'Blues-Rock'
      'Piano Blues'
      '--------'
      'Jazz'
      'Swing'
      'Bebop'
      'Jazz-Funk'
      'Fusion'
      'Fast Fusion'
      'Soul Jazz'
      'New Orleans'
      '--------'
      'Country'
      'Bluegrass'
      'Honky Tonk'
      'Country-Pop'
      '--------'
      'Reggae'
      'Dancehall'
      'Ska'
      'Dub'
      '--------'
      'Electronica'
      'Ambient'
      'Acid Jazz'
      'Industrial'
      'Darkwave'
      'House'
      'Euro-House'
      'Acid House'
      'Techno'
      'Euro-Techno'
      'Techno-Industrial'
      'Drum & Bass'
      'Jungle'
      'Breakbeat'
      'Trip-Hop'
      'Hardcore Techno'
      'Rave'
      'Terrorcore'
      'Happy Hardcore'
      'Trance'
      'Goa'
      '--------'
      'Klassiskt'
      'Kammarmusik'
      'Opera'
      'Sonat'
      'Symfoni'
      'Medeltida'
      'Barock'
      'Romantisk'
      'Ren'#228'ssans'
      'Impressionist'
      'Expressionist'
      '--------'
      'Soundtrack'
      'Filmmusik'
      'Trailer'
      'Porn Groove'
      'TV-musik'
      'Musikal'
      'Dataspel'
      'Anime '
      '--------'
      'Gospel'
      'Black Gospel'
      'Contemporary Christian'
      'Christian Rock'
      'Christian Rap'
      'Christian Gangsta Rap'
      'Lovs'#229'ng'
      '--------'
      'Vokal'
      'Showtunes'
      'A cappella'
      'Kabar'#233
      'K'#246'rs'#229'ng'
      'Ballad'
      'Duett'
      'Gregoriansk s'#229'ng'
      'Power Ballad'
      'Vokalistgrupp'
      'Barbershop'
      '--------'
      'New Age'
      'Avslappning'
      'Neo-klassisk'
      'Natur'
      'Meditativ'
      'Space'
      '--------'
      'L'#228'ttlyssnat'
      'Hissmusik'
      'Polka'
      'Orkestral'
      'Mood Music'
      'Instrumental pop'
      '--------'
      'Folkmusik'
      'Folk-Pop'
      'Folk-Rock'
      'National Folk'
      'Amerikansk indian'
      'Chanson'
      'Folkvisa'
      '--------'
      'V'#228'rldsmusik'
      'Etnisk'
      'Afrikansk'
      'Folklore'
      'Keltisk'
      'Latinsk'
      'Tango'
      'Merengue'
      'Salsa'
      'Samba'
      'Bossanova'
      '--------'
      'Avant-Garde'
      'Improviserad musik'
      'Sound Art'
      'Noise'
      '--------'
      'Alternative'
      'Akustisk'
      'Crossover'
      'Hardcore'
      'Humor'
      'Spratt'
      'Satir'
      'Tal'
      'Ljudklipp'
      'Trumsolo'
      'Slow Jam'
      'Kult'
      'Revival'
      'Retro'
      'Tribal'
      'Oldies'
      'Instrumental')
  end
  object GroupBox1: TGroupBox
    Left = 320
    Top = 40
    Width = 273
    Height = 125
    Caption = 'Subjektiv bed'#246'mning'
    TabOrder = 7
    object Label8: TLabel
      Left = 28
      Top = 32
      Width = 32
      Height = 13
      Caption = 'Betyg:'
    end
    object Label9: TLabel
      Left = 28
      Top = 60
      Width = 36
      Height = 13
      Caption = 'Tillf'#228'lle:'
    end
    object Label10: TLabel
      Left = 28
      Top = 88
      Width = 35
      Height = 13
      Caption = 'Hum'#246'r:'
    end
    object RatingComboBox: TComboBox
      Left = 76
      Top = 28
      Width = 165
      Height = 21
      Hint = 'Ange hur bra du tycker att l'#229'ten '#228'r'
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 0
      Items.Strings = (
        '5 - Utm'#228'rkt'
        '4 - Mycket bra'
        '3 - Bra'
        '2 - OK'
        '1 - D'#229'lig')
    end
    object SituationComboBox: TComboBox
      Left = 76
      Top = 56
      Width = 165
      Height = 21
      Hint = 'Ange det tillf'#228'lle d'#229' denna l'#229't g'#246'r sig b'#228'st'
      ItemHeight = 13
      TabOrder = 1
      Items.Strings = (
        'Avkoppling'
        'Bakgrund'
        'Dans'
        'Fest'
        'Middag'
        'Romantik')
    end
    object MoodComboBox: TComboBox
      Left = 76
      Top = 84
      Width = 165
      Height = 21
      Hint = 'Ange vilket hum'#246'r du tycker att l'#229'ten f'#246'rmedlar'
      ItemHeight = 13
      TabOrder = 2
      Items.Strings = (
        'D'#229'sig'
        'Glad'
        'L'#228'tt'
        'Stillsam'
        'Surmulen'
        'Vild')
    end
  end
  object CommentMemo: TMemo
    Left = 88
    Top = 188
    Width = 201
    Height = 49
    ScrollBars = ssVertical
    TabOrder = 6
  end
  object AlbumEdit: TEdit
    Left = 88
    Top = 104
    Width = 201
    Height = 21
    TabOrder = 2
  end
end
