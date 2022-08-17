#pragma once
#include "CRD.h"
enum _type
{
	_FORMS,_TEXTBOX,_LABEL,_RADIOBUTTONGROUP,_CHECTBOX,_RADIOBUTTON,_BOX,_BUTTON,_CONTAINER,_BUTTONSACCEPTCANCEL,_BASEBUTTON,_BUTTONACCEPT,_BUTTONCANCEl,_LABELCENTER,_NULL
};

class _forms
{
public:
	char*name;
	CRD coord;
	float Wigth,Height;//TotalProfundidad;
	int *TotalWigth,*TotalHeight;
	bool active,Draw;
	_type type;
	//////////////////////////
	_forms(){
		name=new char[1];
		active=Draw=true;
		type=_FORMS;
	};
	_forms(char*name,CRD coord,float wigth,float height,int*TotalWigth,int*TotalHeight){
		this->name=new char[strlen(name)+1];
		this->name[strlen(name)]=0;
		for(unsigned i=0;i<strlen(name);i++)
			this->name[i]=name[i];
		this->TotalHeight=TotalHeight;
		this->TotalWigth=TotalWigth;
		//this->TotalProfundidad=0;
		this->Wigth=wigth;
		this->Height=height;
		this->coord=coord;
		this->active=true;
		this->Draw=true;
	};
	virtual ~_forms()
	{
		delete []name;
	};
	///////////////STATIC///////////////
	static bool Pulsado(int x,int y,_forms*f,bool PulsadoEspecial=false)
	{
		if(!f->Draw||!f->active)
			return false;
		if(PulsadoEspecial&&x>=f->coord.x&&x<=f->coord.x+f->Wigth&& y>=f->coord.y && y<=f->coord.y+f->Height)			
			return true;
		else if(x>=f->coord.x&&x<=f->coord.x+f->Wigth&&y<=f->coord.y&&y>=f->coord.y-f->Height)			
			return true;
		return false;
	}
	///////////////VIRTUALES////////////
	virtual bool Pulsado(int x,int y)
	{
		return	_forms::Pulsado(x,y,this);
	}
	virtual void New_CRD(CRD crd)
	{
		this->coord=crd;
	}
	virtual void New_Wigth(float Wigth){}
	virtual _type Get_BtnPulsado()
	{
		return _NULL;
	}
	//GET//
	virtual float Get_All_Wigth()
	{
		return Wigth;
	}
	virtual float Get_All_Height()
	{
		return Height;
	}
	virtual char* Get_Text(){return 0;}
	//SET//
	virtual void Set_Draw(bool Draw)
	{
		this->Draw=Draw;
	}
	virtual void Set_Color(GLfloat R,GLfloat G,GLfloat B)
	{}
	//////LABEL//////
	virtual void Set_Text(char*text){};
	
	////////TEXTBOX////
	virtual bool TextBox_Get_Escribiendo(){return false;}
	//virtual char* TextBox_Get_Text(){	return nullptr;}
	virtual void TextBox_Add_Caracter(char caracter){}
	virtual void TextBox_Sub_Caracter(){}
	///////CHECTBOX/////
	//virtual bool ChectBox_GetChect(){	return false;}
	
	//////RADIOBUTTON////
	
	/////RADIOBUTTONGROUP///
	virtual void RadioButtonGroup_Add_RadioButton(char*RadioButtonName,char*escritura,bool Chect=false,bool active=true){}
	///////////////PURAS//////////////////
	virtual void _draw()=0; 
};