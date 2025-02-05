#include <iostream>
#include <Windows.h>
#include <string>
#include <random>
#include <conio.h>
#include <format>
#include <iomanip>

using namespace std;

// 커서 깜박임 제거
void Init() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = 0;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    srand(time(NULL));
}

// 랜덤 수 반환, 전역으로 선언하여 성능향상
random_device rd;
mt19937 mt(rd());
int random_engine() {
    uniform_int_distribution<int> dist(0, 50);
    return dist(mt);
}
int random_engine_2() {
    uniform_int_distribution<int> dist(0, 1);
    return dist(mt);
}
int random_engine_4() {
    uniform_int_distribution<int> dist(0, 3);
    return dist(mt);
}
int random_engine_10() {
    uniform_int_distribution<int> dist(1, 10);
    return dist(mt);
}

// 강아지 구조체
struct jindo {
    string name = "진돗개";
    int level = 1;
    int exp = 0;
    int hp = 500;
    int atk = 200;
    int def = 100;
    int charm = 100;
    string skill_name = "물고 흔들기";
};
struct mix {
    string name = "믹스";
    int level = 1;
    int exp = 0;
    int hp = 400;
    int atk = 150;
    int def = 100;
    int charm = 90;
    string skill_name = "앞 발 치기";
};
struct chihuahua {
    string name = "치와와";
    int level = 1;
    int exp = 0;
    int hp = 200;
    int atk = 180;
    int def = 10;
    int charm = 50;
    string skill_name = "닥치는대로 물기";
};



// 처음 화면
void lobby() {
    while (true) {

        std::cout << R"(
    o-o-o                                                                     o-o-o  
  o       o -o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o- o       o  
 o                                                                                   o
  o      ###    #####    ####        #     #     #        ####     ###    ####      o  
   o    #         #      #   #      # #     #   #         #   #   #   #  #         o 
    o    ###      #      ####      #####     # #          #   #   #   #  #  ###   o  
   o        #     #      #   #    #     #     #           #   #   #   #  #   #     o 
  o      ###      #      #    #  #      #     #           ####     ###    ####      o 
 o                                                                                   o      
  o       o -o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o- o       o  
    o-o-o                                                                     o-o-o
    

                                  1. 게임 시작
                                  2. 게임 종료
)" << std::endl;
        int user = 0;
        cin >> user;
        if (user == 2) {
            exit(0);
        }
        else if (user == 1) {
            system("cls");
            return;
        }
        else if (cin.fail()) { // 문자열 입력시 예외처리
            cin.clear();
            cin.ignore(100, '\n');
            system("cls");
            continue;
        }
        else { // 다른 숫자 입력시 예외처리
            system("cls");
            continue;
        }
    }
}

int num;
int* input = &num; // 캐릭터 선정 번호

