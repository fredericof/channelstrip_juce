
#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include<array>
#include<vector>

double GainMin = -60, GainMax = 60, GainPasso = 0.01, GainIni = 0, GainReset = 0;

double EqGainMin = -30, EqGainMax = 30, EqGainPasso = 0.1, EqGainIni = 0, EqGainReset = 0;
double EqFreqHiMin = 1000, EqFreqHiMax = 20000, EqFreqHiPasso = 1, EqFreqHiIni = 10000, EqFreqHiReset = 10000;
double EqFreqMidHiMin = 200, EqFreqMidHiMax = 5000, EqFreqMidHiPasso = 1, EqFreqMidHiIni = 1200, EqFreqMidHiReset = 1200;
double EqFreqMidLowMin = 80, EqFreqMidLowMax = 800, EqFreqMidLowPasso = 1, EqFreqMidLowIni = 250, EqFreqMidLowReset = 250;
double EqFreqLowMin = 15, EqFreqLowMax = 400, EqFreqLowPasso = 1, EqFreqLowIni = 80, EqFreqLowReset = 80;
double EqQMin = 0.5, EqQMax = 5, EqQPasso = 0.1, EqQIni = 1.4, EqQReset = 1.4;

double CompThresholdMin = -60, CompThresholdMax = 0, CompThresholdPasso = 0.1, CompThresholdIni = 0, CompThresholdReset = 0;
double CompRatioMin = 1, CompRatioMax = 20, CompRatioPasso = 0.1, CompRatioIni = 1, CompRatioReset = 0;
double CompAttackMin = 0.001, CompAttackMax = 100, CompAttackPasso = 0.001, CompAttackIni = 0.5, CompAttackReset = 0.5;
double CompReleaseMin = 0.001, CompReleaseMax = 1000, CompReleasePasso = 0.001, CompReleaseIni = 300, CompReleaseReset = 300;
double CompKneeMin = 0, CompKneeMax = 30, CompKneePasso = 0.1, CompKneeIni = 0, CompKneeReset = 0;
double CompMakeUpMin = 0, CompMakeUpMax = 40, CompMakeUpPasso = 0.1, CompMakeUpIni = 0, CompMakeUpReset = 0;

double ReverbMin = -144, ReverbMax = 0, ReverbPasso = 0.1, ReverbIni = -144, ReverbReset = -144;
double DelayMin = -144, DelayMax = 0, DelayPasso = 0.1, DelayIni = -144, DelayReset = -144;
double PanMin = 0, PanMax = 1, PanPasso = 0.01, PanIni = 0.5, PanReset = 0.5;
double LevelMin = -144, LevelMax = 6, LevelPasso = 0.1, LevelIni = -144, LevelReset = 0;

double ReverbDecayMin = 0, ReverbDecayMax = 0.98, ReverbDecayPasso = 0.01, ReverbDecayIni = 0.95, ReverbDecayReset = 0.95;
double ReverbDensityMin = 0, ReverbDensityMax = 0.95, ReverbDensityPasso, ReverbDensityIni = 0.5, ReverbDensityReset = 0.5;

double DelayTimeMin = 0, DelayTimeMax = 10, DelayTimePasso = 0.1, DelayTimeIni = 1, DelayTimeReset = 1;
double DelayFeedbackMin = 0, DelayFeedbackMax = 10, DelayFeedbackPasso = 0.1, DelayFeedbackIni = 2, DelayFeedbackReset = 2;

double MasterLevelMin = -144, MasterLevelMax = 10, MasterLevelPasso = 0.01, MasterLevelIni = 0, MasterLevelReset = 0;

class MainContentComponent : public AudioAppComponent, public Slider::Listener, public ToggleButton::Listener
{
#include <array>
public:  // MEMBROS PUBLICOS DA MainContentComponent

	int CSwidth = 100; //Channel Strip width - em pixels
	double Fs;		   //Armazena a frequencia de amostragem
	int TamanhoBuffer = 128;  // SETA O TAMANHO DO BUFFER DE ENTRADA/SAIDA
	int setSampleRate = 44100;


	//======================================================================================
	//      Valores Minimos, Maximos, Iniciais, de Passo e de Reset de cada parametro
	//======================================================================================

	//Minimos, Maximos, Inicial, de Passo e Reset de cada parametro dos canais
	// TODOS OS GANHOS ESTAO EM dB, Todas as Frequencias em Hz 
/*
	double GainMin = -60, GainMax = 60, GainPasso = 0.01, GainIni = 0, GainReset = 0;

	double EqGainMin = -30, EqGainMax = 30, EqGainPasso = 0.1, EqGainIni = 0, EqGainReset = 0;
	double EqFreqHiMin = 1000, EqFreqHiMax = 20000, EqFreqHiPasso = 1, EqFreqHiIni = 10000, EqFreqHiReset = 10000;
	double EqFreqMidHiMin = 200, EqFreqMidHiMax = 5000, EqFreqMidHiPasso = 1, EqFreqMidHiIni = 1200, EqFreqMidHiReset = 1200;
	double EqFreqMidLowMin = 80, EqFreqMidLowMax = 800, EqFreqMidLowPasso = 1, EqFreqMidLowIni = 250, EqFreqMidLowReset = 250;
	double EqFreqLowMin = 15, EqFreqLowMax = 400, EqFreqLowPasso = 1, EqFreqLowIni = 80, EqFreqLowReset = 80;
	double EqQMin = 0.5, EqQMax = 5, EqQPasso = 0.1, EqQIni = 1.4, EqQReset = 1.4;

	double CompThresholdMin = -60, CompThresholdMax = 0, CompThresholdPasso = 0.1, CompThresholdIni = 0, CompThresholdReset = 0;
	double CompRatioMin = 1, CompRatioMax = 100, CompRatioPasso = 0.1, CompRatioIni = 1, CompRatioReset = 0;
	double CompAttackMin = 0.01, CompAttackMax = 3000, CompAttackPasso = 0.01, CompAttackIni = 0.5, CompAttackReset = 0.5;
	double CompReleaseMin = 0.01, CompReleaseMax = 3000, CompReleasePasso = 0.01, CompReleaseIni = 300, CompReleaseReset = 300;
	double CompKneeMin = 0, CompKneeMax = 30, CompKneePasso = 0.1, CompKneeIni = 0, CompKneeReset = 0;
	double CompMakeUpMin = 0, CompMakeUpMax = 40, CompMakeUpPasso = 0.1, CompMakeUpIni = 0, CompMakeUpReset = 0;

	double ReverbMin = -144, ReverbMax = 0, ReverbPasso = 0.1, ReverbIni = -144, ReverbReset = -144;
	double DelayMin = -144, DelayMax = 0, DelayPasso = 0.1, DelayIni = -144, DelayReset = -144;
	double PanMin = 0, PanMax = 1, PanPasso = 0.01, PanIni = 0.5, PanReset = 0.5;
	double LevelMin = -144, LevelMax = 6, LevelPasso = 0.1, LevelIni = -144, LevelReset = 0;

	double ReverbDecayMin = 0, ReverbDecayMax = 0.95, ReverbDecayPasso = 0.01, ReverbDecayIni = 0.84, ReverbDecayReset = 0.84;
	double ReverbDensityMin = 0, ReverbDensityMax = 0.95, ReverbDensityPasso, ReverbDensityIni = 0.5, ReverbDensityReset = 0.5;

	double DelayTimeMin = 0, DelayTimeMax = 10, DelayTimePasso = 0.1, DelayTimeIni = 1, DelayTimeReset = 1;
	double DelayFeedbackMin = 0, DelayFeedbackMax = 10, DelayFeedbackPasso = 0.1, DelayFeedbackIni = 2, DelayFeedbackReset = 2;

	double MasterLevelMin = -144, MasterLevelMax = 10, MasterLevelPasso = 0.01, MasterLevelIni = 0, MasterLevelReset = 0;
*/
	String GainTextValueSuffix = "dB GAIN";

	String EQONTextValueSuffix = " EQ ON/OFF ";
	String EqGainHiTextValueSuffix = "dB Hi Gain";
	String EqGainMidHiTextValueSuffix = "dB MH Gain";
	String EqGainMidLowTextValueSuffix = "dB ML Gain";
	String EqGainLowTextValueSuffix = "dB Low Gain";
	String EqFreqTextValueSuffix = " Hz";
	String EqQTextValueSuffix = " Q";

	String CompONTextValueSuffix = " Comp ON/OFF ";
	String CompThresholdTextValueSuffix = " dB Thres";
	String CompRatioTextValueSuffix = " Ratio";
	String CompAttackTextValueSuffix = " ms Attack";
	String CompReleaseTextValueSuffix = " ms Release";
	String CompKneeTextValueSuffix = " dB Knee";
	String CompMakeUpTextValueSuffix = " dB MakeUp";

	String ReverbTextValueSuffix = " dB Reverb";
	String DelayTextValueSuffix = "dB Delay";
	String PanTextValueSuffix = " Pan";
	String LevelTextValueSuffix = " dB Level";

	String ReverbDecayTextValueSuffix = "s Decay";
	String ReverbDensityTextValueSuffix = " Density";
	String DelayTimeTextValueSuffix = "s Time";
	String DelayFeedbackTextValueSuffix = "s Feedback";
	String MasterLevelTextValueSuffix = "dB Level";

	String MuteTextValueSuffix = "Mute";
	String LabelCanal1setText = "Canal 1";
	String LabelCanal2setText = "Canal 2";
	String LabelCanal3setText = "Canal 3";
	String LabelCanal4setText = "Canal 4";
	String LabelReverbsetText = "Parametros do Reverb";
	String LabelDelaysetText = "Parametros do Delay";
	String LabelMastersetText = "MASTER LEVEL";

	//=================== VARIAVEIS/PAMETROS DE PROCESSAMENTO ========================

	struct ChannelStrip
	{

		double Gain = pow(10, 0 / 20);

		double AmostraAtual = 0;

		// EQUALIZADOR
		bool EqualizadorON = false;

		double Eq_Hi_Gain = 0;   // Ganho dB
		double Eq_Hi_Freq = 1000;

		double Eq_HiMid_Gain = 0; // Ganho dB
		double Eq_HiMid_Freq = 1200;
		double Eq_HiMid_Q = 1.4;

		double Eq_LowMid_Gain = 0; // Ganho dB
		double Eq_LowMid_Freq = 250;
		double Eq_LowMid_Q = 1.4;

		double Eq_Low_Gain = 1; // Ganho dB
		double Eq_Low_Freq = 80;

		struct
		{
			double a0 = 1, a1 = 0, a2 = 0, b1 = 0, b2 = 0, Y1 = 0, Y2 = 0;

		}Hi_Coef, HiMid_Coef, LowMid_Coef, Low_Coef; //Parametros para calculo do filtro

													 //COMPRESSOR VARIABLES
		bool CompressorOn = false;
		double Comp_Threshold = 0;
		double Comp_Ratio = 1;
		double Comp_Attack = CompAttackIni;
		double Comp_Release = CompReleaseIni;
		double Comp_KneeWidth = 1;
		double Comp_MakeUp = 1;		// NAO E EM dB - Usar numero puro
		double Comp_AlfaAttack = 0;
		double Comp_AlfaRelease = 0;

		double XdB = 0, Xsc = 0, Gc = 0; //Ganho de compressao
		double Gs0 = 0, Gs1 = 0;  //Ganho de compressao suavizado - Smooth Gain
		double Glin = 1;   // Ganho linear a ser aplicado no sinal

						   //MIXAGEM
		double Aux_Reverb = pow(10, -144 / 20);
		double Aux_Delay = pow(10, -144 / 20);
		double PanR = 0.5;
		double PanL = 0.5;
		double Level = pow(10, -144 / 20);
		double Mute = 1;

	} ChannelStrip1, ChannelStrip2, ChannelStrip3, ChannelStrip4;

	struct RReverb
	{
		double Decay = 0.5;
		double Density = 500;
		bool ReverbOn = false;
		double Fcorte = 5000;
		double a0 = 1, a1 = 0, a2 = 0, b1 = 0, b2 = 0, Y1 = 0, Y2 = 0, AmostraAtual;

	} RReverb;

	struct Delay {
		double Time = 1;
		double Feedback = 2;
		bool DelayOn = false;
	} Delay;

	double MasterLevel = pow(10, 0 / 20);

	//====================================================================================
	//					   FUNÇÕES UTILIZADAS NO PROCESSAMENTO
	//====================================================================================

	//========================		EQUALIZADOR		==============================

	void calculaequalizadorparametrico(ChannelStrip &CS)
	{
		double V = pow(10, fabs(CS.Eq_HiMid_Gain) / 20); // Ganho LINEAR
		double K = tan(double_Pi * CS.Eq_HiMid_Freq / Fs);
		double norm;

		/// /// /// /// HI MID /// /// /// /// 

		if (CS.Eq_HiMid_Gain < 0)
		{
			//Peak Cut
			norm = 1 / (1 + V / CS.Eq_HiMid_Q * K + K * K);
			CS.HiMid_Coef.a0 = (1 + 1 / CS.Eq_HiMid_Q * K + K * K) * norm;
			CS.HiMid_Coef.a1 = 2 * (K * K - 1) * norm;
			CS.HiMid_Coef.a2 = (1 - 1 / CS.Eq_HiMid_Q * K + K * K) * norm;
			CS.HiMid_Coef.b1 = CS.HiMid_Coef.a1;
			CS.HiMid_Coef.b2 = (1 - V / CS.Eq_HiMid_Q * K + K * K) * norm;
		}
		else if (CS.Eq_HiMid_Gain > 0)
		{
			//Peak Boost

			norm = 1 / (1 + 1 / CS.Eq_HiMid_Q * K + K * K);
			CS.HiMid_Coef.a0 = (1 + V / CS.Eq_HiMid_Q * K + K * K) * norm;
			CS.HiMid_Coef.a1 = 2 * (K * K - 1) * norm;
			CS.HiMid_Coef.a2 = (1 - V / CS.Eq_HiMid_Q * K + K * K) * norm;
			CS.HiMid_Coef.b1 = CS.HiMid_Coef.a1;
			CS.HiMid_Coef.b2 = (1 - 1 / CS.Eq_HiMid_Q * K + K * K) * norm;
		}
		else if (CS.Eq_HiMid_Gain == 0)
		{
			CS.HiMid_Coef.a0 = 1;
			CS.HiMid_Coef.a1 = 0;
			CS.HiMid_Coef.a2 = 0;
			CS.HiMid_Coef.b1 = 0;
			CS.HiMid_Coef.b2 = 0;
		}

		CS.HiMid_Coef.Y1 = CS.HiMid_Coef.Y2 = 0.0;

		/// LOW MID

		V = pow(10, fabs(CS.Eq_LowMid_Gain) / 20); // Ganho LINEAR
		K = tan(double_Pi * CS.Eq_LowMid_Freq / Fs);

		if (CS.Eq_LowMid_Gain < 0.0)
		{
			//Peak Cut
			norm = 1 / (1 + V / CS.Eq_LowMid_Q * K + K * K);
			CS.LowMid_Coef.a0 = (1 + 1 / CS.Eq_LowMid_Q * K + K * K) * norm;
			CS.LowMid_Coef.a1 = 2 * (K * K - 1) * norm;
			CS.LowMid_Coef.a2 = (1 - 1 / CS.Eq_LowMid_Q * K + K * K) * norm;
			CS.LowMid_Coef.b1 = CS.LowMid_Coef.a1;
			CS.LowMid_Coef.b2 = (1 - V / CS.Eq_LowMid_Q * K + K * K) * norm;
		}
		else if (CS.Eq_LowMid_Gain > 0.0)
		{
			//Peak Boost
			norm = 1 / (1 + 1 / CS.Eq_LowMid_Q * K + K * K);
			CS.LowMid_Coef.a0 = (1 + V / CS.Eq_LowMid_Q * K + K * K) * norm;
			CS.LowMid_Coef.a1 = 2 * (K * K - 1) * norm;
			CS.LowMid_Coef.a2 = (1 - V / CS.Eq_LowMid_Q * K + K * K) * norm;
			CS.LowMid_Coef.b1 = CS.LowMid_Coef.a1;
			CS.LowMid_Coef.b2 = (1 - 1 / CS.Eq_LowMid_Q * K + K * K) * norm;
		}
		else if (CS.Eq_LowMid_Gain == 0.0)
		{
			CS.LowMid_Coef.a0 = 1;
			CS.LowMid_Coef.a1 = 0;
			CS.LowMid_Coef.a2 = 0;
			CS.LowMid_Coef.b1 = 0;
			CS.LowMid_Coef.b2 = 0;
		}

		CS.LowMid_Coef.Y1 = CS.LowMid_Coef.Y2 = 0.0;

	}

