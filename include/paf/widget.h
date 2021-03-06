/*
	Vita Development Suite Libraries git-9c2c72f1
*/

#ifndef _VDSUITE_USER_PAF_WIDGET_H
#define _VDSUITE_USER_PAF_WIDGET_H

#include <ctrl.h>
#include <scetypes.h>

namespace paf {

	namespace ui {

		enum LoopEffect
		{
			LoopEffect_None = 0,
			LoopEffect_1,
			LoopEffect_2,
			LoopEffect_3,
			LoopEffect_4,
			LoopEffect_5,
			LoopEffect_6,
			LoopEffect_7,
			LoopEffect_Paceholder = 0xff,
		};

		enum EventCtrl
		{
			EventCtrl_ButtonPress = 0x10001,
			EventCtrl_ButtonRelease = 0x10002,
			EventCtrl_ButtonHold = 0x10003
		};

		enum EventFocus
		{
			EventFocus_On = 0x40001,
			EventFocus_Off = 0x40002
		};

		enum EventMain
		{
			EventMain_Tapped = 0x10000003,
			EventMain_LongDecide = 0x10000007,
			EventMain_Decide = 0x10000008
		};

		class EventCallback
		{
		public:

			typedef void(*EventHandler)(SceInt32 eventId, Widget *self, SceInt32, ScePVoid pUserData);

			EventCallback() : state(2), pUserData(SCE_NULL)
			{

			};

			virtual ~EventCallback()
			{

			};

			virtual SceInt32 HandleEvent(SceInt32 eventId, Widget *self, SceInt32 a3)
			{
				SceInt32 ret;

				if ((this->state & 1) == 0) {
					if (this->eventHandler != 0) {
						this->eventHandler(eventId, self, a3, this->pUserData);
					}
					ret = SCE_OK;
				}
				else {
					ret = SCE_PAF_ERROR_UI_EVENT_CALLBACK_UNHANDLED;
				}

				return ret;
			};

			virtual EventHandler GetHandler()
			{
				return this->eventHandler;
			};

			SceInt32 state;
			ScePVoid pUserData;
			EventHandler eventHandler;

		};

		class Context
		{
		public:

			//FE22E2B3 c1
			//22303A4C c2
			Context(SceUInt32 flags);

			//FA21D400 d1
			//7E3CFE67 d2
			//C230312B d0
			virtual ~Context();

		private:

			SceUChar8 m_work[0x10];
		};

		class CopyPaste
		{
		public:

			virtual ~CopyPaste();

			virtual int Open(Widget *targetWidget);
			virtual int Close(Widget *targetWidget);
			virtual int unkFun_10(Widget *targetWidget, paf::Vector4 *arg);
			virtual int unkFun_14(Widget *targetWidget);
			virtual int unkFun_1C(Widget *targetWidget);

		private:

			SceUChar8 work[0x34];
		};

		class Widget
		{
		public:

			Widget(Widget *parent, SceInt32 a2);

			virtual ~Widget();

