object MainForm: TMainForm
  Left = 288
  Top = 214
  Width = 670
  Height = 441
  Caption = 'Lira!'
  Color = clBtnFace
  Constraints.MinHeight = 100
  Constraints.MinWidth = 100
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar: TStatusBar
    Left = 0
    Top = 376
    Width = 662
    Height = 19
    Panels = <>
    SimplePanel = True
  end
  object Panel1: TPanel
    Left = 153
    Top = 0
    Width = 509
    Height = 376
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object SongList: TListView
      Left = 0
      Top = 0
      Width = 509
      Height = 376
      Align = alClient
      Columns = <
        item
          Caption = 'L'#229'ttitel'
          MinWidth = 10
          Width = 150
        end
        item
          Caption = 'Artist'
          MinWidth = 10
          Width = 150
        end
        item
          Caption = 'Album'
          MinWidth = 10
          Width = 150
        end
        item
          Caption = 'Genre'
          MinWidth = 10
          Width = 70
        end
        item
          Caption = 'Utgiven'
          MinWidth = 10
        end
        item
          Caption = 'Filnamn'
          MinWidth = 10
          Width = 250
        end>
      Constraints.MinHeight = 50
      Constraints.MinWidth = 200
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      FullDrag = True
      GridLines = True
      HideSelection = False
      MultiSelect = True
      ReadOnly = True
      RowSelect = True
      ParentFont = False
      PopupMenu = SongListPopupMenu
      TabOrder = 0
      ViewStyle = vsReport
      OnColumnClick = SongListColumnClick
      OnCompare = SongListCompare
      OnDblClick = SongListDblClick
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 153
    Height = 376
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 2
    object LMDButton1: TLMDButton
      Left = 24
      Top = 16
      Width = 97
      Height = 25
      Caption = 'Genre'
      TabOrder = 0
      Visible = True
      ButtonLayout.Alignment = agCenterRight
      ButtonLayout.OffsetX = -5
      ButtonLayout.Arrow = True
      ButtonLayout.ArrowColor = clBtnText
      ButtonLayout.ArrowIndent = 4
      ButtonLayout.ArrowSize = 4
      DropDownMenu = GenrePopupMenu
      DropDownRight = True
    end
    object LMDButton2: TLMDButton
      Left = 24
      Top = 48
      Width = 97
      Height = 25
      Caption = 'Artist'
      TabOrder = 1
      Visible = True
      ButtonLayout.Alignment = agCenterRight
      ButtonLayout.OffsetX = -5
      ButtonLayout.Arrow = True
      ButtonLayout.ArrowIndent = 4
      ButtonLayout.ArrowSize = 4
      DropDownMenu = ArtistPopupMenu
      DropDownRight = True
    end
    object LMDButton3: TLMDButton
      Left = 24
      Top = 80
      Width = 97
      Height = 25
      Caption = #197'rtal'
      TabOrder = 2
      Visible = True
      ButtonLayout.Alignment = agCenterRight
      ButtonLayout.OffsetX = -5
      ButtonLayout.Arrow = True
      ButtonLayout.ArrowIndent = 4
      ButtonLayout.ArrowSize = 4
      DropDownMenu = YearPopupMenu
      DropDownRight = True
    end
    object LMDButton4: TLMDButton
      Left = 24
      Top = 112
      Width = 97
      Height = 25
      Caption = 'Betyg'
      TabOrder = 3
      Visible = True
      ButtonLayout.Alignment = agCenterRight
      ButtonLayout.OffsetX = -5
      ButtonLayout.Arrow = True
      ButtonLayout.ArrowIndent = 4
      ButtonLayout.ArrowSize = 4
      DropDownMenu = RatingPopupMenu
      DropDownRight = True
    end
    object LMDButton5: TLMDButton
      Left = 24
      Top = 144
      Width = 97
      Height = 25
      Caption = 'Tillf'#228'lle'
      TabOrder = 4
      Visible = True
      ButtonLayout.Alignment = agCenterRight
      ButtonLayout.OffsetX = -5
      ButtonLayout.Arrow = True
      ButtonLayout.ArrowIndent = 4
      ButtonLayout.ArrowSize = 4
      DropDownMenu = SituationPopupMenu
      DropDownRight = True
    end
    object LMDButton6: TLMDButton
      Left = 24
      Top = 176
      Width = 97
      Height = 25
      Caption = 'Hum'#246'r'
      TabOrder = 5
      Visible = True
      ButtonLayout.Alignment = agCenterRight
      ButtonLayout.OffsetX = -5
      ButtonLayout.Arrow = True
      ButtonLayout.ArrowIndent = 4
      ButtonLayout.ArrowSize = 4
      DropDownMenu = MoodPopupMenu
      DropDownRight = True
    end
    object ShowAllButton: TButton
      Left = 24
      Top = 232
      Width = 97
      Height = 25
      Caption = 'Visa alla'
      TabOrder = 6
      OnClick = ShowAllButtonClick
    end
  end
  object GenrePopupMenu: TPopupMenu
    Left = 112
    Top = 48
    object Rock1: TMenuItem
      Caption = 'Rock'
      object Rock2: TMenuItem
        Caption = 'Rock'
        OnClick = Genre1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object AlternativeRock1: TMenuItem
        Caption = 'Alternative Rock'
        object AlternativeRock2: TMenuItem
          Caption = 'Alternative Rock'
          OnClick = Genre1Click
        end
        object N6: TMenuItem
          Caption = '-'
        end
        object BritPop1: TMenuItem
          Caption = 'Brit-Pop'
          OnClick = Genre1Click
        end
        object CollegeRock1: TMenuItem
          Caption = 'College Rock'
          OnClick = Genre1Click
        end
        object DreamPop1: TMenuItem
          Caption = 'Dream-Pop'
          OnClick = Genre1Click
        end
        object GothicRock1: TMenuItem
          Caption = 'Gothic Rock'
          OnClick = GothicRock1Click
        end
        object Grunge1: TMenuItem
          Caption = 'Grunge'
          OnClick = Genre1Click
        end
        object Indierock1: TMenuItem
          Caption = 'Indierock'
          OnClick = Genre1Click
        end
        object LoFi1: TMenuItem
          Caption = 'Lo-Fi'
          OnClick = Genre1Click
        end
      end
      object CountryRock1: TMenuItem
        Caption = 'Country-Rock'
        OnClick = Genre1Click
      end
      object Hrdrock1: TMenuItem
        Caption = 'H'#229'rdrock'
        object Hrdrock2: TMenuItem
          Caption = 'H'#229'rdrock'
          OnClick = Genre1Click
        end
        object N3: TMenuItem
          Caption = '-'
        end
        object Metal1: TMenuItem
          Caption = 'Metal'
          object Metal2: TMenuItem
            Caption = 'Metal'
            OnClick = Genre1Click
          end
          object N4: TMenuItem
            Caption = '-'
          end
          object BlackMetal1: TMenuItem
            Caption = 'Black Metal'
            OnClick = Genre1Click
          end
          object DeathMetal1: TMenuItem
            Caption = 'Death Metal'
            OnClick = Genre1Click
          end
          object HeavyMetal1: TMenuItem
            Caption = 'Heavy Metal'
            OnClick = Genre1Click
          end
          object Primus1: TMenuItem
            Caption = 'Primus'
            OnClick = Genre1Click
          end
          object ThrashMetal1: TMenuItem
            Caption = 'Thrash Metal'
            OnClick = Genre1Click
          end
        end
        object SouthernRock1: TMenuItem
          Caption = 'Southern Rock'
          OnClick = Genre1Click
        end
      end
      object Merseybeat1: TMenuItem
        Caption = 'Merseybeat'
        OnClick = Genre1Click
      end
      object NewWave1: TMenuItem
        Caption = 'New Wave'
        object NewWave2: TMenuItem
          Caption = 'New Wave'
          OnClick = Genre1Click
        end
        object N49: TMenuItem
          Caption = '-'
        end
        object Syntpop1: TMenuItem
          Caption = 'Synt-pop'
          OnClick = Genre1Click
        end
      end
      object Pop1: TMenuItem
        Caption = 'Pop'
        object Pop2: TMenuItem
          Caption = 'Pop'
          OnClick = Genre1Click
        end
        object N2: TMenuItem
          Caption = '-'
        end
        object Europop1: TMenuItem
          Caption = 'Europop'
          OnClick = Genre1Click
        end
        object Japanskpop1: TMenuItem
          Caption = 'Japansk pop'
          OnClick = Genre1Click
        end
        object Topp401: TMenuItem
          Caption = 'Topp 40'
          OnClick = Genre1Click
        end
      end
      object ProgressivRock1: TMenuItem
        Caption = 'Progressiv rock'
        object ProgressivRock2: TMenuItem
          Caption = 'Progressiv Rock'
          OnClick = Genre1Click
        end
        object N8: TMenuItem
          Caption = '-'
        end
        object Symfoniskrock1: TMenuItem
          Caption = 'Symfonisk rock'
          OnClick = Genre1Click
        end
      end
      object PsykedeliskRock1: TMenuItem
        Caption = 'Psykedelisk rock'
        object Psykedeliskrock2: TMenuItem
          Caption = 'Psykedelisk rock'
          OnClick = Psykedeliskrock2Click
        end
        object N9: TMenuItem
          Caption = '-'
        end
        object GarageRock1: TMenuItem
          Caption = 'Garage Rock'
          OnClick = Genre1Click
        end
      end
      object Punk1: TMenuItem
        Caption = 'Punk'
        object Punk2: TMenuItem
          Caption = 'Punk'
          OnClick = Punk2Click
        end
        object N7: TMenuItem
          Caption = '-'
        end
        object AcidPunk1: TMenuItem
          Caption = 'Acid Punk'
          OnClick = Genre1Click
        end
        object Negerpunk1: TMenuItem
          Caption = 'N-punk'
          OnClick = Genre1Click
        end
        object PolskPunk1: TMenuItem
          Caption = 'Polsk Punk'
          OnClick = Genre1Click
        end
      end
      object RocknRoll1: TMenuItem
        Caption = 'Rock && Roll'
        object RockRoll1: TMenuItem
          Caption = 'Rock && Roll'
          OnClick = RockRoll1Click
        end
        object N5: TMenuItem
          Caption = '-'
        end
        object Instrumentalrock1: TMenuItem
          Caption = 'Instrumental rock'
          OnClick = Genre1Click
        end
        object Rockabilly1: TMenuItem
          Caption = 'Rockabilly'
          OnClick = Genre1Click
        end
      end
      object SlowRock1: TMenuItem
        Caption = 'Slow Rock'
        OnClick = Genre1Click
      end
      object SoftRock1: TMenuItem
        Caption = 'Soft Rock'
        OnClick = Genre1Click
      end
    end
    object Dance2: TMenuItem
      Caption = 'Dance'
      object Dance3: TMenuItem
        Caption = 'Dance'
        OnClick = Genre1Click
      end
      object N17: TMenuItem
        Caption = '-'
      end
      object Club1: TMenuItem
        Caption = 'Club'
        object Club2: TMenuItem
          Caption = 'Club'
          OnClick = Genre1Click
        end
        object N18: TMenuItem
          Caption = '-'
        end
        object ClubHouse1: TMenuItem
          Caption = 'Club-House'
          OnClick = Genre1Click
        end
      end
      object Disco1: TMenuItem
        Caption = 'Disco'
        OnClick = Genre1Click
      end
      object Freestyle1: TMenuItem
        Caption = 'Freestyle'
        OnClick = Genre1Click
      end
      object Eurodance1: TMenuItem
        Caption = 'Eurodance'
        OnClick = Genre1Click
      end
    end
    object RB2: TMenuItem
      Caption = 'R&&B'
      object RB1: TMenuItem
        Caption = 'R&&B'
        OnClick = Genre1Click
      end
      object N11: TMenuItem
        Caption = '-'
      end
      object DooWop1: TMenuItem
        Caption = 'Doo Wop'
        OnClick = Genre1Click
      end
      object Funk1: TMenuItem
        Caption = 'Funk'
        object Funk2: TMenuItem
          Caption = 'Funk'
          OnClick = Genre1Click
        end
        object N12: TMenuItem
          Caption = '-'
        end
        object PopFunk1: TMenuItem
          Caption = 'Pop/Funk'
          OnClick = Genre1Click
        end
      end
      object QuietStorm1: TMenuItem
        Caption = 'Quiet Storm'
        OnClick = Genre1Click
      end
      object Urban1: TMenuItem
        Caption = 'Urban'
        OnClick = Genre1Click
      end
      object Soul2: TMenuItem
        Caption = 'Soul'
        object Soul3: TMenuItem
          Caption = 'Soul'
          OnClick = Genre1Click
        end
        object N13: TMenuItem
          Caption = '-'
        end
        object Motown1: TMenuItem
          Caption = 'Motown'
          OnClick = Genre1Click
        end
        object RhythmicSoul1: TMenuItem
          Caption = 'Rhythmic Soul'
          OnClick = Genre1Click
        end
      end
    end
    object Hiphop1: TMenuItem
      Caption = 'Hip-hop'
      object Hiphop2: TMenuItem
        Caption = 'Hip-hop'
        OnClick = Genre1Click
      end
      object N19: TMenuItem
        Caption = '-'
      end
      object BassMusic1: TMenuItem
        Caption = 'Bass Music'
        object BassMusic2: TMenuItem
          Caption = 'Bass Music'
          OnClick = Genre1Click
        end
        object N20: TMenuItem
          Caption = '-'
        end
        object MiamiBass1: TMenuItem
          Caption = 'Miami Bass'
          OnClick = Genre1Click
        end
      end
      object Rap1: TMenuItem
        Caption = 'Rap'
        object Rap2: TMenuItem
          Caption = 'Rap'
          OnClick = Genre1Click
        end
        object N21: TMenuItem
          Caption = '-'
        end
        object GangstaRap1: TMenuItem
          Caption = 'Gangsta Rap'
          OnClick = Genre1Click
        end
      end
    end
    object Blues2: TMenuItem
      Caption = 'Blues'
      object Blues1: TMenuItem
        Caption = 'Blues'
        OnClick = Genre1Click
      end
      object N10: TMenuItem
        Caption = '-'
      end
      object BluesRock1: TMenuItem
        Caption = 'Blues-Rock'
        OnClick = Genre1Click
      end
      object ChicagoBlues1: TMenuItem
        Caption = 'Chicago Blues'
        OnClick = Genre1Click
      end
      object CountryBlues1: TMenuItem
        Caption = 'Country Blues'
        OnClick = Genre1Click
      end
      object PianoBlues1: TMenuItem
        Caption = 'Piano Blues'
        OnClick = Genre1Click
      end
      object TexasBlues1: TMenuItem
        Caption = 'Texas Blues'
        OnClick = Genre1Click
      end
    end
    object Jazz2: TMenuItem
      Caption = 'Jazz'
      object Jazz1: TMenuItem
        Caption = 'Jazz'
        OnClick = Genre1Click
      end
      object N14: TMenuItem
        Caption = '-'
      end
      object Bebop1: TMenuItem
        Caption = 'Bebop'
        OnClick = Genre1Click
      end
      object Fusion1: TMenuItem
        Caption = 'Fusion'
        object Fusion2: TMenuItem
          Caption = 'Fusion'
          OnClick = Genre1Click
        end
        object N15: TMenuItem
          Caption = '-'
        end
        object FastFusion1: TMenuItem
          Caption = 'Fast Fusion'
          OnClick = Genre1Click
        end
      end
      object JazzFunk1: TMenuItem
        Caption = 'Jazz-Funk'
        OnClick = Genre1Click
      end
      object NewOrleans1: TMenuItem
        Caption = 'New Orleans'
        OnClick = Genre1Click
      end
      object SoulJazz1: TMenuItem
        Caption = 'Soul Jazz'
        OnClick = Genre1Click
      end
      object Swing1: TMenuItem
        Caption = 'Swing'
        OnClick = Swing1Click
      end
    end
    object Country1: TMenuItem
      Caption = 'Country'
      object Country2: TMenuItem
        Caption = 'Country'
        OnClick = Genre1Click
      end
      object N23: TMenuItem
        Caption = '-'
      end
      object Bluegrass1: TMenuItem
        Caption = 'Bluegrass'
        OnClick = Genre1Click
      end
      object CountryPop1: TMenuItem
        Caption = 'Country-Pop'
        OnClick = Genre1Click
      end
      object Honkytonk1: TMenuItem
        Caption = 'Honky Tonk'
        OnClick = Genre1Click
      end
    end
    object Reggae1: TMenuItem
      Caption = 'Reggae'
      object Reggae2: TMenuItem
        Caption = 'Reggae'
        OnClick = Genre1Click
      end
      object N22: TMenuItem
        Caption = '-'
      end
      object Dancehall1: TMenuItem
        Caption = 'Dancehall'
        OnClick = Genre1Click
      end
      object Dub1: TMenuItem
        Caption = 'Dub'
        OnClick = Genre1Click
      end
      object Ska1: TMenuItem
        Caption = 'Ska'
        OnClick = Genre1Click
      end
    end
    object Electronica1: TMenuItem
      Caption = 'Electronica'
      object Electronica2: TMenuItem
        Caption = 'Electronica'
        OnClick = Genre1Click
      end
      object N24: TMenuItem
        Caption = '-'
      end
      object AcidJazz1: TMenuItem
        Caption = 'Acid Jazz'
        OnClick = Genre1Click
      end
      object Ambient1: TMenuItem
        Caption = 'Ambient'
        OnClick = Genre1Click
      end
      object Breakbeat1: TMenuItem
        Caption = 'Breakbeat'
        OnClick = Genre1Click
      end
      object HardcoreTechno1: TMenuItem
        Caption = 'Hardcore Techno'
        object HardcoreTechno2: TMenuItem
          Caption = 'Hardcore Techno'
          OnClick = Genre1Click
        end
        object N29: TMenuItem
          Caption = '-'
        end
        object HappyHardcore1: TMenuItem
          Caption = 'Happy Hardcore'
          OnClick = Genre1Click
        end
        object Rave1: TMenuItem
          Caption = 'Rave'
          OnClick = Genre1Click
        end
        object Terrorcore1: TMenuItem
          Caption = 'Terrorcore'
          OnClick = Genre1Click
        end
      end
      object House1: TMenuItem
        Caption = 'House'
        object House2: TMenuItem
          Caption = 'House'
          OnClick = Genre1Click
        end
        object N26: TMenuItem
          Caption = '-'
        end
        object EuroHouse1: TMenuItem
          Caption = 'Euro-House'
          OnClick = Genre1Click
        end
        object AcidHouse1: TMenuItem
          Caption = 'Acid House'
          OnClick = Genre1Click
        end
      end
      object Industrial1: TMenuItem
        Caption = 'Industrial'
        object Industrial2: TMenuItem
          Caption = 'Industrial'
          OnClick = Genre1Click
        end
        object N25: TMenuItem
          Caption = '-'
        end
        object Darkwave1: TMenuItem
          Caption = 'Darkwave'
          OnClick = Genre1Click
        end
      end
      object Techno1: TMenuItem
        Caption = 'Techno'
        object Techno2: TMenuItem
          Caption = 'Techno'
          OnClick = Genre1Click
        end
        object N27: TMenuItem
          Caption = '-'
        end
        object EuroTechno1: TMenuItem
          Caption = 'Euro-Techno'
          OnClick = Genre1Click
        end
        object TechnoIndustrial1: TMenuItem
          Caption = 'Techno-Industrial'
          OnClick = Genre1Click
        end
        object DrumBass1: TMenuItem
          Caption = 'Drum && Bass'
          object DrumBass2: TMenuItem
            Caption = 'Drum && Bass'
            OnClick = Genre1Click
          end
          object N28: TMenuItem
            Caption = '-'
          end
          object Jungle1: TMenuItem
            Caption = 'Jungle'
            OnClick = Genre1Click
          end
        end
      end
      object Trance1: TMenuItem
        Caption = 'Trance'
        object Trance2: TMenuItem
          Caption = 'Trance'
          OnClick = Genre1Click
        end
        object N30: TMenuItem
          Caption = '-'
        end
        object Goa1: TMenuItem
          Caption = 'Goa'
          OnClick = Genre1Click
        end
      end
      object TripHop1: TMenuItem
        Caption = 'Trip-Hop'
        OnClick = Genre1Click
      end
    end
    object Klassiskt2: TMenuItem
      Caption = 'Klassiskt'
      object Klassiskt1: TMenuItem
        Caption = 'Klassiskt'
        OnClick = Genre1Click
      end
      object N16: TMenuItem
        Caption = '-'
      end
      object Barock1: TMenuItem
        Caption = 'Barock'
        OnClick = Genre1Click
      end
      object Expressionist1: TMenuItem
        Caption = 'Expressionist'
        OnClick = Genre1Click
      end
      object Impressionist1: TMenuItem
        Caption = 'Impressionist'
        OnClick = Genre1Click
      end
      object Kammarmusik1: TMenuItem
        Caption = 'Kammarmusik'
        OnClick = Genre1Click
      end
      object Medeltida1: TMenuItem
        Caption = 'Medeltida'
        OnClick = Genre1Click
      end
      object Opera1: TMenuItem
        Caption = 'Opera'
        OnClick = Genre1Click
      end
      object Renssans1: TMenuItem
        Caption = 'Ren'#228'ssans'
        OnClick = Genre1Click
      end
      object Romantisk1: TMenuItem
        Caption = 'Romantisk'
        OnClick = Genre1Click
      end
      object Sonat1: TMenuItem
        Caption = 'Sonat'
        OnClick = Genre1Click
      end
      object Symfoni1: TMenuItem
        Caption = 'Symfoni'
        OnClick = Genre1Click
      end
    end
    object Soundtrack1: TMenuItem
      Caption = 'Soundtrack'
      object Soundtrack2: TMenuItem
        Caption = 'Soundtrack'
        OnClick = Genre1Click
      end
      object N34: TMenuItem
        Caption = '-'
      end
      object Anime1: TMenuItem
        Caption = 'Anime'
        OnClick = Genre1Click
      end
      object Dataspel1: TMenuItem
        Caption = 'Dataspel'
        OnClick = Genre1Click
      end
      object Filmmusik1: TMenuItem
        Caption = 'Filmmusik'
        object Filmmusik2: TMenuItem
          Caption = 'Filmmusik'
          OnClick = Genre1Click
        end
        object N35: TMenuItem
          Caption = '-'
        end
        object PornGroove1: TMenuItem
          Caption = 'Porn Groove'
          OnClick = Genre1Click
        end
        object Trailer1: TMenuItem
          Caption = 'Trailer'
          OnClick = Genre1Click
        end
      end
      object Musikal1: TMenuItem
        Caption = 'Musikal'
        OnClick = Genre1Click
      end
      object TVmusik1: TMenuItem
        Caption = 'TV-musik'
        OnClick = Genre1Click
      end
    end
    object Gospel1: TMenuItem
      Caption = 'Gospel'
      object Gospel2: TMenuItem
        Caption = 'Gospel'
        OnClick = Genre1Click
      end
      object N31: TMenuItem
        Caption = '-'
      end
      object BlackGospel1: TMenuItem
        Caption = 'Black Gospel'
        OnClick = Genre1Click
      end
      object CCM1: TMenuItem
        Caption = 'Contemporary Christian'
        object CCM2: TMenuItem
          Caption = 'Contemporary Christian'
          OnClick = Genre1Click
        end
        object N32: TMenuItem
          Caption = '-'
        end
        object Kristengangstarap1: TMenuItem
          Caption = 'Christian Gangsta Rap'
          OnClick = Genre1Click
        end
        object Kristenrap1: TMenuItem
          Caption = 'Christian Rap'
          OnClick = Genre1Click
        end
        object Kristenrock1: TMenuItem
          Caption = 'Christian Rock'
          OnClick = Genre1Click
        end
        object Lovsng1: TMenuItem
          Caption = 'Lovs'#229'ng'
          OnClick = Genre1Click
        end
      end
    end
    object Vokal1: TMenuItem
      Caption = 'Vokal'
      object Acappella1: TMenuItem
        Caption = 'A cappella'
        OnClick = Genre1Click
      end
      object Ballad1: TMenuItem
        Caption = 'Ballad'
        OnClick = Genre1Click
      end
      object Barbershop1: TMenuItem
        Caption = 'Barbershop'
        OnClick = Genre1Click
      end
      object Duett1: TMenuItem
        Caption = 'Duett'
        OnClick = Genre1Click
      end
      object Gregoriansksng1: TMenuItem
        Caption = 'Gregoriansk s'#229'ng'
        OnClick = Genre1Click
      end
      object Kabar1: TMenuItem
        Caption = 'Kabar'#233
        OnClick = Genre1Click
      end
      object Krsng1: TMenuItem
        Caption = 'K'#246'rs'#229'ng'
        OnClick = Genre1Click
      end
      object PowerBallad1: TMenuItem
        Caption = 'Power Ballad'
        OnClick = Genre1Click
      end
      object Showtunes1: TMenuItem
        Caption = 'Showtunes'
        OnClick = Genre1Click
      end
      object Vokalistgrupp1: TMenuItem
        Caption = 'Vokalistgrupp'
        OnClick = Genre1Click
      end
    end
    object NewAge2: TMenuItem
      Caption = 'New Age'
      object Avslappning1: TMenuItem
        Caption = 'Avslappning'
        OnClick = Genre1Click
      end
      object Meditativ1: TMenuItem
        Caption = 'Meditativ'
        OnClick = Genre1Click
      end
      object Natur1: TMenuItem
        Caption = 'Natur'
        OnClick = Genre1Click
      end
      object Neoklassisk1: TMenuItem
        Caption = 'Neo-klassisk'
        OnClick = Genre1Click
      end
      object Space1: TMenuItem
        Caption = 'Space'
        OnClick = Genre1Click
      end
    end
    object Lttlyssnat1: TMenuItem
      Caption = 'L'#228'ttlyssnat'
      object Lttlyssnat2: TMenuItem
        Caption = 'L'#228'ttlyssnat'
        OnClick = Genre1Click
      end
      object N33: TMenuItem
        Caption = '-'
      end
      object Instrumentalpop1: TMenuItem
        Caption = 'Instrumental pop'
        OnClick = Genre1Click
      end
      object Hissmusik1: TMenuItem
        Caption = 'Hissmusik'
        OnClick = Genre1Click
      end
      object MoodMusic1: TMenuItem
        Caption = 'Mood Music'
        OnClick = Genre1Click
      end
      object Orkestral1: TMenuItem
        Caption = 'Orkestral'
        OnClick = Genre1Click
      end
      object Polka1: TMenuItem
        Caption = 'Polka'
        OnClick = Genre1Click
      end
    end
    object Folkmusik1: TMenuItem
      Caption = 'Folkmusik'
      object Folkmusik2: TMenuItem
        Caption = 'Folkmusik'
        OnClick = Genre1Click
      end
      object N36: TMenuItem
        Caption = '-'
      end
      object Amerikanskindian1: TMenuItem
        Caption = 'Amerikansk indian'
        OnClick = Genre1Click
      end
      object Chanson1: TMenuItem
        Caption = 'Chanson'
        OnClick = Genre1Click
      end
      object FolkPop1: TMenuItem
        Caption = 'Folk-Pop'
        OnClick = Genre1Click
      end
      object FolkRock1: TMenuItem
        Caption = 'Folk-Rock'
        OnClick = Genre1Click
      end
      object Folkvisa1: TMenuItem
        Caption = 'Folkvisa'
        OnClick = Genre1Click
      end
      object NationalFolk1: TMenuItem
        Caption = 'National Folk'
        OnClick = Genre1Click
      end
    end
    object Vrldsmusik1: TMenuItem
      Caption = 'V'#228'rldsmusik'
      object Vrldsmusik2: TMenuItem
        Caption = 'V'#228'rldsmusik'
        OnClick = Genre1Click
      end
      object N37: TMenuItem
        Caption = '-'
      end
      object Afrikansk1: TMenuItem
        Caption = 'Afrikansk'
        OnClick = Genre1Click
      end
      object Etnisk1: TMenuItem
        Caption = 'Etnisk'
        OnClick = Genre1Click
      end
      object Folklore1: TMenuItem
        Caption = 'Folklore'
        OnClick = Genre1Click
      end
      object Keltisk1: TMenuItem
        Caption = 'Keltisk'
        OnClick = Genre1Click
      end
      object Latinsk1: TMenuItem
        Caption = 'Latinsk'
        object Latinsk2: TMenuItem
          Caption = 'Latinsk'
          OnClick = Genre1Click
        end
        object N38: TMenuItem
          Caption = '-'
        end
        object Bossanova1: TMenuItem
          Caption = 'Bossanova'
          OnClick = Genre1Click
        end
        object Merengue1: TMenuItem
          Caption = 'Merengue'
          OnClick = Genre1Click
        end
        object Salsa1: TMenuItem
          Caption = 'Salsa'
          OnClick = Genre1Click
        end
        object Samba1: TMenuItem
          Caption = 'Samba'
          OnClick = Genre1Click
        end
        object Tango1: TMenuItem
          Caption = 'Tango'
          OnClick = Genre1Click
        end
      end
    end
    object AvantGarde1: TMenuItem
      Caption = 'Avant-Garde'
      object AvantGarde2: TMenuItem
        Caption = 'Avant-Garde'
        OnClick = Genre1Click
      end
      object N39: TMenuItem
        Caption = '-'
      end
      object Improviseradmusik1: TMenuItem
        Caption = 'Improviserad musik'
        OnClick = Genre1Click
      end
      object SoundArt1: TMenuItem
        Caption = 'Sound Art'
        object SoundArt2: TMenuItem
          Caption = 'Sound Art'
          OnClick = Genre1Click
        end
        object N40: TMenuItem
          Caption = '-'
        end
        object Noise1: TMenuItem
          Caption = 'Noise'
          OnClick = Genre1Click
        end
      end
    end
    object vrigt1: TMenuItem
      Caption = #214'vrigt'
      object Alternative1: TMenuItem
        Caption = 'Alternative'
        OnClick = Genre1Click
      end
      object Akustisk1: TMenuItem
        Caption = 'Akustisk'
        OnClick = Genre1Click
      end
      object Crossover1: TMenuItem
        Caption = 'Crossover'
        OnClick = Genre1Click
      end
      object Hardcore1: TMenuItem
        Caption = 'Hardcore'
        OnClick = Genre1Click
      end
      object Humor1: TMenuItem
        Caption = 'Humor'
        object Humor2: TMenuItem
          Caption = 'Humor'
          OnClick = Humor2Click
        end
        object N42: TMenuItem
          Caption = '-'
        end
        object Satir1: TMenuItem
          Caption = 'Satir'
          OnClick = Genre1Click
        end
        object Spratt1: TMenuItem
          Caption = 'Spratt'
          OnClick = Genre1Click
        end
      end
      object Instrumental1: TMenuItem
        Caption = 'Instrumental'
        OnClick = Genre1Click
      end
      object Kult1: TMenuItem
        Caption = 'Kult'
        OnClick = Genre1Click
      end
      object Ljudklipp1: TMenuItem
        Caption = 'Ljudklipp'
        object Ljudklipp2: TMenuItem
          Caption = 'Ljudklipp'
          OnClick = Genre1Click
        end
        object N41: TMenuItem
          Caption = '-'
        end
        object Trumsolo1: TMenuItem
          Caption = 'Trumsolo'
          OnClick = Genre1Click
        end
      end
      object Oldies1: TMenuItem
        Caption = 'Oldies'
        OnClick = Genre1Click
      end
      object Retro1: TMenuItem
        Caption = 'Retro'
        OnClick = Genre1Click
      end
      object Revival1: TMenuItem
        Caption = 'Revival'
        OnClick = Genre1Click
      end
      object SlowJam1: TMenuItem
        Caption = 'Slow Jam'
        OnClick = Genre1Click
      end
      object Tal1: TMenuItem
        Caption = 'Tal'
        OnClick = Genre1Click
      end
      object Tribal1: TMenuItem
        Caption = 'Tribal'
        OnClick = Genre1Click
      end
    end
    object Genre1: TMenuItem
      Caption = 'g'
      Visible = False
      OnClick = Genre1Click
    end
  end
  object YearPopupMenu: TPopupMenu
    Left = 112
    Top = 112
    object N2000talet1: TMenuItem
      Caption = '20&00-talet'
      object Hela2000talet1: TMenuItem
        Caption = 'Hela 2000-talet'
        OnClick = Hela2000talet1Click
      end
      object N46: TMenuItem
        Caption = '-'
      end
      object N20041: TMenuItem
        Tag = 2004
        Caption = '2004'
        OnClick = Year1Click
      end
      object N20031: TMenuItem
        Tag = 2003
        Caption = '2003'
        OnClick = Year1Click
      end
      object N20021: TMenuItem
        Tag = 2002
        Caption = '2002'
        OnClick = Year1Click
      end
      object N20011: TMenuItem
        Tag = 2001
        Caption = '2001'
        OnClick = Year1Click
      end
      object N20001: TMenuItem
        Tag = 2000
        Caption = '2000'
        OnClick = Year1Click
      end
    end
    object N1990talet1: TMenuItem
      Caption = '19&90-talet'
      object Hela1990talet1: TMenuItem
        Caption = 'Hela 1990-talet'
        OnClick = Hela1990talet1Click
      end
      object N43: TMenuItem
        Caption = '-'
      end
      object N19991: TMenuItem
        Tag = 1999
        Caption = '1999'
        OnClick = Year1Click
      end
      object N19981: TMenuItem
        Tag = 1998
        Caption = '1998'
        OnClick = Year1Click
      end
      object N19971: TMenuItem
        Tag = 1997
        Caption = '1997'
        OnClick = Year1Click
      end
      object N19961: TMenuItem
        Tag = 1996
        Caption = '1996'
        OnClick = Year1Click
      end
      object N19951: TMenuItem
        Tag = 1995
        Caption = '1995'
        OnClick = Year1Click
      end
      object N19941: TMenuItem
        Tag = 1994
        Caption = '1994'
        OnClick = Year1Click
      end
      object N19931: TMenuItem
        Tag = 1993
        Caption = '1993'
        OnClick = Year1Click
      end
      object N19921: TMenuItem
        Tag = 1992
        Caption = '1992'
        OnClick = Year1Click
      end
      object N19911: TMenuItem
        Tag = 1991
        Caption = '1991'
        OnClick = Year1Click
      end
      object N19901: TMenuItem
        Tag = 1990
        Caption = '1990'
        OnClick = Year1Click
      end
    end
    object N1980talet1: TMenuItem
      Caption = '19&80-talet'
      object Hela1980talet1: TMenuItem
        Caption = 'Hela 1980-talet'
        OnClick = Hela1980talet1Click
      end
      object N44: TMenuItem
        Caption = '-'
      end
      object N19891: TMenuItem
        Tag = 1989
        Caption = '1989'
        OnClick = Year1Click
      end
      object N19881: TMenuItem
        Tag = 1988
        Caption = '1988'
        OnClick = Year1Click
      end
      object N19871: TMenuItem
        Tag = 1987
        Caption = '1987'
        OnClick = Year1Click
      end
      object N19861: TMenuItem
        Tag = 1986
        Caption = '1986'
        OnClick = Year1Click
      end
      object N19851: TMenuItem
        Tag = 1985
        Caption = '1985'
        OnClick = Year1Click
      end
      object N19841: TMenuItem
        Tag = 1984
        Caption = '1984'
        OnClick = Year1Click
      end
      object N19831: TMenuItem
        Tag = 1983
        Caption = '1983'
        OnClick = Year1Click
      end
      object N19821: TMenuItem
        Tag = 1982
        Caption = '1982'
        OnClick = Year1Click
      end
      object N19811: TMenuItem
        Tag = 1981
        Caption = '1981'
        OnClick = Year1Click
      end
      object N19801: TMenuItem
        Tag = 1980
        Caption = '1980'
        OnClick = Year1Click
      end
    end
    object N1970talet1: TMenuItem
      Caption = '19&70-talet'
      object Hela1970talet1: TMenuItem
        Caption = 'Hela 1970-talet'
        OnClick = Hela1970talet1Click
      end
      object N45: TMenuItem
        Caption = '-'
      end
      object N19791: TMenuItem
        Tag = 1979
        Caption = '1979'
        OnClick = Year1Click
      end
      object N19781: TMenuItem
        Tag = 1978
        Caption = '1978'
        OnClick = Year1Click
      end
      object N19771: TMenuItem
        Tag = 1977
        Caption = '1977'
        OnClick = Year1Click
      end
      object N19761: TMenuItem
        Tag = 1976
        Caption = '1976'
        OnClick = Year1Click
      end
      object N19751: TMenuItem
        Tag = 1975
        Caption = '1975'
        OnClick = Year1Click
      end
      object N19741: TMenuItem
        Tag = 1974
        Caption = '1974'
        OnClick = Year1Click
      end
      object N19731: TMenuItem
        Tag = 1973
        Caption = '1973'
        OnClick = Year1Click
      end
      object N19721: TMenuItem
        Tag = 1972
        Caption = '1972'
        OnClick = Year1Click
      end
      object N19711: TMenuItem
        Tag = 1971
        Caption = '1971'
        OnClick = Year1Click
      end
      object N19701: TMenuItem
        Tag = 1970
        Caption = '1970'
        OnClick = Year1Click
      end
    end
    object N1960talet1: TMenuItem
      Caption = '19&60-talet'
      object Hela1960talet1: TMenuItem
        Caption = 'Hela 1960-talet'
        OnClick = Hela1960talet1Click
      end
      object N47: TMenuItem
        Caption = '-'
      end
      object N19691: TMenuItem
        Tag = 1969
        Caption = '1969'
        OnClick = Year1Click
      end
      object N19681: TMenuItem
        Tag = 1968
        Caption = '1968'
        OnClick = Year1Click
      end
      object N19671: TMenuItem
        Tag = 1967
        Caption = '1967'
        OnClick = Year1Click
      end
      object N19661: TMenuItem
        Tag = 1966
        Caption = '1966'
        OnClick = Year1Click
      end
      object N19651: TMenuItem
        Tag = 1965
        Caption = '1965'
        OnClick = Year1Click
      end
      object N19641: TMenuItem
        Tag = 1964
        Caption = '1964'
        OnClick = Year1Click
      end
      object N19631: TMenuItem
        Tag = 1963
        Caption = '1963'
        OnClick = Year1Click
      end
      object N19621: TMenuItem
        Tag = 1962
        Caption = '1962'
        OnClick = Year1Click
      end
      object N19611: TMenuItem
        Tag = 1961
        Caption = '1961'
        OnClick = Year1Click
      end
      object N19601: TMenuItem
        Tag = 1960
        Caption = '1960'
        OnClick = Year1Click
      end
    end
    object N1950talet1: TMenuItem
      Caption = '19&50-talet'
      object Hela1950talet1: TMenuItem
        Caption = 'Hela 1950-talet'
        OnClick = Hela1950talet1Click
      end
      object N48: TMenuItem
        Caption = '-'
      end
      object N19591: TMenuItem
        Tag = 1959
        Caption = '1959'
        OnClick = Year1Click
      end
      object N19581: TMenuItem
        Tag = 1958
        Caption = '1958'
        OnClick = Year1Click
      end
      object N19571: TMenuItem
        Tag = 1957
        Caption = '1957'
        OnClick = Year1Click
      end
      object N19561: TMenuItem
        Tag = 1956
        Caption = '1956'
        OnClick = Year1Click
      end
      object N19551: TMenuItem
        Tag = 1955
        Caption = '1955'
        OnClick = Year1Click
      end
      object N19541: TMenuItem
        Tag = 1954
        Caption = '1954'
        OnClick = Year1Click
      end
      object N19531: TMenuItem
        Tag = 1953
        Caption = '1953'
        OnClick = Year1Click
      end
      object N19521: TMenuItem
        Tag = 1952
        Caption = '1952'
        OnClick = Year1Click
      end
      object N19511: TMenuItem
        Tag = 1951
        Caption = '1951'
        OnClick = Year1Click
      end
      object N19501: TMenuItem
        Tag = 1950
        Caption = '1950'
        OnClick = Year1Click
      end
    end
    object Year1: TMenuItem
      Caption = 'y'
      Visible = False
      OnClick = Year1Click
    end
  end
  object ArtistPopupMenu: TPopupMenu
    Left = 112
    Top = 80
    object AD1: TMenuItem
      Caption = 'A-D'
      object AllaAD1: TMenuItem
        Caption = 'Alla A-D'
        OnClick = Artist1Click
      end
      object N50: TMenuItem
        Caption = '-'
      end
      object A1: TMenuItem
        Caption = 'A'
        OnClick = Artist1Click
      end
      object B1: TMenuItem
        Caption = 'B'
        OnClick = Artist1Click
      end
      object C1: TMenuItem
        Caption = 'C'
        OnClick = Artist1Click
      end
      object D1: TMenuItem
        Caption = 'D'
        OnClick = Artist1Click
      end
    end
    object EH1: TMenuItem
      Caption = 'E-H'
      object AllaEH1: TMenuItem
        Caption = 'Alla E-H'
        OnClick = Artist1Click
      end
      object N51: TMenuItem
        Caption = '-'
      end
      object E1: TMenuItem
        Caption = 'E'
        OnClick = Artist1Click
      end
      object F1: TMenuItem
        Caption = 'F'
        OnClick = Artist1Click
      end
      object G1: TMenuItem
        Caption = 'G'
        OnClick = Artist1Click
      end
      object H1: TMenuItem
        Caption = 'H'
        OnClick = Artist1Click
      end
    end
    object IL1: TMenuItem
      Caption = 'I-L'
      object AllaIL1: TMenuItem
        Caption = 'Alla I-L'
        OnClick = Artist1Click
      end
      object N52: TMenuItem
        Caption = '-'
      end
      object I1: TMenuItem
        Caption = 'I'
        OnClick = Artist1Click
      end
      object J1: TMenuItem
        Caption = 'J'
        OnClick = Artist1Click
      end
      object K1: TMenuItem
        Caption = 'K'
        OnClick = Artist1Click
      end
      object L1: TMenuItem
        Caption = 'L'
        OnClick = Artist1Click
      end
    end
    object MP1: TMenuItem
      Caption = 'M-P'
      object AllaMP1: TMenuItem
        Caption = 'Alla M-P'
        OnClick = Artist1Click
      end
      object N53: TMenuItem
        Caption = '-'
      end
      object M1: TMenuItem
        Caption = 'M'
        OnClick = Artist1Click
      end
      object N54: TMenuItem
        Caption = 'N'
        OnClick = Artist1Click
      end
      object O1: TMenuItem
        Caption = 'O'
        OnClick = Artist1Click
      end
      object P1: TMenuItem
        Caption = 'P'
        OnClick = Artist1Click
      end
    end
    object QT1: TMenuItem
      Caption = 'Q-T'
      object AllaQT1: TMenuItem
        Caption = 'Alla Q-T'
        OnClick = Artist1Click
      end
      object N55: TMenuItem
        Caption = '-'
      end
      object Q1: TMenuItem
        Caption = 'Q'
        OnClick = Artist1Click
      end
      object R1: TMenuItem
        Caption = 'R'
        OnClick = Artist1Click
      end
      object S1: TMenuItem
        Caption = 'S'
        OnClick = Artist1Click
      end
      object T1: TMenuItem
        Caption = 'T'
        OnClick = Artist1Click
      end
    end
    object UX1: TMenuItem
      Caption = 'U-X'
      object AllaUX1: TMenuItem
        Caption = 'Alla U-X'
        OnClick = Artist1Click
      end
      object N56: TMenuItem
        Caption = '-'
      end
      object U1: TMenuItem
        Caption = 'U'
        OnClick = Artist1Click
      end
      object V1: TMenuItem
        Caption = 'V'
        OnClick = Artist1Click
      end
      object W1: TMenuItem
        Caption = 'W'
        OnClick = Artist1Click
      end
      object X1: TMenuItem
        Caption = 'X'
        OnClick = Artist1Click
      end
    end
    object Y1: TMenuItem
      Caption = 'Y-'#214
      object AllaY1: TMenuItem
        Caption = 'Alla Y-'#214
        OnClick = Artist1Click
      end
      object N57: TMenuItem
        Caption = '-'
      end
      object Y2: TMenuItem
        Caption = 'Y'
        OnClick = Artist1Click
      end
      object Z1: TMenuItem
        Caption = 'Z'
        OnClick = Artist1Click
      end
      object N58: TMenuItem
        Caption = #197
        OnClick = Artist1Click
      end
      object N59: TMenuItem
        Caption = #196
        OnClick = Artist1Click
      end
      object N60: TMenuItem
        Caption = #214
        OnClick = Artist1Click
      end
    end
    object Artist1: TMenuItem
      Caption = 'a'
      Visible = False
      OnClick = Artist1Click
    end
  end
  object RatingPopupMenu: TPopupMenu
    Left = 112
    Top = 144
    object Utmrkt1: TMenuItem
      Caption = '5 - Utm'#228'rkt'
      OnClick = Rating1Click
    end
    object Mycketbra41: TMenuItem
      Caption = '4 - Mycket bra'
      OnClick = Rating1Click
    end
    object Bra31: TMenuItem
      Caption = '3 - Bra'
      OnClick = Rating1Click
    end
    object OK21: TMenuItem
      Caption = '2 - OK'
      OnClick = Rating1Click
    end
    object Dlig11: TMenuItem
      Caption = '1 - D'#229'lig'
      OnClick = Rating1Click
    end
    object Rating1: TMenuItem
      Caption = 'r'
      Visible = False
      OnClick = Rating1Click
    end
  end
  object SituationPopupMenu: TPopupMenu
    Left = 112
    Top = 176
    object Avkoppling1: TMenuItem
      Caption = 'Avkoppling'
      OnClick = Situation1Click
    end
    object Bakgrund1: TMenuItem
      Caption = 'Bakgrund'
      OnClick = Situation1Click
    end
    object Dans1: TMenuItem
      Caption = 'Dans'
      OnClick = Situation1Click
    end
    object Fest1: TMenuItem
      Caption = 'Fest'
      OnClick = Situation1Click
    end
    object Middag1: TMenuItem
      Caption = 'Middag'
      OnClick = Situation1Click
    end
    object Romantik1: TMenuItem
      Caption = 'Romantik'
      OnClick = Situation1Click
    end
    object Situation1: TMenuItem
      Caption = 's'
      Visible = False
      OnClick = Situation1Click
    end
  end
  object MoodPopupMenu: TPopupMenu
    Left = 112
    Top = 208
    object Dsig1: TMenuItem
      Caption = 'D'#229'sig'
      OnClick = Mood1Click
    end
    object Glad1: TMenuItem
      Caption = 'Glad'
      OnClick = Mood1Click
    end
    object Ltt1: TMenuItem
      Caption = 'L'#228'tt'
      OnClick = Mood1Click
    end
    object Stillsam1: TMenuItem
      Caption = 'Stillsam'
      OnClick = Mood1Click
    end
    object Surmulen1: TMenuItem
      Caption = 'Surmulen'
      OnClick = Mood1Click
    end
    object Vild1: TMenuItem
      Caption = 'Vild'
      OnClick = Mood1Click
    end
    object Mood1: TMenuItem
      Caption = 'm'
      Visible = False
      OnClick = Mood1Click
    end
  end
  object MainMenu: TMainMenu
    Left = 60
    Top = 320
    object Instllningar1: TMenuItem
      Caption = 'Inst'#228'llningar'
      OnClick = Arkiv1Click
    end
    object Om1: TMenuItem
      Caption = 'Om'
      OnClick = Om1Click
    end
  end
  object SongListPopupMenu: TPopupMenu
    Left = 280
    Top = 64
    object Spelaupp1: TMenuItem
      Caption = 'Spela upp'
      Default = True
      ShortCut = 16467
      OnClick = SongListDblClick
    end
    object Spelauppislumpmssigordning1: TMenuItem
      Caption = 'Spela upp i slumpm'#228'ssig ordning'
      ShortCut = 16463
      OnClick = Spelauppislumpmssigordning1Click
    end
    object N61: TMenuItem
      Caption = '-'
    end
    object Egenskaper1: TMenuItem
      Caption = 'Egenskaper...'
      ShortCut = 16453
      OnClick = Egenskaper1Click
    end
  end
  object TrayIcon: TLMDTrayIcon
    Hint = 'Lira!'
    Icon.Data = {
      0000010001001010100000000000280100001600000028000000100000002000
      00000100040000000000C0000000000000000000000000000000000000000000
      0000000080000080000000808000800000008000800080800000C0C0C0008080
      80000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
      0AAAAA000000000AAAAAAAA2000000AAA40AAAAAA00000AA0440AAAAA0000AAA
      04440AAAAA000AAAA4040AAAAA000AAAAAAA0AA0AAA00AAAAAAA0AA0AAA00AAA
      AAAA0AA0AAA00AAAAAAA0AA0AAA00AAAAAAA000AAA0000AAAAAA04AAAA0000AA
      AAAA0AAAA000000AAAAA0AAA200000000AAAAA2000000000000000000000F83F
      0000E00F0000C0070000C0070000800300008003000080010000800100008001
      00008001000080030000C0030000C0070000E0070000F81F0000FFFF0000}
    OnClick = TrayIconClick
    Left = 24
    Top = 320
  end
end