	void calculaequalizadorshelving(ChannelStrip &CS)
	{

		///  /// /// ///   HI   ///  /// /// 

		double A = pow(10, CS.Eq_Hi_Gain / 40);
		double omega = 2 * double_Pi * CS.Eq_Hi_Freq / Fs;
		double omegaS = sin(omega);
		double omegaC = cos(omega);
		double beta = sqrt(A) / 1.4;
		double a0, a1, a2, b0, b1, b2;

		if (CS.Eq_Hi_Gain != 0)
		{
			b0 = A * ((A + 1) + ((A - 1) * omegaC) + beta*omegaS);
			b1 = -2 * A * ((A - 1) + ((A + 1) * omegaC));
			b2 = A * ((A + 1) + ((A - 1) * omegaC) - (beta * omegaS));
			a0 = (A + 1) - (A - 1)*omegaC + beta*omegaS;
			a1 = 2 * ((A - 1) - ((A + 1) * omegaC));
			a2 = (A + 1) - (A - 1)*omegaC - beta*omegaS;

			CS.Hi_Coef.a0 = b0 / a0;
			CS.Hi_Coef.a1 = b1 / a0;
			CS.Hi_Coef.a2 = b2 / a0;
			CS.Hi_Coef.b1 = a1 / a0;
			CS.Hi_Coef.b2 = a2 / a0;
		}
		else if (CS.Eq_Hi_Gain == 0)
		{

			CS.Hi_Coef.a0 = 1;
			CS.Hi_Coef.a1 = 0;
			CS.Hi_Coef.a2 = 0;
			CS.Hi_Coef.b1 = 0;
			CS.Hi_Coef.b2 = 0;
		}

		CS.Hi_Coef.Y1 = CS.Hi_Coef.Y2 = 0;

		///  /// /// ///   LOW   ///  /// /// ///

		A = pow(10, CS.Eq_Low_Gain / 40);
		omega = 2 * double_Pi * CS.Eq_Low_Freq / Fs;
		omegaS = sin(omega);
		omegaC = cos(omega);
		beta = sqrt(A) / 0.707;
		a0, a1, a2, b0, b1, b2;

		if (CS.Eq_Low_Gain != 0)
		{
			b0 = A * ((A + 1) - ((A - 1) * omegaC) + beta*omegaS);
			b1 = 2 * A * ((A - 1) - ((A + 1) * omegaC));
			b2 = A * ((A + 1) - ((A - 1) * omegaC) - (beta * omegaS));
			a0 = (A + 1) + (A - 1)*omegaC + beta*omegaS;
			a1 = -2 * ((A - 1) + ((A + 1) * omegaC));
			a2 = (A + 1) + (A - 1)*omegaC - beta*omegaS;

			CS.Low_Coef.a0 = b0 / a0;
			CS.Low_Coef.a1 = b1 / a0;
			CS.Low_Coef.a2 = b2 / a0;
			CS.Low_Coef.b1 = a1 / a0;
			CS.Low_Coef.b2 = a2 / a0;
		}
		else if (CS.Eq_Low_Gain == 0)
		{

			CS.Low_Coef.a0 = 1;
			CS.Low_Coef.a1 = 0;
			CS.Low_Coef.a2 = 0;
			CS.Low_Coef.b1 = 0;
			CS.Low_Coef.b2 = 0;
		}

		CS.Low_Coef.Y1 = CS.Low_Coef.Y2 = 0;

	}

	//========================		COMPRESSOR		==============================

	void calculacompressor(ChannelStrip &endereco, Slider &EndTemp_Attack, Slider &EndTemp_Release)
	{
		double Temp_Attack, Temp_Release;
		Temp_Attack = 0.001 * EndTemp_Attack.getValue();
		Temp_Release = 0.001 * EndTemp_Release.getValue();
		endereco.Comp_AlfaAttack = 1 - exp(-2.2 / (Fs * Temp_Attack) );
		endereco.Comp_AlfaRelease = 1 - exp(-2.2 / (Fs * Temp_Release) );
	}

	//========================		REVERB		==============================
	void calculareverb()
	{

		double omega = 2 * double_Pi * RReverb.Fcorte / Fs;
		double omegaS = sin(omega);
		double omegaC = cos(omega);
		double alfa = omegaS / 2 * 0.8;
		double a0, a1, a2, b0, b1, b2;

		b0 = (1 - omegaC) / 2;
		b1 = (1 - omegaC);
		b2 = (1 - omegaC) / 2;
		a0 = 1 + alfa;
		a1 = -2 * omegaC;
		a2 = 1 - alfa;

		RReverb.a0 = b0 / a0;
		RReverb.a1 = b1 / a0;
		RReverb.a2 = b2 / a0;
		RReverb.b1 = a1 / a0;
		RReverb.b2 = a2 / a0;

	}