			//109 virtual functions
			virtual int unkFun_008(SceInt32);
			virtual int unkFun_00C(SceInt32);
			virtual int unkFun_010(SceInt32);
			virtual int unkFun_014(SceInt32);
			virtual int unkFun_018(SceInt32);
			virtual int unkFun_01C(SceInt32);
			virtual int unkFun_020(SceInt32);
			virtual int unkFun_024(SceInt32);
			virtual int unkFun_028(SceInt32);
			virtual int unkFun_02C(SceInt32);
			virtual int unkFun_030();
			virtual int unkFun_034();
			virtual int unkFun_038();
			virtual int unkFun_03C();
			virtual int unkFun_040(SceInt32);
			virtual int unkFun_044(SceInt32);
			virtual int unkFun_048(SceInt32, SceInt32);
			virtual SceVoid SetFocusEnable(bool enable);
			virtual int unkFun_050(SceInt32);
			virtual int unkFun_054();
			virtual SceVoid SetTouchEnable(bool enable);
			virtual bool GetTouchEnable();
			virtual int unkFun_060();
			virtual bool equal(const char *pTypeName);
			virtual const char *name();
			virtual int unkFun_06C();
			virtual int unkFun_070();
			virtual int unkFun_074(SceInt32, SceInt32);
			virtual int unkFun_078();
			virtual int unkFun_07C();
			virtual int unkFun_080();
			virtual int unkFun_084();
			virtual int unkFun_088();
			virtual int unkFun_08C();
			virtual int unkFun_090_effect(SceFloat32 a1, SceInt32 animationCode, bool setSomeFloat);
			virtual int unkFun_094_effectRev(SceFloat32 a1, SceInt32 animationCode, bool setSomeFloat);
			virtual SceInt32 SetColor(const Rgba *pColor);
			virtual int unkFun_09C();
			virtual int unkFun_0A0();
			virtual int unkFun_0A4();
			virtual int unkFun_0A8();
			virtual int unkFun_0AC();
			virtual int unkFun_0B0();
			virtual int unkFun_0B4();
			virtual int unkFun_0B8();
			virtual int unkFun_0BC();
			virtual int unkFun_0C0();
			virtual int unkFun_0C4();
			virtual int unkFun_0C8();
			virtual int unkFun_0CC();
			virtual int unkFun_0D0();
			virtual int unkFun_0D4();
			virtual int unkFun_0D8();
			virtual int unkFun_0DC();
			virtual int unkFun_0E0();
			virtual int unkFun_0E4();
			virtual int unkFun_0E8();
			virtual int unkFun_0EC();
			virtual int unkFun_0F0();
			virtual int unkFun_0F4();
			virtual graph::DrawObj *GetDrawObj(SceInt32 a1 = 0);
			virtual int SetSurface(paf::graph::Surface **surf, SceInt32 childNum, SceInt32 a3 = 0);
			virtual int SetSurfaceBase(paf::graph::Surface **surf);
			virtual int unkFun_104();
			virtual int unkFun_108();
			virtual int unkFun_10C();
			virtual int unkFun_110();
			virtual int unkFun_114();
			virtual SceInt32 SetLabelWithFlag(paf::wstring *text, SceInt32 flag);
			virtual SceInt32 SetLabel(paf::wstring *text);
			virtual SceInt32 GetLabelWithFlag(paf::wstring *text, SceInt32 flag);
			virtual SceInt32 GetLabel(paf::wstring *text);
			virtual int unkFun_128();
			virtual int unkFun_12C();
			virtual int unkFun_130(SceInt32);
			virtual int unkFun_134(SceInt32);
			virtual int unkFun_138();
			virtual int unkFun_13C();
			virtual int unkFun_140();
			virtual int unkFun_144();
			virtual int unkFun_148();
			virtual int unkFun_14C();
			virtual int unkFun_150();
			virtual int unkFun_154();
			virtual int unkFun_158();
			virtual int unkFun_15C();
			virtual int unkFun_160();
			virtual int unkFun_164();
			virtual int unkFun_168();
			virtual int unkFun_16C();
			virtual int SendEvent(SceInt32 eventId, bool a2);
			virtual int unkFun_174(SceInt32 a1);
			virtual int unkFun_178(SceInt32 a1);
			virtual int unkFun_17C();
			virtual int unkFun_180();
			virtual int unkFun_184();
			virtual int unkFun_188();
			virtual int unkFun_18C();
			virtual int unkFun_190();
			virtual int unkFun_194(SceFloat32 a1, SceFVector4 *a2, SceInt32 a3, SceInt32 a4, SceInt32 a5);
			virtual int unkFun_198();
			virtual int unkFun_19C();
			virtual int unkFun_1A0();
			virtual int unkFun_1A4();
			virtual int unkFun_1A8();

			//ScePafWidget_1EE9D37E
			//static CopyPaste *GetCopyPasteObj();

			//ScePafWidget_BFF4C5A2
			//static ScePVoid GetCopyPasteTextBoxObj();

			SceInt32 SetFilterColor(const paf::Rgba *pColor, SceFloat32 a2, SceInt32 a3 = 0, SceInt32 a4 = 0x10001, SceInt32 a5 = 0, SceInt32 a6 = 0, SceInt32 a7 = 0);