// 캐릭터 선정
int character_choice() {
    
    int input_2 = 0;
    while (true) {
        std::cout << R"(
      o-o-o-o-o-o-o-o-o       o-o-o-o-o-o-o-o-o        o-o-o-o-o-o-o-o-o  
    o                   o   o                   o    o                   o                     
    o    √↖__         o   o    √ ~~~~~  √   o    o     / `__/ `      o                     
    o   (     @ ____    o   o    ( ≡   ≡ )    o    o    (  `  ´ )     o                     
    o  (            o   o   o   (    ▼   )     o    o         ^  /      o                     
    o   /    (____ /    o   o     --    --      o    o    / -  -- `      o                     
    o  /_____/   ∪     o   o     /  ~~~  )     o    o   /         `     o         
    o                   o   o    /         )    o    o                   o                                                                                        
      o-o-o-o-o-o-o-o-o       o-o-o-o-o-o-o-o-o        o-o-o-o-o-o-o-o-o         
          1. 진돗개               2. 믹스견                3. 치와와
          (  쉬움 )               (  평범  )               ( 어려움 )

    
)" << std::endl;
        
        cin >> *input;
        // 진돗개 선택 시
        if (*input == 1) {// 진돗개 선택 시
            system("cls");
            cout << "진돗개를 선택하셨습니다!" << endl;
            std::cout << R"(
      o-o-o-o-o-o-o-o-o    
    o                   o  
    o    √↖__         o   진돗개
    o   (     @ ____    o   HP    = 500
    o  (            o   o   ATK   = 200
    o   /    (____ /    o   DEF   = 100
    o  /_____/   ∪     o   CHARM = 100
    o                   o  
      o-o-o-o-o-o-o-o-o   
              
)" << std::endl;
            cout << "계속하시겠습니까?" << endl;
            cout << "1. 진행하기" << endl;
            cout << "2. 돌아가기" << endl;
            cin >> input_2;

            if (input_2 == 1) {
                system("cls");
                return *input;
            }
            else if (input_2 == 2) {
                system("cls");
            }
        }
        // 믹스견 선택 시
        else if (*input == 2) {
            system("cls");
            cout << "믹스견을 선택하셨습니다!" << endl;
            std::cout << R"(
      o-o-o-o-o-o-o-o-o    
    o                   o  
    o   √ ~~~~~  √    o   믹스견
    o   ( ≡   ≡ )     o   HP    = 400
    o  (    ▼   )      o   ATK   = 150
    o    --    --       o   DEF   = 100
    o    /  ~~~  )      o   CHARM = 90
    o   /         )     o  
      o-o-o-o-o-o-o-o-o   
              
)" << std::endl;
            cout << "계속하시겠습니까?" << endl;
            cout << "1. 진행하기" << endl;
            cout << "2. 돌아가기" << endl;
            cin >> input_2;

            if (input_2 == 1) {
                system("cls");
                return *input;
            }
            else if (input_2 == 2) {
                system("cls");
            }
        }
        // 치와와 선택 시
        else if (*input == 3) {
            system("cls");
            cout << "치와와를 선택하셨습니다!" << endl;
            std::cout << R"(
      o-o-o-o-o-o-o-o-o    
    o                   o  
    o     / `__/ `      o   치와와
    o    (  `  ´ )     o   HP    = 200
    o         ^  /      o   ATK   = 180
    o    / -  -- `      o   DEF   = 10
    o   /         `     o   CHARM = 50
    o                   o  
      o-o-o-o-o-o-o-o-o   
              
            )" << std::endl;
            cout << "계속하시겠습니까?" << endl;
            cout << "1. 진행하기" << endl;
            cout << "2. 돌아가기" << endl;
            cin >> input_2;

            if (input_2 == 1) {
            system("cls");
            return *input;
            }
            else if (input_2 == 2) {
                system("cls");
                continue;
            }
        }
        else if (cin.fail()) { // 문자열 입력시 예외처리
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }
        else { // 다른숫자 입력시 예외처리
            system("cls");
            continue;
        }   
    }
    
}


//class mob {
//
//
//    string name;
//    int level;
//    int hp;
//    int atk;
//    int def;
//    int charm;
//    string skill_name;
//public:
//
//    void dog_info(string &dog_name, int dog_level, int dog_hp, int dog_atk, int dog_def, int dog_charm, string skill_name ) {
//        name = dog_name;
//    }
//    
//    
//
//    }
//};

struct trashbag {
    string name = "음식물 쓰레기 봉투";
    int enemy_type = 1;
    int enemy_hp = random_engine(), enemy_atk = 50, enemy_def = random_engine_10();
    string skill_name = "음쓰공격";

};
struct ricecake {
    string name = "컵 떡볶이";
    int enemy_type = 1;
    int enemy_hp = 1, enemy_atk = 1, enemy_def = random_engine();
    string skill_name = "나트륨 공격";
};
struct shattered_glass {
    string name = "유리조각";
    int enemy_type = 2;
    int enemy_hp = 0, enemy_atk = 100, enemy_def = random_engine_10();
    string skill_name = "베기";
};
struct fishbone {
    string name = "생선가시";
    int enemy_type = 2;
    int enemy_hp = 0, enemy_atk = 50, enemy_def = 0;
    string skill_name = "목 찌르기";
};

