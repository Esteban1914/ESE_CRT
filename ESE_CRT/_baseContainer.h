#pragma once
#include "_baseArrayForms.h"
#include "_forms.h"

class _baseContainer:public _baseArrayForms, public _forms
{
public:
	_baseContainer(char*name,CRD crd,int*TotalWigth,int*TotalHeight):_forms(name,crd,0,0,TotalWigth,TotalHeight),_baseArrayForms(){}
	~_baseContainer()
	{
	}
	//NEW//
	virtual void New_CRD(CRD crd)
	{
		_forms::New_CRD(crd);
		for(unsigned i=0;i<cont;i++)
			forms[i]->New_CRD(CRD(crd));
	}
	void New_CRD(char*name,CRD crd)
	{
		_baseArrayForms::New_CRD(name,crd);
	}
	void Actualizar_ParentWigth(float Wigth)
	{
		this->Wigth=Wigth;
		_baseArrayForms::Actualizar_ParentWigth();
			/*if(forms[i]->type==_TEXTBOX)
				forms[i]->New_Wigth(Wigth);
			else if(forms[i]->type==_LABELCENTER)
				forms[i]->New_CRD(forms[i]->coord);*/
	}
	void Clear()
	{
		_baseArrayForms::Clear();
		Wigth=0;
		Height=0;
	}
	virtual bool PulsadoPasivo(int x,int y)
	{
		return false;
	}
	//ADD//
	void Add_Label_Free(char*name,char*escritura,CRD crd,bool Draw=true,unsigned LetterSize=1,double R=0,double G=0,double B=0)
	{
		_label*lF=new _label(name,escritura,crd,LetterSize,R,G,B,this->TotalWigth,this->TotalHeight);
		lF->Set_Draw(Draw);
		Add_Element(lF);
	}
	void Add_Label(char*name,char*escritura,unsigned LetterSize=1,double R=0,double G=0,double B=0)
	{
		_label*l=new _label(name,escritura,CRD(),LetterSize,R,G,B,this->TotalWigth,this->TotalHeight);
		Add_Element(l);
	}
	void Add_LabelCenter(char*name,char*escritura,unsigned LetterSize=1,double R=0,double G=0,double B=0)
	{
		_labelCenter*lC=new _labelCenter(name,escritura,CRD(),LetterSize,R,G,B,TotalWigth,TotalHeight,&this->Wigth);
		Add_Element(lC);

	}
	void Add_TextBox(char*name,char*escritura,_textBoxType TextBoxType=_DEFAULT)
	{
		_textBox*tB=new _textBox(name,escritura,CRD(),this->Wigth,this->TotalWigth,this->TotalHeight,TextBoxType);
		Add_Element(tB);
	}
	void Add_TextBoxCenter(char*name,char*escritura,_textBoxType TextBoxType=_DEFAULT)
	{
		_textBoxCenter*tBC=new _textBoxCenter(name,escritura,CRD(),this->Wigth,this->TotalWigth,this->TotalHeight,&this->Wigth,TextBoxType);
		Add_Element(tBC);
	}
	void Add_ChectBox(char*name,char*Escritura,bool Chect=false)
	{
		_chectBox* cb=new _chectBox(name,Escritura,CRD(),this->TotalWigth,this->TotalHeight,Chect);
		Add_Element(cb);
	}
	void Add_RadioButtonGroup(char*name)
	{
		_radioButtonGroup* rbg=new _radioButtonGroup(name,CRD(),this->TotalWigth,this->TotalHeight);
		Add_Element(rbg);
	}
	void Add_RadioButtonGroupFree(char*name)
	{
		_radioButtonGroupFree* rbgf=new _radioButtonGroupFree(name,CRD(),this->TotalWigth,this->TotalHeight);
		Add_Element(rbgf);
	}
	
	void Add_RadioButton_To_RadioButtonGroup(char*RadioButtonGroupName,char*RadioButtonName,char*Escritura,bool Chect=false)
	{
		int i=Get_Element_By_Name(RadioButtonGroupName);
		if(i==-1)
			return;
		forms[i]->RadioButtonGroup_Add_RadioButton(RadioButtonName,Escritura,Chect);
		this->Height+=25;
	}
	void Add_ButtonLabel(char*name,char*Escritura)
	{
		_buttonLabel*btnL=new _buttonLabel(name,Escritura,CRD(),TotalWigth,TotalHeight);
		Add_Element(btnL);
	}
	void Add_ButtonLabelCenter(char*name,char*Escritura)
	{
		_buttonLabelCenter*btnLC=new _buttonLabelCenter(name,Escritura,CRD(),&Wigth,TotalWigth,TotalHeight);
		Add_Element(btnLC);
	}
	void Add_ButtonAccept(char*name)
	{
		_buttonAccept*btnA=new _buttonAccept(name,CRD(),this->TotalWigth,this->TotalHeight);
		Add_Element(btnA);
	}
	void Add_ButtonCancel(char*name)
	{
		_buttonCancel*btnC=new _buttonCancel(name,CRD(),this->TotalWigth,this->TotalHeight);
		Add_Element(btnC);
	}
	void Add_ButtonsAcceptCancel(char*name)
	{
		_buttonsAcceptCancel*btnAC=new _buttonsAcceptCancel(name,CRD(),TotalWigth,TotalHeight,&this->Wigth);
		Add_Element(btnAC);
	}
	void Add_ButtonsAcceptAtras(char*name)
	{
		_buttonsAcceptAtras*btnAt=new _buttonsAcceptAtras(name,CRD(),TotalWigth,TotalHeight,&this->Wigth);
		Add_Element(btnAt);
	}
	void Add_ButtonAtras(char*name)
	{
		_buttonAtras*btnAtr=new _buttonAtras(name,CRD(),TotalWigth,TotalHeight);
		Add_Element(btnAtr);
	}
	//TEXTBOX//
	bool TextBox_Get_Escribiendo()
	{
		return _baseArrayForms::TextBox_Get_Escribiendo();
	}
	void TextBox_Add_Caracter(char caracter)
	{
		_baseArrayForms::TextBox_Add_Caracter(caracter);
	}
	void TextBox_Sub_Caracter()
	{
		_baseArrayForms::TextBox_Sub_Caracter();
	}
	//SET//
	void Set_Draw(bool Draw)
	{
		_forms::Set_Draw(Draw);
	}
	void Set_Draw(char*name,bool Draw)
	{
		_baseArrayForms::Set_Draw(name,Draw);
	}
	void Set_Color(float R,float G,float B)
	{
		_forms::Set_Color(R,G,B);
	}
	void Set_Color(char*name,GLfloat R,GLfloat G,GLfloat B)
	{
		_baseArrayForms::Set_Color(name,R,G,B);
	}
	void Set_Text(char*name,char*text)
	{
		_baseArrayForms::Set_Text(name,text);
	}
	void Set_Active(bool Active)
	{
		_forms::Set_Active(Active);
		_baseArrayForms::Set_Active(Active);
	}
	void Set_Active(char*name,bool Draw)
	{
		_baseArrayForms::Set_Active(name,Draw);
	}
	//GET//
	char* Get_Text(char*name)
	{
		return _baseArrayForms::Get_Text(name);
	}
	//TRABAJO_INTERNO//
	virtual void Pulsar_Accept(){};
	virtual void Pulsar_Cancel(){};
	virtual void Pulsar_Btn(unsigned ElementPulsadoPositionInArray){}
	virtual void Pulsar_Atras(){}
	//PURAS//
	virtual bool Pulsado(int x,int y)=0;
	virtual void _draw()=0;
};