	MainContentComponent()
	{

		//==========================================
		//             GRAFICOS CANAL 1
		//==========================================

		//Label
		labelCanal1.setText(LabelCanal1setText, dontSendNotification);
		labelCanal1.setColour(Label::textColourId, Colours::black);
		labelCanal1.setColour(Label::backgroundColourId, Colours::whitesmoke);
		labelCanal1.setJustificationType(Justification::centred);
		addAndMakeVisible(labelCanal1);

		//Ganho
		wGain_1.setRange(GainMin, GainMax, GainPasso);
		wGain_1.setValue(GainIni);
		wGain_1.setDoubleClickReturnValue(true, GainReset);
		wGain_1.setSliderStyle(Slider::LinearHorizontal);
		wGain_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wGain_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wGain_1.setTextValueSuffix(GainTextValueSuffix);
		wGain_1.addListener(this);
		addAndMakeVisible(wGain_1);

		//Enable EQ
		addAndMakeVisible(wEq_OnOff_1);
		wEq_OnOff_1.toBack();
		wEq_OnOff_1.setToggleState(false, false);
		wEq_OnOff_1.setColour(ToggleButton::tickColourId, Colours::black);
		wEq_OnOff_1.setColour(ToggleButton::tickDisabledColourId, Colours::black);
		wEq_OnOff_1.setButtonText(EQONTextValueSuffix);
		wEq_OnOff_1.setColour(ToggleButton::textColourId, Colours::black);
		wEq_OnOff_1.addListener(this);

		//GanhoHi
		wEq_Gain_Hi_1.setRange(EqGainMin, EqGainMax, EqGainPasso);
		wEq_Gain_Hi_1.setValue(EqGainIni);
		wEq_Gain_Hi_1.setDoubleClickReturnValue(true, EqGainReset);
		wEq_Gain_Hi_1.setSliderStyle(Slider::LinearHorizontal);
		wEq_Gain_Hi_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Gain_Hi_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Gain_Hi_1.setTextValueSuffix(EqGainHiTextValueSuffix);
		wEq_Gain_Hi_1.setColour(Slider::backgroundColourId, Colours::white);
		wEq_Gain_Hi_1.addListener(this);
		addAndMakeVisible(wEq_Gain_Hi_1);
		//FreqHi
		wEq_Freq_Hi_1.setRange(EqFreqHiMin, EqFreqHiMax, EqFreqHiPasso);
		wEq_Freq_Hi_1.setValue(EqFreqHiIni);
		wEq_Freq_Hi_1.setDoubleClickReturnValue(true, EqFreqHiReset);
		wEq_Freq_Hi_1.setSliderStyle(Slider::LinearHorizontal);
		wEq_Freq_Hi_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Freq_Hi_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Freq_Hi_1.setTextValueSuffix(EqFreqTextValueSuffix);
		wEq_Freq_Hi_1.addListener(this);
		addAndMakeVisible(wEq_Freq_Hi_1);
		//GainMidHi
		wEq_Gain_MidHi_1.setRange(EqGainMin, EqGainMax, EqGainPasso);
		wEq_Gain_MidHi_1.setValue(EqGainIni);
		wEq_Gain_MidHi_1.setDoubleClickReturnValue(true, EqGainReset);
		wEq_Gain_MidHi_1.setSliderStyle(Slider::LinearHorizontal);
		wEq_Gain_MidHi_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Gain_MidHi_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Gain_MidHi_1.setTextValueSuffix(EqGainMidHiTextValueSuffix);
		wEq_Gain_MidHi_1.setColour(Slider::backgroundColourId, Colours::white);
		wEq_Gain_MidHi_1.addListener(this);
		addAndMakeVisible(wEq_Gain_MidHi_1);
		//FreqMidHi
		wEq_Freq_MidHi_1.setRange(EqFreqMidHiMin, EqFreqMidHiMax, EqFreqMidHiPasso);
		wEq_Freq_MidHi_1.setValue(EqFreqMidHiIni);
		wEq_Freq_MidHi_1.setDoubleClickReturnValue(true, EqFreqMidHiReset);
		wEq_Freq_MidHi_1.setSliderStyle(Slider::LinearHorizontal);
		wEq_Freq_MidHi_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Freq_MidHi_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Freq_MidHi_1.setTextValueSuffix(EqFreqTextValueSuffix);
		wEq_Freq_MidHi_1.addListener(this);
		addAndMakeVisible(wEq_Freq_MidHi_1);
		//QMidHi
		wEq_Q_MidHi_1.setRange(EqQMin, EqQMax, EqQPasso);
		wEq_Q_MidHi_1.setValue(EqQIni);
		wEq_Q_MidHi_1.setDoubleClickReturnValue(true, EqQReset);
		wEq_Q_MidHi_1.setSliderStyle(Slider::LinearHorizontal);
		wEq_Q_MidHi_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Q_MidHi_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Q_MidHi_1.setTextValueSuffix(EqQTextValueSuffix);
		wEq_Q_MidHi_1.addListener(this);
		addAndMakeVisible(wEq_Q_MidHi_1);
		//GainMidLow
		wEq_Gain_MidLow_1.setRange(EqGainMin, EqGainMax, EqGainPasso);
		wEq_Gain_MidLow_1.setValue(EqGainIni);
		wEq_Gain_MidLow_1.setDoubleClickReturnValue(true, EqGainReset);
		wEq_Gain_MidLow_1.setSliderStyle(Slider::LinearHorizontal);
		wEq_Gain_MidLow_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Gain_MidLow_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Gain_MidLow_1.setTextValueSuffix(EqGainMidLowTextValueSuffix);
		wEq_Gain_MidLow_1.setColour(Slider::backgroundColourId, Colours::white);
		wEq_Gain_MidLow_1.addListener(this);
		addAndMakeVisible(wEq_Gain_MidLow_1);
		//FreqMidLow
		wEq_Freq_MidLow_1.setRange(EqFreqMidLowMin, EqFreqMidLowMax, EqFreqMidLowPasso);
		wEq_Freq_MidLow_1.setValue(EqFreqMidLowIni);
		wEq_Freq_MidLow_1.setDoubleClickReturnValue(true, EqFreqMidLowReset);
		wEq_Freq_MidLow_1.setSliderStyle(Slider::LinearHorizontal);
		wEq_Freq_MidLow_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Freq_MidLow_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Freq_MidLow_1.setTextValueSuffix(EqFreqTextValueSuffix);
		wEq_Freq_MidLow_1.addListener(this);
		addAndMakeVisible(wEq_Freq_MidLow_1);
		//QMidLow
		wEq_Q_MidLow_1.setRange(EqQMin, EqQMax, EqQPasso);
		wEq_Q_MidLow_1.setValue(EqQIni);
		wEq_Q_MidLow_1.setDoubleClickReturnValue(true, EqQReset);
		wEq_Q_MidLow_1.setSliderStyle(Slider::LinearHorizontal);
		wEq_Q_MidLow_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Q_MidLow_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Q_MidLow_1.setTextValueSuffix(EqQTextValueSuffix);
		wEq_Q_MidLow_1.addListener(this);
		addAndMakeVisible(wEq_Q_MidLow_1);
		//
		//GanhoLow
		wEq_Gain_Low_1.setRange(EqGainMin, EqGainMax, EqGainPasso);
		wEq_Gain_Low_1.setValue(EqGainIni);
		wEq_Gain_Low_1.setDoubleClickReturnValue(true, EqGainReset);
		wEq_Gain_Low_1.setSliderStyle(Slider::LinearHorizontal);
		wEq_Gain_Low_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Gain_Low_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Gain_Low_1.setTextValueSuffix(EqGainLowTextValueSuffix);
		wEq_Gain_Low_1.setColour(Slider::backgroundColourId, Colours::white);
		wEq_Gain_Low_1.addListener(this);
		addAndMakeVisible(wEq_Gain_Low_1);
		//FreqLow
		wEq_Freq_Low_1.setRange(EqFreqLowMin, EqFreqLowMax, EqFreqLowPasso);
		wEq_Freq_Low_1.setValue(EqFreqLowIni);
		wEq_Freq_Low_1.setDoubleClickReturnValue(true, EqFreqLowReset);
		wEq_Freq_Low_1.setSliderStyle(Slider::LinearHorizontal);
		wEq_Freq_Low_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Freq_Low_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Freq_Low_1.setTextValueSuffix(EqFreqTextValueSuffix);
		wEq_Freq_Low_1.addListener(this);
		addAndMakeVisible(wEq_Freq_Low_1);

		//Enable COMPRESSOR
		addAndMakeVisible(wCompOnOff_1);
		wCompOnOff_1.toBack();
		wCompOnOff_1.setToggleState(false, false);
		wCompOnOff_1.setColour(ToggleButton::tickColourId, Colours::black);
		wCompOnOff_1.setColour(ToggleButton::tickDisabledColourId, Colours::black);
		wCompOnOff_1.setButtonText(CompONTextValueSuffix);
		wCompOnOff_1.setColour(ToggleButton::textColourId, Colours::black);
		wCompOnOff_1.addListener(this);

		//CompThreshold
		wCompThreshold_1.setRange(CompThresholdMin, CompThresholdMax, CompThresholdPasso);
		wCompThreshold_1.setValue(CompThresholdIni);
		wCompThreshold_1.setDoubleClickReturnValue(true, CompThresholdReset);
		wCompThreshold_1.setSliderStyle(Slider::LinearHorizontal);
		wCompThreshold_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompThreshold_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompThreshold_1.setTextValueSuffix(CompThresholdTextValueSuffix);
		wCompThreshold_1.addListener(this);
		addAndMakeVisible(wCompThreshold_1);
		//CompRatio
		wCompRatio_1.setRange(CompRatioMin, CompRatioMax, CompRatioPasso);
		wCompRatio_1.setValue(CompRatioIni);
		wCompRatio_1.setDoubleClickReturnValue(true, CompRatioReset);
		wCompRatio_1.setSliderStyle(Slider::LinearHorizontal);
		wCompRatio_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompRatio_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompRatio_1.setTextValueSuffix(CompRatioTextValueSuffix);
		wCompRatio_1.addListener(this);
		addAndMakeVisible(wCompRatio_1);
		//CompAttack
		wCompAttack_1.setRange(CompAttackMin, CompAttackMax, CompAttackPasso);
		wCompAttack_1.setValue(CompAttackIni);
		wCompAttack_1.setDoubleClickReturnValue(true, CompAttackReset);
		wCompAttack_1.setSliderStyle(Slider::LinearHorizontal);
		wCompAttack_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompAttack_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompAttack_1.setTextValueSuffix(CompAttackTextValueSuffix);
		wCompAttack_1.addListener(this);
		addAndMakeVisible(wCompAttack_1);
		//CompRelease
		wCompRelease_1.setRange(CompReleaseMin, CompReleaseMax, CompReleasePasso);
		wCompRelease_1.setValue(CompReleaseIni);
		wCompRelease_1.setDoubleClickReturnValue(true, CompReleaseReset);
		wCompRelease_1.setSliderStyle(Slider::LinearHorizontal);
		wCompRelease_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompRelease_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompRelease_1.setTextValueSuffix(CompReleaseTextValueSuffix);
		wCompRelease_1.addListener(this);
		addAndMakeVisible(wCompRelease_1);
		//CompKnee
		wCompKnee_1.setRange(CompKneeMin, CompKneeMax, CompKneePasso);
		wCompKnee_1.setValue(CompKneeIni);
		wCompKnee_1.setDoubleClickReturnValue(true, CompKneeReset);
		wCompKnee_1.setSliderStyle(Slider::LinearHorizontal);
		wCompKnee_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompKnee_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompKnee_1.setTextValueSuffix(CompKneeTextValueSuffix);
		wCompKnee_1.addListener(this);
		addAndMakeVisible(wCompKnee_1);
		//CompMakeUp
		wCompMakeUp_1.setRange(CompMakeUpMin, CompMakeUpMax, CompMakeUpPasso);
		wCompMakeUp_1.setValue(CompMakeUpIni);
		wCompMakeUp_1.setDoubleClickReturnValue(true, CompMakeUpReset);
		wCompMakeUp_1.setSliderStyle(Slider::LinearHorizontal);
		wCompMakeUp_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompMakeUp_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompMakeUp_1.setTextValueSuffix(CompMakeUpTextValueSuffix);
		wCompMakeUp_1.addListener(this);
		addAndMakeVisible(wCompMakeUp_1);
		//AuxilarReverb
		wAuxReverb_1.setRange(ReverbMin, ReverbMax, ReverbPasso);
		wAuxReverb_1.setValue(ReverbIni);
		wAuxReverb_1.setDoubleClickReturnValue(true, ReverbReset);
		wAuxReverb_1.setSkewFactorFromMidPoint(-24);
		wAuxReverb_1.setSliderStyle(Slider::LinearHorizontal);
		wAuxReverb_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wAuxReverb_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wAuxReverb_1.setTextValueSuffix(ReverbTextValueSuffix);
		wAuxReverb_1.addListener(this);
		addAndMakeVisible(wAuxReverb_1);
		//AuxilarDelay
		wAuxDelay_1.setRange(DelayMin, DelayMax, DelayPasso);
		wAuxDelay_1.setValue(DelayIni);
		wAuxDelay_1.setDoubleClickReturnValue(true, DelayReset);
		wAuxDelay_1.setSkewFactorFromMidPoint(-24);
		wAuxDelay_1.setSliderStyle(Slider::LinearHorizontal);
		wAuxDelay_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wAuxDelay_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wAuxDelay_1.setTextValueSuffix(DelayTextValueSuffix);
		wAuxDelay_1.addListener(this);
		addAndMakeVisible(wAuxDelay_1);
		//Pan
		wPan_1.setRange(PanMin, PanMax, PanPasso);
		wPan_1.setValue(PanIni);
		wPan_1.setDoubleClickReturnValue(true, PanReset);
		wPan_1.setSliderStyle(Slider::LinearHorizontal);
		wPan_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wPan_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wPan_1.setTextValueSuffix(PanTextValueSuffix);
		wPan_1.addListener(this);
		addAndMakeVisible(wPan_1);
		//Level
		wLevel_1.setRange(LevelMin, LevelMax, LevelPasso);
		wLevel_1.setValue(LevelIni);
		wLevel_1.setDoubleClickReturnValue(true, LevelReset);
		wLevel_1.setSkewFactorFromMidPoint(-6);
		wLevel_1.setSliderStyle(Slider::LinearVertical);
		wLevel_1.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wLevel_1.setColour(Slider::textBoxTextColourId, Colours::black);
		wLevel_1.setTextValueSuffix(LevelTextValueSuffix);
		wLevel_1.addListener(this);
		addAndMakeVisible(wLevel_1);

		addAndMakeVisible(wMute_1);
		wMute_1.toBack();
		wMute_1.setToggleState(false, false);
		wMute_1.setColour(ToggleButton::tickColourId, Colours::black);
		wMute_1.setColour(ToggleButton::tickDisabledColourId, Colours::black);
		wMute_1.setButtonText(MuteTextValueSuffix);
		wMute_1.setColour(ToggleButton::textColourId, Colours::black);
		wMute_1.addListener(this);

		//==========================================
		//             GRAFICOS CANAL 2
		//==========================================

		//Label
		labelCanal2.setText(LabelCanal2setText, dontSendNotification);
		labelCanal2.setColour(Label::textColourId, Colours::black);
		labelCanal2.setColour(Label::backgroundColourId, Colours::whitesmoke);
		labelCanal2.setJustificationType(Justification::centred);
		addAndMakeVisible(labelCanal2);

		//Ganho
		wGain_2.setRange(GainMin, GainMax, GainPasso);
		wGain_2.setValue(GainIni);
		wGain_2.setDoubleClickReturnValue(true, GainReset);
		wGain_2.setSliderStyle(Slider::LinearHorizontal);
		wGain_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wGain_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wGain_2.setTextValueSuffix(GainTextValueSuffix);
		wGain_2.addListener(this);
		addAndMakeVisible(wGain_2);

		//Enable EQ
		addAndMakeVisible(wEq_OnOff_2);
		wEq_OnOff_2.toBack();
		wEq_OnOff_2.setToggleState(false, false);
		wEq_OnOff_2.setColour(ToggleButton::tickColourId, Colours::black);
		wEq_OnOff_2.setColour(ToggleButton::tickDisabledColourId, Colours::black);
		wEq_OnOff_2.setButtonText(EQONTextValueSuffix);
		wEq_OnOff_2.setColour(ToggleButton::textColourId, Colours::black);
		wEq_OnOff_2.addListener(this);

		//GanhoHi
		wEq_Gain_Hi_2.setRange(EqGainMin, EqGainMax, EqGainPasso);
		wEq_Gain_Hi_2.setValue(EqGainIni);
		wEq_Gain_Hi_2.setDoubleClickReturnValue(true, EqGainReset);
		wEq_Gain_Hi_2.setSliderStyle(Slider::LinearHorizontal);
		wEq_Gain_Hi_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Gain_Hi_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Gain_Hi_2.setTextValueSuffix(EqGainHiTextValueSuffix);
		wEq_Gain_Hi_2.setColour(Slider::backgroundColourId, Colours::white);
		wEq_Gain_Hi_2.addListener(this);
		addAndMakeVisible(wEq_Gain_Hi_2);
		//FreqHi
		wEq_Freq_Hi_2.setRange(EqFreqHiMin, EqFreqHiMax, EqFreqHiPasso);
		wEq_Freq_Hi_2.setValue(EqFreqHiIni);
		wEq_Freq_Hi_2.setDoubleClickReturnValue(true, EqFreqHiReset);
		wEq_Freq_Hi_2.setSliderStyle(Slider::LinearHorizontal);
		wEq_Freq_Hi_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Freq_Hi_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Freq_Hi_2.setTextValueSuffix(EqFreqTextValueSuffix);
		wEq_Freq_Hi_2.addListener(this);
		addAndMakeVisible(wEq_Freq_Hi_2);
		//GainMidHi
		wEq_Gain_MidHi_2.setRange(EqGainMin, EqGainMax, EqGainPasso);
		wEq_Gain_MidHi_2.setValue(EqGainIni);
		wEq_Gain_MidHi_2.setDoubleClickReturnValue(true, EqGainReset);
		wEq_Gain_MidHi_2.setSliderStyle(Slider::LinearHorizontal);
		wEq_Gain_MidHi_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Gain_MidHi_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Gain_MidHi_2.setTextValueSuffix(EqGainMidHiTextValueSuffix);
		wEq_Gain_MidHi_2.setColour(Slider::backgroundColourId, Colours::white);
		wEq_Gain_MidHi_2.addListener(this);
		addAndMakeVisible(wEq_Gain_MidHi_2);
		//FreqMidHi
		wEq_Freq_MidHi_2.setRange(EqFreqMidHiMin, EqFreqMidHiMax, EqFreqMidHiPasso);
		wEq_Freq_MidHi_2.setValue(EqFreqMidHiIni);
		wEq_Freq_MidHi_2.setDoubleClickReturnValue(true, EqFreqMidHiReset);
		wEq_Freq_MidHi_2.setSliderStyle(Slider::LinearHorizontal);
		wEq_Freq_MidHi_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Freq_MidHi_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Freq_MidHi_2.setTextValueSuffix(EqFreqTextValueSuffix);
		wEq_Freq_MidHi_2.addListener(this);
		addAndMakeVisible(wEq_Freq_MidHi_2);
		//QMidHi
		wEq_Q_MidHi_2.setRange(EqQMin, EqQMax, EqQPasso);
		wEq_Q_MidHi_2.setValue(EqQIni);
		wEq_Q_MidHi_2.setDoubleClickReturnValue(true, EqQReset);
		wEq_Q_MidHi_2.setSliderStyle(Slider::LinearHorizontal);
		wEq_Q_MidHi_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Q_MidHi_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Q_MidHi_2.setTextValueSuffix(EqQTextValueSuffix);
		wEq_Q_MidHi_2.addListener(this);
		addAndMakeVisible(wEq_Q_MidHi_2);
		//GainMidLow
		wEq_Gain_MidLow_2.setRange(EqGainMin, EqGainMax, EqGainPasso);
		wEq_Gain_MidLow_2.setValue(EqGainIni);
		wEq_Gain_MidLow_2.setDoubleClickReturnValue(true, EqGainReset);
		wEq_Gain_MidLow_2.setSliderStyle(Slider::LinearHorizontal);
		wEq_Gain_MidLow_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Gain_MidLow_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Gain_MidLow_2.setTextValueSuffix(EqGainMidLowTextValueSuffix);
		wEq_Gain_MidLow_2.setColour(Slider::backgroundColourId, Colours::white);
		wEq_Gain_MidLow_2.addListener(this);
		addAndMakeVisible(wEq_Gain_MidLow_2);
		//FreqMidLow
		wEq_Freq_MidLow_2.setRange(EqFreqMidLowMin, EqFreqMidLowMax, EqFreqMidLowPasso);
		wEq_Freq_MidLow_2.setValue(EqFreqMidLowIni);
		wEq_Freq_MidLow_2.setDoubleClickReturnValue(true, EqFreqMidLowReset);
		wEq_Freq_MidLow_2.setSliderStyle(Slider::LinearHorizontal);
		wEq_Freq_MidLow_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Freq_MidLow_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Freq_MidLow_2.setTextValueSuffix(EqFreqTextValueSuffix);
		wEq_Freq_MidLow_2.addListener(this);
		addAndMakeVisible(wEq_Freq_MidLow_2);
		//QMidLow
		wEq_Q_MidLow_2.setRange(EqQMin, EqQMax, EqQPasso);
		wEq_Q_MidLow_2.setValue(EqQIni);
		wEq_Q_MidLow_2.setDoubleClickReturnValue(true, EqQReset);
		wEq_Q_MidLow_2.setSliderStyle(Slider::LinearHorizontal);
		wEq_Q_MidLow_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Q_MidLow_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Q_MidLow_2.setTextValueSuffix(EqQTextValueSuffix);
		wEq_Q_MidLow_2.addListener(this);
		addAndMakeVisible(wEq_Q_MidLow_2);
		//
		//GanhoLow
		wEq_Gain_Low_2.setRange(EqGainMin, EqGainMax, EqGainPasso);
		wEq_Gain_Low_2.setValue(EqGainIni);
		wEq_Gain_Low_2.setDoubleClickReturnValue(true, EqGainReset);
		wEq_Gain_Low_2.setSliderStyle(Slider::LinearHorizontal);
		wEq_Gain_Low_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Gain_Low_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Gain_Low_2.setTextValueSuffix(EqGainLowTextValueSuffix);
		wEq_Gain_Low_2.setColour(Slider::backgroundColourId, Colours::white);
		wEq_Gain_Low_2.addListener(this);
		addAndMakeVisible(wEq_Gain_Low_2);
		//FreqLow
		wEq_Freq_Low_2.setRange(EqFreqLowMin, EqFreqLowMax, EqFreqLowPasso);
		wEq_Freq_Low_2.setValue(EqFreqLowIni);
		wEq_Freq_Low_2.setDoubleClickReturnValue(true, EqFreqLowReset);
		wEq_Freq_Low_2.setSliderStyle(Slider::LinearHorizontal);
		wEq_Freq_Low_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Freq_Low_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Freq_Low_2.setTextValueSuffix(EqFreqTextValueSuffix);
		wEq_Freq_Low_2.addListener(this);
		addAndMakeVisible(wEq_Freq_Low_2);

		//Enable COMPRESSOR
		addAndMakeVisible(wCompOnOff_2);
		wCompOnOff_2.toBack();
		wCompOnOff_2.setToggleState(false, false);
		wCompOnOff_2.setColour(ToggleButton::tickColourId, Colours::black);
		wCompOnOff_2.setColour(ToggleButton::tickDisabledColourId, Colours::black);
		wCompOnOff_2.setButtonText(CompONTextValueSuffix);
		wCompOnOff_2.setColour(ToggleButton::textColourId, Colours::black);
		wCompOnOff_2.addListener(this);

		//CompThreshold
		wCompThreshold_2.setRange(CompThresholdMin, CompThresholdMax, CompThresholdPasso);
		wCompThreshold_2.setValue(CompThresholdIni);
		wCompThreshold_2.setDoubleClickReturnValue(true, CompThresholdReset);
		wCompThreshold_2.setSliderStyle(Slider::LinearHorizontal);
		wCompThreshold_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompThreshold_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompThreshold_2.setTextValueSuffix(CompThresholdTextValueSuffix);
		wCompThreshold_2.addListener(this);
		addAndMakeVisible(wCompThreshold_2);
		//CompRatio
		wCompRatio_2.setRange(CompRatioMin, CompRatioMax, CompRatioPasso);
		wCompRatio_2.setValue(CompRatioIni);
		wCompRatio_2.setDoubleClickReturnValue(true, CompRatioReset);
		wCompRatio_2.setSliderStyle(Slider::LinearHorizontal);
		wCompRatio_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompRatio_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompRatio_2.setTextValueSuffix(CompRatioTextValueSuffix);
		wCompRatio_2.addListener(this);
		addAndMakeVisible(wCompRatio_2);
		//CompAttack
		wCompAttack_2.setRange(CompAttackMin, CompAttackMax, CompAttackPasso);
		wCompAttack_2.setValue(CompAttackIni);
		wCompAttack_2.setDoubleClickReturnValue(true, CompAttackReset);
		wCompAttack_2.setSliderStyle(Slider::LinearHorizontal);
		wCompAttack_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompAttack_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompAttack_2.setTextValueSuffix(CompAttackTextValueSuffix);
		wCompAttack_2.addListener(this);
		addAndMakeVisible(wCompAttack_2);
		//CompRelease
		wCompRelease_2.setRange(CompReleaseMin, CompReleaseMax, CompReleasePasso);
		wCompRelease_2.setValue(CompReleaseIni);
		wCompRelease_2.setDoubleClickReturnValue(true, CompReleaseReset);
		wCompRelease_2.setSliderStyle(Slider::LinearHorizontal);
		wCompRelease_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompRelease_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompRelease_2.setTextValueSuffix(CompReleaseTextValueSuffix);
		wCompRelease_2.addListener(this);
		addAndMakeVisible(wCompRelease_2);
		//CompKnee
		wCompKnee_2.setRange(CompKneeMin, CompKneeMax, CompKneePasso);
		wCompKnee_2.setValue(CompKneeIni);
		wCompKnee_2.setDoubleClickReturnValue(true, CompKneeReset);
		wCompKnee_2.setSliderStyle(Slider::LinearHorizontal);
		wCompKnee_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompKnee_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompKnee_2.setTextValueSuffix(CompKneeTextValueSuffix);
		wCompKnee_2.addListener(this);
		addAndMakeVisible(wCompKnee_2);
		//CompMakeUp
		wCompMakeUp_2.setRange(CompMakeUpMin, CompMakeUpMax, CompMakeUpPasso);
		wCompMakeUp_2.setValue(CompMakeUpIni);
		wCompMakeUp_2.setDoubleClickReturnValue(true, CompMakeUpReset);
		wCompMakeUp_2.setSliderStyle(Slider::LinearHorizontal);
		wCompMakeUp_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompMakeUp_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompMakeUp_2.setTextValueSuffix(CompMakeUpTextValueSuffix);
		wCompMakeUp_2.addListener(this);
		addAndMakeVisible(wCompMakeUp_2);
		//AuxilarReverb
		wAuxReverb_2.setRange(ReverbMin, ReverbMax, ReverbPasso);
		wAuxReverb_2.setValue(ReverbIni);
		wAuxReverb_2.setDoubleClickReturnValue(true, ReverbReset);
		wAuxReverb_2.setSkewFactorFromMidPoint(-24);
		wAuxReverb_2.setSliderStyle(Slider::LinearHorizontal);
		wAuxReverb_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wAuxReverb_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wAuxReverb_2.setTextValueSuffix(ReverbTextValueSuffix);
		wAuxReverb_2.addListener(this);
		addAndMakeVisible(wAuxReverb_2);
		//AuxilarDelay
		wAuxDelay_2.setRange(DelayMin, DelayMax, DelayPasso);
		wAuxDelay_2.setValue(DelayIni);
		wAuxDelay_2.setDoubleClickReturnValue(true, DelayReset);
		wAuxDelay_2.setSkewFactorFromMidPoint(-24);
		wAuxDelay_2.setSliderStyle(Slider::LinearHorizontal);
		wAuxDelay_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wAuxDelay_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wAuxDelay_2.setTextValueSuffix(DelayTextValueSuffix);
		wAuxDelay_2.addListener(this);
		addAndMakeVisible(wAuxDelay_2);
		//Pan
		wPan_2.setRange(PanMin, PanMax, PanPasso);
		wPan_2.setValue(PanIni);
		wPan_2.setDoubleClickReturnValue(true, PanReset);
		wPan_2.setSliderStyle(Slider::LinearHorizontal);
		wPan_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wPan_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wPan_2.setTextValueSuffix(PanTextValueSuffix);
		wPan_2.addListener(this);
		addAndMakeVisible(wPan_2);
		//Level
		wLevel_2.setRange(LevelMin, LevelMax, LevelPasso);
		wLevel_2.setValue(LevelIni);
		wLevel_2.setDoubleClickReturnValue(true, LevelReset);
		wLevel_2.setSkewFactorFromMidPoint(-6);
		wLevel_2.setSliderStyle(Slider::LinearVertical);
		wLevel_2.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wLevel_2.setColour(Slider::textBoxTextColourId, Colours::black);
		wLevel_2.setTextValueSuffix(LevelTextValueSuffix);
		wLevel_2.addListener(this);
		addAndMakeVisible(wLevel_2);

		addAndMakeVisible(wMute_2);
		wMute_2.toBack();
		wMute_2.setToggleState(false, false);
		wMute_2.setColour(ToggleButton::tickColourId, Colours::black);
		wMute_2.setColour(ToggleButton::tickDisabledColourId, Colours::black);
		wMute_2.setButtonText(MuteTextValueSuffix);
		wMute_2.setColour(ToggleButton::textColourId, Colours::black);
		wMute_2.addListener(this);

		//==========================================
		//             GRAFICOS CANAL 3
		//==========================================

		//Label
		labelCanal3.setText(LabelCanal3setText, dontSendNotification);
		labelCanal3.setColour(Label::textColourId, Colours::black);
		labelCanal3.setColour(Label::backgroundColourId, Colours::whitesmoke);
		labelCanal3.setJustificationType(Justification::centred);
		addAndMakeVisible(labelCanal3);

		//Ganho
		wGain_3.setRange(GainMin, GainMax, GainPasso);
		wGain_3.setValue(GainIni);
		wGain_3.setDoubleClickReturnValue(true, GainReset);
		wGain_3.setSliderStyle(Slider::LinearHorizontal);
		wGain_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wGain_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wGain_3.setTextValueSuffix(GainTextValueSuffix);
		wGain_3.addListener(this);
		addAndMakeVisible(wGain_3);

		//Enable EQ
		addAndMakeVisible(wEq_OnOff_3);
		wEq_OnOff_3.toBack();
		wEq_OnOff_3.setToggleState(false, false);
		wEq_OnOff_3.setColour(ToggleButton::tickColourId, Colours::black);
		wEq_OnOff_3.setColour(ToggleButton::tickDisabledColourId, Colours::black);
		wEq_OnOff_3.setButtonText(EQONTextValueSuffix);
		wEq_OnOff_3.setColour(ToggleButton::textColourId, Colours::black);
		wEq_OnOff_3.addListener(this);

		//GanhoHi
		wEq_Gain_Hi_3.setRange(EqGainMin, EqGainMax, EqGainPasso);
		wEq_Gain_Hi_3.setValue(EqGainIni);
		wEq_Gain_Hi_3.setDoubleClickReturnValue(true, EqGainReset);
		wEq_Gain_Hi_3.setSliderStyle(Slider::LinearHorizontal);
		wEq_Gain_Hi_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Gain_Hi_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Gain_Hi_3.setTextValueSuffix(EqGainHiTextValueSuffix);
		wEq_Gain_Hi_3.setColour(Slider::backgroundColourId, Colours::white);
		wEq_Gain_Hi_3.addListener(this);
		addAndMakeVisible(wEq_Gain_Hi_3);
		//FreqHi
		wEq_Freq_Hi_3.setRange(EqFreqHiMin, EqFreqHiMax, EqFreqHiPasso);
		wEq_Freq_Hi_3.setValue(EqFreqHiIni);
		wEq_Freq_Hi_3.setDoubleClickReturnValue(true, EqFreqHiReset);
		wEq_Freq_Hi_3.setSliderStyle(Slider::LinearHorizontal);
		wEq_Freq_Hi_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Freq_Hi_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Freq_Hi_3.setTextValueSuffix(EqFreqTextValueSuffix);
		wEq_Freq_Hi_3.addListener(this);
		addAndMakeVisible(wEq_Freq_Hi_3);
		//GainMidHi
		wEq_Gain_MidHi_3.setRange(EqGainMin, EqGainMax, EqGainPasso);
		wEq_Gain_MidHi_3.setValue(EqGainIni);
		wEq_Gain_MidHi_3.setDoubleClickReturnValue(true, EqGainReset);
		wEq_Gain_MidHi_3.setSliderStyle(Slider::LinearHorizontal);
		wEq_Gain_MidHi_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Gain_MidHi_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Gain_MidHi_3.setTextValueSuffix(EqGainMidHiTextValueSuffix);
		wEq_Gain_MidHi_3.setColour(Slider::backgroundColourId, Colours::white);
		wEq_Gain_MidHi_3.addListener(this);
		addAndMakeVisible(wEq_Gain_MidHi_3);
		//FreqMidHi
		wEq_Freq_MidHi_3.setRange(EqFreqMidHiMin, EqFreqMidHiMax, EqFreqMidHiPasso);
		wEq_Freq_MidHi_3.setValue(EqFreqMidHiIni);
		wEq_Freq_MidHi_3.setDoubleClickReturnValue(true, EqFreqMidHiReset);
		wEq_Freq_MidHi_3.setSliderStyle(Slider::LinearHorizontal);
		wEq_Freq_MidHi_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Freq_MidHi_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Freq_MidHi_3.setTextValueSuffix(EqFreqTextValueSuffix);
		wEq_Freq_MidHi_3.addListener(this);
		addAndMakeVisible(wEq_Freq_MidHi_3);
		//QMidHi
		wEq_Q_MidHi_3.setRange(EqQMin, EqQMax, EqQPasso);
		wEq_Q_MidHi_3.setValue(EqQIni);
		wEq_Q_MidHi_3.setDoubleClickReturnValue(true, EqQReset);
		wEq_Q_MidHi_3.setSliderStyle(Slider::LinearHorizontal);
		wEq_Q_MidHi_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Q_MidHi_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Q_MidHi_3.setTextValueSuffix(EqQTextValueSuffix);
		wEq_Q_MidHi_3.addListener(this);
		addAndMakeVisible(wEq_Q_MidHi_3);
		//GainMidLow
		wEq_Gain_MidLow_3.setRange(EqGainMin, EqGainMax, EqGainPasso);
		wEq_Gain_MidLow_3.setValue(EqGainIni);
		wEq_Gain_MidLow_3.setDoubleClickReturnValue(true, EqGainReset);
		wEq_Gain_MidLow_3.setSliderStyle(Slider::LinearHorizontal);
		wEq_Gain_MidLow_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Gain_MidLow_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Gain_MidLow_3.setTextValueSuffix(EqGainMidLowTextValueSuffix);
		wEq_Gain_MidLow_3.setColour(Slider::backgroundColourId, Colours::white);
		wEq_Gain_MidLow_3.addListener(this);
		addAndMakeVisible(wEq_Gain_MidLow_3);
		//FreqMidLow
		wEq_Freq_MidLow_3.setRange(EqFreqMidLowMin, EqFreqMidLowMax, EqFreqMidLowPasso);
		wEq_Freq_MidLow_3.setValue(EqFreqMidLowIni);
		wEq_Freq_MidLow_3.setDoubleClickReturnValue(true, EqFreqMidLowReset);
		wEq_Freq_MidLow_3.setSliderStyle(Slider::LinearHorizontal);
		wEq_Freq_MidLow_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Freq_MidLow_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Freq_MidLow_3.setTextValueSuffix(EqFreqTextValueSuffix);
		wEq_Freq_MidLow_3.addListener(this);
		addAndMakeVisible(wEq_Freq_MidLow_3);
		//QMidLow
		wEq_Q_MidLow_3.setRange(EqQMin, EqQMax, EqQPasso);
		wEq_Q_MidLow_3.setValue(EqQIni);
		wEq_Q_MidLow_3.setDoubleClickReturnValue(true, EqQReset);
		wEq_Q_MidLow_3.setSliderStyle(Slider::LinearHorizontal);
		wEq_Q_MidLow_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Q_MidLow_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Q_MidLow_3.setTextValueSuffix(EqQTextValueSuffix);
		wEq_Q_MidLow_3.addListener(this);
		addAndMakeVisible(wEq_Q_MidLow_3);
		//
		//GanhoLow
		wEq_Gain_Low_3.setRange(EqGainMin, EqGainMax, EqGainPasso);
		wEq_Gain_Low_3.setValue(EqGainIni);
		wEq_Gain_Low_3.setDoubleClickReturnValue(true, EqGainReset);
		wEq_Gain_Low_3.setSliderStyle(Slider::LinearHorizontal);
		wEq_Gain_Low_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Gain_Low_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Gain_Low_3.setTextValueSuffix(EqGainLowTextValueSuffix);
		wEq_Gain_Low_3.setColour(Slider::backgroundColourId, Colours::white);
		wEq_Gain_Low_3.addListener(this);
		addAndMakeVisible(wEq_Gain_Low_3);
		//FreqLow
		wEq_Freq_Low_3.setRange(EqFreqLowMin, EqFreqLowMax, EqFreqLowPasso);
		wEq_Freq_Low_3.setValue(EqFreqLowIni);
		wEq_Freq_Low_3.setDoubleClickReturnValue(true, EqFreqLowReset);
		wEq_Freq_Low_3.setSliderStyle(Slider::LinearHorizontal);
		wEq_Freq_Low_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Freq_Low_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Freq_Low_3.setTextValueSuffix(EqFreqTextValueSuffix);
		wEq_Freq_Low_3.addListener(this);
		addAndMakeVisible(wEq_Freq_Low_3);

		//Enable COMPRESSOR
		addAndMakeVisible(wCompOnOff_3);
		wCompOnOff_3.toBack();
		wCompOnOff_3.setToggleState(false, false);
		wCompOnOff_3.setColour(ToggleButton::tickColourId, Colours::black);
		wCompOnOff_3.setColour(ToggleButton::tickDisabledColourId, Colours::black);
		wCompOnOff_3.setButtonText(CompONTextValueSuffix);
		wCompOnOff_3.setColour(ToggleButton::textColourId, Colours::black);
		wCompOnOff_3.addListener(this);

		//CompThreshold
		wCompThreshold_3.setRange(CompThresholdMin, CompThresholdMax, CompThresholdPasso);
		wCompThreshold_3.setValue(CompThresholdIni);
		wCompThreshold_3.setDoubleClickReturnValue(true, CompThresholdReset);
		wCompThreshold_3.setSliderStyle(Slider::LinearHorizontal);
		wCompThreshold_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompThreshold_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompThreshold_3.setTextValueSuffix(CompThresholdTextValueSuffix);
		wCompThreshold_3.addListener(this);
		addAndMakeVisible(wCompThreshold_3);
		//CompRatio
		wCompRatio_3.setRange(CompRatioMin, CompRatioMax, CompRatioPasso);
		wCompRatio_3.setValue(CompRatioIni);
		wCompRatio_3.setDoubleClickReturnValue(true, CompRatioReset);
		wCompRatio_3.setSliderStyle(Slider::LinearHorizontal);
		wCompRatio_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompRatio_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompRatio_3.setTextValueSuffix(CompRatioTextValueSuffix);
		wCompRatio_3.addListener(this);
		addAndMakeVisible(wCompRatio_3);
		//CompAttack
		wCompAttack_3.setRange(CompAttackMin, CompAttackMax, CompAttackPasso);
		wCompAttack_3.setValue(CompAttackIni);
		wCompAttack_3.setDoubleClickReturnValue(true, CompAttackReset);
		wCompAttack_3.setSliderStyle(Slider::LinearHorizontal);
		wCompAttack_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompAttack_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompAttack_3.setTextValueSuffix(CompAttackTextValueSuffix);
		wCompAttack_3.addListener(this);
		addAndMakeVisible(wCompAttack_3);
		//CompRelease
		wCompRelease_3.setRange(CompReleaseMin, CompReleaseMax, CompReleasePasso);
		wCompRelease_3.setValue(CompReleaseIni);
		wCompRelease_3.setDoubleClickReturnValue(true, CompReleaseReset);
		wCompRelease_3.setSliderStyle(Slider::LinearHorizontal);
		wCompRelease_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompRelease_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompRelease_3.setTextValueSuffix(CompReleaseTextValueSuffix);
		wCompRelease_3.addListener(this);
		addAndMakeVisible(wCompRelease_3);
		//CompKnee
		wCompKnee_3.setRange(CompKneeMin, CompKneeMax, CompKneePasso);
		wCompKnee_3.setValue(CompKneeIni);
		wCompKnee_3.setDoubleClickReturnValue(true, CompKneeReset);
		wCompKnee_3.setSliderStyle(Slider::LinearHorizontal);
		wCompKnee_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompKnee_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompKnee_3.setTextValueSuffix(CompKneeTextValueSuffix);
		wCompKnee_3.addListener(this);
		addAndMakeVisible(wCompKnee_3);
		//CompMakeUp
		wCompMakeUp_3.setRange(CompMakeUpMin, CompMakeUpMax, CompMakeUpPasso);
		wCompMakeUp_3.setValue(CompMakeUpIni);
		wCompMakeUp_3.setDoubleClickReturnValue(true, CompMakeUpReset);
		wCompMakeUp_3.setSliderStyle(Slider::LinearHorizontal);
		wCompMakeUp_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompMakeUp_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompMakeUp_3.setTextValueSuffix(CompMakeUpTextValueSuffix);
		wCompMakeUp_3.addListener(this);
		addAndMakeVisible(wCompMakeUp_3);
		//AuxilarReverb
		wAuxReverb_3.setRange(ReverbMin, ReverbMax, ReverbPasso);
		wAuxReverb_3.setValue(ReverbIni);
		wAuxReverb_3.setDoubleClickReturnValue(true, ReverbReset);
		wAuxReverb_3.setSkewFactorFromMidPoint(-24);
		wAuxReverb_3.setSliderStyle(Slider::LinearHorizontal);
		wAuxReverb_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wAuxReverb_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wAuxReverb_3.setTextValueSuffix(ReverbTextValueSuffix);
		wAuxReverb_3.addListener(this);
		addAndMakeVisible(wAuxReverb_3);
		//AuxilarDelay
		wAuxDelay_3.setRange(DelayMin, DelayMax, DelayPasso);
		wAuxDelay_3.setValue(DelayIni);
		wAuxDelay_3.setDoubleClickReturnValue(true, DelayReset);
		wAuxDelay_3.setSkewFactorFromMidPoint(-24);
		wAuxDelay_3.setSliderStyle(Slider::LinearHorizontal);
		wAuxDelay_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wAuxDelay_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wAuxDelay_3.setTextValueSuffix(DelayTextValueSuffix);
		wAuxDelay_3.addListener(this);
		addAndMakeVisible(wAuxDelay_3);
		//Pan
		wPan_3.setRange(PanMin, PanMax, PanPasso);
		wPan_3.setValue(PanIni);
		wPan_3.setDoubleClickReturnValue(true, PanReset);
		wPan_3.setSliderStyle(Slider::LinearHorizontal);
		wPan_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wPan_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wPan_3.setTextValueSuffix(PanTextValueSuffix);
		wPan_3.addListener(this);
		addAndMakeVisible(wPan_3);
		//Level
		wLevel_3.setRange(LevelMin, LevelMax, LevelPasso);
		wLevel_3.setValue(LevelIni);
		wLevel_3.setDoubleClickReturnValue(true, LevelReset);
		wLevel_3.setSkewFactorFromMidPoint(-6);
		wLevel_3.setSliderStyle(Slider::LinearVertical);
		wLevel_3.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wLevel_3.setColour(Slider::textBoxTextColourId, Colours::black);
		wLevel_3.setTextValueSuffix(LevelTextValueSuffix);
		wLevel_3.addListener(this);
		addAndMakeVisible(wLevel_3);
		//MUTE
		addAndMakeVisible(wMute_3);
		wMute_3.toBack();
		wMute_3.setToggleState(false, false);
		wMute_3.setColour(ToggleButton::tickColourId, Colours::black);
		wMute_3.setColour(ToggleButton::tickDisabledColourId, Colours::black);
		wMute_3.setButtonText(MuteTextValueSuffix);
		wMute_3.setColour(ToggleButton::textColourId, Colours::black);
		wMute_3.addListener(this);

		//==========================================
		//             GRAFICOS CANAL 4
		//==========================================

		//Label
		labelCanal4.setText(LabelCanal4setText, dontSendNotification);
		labelCanal4.setColour(Label::textColourId, Colours::black);
		labelCanal4.setColour(Label::backgroundColourId, Colours::whitesmoke);
		labelCanal4.setJustificationType(Justification::centred);
		addAndMakeVisible(labelCanal4);

		//Ganho
		wGain_4.setRange(GainMin, GainMax, GainPasso);
		wGain_4.setValue(GainIni);
		wGain_4.setDoubleClickReturnValue(true, GainReset);
		wGain_4.setSliderStyle(Slider::LinearHorizontal);
		wGain_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wGain_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wGain_4.setTextValueSuffix(GainTextValueSuffix);
		wGain_4.addListener(this);
		addAndMakeVisible(wGain_4);

		//Enable EQ
		addAndMakeVisible(wEq_OnOff_4);
		wEq_OnOff_4.toBack();
		wEq_OnOff_4.setToggleState(false, false);
		wEq_OnOff_4.setColour(ToggleButton::tickColourId, Colours::black);
		wEq_OnOff_4.setColour(ToggleButton::tickDisabledColourId, Colours::black);
		wEq_OnOff_4.setButtonText(EQONTextValueSuffix);
		wEq_OnOff_4.setColour(ToggleButton::textColourId, Colours::black);
		wEq_OnOff_4.addListener(this);

		//GanhoHi
		wEq_Gain_Hi_4.setRange(EqGainMin, EqGainMax, EqGainPasso);
		wEq_Gain_Hi_4.setValue(EqGainIni);
		wEq_Gain_Hi_4.setDoubleClickReturnValue(true, EqGainReset);
		wEq_Gain_Hi_4.setSliderStyle(Slider::LinearHorizontal);
		wEq_Gain_Hi_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Gain_Hi_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Gain_Hi_4.setTextValueSuffix(EqGainHiTextValueSuffix);
		wEq_Gain_Hi_4.setColour(Slider::backgroundColourId, Colours::white);
		wEq_Gain_Hi_4.addListener(this);
		addAndMakeVisible(wEq_Gain_Hi_4);
		//FreqHi
		wEq_Freq_Hi_4.setRange(EqFreqHiMin, EqFreqHiMax, EqFreqHiPasso);
		wEq_Freq_Hi_4.setValue(EqFreqHiIni);
		wEq_Freq_Hi_4.setDoubleClickReturnValue(true, EqFreqHiReset);
		wEq_Freq_Hi_4.setSliderStyle(Slider::LinearHorizontal);
		wEq_Freq_Hi_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Freq_Hi_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Freq_Hi_4.setTextValueSuffix(EqFreqTextValueSuffix);
		wEq_Freq_Hi_4.addListener(this);
		addAndMakeVisible(wEq_Freq_Hi_4);
		//GainMidHi
		wEq_Gain_MidHi_4.setRange(EqGainMin, EqGainMax, EqGainPasso);
		wEq_Gain_MidHi_4.setValue(EqGainIni);
		wEq_Gain_MidHi_4.setDoubleClickReturnValue(true, EqGainReset);
		wEq_Gain_MidHi_4.setSliderStyle(Slider::LinearHorizontal);
		wEq_Gain_MidHi_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Gain_MidHi_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Gain_MidHi_4.setTextValueSuffix(EqGainMidHiTextValueSuffix);
		wEq_Gain_MidHi_4.setColour(Slider::backgroundColourId, Colours::white);
		wEq_Gain_MidHi_4.addListener(this);
		addAndMakeVisible(wEq_Gain_MidHi_4);
		//FreqMidHi
		wEq_Freq_MidHi_4.setRange(EqFreqMidHiMin, EqFreqMidHiMax, EqFreqMidHiPasso);
		wEq_Freq_MidHi_4.setValue(EqFreqMidHiIni);
		wEq_Freq_MidHi_4.setDoubleClickReturnValue(true, EqFreqMidHiReset);
		wEq_Freq_MidHi_4.setSliderStyle(Slider::LinearHorizontal);
		wEq_Freq_MidHi_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Freq_MidHi_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Freq_MidHi_4.setTextValueSuffix(EqFreqTextValueSuffix);
		wEq_Freq_MidHi_4.addListener(this);
		addAndMakeVisible(wEq_Freq_MidHi_4);
		//QMidHi
		wEq_Q_MidHi_4.setRange(EqQMin, EqQMax, EqQPasso);
		wEq_Q_MidHi_4.setValue(EqQIni);
		wEq_Q_MidHi_4.setDoubleClickReturnValue(true, EqQReset);
		wEq_Q_MidHi_4.setSliderStyle(Slider::LinearHorizontal);
		wEq_Q_MidHi_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Q_MidHi_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Q_MidHi_4.setTextValueSuffix(EqQTextValueSuffix);
		wEq_Q_MidHi_4.addListener(this);
		addAndMakeVisible(wEq_Q_MidHi_4);
		//GainMidLow
		wEq_Gain_MidLow_4.setRange(EqGainMin, EqGainMax, EqGainPasso);
		wEq_Gain_MidLow_4.setValue(EqGainIni);
		wEq_Gain_MidLow_4.setDoubleClickReturnValue(true, EqGainReset);
		wEq_Gain_MidLow_4.setSliderStyle(Slider::LinearHorizontal);
		wEq_Gain_MidLow_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Gain_MidLow_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Gain_MidLow_4.setTextValueSuffix(EqGainMidLowTextValueSuffix);
		wEq_Gain_MidLow_4.setColour(Slider::backgroundColourId, Colours::white);
		wEq_Gain_MidLow_4.addListener(this);
		addAndMakeVisible(wEq_Gain_MidLow_4);
		//FreqMidLow
		wEq_Freq_MidLow_4.setRange(EqFreqMidLowMin, EqFreqMidLowMax, EqFreqMidLowPasso);
		wEq_Freq_MidLow_4.setValue(EqFreqMidLowIni);
		wEq_Freq_MidLow_4.setDoubleClickReturnValue(true, EqFreqMidLowReset);
		wEq_Freq_MidLow_4.setSliderStyle(Slider::LinearHorizontal);
		wEq_Freq_MidLow_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Freq_MidLow_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Freq_MidLow_4.setTextValueSuffix(EqFreqTextValueSuffix);
		wEq_Freq_MidLow_4.addListener(this);
		addAndMakeVisible(wEq_Freq_MidLow_4);
		//QMidLow
		wEq_Q_MidLow_4.setRange(EqQMin, EqQMax, EqQPasso);
		wEq_Q_MidLow_4.setValue(EqQIni);
		wEq_Q_MidLow_4.setDoubleClickReturnValue(true, EqQReset);
		wEq_Q_MidLow_4.setSliderStyle(Slider::LinearHorizontal);
		wEq_Q_MidLow_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Q_MidLow_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Q_MidLow_4.setTextValueSuffix(EqQTextValueSuffix);
		wEq_Q_MidLow_4.addListener(this);
		addAndMakeVisible(wEq_Q_MidLow_4);
		//GanhoLow
		wEq_Gain_Low_4.setRange(EqGainMin, EqGainMax, EqGainPasso);
		wEq_Gain_Low_4.setValue(EqGainIni);
		wEq_Gain_Low_4.setDoubleClickReturnValue(true, EqGainReset);
		wEq_Gain_Low_4.setSliderStyle(Slider::LinearHorizontal);
		wEq_Gain_Low_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Gain_Low_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Gain_Low_4.setTextValueSuffix(EqGainLowTextValueSuffix);
		wEq_Gain_Low_4.setColour(Slider::backgroundColourId, Colours::white);
		wEq_Gain_Low_4.addListener(this);
		addAndMakeVisible(wEq_Gain_Low_4);
		//FreqLow
		wEq_Freq_Low_4.setRange(EqFreqLowMin, EqFreqLowMax, EqFreqLowPasso);
		wEq_Freq_Low_4.setValue(EqFreqLowIni);
		wEq_Freq_Low_4.setDoubleClickReturnValue(true, EqFreqLowReset);
		wEq_Freq_Low_4.setSliderStyle(Slider::LinearHorizontal);
		wEq_Freq_Low_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wEq_Freq_Low_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wEq_Freq_Low_4.setTextValueSuffix(EqFreqTextValueSuffix);
		wEq_Freq_Low_4.addListener(this);
		addAndMakeVisible(wEq_Freq_Low_4);

		//Enable COMPRESSOR
		addAndMakeVisible(wCompOnOff_4);
		wCompOnOff_4.toBack();
		wCompOnOff_4.setToggleState(false, false);
		wCompOnOff_4.setColour(ToggleButton::tickColourId, Colours::black);
		wCompOnOff_4.setColour(ToggleButton::tickDisabledColourId, Colours::black);
		wCompOnOff_4.setButtonText(CompONTextValueSuffix);
		wCompOnOff_4.setColour(ToggleButton::textColourId, Colours::black);
		wCompOnOff_4.addListener(this);

		//CompThreshold
		wCompThreshold_4.setRange(CompThresholdMin, CompThresholdMax, CompThresholdPasso);
		wCompThreshold_4.setValue(CompThresholdIni);
		wCompThreshold_4.setDoubleClickReturnValue(true, CompThresholdReset);
		wCompThreshold_4.setSliderStyle(Slider::LinearHorizontal);
		wCompThreshold_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompThreshold_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompThreshold_4.setTextValueSuffix(CompThresholdTextValueSuffix);
		wCompThreshold_4.addListener(this);
		addAndMakeVisible(wCompThreshold_4);
		//CompRatio
		wCompRatio_4.setRange(CompRatioMin, CompRatioMax, CompRatioPasso);
		wCompRatio_4.setValue(CompRatioIni);
		wCompRatio_4.setDoubleClickReturnValue(true, CompRatioReset);
		wCompRatio_4.setSliderStyle(Slider::LinearHorizontal);
		wCompRatio_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompRatio_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompRatio_4.setTextValueSuffix(CompRatioTextValueSuffix);
		wCompRatio_4.addListener(this);
		addAndMakeVisible(wCompRatio_4);
		//CompAttack
		wCompAttack_4.setRange(CompAttackMin, CompAttackMax, CompAttackPasso);
		wCompAttack_4.setValue(CompAttackIni);
		wCompAttack_4.setDoubleClickReturnValue(true, CompAttackReset);
		wCompAttack_4.setSliderStyle(Slider::LinearHorizontal);
		wCompAttack_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompAttack_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompAttack_4.setTextValueSuffix(CompAttackTextValueSuffix);
		wCompAttack_4.addListener(this);
		addAndMakeVisible(wCompAttack_4);
		//CompRelease
		wCompRelease_4.setRange(CompReleaseMin, CompReleaseMax, CompReleasePasso);
		wCompRelease_4.setValue(CompReleaseIni);
		wCompRelease_4.setDoubleClickReturnValue(true, CompReleaseReset);
		wCompRelease_4.setSliderStyle(Slider::LinearHorizontal);
		wCompRelease_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompRelease_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompRelease_4.setTextValueSuffix(CompReleaseTextValueSuffix);
		wCompRelease_4.addListener(this);
		addAndMakeVisible(wCompRelease_4);
		//CompKnee
		wCompKnee_4.setRange(CompKneeMin, CompKneeMax, CompKneePasso);
		wCompKnee_4.setValue(CompKneeIni);
		wCompKnee_4.setDoubleClickReturnValue(true, CompKneeReset);
		wCompKnee_4.setSliderStyle(Slider::LinearHorizontal);
		wCompKnee_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompKnee_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompKnee_4.setTextValueSuffix(CompKneeTextValueSuffix);
		wCompKnee_4.addListener(this);
		addAndMakeVisible(wCompKnee_4);
		//CompMakeUp
		wCompMakeUp_4.setRange(CompMakeUpMin, CompMakeUpMax, CompMakeUpPasso);
		wCompMakeUp_4.setValue(CompMakeUpIni);
		wCompMakeUp_4.setDoubleClickReturnValue(true, CompMakeUpReset);
		wCompMakeUp_4.setSliderStyle(Slider::LinearHorizontal);
		wCompMakeUp_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wCompMakeUp_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wCompMakeUp_4.setTextValueSuffix(CompMakeUpTextValueSuffix);
		wCompMakeUp_4.addListener(this);
		addAndMakeVisible(wCompMakeUp_4);
		//AuxilarReverb
		wAuxReverb_4.setRange(ReverbMin, ReverbMax, ReverbPasso);
		wAuxReverb_4.setValue(ReverbIni);
		wAuxReverb_4.setDoubleClickReturnValue(true, ReverbReset);
		wAuxReverb_4.setSkewFactorFromMidPoint(-24);
		wAuxReverb_4.setSliderStyle(Slider::LinearHorizontal);
		wAuxReverb_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wAuxReverb_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wAuxReverb_4.setTextValueSuffix(ReverbTextValueSuffix);
		wAuxReverb_4.addListener(this);
		addAndMakeVisible(wAuxReverb_4);
		//AuxilarDelay
		wAuxDelay_4.setRange(DelayMin, DelayMax, DelayPasso);
		wAuxDelay_4.setValue(DelayIni);
		wAuxDelay_4.setDoubleClickReturnValue(true, DelayReset);
		wAuxDelay_4.setSkewFactorFromMidPoint(-24);
		wAuxDelay_4.setSliderStyle(Slider::LinearHorizontal);
		wAuxDelay_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wAuxDelay_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wAuxDelay_4.setTextValueSuffix(DelayTextValueSuffix);
		wAuxDelay_4.addListener(this);
		addAndMakeVisible(wAuxDelay_4);
		//Pan
		wPan_4.setRange(PanMin, PanMax, PanPasso);
		wPan_4.setValue(PanIni);
		wPan_4.setDoubleClickReturnValue(true, PanReset);
		wPan_4.setSliderStyle(Slider::LinearHorizontal);
		wPan_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wPan_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wPan_4.setTextValueSuffix(PanTextValueSuffix);
		wPan_4.addListener(this);
		addAndMakeVisible(wPan_4);
		//Level
		wLevel_4.setRange(LevelMin, LevelMax, LevelPasso);
		wLevel_4.setValue(LevelIni);
		wLevel_4.setDoubleClickReturnValue(true, LevelReset);
		wLevel_4.setSkewFactorFromMidPoint(-6);
		wLevel_4.setSliderStyle(Slider::LinearVertical);
		wLevel_4.setTextBoxStyle(Slider::TextBoxBelow, false, CSwidth, 20);
		wLevel_4.setColour(Slider::textBoxTextColourId, Colours::black);
		wLevel_4.setTextValueSuffix(LevelTextValueSuffix);
		wLevel_4.addListener(this);
		addAndMakeVisible(wLevel_4);
		//MUTE
		addAndMakeVisible(wMute_4);
		wMute_4.toBack();
		wMute_4.setToggleState(false, false);
		wMute_4.setColour(ToggleButton::tickColourId, Colours::black);
		wMute_4.setColour(ToggleButton::tickDisabledColourId, Colours::black);
		wMute_4.setButtonText(MuteTextValueSuffix);
		wMute_4.setColour(ToggleButton::textColourId, Colours::black);
		wMute_4.addListener(this);

		//==========================================
		//             GRAFICOS REVERB
		//==========================================

		//Label
		labelReverb.setText(LabelReverbsetText, dontSendNotification);
		labelReverb.setColour(Label::textColourId, Colours::black);
		labelReverb.setColour(Label::backgroundColourId, Colours::whitesmoke);
		labelReverb.setJustificationType(Justification::centred);
		addAndMakeVisible(labelReverb);

		//decay
		wReverbDecay.setRange(ReverbDecayMin, ReverbDecayMax, ReverbDecayPasso);
		wReverbDecay.setValue(ReverbDecayIni);
		wReverbDecay.setDoubleClickReturnValue(true, ReverbDecayReset);
		wReverbDecay.setSkewFactorFromMidPoint(0.9);
		wReverbDecay.setSliderStyle(Slider::LinearHorizontal);
		wReverbDecay.setTextBoxStyle(Slider::TextBoxBelow, false, 200, 20);
		wReverbDecay.setColour(Slider::textBoxTextColourId, Colours::black);
		wReverbDecay.setTextValueSuffix(ReverbDecayTextValueSuffix);
		wReverbDecay.addListener(this);
		addAndMakeVisible(wReverbDecay);

		//density
		wReverbDensity.setRange(ReverbDensityMin, ReverbDensityMax, ReverbDensityPasso);
		wReverbDensity.setValue(ReverbDensityIni);
		wReverbDensity.setDoubleClickReturnValue(true, ReverbDensityReset);
		wReverbDensity.setSliderStyle(Slider::LinearHorizontal);
		wReverbDensity.setTextBoxStyle(Slider::TextBoxBelow, false, 200, 20);
		wReverbDensity.setColour(Slider::textBoxTextColourId, Colours::black);
		wReverbDensity.setTextValueSuffix(ReverbDensityTextValueSuffix);
		wReverbDensity.addListener(this);
		addAndMakeVisible(wReverbDensity);

		addAndMakeVisible(wReverbOnOff);
		wReverbOnOff.toBack();
		wReverbOnOff.setToggleState(false, false);
		wReverbOnOff.setColour(ToggleButton::tickColourId, Colours::black);
		wReverbOnOff.setColour(ToggleButton::tickDisabledColourId, Colours::black);
		wReverbOnOff.setButtonText("Reverb On/Off");
		wReverbOnOff.setColour(ToggleButton::textColourId, Colours::black);
		wReverbOnOff.addListener(this);

		//==========================================
		//             GRAFICOS DELAY
		//==========================================

		//Label
		labelDelay.setText(LabelDelaysetText, dontSendNotification);
		labelDelay.setColour(Label::textColourId, Colours::black);
		labelDelay.setColour(Label::backgroundColourId, Colours::whitesmoke);
		labelDelay.setJustificationType(Justification::centred);
		addAndMakeVisible(labelDelay);


		//time
		wDelayTime.setRange(DelayFeedbackMin, DelayFeedbackMax, DelayFeedbackPasso);
		wDelayTime.setValue(DelayFeedbackIni);
		wDelayTime.setDoubleClickReturnValue(true, DelayFeedbackReset);
		wDelayTime.setSliderStyle(Slider::LinearHorizontal);
		wDelayTime.setTextBoxStyle(Slider::TextBoxBelow, false, 200, 20);
		wDelayTime.setColour(Slider::textBoxTextColourId, Colours::black);
		wDelayTime.setTextValueSuffix(DelayTimeTextValueSuffix);
		wDelayTime.addListener(this);
		addAndMakeVisible(wDelayTime);

		//feedback
		wDelayFeedback.setRange(DelayFeedbackMin, DelayFeedbackMax, DelayFeedbackPasso);
		wDelayFeedback.setValue(DelayFeedbackIni);
		wDelayFeedback.setDoubleClickReturnValue(true, DelayFeedbackReset);
		wDelayFeedback.setSliderStyle(Slider::LinearHorizontal);
		wDelayFeedback.setTextBoxStyle(Slider::TextBoxBelow, false, 200, 20);
		wDelayFeedback.setColour(Slider::textBoxTextColourId, Colours::black);
		wDelayFeedback.setTextValueSuffix(DelayFeedbackTextValueSuffix);
		wDelayFeedback.addListener(this);
		addAndMakeVisible(wDelayFeedback);

		addAndMakeVisible(wDelayOnOff);
		wDelayOnOff.toBack();
		wDelayOnOff.setToggleState(false, false);
		wDelayOnOff.setColour(ToggleButton::tickColourId, Colours::black);
		wDelayOnOff.setColour(ToggleButton::tickDisabledColourId, Colours::black);
		wDelayOnOff.setButtonText("Delay On/Off");
		wDelayOnOff.setColour(ToggleButton::textColourId, Colours::black);
		wDelayOnOff.addListener(this);


		//===========================================
		//             MASTER
		//===========================================

		//Label
		labelMaster.setText(LabelMastersetText, dontSendNotification);
		labelMaster.setColour(Label::textColourId, Colours::black);
		labelMaster.setColour(Label::backgroundColourId, Colours::whitesmoke);
		labelMaster.setJustificationType(Justification::centred);
		addAndMakeVisible(labelMaster);

		wMasterLevel.setRange(MasterLevelMin, MasterLevelMax, MasterLevelPasso);
		wMasterLevel.setValue(MasterLevelIni);
		wMasterLevel.setDoubleClickReturnValue(true, MasterLevelReset);
		wMasterLevel.setSkewFactorFromMidPoint(-6);
		wMasterLevel.setSliderStyle(Slider::LinearVertical);
		wMasterLevel.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
		wMasterLevel.setColour(Slider::textBoxTextColourId, Colours::black);
		wMasterLevel.setTextValueSuffix(MasterLevelTextValueSuffix);
		wMasterLevel.addListener(this);
		addAndMakeVisible(wMasterLevel);

		//PARAMETROS DO HARDWARE

		juce::AudioDeviceManager::AudioDeviceSetup result;
		deviceManager.getAudioDeviceSetup(result);
		result.bufferSize = TamanhoBuffer;
		result.sampleRate = setSampleRate;
		deviceManager.setAudioDeviceSetup(result, true);


		//SETA O TAMANHO DA JANELA PRINCIPAL
		setSize(1300, 680);

		//SETA A QUANTIDADE DE CANAIS DE ENTRADA E SAIDA
		setAudioChannels(4, 4);

	}