void encounter(string& dog_name, int &dog_level, int &dog_hp, int &dog_atk, int &dog_def,
    int &dog_charm, string skill_name, string _name, int _hp, int _atk, int _def, int _type) {

    int dog_do = 0;
    bool flag = true;
    int seek = 2;

    cout << endl << _name << "을(를) 발견했다." << endl;
    cin.get();
    system("cls");

    while (flag) {

        switch (seek) {
        case 1:
            cout << dog_name << setw(13) << setfill(' ') << "발견! : " << _name << endl;
            cout << "HP    : " << setw(3) << setfill(' ') << dog_hp << "   " << "HP  : " << setw(3) << setfill(' ') << _hp << endl;
            cout << "ATK   : " << setw(3) << setfill(' ') << dog_atk << "   " << "ATK : " << setw(3) << setfill(' ') << _atk << endl;
            cout << "CHARM : " << setw(3) << setfill(' ') << dog_charm << endl << endl;
            break;
        case 2:
            cout << dog_name << setw(13) << setfill(' ') << "발견! : " << _name << endl;
            cout << "HP    : " << setw(3) << setfill(' ') << dog_hp << "   " << "HP  : " << setw(3) << setfill(' ') << "???" << endl;
            cout << "ATK   : " << setw(3) << setfill(' ') << dog_atk << "   " << "ATK : " << setw(3) << setfill(' ') << "???" << endl;
            cout << "CHARM : " << setw(3) << setfill(' ') << dog_charm << endl<< endl;
        }

        
        cout << "무슨 행동을 할까? " << endl;
        cout << "1. 핥기" << endl;
        cout << "2. 물기" << endl;
        cout << "3. 냄새맡기" << endl;
        cout << "4. 도망가기" << endl;
        cout << "행동 선택 >> ";
        cin >> dog_do;

        switch (dog_do) {

        case 1:
            if (_type == 1) {
                cout << endl << dog_name << "은(는) " << _name << "을(를) 핥았다." << endl;
                cin.get();
                cout << dog_name << "의 HP가 소량 올랐다." << endl;
                cout << dog_name << "의 매력이 줄었다." << endl;
                dog_hp += _hp;
                dog_charm -= 5;
                cin.get();
                break;
            }
            else if (_type == 2) {
                cout << endl << dog_name << "은(는) " << _name << "을(를) 핥았다." << endl;
                cin.get();
                cout << dog_name << "의 HP가 줄었다." << endl;
                cout << dog_name << "의 매력이 줄었다." << endl;
                dog_hp -= _atk;
                dog_charm -= 5;
                cin.get();
                break;
            }
        case 2:
            if (_type == 1) {
                cout << endl << dog_name << "은(는) " << _name << "을(를) 물었다." << endl;
                cin.get();
                cout << _name << "을(를) 먹었다." << endl;
                cin.get();
                cout << dog_name << "의 HP가 소량 올랐다." << endl;
                cout << dog_name << "의 매력이 줄었다." << endl;
                dog_charm -= 5;
                dog_hp += _hp;
                cin.get();
                return;
                
            }
            else if (_type == 2) {
                cout << endl << dog_name << "은(는) " << _name << "을(를) 물었다." << endl;
                cin.get();
                cout << _name << "을(를) 먹었다." << endl;
                cin.get();
                cout << dog_name << "의 HP가 줄었다." << endl;
                cout << dog_name << "의 매력이 줄었다." << endl;
                dog_charm -= 5;
                dog_hp -= _def;
                cin.get();
                return;
                
            }
            
        case 3:
            cout << endl << dog_name << "은(는) " << _name << "의 냄새를 맡았다." << endl;
            cin.get();
            cout << _name << "을(를) 파악했다." << endl;
            cin.get();
            seek = 1;
            break;
        case 4:
            
            cout << dog_name << "은(는) 도망갔다." << endl;
            cin.get();
            cin.get();
            return;
            break;
        }

        cout << endl << "아무키나 눌러서 계속 진행하기" << endl;
        cin.get();
        system("cls");

    }
}

