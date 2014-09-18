

public static partial class AI::AI	{
	public static string GetTeamName()	{
		return TEAMNAME;
	}
	public static void SetSuperObj(int X, int Y, int N)	{
		SuperObjects[nSuperObjects].X = X;
		SuperObjects[nSuperObjects].Y = X;
	}
	public static SuperObject GetSuperObj(int N)	{
		return SuperObjects[N];
	}
	public static void SetData(int S0, int S1, int S2, int S3, int S4, int S5,
	int S6, int S7, int S8, int S9, int S10, int S11, int S12, int S13, int S14)	{
		US_Front = S0;
		US_Back = S1;
		US_Left = S2;
		US_Right = S3;
		CSLeft_R = S4;
		CSLeft_G = S5;
		CSLeft_B = S6;
		CSRight_R = S7;
		CSRight_G = S8;
		CSRight_B = S9;
		Position_X = S10;
		Position_Y = S11;
		TM_State = S12;
		Compass = S13;
		Time = S14;
	}
	public static void GetCommand(ref int Actuator0, ref int Actuator1,
	ref int Actuator2, ref int Actuator3)	{
		Actuator0 = Wheel_Left;
		Actuator1 = Wheel_Right;
		Actuator2 = LED_1;
		Actuator3 = MyState;
	}
	public static void OnTimer()	{
	}
}