	~MainContentComponent()  // DESTRUTOR DA MainContentComponent
	{
		shutdownAudio();
	}


	void MainContentComponent::paint(Graphics &g)
	{
		g.fillAll(Colours::lightgrey); //plano de fundo

	}


	//=============================================================================================
	//							MANIPULA EVENTO DOS LISTENERS DOS BOTOES
	//=============================================================================================
	void buttonClicked(Button* button) override
	{
		//Equalizadores

		if (button == &wEq_OnOff_1)
		{
			ChannelStrip1.EqualizadorON = wEq_OnOff_1.getToggleState();
			if (ChannelStrip1.EqualizadorON)
			{
				calculaequalizadorshelving(ChannelStrip1);
				calculaequalizadorparametrico(ChannelStrip1);
			}
		}

		else if (button == &wEq_OnOff_2)
		{
			ChannelStrip2.EqualizadorON = wEq_OnOff_2.getToggleState();
			if (ChannelStrip2.EqualizadorON)
			{
				calculaequalizadorshelving(ChannelStrip2);
				calculaequalizadorparametrico(ChannelStrip2);
			}
		}
		else if (button == &wEq_OnOff_3)
		{
			ChannelStrip3.EqualizadorON = wEq_OnOff_3.getToggleState();
			if (ChannelStrip3.EqualizadorON)
			{
				calculaequalizadorshelving(ChannelStrip3);
				calculaequalizadorparametrico(ChannelStrip3);
			}
		}

		else if (button == &wEq_OnOff_4)
		{
			ChannelStrip4.EqualizadorON = wEq_OnOff_4.getToggleState();
			if (ChannelStrip4.EqualizadorON)
			{
				calculaequalizadorshelving(ChannelStrip4);
				calculaequalizadorparametrico(ChannelStrip4);
			}
		}

		// Compressores

		else if (button == &wCompOnOff_1)
		{
			if (wCompOnOff_1.getToggleState() == true)
			{
				ChannelStrip1.CompressorOn = true;
				ChannelStrip1.Gs0 = 0;
				ChannelStrip1.Gs1 = 0;
				calculacompressor(ChannelStrip1, wCompAttack_1, wCompRelease_1);
			}
			else
				ChannelStrip1.CompressorOn = false;
		}
		else if (button == &wCompOnOff_2)
		{
			if (wCompOnOff_2.getToggleState() == true)
			{
				ChannelStrip2.CompressorOn = true;
				ChannelStrip2.Gs0 = 0;
				ChannelStrip2.Gs1 = 0;
				calculacompressor(ChannelStrip2, wCompAttack_2, wCompRelease_2);
			}
			else
				ChannelStrip2.CompressorOn = false;
		}
		else if (button == &wCompOnOff_3)
		{
			if (wCompOnOff_3.getToggleState() == true)
			{
				ChannelStrip3.CompressorOn = true;
				ChannelStrip3.Gs0 = 0;
				ChannelStrip3.Gs1 = 0;
				calculacompressor(ChannelStrip3, wCompAttack_3, wCompRelease_3);
			}
			else
				ChannelStrip3.CompressorOn = false;
		}
		else if (button == &wCompOnOff_4)
		{
			if (wCompOnOff_4.getToggleState() == true)
			{
				ChannelStrip4.CompressorOn = true;
				ChannelStrip4.Gs0 = 0;
				ChannelStrip4.Gs1 = 0;
				calculacompressor(ChannelStrip4, wCompAttack_4, wCompRelease_4);
			}
			else
				ChannelStrip4.CompressorOn = false;
		}

		//Mutes

		else if (button == &wMute_1)
		{
			if (wMute_1.getToggleState())
				ChannelStrip1.Mute = 0;
			else
				ChannelStrip1.Mute = 1;
		}

		else if (button == &wMute_2)
		{
			if (wMute_2.getToggleState())
				ChannelStrip2.Mute = 0;
			else
				ChannelStrip2.Mute = 1;
		}

		else if (button == &wMute_3)
		{
			if (wMute_3.getToggleState())
				ChannelStrip3.Mute = 0;
			else
				ChannelStrip3.Mute = 1;
		}

		else if (button == &wMute_4)
		{
			if (wMute_4.getToggleState())
				ChannelStrip4.Mute = 0;
			else
				ChannelStrip4.Mute = 1;
		}

		// DELAY

		else if (button == &wDelayOnOff)
		{
			if (wDelayOnOff.getToggleState()) {
				delayBuffer.clear();
				Delay.DelayOn = true;
			}
			else {
				Delay.DelayOn = false;
				delayBuffer.clear();
			}
		}

		// REVERB

		else if (button == &wReverbOnOff)
		{
			if (wReverbOnOff.getToggleState()) {

				RReverb.ReverbOn = true;

				LBCF1.clear();
				LBCF2.clear();
				LBCF3.clear();
				LBCF4.clear();
				LBCF5.clear();
				LBCF6.clear();
				LBCF7.clear();
				LBCF8.clear();
				AP1.clear();
				AP2.clear();
				AP3.clear();
				AP4.clear();

			}
			else {
				RReverb.ReverbOn = false;

				LBCF1.clear();
				LBCF2.clear();
				LBCF3.clear();
				LBCF4.clear();
				LBCF5.clear();
				LBCF6.clear();
				LBCF7.clear();
				LBCF8.clear();
				AP1.clear();
				AP2.clear();
				AP3.clear();
				AP4.clear();

			}
		}

	}

