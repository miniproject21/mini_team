typedef struct{
    char name[10]; //예약자 이름
    int time; //사용할 시간
    int type; // 좌석종류(1. 오픈형 2. 1인실)
    char num[10]; //좌석 번호
}Menu;

int addMenu(Menu *s);
void readMenu(Menu s);
void listMenu(Menu *s, int count);
int selectDataNo(Menu *s, int count);
int updateMenu(Menu *s);
int deleteMenu(Menu *s);
void saveData(Menu *s, int count);
int loadData(Menu *s);
int selectMenu();
