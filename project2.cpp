#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;

enum ChoiceAtOperater{Add=1, sub=2, Mul=3, Div=4, Mix1=5};
enum ChoiceALevel{Easy=1, Med=2, Hard=3, Mix2=4};


struct stGameResults{

    int GameRounds=0,
        Level=0,
        Operater=0,
        PlayerWon=0,
        PlayerFail=0;
};

int Read( string message ){

    int Number=0 ;

    do{

        cout << message << endl ;
        cin >> Number ;

    } while ( Number < 0 );

    return Number;
}

int RandomNumber(int From, int To){
    int randum= rand() % (To - From + 1) + From ;
    return randum;
}

char Operator(ChoiceAtOperater OPType){


        switch (OPType){
        case ChoiceAtOperater::Add :
            return '+';
            break;
        case ChoiceAtOperater::sub:
            return '-';
            break;
        case ChoiceAtOperater::Mul:
            return '*';
            break;
        case ChoiceAtOperater::Div:
            return '/';
            break;
        case ChoiceAtOperater::Mix1: {
            int RandomOP=RandomNumber(1,4);
            return Operator((ChoiceAtOperater)RandomOP);
        }
        }
}
string GetLevelName(int LevelNumber) {
    string arrLevelNames[4] = { "Easy", "Med", "Hard", "Mix" };
    return arrLevelNames[LevelNumber - 1]; // نطرح 1 لأن المصفوفة تبدأ من صفر
}

string GetOpName(int OpNumber) {
    string arrOpNames[5] = { "Add", "Sub", "Mul", "Div", "Mix" };
    return arrOpNames[OpNumber - 1];
}

int InputALevel(ChoiceALevel Level){
    switch(Level){
    case ChoiceALevel::Easy:
        return RandomNumber(1,10);
        break;
    case ChoiceALevel::Med:
        return RandomNumber(10,50);
        break;
    case ChoiceALevel::Hard:
        return RandomNumber(50,90);
        break;
    case ChoiceALevel::Mix2:
        return RandomNumber(1,100);
        break;
    }
}

ChoiceAtOperater InputOfGamerToOperator(stGameResults &Game){

    Game.Operater=Read("\nYour Choice : [1]:Add,  [2]:sub,  [3]:Mul,  [4]:Div,  [5]:Mix1   ? ");
    return (ChoiceAtOperater)Game.Operater;

}

ChoiceALevel InputOfGamerToLevel(stGameResults &Game){

    Game.Level=Read("\nYour Choice : [1]:Easy,  [2]:Med,  [3]:Hard,  [4]:Mix2   ? ");
    return (ChoiceALevel)Game.Level;

}

int InputOfGamerToNumberRound(stGameResults &Game){

    Game.GameRounds=Read("How Many Question do you want to answer  ? ");
    return Game.GameRounds;

}

int InputOfGamerAnswer(){

    int Answer=Read("");
    return Answer;

}

int TrueAnswer(char Operator, int number1, int number2 ){

    switch(Operator){
    case '+':
        return number1+number2;
        break;
    case '-':
        return number1-number2;
        break;
    case '*':
        return number1*number2;
        break;
    case '/':
        return number1/number2;
        break;
    }

}

void checkAnswer(int trueAnswe, int GamerAnswer, stGameResults &Game){
    if(trueAnswe==GamerAnswer){
        system("color 2f");
        cout << "Rigth Answer :-)" << endl ;
        Game.PlayerWon++;
    }
    else{
        system("color 4f");
        cout << "\a wrong Answer :-(" << endl ;
        cout << "The Right Answer : " << trueAnswe << endl;
        Game.PlayerFail++;
    }
}

void printProcess(char Operator, int number1, int number2){
        cout << number1 << endl;
        cout <<  number2 << Operator << endl ;
        cout << "________" << endl ;
}

void PartOneFromProgram(stGameResults &Game){

    int Round=InputOfGamerToNumberRound(Game);
    ChoiceALevel Level=InputOfGamerToLevel(Game);
    ChoiceAtOperater Operatorr=InputOfGamerToOperator(Game);


    for (int i = 1 ; i <= Round ; i++ ){
        char Operatorrr=Operator(Operatorr);
        int number1=InputALevel(Level);
        int number2=InputALevel(Level);

        int TrueAnswerr=TrueAnswer(Operatorrr,number1,number2);


        cout << "______ Question[" << i <<"/" << Round << "] ______" << endl;
        printProcess(Operatorrr,number1,number2);
        int GamerAnswer=InputOfGamerAnswer();
        checkAnswer(TrueAnswerr,GamerAnswer,Game);
    }
}

void PartTowHeaderResult(stGameResults &Game){

    cout << "\t\t_______________________________________" << endl ;
    if(Game.PlayerWon > Game.PlayerFail){
        system("color 2f");
        cout << "\t\t\tFinal Results is PASS :-) " << endl ;
    }
    else {
        system("color 4f");
        cout << "Final Results is WRONG :-) " << endl ;
    }
    cout << "\t\t_______________________________________" << endl ;
}

void PartThreeFromProgram(stGameResults &Game){



    cout << "\n\t\tNumber of Question : " <<Game.GameRounds << endl ;
    cout << "\t\tQuestion Level : " << GetLevelName(Game.Level) << endl ;
    cout << "\t\tOpType : " << GetOpName(Game.Operater) << endl ;
    cout << "\t\tNumber Of Right Answer : " << Game.PlayerWon << endl;
    cout << "\t\tNumber Of Wrong Answer : " << Game.PlayerFail << endl ;
}
void ResetProgram(){

    system("cls");
    system("color 0f");

}

void start(){

    char Question='y';

    do {
        stGameResults Game;
        ResetProgram();
        PartOneFromProgram(Game);
        PartTowHeaderResult(Game);
        PartThreeFromProgram(Game);
        cout << "\n\nDo you want to play again? y/n ? " ;
        cin >> Question;


    } while(Question=='y' || Question=='Y');

    system("color 0f");
}


int main()
{

    srand((signed)time(NULL));

    start();

    return 0;
}