	//=============================================================================================
	//							MANIPULA EVENTO DOS LISTENERS DOS SLIDERS
	//=============================================================================================

	void sliderValueChanged(Slider* slider) override
	{

		//  ------ LISTENERS DO CANAL 1 ------ //

		if (slider == &wGain_1)
			ChannelStrip1.Gain = pow(10, wGain_1.getValue() / 20);

		else if (slider == &wEq_Gain_Hi_1)
		{
			ChannelStrip1.Eq_Hi_Gain = wEq_Gain_Hi_1.getValue();
			calculaequalizadorshelving(ChannelStrip1);
		}
		else if (slider == &wEq_Freq_Hi_1)
		{
			ChannelStrip1.Eq_Hi_Freq = wEq_Freq_Hi_1.getValue();
			calculaequalizadorshelving(ChannelStrip1);
		}
		else if (slider == &wEq_Gain_MidHi_1)
		{
			ChannelStrip1.Eq_HiMid_Gain = wEq_Gain_MidHi_1.getValue();
			calculaequalizadorparametrico(ChannelStrip1);
		}
		else if (slider == &wEq_Freq_MidHi_1)
		{
			ChannelStrip1.Eq_HiMid_Freq = wEq_Freq_MidHi_1.getValue();
			calculaequalizadorparametrico(ChannelStrip1);
		}

		else if (slider == &wEq_Q_MidHi_1)
		{
			ChannelStrip1.Eq_HiMid_Q = wEq_Q_MidHi_1.getValue();
			calculaequalizadorparametrico(ChannelStrip1);
		}
		else if (slider == &wEq_Gain_MidLow_1)
		{
			ChannelStrip1.Eq_LowMid_Gain = wEq_Gain_MidLow_1.getValue();
			calculaequalizadorparametrico(ChannelStrip1);
		}
		else if (slider == &wEq_Freq_MidLow_1)
		{
			ChannelStrip1.Eq_LowMid_Freq = wEq_Freq_MidLow_1.getValue();
			calculaequalizadorparametrico(ChannelStrip1);
		}
		else if (slider == &wEq_Q_MidLow_1)
		{
			ChannelStrip1.Eq_LowMid_Q = wEq_Q_MidLow_1.getValue();
			calculaequalizadorparametrico(ChannelStrip1);
		}
		else if (slider == &wEq_Gain_Low_1)
		{
			ChannelStrip1.Eq_Low_Gain = wEq_Gain_Low_1.getValue();
			calculaequalizadorshelving(ChannelStrip1);
		}
		else if (slider == &wEq_Freq_Low_1)
		{
			ChannelStrip1.Eq_Low_Freq = wEq_Freq_Low_1.getValue();
			calculaequalizadorshelving(ChannelStrip1);
		}
		else if (slider == &wCompThreshold_1)
			ChannelStrip1.Comp_Threshold = wCompThreshold_1.getValue();

		else if (slider == &wCompRatio_1)
			ChannelStrip1.Comp_Ratio = wCompRatio_1.getValue();

		else if (slider == &wCompAttack_1)
			calculacompressor(ChannelStrip1, wCompAttack_1, wCompRelease_1);

		else if (slider == &wCompRelease_1)
			calculacompressor(ChannelStrip1, wCompAttack_1, wCompRelease_1);

		else if (slider == &wCompKnee_1)
			ChannelStrip1.Comp_KneeWidth = wCompKnee_1.getValue();

		else if (slider == &wCompMakeUp_1)
			ChannelStrip1.Comp_MakeUp = pow(10, wCompMakeUp_1.getValue() / 20);

		else if (slider == &wAuxReverb_1)
			ChannelStrip1.Aux_Reverb = pow(10, wAuxReverb_1.getValue() / 20);

		else if (slider == &wAuxDelay_1)
			ChannelStrip1.Aux_Delay = pow(10, wAuxDelay_1.getValue() / 20);

		else if (slider == &wPan_1)
		{
			double aux = wPan_1.getValue();
			ChannelStrip1.PanL = 1 - aux;
			ChannelStrip1.PanR = aux;
		}
		else if (slider == &wLevel_1)
			ChannelStrip1.Level = pow(10, wLevel_1.getValue() / 20);

		//  ------ LISTENERS DO CANAL 2 ------ //

		else if (slider == &wGain_2)
			ChannelStrip2.Gain = pow(10, wGain_2.getValue() / 20);

		else if (slider == &wEq_Gain_Hi_2)
		{
			ChannelStrip2.Eq_Hi_Gain = wEq_Gain_Hi_2.getValue();
			calculaequalizadorshelving(ChannelStrip2);
		}
		else if (slider == &wEq_Freq_Hi_2)
		{
			ChannelStrip2.Eq_Hi_Freq = wEq_Freq_Hi_2.getValue();
			calculaequalizadorshelving(ChannelStrip2);
		}
		else if (slider == &wEq_Gain_MidHi_2)
		{
			ChannelStrip2.Eq_HiMid_Gain = wEq_Gain_MidHi_2.getValue();
			calculaequalizadorparametrico(ChannelStrip2);
		}

		else if (slider == &wEq_Freq_MidHi_2)
		{
			ChannelStrip2.Eq_HiMid_Freq = wEq_Freq_MidHi_2.getValue();
			calculaequalizadorparametrico(ChannelStrip2);
		}
		else if (slider == &wEq_Q_MidHi_2)
		{
			ChannelStrip2.Eq_HiMid_Q = wEq_Q_MidHi_2.getValue();
			calculaequalizadorparametrico(ChannelStrip2);
		}
		else if (slider == &wEq_Gain_MidLow_2)
		{
			ChannelStrip2.Eq_LowMid_Gain = wEq_Gain_MidLow_2.getValue();
			calculaequalizadorparametrico(ChannelStrip2);
		}
		else if (slider == &wEq_Freq_MidLow_2)
		{
			ChannelStrip2.Eq_LowMid_Freq = wEq_Freq_MidLow_2.getValue();
			calculaequalizadorparametrico(ChannelStrip2);
		}

		else if (slider == &wEq_Q_MidLow_2)
		{
			ChannelStrip2.Eq_LowMid_Q = wEq_Q_MidLow_2.getValue();
			calculaequalizadorparametrico(ChannelStrip2);
		}

		else if (slider == &wEq_Gain_Low_2)
		{
			ChannelStrip2.Eq_Low_Gain = wEq_Gain_Low_2.getValue();
			calculaequalizadorshelving(ChannelStrip2);
		}
		else if (slider == &wEq_Freq_Low_2)
		{
			ChannelStrip2.Eq_Low_Freq = wEq_Freq_Low_2.getValue();
			calculaequalizadorshelving(ChannelStrip2);
		}
		else if (slider == &wCompThreshold_2)
			ChannelStrip2.Comp_Threshold = wCompThreshold_2.getValue();

		else if (slider == &wCompRatio_2)
			ChannelStrip2.Comp_Ratio = wCompRatio_2.getValue();

		else if (slider == &wCompAttack_2)
			calculacompressor(ChannelStrip2, wCompAttack_2, wCompRelease_2);

		else if (slider == &wCompRelease_2)
			calculacompressor(ChannelStrip2, wCompAttack_2, wCompRelease_2);

		else if (slider == &wCompKnee_2)
			ChannelStrip2.Comp_KneeWidth = wCompKnee_2.getValue();

		else if (slider == &wCompMakeUp_2)
			ChannelStrip2.Comp_MakeUp = pow(10, wCompMakeUp_2.getValue() / 20);

		else if (slider == &wAuxReverb_2)
			ChannelStrip2.Aux_Reverb = pow(10, wAuxReverb_2.getValue() / 20);

		else if (slider == &wAuxDelay_2)
			ChannelStrip2.Aux_Delay = pow(10, wAuxDelay_2.getValue() / 20);

		else if (slider == &wPan_2)
		{
			double aux = wPan_2.getValue();
			ChannelStrip2.PanL = 1 - aux;
			ChannelStrip2.PanR = aux;
		}
		else if (slider == &wLevel_2)
			ChannelStrip2.Level = pow(10, wLevel_2.getValue() / 20);

		//  ------ LISTENERS DO CANAL 3 ------ //

		else if (slider == &wGain_3)
			ChannelStrip3.Gain = pow(10, wGain_3.getValue() / 20);

		else if (slider == &wEq_Gain_Hi_3)
		{
			ChannelStrip3.Eq_Hi_Gain = wEq_Gain_Hi_3.getValue();
			calculaequalizadorshelving(ChannelStrip3);
		}
		else if (slider == &wEq_Freq_Hi_3)
		{
			ChannelStrip3.Eq_Hi_Freq = wEq_Freq_Hi_3.getValue();
			calculaequalizadorshelving(ChannelStrip3);
		}
		else if (slider == &wEq_Gain_MidHi_3)
		{
			ChannelStrip3.Eq_HiMid_Gain = wEq_Gain_MidHi_3.getValue();
			calculaequalizadorparametrico(ChannelStrip3);
		}
		else if (slider == &wEq_Freq_MidHi_3)
		{
			ChannelStrip3.Eq_HiMid_Freq = wEq_Freq_MidHi_3.getValue();
			calculaequalizadorparametrico(ChannelStrip3);
		}
		else if (slider == &wEq_Q_MidHi_3)
		{
			ChannelStrip3.Eq_HiMid_Q = wEq_Q_MidHi_3.getValue();
			calculaequalizadorparametrico(ChannelStrip3);
		}
		else if (slider == &wEq_Gain_MidLow_3)
		{
			ChannelStrip3.Eq_LowMid_Gain = wEq_Gain_MidLow_3.getValue();
			calculaequalizadorparametrico(ChannelStrip3);
		}
		else if (slider == &wEq_Freq_MidLow_3)
		{
			ChannelStrip3.Eq_LowMid_Freq = wEq_Freq_MidLow_3.getValue();
			calculaequalizadorparametrico(ChannelStrip2);
		}
		else if (slider == &wEq_Q_MidLow_3)
		{
			ChannelStrip3.Eq_LowMid_Q = wEq_Q_MidLow_3.getValue();
			calculaequalizadorparametrico(ChannelStrip2);
		}
		else if (slider == &wEq_Gain_Low_3)
		{
			ChannelStrip3.Eq_Low_Gain = wEq_Gain_Low_3.getValue();
			calculaequalizadorshelving(ChannelStrip3);
		}
		else if (slider == &wEq_Freq_Low_3)
		{
			ChannelStrip3.Eq_Low_Freq = wEq_Freq_Low_3.getValue();
			calculaequalizadorshelving(ChannelStrip3);
		}
		else if (slider == &wCompThreshold_3)
			ChannelStrip3.Comp_Threshold = wCompThreshold_3.getValue();

		else if (slider == &wCompRatio_3)
			ChannelStrip3.Comp_Ratio = wCompRatio_3.getValue();

		else if (slider == &wCompAttack_3)
			calculacompressor(ChannelStrip3, wCompAttack_3, wCompRelease_3);

		else if (slider == &wCompRelease_3)
			calculacompressor(ChannelStrip3, wCompAttack_3, wCompRelease_3);

		else if (slider == &wCompKnee_3)
			ChannelStrip3.Comp_KneeWidth = wCompKnee_3.getValue();

		else if (slider == &wCompMakeUp_3)
			ChannelStrip3.Comp_MakeUp = pow(10, wCompMakeUp_3.getValue() / 20);

		else if (slider == &wAuxReverb_3)
			ChannelStrip3.Aux_Reverb = pow(10, wAuxReverb_3.getValue() / 20);

		else if (slider == &wAuxDelay_3)
			ChannelStrip3.Aux_Delay = pow(10, wAuxDelay_3.getValue() / 20);

		else if (slider == &wPan_3)
		{
			double aux = wPan_3.getValue();
			ChannelStrip3.PanL = 1 - aux;
			ChannelStrip3.PanR = aux;
		}

		else if (slider == &wLevel_3)
			ChannelStrip3.Level = pow(10, wLevel_3.getValue() / 20);

		//  ------ LISTENERS DO CANAL 4 ------ //

		else if (slider == &wGain_4)
			ChannelStrip4.Gain = pow(10, wGain_4.getValue() / 20);

		else if (slider == &wEq_Gain_Hi_4)
		{
			ChannelStrip4.Eq_Hi_Gain = wEq_Gain_Hi_4.getValue();
			calculaequalizadorshelving(ChannelStrip4);
		}
		else if (slider == &wEq_Freq_Hi_4)
		{
			ChannelStrip4.Eq_Hi_Freq = wEq_Freq_Hi_4.getValue();
			calculaequalizadorshelving(ChannelStrip4);
		}
		else if (slider == &wEq_Gain_MidHi_4)
		{
			ChannelStrip4.Eq_HiMid_Gain = wEq_Gain_MidHi_4.getValue();
			calculaequalizadorparametrico(ChannelStrip4);
		}
		else if (slider == &wEq_Freq_MidHi_4)
		{
			ChannelStrip4.Eq_HiMid_Freq = wEq_Freq_MidHi_4.getValue();
			calculaequalizadorparametrico(ChannelStrip4);
		}
		else if (slider == &wEq_Q_MidHi_4)
		{
			ChannelStrip4.Eq_HiMid_Q = wEq_Q_MidHi_4.getValue();
			calculaequalizadorparametrico(ChannelStrip4);
		}
		else if (slider == &wEq_Gain_MidLow_4)
		{
			ChannelStrip4.Eq_LowMid_Gain = wEq_Gain_MidLow_4.getValue();
			calculaequalizadorparametrico(ChannelStrip4);
		}
		else if (slider == &wEq_Freq_MidLow_4)
		{
			ChannelStrip4.Eq_LowMid_Freq = wEq_Freq_MidLow_4.getValue();
			calculaequalizadorparametrico(ChannelStrip4);
		}
		else if (slider == &wEq_Q_MidLow_4)
		{
			ChannelStrip4.Eq_LowMid_Q = wEq_Q_MidLow_4.getValue();
			calculaequalizadorparametrico(ChannelStrip4);
		}
		else if (slider == &wEq_Gain_Low_4)
		{
			ChannelStrip4.Eq_Low_Gain = wEq_Gain_Low_4.getValue();
			calculaequalizadorshelving(ChannelStrip4);
		}
		else if (slider == &wEq_Freq_Low_4)
		{
			ChannelStrip4.Eq_Low_Freq = wEq_Freq_Low_4.getValue();
			calculaequalizadorshelving(ChannelStrip4);
		}
		else if (slider == &wCompThreshold_4)
			ChannelStrip4.Comp_Threshold = wCompThreshold_4.getValue();

		else if (slider == &wCompRatio_4)
			ChannelStrip4.Comp_Ratio = wCompRatio_4.getValue();

		else if (slider == &wCompAttack_4)
			calculacompressor(ChannelStrip4, wCompAttack_4, wCompRelease_4);

		else if (slider == &wCompRelease_4)
			calculacompressor(ChannelStrip4, wCompAttack_4, wCompRelease_4);

		else if (slider == &wCompKnee_4)
			ChannelStrip4.Comp_KneeWidth = wCompKnee_4.getValue();

		else if (slider == &wCompMakeUp_4)
			ChannelStrip4.Comp_MakeUp = pow(10, wCompMakeUp_4.getValue() / 20);

		else if (slider == &wAuxReverb_4)
			ChannelStrip4.Aux_Reverb = pow(10, wAuxReverb_4.getValue() / 20);

		else if (slider == &wAuxDelay_4)
			ChannelStrip4.Aux_Delay = pow(10, wAuxDelay_4.getValue() / 20);

		else if (slider == &wPan_4)
		{
			double aux = wPan_4.getValue();
			ChannelStrip4.PanL = 1 - aux;
			ChannelStrip4.PanR = aux;
		}

		else if (slider == &wLevel_4)
			ChannelStrip4.Level = pow(10, (double)wLevel_4.getValue() / 20);

		//  ------ LISTENERS DO REVERB------ //

		else if (slider == &wReverbDecay)
		{
			RReverb.Decay = (double)wReverbDecay.getValue();
		}

		else if (slider == &wReverbDensity)
			RReverb.Density = (double)wReverbDensity.getValue();

		//  ------ LISTENERS DO DELAY ------ //

		else if (slider == &wDelayTime)
		{
			Delay.Time = (double)wDelayTime.getValue();
			delayLength = Delay.Time * Fs;
			constDecai = exp(-5 * Delay.Time / (Delay.Feedback));
			delayBuffer.clear();
		}

		else if (slider == &wDelayFeedback)
		{
			Delay.Feedback = (double)wDelayFeedback.getValue();
			constDecai = exp(-5 * Delay.Time / (Delay.Feedback));
			delayBuffer.clear();
		}


		//  ------ LISTENER DO MASTER ------ //

		else if (slider == &wMasterLevel)
			MasterLevel = pow(10, (double)wMasterLevel.getValue() / 20);

		//AQUI ACABA O MANUSEIO DOS LISTENERS
	}


