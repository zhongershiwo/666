/*
 * UI.h
 *
 *  Created on: 2017��9��26��
 *      Author: ����
 */

#ifndef UI_H_
#define UI_H_
#include "../User_Component/User_Device/Key/key.h"
#include "../User_Component/User_Device/oled/oled.h"
#include "../User_Component/User_Driver/Flash/Storage.h"


/******************************************
 ********UI�����������豸�ź�֮��Ķ�Ӧ��ϵ**********
 ******************************************/
typedef enum{
	UI_None			= Key_None,
	UI_Value_Plus 		= 12, //Number3
	UI_Value_Minus 		= 13,//Number1
	UI_Item_Plus		= 2,//Number2
	UI_Item_Minus		= 8,//Number8
	UI_Page_Plus		= 6,//Number6
	UI_Page_Minus		= 4,//Number4
	UI_Accuracy_Plus	= 3,//Number9
	UI_Accuracy_Minus	= 11,//Number7
	UI_Save			= 14,  //Signj
	UI_Read		    = 15,  //Signx
	UI_Start        = 5//Number5
}UI_CMD_e,*UI_CMD_Ptr_e;

/*************************
 **�����Ĳ������������������ͺ�Ȩ��**
 *************************/
typedef struct {
	enum{
		Double,
		Float,
		Int32_t,
		Uint32_t,
		Int16_t,
		Uint16_t,
		Int8_t,
		Uint8_t,
		Function,	//��ʾ��ʾͼ��ĺ���
	}Type;

	enum{
		RO,			//ֻ��
		RW,			//��д
	}Authority;
}Variable_Attribute;

/********************************************
 ************һ��Item���ر���Ԫ��*****************
 ********************************************/
typedef struct{
	signed char*		Name;				//Item�����ַ�������
	void*				DataPtr;			//���Itemָ������ݵ�ַ
	Variable_Attribute	Data_Attribute;		//���Item��Ӧ���ݵĲ���
}Item_Lib,*Item_LibPtr;

/********************************************
 ************һ��Page���ر���Ԫ��*****************
 ********************************************/
typedef struct{
	signed char*		Name;				//Page�����ַ�������
	Item_LibPtr			ItemPtr;			//���Page�ĵ�һ��Item���׵�ַ
	uint16_t			Item_Max;			//���Page��Ӧ������Item����
}Page_Lib,*Page_LibPtr;

/********************************************
 ***************���浱ǰ�Ļ״̬*****************
 ********************************************/
typedef struct{
	float 				Accuracy;			//��ǰ���ݵ�������
	bool				ShowGraphic;		        //����Ƿ���ͼ����ʾ
	int16_t				PageNum;			//��ǰ��Page�����ͣ�������
	Page_LibPtr			PagePtr;			//��ǰPageָ���Page��Ϣ�׵�ַ�����ͣ�ָ��
	int16_t				ItemNum;			//��ǰ��Item�����ͣ�������
	Item_LibPtr			ItemPtr;			//��ǰItemָ���Item��Ϣ�׵�ַ�����ͣ�ָ��
}Active_Type,*Active_TypePtr;

void UI_Init(void);
void UI_Main(void);
void UI_GetCmd(void);
void Read_Data(void);
void Save_Data(void);

extern UI_CMD_e UI_CMD;

#endif /* UI_H_ */