			Widget *GetChild(paf::rco::Element *widgetInfo, SceUInt32 param); //param can be 0,1,2

			Widget *GetChild(SceUInt32 childNum);

			Widget *GetParent();

			SceInt32 SetPosition(const paf::Vector4 *pPosition, SceFloat32 a2 = 0.0f, SceInt32 a3 = 0, SceInt32 a4 = 0x10000, SceInt32 a5 = 0, SceInt32 a6 = 0, SceInt32 a7 = 0);

			SceInt32 SetSize(const paf::Vector4 *pSize, SceFloat32 a2 = 0.0f, SceInt32 a3 = 0, SceInt32 a4 = 0x10004, SceInt32 a5 = 0, SceInt32 a6 = 0, SceInt32 a7 = 0);

			SceInt32 SetZoom(const paf::Vector4 *pZoom, SceFloat32 a2 = 0.0f, SceInt32 a3 = 0, SceInt32 a4 = 0x10005, SceInt32 a5 = 0, SceInt32 a6 = 0, SceInt32 a7 = 0);

			SceInt32 SetRotation(const paf::Vector4 *pRot1, SceFloat32 a2 = 0.0f, const paf::Vector4 *pRot2 = SCE_NULL, SceInt32 a4 = 0, SceInt32 a5 = 0x10006, SceInt32 a6 = 0, SceInt32 a7 = 0, SceInt32 a8 = 0);

			SceInt32 SetAdjust(bool x, bool y, bool z);

			SceVoid SetGraphicsDisabled(bool disable);

			SceVoid SetOrientation();

			SceInt32 RegisterEventCallback(SceInt32 eventId, EventCallback *cb, bool a3);

			SceInt32 UnregisterEventCallback(SceInt32 eventId, SceInt32 a2, SceInt32 a3);

			SceInt32 RegisterFwEventCallback(SceFloat32 delay, SceInt32 eventId, EventCallback *cb);

			SceInt32 UnregisterFwEventCallback(SceInt32 eventId);

			SceInt32 AssignButton(SceUInt32 buttons);

			SceInt32 SetAlpha(SceFloat32 alpha, SceInt32 a2 = 0, SceInt32 a3 = 0x10003, SceInt32 a4 = 0, SceInt32 a5 = 0, SceInt32 a6 = 0);

			SceVoid Disable(bool a1);

			SceVoid Enable(bool a1);

			SceVoid SetLimitedFpsMode(bool enable);

			SceInt32 SetLoopEffect(LoopEffect effId, SceInt32 a2);

			SceInt32 PlayEffect(SceFloat32 parameter, paf::effect::EffectType animId, EventCallback::EventHandler animCB = 0, ScePVoid pUserData = SCE_NULL);

			SceInt32 PlayEffectReverse(SceFloat32 parameter, paf::effect::EffectType animId, EventCallback::EventHandler animCB = 0, ScePVoid pUserData = SCE_NULL);

		public:

			SceUChar8 unk_004[0x5D];

			SceUInt8 unk_061;

			SceUChar8 unk_062[0x74];

			SceUInt8 unk_0D6;

			SceUChar8 unk_0D7[0x75];

			SceUInt32 hash;

			SceUChar8 unk_150[0x24];

			SceUInt32 childNum;

			SceUChar8 unk_178[0x1E];

			SceUInt8 animationStatus;

			SceUChar8 unk_197[0x15];

			SceFloat32 alpha;

			SceUChar8 unk_1B4[0xD0];
		};

		class BusyIndicator : public Widget
		{
		public:

			BusyIndicator(Widget *parent, SceInt32 a2);

			virtual ~BusyIndicator();

			SceVoid Start();

			SceVoid Stop();

			SceVoid SetBallSize(SceFloat32 size);

		private:

			SceUChar8 unk_280[0x28];
		};

		class Text : public Widget //0x2d4
		{
		public:

			enum ColorType
			{
				ColorType_Text = 2,
				ColorType_TextShadow,
				ColorType_Background,
				ColorType_Unk5,
				ColorType_Unk6
			};

			enum CapFlag
			{
				CapFlag_CopyMode = 1,
				CapFlag_TextScroll = 2,
				CapFlag_PasteMode = 4,
				CapFlag_EditMode = 8
			};