struct straycat {
    string name = "길고양이";
    int enemy_type = 1;
    int enemy_hp = 500, enemy_atk = 100, enemy_def = 50;
    int exp = 10;
    string skill_name = "할퀴기";
};
struct cleandog {
    string name = "산책하는 강아지";
    int enemy_type = 2;
    int enemy_hp = 200, enemy_atk = 50, enemy_def = 90;
    int exp = 5;
    string skill_name = "크게 짖기";
};
struct crow {
    string name = "까마귀";
    int enemy_type = 3;
    int enemy_hp = 50, enemy_atk = 100, enemy_def = 20;
    int exp = 15;
    string skill_name = "부리로 쪼기";
};
struct people {
    string name = "동물 보호소 직원";
    int enemy_type = 4;
    int enemy_hp = 1000, enemy_atk = 50, enemy_def = 200;
    int exp = 30;
    string skill_name = "간식으로 유혹하기";
};

struct bosscat {
    string name = "대장고양이";
    int enemy_type = 5;
    int enemy_hp = 1000, enemy_atk = 100, enemy_def = 100;
    string skill_name = "크게 할퀴기";
};




void adventure(string& dog_name, int& dog_level, int& dog_hp, int& dog_atk, int& dog_def, int& dog_charm, int &dog_exp, string skill_name, string _name, int _hp, int _atk, int _def, int _type, int _exp, string _skill_name) {
    int dog_do = 0;
    bool flag = true;
    int seek = 2;

    cout << endl << _name << "과 마주쳤다..!" << endl;

   
    switch (_type) { // 적 설명 출력.
    case 1: // 길고양이
        cout << endl << "평범한 길고양이이다." << endl;
        cout << "발톱이 날카롭다." << endl;
    case 2: // 산책강아지
        cout << endl << "주인과 산책하는 강아지다." << endl;
        cout << "위협적으로 나가면 보통 주인이 데리고 도망간다." << endl;
    case 3: // 까마귀
        cout << endl << "짜증나는 까마귀다." << endl;
    case 4: // 보호소 직원
        cout << endl << "보호소 직원이 나타났다..!" << endl;
        cout << "간식으로 유혹한다." << endl;
        cout << "유혹을 피하지 못하면 자유로운 삶을 뺏길지 모른다..!" << endl;
        cout << "너무 위협하지말고 도망가는걸 추천한다." << endl;
    }

    cin.get();
    system("cls");

    while (flag) {
        int enemy_do = random_engine_4();


        cout << dog_name << setw(13) << setfill(' ') << "적 : " << _name << endl;
        cout << "HP    : " << setw(3) << setfill(' ') << dog_hp << "   " << "HP  : " << setw(3) << setfill(' ') << _hp << endl;
        cout << "ATK   : " << setw(3) << setfill(' ') << dog_atk << "   " << "ATK : " << setw(3) << setfill(' ') << _atk << endl;
        cout << "DEF   : " << setw(3) << setfill(' ') << dog_def << "   " << "DEF : " << setw(3) << setfill(' ') << _def << endl;
        cout << "CHARM : " << setw(3) << setfill(' ') << dog_charm << endl << endl;


        cout << "무슨 행동을 할까? " << endl;
        cout << "1. 짖기" << endl;
        cout << "2. 공격" << endl;
        cout << "3. 피하기" << endl;
        cout << "4. 도망가기" << endl;
        cout << "행동 선택 >> ";
        cin >> dog_do;

        switch (dog_do) {

        case 1:
            if (_type == 1) {
                cout << endl << dog_name << "은 " << _name << "에게 짖었다..!" << endl;
                cin.get();
                switch (enemy_do)
                {
                case 0: 
                case 1: 
                    cout << endl << "길고양이는 하악질을 하며 할퀴었다..!" << endl;
                    cout << "HP 가" << (_atk / 2) << "만큼 감소" << endl;
                    dog_hp -= (_atk/2);
                    break;
                case 2: 
                    cout << endl << "길고양이는 겁을 먹고 도망갔다!" << endl;
                    cout << "EXP가 " << _exp << "만큼 증가했다..!" << endl;
                    cin.get();
                    dog_exp += _exp;
                    return;
                    break;
                case 3: 
                    cout << endl << "길고양이는 경계하고있다." << endl;
                    break;
                }
                cin.get();
                break;
            }
            else if (_type == 2) {
                cout << endl << dog_name << "은 " << _name << "에게 짖었다..!" << endl;
                cin.get();
                cout << "주인이 강아지를 데리고 도망갔다." << endl;
                cout << "EXP가 " << _exp << "만큼 증가했다..!" << endl;
                cin.get();
                dog_exp += _exp;
                return;
                cin.get();
                break;
            }
            else if (_type == 3) {
                cout << endl << dog_name << "은 " << _name << "에게 짖었다..!" << endl;
                cin.get();
                switch (enemy_do)
                {
                case 0:
                case 1:
                case 2:
                    cout << endl << "까마귀는 까악거리며 날아들었다..!" << endl;
                    cout << "HP 가" << (_atk / 4) << "만큼 감소" << endl;
                    dog_hp -= (_atk / 4);                  
                    cin.get();
                    break;
                case 3:
                    cout << endl << "까마귀는 경계하고있다." << endl;
                    cin.get();
                    break;
                }

                cin.get();
                break;
            }
            else if (_type == 4) {
                int patient = 0;
                cout << endl << dog_name << "은 " << _name << "에게 짖었다..!" << endl;
                
                cin.get();
                
                    cout << endl << "보호소직원은 거리를 유지하고있다." << endl;
                    patient++;
                    if (patient == 3) {
                        cout << endl << "참다못한 보호소직원은 마취총을 꺼내들었다...!!!" << endl;
                        _skill_name = "마취총";
                    }
                    else {
                        cout << "보호소직원 참을성 : " << (3 - patient) << endl;
                    }

                cin.get();
                break;
            }
        case 2:
            if (_type == 1) {
                cout << endl << dog_name << "은(는) " << skill_name << " 을(를) 사용했다..!" << endl;
                cin.get();
                if (enemy_do == 2) {
                    cout << endl << _name << "은(는) 피했다..!" << endl;
                    break;
                }
                cout << _name << "의 HP가 줄었다." << endl;
                _hp -= dog_atk;

                cin.get();
                break;

            }
            else if (_type == 2) {
                cout << endl << dog_name << "은(는) " << _name << "을(를) 물었다." << endl;
                cin.get();
                cout << _name << "을(를) 먹었다." << endl;
                cin.get();
                cout << dog_name << "의 HP가 줄었다." << endl;
                cout << dog_name << "의 매력이 줄었다." << endl;
                dog_charm -= 5;
                dog_hp -= _def;
                cin.get();
                return;

            }

        case 3:
            cout << endl << dog_name << "은(는) " << _name << "의 공격을 피하기로 결정했다." << endl;
            
            cin.get();
            cin.get();       
            
            break;
        case 4:
            switch (enemy_do)
            {
            case 0:
            case 1:
            case 3:
                cout << "도망에 실패했다.." << endl;
                break;
            case 2:
                cout << dog_name << "은(는) 도망에 성공했다..!" << endl;
                cin.get();
                return;
                break;
            }  
        }

        if (_hp <= 0) { // 적 쓰러짐
            cout << endl << _name << "이(가) 쓰러졌다..!" << endl;
            cin.get();
            cout << "EXP가 " << _exp << "만큼 증가했다..!" << endl;
            cin.get();
            dog_exp += _exp;
            return;
        }


        switch (enemy_do) {
        case 0:
            cout << _name << "이 " << dog_name << "에게 공격했다." << endl;
            if (dog_do == 3) {
                cout << dog_name << "은(는) 공격을 피했다." << endl;
                break;
            }
            cout << dog_name << "의 HP가 " << (_atk / 2) << "만큼 줄었다." << endl;
            dog_hp -= (_atk / 2);
            break;
        case 1:
            cout << _name << "은(는) " << _skill_name << "을 사용하였다." << endl;
            if (dog_do == 3) {
                cout << dog_name << "은(는) 공격을 피했다." << endl;
                break;
            }
            cout << dog_name << "의 HP가 " << _atk << "만큼 줄었다." << endl;
            dog_hp -= _atk;
            break;
        case 2:
            cout << _name << "은(는) 방어적이다. " << endl;
            break;
        case 3:
            cout << _name << "은(는) 위협하고있다." << endl;
            break;
        }

        cout << endl << "아무키나 눌러서 계속 진행하기" << endl;
        cin.get();
        system("cls");

        if (dog_hp <= 0) {
            cout << endl << dog_name << "이 쓰러졌다.." << endl;
            cin.get();
            return;
        }
        

    }
}


