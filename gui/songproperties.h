//---------------------------------------------------------------------------
#ifndef songpropertiesH
#define songpropertiesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>

#include "../Song/SongProperty.h"
//---------------------------------------------------------------------------
class TSongPropertiesForm : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label1;
    TEdit *TitleEdit;
    TLabel *Label4;
    TButton *CancelButton;
    TButton *OKButton;
    TLabel *Label5;
    TEdit *YearEdit;
    TLabel *Label6;
    TComboBox *GenreComboBox;
    TLabel *Label7;
    TGroupBox *GroupBox1;
    TComboBox *RatingComboBox;
    TLabel *Label8;
    TLabel *Label9;
    TComboBox *SituationComboBox;
    TComboBox *MoodComboBox;
    TLabel *Label10;
    TMemo *CommentMemo;
    TLabel *Label11;
    TLabel *FileNameLabel;
    TEdit *ArtistEdit;
    TEdit *AlbumEdit;
    TEdit *TrackEdit;
    void __fastcall OKButtonClick(TObject *Sender);
private:	// User declarations
    SongProperty m_songproperties;
public:		// User declarations
    __fastcall TSongPropertiesForm(TComponent* Owner);
    void Initialise(const SongProperty &);
    SongProperty GetNewProperties();
};
//---------------------------------------------------------------------------
extern PACKAGE TSongPropertiesForm *SongPropertiesForm;
//---------------------------------------------------------------------------
#endif