			enum Option
			{
				Text_Bold = 0x7,
				Text_Shadow = 0xC,
				Text_ExternalLine = 0xD
			};


			Text(Widget *parent, SceInt32 a2);

			virtual ~Text();

			SceInt32 SetColor(ColorType type, SceInt32 a2, SceInt32 a3, const paf::Rgba *pColor);

			SceInt32 GetColor(ColorType type, SceInt32 a2, paf::Rgba *pColor);

			SceInt32 SetOption(Option option, SceInt32 a2, SceInt32 a3, bool enable);

			SceInt32 SetFontSize(SceFloat32 size, SceInt32 a2, SceSize pos, SceSize len);

		public:

			graph::TextObj *textObj;

			SceUChar8 unk_284[0x4];

			SceByte capFlags;

			SceUChar8 unk_289[0x3];

			paf::Rgba *pDisabledColor;

			SceUInt32 unk_290;

			SceUChar8 unk_294[0x1];

			SceUInt32 unk_298;

		private:

			SceUChar8 unk_29C[0x3C];
		};

		class TextBox : public Text
		{
		public:

			TextBox(Widget *parent, SceInt32 a2);

			virtual ~TextBox();

		private:

			SceChar8 unk_2D8[0x50];
		};

		class Plane : public Widget
		{
		public:

			Plane(Widget *parent, SceInt32 a2);

			virtual ~Plane();
		};

		class SpeechBalloon : public Plane
		{
		public:

			SpeechBalloon(Widget *parent, SceInt32 a2);

			virtual ~SpeechBalloon();

		private:

			SceChar8 unk_280[0x8];
		};

		class Box : public Plane
		{
		public:

			Box(Widget *parent, SceInt32 a2);

			virtual ~Box();

		private:

			SceUChar8 unk_280[0xA0];
		};

		class AppIconBase : public Widget
		{
		public:

			AppIconBase(Widget *parent, SceInt32 a2);

			virtual ~AppIconBase();
		};

		class AppIcon2D : public AppIconBase
		{
		public:

			AppIcon2D(Widget *parent, SceInt32 a2);

			virtual ~AppIcon2D();
		};

		class ButtonBase : public Widget
		{
		public:

			ButtonBase(Widget *parent, SceInt32 a2);

			virtual ~ButtonBase();

			SceVoid SetThreshold(SceInt32 threshold, SceInt32 repeatThreshold);

			SceChar8 unk_280[0xC];

			Rgba *pDisabledColor;

			SceUChar8 unk_290[0x1D];

			SceUInt8 state;

			//SceUChar8 unk_2AE[0x3];
		};

		class Button : public ButtonBase
		{
		public:

			Button(Widget *parent, SceInt32 a2);

			virtual ~Button();

		private:

			SceUChar8 unk_2AE[0x10];
		};

		class CornerButton : public Button
		{
		public:

			CornerButton(Widget *parent, SceInt32 a2);

			virtual ~CornerButton();

		private:

			SceUChar8 unk_2BE[0x10];
		};

		class Dialog : public Box
		{
		public:

			Dialog(Widget *parent, SceInt32 a2);

			virtual ~Dialog();

		private:

			SceUChar8 unk_320[0x10];
		};

		class ImageButton : public Button
		{
		public:

			ImageButton(Widget *parent, SceInt32 a2);

			virtual ~ImageButton();

		private:

			SceChar8 unk_2BE[0xA];

			graph::Surface *imageSurf;

			graph::Surface *baseSurf;

			SceChar8 unk_2D0[0x90];
		};

		//TODO
		class PlaneButton : public Widget
		{
		public:

			PlaneButton(Widget *parent, SceInt32 a2);

			virtual ~PlaneButton();
		};

		//TODO
		class CompositeButton : public Widget
		{
		public:

			CompositeButton(Widget *parent, SceInt32 a2);

			virtual ~CompositeButton();
		};

		class ImageSlidebar : public Widget
		{
		public:

			ImageSlidebar(Widget *parent, SceInt32 a2);

			virtual ~ImageSlidebar();