	void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override
	{
		Fs = sampleRate;
		calculaequalizadorparametrico(ChannelStrip1);
		calculaequalizadorparametrico(ChannelStrip2);
		calculaequalizadorparametrico(ChannelStrip3);
		calculaequalizadorparametrico(ChannelStrip4);

		calculaequalizadorshelving(ChannelStrip1);
		calculaequalizadorshelving(ChannelStrip2);
		calculaequalizadorshelving(ChannelStrip3);
		calculaequalizadorshelving(ChannelStrip4);

		LBCF1.setSize(1, 1557); LBCF1.clear();
		LBCF2.setSize(1, 1617); LBCF2.clear();
		LBCF3.setSize(1, 1491); LBCF3.clear();
		LBCF4.setSize(1, 1422); LBCF4.clear();
		LBCF5.setSize(1, 1277); LBCF5.clear();
		LBCF6.setSize(1, 1356); LBCF6.clear();
		LBCF7.setSize(1, 1188); LBCF7.clear();
		LBCF8.setSize(1, 1116); LBCF8.clear();

		AP1.setSize(1, 225); AP1.clear();
		AP2.setSize(1, 556); AP2.clear();
		AP3.setSize(1, 441); AP3.clear();
		AP4.setSize(1, 341); AP4.clear();

		delayBufferLength = 10 * Fs;
		delayBuffer.setSize(1, delayBufferLength);
		delayBuffer.clear();

		calculareverb();
	}

