// Eu prefiro dividir em varios arquivos pra nao ficar tap exageradp
// mas nao achei nada que falasse algo sobre compilar esse codigo
// entao, por seguranca sempre usem "static" pra compilar dando cat nos
// arquivos.

// Definindo nada por motivo nenhum.
#define TEAMNAME "Int Egrado;"
#define MAX_SUPER_OBJECTS 10

#define YES true
#define NO false

#define COLORS.RED RED
#define COLORS.GREEN GREEN
#define COLORS.BLACK BLACK
#define COLORS.PURPLE PURPLE

// O purple eh um super object.
enum COLORS {RED,GREEN,BLACK,PURPLE}

// Se possivel tentem ver se da pra mudar o namespace de AI pra ROBOT
// O AI pode ser reservado pro proprio AI mesmo.

namespace AI	{	
	public static partial class AI	{
		// Constantes auto-explicativas.
		static int Duration=0;
		static int SuperDuration=0;
		
		static bool isGameEnd=NO;
		static int nAction=0xF0DA5E;

		static struct	SuperObject	{
			int X;
			int Y;
		} SuperObjects[MAX_SUPER_OBJECTS];
		static nSuperObjects=0;
		// Nao entendi essas duas variaveis a seguir.
		static int teleport=0; 
		static int nLoadedObjects=0;
		
		// Ultra-sonic sensors.
		static int US_Front=0;
		static int US_Back=0;
		static int US_Left=0;
		static int US_Right=0;
		
		// 
		static int CSLeft_R=0;
		static int CSLeft_G=0;
		static int CSLeft_B=0;
		static int CSRight_R=0;
		static int CSRight_G=0;
		static int CSRight_B=0;

		static int POSITION_X=0;
		static int POSITION_Y=0;
		static int Wheel_Left=0;
		static int Wheel_Right=0;
		
		static int TM_STATE=0;
		static int Time=0;
		static int LED_1=0;
		static int MyState=0;

		// public static void OnTimer();
	}
}