		private:

			SceChar8 unk_280[0x28];
		};

		class CompositeDrawer : public Widget
		{
		public:

			CompositeDrawer(Widget *parent, SceInt32 a2);

			virtual ~CompositeDrawer();
		};

		class ScrollViewBase : public Widget
		{
		public:

			ScrollViewBase(Widget *parent, SceInt32 a2);

			virtual ~ScrollViewBase();

		private:

			SceChar8 unk_280[0x180];
		};

		class SlidingDrawer : public ScrollViewBase
		{
		public:

			SlidingDrawer(Widget *parent, SceInt32 a2);

			virtual ~SlidingDrawer();
		};

		class ScrollViewParent : public Widget
		{
		public:

			ScrollViewParent(Widget *parent, SceInt32 a2);

			virtual ~ScrollViewParent();

		private:

			SceChar8 unk_280[0x28];
		};

		class ScrollView : public ScrollViewBase
		{
		public:

			ScrollView(Widget *parent, SceInt32 a2);

			virtual ~ScrollView();

			virtual int unkFun_1AC();
			virtual int unkFun_1B0();
			virtual int unkFun_1B4();
			virtual int unkFun_1B8();
			virtual int unkFun_1BC();
			virtual int unkFun_1C0();
			virtual int unkFun_1C4();
			virtual int unkFun_1C8();
			virtual int unkFun_1CC();
			virtual int unkFun_1D0();
			virtual int unkFun_1D4();
			virtual int unkFun_1D8();
			virtual int unkFun_1DC();
			virtual int unkFun_1E0();
			virtual int unkFun_1E4();
			virtual int unkFun_1E8();
			virtual int unkFun_1EC();
			virtual int unkFun_1F0();
			virtual int unkFun_1F4();
			virtual int unkFun_1F8();
			virtual int unkFun_1FC();
			virtual int unkFun_200();
			virtual int unkFun_204();
			virtual int unkFun_208();
			virtual int unkFun_20C();
			virtual int unkFun_210();
			virtual int unkFun_214();
			virtual int unkFun_218();
			virtual int unkFun_21C();
			virtual int unkFun_220();
			virtual int unkFun_224();
			virtual int unkFun_228();
			virtual int unkFun_22C(SceInt32 a2);
			virtual int unkFun_230();
			virtual int unkFun_234();
			virtual int unkFun_238();
			virtual int unkFun_23C();
			virtual int unkFun_240(SceFVector4 *a1, SceInt32 a2);
			virtual int unkFun_244();
			virtual int unkFun_248(SceInt32 a1);
			virtual int unkFun_24C(SceInt32 a1);
			virtual int unkFun_250();
			virtual int unkFun_254(SceUInt64 *a1, SceInt32 a2, SceInt32 a3, SceInt32 a4);
			virtual int unkFun_258(SceInt32 a1);
			virtual int unkFun_25C();
			virtual int unkFun_260(SceFVector4 *a1, SceInt32 a2);
			virtual int unkFun_264();
			virtual int unkFun_268();
			virtual int unkFun_26C();
			virtual int unkFun_270();
			virtual int unkFun_274(SceInt32 a1);

		private:

			SceChar8 unk_400[0x40];
		};

		class ScrollBar2D : public Widget
		{
		public:

			ScrollBar2D(Widget *parent, SceInt32 a2);

			virtual ~ScrollBar2D();

		private:

			SceChar8 unk_280[0x50];
		};

		class ScrollBar : public Widget
		{
		public:

			ScrollBar(Widget *parent, SceInt32 a2);

			virtual ~ScrollBar();

		private:

			SceChar8 unk_280[0x50];
		};

		class SlideBar : public Widget
		{
		public:

			SlideBar(Widget *parent, SceInt32 a2);

			virtual ~SlideBar();

		private:

			SceChar8 unk_280[0x70];
		};

		class RichText : public ScrollViewBase
		{
		public:

			RichText(Widget *parent, SceInt32 a2);

			virtual ~RichText();

			SceInt32 SetRichText(char *text, SceUInt32 len);
		};

		class PageTurnBase : public Widget
		{
		public:

			PageTurnBase(Widget *parent, SceInt32 a2);

			virtual ~PageTurnBase();

		private:

			SceChar8 unk_280[0x30];
		};

		class PageTurn : public Widget
		{
		public:

			PageTurn(Widget *parent, SceInt32 a2);

			virtual ~PageTurn();
		};

		class ProgressBar : public Widget
		{
		public:

			ProgressBar(Widget *parent, SceInt32 a2);

			virtual ~ProgressBar();

			virtual int unkFun_1AC();
			virtual int unkFun_1B0();
			virtual int unkFun_1B4();
			virtual int unkFun_1B8();
			virtual int unkFun_1BC();
			virtual int unkFun_1C0();
			virtual int unkFun_1C4();
			virtual int unkFun_1C8();
			virtual int unkFun_1CC();
			virtual int unkFun_1D0();
			virtual int unkFun_1D4();
			virtual int unkFun_1D8();
			virtual int unkFun_1DC();
			virtual int unkFun_1E0();
			virtual int unkFun_1E4();
			virtual int SetProgress(SceFloat32 value, SceUInt32 a2, SceUInt32 a3);
			virtual int unkFun_1EC();
			virtual int unkFun_1F0();
			virtual int unkFun_1F4();
			virtual int unkFun_1F8();
			virtual int unkFun_1FC();
			virtual int unkFun_200();

			SceUChar8 unk_280[0x1C];

			SceFloat32 maxValue;
			SceFloat32 minValue;
			SceFloat32 currentValue;

		private:

			SceChar8 unk_2A8[0x48];

		};

		class ProgressBarTouch : public ProgressBar
		{
		public:

			ProgressBarTouch(Widget *parent, SceInt32 a2);

			virtual ~ProgressBarTouch();

		private:

			SceChar8 unk_2F0[0x28];
		};

		class ListItem : public Widget
		{
		public:

			ListItem(Widget *parent, SceInt32 a2);

			virtual ~ListItem();

		private:

			SceUChar8 unk_280[0x50];
		};

		class ListView : public ScrollViewBase
		{
		public:

			ListView(Widget *parent, SceInt32 a2);

			virtual ~ListView();

		private:

			SceUChar8 unk_400[0xE8];
		};

		class FileList : public ListView
		{
		public:

			FileList(Widget *parent, SceInt32 a2);

			virtual ~FileList();
		};

		class RadioBox : public Widget
		{
		public:

			RadioBox(Widget *parent, SceInt32 a2);

			virtual ~RadioBox();
		};

		class StateButtonBase : public ButtonBase
		{
		public:

			StateButtonBase(Widget *parent, SceInt32 a2);

			virtual ~StateButtonBase();
		};

		class RadioButton : public StateButtonBase
		{
		public:

			RadioButton(Widget *parent, SceInt32 a2);

			virtual ~RadioButton();
		};

		class CheckBox : public StateButtonBase
		{
		public:

			virtual int unkFun_1AC();
			virtual int unkFun_1B0();
			virtual int unkFun_1B4();
			virtual int unkFun_1B8(SceInt32);
			virtual SceVoid SetChecked(SceFloat32 delay, bool checked, SceInt32 a3);
			virtual SceVoid SwitchChecked();
			virtual int unkFun_1C4();
			virtual int unkFun_1C8();

			CheckBox(Widget *parent, SceInt32 a2);

			virtual ~CheckBox();
		};

		//TODO
		class SpinBase : public Widget
		{
		public:

			SpinBase(Widget *parent, SceInt32 a2);

			virtual ~SpinBase();
		};

		//TODO
		class ItemSpin : public SpinBase
		{
		public:

			ItemSpin(Widget *parent, SceInt32 a2);

			virtual ~ItemSpin();
		};

		//TODO
		class NumSpin : public SpinBase
		{
		public:

			NumSpin(Widget *parent, SceInt32 a2);

			virtual ~NumSpin();
		};

		__declspec (dllimport) SceInt32 s_widget19999DA5;

		__declspec (dllimport) SceInt32 s_widget91871D2D;
	}
}

#endif /* _VDSUITE_USER_PAF_WIDGET_H */