	///////////////////////////////////////////////////////////////////////////////////////////
	//
	//                              PROCESSAMENTO DO SINAL - INICIO
	//
	///////////////////////////////////////////////////////////////////////////////////////////

#define MOD(x) ( (x)>=0 ? (x) : -(x) ) //MACRO QUE CALCULA O MODULO

	ChannelStrip *CS; // PONTEIRO PARA O CANAL SENDO PROCESSADO NO MOMENTO

	void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override
	{


		float* const outBuffer0 = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
		float* const outBuffer1 = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);

		double auxSample;

		float* delayData = delayBuffer.getWritePointer(0);
		float in = 0;
		float outDelay = 0.0;

		float* LBCF1_pointer = LBCF1.getWritePointer(0);
		float* LBCF2_pointer = LBCF2.getWritePointer(0);
		float* LBCF3_pointer = LBCF3.getWritePointer(0);
		float* LBCF4_pointer = LBCF4.getWritePointer(0);
		float* LBCF5_pointer = LBCF5.getWritePointer(0);
		float* LBCF6_pointer = LBCF6.getWritePointer(0);
		float* LBCF7_pointer = LBCF7.getWritePointer(0);
		float* LBCF8_pointer = LBCF8.getWritePointer(0);

		float* AP1_pointer = AP1.getWritePointer(AP1.getNumChannels() - 1);
		float* AP2_pointer = AP2.getWritePointer(AP2.getNumChannels() - 1);
		float* AP3_pointer = AP3.getWritePointer(AP3.getNumChannels() - 1);
		float* AP4_pointer = AP4.getWritePointer(AP4.getNumChannels() - 1);


		for (int sample = 0; sample < bufferToFill.numSamples; ++sample)  // INICIO - FOR por Amostra
		{

			for (int channel = 0; channel < bufferToFill.buffer->getNumChannels(); ++channel) // INICIO - FOR por Canal
			{
				//float* const outBuffer = bufferToFill.buffer->getWritePointer(channel, bufferToFill.startSample);
				const float* inBuffer = bufferToFill.buffer->getReadPointer(channel, bufferToFill.startSample);

				if (channel == 0)
					CS = &ChannelStrip1;
				else if (channel == 1)
					CS = &ChannelStrip2;
				else if (channel == 2)
					CS = &ChannelStrip3;
				else if (channel == 3)
					CS = &ChannelStrip4;

				// GANHO

				CS->AmostraAtual = inBuffer[sample] * CS->Gain;

				//==================	INICIO EQUALIZADOR		==================

				if (CS->EqualizadorON)
				{
					// HiMid
					//  /*				
					auxSample = CS->AmostraAtual;
					CS->AmostraAtual = auxSample * CS->HiMid_Coef.a0 + CS->HiMid_Coef.Y1;
					CS->HiMid_Coef.Y1 = auxSample * CS->HiMid_Coef.a1 + CS->HiMid_Coef.Y2 - CS->HiMid_Coef.b1 * CS->AmostraAtual;
					CS->HiMid_Coef.Y2 = auxSample * CS->HiMid_Coef.a2 - CS->HiMid_Coef.b2 * CS->AmostraAtual;
					// */

					// Hi - OKOK
					// /*
					auxSample = CS->AmostraAtual;
					CS->AmostraAtual = auxSample * CS->Hi_Coef.a0 + CS->Hi_Coef.Y1;
					CS->Hi_Coef.Y1 = auxSample * CS->Hi_Coef.a1 + CS->Hi_Coef.Y2 - CS->Hi_Coef.b1 * CS->AmostraAtual;
					CS->Hi_Coef.Y2 = auxSample * CS->Hi_Coef.a2 - CS->Hi_Coef.b2 * CS->AmostraAtual;

					// */

					// LowMid - OKOK

					auxSample = CS->AmostraAtual;
					CS->AmostraAtual = auxSample * CS->LowMid_Coef.a0 + CS->LowMid_Coef.Y1;
					CS->LowMid_Coef.Y1 = auxSample * CS->LowMid_Coef.a1 + CS->LowMid_Coef.Y2 - CS->LowMid_Coef.b1 * CS->AmostraAtual;
					CS->LowMid_Coef.Y2 = auxSample * CS->LowMid_Coef.a2 - CS->LowMid_Coef.b2 * CS->AmostraAtual;


					// LOW - OKOK

					auxSample = CS->AmostraAtual;
					CS->AmostraAtual = auxSample * CS->Low_Coef.a0 + CS->Low_Coef.Y1;
					CS->Low_Coef.Y1 = auxSample * CS->Low_Coef.a1 + CS->Low_Coef.Y2 - CS->Low_Coef.b1 * CS->AmostraAtual;
					CS->Low_Coef.Y2 = auxSample * CS->Low_Coef.a2 - CS->Low_Coef.b2 * CS->AmostraAtual;

				}


				//==================	FIM EQUALIZADOR		==================		

				//==================	INICIO COMPRESSOR		==================

				if (CS->CompressorOn)
				{
					CS->XdB = 20 * log10(MOD(CS->AmostraAtual));

					//Calcula Xsc

					if (CS->Comp_KneeWidth > 0)
					{
						if (CS->XdB < (CS->Comp_Threshold - CS->Comp_KneeWidth / 2))
							CS->Xsc = CS->XdB;

						else if ((CS->XdB >= (CS->Comp_Threshold - CS->Comp_KneeWidth / 2)) && (CS->XdB <= (CS->Comp_Threshold + CS->Comp_KneeWidth / 2)))
							CS->Xsc = CS->XdB + ((1 / CS->Comp_Ratio - 1) * pow((CS->XdB - CS->Comp_Threshold + CS->Comp_KneeWidth / 2), 2) / (2 * CS->Comp_KneeWidth));

						else if (CS->XdB >(CS->Comp_Threshold + (CS->Comp_KneeWidth / 2)))
							CS->Xsc = CS->Comp_Threshold + ((CS->XdB - CS->Comp_Threshold) / CS->Comp_Ratio);

					}
					else if (CS->XdB >= CS->Comp_Threshold)
						CS->Xsc = CS->Comp_Threshold + ((CS->XdB - CS->Comp_Threshold) / CS->Comp_Ratio);

					else
						CS->Xsc = CS->XdB;

					CS->Gc = CS->Xsc - CS->XdB;
					
					//Calcula Smooth gain

					if (CS->Gc <= CS->Gs1)
						CS->Gs0 = CS->Comp_AlfaAttack * CS->Gc + (1 - CS->Comp_AlfaAttack) * CS->Gs1;
						//CS->Gs0 = (1 - CS->Comp_AlfaAttack) * CS->Gc + CS->Comp_AlfaAttack * CS->Gs1;

					else if (CS->Gc > CS->Gs1)
						CS->Gs0 = CS->Comp_AlfaRelease  * CS->Gc + (1 - CS->Comp_AlfaRelease) * CS->Gs1;
						//CS->Gs0 = (1 - CS->Comp_AlfaRelease) * CS->Gc + CS->Comp_AlfaRelease * CS->Gs1;

					if (isnan(CS->Gs0))
						CS->Gs0 = CS->Gs1;

					CS->Gs1 = CS->Gs0; // CRIA O PASSADO - FILTRO SMOOTH
					
					CS->Glin = pow(10, (CS->Gs0 / 20)); // Calcula o ganho linear a ser aplicado

					CS->AmostraAtual = CS->AmostraAtual * CS->Glin * CS->Comp_MakeUp;   // COMPRIME O SINAL ORIGINAL- Aplica o ganho linear

					// SEM Smooth gain - ATTACK e RELEASE
					/*
					if (isnan(CS->Gc))
						CS->Gc = 0;
					CS->Glin = pow(10, (CS->Gc / 20)); // Calcula o ganho linear a ser aplicado
					CS->AmostraAtual = CS->AmostraAtual * CS->Glin * CS->Comp_MakeUp;   // COMPRIME O SINAL ORIGINAL- Aplica o ganho linear
					*/


				}
				else
					CS->AmostraAtual = CS->AmostraAtual; //

			}  // FIM - FOR para CANAL //

			   ///////////////// DELAY  /////////////////

			in = ChannelStrip1.AmostraAtual * ChannelStrip1.Mute * ChannelStrip1.Aux_Delay
				+ ChannelStrip2.AmostraAtual * ChannelStrip2.Mute * ChannelStrip2.Aux_Delay
				+ ChannelStrip3.AmostraAtual * ChannelStrip3.Mute * ChannelStrip3.Aux_Delay
				+ ChannelStrip4.AmostraAtual * ChannelStrip4.Mute * ChannelStrip4.Aux_Delay;

			outDelay = 0.0;

			if (Delay.DelayOn == true) {

				outDelay = delayData[delayReadPosition];
				delayData[delayWritePosition] = in + (delayData[delayReadPosition] * constDecai);

				if (++delayReadPosition >= delayLength) {
					delayReadPosition = 0;
				}
				if (++delayWritePosition >= delayLength) {
					delayWritePosition = 0;

				}
			}
			else
				outDelay = 0.0;

			///////////////// DELAY - FIM /////////////////

			///////////////// REVERB  /////////////////

			inReverb = 0.0;
			outReverb = 0.0;
			Ycomb1 = 0, Ycomb2 = 0, Ycomb3 = 0, Ycomb4 = 0, Ycomb5 = 0, Ycomb6 = 0, Ycomb7 = 0, Ycomb8 = 0;
			Xh = 0;

			if (RReverb.ReverbOn == true) {

				inReverb = ChannelStrip1.AmostraAtual * ChannelStrip1.Aux_Reverb
					+ ChannelStrip2.AmostraAtual * ChannelStrip2.Aux_Reverb
					+ ChannelStrip3.AmostraAtual * ChannelStrip3.Aux_Reverb
					+ ChannelStrip4.AmostraAtual * ChannelStrip4.Aux_Reverb;

				//LOW PASS
				RReverb.AmostraAtual = inReverb * RReverb.a0 + RReverb.Y1;
				RReverb.Y1 = inReverb * RReverb.a1 + RReverb.Y2 - RReverb.b1 * RReverb.AmostraAtual;
				RReverb.Y2 = inReverb * RReverb.a2 - RReverb.b2 * RReverb.AmostraAtual;

				inReverb = RReverb.AmostraAtual;

				//// COMB FILTER 1 ////

				Xh = 0.2 * inReverb - RReverb.Decay * LBCF1_pointer[LBCF1_index];
				Ycomb1 = Xh;
				LBCF1_pointer[LBCF1_index] = Xh;

				if (++LBCF1_index >= 1557) {
					LBCF1_index = 0;
				}

				//// COMB FILTER 2 ////

				Xh = 0.2 * inReverb - RReverb.Decay * LBCF2_pointer[LBCF2_index];
				Ycomb2 = Xh;
				LBCF2_pointer[LBCF2_index] = Xh;

				if (++LBCF2_index >= 1617) {
					LBCF2_index = 0;
				}

				//// COMB FILTER 3 ////

				Xh = 0.2 * inReverb - RReverb.Decay * LBCF3_pointer[LBCF3_index];
				Ycomb3 = Xh;
				LBCF3_pointer[LBCF3_index] = Xh;

				if (++LBCF3_index >= 1491) {
					LBCF3_index = 0;
				}

				//// COMB FILTER 4 ////

				Xh = 0.2 * inReverb - RReverb.Decay * LBCF4_pointer[LBCF4_index];
				Ycomb4 = Xh;
				LBCF4_pointer[LBCF4_index] = Xh;

				if (++LBCF4_index >= 1422) {
					LBCF4_index = 0;
				}

				//// COMB FILTER 5 ////

				Xh = 0.2 * inReverb - RReverb.Decay * LBCF5_pointer[LBCF5_index];
				Ycomb5 = Xh;
				LBCF5_pointer[LBCF5_index] = Xh;

				if (++LBCF4_index >= 1277) {
					LBCF4_index = 0;
				}

				//// COMB FILTER 6 ////

				Xh = 0.2 * inReverb - RReverb.Decay * LBCF6_pointer[LBCF6_index];
				Ycomb6 = Xh;
				LBCF6_pointer[LBCF6_index] = Xh;

				if (++LBCF6_index >= 1356) {
					LBCF6_index = 0;
				}

				//// COMB FILTER 7 ////

				Xh = 0.2 * inReverb - RReverb.Decay * LBCF7_pointer[LBCF7_index];
				Ycomb7 = Xh;
				LBCF7_pointer[LBCF7_index] = Xh;

				if (++LBCF7_index >= 1188) {
					LBCF7_index = 0;
				}

				//// COMB FILTER 8 ////

				Xh = 0.2 * inReverb - RReverb.Decay * LBCF8_pointer[LBCF8_index];
				Ycomb8 = Xh;
				LBCF8_pointer[LBCF8_index] = Xh;

				if (++LBCF8_index >= 1116) {
					LBCF8_index = 0;
				}

				inAllPass = Ycomb1 + Ycomb2 + Ycomb3 + Ycomb4 + Ycomb5 + Ycomb6 + Ycomb7 + Ycomb8;
				//inAllPass = Ycomb1;

				double Y_AllPass1 = 0;
				double Y_AllPass2 = 0;
				double Y_AllPass3 = 0;
				double Y_AllPass4 = 0;
				Xh = 0;

				//// ALLPASS FILTER 1 ////
				Xh = inAllPass - RReverb.Density * AP1_pointer[AP1_index];
				Y_AllPass1 = RReverb.Density * Xh + AP1_pointer[AP1_index];
				AP1_pointer[AP1_index] = Xh;

				if (++LBCF1_index >= 225) {
					LBCF1_index = 0;
				}

				//// ALLPASS FILTER 2 ////
				Xh = Y_AllPass1 - RReverb.Density * AP2_pointer[AP2_index];
				Y_AllPass2 = RReverb.Density * Xh + AP2_pointer[AP2_index];
				AP2_pointer[AP2_index] = Xh;

				if (++LBCF2_index >= 556) {
					LBCF2_index = 0;
				}

				//// ALLPASS FILTER 3 ////
				Xh = Y_AllPass2 - RReverb.Density * AP3_pointer[AP3_index];
				Y_AllPass3 = RReverb.Density * Xh + AP3_pointer[AP3_index];
				AP3_pointer[AP3_index] = Xh;

				if (++AP3_index >= 441) {
					AP3_index = 0;
				}

				//// ALLPASS FILTER 4 ////
				Xh = Y_AllPass3 - RReverb.Density * AP4_pointer[AP4_index];
				Y_AllPass4 = RReverb.Density * Xh + AP4_pointer[AP4_index];
				AP4_pointer[AP4_index] = Xh;

				if (++AP4_index >= 341) {
					AP4_index = 0;
				}

				outReverb = Y_AllPass4;

			}
			else
				outReverb = 0.0;


			///////////////// REVERB - FIM  /////////////////


			outBuffer0[sample] = MasterLevel * (
				ChannelStrip1.AmostraAtual * ChannelStrip1.Mute * ChannelStrip1.Level * ChannelStrip1.PanL
				+ ChannelStrip2.AmostraAtual * ChannelStrip2.Mute * ChannelStrip2.Level * ChannelStrip2.PanL
				+ ChannelStrip3.AmostraAtual * ChannelStrip3.Mute * ChannelStrip3.Level * ChannelStrip3.PanL
				+ ChannelStrip4.AmostraAtual * ChannelStrip4.Mute * ChannelStrip4.Level * ChannelStrip4.PanL
				+ outDelay
				+ outReverb
				);


			outBuffer1[sample] = MasterLevel * (
				ChannelStrip1.AmostraAtual * ChannelStrip1.Mute * ChannelStrip1.Level * ChannelStrip1.PanR
				+ ChannelStrip2.AmostraAtual * ChannelStrip2.Mute * ChannelStrip2.Level * ChannelStrip2.PanR
				+ ChannelStrip3.AmostraAtual * ChannelStrip3.Mute * ChannelStrip3.Level * ChannelStrip3.PanR
				+ ChannelStrip4.AmostraAtual * ChannelStrip4.Mute * ChannelStrip4.Level * ChannelStrip4.PanR
				+ outDelay
				+ outReverb
				);

		} // FIM - FOR por Amostra

	}//FIM getNextAudioBlock


	 ///////////////////////////////////////////////////////////////////////////////////////////
	 //
	 //                              PROCESSAMENTO DO SINAL - FIM
	 //
	 ///////////////////////////////////////////////////////////////////////////////////////////

	void releaseResources() override // Sera chamado quando a fonte ja nao receber o metodo getNextAudioBlock()
	{

	}

	void resized() override //chamada quando 
	{
		//==================================================================
		//AJUSTAR POSICAO E TAMANHO DOS OBJETOS GRÁFICOS USANDO setBounds
		//==================================================================
		//
		//void Component::setBounds(
		//  int 	x,
		//	int 	y,
		//	int 	width,
		//	int 	height
		//)

		//==========================================
		//                  CANAL 1
		//==========================================
		int x1 = 0;

		wGain_1.setBounds(CSwidth / 2 + x1, 0, CSwidth, 40);

		wEq_OnOff_1.setBounds(CSwidth / 2 + x1, 35, CSwidth, 40);
		wEq_Gain_Hi_1.setBounds(0 + x1, 60, CSwidth, 40);
		wEq_Freq_Hi_1.setBounds(CSwidth + x1, 60, CSwidth, 40);
		wEq_Gain_MidHi_1.setBounds(CSwidth / 2 + x1, 100, CSwidth, 40);
		wEq_Freq_MidHi_1.setBounds(0 + x1, 140, CSwidth, 40);
		wEq_Q_MidHi_1.setBounds(CSwidth + x1, 140, CSwidth, 40);
		wEq_Gain_MidLow_1.setBounds(CSwidth / 2 + x1, 180, CSwidth, 40);
		wEq_Freq_MidLow_1.setBounds(0 + x1, 220, CSwidth, 40);
		wEq_Q_MidLow_1.setBounds(CSwidth + x1, 220, CSwidth, 40);
		wEq_Gain_Low_1.setBounds(0 + x1, 260, CSwidth, 40);
		wEq_Freq_Low_1.setBounds(CSwidth + x1, 260, CSwidth, 40);

		wCompOnOff_1.setBounds(CSwidth / 2 + x1, 295, CSwidth, 40);
		wCompThreshold_1.setBounds(0 + x1, 320, CSwidth, 40);
		wCompRatio_1.setBounds(CSwidth + x1, 320, CSwidth, 40);
		wCompAttack_1.setBounds(0 + x1, 360, CSwidth, 40);
		wCompRelease_1.setBounds(CSwidth + x1, 360, CSwidth, 40);
		wCompKnee_1.setBounds(0 + x1, 400, CSwidth, 40);
		wCompMakeUp_1.setBounds(CSwidth + x1, 400, CSwidth, 40);

		wAuxReverb_1.setBounds(0 + x1, 460, CSwidth, 40);
		wAuxDelay_1.setBounds(CSwidth + x1, 460, CSwidth, 40);
		wPan_1.setBounds(CSwidth / 2 + x1, 500, CSwidth, 40);
		wLevel_1.setBounds(CSwidth / 2 + x1, 540, CSwidth, 120);
		wMute_1.setBounds(0 + x1, 500, CSwidth, 120);
		labelCanal1.setBounds(CSwidth / 2 + x1, 660, CSwidth, 20);

		//==========================================
		//                  CANAL 2
		//==========================================
		int x2 = 220;

		wGain_2.setBounds(CSwidth / 2 + x2, 0, CSwidth, 40);

		wEq_OnOff_2.setBounds(CSwidth / 2 + x2, 35, CSwidth, 40);
		wEq_Gain_Hi_2.setBounds(0 + x2, 60, CSwidth, 40);
		wEq_Freq_Hi_2.setBounds(CSwidth + x2, 60, CSwidth, 40);
		wEq_Gain_MidHi_2.setBounds(CSwidth / 2 + x2, 100, CSwidth, 40);
		wEq_Freq_MidHi_2.setBounds(0 + x2, 140, CSwidth, 40);
		wEq_Q_MidHi_2.setBounds(CSwidth + x2, 140, CSwidth, 40);
		wEq_Gain_MidLow_2.setBounds(CSwidth / 2 + x2, 180, CSwidth, 40);
		wEq_Freq_MidLow_2.setBounds(0 + x2, 220, CSwidth, 40);
		wEq_Q_MidLow_2.setBounds(CSwidth + x2, 220, CSwidth, 40);
		wEq_Gain_Low_2.setBounds(0 + x2, 260, CSwidth, 40);
		wEq_Freq_Low_2.setBounds(CSwidth + x2, 260, CSwidth, 40);

		wCompOnOff_2.setBounds(CSwidth / 2 + x2, 295, CSwidth, 40);
		wCompThreshold_2.setBounds(0 + x2, 320, CSwidth, 40);
		wCompRatio_2.setBounds(CSwidth + x2, 320, CSwidth, 40);
		wCompAttack_2.setBounds(0 + x2, 360, CSwidth, 40);
		wCompRelease_2.setBounds(CSwidth + x2, 360, CSwidth, 40);
		wCompKnee_2.setBounds(0 + x2, 400, CSwidth, 40);
		wCompMakeUp_2.setBounds(CSwidth + x2, 400, CSwidth, 40);

		wAuxReverb_2.setBounds(0 + x2, 460, CSwidth, 40);
		wAuxDelay_2.setBounds(CSwidth + x2, 460, CSwidth, 40);
		wPan_2.setBounds(CSwidth / 2 + x2, 500, CSwidth, 40);
		wLevel_2.setBounds(CSwidth / 2 + x2, 540, CSwidth, 120);
		wMute_2.setBounds(0 / 2 + x2, 500, CSwidth, 120);
		labelCanal2.setBounds(CSwidth / 2 + x2, 660, CSwidth, 20);

		//==========================================
		//                  CANAL 3
		//==========================================
		int x3 = 440;

		wGain_3.setBounds(CSwidth / 2 + x3, 0, CSwidth, 40);

		wEq_OnOff_3.setBounds(CSwidth / 2 + x3, 35, CSwidth, 40);
		wEq_Gain_Hi_3.setBounds(0 + x3, 60, CSwidth, 40);
		wEq_Freq_Hi_3.setBounds(CSwidth + x3, 60, CSwidth, 40);
		wEq_Gain_MidHi_3.setBounds(CSwidth / 2 + x3, 100, CSwidth, 40);
		wEq_Freq_MidHi_3.setBounds(0 + x3, 140, CSwidth, 40);
		wEq_Q_MidHi_3.setBounds(CSwidth + x3, 140, CSwidth, 40);
		wEq_Gain_MidLow_3.setBounds(CSwidth / 2 + x3, 180, CSwidth, 40);
		wEq_Freq_MidLow_3.setBounds(0 + x3, 220, CSwidth, 40);
		wEq_Q_MidLow_3.setBounds(CSwidth + x3, 220, CSwidth, 40);
		wEq_Gain_Low_3.setBounds(0 + x3, 260, CSwidth, 40);
		wEq_Freq_Low_3.setBounds(CSwidth + x3, 260, CSwidth, 40);

		wCompOnOff_3.setBounds(CSwidth / 2 + x3, 295, CSwidth, 40);
		wCompThreshold_3.setBounds(0 + x3, 320, CSwidth, 40);
		wCompRatio_3.setBounds(CSwidth + x3, 320, CSwidth, 40);
		wCompAttack_3.setBounds(0 + x3, 360, CSwidth, 40);
		wCompRelease_3.setBounds(CSwidth + x3, 360, CSwidth, 40);
		wCompKnee_3.setBounds(0 + x3, 400, CSwidth, 40);
		wCompMakeUp_3.setBounds(CSwidth + x3, 400, CSwidth, 40);

		wAuxReverb_3.setBounds(0 + x3, 460, CSwidth, 40);
		wAuxDelay_3.setBounds(CSwidth + x3, 460, CSwidth, 40);
		wPan_3.setBounds(CSwidth / 2 + x3, 500, CSwidth, 40);
		wLevel_3.setBounds(CSwidth / 2 + x3, 540, CSwidth, 120);
		wMute_3.setBounds(0 / 2 + x3, 500, CSwidth, 120);
		labelCanal3.setBounds(CSwidth / 2 + x3, 660, CSwidth, 20);

		//==========================================
		//                  CANAL 4
		//==========================================
		int x4 = 660;

		wGain_4.setBounds(CSwidth / 2 + x4, 0, CSwidth, 40);

		wEq_OnOff_4.setBounds(CSwidth / 2 + x4, 35, CSwidth, 40);
		wEq_Gain_Hi_4.setBounds(0 + x4, 60, CSwidth, 40);
		wEq_Freq_Hi_4.setBounds(CSwidth + x4, 60, CSwidth, 40);
		wEq_Gain_MidHi_4.setBounds(CSwidth / 2 + x4, 100, CSwidth, 40);
		wEq_Freq_MidHi_4.setBounds(0 + x4, 140, CSwidth, 40);
		wEq_Q_MidHi_4.setBounds(CSwidth + x4, 140, CSwidth, 40);
		wEq_Gain_MidLow_4.setBounds(CSwidth / 2 + x4, 180, CSwidth, 40);
		wEq_Freq_MidLow_4.setBounds(0 + x4, 220, CSwidth, 40);
		wEq_Q_MidLow_4.setBounds(CSwidth + x4, 220, CSwidth, 40);
		wEq_Gain_Low_4.setBounds(0 + x4, 260, CSwidth, 40);
		wEq_Freq_Low_4.setBounds(CSwidth + x4, 260, CSwidth, 40);

		wCompOnOff_4.setBounds(CSwidth / 2 + x4, 295, CSwidth, 40);
		wCompThreshold_4.setBounds(0 + x4, 320, CSwidth, 40);
		wCompRatio_4.setBounds(CSwidth + x4, 320, CSwidth, 40);
		wCompAttack_4.setBounds(0 + x4, 360, CSwidth, 40);
		wCompRelease_4.setBounds(CSwidth + x4, 360, CSwidth, 40);
		wCompKnee_4.setBounds(0 + x4, 400, CSwidth, 40);
		wCompMakeUp_4.setBounds(CSwidth + x4, 400, CSwidth, 40);

		wAuxReverb_4.setBounds(0 + x4, 460, CSwidth, 40);
		wAuxDelay_4.setBounds(CSwidth + x4, 460, CSwidth, 40);
		wPan_4.setBounds(CSwidth / 2 + x4, 500, CSwidth, 40);
		wLevel_4.setBounds(CSwidth / 2 + x4, 540, CSwidth, 120);
		wMute_4.setBounds(0 / 2 + x4, 500, CSwidth, 120);
		labelCanal4.setBounds(CSwidth / 2 + x4, 660, CSwidth, 20);

		//==========================================
		//                  REVERB
		//==========================================
		int x5 = 900;

		labelReverb.setBounds(x5, 20, 400, 20);
		wReverbDecay.setBounds(x5, 40, 200, 40);
		wReverbDensity.setBounds(x5 + 200, 40, 200, 40);
		wReverbOnOff.setBounds(x5 + 200, 80, 200, 40);

		//==========================================
		//                  DELAY
		//==========================================

		labelDelay.setBounds(x5, 120, 400, 20);
		wDelayTime.setBounds(x5, 140, 200, 40);
		wDelayFeedback.setBounds(x5 + 200, 140, 200, 40);
		wDelayOnOff.setBounds(x5 + 200, 180, 200, 40);

		//==========================================
		//                  MASTER
		//==========================================

		labelMaster.setBounds(x5 + 100, 220, 200, 40);
		wMasterLevel.setBounds(x5 + 100, 260, 200, 200);

	}