int main_screen(string name = " ", int level = 0, int hp = 0, int atk = 0, int def = 0, int exp = 0, int charm = 0) {
    
    int user_input;
    while (true) {
        system("cls");
    cout << "[ " << name << " ]" << endl;
    cout << "LEVEL : " << level << endl;
    cout << "EXP : " << exp << endl;
    cout << "HP    : " << hp << endl;
    cout << "ATK   : " << atk << endl;
    cout << "DEF   : " << def << endl;
    cout << "CHARM : " << charm << endl;
    cout << "===============" << endl << endl;

    cout << "무엇을 할까?" << endl;
    cout << "1. 모험" << endl;
    cout << "2. 쓰레기뒤지기" << endl;
    cout << "3. 보스 도전" << endl;
    cout << "0. 게임 종료" << endl;
    cout << "입력 : " ;
    cin >> user_input;

    if (user_input == 1) {
        system("cls");
        return user_input;
    }
    else if (user_input == 2) {
        system("cls");
        return user_input;
    }
    else if (user_input == 3) {
        system("cls");
        return user_input;
    }
    else if (user_input == 0) {
        system("cls");
        return user_input;
    }
    else if (cin.fail()) { // 문자열 입력시 예외처리
        cin.clear();
        cin.ignore(100, '\n');
        system("cls");
        continue;
    }
    else { // 다른 숫자 입력시 예외처리
        system("cls");
        continue;
    }
    return user_input;
    }

}

void levelup(int& exp, int&level) {
    
    int max = 5;
    int *p_max = &max;

    if (exp >= *p_max) {
        level++;
        *p_max += max;
    }
}

void main()
{
    system("mode con cols=87 lines=25 | title Stray Dog"); // 창 크기 지정, 타이틀

    jindo j;
    mix m;
    chihuahua c;

    jindo* p_j = &j;
    mix* p_m = &m;
    chihuahua* p_c = &c;

    string name = " ";
    int level = 1;
    int exp = 1;
    int hp = 1;
    int atk = 1;
    int def = 1;
    int charm = 1;
    string skill_name = " ";


    // 쓰레기
    trashbag tg;
    shattered_glass sg;
    fishbone fb;
    ricecake rc;

    // 모험 몹
    straycat sc;
    cleandog cd;
    crow cr;
    people pe;


    int random = 0;

    Init();
    lobby();
    int char_num = character_choice();
    
    switch (char_num) {
    case 1:
        name = (*p_j).name;
        level = (*p_j).level;
        exp = (*p_j).exp;
        hp = (*p_j).hp;
        atk = (*p_j).atk;
        def = (*p_j).def;
        charm = (*p_j).charm;
        skill_name = (*p_j).skill_name;
        break;
    case 2:
        name = (*p_m).name;
        level = (*p_m).level;
        exp = (*p_m).exp;
        hp = (*p_m).hp;
        atk = (*p_m).atk;
        def = (*p_m).def;
        charm = (*p_m).charm;
        skill_name = (*p_m).skill_name;
        break;
    case 3:
        name = (*p_c).name;
        level = (*p_c).level;
        exp = (*p_c).exp;
        hp = (*p_c).hp;
        atk = (*p_c).atk;
        def = (*p_c).def;
        charm = (*p_c).charm;
        skill_name = (*p_c).skill_name;
        break;
    }

    while (true) {

    int user_input_1 = main_screen(name, level, hp, atk, def, exp, charm);

    switch (user_input_1) {
    case 1: // 모험 ( 레벨업 )
        random = random_engine_10();
        switch (random) {
            case 1:
            case 2:
            case 3:
                adventure(name, level, hp, atk, def, charm, exp, skill_name, sc.name, sc.enemy_hp, sc.enemy_atk, sc.enemy_def, sc.enemy_type, sc.exp, sc.skill_name);
                break;
            case 4:
            case 5:
            case 6:
                adventure(name, level, hp, atk, def, charm, exp, skill_name, cd.name, cd.enemy_hp, cd.enemy_atk, cd.enemy_def, cd.enemy_type, cd.exp, cd.skill_name);
                break;
            case 7:
            case 8:
            case 9:
                adventure(name, level, hp, atk, def, charm, exp, skill_name, cr.name, cr.enemy_hp, cr.enemy_atk, cr.enemy_def, cr.enemy_type, cr.exp, cr.skill_name);
                break;
            case 10:
                adventure(name, level, hp, atk, def, charm, exp, skill_name, pe.name, pe.enemy_hp, pe.enemy_atk, pe.enemy_def, pe.enemy_type, pe.exp, pe.skill_name);
                break;
        }
       
    case 2: // 쓰레기 뒤지기 ( 파밍 )
        random = random_engine_4();
        switch (random) {
        case 0:
            encounter(name, level, hp, atk, def, charm, skill_name, tg.name, tg.enemy_hp, tg.enemy_atk, tg.enemy_def, tg.enemy_type);
            break;
        case 1:
            encounter(name, level, hp, atk, def, charm, skill_name, sg.name, sg.enemy_hp, sg.enemy_atk, sg.enemy_def, sg.enemy_type);
            break;
        case 2:
            encounter(name, level, hp, atk, def, charm, skill_name, fb.name, fb.enemy_hp, fb.enemy_atk, fb.enemy_def, fb.enemy_type);
            break;
        case 3:
            encounter(name, level, hp, atk, def, charm, skill_name, rc.name, rc.enemy_hp, rc.enemy_atk, rc.enemy_def, rc.enemy_type);
            break;
        }
        break;
    case 3: // 보스도전

        break;
    case 0: //게임 종료
        int end = 2;
        while (end-1) {
        system("cls");
        cout << "정말 게임을 종료하시겠습니까? " << endl;
        cout << "1. 계속하기 " << endl;
        cout << "2. 종료" << endl;
        
        cin >> end;
        
        if (end == 2) {
            cout << "게임을 종료하였습니다.";
            exit(0);
            break;
        }
        else if (end == 1) {
            break;
        }
        else if (cin.fail()) { // 문자열 입력시 예외처리
        cin.clear();
            cin.ignore(100, '\n');
            system("cls");
            continue;
            }
        else { // 다른 숫자 입력시 예외처리
            system("cls");
            continue;
            }
        }


    } // switch문 끝
    
    levelup(exp, level);

    if (hp <= 0) {
        cout << endl << "게임 오버..." << endl;
        cin.get();
        return;
    }

    } // whil3문 끝
    
    return;
}