private:

	// MEMBROS PRIVADOS DA MainContentComponent

	//Declaração dos componentes graficos

	// ----- Canal 1 -----

	Label labelCanal1;

	Slider wGain_1;

	ToggleButton wEq_OnOff_1;
	Slider wEq_Freq_Hi_1;
	Slider wEq_Gain_Hi_1;
	Slider wEq_Freq_MidHi_1;
	Slider wEq_Q_MidHi_1;
	Slider wEq_Gain_MidHi_1;
	Slider wEq_Freq_MidLow_1;
	Slider wEq_Q_MidLow_1;
	Slider wEq_Gain_MidLow_1;
	Slider wEq_Freq_Low_1;
	Slider wEq_Gain_Low_1;

	ToggleButton wCompOnOff_1;
	Slider wCompThreshold_1;
	Slider wCompRatio_1;
	Slider wCompAttack_1;
	Slider wCompRelease_1;
	Slider wCompKnee_1;
	Slider wCompMakeUp_1;

	Slider wAuxReverb_1;
	Slider wAuxDelay_1;
	Slider wPan_1;
	Slider wLevel_1;
	ToggleButton wMute_1;

	/// ----- Canal 2 -----

	Label labelCanal2;

	Slider wGain_2;

	ToggleButton wEq_OnOff_2;
	Slider wEq_Freq_Hi_2;
	Slider wEq_Gain_Hi_2;
	Slider wEq_Freq_MidHi_2;
	Slider wEq_Q_MidHi_2;
	Slider wEq_Gain_MidHi_2;
	Slider wEq_Freq_MidLow_2;
	Slider wEq_Q_MidLow_2;
	Slider wEq_Gain_MidLow_2;
	Slider wEq_Freq_Low_2;
	Slider wEq_Gain_Low_2;

	ToggleButton wCompOnOff_2;
	Slider wCompThreshold_2;
	Slider wCompRatio_2;
	Slider wCompAttack_2;
	Slider wCompRelease_2;
	Slider wCompKnee_2;
	Slider wCompMakeUp_2;

	Slider wAuxReverb_2;
	Slider wAuxDelay_2;
	Slider wPan_2;
	Slider wLevel_2;
	ToggleButton wMute_2;

	/// ----- Canal 3 -----

	Label labelCanal3;

	Slider wGain_3;

	ToggleButton wEq_OnOff_3;
	Slider wEq_Freq_Hi_3;
	Slider wEq_Gain_Hi_3;
	Slider wEq_Freq_MidHi_3;
	Slider wEq_Q_MidHi_3;
	Slider wEq_Gain_MidHi_3;
	Slider wEq_Freq_MidLow_3;
	Slider wEq_Q_MidLow_3;
	Slider wEq_Gain_MidLow_3;
	Slider wEq_Freq_Low_3;
	Slider wEq_Gain_Low_3;

	ToggleButton wCompOnOff_3;
	Slider wCompThreshold_3;
	Slider wCompRatio_3;
	Slider wCompAttack_3;
	Slider wCompRelease_3;
	Slider wCompKnee_3;
	Slider wCompMakeUp_3;

	Slider wAuxReverb_3;
	Slider wAuxDelay_3;
	Slider wPan_3;
	Slider wLevel_3;
	ToggleButton wMute_3;

	/// ----- Canal 4 -----

	Label labelCanal4;

	Slider wGain_4;

	ToggleButton wEq_OnOff_4;
	Slider wEq_Freq_Hi_4;
	Slider wEq_Gain_Hi_4;
	Slider wEq_Freq_MidHi_4;
	Slider wEq_Q_MidHi_4;
	Slider wEq_Gain_MidHi_4;
	Slider wEq_Freq_MidLow_4;
	Slider wEq_Q_MidLow_4;
	Slider wEq_Gain_MidLow_4;
	Slider wEq_Freq_Low_4;
	Slider wEq_Gain_Low_4;

	ToggleButton wCompOnOff_4;
	Slider wCompThreshold_4;
	Slider wCompRatio_4;
	Slider wCompAttack_4;
	Slider wCompRelease_4;
	Slider wCompKnee_4;
	Slider wCompMakeUp_4;

	Slider wAuxReverb_4;
	Slider wAuxDelay_4;
	Slider wPan_4;
	Slider wLevel_4;
	ToggleButton wMute_4;

	// Reverb

	Label labelReverb;


	Slider wReverbDensity;
	Slider wReverbDecay;
	ToggleButton wReverbOnOff;
	double constDecay_Reverb = 0.84;
	double constDensity_Reverb = 0.0;


	AudioSampleBuffer LBCF1;
	AudioSampleBuffer LBCF2;
	AudioSampleBuffer LBCF3;
	AudioSampleBuffer LBCF4;
	AudioSampleBuffer LBCF5;
	AudioSampleBuffer LBCF6;
	AudioSampleBuffer LBCF7;
	AudioSampleBuffer LBCF8;

	AudioSampleBuffer AP1;
	AudioSampleBuffer AP2;
	AudioSampleBuffer AP3;
	AudioSampleBuffer AP4;

	/*
	double LBCF_1[1577] = {};
	double LBCF_2[1617] = {};
	double LBCF_3[1491] = {};
	double LBCF_4[1422] = {};
	double LBCF_5[1422] = {};
	double LBCF_6[1422] = {};
	double LBCF_7[1422] = {};
	double LBCF_8[1422] = {};
	*/
	int LBCF1_index = 0;
	int LBCF2_index = 0;
	int LBCF3_index = 0;
	int LBCF4_index = 0;
	int LBCF5_index = 0;
	int LBCF6_index = 0;
	int LBCF7_index = 0;
	int LBCF8_index = 0;

	/*
	double AP_1[225] = {};
	double AP_2[556] = {};
	double AP_3[441] = {};
	double AP_4[341] = {};
	*/

	int AP1_index = 0;
	int AP2_index = 0;
	int AP3_index = 0;
	int AP4_index = 0;

	// Delay

	Label labelDelay;

	Slider wDelayTime;
	Slider wDelayFeedback;
	ToggleButton wDelayOnOff;

	float delayLength = 10;
	float feedback;
	float constDecai;
	int aux, position;

	AudioSampleBuffer delayBuffer;
	int delayBufferLength = 0;
	int delayReadPosition = 0;
	int delayWritePosition = 0;


	float inReverb = 0.0;
	float outReverb = 0.0;
	float Ycomb1 = 0, Ycomb2 = 0, Ycomb3 = 0, Ycomb4 = 0, Ycomb5 = 0, Ycomb6 = 0, Ycomb7 = 0, Ycomb8 = 0;
	float Xh = 0;
	double inAllPass = 0;

	// Master

	Label labelMaster;

	Slider wMasterLevel;

	//Termina Aqui a declaração dos componentes Gráficos

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainContentComponent)
};


Component* createMainContentComponent() { return new MainContentComponent(); }

#endif  // MAINCOMPONENT_H_INCLUDED